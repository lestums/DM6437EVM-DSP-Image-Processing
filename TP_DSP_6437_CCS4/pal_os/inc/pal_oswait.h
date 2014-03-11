/*******************************************************************************
**+--------------------------------------------------------------------------+**
**|                            ****                                          |**
**|                            ****                                          |**
**|                            ******o***                                    |**
**|                      ********_///_****                                   |**
**|                      ***** /_//_/ ****                                   |**
**|                       ** ** (__/ ****                                    |**
**|                           *********                                      |**
**|                            ****                                          |**
**|                            ***                                           |**
**|                                                                          |**
**|         Copyright (c) 1998-2006 Texas Instruments Incorporated           |**
**|                        ALL RIGHTS RESERVED                               |**
**|                                                                          |**
**| Permission is hereby granted to licensees of Texas Instruments           |**
**| Incorporated (TI) products to use this computer program for the sole     |**
**| purpose of implementing a licensee product based on TI products.         |**
**| No other rights to reproduce, use, or disseminate this computer          |**
**| program, whether in part or in whole, are granted.                       |**
**|                                                                          |**
**| TI makes no representation or warranties with respect to the             |**
**| performance of this computer program, and specifically disclaims         |**
**| any responsibility for any damages, special or consequential,            |**
**| connected with the use of this program.                                  |**
**|                                                                          |**
**+--------------------------------------------------------------------------+**
*******************************************************************************/

/** \file   pal_osWait.h
    \brief  OsWAIT Services Header File

    This file declares OS abstraction services for programmed interval-waits.
    
    (C) Copyright 2006, Texas Instruments, Inc

    \author     PSP Architecture Team
    \version    1.0
 */

#ifndef __PAL_OSWAIT_H__
#define __PAL_OSWAIT_H__

#include <psp_common.h>

/**
 * \defgroup PalOSWait PAL OS Wait Interface
 * 
 * PAL OS Wait Interface
 * \{
 */

/** \name PAL OS Wait Interface
 *  PAL OS Wait Interface
 * \{
 */

/**
 * \brief   PAL_osWaitMsecs()
 *
 *      This function leverages OS implemented "wait" to delay
 *      further execution of current thread for specified milliseconds
 *      period of time.
 * \note    The currently running thread might be preempted and placed
 *      on scheduler's wait queue for the specified duration of time.
 *      If a more effecient (w/o context switch overhead) wait is required
 *      at finer time granularity (order of microseconds), please use
 *      SysWAIT services defined in pal_sys.h file
 * \note    The function will do any milliseconds-to-ticks conversion
 *      as appropriate for implementing the wait using underlying
 *      OS supported APIs.
 * \param   mSecs [IN] is the duration in milliseconds to wait for
 * \return  PAL_SOK if succesful else a suitable error code
 */
PAL_Result PAL_osWaitMsecs(Uint32 mSecs);

/**
 * \brief   PAL_osWaitTicks()
 *
 *      This function leverages OS implemented "wait" to delay
 *      further execution of current thread for specified number
 *      of operating system ticks.
 * \note    The currently running thread might be preempted and placed
 *      on scheduler's wait queue for the specified duration of time.
 *      If a more effecient (w/o context switch overhead) wait is required
 *      at finer time granularity (order of microseconds), please use
 *      SysWAIT services defined in pal_sys.h file
 * \param   ticks [IN] is the number of operating system ticks to wait for
 * \return  PAL_SOK if succesful else a suitable error code
 */
PAL_Result PAL_osWaitTicks(Uint32 ticks);

/*\}*/
/*\}*/

#endif /* _PAL_OSWAIT_H_ */
