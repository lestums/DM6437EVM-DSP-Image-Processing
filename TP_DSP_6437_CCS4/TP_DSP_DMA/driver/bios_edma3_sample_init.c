#include <ecm.h>
#include <hwi.h>
#include <bios_edma3_sample.h>


/** @brief To enable the HWI event corresponding to the EDMA3 ECM events */
#define EDMA3_HWI_BITMASK                       (0x0100u)


/** @brief EDMA3 Driver Handle, used to call all the Driver APIs */
EDMA3_DRV_Handle hEdma = NULL;

/** @brief EDMA3 Driver Instance specific Semaphore handle */
static EDMA3_OS_Sem_Handle semHandle = NULL;


/**
  * EDMA3 TC ISRs which need to be registered with the underlying OS by the user
  * (Not all TC error ISRs need to be registered, register only for the
  * available Transfer Controllers).
  */
void (*ptrEdma3TcIsrHandler[EDMA3_MAX_TC])(unsigned int arg) =
                                                {
                                                &lisrEdma3TC0ErrHandler0,
                                                &lisrEdma3TC1ErrHandler0,
                                                &lisrEdma3TC2ErrHandler0,
                                                &lisrEdma3TC3ErrHandler0,
                                                &lisrEdma3TC4ErrHandler0,
                                                &lisrEdma3TC5ErrHandler0,
                                                &lisrEdma3TC6ErrHandler0,
                                                &lisrEdma3TC7ErrHandler0,
                                                };


/**  To Register the ISRs with the underlying OS, if required. */
static void registerEdma3Interrupts (void);
/**  To Unregister the ISRs with the underlying OS, if previously registered. */
static void unregisterEdma3Interrupts (void);

/*
 *  ======== C64_enableIER ========
 *  enable interrupts specified by mask
 */
extern Void C64_enableIER( Uns mask );


/**
 * \brief   EDMA3 Initialization
 *
 * This function initializes the EDMA3 Driver and registers the
 * interrupt handlers.
 *
 * \return  EDMA3_DRV_SOK if success, else error code
 */
EDMA3_DRV_Result edma3init() {
  unsigned int edma3InstanceId = 0;
  EDMA3_DRV_InitConfig initCfg;
  EDMA3_DRV_Result    edma3Result = EDMA3_DRV_SOK;

  // Zhengting:
  // semType can be FIFO or PRIORITY which determines how to unblock pending tasks?
  // memSegId is 0 in this case
  EDMA3_OS_SemAttrs semAttrs = {EDMA3_OS_SEMTYPE_FIFO, NULL};

  if ( NULL == hEdma ) {

    /* configuration structure for the Driver */
    initCfg.isMaster    =    TRUE;
    initCfg.regionId = (EDMA3_RM_RegionId)1u;
    initCfg.drvSemHandle = NULL;
    
    /* Driver instance specific config NULL */
    initCfg.drvInstInitConfig = NULL;
    initCfg.gblerrCb = NULL;
    initCfg.gblerrData = NULL;

    /* Create EDMA3 Driver Object first. */
    edma3Result = EDMA3_DRV_create (edma3InstanceId, NULL, NULL);
    if (edma3Result != EDMA3_DRV_SOK) {
#ifdef EDMA3_DRV_DEBUG
      EDMA3_DRV_PRINTF("edma3init: EDMA3_DRV_create FAILED\r\n");
#endif
    } else {
      /**
       * Driver Object created successfully.
       * Create a semaphore now for driver instance.
       */
      edma3Result = edma3OsSemCreate(1, &semAttrs, &initCfg.drvSemHandle);
      if ( edma3Result != EDMA3_DRV_SOK ) {
#ifdef EDMA3_DRV_DEBUG
        EDMA3_DRV_PRINTF("edma3init: edma3OsSemCreate FAILED\r\n");
#endif
      } else {
        /* Save the semaphore handle for future use */
        semHandle = initCfg.drvSemHandle;

        /* Open the Driver Instance */
        hEdma = EDMA3_DRV_open ( edma3InstanceId, (void *) &initCfg,
                                 &edma3Result);
        if ( NULL == hEdma ) {
#ifdef EDMA3_DRV_DEBUG
          EDMA3_DRV_PRINTF("edma3init: EDMA3_DRV_open FAILED\r\n");
#endif
        } else {
          /**
            * Register Interrupt Handlers for various interrupts
            * like transfer completion interrupt, CC error
            * interrupt, TC error interrupts etc, if required.
            */
            registerEdma3Interrupts();
        }
      }
    }
  } else {
#ifdef EDMA3_DRV_DEBUG
    EDMA3_DRV_PRINTF("edma3init: EDMA3 Driver Already Initialized...\r\n");
#endif
  }

  return edma3Result;
}


