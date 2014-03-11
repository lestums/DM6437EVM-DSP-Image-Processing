#ifndef _EDMA3_RM_H_
#define _EDMA3_RM_H_

/*---------------------------------------------------------------------------*/
#include <edma3_common.h>
/*---------------------------------------------------------------------------*/

/**
 * \defgroup Edma3RMIntrMgrMain  EDMA3 Interrupt Manager Interface
 *
 * Top-level Encapsulation of documentation for EDMA3 Interrupt Manager Layer
 *
 * @{
 */


/**
 * \defgroup Edma3RMIntrMgrInst Instance Wide Interface
 *
 * Instance Wide Interface of the EDMA3 Interrupt Manager Layer
 *
 * @{
 */


/**
 * \defgroup Edma3RMStatus Completion status
 *
 * This group defines the error codes of completion
 * of an EDMA3 transfer.
 *
 * @{
 */

/**
 * \brief This enum defines the channel specific status codes of
 * an EDMA3 transfer. It is returned while calling the channel
 * specific callback function to tell the status.
 */
typedef enum
{
    /** DMA Transfer successfully completed (true completion mode)
     *  or submitted to the TC (early completion mode)
     */
    EDMA3_RM_XFER_COMPLETE      = 1,

    /** Channel Controller has reported an error */
    /**
     * DMA missed events:- for all 64 DMA channels.
     * These get latched in the event missed registers (EMR/EMRH).
     */
    EDMA3_RM_E_CC_DMA_EVT_MISS = 2,

    /**
     * QDMA missed events:- for all QDMA channels.
     * These get latched in the QDMA event missed register (QEMR).
     */
    EDMA3_RM_E_CC_QDMA_EVT_MISS = 3
} EDMA3_RM_TccStatus;



/**
 * \brief This enum defines the global (not specific to any channel)
 * error codes of completion of an EDMA3 transfer.
 */
typedef enum
{
    /**
     * Threshold exceed:- for all event queues.
     * These get latched in EDMA3CC error register (CCERR).
     * This error has a direct relation with the setting of
     * EDMA3_RM_GblConfigParams.evtQueueWaterMarkLvl
     */
    EDMA3_RM_E_CC_QUE_THRES_EXCEED            = 1,

    /**
     * TCC error:- for outstanding transfer requests expected to return
     * completion code (TCCHEN or TCINTEN bit in OPT is set to 1) exceeding
     * the maximum limit of 63. This also gets latched in the CCERR.
     */
    EDMA3_RM_E_CC_TCC                           = 2,

    /** Transfer Controller has reported an error */
    /**
     * Detection of a Read error signaled by the source or destination address
     */
    EDMA3_RM_E_TC_MEM_LOCATION_READ_ERROR      = 3,

    /**
     * Detection of a Write error signaled by the source or destination address
     */
    EDMA3_RM_E_TC_MEM_LOCATION_WRITE_ERROR     = 4,

    /**
     * Attempt to read or write to an invalid address in the configuration
     * memory map.
     */
    EDMA3_RM_E_TC_INVALID_ADDR                 = 5,

    /**
     * Detection of a FIFO mode TR violating the FIFO mode transfer rules
     * (the source/destination addresses and source/destination indexes must
     * be aligned to 32 bytes).
     */
    EDMA3_RM_E_TC_TR_ERROR                     = 6
} EDMA3_RM_GlobalError;


/* }@ Edma3RMStatus */


/**
 * \brief Global Error callback - caters to module events like bus error etc
 * which are not channel specific. Runs in ISR context.
 *
 * gblerrData is application provided data when open'ing the Resource Manager.
 */
typedef void (* EDMA3_RM_GblErrCallback)(EDMA3_RM_GlobalError deviceStatus,
                                            unsigned int instanceId,
                                            void *gblerrData);

/**
 * \brief Global Error Callback parameters
 *
 * Consists of the Callback function and the data to be passed to it.
 */
typedef struct {
        /**
         * Instance wide callback function to catch non-channel specific errors
         */
        EDMA3_RM_GblErrCallback gblerrCb;

        /** Application data to be passed back to the Global Error callback */
        void *gblerrData;

} EDMA3_RM_GblErrCallbackParams;

/* @} Edma3RMIntrMgrInst */


/**
 * \defgroup Edma3RMIntrMgrChannel Channel Specific Interface
 *
 * Channel Specific Interface of the EDMA3 Interrupt Manager Layer
 *
 * @{
 */

/**
 * \brief TCC callback - caters to channel-specific events like
 * "Event Miss Error" or "Transfer Complete". Runs in ISR context.
 *
 * appData is passed by the application during Register'ing of
 * TCC Callback function.
 */
typedef void (* EDMA3_RM_TccCallback)(unsigned int tcc,
                    EDMA3_RM_TccStatus status,
                    void *appData);


