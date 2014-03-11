/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** ============================================================================
 *   @file  cslr_cache.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for CACHE
 *          Reference: User Guide SPRU871F
 *  ============================================================================
 */
#ifndef _CSLR_CACHE_H_
#define _CSLR_CACHE_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 L2CFG;
    volatile Uint8 RSVD0[28];
    volatile Uint32 L1PCFG;
    volatile Uint32 L1PCC;
    volatile Uint8 RSVD1[24];
    volatile Uint32 L1DCFG;
    volatile Uint32 L1DCC;
    volatile Uint8 RSVD2[16312];
    volatile Uint32 L2WBAR;
    volatile Uint32 L2WWC;
    volatile Uint8 RSVD3[8];
    volatile Uint32 L2WIBAR;
    volatile Uint32 L2WIWC;
    volatile Uint32 L2IBAR;
    volatile Uint32 L2IWC;
    volatile Uint32 L1PIBAR;
    volatile Uint32 L1PIWC;
    volatile Uint8 RSVD4[8];
    volatile Uint32 L1DWIBAR;
    volatile Uint32 L1DWIWC;
    volatile Uint8 RSVD5[8];
    volatile Uint32 L1DWBAR;
    volatile Uint32 L1DWWC;
    volatile Uint32 L1DIBAR;
    volatile Uint32 L1DIWC;
    volatile Uint8 RSVD6[4016];
    volatile Uint32 L2WB;
    volatile Uint32 L2WBINV;
    volatile Uint32 L2INV;
    volatile Uint8 RSVD7[28];
    volatile Uint32 L1PINV;
    volatile Uint8 RSVD8[20];
    volatile Uint32 L1DWB;
    volatile Uint32 L1DWBINV;
    volatile Uint32 L1DINV;
    volatile Uint8 RSVD9[12212];
    volatile Uint32 MAR[256];
} CSL_CacheRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_CacheRegs         *CSL_CacheRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* L2CFG */


#define CSL_CACHE_L2CFG_NUM_MM_MASK (0x0F000000u)
#define CSL_CACHE_L2CFG_NUM_MM_SHIFT (0x00000018u)
#define CSL_CACHE_L2CFG_NUM_MM_RESETVAL (0x00000000u)


#define CSL_CACHE_L2CFG_MMID_MASK (0x000F0000u)
#define CSL_CACHE_L2CFG_MMID_SHIFT (0x00000010u)
#define CSL_CACHE_L2CFG_MMID_RESETVAL (0x00000000u)


#define CSL_CACHE_L2CFG_IP_MASK (0x00000200u)
#define CSL_CACHE_L2CFG_IP_SHIFT (0x00000009u)
#define CSL_CACHE_L2CFG_IP_RESETVAL (0x00000000u)
/*----IP Tokens----*/
#define CSL_CACHE_L2CFG_IP_NORMAL (0x00000000u)
#define CSL_CACHE_L2CFG_IP_INVALIDATE (0x00000001u)

#define CSL_CACHE_L2CFG_ID_MASK (0x00000100u)
#define CSL_CACHE_L2CFG_ID_SHIFT (0x00000008u)
#define CSL_CACHE_L2CFG_ID_RESETVAL (0x00000000u)
/*----ID Tokens----*/
#define CSL_CACHE_L2CFG_ID_NORMAL (0x00000000u)
#define CSL_CACHE_L2CFG_ID_INVALIDATE (0x00000001u)


#define CSL_CACHE_L2CFG_L2CC_MASK (0x00000008u)
#define CSL_CACHE_L2CFG_L2CC_SHIFT (0x00000003u)
#define CSL_CACHE_L2CFG_L2CC_RESETVAL (0x00000000u)
/*----L2CC Tokens----*/
#define CSL_CACHE_L2CFG_L2CC_NORMAL (0x00000000u)
#define CSL_CACHE_L2CFG_L2CC_FREEZE (0x00000001u)

#define CSL_CACHE_L2CFG_MODE_MASK (0x00000007u)
#define CSL_CACHE_L2CFG_MODE_SHIFT (0x00000000u)
#define CSL_CACHE_L2CFG_MODE_RESETVAL (0x00000000u)
/*----MODE Tokens----*/
#define CSL_CACHE_L2CFG_MODE_DISABLE (0x00000000u)
#define CSL_CACHE_L2CFG_MODE_0K (0x00000000u)
#define CSL_CACHE_L2CFG_MODE_32K (0x00000001u)
#define CSL_CACHE_L2CFG_MODE_64K (0x00000002u)
#define CSL_CACHE_L2CFG_MODE_128K (0x00000003u)
#define CSL_CACHE_L2CFG_MODE_256K (0x00000004u)
#define CSL_CACHE_L2CFG_MODE_MAX (0x00000005u)

