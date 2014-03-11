#ifndef _EDMA3_COMMON_H_
#define _EDMA3_COMMON_H_


/** define to enable/disable Resource Manager debug messages*/
/* #define EDMA3_RM_DEBUG */
#undef EDMA3_RM_DEBUG

/** define to enable/disable EDMA3 Driver debug messages*/
/* #define EDMA3_DRV_DEBUG */
#undef EDMA3_DRV_DEBUG


/** Debug mechanism used for Resource Manager */
#ifdef EDMA3_RM_DEBUG
#include <stdio.h>
#define EDMA3_RM_PRINTF printf
#endif

/** Debug mechanism used for EDMA Driver */
#ifdef EDMA3_DRV_DEBUG
#include <stdio.h>
#define EDMA3_DRV_PRINTF printf
#endif


/** Defines for boolean variables */
#ifndef TRUE
  /** TRUE */
  #define TRUE  (1u)
  /** FALSE */
  #define FALSE (0u)
#endif


/** Define for NULL values*/
#ifndef NULL
#define NULL 0u
#endif


/** EDMA3_RM Result - return value of a function  */
typedef int             EDMA3_RM_Result;
/** EDMA3_DRV Result - return value of a function  */
typedef int             EDMA3_DRV_Result;


/** EDMA3 Resource Manager Result OK */
#define EDMA3_RM_SOK             (0u)
/** EDMA3 Driver Result OK */
#define EDMA3_DRV_SOK            (0u)


/** EDMA3 Resource Manager Handle */
typedef void    *EDMA3_RM_Handle;
/** EDMA3 Driver Handle */
typedef void    *EDMA3_DRV_Handle;


/** OS specific Semaphore Handle */
typedef void    *EDMA3_OS_Sem_Handle;

/** Blocking call without timeout */
#define EDMA3_OSSEM_NO_TIMEOUT    (-1)


/**
  * Defines used to support the maximum resources supported
  * by the EDMA3 controller. These are used to allocate the maximum
  * memory for different data structures of the EDMA3 Driver and Resource
  * Manager.
  */
/** Maximum EDMA3 Controllers on the SoC */
#define EDMA3_MAX_EDMA3_INSTANCES               1u
/** Maximum Resource Manager Instances supported by the EDMA3 Package */
#define EDMA3_MAX_RM_INSTANCES                  8u
/** Maximum DMA channels supported by the EDMA3 Controller */
#define EDMA3_MAX_DMA_CH                        64u
/** Maximum QDMA channels supported by the EDMA3 Controller */
#define EDMA3_MAX_QDMA_CH                       8u
/** Maximum PaRAM Sets supported by the EDMA3 Controller */
#define EDMA3_MAX_PARAM_SETS                    512u
/** Maximum Logical channels supported by the EDMA3 Controller */
#define EDMA3_MAX_LOGICAL_CH        (EDMA3_MAX_PARAM_SETS + EDMA3_MAX_QDMA_CH)
/** Maximum TCCs (Interrupt Channels) supported by the EDMA3 Controller */
#define EDMA3_MAX_TCC                           64u
/** Maximum Event Queues supported by the EDMA3 Controller */
#define EDMA3_MAX_EVT_QUE                       8u
/** Maximum Transfer Controllers supported by the EDMA3 Controller */
#define EDMA3_MAX_TC                            8u
/** Maximum Shadow Regions supported by the EDMA3 Controller */
#define EDMA3_MAX_REGIONS                       8u

/**
  * Maximum Words (4-bytes region) required for the book-keeping information
  * specific to the maximum possible DMA channels.
  */
#define EDMA3_MAX_DMA_CHAN_DWRDS                (EDMA3_MAX_DMA_CH / 32u)

/**
  * Maximum Words (4-bytes region) required for the book-keeping information
  * specific to the maximum possible QDMA channels.
  */
#define EDMA3_MAX_QDMA_CHAN_DWRDS               1u

/**
  * Maximum Words (4-bytes region) required for the book-keeping information
  * specific to the maximum possible PaRAM Sets.
  */
#define EDMA3_MAX_PARAM_DWRDS                   (EDMA3_MAX_PARAM_SETS / 32u)

/**
  * Maximum Words (4-bytes region) required for the book-keeping information
  * specific to the maximum possible TCCs.
  */
#define EDMA3_MAX_TCC_DWRDS                     (EDMA3_MAX_TCC / 32u)


/**
  * EDMA3 ISRs which need to be registered with the underlying OS by the user
  * (Not all TC error ISRs need to be registered, register only for the
  * available Transfer Controllers).
  */

