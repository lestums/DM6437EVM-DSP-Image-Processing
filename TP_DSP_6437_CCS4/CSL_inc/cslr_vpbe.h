/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005. 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
 
/** ============================================================================
 *   @file  cslr_vpbe.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Desciptions for VPBE
 *
 *  ============================================================================
 */
#ifndef _CSLR_VPBE_H_
#define _CSLR_VPBE_H_

#include <cslr.h>
#include "tistdtypes.h"

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 PCR;
} CSL_VpbeRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_VpbeRegs             *CSL_VpbeRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */


#define CSL_VPBE_PID_TID_MASK (0x00FF0000u)
#define CSL_VPBE_PID_TID_SHIFT (0x00000010u)
#define CSL_VPBE_PID_TID_RESETVAL (0x000000BEu)

#define CSL_VPBE_PID_CID_MASK (0x0000FF00u)
#define CSL_VPBE_PID_CID_SHIFT (0x00000008u)
#define CSL_VPBE_PID_CID_RESETVAL (0x00000004u)

#define CSL_VPBE_PID_PREV_MASK (0x000000FFu)
#define CSL_VPBE_PID_PREV_SHIFT (0x00000000u)
#define CSL_VPBE_PID_PREV_RESETVAL (0x00000000u)

#define CSL_VPBE_PID_RESETVAL (0x00BE0400u)

/* PCR */


#define CSL_VPBE_PCR_VENC_DIV_MASK (0x00000002u)
#define CSL_VPBE_PCR_VENC_DIV_SHIFT (0x00000001u)
#define CSL_VPBE_PCR_VENC_DIV_RESETVAL (0x00000000u)
/*----VENC_DIV Tokens----*/
#define CSL_VPBE_PCR_VENC_DIV_FULL (0x00000000u)
#define CSL_VPBE_PCR_VENC_DIV_HALF (0x00000001u)

#define CSL_VPBE_PCR_CLK_OFF_MASK (0x00000001u)
#define CSL_VPBE_PCR_CLK_OFF_SHIFT (0x00000000u)
#define CSL_VPBE_PCR_CLK_OFF_RESETVAL (0x00000000u)
/*----CLK_OFF Tokens----*/
#define CSL_VPBE_PCR_CLK_OFF_ON (0x00000000u)
#define CSL_VPBE_PCR_CLK_OFF_OFF (0x00000001u)

#define CSL_VPBE_PCR_RESETVAL (0x00000000u)

#endif