/**
 * EDMA3_RM_registerTccCb
 * \brief   Register Interrupt / Completion Handler for a given TCC. If a call-
 *          back function is already registered, it fails.
 *
 * \param   hEdmaResMgr         [IN]    Handle to the EDMA3 Resource Manager
 *                                      Instance.
 * \param   tcc                 [IN]    TCC against which the handler needs to
 *                                      be registered.
 * \param   tccCb               [IN]    The Callback function to be registered
 *                                      against the tcc.
 * \param   cbData              [IN]    Callback data to be passed to the
 *                                      Callback function.
 *
 * \return  EDMA3_RM_SOK or EDMA3_RM Error Code
 *
 * \note    This function is re-entrant for unique tcc values. It is non-
 *          re-entrant for same tcc value.
 */
EDMA3_RM_Result EDMA3_RM_registerTccCb(EDMA3_RM_Handle hEdmaResMgr,
                    unsigned int tcc,
                    EDMA3_RM_TccCallback tccCb,
                    void *cbData);

/**
 * EDMA3_RM_unregisterTccCb
 * \brief   Unregister Interrupt / Completion Handler for a given TCC
 *
 *
 * \param   hEdmaResMgr         [IN]    Handle to the EDMA3 Resource Manager
 *                                      Instance.
 * \param   tcc                 [IN]    TCC against which the handler was
 *                                      registered.
 * \return  EDMA3_RM_SOK or EDMA3_RM Error Code
 *
 * \note    This function is re-entrant for unique tcc values. It is non-
 *          re-entrant for same tcc value.
 */
EDMA3_RM_Result EDMA3_RM_unregisterTccCb(EDMA3_RM_Handle hEdmaResMgr,
                    unsigned int tcc);

/* @} Edma3RMIntrMgrChannel */

/* @} Edma3RMIntrMgrMain */




/**
 * \defgroup Edma3RMMain  Interface Definition for EDMA3 Resource Manager Layer
 *
 * Top-level Encapsulation of all documentation for EDMA3 Resource Manager Layer
 *
 * @{
 */


/*---------------------------------------------------------------------------*/
/*------------------Usage Guidelines Start-----------------------------------*/
/*---------------------------------------------------------------------------*/

/**
 * \defgroup Edma3RMUsage Usage Guidelines
 *
 * Guidelines for typical usage of EDMA3 Resource Manager.
 *
 * @{
 */


