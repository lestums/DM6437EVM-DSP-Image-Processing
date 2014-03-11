/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *  Use of this software is controlled by the terms and conditions found in the
 *  license agreement under which this software has been supplied.
 *   ===========================================================================
 */ 
/** ============================================================================
 *   @file  cslr_hpi.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for HPI
 *          Reference: User Guide SPRU998C
 *  ============================================================================
 */
#ifndef _CSLR_HPI_H_
#define _CSLR_HPI_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 PWREMU_MGMT;
    volatile Uint8 RSVD0[40];
    volatile Uint32 HPIC;
    volatile Uint32 HPIAW;
    volatile Uint32 HPIAR;
} CSL_HpiRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_HpiRegs  *CSL_HpiRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */


#define CSL_HPI_PID_TID_MASK (0x00FF0000u)
#define CSL_HPI_PID_TID_SHIFT (0x00000010u)
#define CSL_HPI_PID_TID_RESETVAL (0x00000001u)

#define CSL_HPI_PID_CID_MASK (0x0000FF00u)
#define CSL_HPI_PID_CID_SHIFT (0x00000008u)
#define CSL_HPI_PID_CID_RESETVAL (0x00000002u)

#define CSL_HPI_PID_PREV_MASK (0x000000FFu)
#define CSL_HPI_PID_PREV_SHIFT (0x00000000u)
#define CSL_HPI_PID_PREV_RESETVAL (0x00000000u)

#define CSL_HPI_PID_RESETVAL (0x00010200u)

/* PWREMU_MGMT */


#define CSL_HPI_PWREMU_MGMT_SOFT_MASK    (0x00000002u)
#define CSL_HPI_PWREMU_MGMT_SOFT_SHIFT   (0x00000001u)
#define CSL_HPI_PWREMU_MGMT_SOFT_RESETVAL (0x00000000u)
/*----SOFT Tokens----*/
#define CSL_HPI_PWREMU_MGMT_SOFT_OFF     (0x00000000u)
#define CSL_HPI_PWREMU_MGMT_SOFT_ON      (0x00000001u)

#define CSL_HPI_PWREMU_MGMT_FREE_MASK    (0x00000001u)
#define CSL_HPI_PWREMU_MGMT_FREE_SHIFT   (0x00000000u)
#define CSL_HPI_PWREMU_MGMT_FREE_RESETVAL (0x00000000u)
/*----FREE Tokens----*/
#define CSL_HPI_PWREMU_MGMT_FREE_OFF     (0x00000000u)
#define CSL_HPI_PWREMU_MGMT_FREE_ON      (0x00000001u)

#define CSL_HPI_PWREMU_MGMT_RESETVAL     (0x00000000u)

/* HPIC */


#define CSL_HPI_HPIC_HPIASEL_MASK (0x00000800u)
#define CSL_HPI_HPIC_HPIASEL_SHIFT (0x0000000Bu)
#define CSL_HPI_HPIC_HPIASEL_RESETVAL (0x00000000u)
/*----HPIASEL Tokens----*/
#define CSL_HPI_HPIC_HPIASEL_WRITE (0x00000000u)
#define CSL_HPI_HPIC_HPIASEL_READ (0x00000001u)


#define CSL_HPI_HPIC_DUALHPIA_MASK       (0x00000200u)
#define CSL_HPI_HPIC_DUALHPIA_SHIFT      (0x00000009u)
#define CSL_HPI_HPIC_DUALHPIA_RESETVAL   (0x00000000u)
/*----DUALHPIA Tokens----*/
#define CSL_HPI_HPIC_DUALHPIA_DISABLE    (0x00000000u)
#define CSL_HPI_HPIC_DUALHPIA_ENABLE     (0x00000001u)

#define CSL_HPI_HPIC_HWOBSTAT_MASK       (0x00000100u)
#define CSL_HPI_HPIC_HWOBSTAT_SHIFT      (0x00000008u)
#define CSL_HPI_HPIC_HWOBSTAT_RESETVAL   (0x00000000u)
/*----HWOBSTAT Tokens----*/
#define CSL_HPI_HPIC_HWOBSTAT_LOGIC0 (0x00000000u)
#define CSL_HPI_HPIC_HWOBSTAT_LOGIC1 (0x00000001u)



#define CSL_HPI_HPIC_FETCH_MASK          (0x00000010u)
#define CSL_HPI_HPIC_FETCH_SHIFT         (0x00000004u)
#define CSL_HPI_HPIC_FETCH_RESETVAL      (0x00000000u)


#define CSL_HPI_HPIC_HINT_MASK           (0x00000004u)
#define CSL_HPI_HPIC_HINT_SHIFT          (0x00000002u)
#define CSL_HPI_HPIC_HINT_RESETVAL       (0x00000000u)
/*----HINT Tokens----*/
#define CSL_HPI_HPIC_HINT_ENABLE         (0x00000001u)

#define CSL_HPI_HPIC_DSPINT_MASK (0x00000002u)
#define CSL_HPI_HPIC_DSPINT_SHIFT (0x00000001u)
#define CSL_HPI_HPIC_DSPINT_RESETVAL (0x00000000u)
/*----DSPINT Tokens----*/
#define CSL_HPI_HPIC_DSPINT_ENABLE (0x00000001u)

#define CSL_HPI_HPIC_HWOB_MASK           (0x00000001u)
#define CSL_HPI_HPIC_HWOB_SHIFT          (0x00000000u)
#define CSL_HPI_HPIC_HWOB_RESETVAL       (0x00000000u)
/*----HWOB Tokens----*/
#define CSL_HPI_HPIC_HWOB_MS (0x00000000u)
#define CSL_HPI_HPIC_HWOB_LS (0x00000001u)

#define CSL_HPI_HPIC_RESETVAL (0x00000008u)

/* HPIAW */

#define CSL_HPI_HPIAW_HPIAW_MASK         (0xFFFFFFFFu)
#define CSL_HPI_HPIAW_HPIAW_SHIFT        (0x00000000u)
#define CSL_HPI_HPIAW_HPIAW_RESETVAL (0x00008000u)

#define CSL_HPI_HPIAW_RESETVAL (0x00008000u)

/* HPIAR */

#define CSL_HPI_HPIAR_HPIAR_MASK         (0xFFFFFFFFu)
#define CSL_HPI_HPIAR_HPIAR_SHIFT        (0x00000000u)
#define CSL_HPI_HPIAR_HPIAR_RESETVAL (0x00008000u)

#define CSL_HPI_HPIAR_RESETVAL (0x00008000u)

#endif

