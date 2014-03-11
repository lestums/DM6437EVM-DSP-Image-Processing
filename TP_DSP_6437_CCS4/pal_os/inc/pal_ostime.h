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

/** \file   pal_ostime.h
    \brief  PAL OS Service Header File

    This file declares additional OS abstraction services for BIOS. The following
    BIOS services are provided:

    1. Get systime, current tick and check timeout.

    (C) Copyright 2004, Texas Instruments, Inc

    \author     Nagarjuna Kristam
    \version    1.0
 */

#ifndef _PAL_OSTIME_H
#define _PAL_OSTIME_H

#include <psp_common.h>


/**
 * \defgroup PAL OS Time Interface
 *
 * PAL OS TIME INTERFACE
 * @{
 */
/* Checks the timeout */
Bool PAL_osCheckTimeOut(Uint32 startValue,Int32 timeout);

#ifndef BIOS_BUILD
/* Gets current system time */
void PAL_osGetSysTime(SYSTIM *p_systim);
#endif

Uint32 PAL_osGetCurrentTick(void);
/*@}*/

#endif /* _PAL_OSTIME_H */