/**
  \brief Usage of Resource Manager.

    -# Create Resource Manager Object (one for each EDMA3 hardware instance)
        - EDMA3_RM_Result result = EDMA3_RM_SOK;
        - unsigned int edma3HwInstanceId = 0;
        - EDMA3_RM_GblConfigParams *gblCfgParams;
        - Init-time Configuration structure for EDMA3 controller, to provide
            Global SoC specific Information. This could be NULL also. In that
            case, static configuration will be taken.
        - result = EDMA3_RM_create (edma3HwInstanceId, NULL, NULL);
    -# Open Resource Manager Instance
        - Steps
            - EDMA3_RM_Param initParam;
            - unsigned int resMgrIdx = 0;
            - EDMA3_RM_Handle hRes = NULL;
            - unsigned int mappedPaRAMId;
            - EDMA3_RM_Result edmaResult;
                -To get the error code while opening Resource Manager instance

            -# initParam.regionId = Region Id
               e.g. (EDMA3_RM_RegionId)0u OR (EDMA3_RM_RegionId)1u

            -# Set initParam.isMaster =  TRUE/FALSE (Whether this EDMA3
               RM instance is Master or not. Whether this EDMA3 driver instance
               is Master or not. Only the master instance shadow region will
                receive the EDMA3 interrupts, if enabled.);

            -# initParam.rmSemHandle =
               EDMA3 RM Instance specific semaphore handle. It should
               be provided by the user for proper sharing of resources.

            -# initParam.regionInitEnable =  TRUE/FALSE (Whether init of Region
               Specifc registers should be done or not?);

            -# Set initParam.gblerrCbParams.gblerrCb =
               Instance  wide callback function to catch non-channel specific
                errors
            -# initParam.gblerrCbParams.gblerrData =
               Data to be passed to gblerrCb

            -# initParam.rmInstInitConfig.ownDmaChannels[] =
               The bitmap(s) which indicate the DMA channels owned by this
               instance of the Resource Manager\n
               E.g. A '1' at bit position 24 indicates that this instance of
               the Resource Manager owns Channel Id 24\n
               Later when a request is made based on a particular Channel Id,
               the Resource Manager will check first if it owns that channel.
               If it doesnot own it, Resource Manager returns error
               EDMA3_RM_E_RES_NOT_OWNED.
            -# initParam.rmInstInitConfig.ownQdmaChannels[] =
               The bitmap(s) which indicate the QDMA channels owned by this
               instance of the Resource Manager\n
            -# initParam.rmInstInitConfig.ownPaRAMSets[] =
               PaRAM Sets which are to be used by this Region;
            -# initParam.rmInstInitConfig.ownTccs[] =
               TCCs which are to be used by this Region;

            -# initParam.rmInstInitConfig.resvdDmaChannels[] =
               The bitmap(s) which indicate the DMA channels reserved by this
               instance of the Resource Manager\n
               E.g. A '1' at bit position 24 indicates that this instance of
               the Resource Manager reserves Channel Id 24\n
               These channels are reserved and may be mapped to HW events,
               these are not given to 'EDMA3_DRV_DMA_CHANNEL_ANY' request\n
            -# initParam.rmInstInitConfig.resvdQdmaChannels[] =
               The bitmap(s) which indicate the QDMA channels reserved by this
               instance of the Resource Manager\n
               E.g. A '1' at bit position 1 indicates that this instance of
               the Resource Manager reserves QDMA Channel Id 1\n
               These channels are reserved and may be mapped to HW events,
               these are not given to 'EDMA3_DRV_QDMA_CHANNEL_ANY' request\n
            -# initParam.rmInstInitConfig.resvdPaRAMSets[] =
               PaRAM Sets which are reserved by this Region;
            -# initParam.rmInstInitConfig.resvdTccs[] =
               TCCs which are reserved by this Region;

            -# hRes = EDMA3_RM_open (instId, &initParam, &edmaResult);

    -# Resource Management APIs
        - EDMA3_RM_ResDesc              resObj;
        - EDMA3_RM_Result               result;
        - unsigned int                  dmaChId;
        - unsigned int                  qdmaChId;
        - unsigned int                  paRAMId;
        - unsigned int                  tcc;
        - EDMA3_RM_QdmaTrigWord         trigword;
        - EDMA3_RM_TccCallback          tccCb;
        - void                          *cbData;

        - Use Case 1: Request specific DMA Channel, say EDMA Channel 5.\n\n
            - dmaChId = 5;\n\n
            - resObj.type = EDMA3_RM_RES_DMA_CHANNEL;
            - resObj.resId = dmaChId;
            - result = EDMA3_RM_allocResource(hRes, &resObj);\n\n
        - Use Case 2: Request any available DMA Channel.\n\n
            - dmaChId = EDMA3_RM_RES_ANY;\n\n
            - resObj.type = EDMA3_RM_RES_DMA_CHANNEL;
            - resObj.resId = dmaChId;
            - result = EDMA3_RM_allocResource(hRes, &resObj);\n\n
            - dmaCh1Id = resObj.resId; \n\n

        - Use Case 3: Request a specific QDMA Channel, say QDMA Channel 0.\n\n
            - qdmaChId = 0;\n\n
            - resObj.type = EDMA3_RM_RES_QDMA_CHANNEL;
            - resObj.resId = qdmaChId;
            - result = EDMA3_RM_allocResource(hRes, &resObj);\n\n
        - Use Case 4: Request any available QDMA Channel.\n\n
            - qdmaChId = EDMA3_RM_RES_ANY;\n\n
            - resObj.type = EDMA3_RM_RES_QDMA_CHANNEL;
            - resObj.resId = qdmaChId;
            - result = EDMA3_RM_allocResource(hRes, &resObj);\n\n
            - qdmaChId = resObj.resId;\n\n

        - Use Case 5: Request specific Parameter RAM Set, say 20.\n\n
            - paRAMId = 20; \n\n
            - resObj.type = EDMA3_RM_RES_PARAM_SET;
            - resObj.resId = paRAMId;
            - result = EDMA3_RM_allocResource(hRes, &resObj); \n\n
        - Use Case 6: Request any available Parameter RAM Set.\n\n
            - paRAMId = EDMA3_RM_RES_ANY;\n\n
            - resObj.type = EDMA3_RM_RES_PARAM_SET;
            - resObj.resId = paRAMId;
            - result = EDMA3_RM_allocResource(hRes, &resObj);\n\n
            - paRAMId = resObj.resId; \n\n

        - Use Case 7: Request a specific TCC, say TCC 35. \n\n
            - tcc = 35;   \n\n
            - resObj.type = EDMA3_RM_RES_TCC;
            - resObj.resId = tcc;
            - result = EDMA3_RM_allocResource(hRes, &resObj); \n\n
        - Use Case 8: Request any available TCC. \n\n
            - tcc = EDMA3_RM_RES_ANY; \n\n
            - resObj.type = EDMA3_RM_RES_TCC;
            - resObj.resId = tcc;
            - result = EDMA3_RM_allocResource(hRes, &resObj); \n\n
            - tcc = resObj.resId;    \n\n

        - Use Case 9: Free the already allocated DMA channel
            - resObj.type = EDMA3_RM_RES_DMA_CHANNEL;
            - resObj.resId = dmaChId;
            - result = EDMA3_RM_freeResource(hRes, &resObj); \n\n
        - Use Case 10: Free the already allocated QDMA channel
            - resObj.type = EDMA3_RM_RES_QDMA_CHANNEL;
            - resObj.resId = qdmaChId;
            - result = EDMA3_RM_freeResource(hRes, &resObj); \n\n
        - Use Case 11: Free the already allocated PaRAM Set
            - resObj.type = EDMA3_RM_RES_PARAM_SET;
            - resObj.resId = paRAMId;
            - result = EDMA3_RM_freeResource(hRes, &resObj); \n\n
        - Use Case 12: Free the already allocated TCC
            - resObj.type = EDMA3_RM_RES_TCC;
            - resObj.resId = tcc;
            - result = EDMA3_RM_freeResource(hRes, &resObj); \n\n

        - Use Case 13: Bind DMA Channel and a PaRAM Set
            - result = EDMA3_RM_mapEdmaChannel (hRes,dmaChId,paRAMId); \n\n
        - Use Case 14: Bind QDMA Channel and a PaRAM Set. Also, specify
            the Trigger word for the QDMA channel.
            - result = EDMA3_RM_mapQdmaChannel (hRes, qdmaChId, paRAMId,
                                                trigword); \n\n

        - Use Case 15: Register a Callback function associated with a TCC \n\n
            - result = EDMA3_RM_registerTccCb (hRes,tcc,tccCb,cbData); \n\n
        - Use Case 16: Unregister a Callback function associated with a TCC \n\n
            - result = EDMA3_RM_unregisterTccCb (hRes,tcc); \n\n
*/

