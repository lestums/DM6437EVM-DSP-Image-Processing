#include <ecm.h>
#include <bcache.h>
#include <hwi.h>
#include <tsk.h>
#include <clk.h>
#include <sem.h>
#include <bios_edma3_sample.h>

#define EDMA3_CACHE_WAIT        (1u)


/**
 * \brief   EDMA3 OS Protect Entry
 *
 *      This function saves the current state of protection in 'intState'
 *      variable passed by caller, if the protection level is
 *      EDMA3_OS_PROTECT_INTERRUPT. It then applies the requested level of
 *      protection.
 *      For EDMA3_OS_PROTECT_INTERRUPT_XFER_COMPLETION and
 *      EDMA3_OS_PROTECT_INTERRUPT_CC_ERROR, variable 'intState' is ignored,
 *      and the requested interrupt is disabled.
 *      For EDMA3_OS_PROTECT_INTERRUPT_TC_ERROR, '*intState' specifies the
 *      Transfer Controller number whose interrupt needs to be disabled.
 *
 * \param   level is numeric identifier of the desired degree of protection.
 * \param   intState is memory location where current state of protection is
 *      saved for future use while restoring it via edma3OsProtectExit() (Only
 *      for EDMA3_OS_PROTECT_INTERRUPT protection level).
 * \return  None
 */
void edma3OsProtectEntry ( int level, unsigned int *intState ) {
  if ( ( (level == EDMA3_OS_PROTECT_INTERRUPT)
         || (level == EDMA3_OS_PROTECT_INTERRUPT_TC_ERROR) )
         && (intState == NULL) ) {
    return;
  } else {
    switch ( level ) {
    /* Disable all (global) interrupts */
    case EDMA3_OS_PROTECT_INTERRUPT :
      *intState = HWI_disable();
      break;

    /* Disable scheduler */
    case EDMA3_OS_PROTECT_SCHEDULER :
      TSK_disable();
      break;

    /* Disable EDMA3 transfer completion interrupt only */
    case EDMA3_OS_PROTECT_INTERRUPT_XFER_COMPLETION :
      ECM_disableEvent(ccXferCompInt);
      break;

    /* Disable EDMA3 CC error interrupt only */
    case EDMA3_OS_PROTECT_INTERRUPT_CC_ERROR :
      ECM_disableEvent(ccErrorInt);
      break;

    /* Disable EDMA3 TC error interrupt only */
    case EDMA3_OS_PROTECT_INTERRUPT_TC_ERROR :
      switch (*intState) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        /* Fall through... */
        /* Disable the corresponding interrupt */
        ECM_disableEvent(tcErrorInt[*intState]);
        break;

      default:
        break;
      }

      break;

    default:
      break;
    }
  }
}


/**
 * \brief   EDMA3 OS Protect Exit
 *
 *      This function undoes the protection enforced to original state
 *      as is specified by the variable 'intState' passed, if the protection
 *      level is EDMA3_OS_PROTECT_INTERRUPT.
 *      For EDMA3_OS_PROTECT_INTERRUPT_XFER_COMPLETION and
 *      EDMA3_OS_PROTECT_INTERRUPT_CC_ERROR, variable 'intState' is ignored,
 *      and the requested interrupt is enabled.
 *      For EDMA3_OS_PROTECT_INTERRUPT_TC_ERROR, 'intState' specifies the
 *      Transfer Controller number whose interrupt needs to be enabled.
 * \param   level is numeric identifier of the desired degree of protection.
 * \param   intState is original state of protection at time when the
 *      corresponding edma3OsProtectEntry() was called (Only
 *      for EDMA3_O_PROTECT_INTERRUPT protection level).
 * \return  None
 */
void edma3OsProtectExit ( int level, unsigned int intState ) {
  switch ( level ) {
  /* Enable all (global) interrupts */
  case EDMA3_OS_PROTECT_INTERRUPT :
    HWI_restore(intState);
    break;

  /* Enable scheduler */
  case EDMA3_OS_PROTECT_SCHEDULER :
    TSK_enable();
    break;

  /* Enable EDMA3 transfer completion interrupt only */
  case EDMA3_OS_PROTECT_INTERRUPT_XFER_COMPLETION :
    ECM_enableEvent(ccXferCompInt);
    break;

  /* Enable EDMA3 CC error interrupt only */
  case EDMA3_OS_PROTECT_INTERRUPT_CC_ERROR :
    ECM_enableEvent(ccErrorInt);
    break;

  /* Enable EDMA3 TC error interrupt only */
  case EDMA3_OS_PROTECT_INTERRUPT_TC_ERROR :
    switch (intState) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    /* Fall through... */
    /* Enable the corresponding interrupt */
      ECM_enableEvent(tcErrorInt[intState]);
      break;

    default:
      break;
    }

    break;

  default:
    break;
  }
}


/* Function to wait for OS Ticks */
void edma3OsWaitMsecs(unsigned int mSecs) {
  unsigned int ticksForSleeping = ((CLK_countspms() / CLK_getprd()) * mSecs);
  TSK_sleep(ticksForSleeping);
}


/**
 *  \brief   EDMA3 Cache Invalidate
 *
 *  This function invalidates the D cache.
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  mem_start_ptr [IN]      Starting adress of memory.
 *                                  Please note that this should be
 *                                  32 bytes alinged.
 *  \param  num_bytes [IN]          length of buffer
 *  \return  nil return value
 */