#define CSL_CACHE_L2CFG_RESETVAL (0x00000000u)

/* L1PCFG */


#define CSL_CACHE_L1PCFG_MODE_MASK (0x00000007u)
#define CSL_CACHE_L1PCFG_MODE_SHIFT (0x00000000u)
#define CSL_CACHE_L1PCFG_MODE_RESETVAL (0x00000000u)
/*----MODE Tokens----*/
#define CSL_CACHE_L1PCFG_MODE_DISABLE (0x00000000u)
#define CSL_CACHE_L1PCFG_MODE_0K (0x00000000u)
#define CSL_CACHE_L1PCFG_MODE_4K (0x00000001u)
#define CSL_CACHE_L1PCFG_MODE_8K (0x00000002u)
#define CSL_CACHE_L1PCFG_MODE_16K (0x00000003u)
#define CSL_CACHE_L1PCFG_MODE_32K (0x00000004u)
#define CSL_CACHE_L1PCFG_MODE_MAX (0x00000005u)

#define CSL_CACHE_L1PCFG_RESETVAL (0x00000000u)

/* L1PCC */


#define CSL_CACHE_L1PCC_POPER_MASK (0x00010000u)
#define CSL_CACHE_L1PCC_POPER_SHIFT (0x00000010u)
#define CSL_CACHE_L1PCC_POPER_RESETVAL (0x00000000u)
/*----POPER Tokens----*/
#define CSL_CACHE_L1PCC_POPER_NORM (0x00000000u)
#define CSL_CACHE_L1PCC_POPER_FREEZE (0x00000001u)


#define CSL_CACHE_L1PCC_OPER_MASK (0x00000001u)
#define CSL_CACHE_L1PCC_OPER_SHIFT (0x00000000u)
#define CSL_CACHE_L1PCC_OPER_RESETVAL (0x00000000u)
/*----OPER Tokens----*/
#define CSL_CACHE_L1PCC_OPER_NORM (0x00000000u)
#define CSL_CACHE_L1PCC_OPER_FREEZE (0x00000001u)

#define CSL_CACHE_L1PCC_RESETVAL (0x00000000u)

/* L1DCFG */


#define CSL_CACHE_L1DCFG_MODE_MASK (0x00000007u)
#define CSL_CACHE_L1DCFG_MODE_SHIFT (0x00000000u)
#define CSL_CACHE_L1DCFG_MODE_RESETVAL (0x00000000u)
/*----MODE Tokens----*/
#define CSL_CACHE_L1DCFG_MODE_DISABLE (0x00000000u)
#define CSL_CACHE_L1DCFG_MODE_0K (0x00000000u)
#define CSL_CACHE_L1DCFG_MODE_4K (0x00000001u)
#define CSL_CACHE_L1DCFG_MODE_8K (0x00000002u)
#define CSL_CACHE_L1DCFG_MODE_16K (0x00000003u)
#define CSL_CACHE_L1DCFG_MODE_32K (0x00000004u)
#define CSL_CACHE_L1DCFG_MODE_MAX (0x00000005u)

#define CSL_CACHE_L1DCFG_RESETVAL (0x00000000u)

/* L1DCC */


#define CSL_CACHE_L1DCC_POPER_MASK (0x00010000u)
#define CSL_CACHE_L1DCC_POPER_SHIFT (0x00000010u)
#define CSL_CACHE_L1DCC_POPER_RESETVAL (0x00000000u)
/*----POPER Tokens----*/
#define CSL_CACHE_L1DCC_POPER_NORMAL (0x00000000u)
#define CSL_CACHE_L1DCC_POPER_FREEZE (0x00000001u)


#define CSL_CACHE_L1DCC_OPER_MASK (0x00000001u)
#define CSL_CACHE_L1DCC_OPER_SHIFT (0x00000000u)
#define CSL_CACHE_L1DCC_OPER_RESETVAL (0x00000000u)
/*----OPER Tokens----*/
#define CSL_CACHE_L1DCC_OPER_NORM (0x00000000u)
#define CSL_CACHE_L1DCC_OPER_FREEZE (0x00000001u)

#define CSL_CACHE_L1DCC_RESETVAL (0x00000000u)

/* L2WBAR */

#define CSL_CACHE_L2WBAR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CACHE_L2WBAR_ADDR_SHIFT (0x00000000u)
#define CSL_CACHE_L2WBAR_ADDR_RESETVAL (0x00000000u)

#define CSL_CACHE_L2WBAR_RESETVAL (0x00000000u)

/* L2WWC */


#define CSL_CACHE_L2WWC_CNT_MASK (0x0000FFFFu)
#define CSL_CACHE_L2WWC_CNT_SHIFT (0x00000000u)
#define CSL_CACHE_L2WWC_CNT_RESETVAL (0x00000000u)