/* @} Edma3RMUsage */

/*---------------------------------------------------------------------------*/
/*------------------Usage Guidelines End-------------------------------------*/
/*---------------------------------------------------------------------------*/


/**
 * \defgroup Edma3RMErrCode Error Codes
 *
 * Error Codes returned by the EDMA3 Resource Manager Layer
 *
 * @{
 */

/** Resource Manager Error Codes base define */
#define EDMA3_RM_E_BASE                             (-155)

/**
 * Resource Manager Object Not Deleted yet.
 * So the object cannot be created.
 */
#define EDMA3_RM_E_OBJ_NOT_DELETED                  (EDMA3_RM_E_BASE)

/**
 * Resource Manager Object Not Closed yet.
 * So the object cannot be deleted.
 */
#define EDMA3_RM_E_OBJ_NOT_CLOSED                  (EDMA3_RM_E_BASE-1)

/**
 * Resource Manager Object Not Opened yet
 * So the object cannot be closed.
 */
#define EDMA3_RM_E_OBJ_NOT_OPENED                  (EDMA3_RM_E_BASE-2)

/** Invalid Parameter passed to API */
#define EDMA3_RM_E_INVALID_PARAM                   (EDMA3_RM_E_BASE-3)

/** Resource requested for freeing is already free */
#define EDMA3_RM_E_RES_ALREADY_FREE                (EDMA3_RM_E_BASE-4)

/** Resource requested for allocation/freeing is not owned */
#define EDMA3_RM_E_RES_NOT_OWNED                   (EDMA3_RM_E_BASE-5)

/** Resource is not available */
#define EDMA3_RM_E_SPECIFIED_RES_NOT_AVAILABLE     (EDMA3_RM_E_BASE-6)

/** No Resource of specified type is available */
#define EDMA3_RM_E_ALL_RES_NOT_AVAILABLE           (EDMA3_RM_E_BASE-7)

/** Invalid State of EDMA3 RM Obj */
#define EDMA3_RM_E_INVALID_STATE                   (EDMA3_RM_E_BASE-8)

/** Maximum no of Res Mgr Instances already Opened */
#define EDMA3_RM_E_MAX_RM_INST_OPENED              (EDMA3_RM_E_BASE-9)

/**
* More than one Res Mgr Master Instance NOT supported.
* Only 1 master can exist.
*/
#define EDMA3_RM_E_RM_MASTER_ALREADY_EXISTS         (EDMA3_RM_E_BASE-10)

/** Callback function already registered. */
#define EDMA3_RM_E_CALLBACK_ALREADY_REGISTERED      (EDMA3_RM_E_BASE-11)

/** Semaphore related error */
#define EDMA3_RM_E_SEMAPHORE                        (EDMA3_RM_E_BASE-12)

/* @} Edma3RMErrCode */



/**
 * \brief EDMA3 Region Id
 *
 * Use this to assign channels/PaRAM sets/TCCs
 * to a particular Region.
 */
typedef unsigned int EDMA3_RM_RegionId;

/**
 * \brief EDMA3 Event Queue assignment
 *
 * There can be 8 Event Queues.  Either of them can be assigned
 * to a DMA/QDMA channel using this.
 *
 */
