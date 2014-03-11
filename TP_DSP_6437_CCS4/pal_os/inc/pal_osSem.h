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

/** \file   pal_osSem.h
    \brief  OsSEM Services Header File

    This file declares OS abstraction services for counting semaphores.
    All services run in the context of the calling thread or program.
    OsSEM does not spawn a thread of its own to implement the APIs
    declared here.

    (C) Copyright 2006, Texas Instruments, Inc

    \author     PSP Architecture Team
    \version    1.0
 */

#ifndef __PAL_OSSEM_H__
#define __PAL_OSSEM_H__

#include <psp_common.h>
#ifndef BIOS_BUILD
    #include "pal_osMem.h"
#endif

/**
 * \defgroup PalOSSem PAL OS Semaphore Interface
 * 
 * PAL OS Semaphore Interface
 * @{
 */

/** \name PAL OS Semaphore Interface
 *  PAL OS Semaphore Interface
 * @{
 */

/* Blocking call without timeout */
#define PAL_OSSEM_NO_TIMEOUT    (-1)

/* PAL OS Semaphore Handle */
typedef Ptr PAL_OsSemHandle;

/**
 * \brief   PAL OS Semaphore Init
 * 
 *      This is an idempotent function that must be called ahead of
 *      calling any other OsSEM services. It initializes OsSEM internal
 *      data structures and does any book-keep necessary to implement
 *      the published services of OsSEM.
 * \param   param [IN] is an arbitrary void* data type used to pass platform
 *      specific initialization information for OsSEM. This can be used
 *      to extend OsSEM configurability to decisions made at run-time.
 *      This is added for future extensions only. 
 * \return  PAL_SOK if successful else a suitable error code.
 */
PAL_Result PAL_osSemInit(Ptr param);

typedef enum 
{
  PAL_OSSEM_TYPE_FIFO = 0,
  PAL_OSSEM_TYPE_PRIORITY = 1
} PAL_OsSemType;

typedef struct 
{
  PAL_OsSemType  type;
  Uint32         memSegId;
} PAL_OsSemAttrs;

/**
 * \brief   PAL OS Semaphore Create
 * 
 *      This function creates a counting semaphore with specified
 *      attributes and initial value.
 * \param   name [IN] is char string name of the semaphore
 * \param   initVal [IN] is initial value for semaphore
 * \param   attrs [IN] is the semaphore attributes ex: Fifo type
 * \param   hSem [OUT] is location to recieve the handle to just created
 *      semaphore
 * \return  PAL_SOK if succesful, else a suitable error code.
 */
PAL_Result PAL_osSemCreate(const char * name,
                           Int32 initVal,
                           const PAL_OsSemAttrs *attrs, 
                           PAL_OsSemHandle * hSem);

/**
 * \brief   PAL OS Semaphore Delete
 * 
 *      This function deletes or removes the specified semaphore
 *      from the system. Associated dynamically allocated memory
 *      if any is also freed up.
 * \warning OsSEM services run in client context and not in a thread
 *      of their own. If there exist threads pended on a semaphore
 *      that is being deleted, results are undefined.
 * \param   hSem [IN] handle to the semaphore to be deleted
 * \return  PAL_SOK if succesful else a suitable error code
 */
PAL_Result PAL_osSemDelete(PAL_OsSemHandle hSem);

/**
 * \brief   PAL OS Semaphore Take
 * 
 *      This function takes a semaphore token if available.
 *      If a semaphore is unavailable, it blocks currently
 *      running thread in wait (for specified duration) for
 *      a free semaphore.
 * \param   hSem [IN] is the handle of the specified semaphore
 * \param   mSecTimeout [IN] is wait time in milliseconds
 * \return  PAL_SOK if successful else a suitable error code
 */
PAL_Result PAL_osSemTake(PAL_OsSemHandle hSem, Int32 mSecTimeout);

/**
 * \brief   PAL OS Semaphore Give
 * 
 *      This function gives or relinquishes an already
 *      acquired semaphore token
 * \param   hSem [IN] is the handle of the specified semaphore
 * \return  PAL_SOK if successful else a suitable error code
 */
PAL_Result PAL_osSemGive(PAL_OsSemHandle hSem);

/**
 * \brief Semaphore Report Data Structure
 *
 * Data structure for Semaphore Report service
 */
typedef struct 
{
    char* name;
    Int32 initVal;
    Int32 currentVal;
    PAL_OsSemAttrs attrs;
} PAL_OsSemReport;

/**
 * \brief   PAL OS Semaphore Report
 * 
 *      This function reports assorted usage statistics information
 *      regarding the specified semaphore
 * \param   hSem [IN] handle of semaphore to be reported on.
 * \param   report [IN/OUT] location where information must be reported
 *      If NULL, structure is not filled.
 * \param   buf [IN/OUT] string buffer where a text formatted report will
 *      be printed. If NULL, no text style reporting is done.
 * \return  PAL_SOK if successful, else a suitable error code.
 */
PAL_Result PAL_osSemReport(PAL_OsSemHandle hSem, PAL_OsSemReport *report, Char* buf);

/*@}*/
/*@}*/

#endif /* _PAL_OSSEM_H_ */