#define CSL_CACHE_L2WWC_RESETVAL (0x00000000u)

/* L2WIBAR */

#define CSL_CACHE_L2WIBAR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CACHE_L2WIBAR_ADDR_SHIFT (0x00000000u)
#define CSL_CACHE_L2WIBAR_ADDR_RESETVAL (0x00000000u)

#define CSL_CACHE_L2WIBAR_RESETVAL (0x00000000u)

/* L2WIWC */


#define CSL_CACHE_L2WIWC_CNT_MASK (0x0000FFFFu)
#define CSL_CACHE_L2WIWC_CNT_SHIFT (0x00000000u)
#define CSL_CACHE_L2WIWC_CNT_RESETVAL (0x00000000u)

#define CSL_CACHE_L2WIWC_RESETVAL (0x00000000u)

/* L2IBAR */

#define CSL_CACHE_L2IBAR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CACHE_L2IBAR_ADDR_SHIFT (0x00000000u)
#define CSL_CACHE_L2IBAR_ADDR_RESETVAL (0x00000000u)

#define CSL_CACHE_L2IBAR_RESETVAL (0x00000000u)

/* L2IWC */


#define CSL_CACHE_L2IWC_CNT_MASK (0x0000FFFFu)
#define CSL_CACHE_L2IWC_CNT_SHIFT (0x00000000u)
#define CSL_CACHE_L2IWC_CNT_RESETVAL (0x00000000u)

#define CSL_CACHE_L2IWC_RESETVAL (0x00000000u)

/* L1PIBAR */

#define CSL_CACHE_L1PIBAR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CACHE_L1PIBAR_ADDR_SHIFT (0x00000000u)
#define CSL_CACHE_L1PIBAR_ADDR_RESETVAL (0x00000000u)

#define CSL_CACHE_L1PIBAR_RESETVAL (0x00000000u)

/* L1PIWC */


#define CSL_CACHE_L1PIWC_CNT_MASK (0x0000FFFFu)
#define CSL_CACHE_L1PIWC_CNT_SHIFT (0x00000000u)
#define CSL_CACHE_L1PIWC_CNT_RESETVAL (0x00000000u)

#define CSL_CACHE_L1PIWC_RESETVAL (0x00000000u)

/* L1DWIBAR */

#define CSL_CACHE_L1DWIBAR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CACHE_L1DWIBAR_ADDR_SHIFT (0x00000000u)
#define CSL_CACHE_L1DWIBAR_ADDR_RESETVAL (0x00000000u)

#define CSL_CACHE_L1DWIBAR_RESETVAL (0x00000000u)

/* L1DWIWC */


#define CSL_CACHE_L1DWIWC_CNT_MASK (0x0000FFFFu)
#define CSL_CACHE_L1DWIWC_CNT_SHIFT (0x00000000u)
#define CSL_CACHE_L1DWIWC_CNT_RESETVAL (0x00000000u)

#define CSL_CACHE_L1DWIWC_RESETVAL (0x00000000u)

/* L1DWBAR */

#define CSL_CACHE_L1DWBAR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CACHE_L1DWBAR_ADDR_SHIFT (0x00000000u)
#define CSL_CACHE_L1DWBAR_ADDR_RESETVAL (0x00000000u)

#define CSL_CACHE_L1DWBAR_RESETVAL (0x00000000u)

/* L1DWWC */


#define CSL_CACHE_L1DWWC_CNT_MASK (0x0000FFFFu)
#define CSL_CACHE_L1DWWC_CNT_SHIFT (0x00000000u)
#define CSL_CACHE_L1DWWC_CNT_RESETVAL (0x00000000u)

#define CSL_CACHE_L1DWWC_RESETVAL (0x00000000u)

/* L1DIBAR */

#define CSL_CACHE_L1DIBAR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CACHE_L1DIBAR_ADDR_SHIFT (0x00000000u)
#define CSL_CACHE_L1DIBAR_ADDR_RESETVAL (0x00000000u)

#define CSL_CACHE_L1DIBAR_RESETVAL (0x00000000u)

/* L1DIWC */


#define CSL_CACHE_L1DIWC_CNT_MASK (0x0000FFFFu)
#define CSL_CACHE_L1DIWC_CNT_SHIFT (0x00000000u)
#define CSL_CACHE_L1DIWC_CNT_RESETVAL (0x00000000u)

#define CSL_CACHE_L1DIWC_RESETVAL (0x00000000u)

/* L2WB */


#define CSL_CACHE_L2WB_CMDANDSTAT_MASK (0x00000001u)
#define CSL_CACHE_L2WB_CMDANDSTAT_SHIFT (0x00000000u)
#define CSL_CACHE_L2WB_CMDANDSTAT_RESETVAL (0x00000000u)
/*----CMDANDSTAT Tokens----*/
#define CSL_CACHE_L2WB_CMDANDSTAT_WB (0x00000001u)
#define CSL_CACHE_L2WB_CMDANDSTAT_NORMAL (0x00000000u)