typedef unsigned int EDMA3_RM_EventQueue;



/**
 * \brief Init-time Configuration structure for EDMA3
 * controller, to provide Global SoC specific Information.
 *
 * This configuration info will be provided by the user at run-time,
 * while calling EDMA3_RM_create().
 */
typedef struct  {
    /** Total number of DMA Channels supported by the EDMA3 Controller */
    unsigned int        numDmaChannels;
    /** Total number of QDMA Channels supported by the EDMA3 Controller */
    unsigned int        numQdmaChannels;
    /** Total number of TCCs supported by the EDMA3 Controller */
    unsigned int        numTccs;
    /** Total number of PaRAM Sets supported by the EDMA3 Controller */
    unsigned int        numPaRAMSets;
    /** Total number of Event Queues in the EDMA3 Controller */
    unsigned int        numEvtQueue;
    /** Total number of Transfer Controllers (TCs) in the EDMA3 Controller */
    unsigned int        numTcs;
    /** Number of Regions on this EDMA3 controller */
    unsigned int        numRegions;

    /**
     * \brief Channel mapping existence
     * A value of 0 (No channel mapping) implies that there is fixed association
     * for a channel number to a parameter entry number or, in other words,
     * PaRAM entry n corresponds to channel n.
     */
    unsigned short      dmaChPaRAMMapExists;

    /** Existence of memory protection feature */
    unsigned short      memProtectionExists;

    /** Pointer to Global Register Region of CC Registers */
    void                *globalRegs;
    /** Pointer to Transfer Controller Registers */
    void                *tcRegs[EDMA3_MAX_TC];
    /** Interrupt no. for Transfer Completion */
    unsigned int        xferCompleteInt;
    /** Interrupt no. for CC Error */
    unsigned int        ccError;
    /** Interrupt no. for TCs Error */
    unsigned int        tcError[EDMA3_MAX_TC];

    /**
     * \brief EDMA3 TC priority setting
     *
     * User can program the priority of the Event Queues
     * at a system-wide level.  This means that the user can set the
     * priority of an IO initiated by either of the TCs (Transfer Controllers)
     * relative to IO initiated by the other bus masters on the
     * device (ARM, DSP, USB, etc)
     */
    unsigned int        evtQPri [EDMA3_MAX_EVT_QUE];
    /**
     * \brief To Configure the Threshold level of number of events
     * that can be queued up in the Event queues. EDMA3CC error register
     * (CCERR) will indicate whether or not at any instant of time the
     * number of events queued up in any of the event queues exceeds
     * or equals the threshold/watermark value that is set
     * in the queue watermark threshold register (QWMTHRA).
     */
    unsigned int        evtQueueWaterMarkLvl [EDMA3_MAX_EVT_QUE];

    /**
     * \brief To Configure the Default Burst Size (DBS) of TCs.
     * An optimally-sized command is defined by the transfer controller
     * default burst size (DBS). Different TCs can have different
     * DBS values. It is defined in Bytes.
     */
    unsigned int        tcDefaultBurstSize[EDMA3_MAX_TC];


    /**
     * \brief Mapping from each DMA channel to a Parameter RAM set
     * Useful only if mapping exists, otherwise of no use.
     */
    unsigned int        dmaChannelPaRAMMap [EDMA3_MAX_DMA_CH];

     /**
      * \brief Mapping from each DMA channel to a TCC. This specific
      * TCC code will be returned when the transfer is completed
      * on the mapped channel.
      */
     unsigned int       dmaChannelTccMap [EDMA3_MAX_DMA_CH];

    /**
     * \brief Mapping of DMA channels to Hardware Events from
     * various peripherals, which use EDMA for data transfer.
     * All channels need not be mapped, some can be free also.
     */
    unsigned int        dmaChannelHwEvtMap [EDMA3_MAX_DMA_CHAN_DWRDS];
    } EDMA3_RM_GblConfigParams;


/**
 * \brief Init-time Region Specific Configuration structure for
 * EDMA3 controller, to provide region specific Information.
 *
 * This configuration info will be provided by the user at run-time,
 * while calling EDMA3_RM_open().
 */
