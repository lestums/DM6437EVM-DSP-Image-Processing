/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** ============================================================================
 *   @file  cslr_ectl.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for ECTL
 *          Reference: User Guide SPRU941
 *  ============================================================================
 */
#ifndef _CSLR_ECTL_H_
#define _CSLR_ECTL_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint8 RSVD0[4];
    volatile Uint32 EWCTL;
    volatile Uint32 EWINTTCNT;
} CSL_EctlRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_EctlRegs         *CSL_EctlRegsOvly;


/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* EWCTL */


#define CSL_ECTL_EWCTL_INTEN_MASK (0x00000001u)
#define CSL_ECTL_EWCTL_INTEN_SHIFT (0x00000000u)
#define CSL_ECTL_EWCTL_INTEN_RESETVAL (0x00000000u)
/*----INTEN Tokens----*/
#define CSL_ECTL_EWCTL_INTEN_DISABLE (0x00000000u)
#define CSL_ECTL_EWCTL_INTEN_ENABLE (0x00000001u)

#define CSL_ECTL_EWCTL_RESETVAL (0x00000000u)

/* EWINTTCNT */


#define CSL_ECTL_EWINTTCNT_EWINTTCNT_MASK (0x0001FFFFu)
#define CSL_ECTL_EWINTTCNT_EWINTTCNT_SHIFT (0x00000000u)
#define CSL_ECTL_EWINTTCNT_EWINTTCNT_RESETVAL (0x00000000u)

#define CSL_ECTL_EWINTTCNT_RESETVAL (0x00000000u)

#endif