#define CSL_CACHE_L2WB_RESETVAL (0x00000000u)

/* L2WBINV */


#define CSL_CACHE_L2WBINV_CMDANDSTAT_MASK (0x00000001u)
#define CSL_CACHE_L2WBINV_CMDANDSTAT_SHIFT (0x00000000u)
#define CSL_CACHE_L2WBINV_CMDANDSTAT_RESETVAL (0x00000000u)
/*----CMDANDSTAT Tokens----*/
#define CSL_CACHE_L2WBINV_CMDANDSTAT_WBINV (0x00000001u)
#define CSL_CACHE_L2WBINV_CMDANDSTAT_NORMAL (0x00000000u)

#define CSL_CACHE_L2WBINV_RESETVAL (0x00000000u)

/* L2INV */


#define CSL_CACHE_L2INV_CMDANDSTAT_MASK (0x00000001u)
#define CSL_CACHE_L2INV_CMDANDSTAT_SHIFT (0x00000000u)
#define CSL_CACHE_L2INV_CMDANDSTAT_RESETVAL (0x00000000u)
/*----CMDANDSTAT Tokens----*/
#define CSL_CACHE_L2INV_CMDANDSTAT_INV (0x00000001u)
#define CSL_CACHE_L2INV_CMDANDSTAT_NORMAL (0x00000000u)

#define CSL_CACHE_L2INV_RESETVAL (0x00000000u)

/* L1PINV */


#define CSL_CACHE_L1PINV_CMDANDSTAT_MASK (0x00000001u)
#define CSL_CACHE_L1PINV_CMDANDSTAT_SHIFT (0x00000000u)
#define CSL_CACHE_L1PINV_CMDANDSTAT_RESETVAL (0x00000000u)
/*----CMDANDSTAT Tokens----*/
#define CSL_CACHE_L1PINV_CMDANDSTAT_INV (0x00000001u)
#define CSL_CACHE_L1PINV_CMDANDSTAT_NORMAL (0x00000000u)

#define CSL_CACHE_L1PINV_RESETVAL (0x00000000u)

/* L1DWB */


#define CSL_CACHE_L1DWB_CMDANDSTAT_MASK (0x00000001u)
#define CSL_CACHE_L1DWB_CMDANDSTAT_SHIFT (0x00000000u)
#define CSL_CACHE_L1DWB_CMDANDSTAT_RESETVAL (0x00000000u)
/*----CMDANDSTAT Tokens----*/
#define CSL_CACHE_L1DWB_CMDANDSTAT_WB (0x00000001u)
#define CSL_CACHE_L1DWB_CMDANDSTAT_NORMAL (0x00000000u)

#define CSL_CACHE_L1DWB_RESETVAL (0x00000000u)

/* L1DWBINV */


#define CSL_CACHE_L1DWBINV_CMDANDSTAT_MASK (0x00000001u)
#define CSL_CACHE_L1DWBINV_CMDANDSTAT_SHIFT (0x00000000u)
#define CSL_CACHE_L1DWBINV_CMDANDSTAT_RESETVAL (0x00000000u)
/*----CMDANDSTAT Tokens----*/
#define CSL_CACHE_L1DWBINV_CMDANDSTAT_WBINV (0x00000001u)
#define CSL_CACHE_L1DWBINV_CMDANDSTAT_NORMAL (0x00000000u)

#define CSL_CACHE_L1DWBINV_RESETVAL (0x00000000u)

/* L1DINV */


#define CSL_CACHE_L1DINV_CMDANDSTAT_MASK (0x00000001u)
#define CSL_CACHE_L1DINV_CMDANDSTAT_SHIFT (0x00000000u)
#define CSL_CACHE_L1DINV_CMDANDSTAT_RESETVAL (0x00000000u)
/*----CMDANDSTAT Tokens----*/
#define CSL_CACHE_L1DINV_CMDANDSTAT_INV (0x00000001u)
#define CSL_CACHE_L1DINV_CMDANDSTAT_NORMAL (0x00000000u)

#define CSL_CACHE_L1DINV_RESETVAL (0x00000000u)

/* MAR */


#define CSL_CACHE_MAR_PC_MASK (0x00000001u)
#define CSL_CACHE_MAR_PC_SHIFT (0x00000000u)
#define CSL_CACHE_MAR_PC_RESETVAL (0x00000000u)
/*----PC Tokens----*/
#define CSL_CACHE_MAR_PC_NOT_CACHEABLE (0x00000000u)
#define CSL_CACHE_MAR_PC_CACHEABLE (0x00000001u)

#define CSL_CACHE_MAR_RESETVAL (0x00000000u)

#endif