typedef struct
{
    /**
     * \brief PaRAM Sets owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each PaRAM Set to a master (Region) using this
     * array.  This assignment should ensure that the same PaRAM Set
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical PaRAM Set may have
     * catastrophic consequences.
     *
     */
    unsigned int ownPaRAMSets[EDMA3_MAX_PARAM_DWRDS];

    /**
     * \brief DMA Channels owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each channel to a master (Region) using this
     * array.  This assignment should ensure that the same channel
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical channel may have
     * catastrophic consequences.
     */
    unsigned int ownDmaChannels[EDMA3_MAX_DMA_CHAN_DWRDS];

    /**
     * \brief QDMA Channels owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each QDMA channel to a master (Region) using this
     * array.  This assignment should ensure that the same QDMA channel
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical QDMA channel may have
     * catastrophic consequences.
     */
    unsigned int ownQdmaChannels[EDMA3_MAX_QDMA_CHAN_DWRDS];

    /**
     * \brief TCCs owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each TCC to a master (Region) using this
     * array.  This assignment should ensure that the same TCC
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical TCC may have
     * catastrophic consequences.
     */
    unsigned int ownTccs[EDMA3_MAX_TCC_DWRDS];

    /** Reserved PaRAM Sets - Which are mapped to any DMA/QDMA channel
     *  - these are not given to 'EDMA3_RM_RES_ANY' request
     */
    unsigned int        resvdPaRAMSets[EDMA3_MAX_PARAM_DWRDS];

    /** Reserved DMA Channels - Channels mapped to HW events
     *  - these are not given to 'EDMA3_RM_RES_ANY' request
     */
    unsigned int        resvdDmaChannels[EDMA3_MAX_DMA_CHAN_DWRDS];

    /** Reserved DMA Channels - Channels mapped to HW events
     *  - these are not given to 'EDMA3_RM_RES_ANY' request
     */
    unsigned int        resvdQdmaChannels[EDMA3_MAX_QDMA_CHAN_DWRDS];

    /** Reserved TCCs- Which are mapped to any DMA channel
     *  - these are not given to 'EDMA3_RM_RES_ANY' request
     */
    unsigned int        resvdTccs[EDMA3_MAX_TCC_DWRDS];
}EDMA3_RM_InstanceInitConfig;



/**
 * \brief Used to Initialize the Resource Manager Instance
 * (Master or Slave).
 */
typedef struct {
    /** Region Identification */
    EDMA3_RM_RegionId               regionId;

    /**
     * Whether EDMA3 driver instance is Master or not.
     * Only the master instance shadow region will receive the
     * EDMA3 interrupts, if enabled.
     */
    unsigned short                  isMaster;

    /**
     * EDMA3 RM Instance (Shadow Region) specific
     * init configuration. Like resources owned by this region and
     * resources reserved by this region.
     */
    EDMA3_RM_InstanceInitConfig     rmInstInitConfig;

    /**
     * EDMA3 RM Instance specific semaphore handle.
     * Used to share resources (DMA/QDMA channels, PaRAM Sets, TCCs etc)
     * among different users.
     */
    void                            *rmSemHandle;

    /**
    Whether initialization of Region Specific Registers is required or not?
    It should be done to map different EDMA resources to the appropriate
    shadow region.
    */
    unsigned short                  regionInitEnable;

    /** Instance wide Global Error callback parameters */
    EDMA3_RM_GblErrCallbackParams   gblerrCbParams;
} EDMA3_RM_Param;



/**
 * \brief   Create EDMA3 Resource Manager Object
 *
 * Use this API to create the EDMA3 RM Object. It should be called
 * once for each EDMA3 hardware instance. After successful completion of
 * this API, RM object's state changes to EDMA3_RM_CREATED.
 *
 * \param phyCtrllerInstId  [IN]    EDMA3 Phy Controller Instance Id
 *                                 (Hardware instance id, starting from 0).
 * \param gblCfgParams      [IN]    SoC specific configuration structure for the
 *                                  EDMA3 Hardware.
 * \param param             [IN]    For possible future use.
 *
 * \return  EDMA3_RM_SOK or EDMA3_RM Error Code
 */
EDMA3_RM_Result EDMA3_RM_create (unsigned int phyCtrllerInstId,
                                const EDMA3_RM_GblConfigParams *gblCfgParams,
                                const void *param);

/**
 * \brief   Delete EDMA3 Resource Manager Object
 *
 * Use this API to delete the EDMA3 RM Object. It should be called
 * once for each EDMA3 hardware instance, ONLY after closing all the
 * EDMA3 RM Instances.
 *
 * \param phyCtrllerInstId  [IN]    EDMA3 Phy Controller Instance Id (Hardware
 *                                  instance id, starting from 0).
 * \param   param           [IN]    For possible future use.
 *
 * \return  EDMA3_RM_SOK or EDMA3_RM Error Code
 */
EDMA3_RM_Result EDMA3_RM_delete (unsigned int phyCtrllerInstId,
                                const void *param);



/**
 * \brief       Open EDMA3 Resource Manager Instance
 *
 * Use this API to open a Resource Manager Instance. It could be
 * called multiple times, for each possible EDMA3 shadow region.
 * Maximum EDMA3_MAX_RM_INSTANCES instances are allowed for
 * each EDMA3 hardware instance.
 * Also, only ONE Res Mgr Instance (Master RM Instance) is allowed to
 * receive interrupts from the EDMA3 controller.
 *
 * \param   phyCtrllerInstId    [IN]    Instance Id of the Resource Manager.
 * \param   initParam           [IN]    Used to Initialize the Resource Manager
 *                                      Instance (Master or Slave).
 * \param   errorCode           [OUT]   Error code while opening RM instance.
 *
 * \return  Handle to the opened Resource Manager instance Or NULL
 *
 * \note    This function disables the global interrupts while modifying
 *          the global RM data structures, to make it re-entrant.
 */
