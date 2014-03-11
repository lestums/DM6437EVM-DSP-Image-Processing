/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** ============================================================================
 *   @file  cslr_vpss.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for VPSS
 *          Reference: User Guide 
 *  ============================================================================
 */
#ifndef _CSLR_VPSS_H_
#define _CSLR_VPSS_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 PCR;
    volatile Uint32 _RESV[64];
    volatile Uint32 SDR_REQ_EXP;
} CSL_VpssRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_VpssRegs         *CSL_VpssRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */


#define CSL_VPSS_PID_TID_MASK (0x00FF0000u)
#define CSL_VPSS_PID_TID_SHIFT (0x00000010u)
#define CSL_VPSS_PID_TID_RESETVAL (0x00000001u)

#define CSL_VPSS_PID_CID_MASK (0x0000FF00u)
#define CSL_VPSS_PID_CID_SHIFT (0x00000008u)
#define CSL_VPSS_PID_CID_RESETVAL (0x000000FBu)

#define CSL_VPSS_PID_PREV_MASK (0x000000FFu)
#define CSL_VPSS_PID_PREV_SHIFT (0x00000000u)
#define CSL_VPSS_PID_PREV_RESETVAL (0x00000000u)

#define CSL_VPSS_PID_RESETVAL (0x0001FB00u)

/* PCR */


#define CSL_VPSS_PCR_CCDC_WBL_O_MASK (0x00800000u)
#define CSL_VPSS_PCR_CCDC_WBL_O_SHIFT (0x00000017u)
#define CSL_VPSS_PCR_CCDC_WBL_O_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_PRV_WBL_O_MASK (0x00400000u)
#define CSL_VPSS_PCR_PRV_WBL_O_SHIFT (0x00000016u)
#define CSL_VPSS_PCR_PRV_WBL_O_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_RSZ1_WBL_O_MASK (0x00200000u)
#define CSL_VPSS_PCR_RSZ1_WBL_O_SHIFT (0x00000015u)
#define CSL_VPSS_PCR_RSZ1_WBL_O_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_RSZ2_WBL_O_MASK (0x00100000u)
#define CSL_VPSS_PCR_RSZ2_WBL_O_SHIFT (0x00000014u)
#define CSL_VPSS_PCR_RSZ2_WBL_O_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_RSZ3_WBL_O_MASK (0x00080000u)
#define CSL_VPSS_PCR_RSZ3_WBL_O_SHIFT (0x00000013u)
#define CSL_VPSS_PCR_RSZ3_WBL_O_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_RSZ4_WBL_O_MASK (0x00040000u)
#define CSL_VPSS_PCR_RSZ4_WBL_O_SHIFT (0x00000012u)
#define CSL_VPSS_PCR_RSZ4_WBL_O_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_AF_WBL_O_MASK (0x00020000u)
#define CSL_VPSS_PCR_AF_WBL_O_SHIFT (0x00000011u)
#define CSL_VPSS_PCR_AF_WBL_O_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_AEW_WBL_O_MASK (0x00010000u)
#define CSL_VPSS_PCR_AEW_WBL_O_SHIFT (0x00000010u)
#define CSL_VPSS_PCR_AEW_WBL_O_RESETVAL (0x00000000u)


#define CSL_VPSS_PCR_DMA_PRI_MASK (0x0000000Fu)
#define CSL_VPSS_PCR_DMA_PRI_SHIFT (0x00000000u)
#define CSL_VPSS_PCR_DMA_PRI_RESETVAL (0x00000000u)

#define CSL_VPSS_PCR_RESETVAL (0x00000000u)

/* _RESV */


#define CSL_VPSS__RESV_RESETVAL (0x00000000u)

/* SDR_REQ_EXP */


#define CSL_VPSS_SDR_REQ_EXP_PRV_EXP_MASK (0x3FF00000u)
#define CSL_VPSS_SDR_REQ_EXP_PRV_EXP_SHIFT (0x00000014u)
#define CSL_VPSS_SDR_REQ_EXP_PRV_EXP_RESETVAL (0x00000000u)

#define CSL_VPSS_SDR_REQ_EXP_RESZ_EXP_MASK (0x000FFC00u)
#define CSL_VPSS_SDR_REQ_EXP_RESZ_EXP_SHIFT (0x0000000Au)
#define CSL_VPSS_SDR_REQ_EXP_RESZ_EXP_RESETVAL (0x00000000u)

#define CSL_VPSS_SDR_REQ_EXP_HIST_EXP_MASK (0x000003FFu)
#define CSL_VPSS_SDR_REQ_EXP_HIST_EXP_SHIFT (0x00000000u)
#define CSL_VPSS_SDR_REQ_EXP_HIST_EXP_RESETVAL (0x00000000u)

#define CSL_VPSS_SDR_REQ_EXP_RESETVAL (0x00000000u)

#endif