void Edma3_CacheInvalidate(Edma3_CacheMemAddrSpace cache,
                           unsigned int mem_start_ptr,
                           unsigned int num_bytes ) {
  /* To avoid compiler warning */
  cache = cache;

  /* Verify whether the start address is 128-bytes aligned or not */
  if ( (mem_start_ptr & (0x7FU))    !=    0 ) {
#ifdef EDMA3_DRV_DEBUG
    EDMA3_DRV_PRINTF("\r\n Cache : Memory is not 128 bytes alinged\r\n");
#endif
  }

  BCACHE_inv( (void *)mem_start_ptr,
              num_bytes,
              EDMA3_CACHE_WAIT );
}


/**
 * \brief   EDMA3 Cache Flush
 *
 * This function flushes (cleans) the Cache
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  mem_start_ptr [IN]      Starting adress of memory. Please note that
 *                                  this should be 32 bytes alinged.
 *  \param  num_bytes [IN]          length of buffer
 * \return  nil return value
 */
void Edma3_CacheFlush( Edma3_CacheMemAddrSpace cache,
                       unsigned int mem_start_ptr,
                       unsigned int num_bytes ) {
  /* To avoid compiler warning */
  cache = cache;

  /* Verify whether the start address is 128-bytes aligned or not */
  if ( (mem_start_ptr & (0x7FU))    !=    0 ) {
#ifdef EDMA3_DRV_DEBUG
    EDMA3_DRV_PRINTF("\r\n Cache : Memory is not 128 bytes alinged\r\n");
#endif
  }

  BCACHE_wb ( (void *)mem_start_ptr,
              num_bytes,
              EDMA3_CACHE_WAIT );
}


/**
  * Counting Semaphore related functions (OS dependent) should be
  * called/implemented by the application. A handle to the semaphore
  * is required while opening the driver/resource manager instance.
  */

/**
 * \brief   EDMA3 OS Semaphore Create
 *
 *      This function creates a counting semaphore with specified
 *      attributes and initial value. It should be used to create a semaphore
 *      with initial value as '1'. The semaphore is then passed by the user
 *      to the EDMA3 driver/RM for proper sharing of resources.
 * \param   initVal [IN] is initial value for semaphore
 * \param   attrs [IN] is the semaphore attributes ex: Fifo type
 * \param   hSem [OUT] is location to recieve the handle to just created
 *      semaphore
 * \return  EDMA3_DRV_SOK if succesful, else a suitable error code.
 */
EDMA3_DRV_Result edma3OsSemCreate( int initVal,
                                   const EDMA3_OS_SemAttrs *attrs,
                                   EDMA3_OS_Sem_Handle *hSem ) {
  EDMA3_DRV_Result semCreateResult = EDMA3_DRV_SOK;

  if ( NULL == hSem ) {
    semCreateResult = EDMA3_DRV_E_INVALID_PARAM;
  } else {
    *hSem = (EDMA3_OS_Sem_Handle)SEM_create(initVal, (SEM_Attrs*)attrs);
    if ( (*hSem) == NULL ) {
      semCreateResult = EDMA3_DRV_E_SEMAPHORE;
    }
  }

  return semCreateResult;
}


/**
 * \brief   EDMA3 OS Semaphore Delete
 *
 *      This function deletes or removes the specified semaphore
 *      from the system. Associated dynamically allocated memory
 *      if any is also freed up.
 * \warning OsSEM services run in client context and not in a thread
 *      of their own. If there exist threads pended on a semaphore
 *      that is being deleted, results are undefined.
 * \param   hSem [IN] handle to the semaphore to be deleted
 * \return  EDMA3_DRV_SOK if succesful else a suitable error code
 */
EDMA3_DRV_Result edma3OsSemDelete( EDMA3_OS_Sem_Handle hSem ) {
  EDMA3_DRV_Result semDeleteResult = EDMA3_DRV_SOK;

  if ( NULL == hSem ) {
    semDeleteResult = EDMA3_DRV_E_INVALID_PARAM;
  } else {
    SEM_delete(hSem);
  }

  return semDeleteResult;
}


/**
 * \brief   EDMA3 OS Semaphore Take
 *
 *      This function takes a semaphore token if available.
 *      If a semaphore is unavailable, it blocks currently
 *      running thread in wait (for specified duration) for
 *      a free semaphore.
 * \param   hSem [IN] is the handle of the specified semaphore
 * \param   mSecTimeout [IN] is wait time in milliseconds
 * \return  EDMA3_DRV_Result if successful else a suitable error code
 */
EDMA3_DRV_Result edma3OsSemTake( EDMA3_OS_Sem_Handle hSem, int mSecTimeout ) {
  EDMA3_DRV_Result semTakeResult = EDMA3_DRV_SOK;
  unsigned short semPendResult;

  if ( NULL == hSem ) {
    semTakeResult = EDMA3_DRV_E_INVALID_PARAM;
  } else {
    semPendResult = SEM_pend(hSem, mSecTimeout);
    if ( semPendResult == FALSE ) {
      semTakeResult = EDMA3_DRV_E_SEMAPHORE;
    }
  }

  return semTakeResult;
}


/**
 * \brief   EDMA3 OS Semaphore Give
 *
 *      This function gives or relinquishes an already
 *      acquired semaphore token
 * \param   hSem [IN] is the handle of the specified semaphore
 * \return  EDMA3_DRV_Result if successful else a suitable error code
 */
EDMA3_DRV_Result edma3OsSemGive( EDMA3_OS_Sem_Handle hSem ) {
  EDMA3_DRV_Result semGiveResult = EDMA3_DRV_SOK;

  if ( NULL == hSem ) {
    semGiveResult = EDMA3_DRV_E_INVALID_PARAM;
  } else {
    SEM_post(hSem);
  }

  return semGiveResult;
}