EDMA3_RM_Handle EDMA3_RM_open (unsigned int phyCtrllerInstId,
                                const EDMA3_RM_Param *initParam,
                                EDMA3_RM_Result *errorCode);


/**
 * \brief  Close EDMA3 Resource Manager Instance
 *
 * Use this API to close an already opened EDMA3 RM Instance.
 *
 * \param  hEdmaResMgr         [IN]    Handle to the opened Resource Manager
 *                                     Instance.
 * \param  param               [IN]    For possible future use.
 *
 * \return EDMA3_RM_SOK or EDMA3_RM Error Code
 *
 * \note    This function disables the global interrupts while modifying
 *          the global RM data structures, to make it re-entrant.
 */
EDMA3_RM_Result EDMA3_RM_close (EDMA3_RM_Handle hEdmaResMgr,
                                const void *param);

/* @} Edma3RMBookkeep */



/**
 * \defgroup Edma3ResMgr Resource Management
 *
 * Resource Management part of the EDMA3 Resource Manager.
 *
 * @{
 */

/** Used to specify any available Resource Id (EDMA3_RM_ResDesc.resId) */
#define EDMA3_RM_RES_ANY            1010u


/**
 * \brief EDMA3 Resource Type
 */
typedef enum
{
    /** DMA Channel resource */
    EDMA3_RM_RES_DMA_CHANNEL        = 1,

    /** QDMA Channel resource*/
    EDMA3_RM_RES_QDMA_CHANNEL       = 2,

    /** TCC resource*/
    EDMA3_RM_RES_TCC                = 3,

    /** Parameter RAM Set resource*/
    EDMA3_RM_RES_PARAM_SET          = 4

} EDMA3_RM_ResType;


/**
 * \brief Handle to a Resource.
 */
typedef struct
{
    /** Resource Id */
    /**
     * Range of resId values :
     * As an example, for resource Type = EDMA3_RM_RES_DMA_CHANNEL;
     * resId can take values from 0 to EDMA3_RM_NUM_DMA_CH
     * Or
     * resId can take the value EDMA3_RM_RES_ANY.
     */
    unsigned int resId;

    /** Resource Type */
    EDMA3_RM_ResType type;
} EDMA3_RM_ResDesc;



 /**
  * \brief   Allocate specified EDMA3 Resource like DMA channel,
  * QDMA channel, PaRAM Set or TCC.
  *
  * \param   hEdmaResMgr    [IN]        Handle to the opened Resource Manager
  *                                     Instance.
  * \param   resObj         [IN/OUT]    Handle to the resource descriptor
  *                                     object, which needs to be allocated.
  *
  * \return  EDMA3_RM_SOK or EDMA3_RM Error Code
  *
  * \note    This function acquires a RM Instance specific semaphore
  *          to prevent simultaneous access to the global pool of resources.
  *          It is re-entrant, but should not be called from the user callback
  *          function (ISR context).
  */
EDMA3_RM_Result EDMA3_RM_allocResource (EDMA3_RM_Handle hEdmaResMgr,
                                        EDMA3_RM_ResDesc *resObj);



 /**
  * \brief   Free the previously allocated specified EDMA3 Resource
  *  like DMA channel, QDMA channel, PaRAM Set or TCC.
  *
  * \param   hEdmaResMgr    [IN]    Handle to the opened Resource Manager
  *                                 instance.
  * \param   resObj         [IN/OUT]    Handle to the resource descriptor
  *                                     object, which needs to be freed.
  *
  * \return  EDMA3_RM_SOK or EDMA3_RM Error Code
  *
  * \note    This function disables the global interrupts to prevent
  *          simultaneous access to the global pool of resources.
  *          It is re-entrant.
  */
EDMA3_RM_Result EDMA3_RM_freeResource (EDMA3_RM_Handle hEdmaResMgr,
                                        const EDMA3_RM_ResDesc *resObj);


 /**
  * \brief   Allocate a contiguous region of specified EDMA3 Resource
  * like DMA channel, QDMA channel, PaRAM Set or TCC.
  *
  * \param   hEdmaResMgr    [IN]    Handle to the opened Resource Manager
  *                                 Instance.
  * \param   firstResIdObj  [IN]    Handle to the first resource descriptor
  *                                 object, which needs to be allocated.
  * \param   lastResId      [IN]    Id of the Last resource in the
  *                                 contiguous region.
  *
  * \return      EDMA3_RM_SOK or EDMA3_RM Error Code
  *
  * \note        This is a re-entrant function which internally calls
  *              EDMA3_RM_allocResource() for resource allocation,
  *              but should not be called from the user callback
  *              function (ISR context).
  */
