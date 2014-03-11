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

/** \file   pal_osInt.h
    \brief  ECM interrupt wrapper header file

    
    
    (C) Copyright 2006, Texas Instruments, Inc

    \author     PSP Architecture Team
    \version    1.0
 */

#ifndef __PAL_OSINT_H__
#define __PAL_OSINT_H__

#include <psp_common.h>


/**
 * \defgroup PalOSInt PAL OS Interrupt Interface
 * 
 * PAL OS Interrupt Interface
 * \{
 */

/** \name PAL OS Interrupt Interface
 *  PAL OS Interrupt Interface
 * \{
 */

/**
 * \brief   PAL_osEvtEnable(Uint32 evtNum, Uint32 eventId)
 *
 *      This function is used to enable specific internal 
 *      interrupts by modifying the Interrupt Enable Register (IER). 
 *      
 * \param   evtNum   [IN] interrupt event number
 * \param   eventId [IN]  interrupt event to set
 * \return  NONE
 */
void PAL_osEvtEnable(Uint32 eventId);

/**
 * \brief   PAL_osEvtDisable()
 *
 *      This function is used to disable specific internal 
 *      interrupts by modifying the Interrupt Enable Register (IER). 
 *      
 * \param   evtNum   [IN] interrupt event number
 * \param   eventId [IN]  interrupt event to set
 * \return  NONE
 */
void PAL_osEvtDisable(Uint32 eventId);

/*\}*/
/*\}*/

#endif /* __PAL_OSINT_H__ */