/**  To Register the ISRs with the underlying OS, if required. */
static void registerEdma3Interrupts( void ) {
  unsigned int intState;
  ECM_Attrs ecmattrs = ECM_ATTRS;
  unsigned int numTc = 0;

  /* Disabling the global interrupts */
  intState = HWI_disable();

  /* Enable the Xfer Completion Event Interrupt */
  ecmattrs.unmask = 1u;
  ECM_dispatchPlug ( ccXferCompInt, (ECM_Fxn)(&lisrEdma3ComplHandler0),
                     &ecmattrs);
  ECM_enableEvent(ccXferCompInt);

  /* Enable the CC Error Event Interrupt */
  ecmattrs.unmask = 1u;
  ECM_dispatchPlug(ccErrorInt, (ECM_Fxn)(&lisrEdma3CCErrHandler0), &ecmattrs);
  ECM_enableEvent(ccErrorInt);

  /* Enable the TC Error Event Interrupt, according to the number of TCs. */
  while ( numTc < numEdma3Tc ) {
    ecmattrs.unmask = 1u;
    ECM_dispatchPlug ( tcErrorInt[numTc], (ECM_Fxn)(ptrEdma3TcIsrHandler[numTc]),
                       &ecmattrs);
    ECM_enableEvent(tcErrorInt[numTc]);
    numTc++;
  }

  /**
   * Enabling the HWI_ID.
   * EDMA3 interrupts (transfer completion, CC error etc.)
   * correspond to different ECM events (SoC specific). These ECM events come
   * under ECM block XXX (handling those specific ECM events). Normally, block
   * 0 handles events 4-31 (events 0-3 are reserved), block 1 handles events
   * 32-63 and so on. This ECM block XXX (or interrupt selection number XXX)
   * is mapped to a specific HWI_INT YYY in the tcf file. So to enable this
   * mapped HWI_INT YYY, one should use the corresponding bitmask in the
   * API C64_enableIER(), in which the YYY bit is SET.
   */
  C64_enableIER(EDMA3_HWI_BITMASK);

  // Zhengting: event 36 - 40 are combined to evt 1
  // code above enables interrupt 8, in which the TCF file set interrupt 
  // selection number (event number) as 1

  /* Restore interrupts */
  HWI_restore(intState);
}


/**
 * \brief   EDMA3 De-initialization
 *
 * This function removes the EDMA3 Driver instance and unregisters the
 * interrupt handlers.
 *
  * \return  EDMA3_DRV_SOK if success, else error code
 */
EDMA3_DRV_Result edma3deinit( void ) {
  unsigned int edmaInstanceId = 0;
  EDMA3_DRV_Result    edma3Result = EDMA3_DRV_SOK;

  /* Unregister Interrupt Handlers first */
  unregisterEdma3Interrupts();

  /* Delete the semaphore */
  edma3Result = edma3OsSemDelete( semHandle );
  if ( EDMA3_DRV_SOK != edma3Result ) {
#ifdef EDMA3_DRV_DEBUG
    EDMA3_DRV_PRINTF("edma3deinit: edma3OsSemDelete FAILED\r\n");
#endif
  } else {
    /* Make the semaphore handle as NULL. */
    semHandle = NULL;

    /* Now, close the EDMA3 Driver Instance */
    edma3Result = EDMA3_DRV_close (hEdma, NULL);
    if ( EDMA3_DRV_SOK != edma3Result ) {
#ifdef EDMA3_DRV_DEBUG
      EDMA3_DRV_PRINTF("edma3deinit: EDMA3_DRV_close FAILED\r\n");
#endif
    } else {
      /* Now, delete the EDMA3 Driver Object */
      edma3Result = EDMA3_DRV_delete ( edmaInstanceId, NULL );
      if ( EDMA3_DRV_SOK != edma3Result ) {
#ifdef EDMA3_DRV_DEBUG
        EDMA3_DRV_PRINTF("edma3deinit: EDMA3_DRV_delete FAILED\r\n");
#endif
      } else {
#ifdef EDMA3_DRV_DEBUG
        EDMA3_DRV_PRINTF("edma3deinit: EDMA3 Deinitialization" \
                                    " Completed...\r\n");
#endif
      }
    }
  }

  return edma3Result;
}


/**  To Unregister the ISRs with the underlying OS, if previously registered. */
static void unregisterEdma3Interrupts( void ) {
  unsigned int intState;
  unsigned int numTc = 0;

  /* Disabling the global interrupts */
  intState = HWI_disable();

  /* Disable the Xfer Completion Event Interrupt */
  ECM_disableEvent( ccXferCompInt );

  /* Disable the CC Error Event Interrupt */
  ECM_disableEvent( ccErrorInt );

  /* Enable the TC Error Event Interrupt, according to the number of TCs. */
  while ( numTc < numEdma3Tc ) {
    ECM_disableEvent(tcErrorInt[numTc]);
    numTc++;
  }

  /* Restore interrupts */
  HWI_restore(intState);
}

/* End of File */