EDMA3_RM_Result EDMA3_RM_allocContiguousResource(EDMA3_RM_Handle hEdmaResMgr,
                                            EDMA3_RM_ResDesc *firstResIdObj,
                                            unsigned int lastResId);


 /**
  * EDMA3_RM_freeContiguousResource
  * \brief   Free a contiguous region of specified EDMA3 Resource
  * like DMA channel, QDMA channel, PaRAM Set or TCC.
  *
  * \param   hEdmaResMgr        [IN]    Handle to the opened Resource Manager
  *                                     Instance.
  * \param   firstResIdObj      [IN]    Handle to the first resource descriptor
  *                                     object, which needs to be freed.
  * \param   lastResId          [IN]    Id of the Last resource in the
  *                                     contiguous region.
  *
  * \note        This is a re-entrant function which internally calls
  *              EDMA3_RM_freeResource() for resource de-allocation.
  */
EDMA3_RM_Result EDMA3_RM_freeContiguousResource(EDMA3_RM_Handle hEdmaResMgr,
                                            EDMA3_RM_ResDesc *firstResIdObj,
                                            unsigned int lastResId);

/**
 * \brief QDMA Trigger Word setting
 *
 * Use this enum to set the QDMA trigger word to any of the
 * 8 DWords(unsigned int) within a Parameter RAM set
 */
typedef enum
{
        /**
         * Set the OPT field (Offset Address 0h Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_OPT                  = 0,
        /**
         * Set the SRC field (Offset Address 4h Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_SRC                  = 1,
        /**
         * Set the (ACNT+BCNT) field (Offset Address 8h Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_ACNT_BCNT            = 2,
        /**
         * Set the DST field (Offset Address Ch Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_DST                  = 3,
        /**
         * Set the (SRCBIDX+DSTBIDX) field (Offset Address 10h Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_SRC_DST_BIDX         = 4,
        /**
         * Set the (LINK+BCNTRLD) field (Offset Address 14h Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_LINK_BCNTRLD         = 5,
        /**
         * Set the (SRCCIDX+DSTCIDX) field (Offset Address 18h Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_SRC_DST_CIDX         = 6,
        /**
         * Set the (CCNT+RSVD) field (Offset Address 1Ch Bytes)
         * as the QDMA trigger word
         */
        EDMA3_RM_QDMA_TRIG_CCNT                 = 7,
        /** Default Trigger Word */
        EDMA3_RM_QDMA_TRIG_DEFAULT              = 7
} EDMA3_RM_QdmaTrigWord;



/**
 * \brief   Bind the resources DMA Channel and PaRAM Set
 *
 * \param   hEdmaResMgr         [IN]    Handle to the EDMA3 Resource Manager
 *                                      Instance.
 * \param   channelId           [IN]    DMA Channel on which Transfer will
 *                                      occur.
 * \param   paRAMId             [IN]    PaRAM Set associated with channelId
 *
 * \return  EDMA3_RM_SOK or EDMA_RM Error Code
 *
 * \note This API is useful only for the EDMA3 Controllers which have a register
 *       for mapping a DMA Channel to a particular PaRAM Set.
 */
EDMA3_RM_Result EDMA3_RM_mapEdmaChannel (EDMA3_RM_Handle hEdmaResMgr,
                                        unsigned int channelId,
                                        unsigned int paRAMId);


 /**
  * \brief   Bind the resources QDMA Channel and PaRAM Set. Also, Set the
  * trigger word for the QDMA channel.
  *
  * \param   hEdmaResMgr     [IN]    Handle to the EDMA3 Resource Manager
  *                                  Instance.
  * \param   channelId       [IN]    QDMA Channel on which Transfer will
  *                                  occur.
  * \param   paRAMId         [IN]    PaRAM Set associated with channelId
  * \param   trigWord        [IN]    The Trigger Word for the channel.
  *                                  Trigger Word is the word in the PaRAM
  *                                  Register Set which - when written to by CPU
  *                                  -will start the QDMA transfer automatically
  *
  * \return  EDMA3_RM_SOK or EDMA3_RM Error Code
  *
  * \note    This function is re-entrant for unique channelId & paRAMId. It is
  *          non-re-entrant for same channelId & paRAMId values.
  */
EDMA3_RM_Result EDMA3_RM_mapQdmaChannel (EDMA3_RM_Handle hEdmaResMgr,
                                        unsigned int channelId,
                                        unsigned int paRAMId,
                                        EDMA3_RM_QdmaTrigWord trigWord);


/* @} Edma3ResMgr */

/* @} Edma3RMMain */

#endif    /* _EDMA3_RM_H_ */