/**  EDMA3 Completion Handler ISR Routine */
extern void lisrEdma3ComplHandler0 (unsigned int arg);

/**  EDMA3 CC Error Interrupt Handler ISR Routine */
extern void lisrEdma3CCErrHandler0 (unsigned int arg);

/**  EDMA3 TC0 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC0ErrHandler0(unsigned int arg);
/**  EDMA3 TC1 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC1ErrHandler0(unsigned int arg);
/**  EDMA3 TC2 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC2ErrHandler0(unsigned int arg);
/**  EDMA3 TC3 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC3ErrHandler0(unsigned int arg);
/**  EDMA3 TC4 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC4ErrHandler0(unsigned int arg);
/**  EDMA3 TC5 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC5ErrHandler0(unsigned int arg);
/**  EDMA3 TC6 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC6ErrHandler0(unsigned int arg);
/**  EDMA3 TC7 Error Interrupt Handler ISR Routine */
extern void lisrEdma3TC7ErrHandler0(unsigned int arg);



/**
  * Defines for the level of OS protection needed when calling
  * edma3OsProtectXXX()
  */

/** Protection from All Interrupts required */
#define EDMA3_OS_PROTECT_INTERRUPT                          1
/** Protection from scheduling required */
#define EDMA3_OS_PROTECT_SCHEDULER                          2
/** Protection from EDMA3 Transfer Completion Interrupt required */
#define EDMA3_OS_PROTECT_INTERRUPT_XFER_COMPLETION          3
/** Protection from EDMA3 CC Errpr Interrupt required */
#define EDMA3_OS_PROTECT_INTERRUPT_CC_ERROR                 4
/** Protection from EDMA3 TC Error Interrupt required */
#define EDMA3_OS_PROTECT_INTERRUPT_TC_ERROR                 5



/**
  * Critical section entry and exit functions (OS dependent) should be
  * implemented by the application for proper linking with the EDMA3 Driver
  * and/or EDMA3 Resource Manager. Without the definitions being provided,
  * the image won’t get linked properly.
  *
  * It is possible that for some regions of code, user needs ultimate
  * degree of protection where some or all external interrupts are blocked,
  * essentially locking out the CPU exclusively for the critical
  * section of code. On the other hand, user may wish to merely avoid
  * thread or task switch from occuring inside said region of code,
  * but he may wish to entertain ISRs to run if so required.
  *
  * Depending on the underlying OS, the number of levels of protection
  * offered may vary. At the least, these basic levels of protection are
  * supported --
  * - EDMA3_OS_PROTECT_INTERRUPT - Mask interrupts globally. This has
  *   real-time implications and must be used with descretion.

  * - EDMA3_OS_PROTECT_SCHEDULER - Only turns off Kernel scheduler
  *   completely, but still allows h/w interrupts from being serviced.

  * - EDMA3_OS_PROTECT_INTERRUPT_XFER_COMPLETION - Mask EDMA3 Transfer
      Completion Interrupt.

  * - EDMA3_OS_PROTECT_INTERRUPT_CC_ERROR - Mask EDMA3 CC Error Interrupt.

  * - EDMA3_OS_PROTECT_INTERRUPT_TC_ERROR - Mask EDMA3 TC Error Interrupt.

  * These APIs should be mandatorily implemented ONCE by the global
  * initialization routine or by the user itself.
  */

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
extern void edma3OsProtectEntry (int level, unsigned int *intState);


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
 *      for EDMA3_OS_PROTECT_INTERRUPT protection level).
 * \return  None
 */
extern void edma3OsProtectExit (int level, unsigned int intState);


/**
  * Counting Semaphore related functions (OS dependent) should be
  * implemented by the application for proper linking with the EDMA3
  * Driver and Resource Manager. The EDMA3 Resource Manager
  * uses these functions for proper sharing of resources (among various users)
  * and assume the implementation of these functions
  * to be provided by the application. Without the definitions being provided,
  * the image won’t get linked properly.
  */
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
extern EDMA3_DRV_Result edma3OsSemTake (EDMA3_OS_Sem_Handle hSem,
                                        int mSecTimeout);

/**
 * \brief   EDMA3 OS Semaphore Give
 *
 *      This function gives or relinquishes an already
 *      acquired semaphore token
 * \param   hSem [IN] is the handle of the specified semaphore
 * \return  EDMA3_DRV_Result if successful else a suitable error code
 */
extern EDMA3_DRV_Result edma3OsSemGive(EDMA3_OS_Sem_Handle hSem);


#endif  /* _EDMA3_COMMON_H_ */

