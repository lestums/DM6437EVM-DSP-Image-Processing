/* =============================================================================
 *  Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *  Use of this software is controlled by the terms and conditions found in the
 *  license agreement under which this software has been supplied.
 *  ============================================================================
 */
/** ============================================================================
 *   file   cslr_ewrap.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *  @desc  This file contains the Register Desciptions for EWRAP
 *  ============================================================================
 */
#ifndef _CSLR_EWRAP_H 
#define _CSLR_EWRAP_H 

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
} CSL_EwrapRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* EWCTL */


#define CSL_EWRAP_EWCTL_INTEN_MASK (0x00000001u)
#define CSL_EWRAP_EWCTL_INTEN_SHIFT (0x00000000u)
#define CSL_EWRAP_EWCTL_INTEN_RESETVAL (0x00000000u)
/*----INTEN Tokens----*/
#define CSL_EWRAP_EWCTL_INTEN_DISABLE (0x00000000u)
#define CSL_EWRAP_EWCTL_INTEN_ENABLE (0x00000001u)

#define CSL_EWRAP_EWCTL_RESETVAL (0x00000000u)

/* EWINTTCNT */


#define CSL_EWRAP_EWINTTCNT_EWINTTCNT_MASK (0x0001FFFFu)
#define CSL_EWRAP_EWINTTCNT_EWINTTCNT_SHIFT (0x00000000u)
#define CSL_EWRAP_EWINTTCNT_EWINTTCNT_RESETVAL (0x00000000u)

#define CSL_EWRAP_EWINTTCNT_RESETVAL (0x00000000u)

#endif
