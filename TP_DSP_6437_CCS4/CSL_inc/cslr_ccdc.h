/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** ============================================================================
 *   @file  cslr_ccdc.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for CCDC
 *  ============================================================================
 */
#ifndef _CSLR_CCDC_H_
#define _CSLR_CCDC_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 PCR;
    volatile Uint32 SYN_MODE;
    volatile Uint32 HD_VD_WID;
    volatile Uint32 PIX_LINES;
    volatile Uint32 HORZ_INFO;
    volatile Uint32 VERT_START;
    volatile Uint32 VERT_LINES;
    volatile Uint32 CULLING;
    volatile Uint32 HSIZE_OFF;
    volatile Uint32 SDOFST;
    volatile Uint32 SDR_ADDR;
    volatile Uint32 CLAMP;
    volatile Uint32 DCSUB;
    volatile Uint32 COLPTN;
    volatile Uint32 BLKCMP;
    volatile Uint32 FPC;
    volatile Uint32 FPC_ADDR;
    volatile Uint32 VDINT;
    volatile Uint32 ALAW;
    volatile Uint32 REC656IF;
    volatile Uint32 CCDCFG;
    volatile Uint32 FMTCFG;
    volatile Uint32 FMT_HORZ;
    volatile Uint32 FMT_VERT;
    volatile Uint8 RSVD0[48];
    volatile Uint32 VP_OUT;
} CSL_CcdcRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_CcdcRegs         *CSL_CcdcRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */


#define CSL_CCDC_PID_TID_MASK (0x00FF0000u)
#define CSL_CCDC_PID_TID_SHIFT (0x00000010u)
#define CSL_CCDC_PID_TID_RESETVAL (0x00000001u)

#define CSL_CCDC_PID_CID_MASK (0x0000FF00u)
#define CSL_CCDC_PID_CID_SHIFT (0x00000008u)
#define CSL_CCDC_PID_CID_RESETVAL (0x000000FEu)

#define CSL_CCDC_PID_PREV_MASK (0x000000FFu)
#define CSL_CCDC_PID_PREV_SHIFT (0x00000000u)
#define CSL_CCDC_PID_PREV_RESETVAL (0x00000000u)

#define CSL_CCDC_PID_RESETVAL (0x0001FE00u)

/* PCR */




#define CSL_CCDC_PCR_BUSY_MASK (0x00000002u)
#define CSL_CCDC_PCR_BUSY_SHIFT (0x00000001u)
#define CSL_CCDC_PCR_BUSY_RESETVAL (0x00000000u)
/*----BUSY Tokens----*/
#define CSL_CCDC_PCR_BUSY_NOTBUSY (0x00000000u)
#define CSL_CCDC_PCR_BUSY_BUSY (0x00000001u)

#define CSL_CCDC_PCR_ENABLE_MASK (0x00000001u)
#define CSL_CCDC_PCR_ENABLE_SHIFT (0x00000000u)
#define CSL_CCDC_PCR_ENABLE_RESETVAL (0x00000000u)
/*----ENABLE Tokens----*/
#define CSL_CCDC_PCR_ENABLE_DISABLE (0x00000000u)
#define CSL_CCDC_PCR_ENABLE_ENABLE (0x00000001u)

#define CSL_CCDC_PCR_RESETVAL (0x00000000u)

/* SYN_MODE */


#define CSL_CCDC_SYN_MODE_SDR2RSZ_MASK (0x00080000u)
#define CSL_CCDC_SYN_MODE_SDR2RSZ_SHIFT (0x00000013u)
#define CSL_CCDC_SYN_MODE_SDR2RSZ_RESETVAL (0x00000000u)
/*----SDR2RSZ Tokens----*/
#define CSL_CCDC_SYN_MODE_SDR2RSZ_DISABLE (0x00000000u)
#define CSL_CCDC_SYN_MODE_SDR2RSZ_ENABLE (0x00000001u)

#define CSL_CCDC_SYN_MODE_VP2SDR_MASK (0x00040000u)
#define CSL_CCDC_SYN_MODE_VP2SDR_SHIFT (0x00000012u)
#define CSL_CCDC_SYN_MODE_VP2SDR_RESETVAL (0x00000000u)
/*----VP2SDR Tokens----*/
#define CSL_CCDC_SYN_MODE_VP2SDR_DISABLE (0x00000000u)
#define CSL_CCDC_SYN_MODE_VP2SDR_ENABLE (0x00000001u)

#define CSL_CCDC_SYN_MODE_WEN_MASK (0x00020000u)
#define CSL_CCDC_SYN_MODE_WEN_SHIFT (0x00000011u)
#define CSL_CCDC_SYN_MODE_WEN_RESETVAL (0x00000000u)
/*----WEN Tokens----*/
#define CSL_CCDC_SYN_MODE_WEN_DISABLE (0x00000000u)
#define CSL_CCDC_SYN_MODE_WEN_ENABLE (0x00000001u)

#define CSL_CCDC_SYN_MODE_VDHDEN_MASK (0x00010000u)
#define CSL_CCDC_SYN_MODE_VDHDEN_SHIFT (0x00000010u)
#define CSL_CCDC_SYN_MODE_VDHDEN_RESETVAL (0x00000000u)
/*----VDHDEN Tokens----*/
#define CSL_CCDC_SYN_MODE_VDHDEN_DISABLE (0x00000000u)
#define CSL_CCDC_SYN_MODE_VDHDEN_ENABLE (0x00000001u)

#define CSL_CCDC_SYN_MODE_FLDSTAT_MASK (0x00008000u)
#define CSL_CCDC_SYN_MODE_FLDSTAT_SHIFT (0x0000000Fu)
#define CSL_CCDC_SYN_MODE_FLDSTAT_RESETVAL (0x00000000u)
/*----FLDSTAT Tokens----*/
#define CSL_CCDC_SYN_MODE_FLDSTAT_ODDFIELD (0x00000000u)
#define CSL_CCDC_SYN_MODE_FLDSTAT_EVENFIELD (0x00000001u)

#define CSL_CCDC_SYN_MODE_LPF_MASK (0x00004000u)
#define CSL_CCDC_SYN_MODE_LPF_SHIFT (0x0000000Eu)
#define CSL_CCDC_SYN_MODE_LPF_RESETVAL (0x00000000u)
/*----LPF Tokens----*/
#define CSL_CCDC_SYN_MODE_LPF_OFF (0x00000000u)
#define CSL_CCDC_SYN_MODE_LPF_ON (0x00000001u)

#define CSL_CCDC_SYN_MODE_INPMOD_MASK (0x00003000u)
#define CSL_CCDC_SYN_MODE_INPMOD_SHIFT (0x0000000Cu)
#define CSL_CCDC_SYN_MODE_INPMOD_RESETVAL (0x00000000u)
/*----INPMOD Tokens----*/
#define CSL_CCDC_SYN_MODE_INPMOD_CCDRAW (0x00000000u)
#define CSL_CCDC_SYN_MODE_INPMOD_YCBCR16 (0x00000001u)
#define CSL_CCDC_SYN_MODE_INPMOD_YCBCR8 (0x00000002u)
#define CSL_CCDC_SYN_MODE_INPMOD_RESERVED (0x00000003u)

#define CSL_CCDC_SYN_MODE_PACK8_MASK (0x00000800u)
#define CSL_CCDC_SYN_MODE_PACK8_SHIFT (0x0000000Bu)
#define CSL_CCDC_SYN_MODE_PACK8_RESETVAL (0x00000000u)
/*----PACK8 Tokens----*/
#define CSL_CCDC_SYN_MODE_PACK8__16BITS_PIXEL (0x00000000u)
#define CSL_CCDC_SYN_MODE_PACK8__8BITS_PIXEL (0x00000001u)

#define CSL_CCDC_SYN_MODE_DATSIZ_MASK (0x00000700u)
#define CSL_CCDC_SYN_MODE_DATSIZ_SHIFT (0x00000008u)
#define CSL_CCDC_SYN_MODE_DATSIZ_RESETVAL (0x00000000u)
/*----DATSIZ Tokens----*/
#define CSL_CCDC_SYN_MODE_DATSIZ__16_BITS (0x00000000u)
#define CSL_CCDC_SYN_MODE_DATSIZ__15_BITS (0x00000001u)
#define CSL_CCDC_SYN_MODE_DATSIZ__14_BITS (0x00000002u)
#define CSL_CCDC_SYN_MODE_DATSIZ__13_BITS (0x00000003u)
#define CSL_CCDC_SYN_MODE_DATSIZ__12_BITS (0x00000004u)
#define CSL_CCDC_SYN_MODE_DATSIZ__11_BITS (0x00000005u)
#define CSL_CCDC_SYN_MODE_DATSIZ__10_BITS (0x00000006u)
#define CSL_CCDC_SYN_MODE_DATSIZ__8_BITS (0x00000007u)

#define CSL_CCDC_SYN_MODE_FLDMODE_MASK (0x00000080u)
#define CSL_CCDC_SYN_MODE_FLDMODE_SHIFT (0x00000007u)
#define CSL_CCDC_SYN_MODE_FLDMODE_RESETVAL (0x00000000u)
/*----FLDMODE Tokens----*/
#define CSL_CCDC_SYN_MODE_FLDMODE_NON_INTERLACED (0x00000000u)
#define CSL_CCDC_SYN_MODE_FLDMODE_INTERLACED (0x00000001u)

#define CSL_CCDC_SYN_MODE_DATAPOL_MASK (0x00000040u)
#define CSL_CCDC_SYN_MODE_DATAPOL_SHIFT (0x00000006u)
#define CSL_CCDC_SYN_MODE_DATAPOL_RESETVAL (0x00000000u)
/*----DATAPOL Tokens----*/
#define CSL_CCDC_SYN_MODE_DATAPOL_NORMAL (0x00000000u)
#define CSL_CCDC_SYN_MODE_DATAPOL_ONES_COMPLEMENT (0x00000001u)

#define CSL_CCDC_SYN_MODE_EXWEN_MASK (0x00000020u)
#define CSL_CCDC_SYN_MODE_EXWEN_SHIFT (0x00000005u)
#define CSL_CCDC_SYN_MODE_EXWEN_RESETVAL (0x00000000u)
/*----EXWEN Tokens----*/
#define CSL_CCDC_SYN_MODE_EXWEN_NO_EXTERNAL_WEN (0x00000000u)
#define CSL_CCDC_SYN_MODE_EXWEN_EXTERNAL_WEN (0x00000001u)

#define CSL_CCDC_SYN_MODE_FLDPOL_MASK (0x00000010u)
#define CSL_CCDC_SYN_MODE_FLDPOL_SHIFT (0x00000004u)
#define CSL_CCDC_SYN_MODE_FLDPOL_RESETVAL (0x00000000u)
/*----FLDPOL Tokens----*/
#define CSL_CCDC_SYN_MODE_FLDPOL_POSITIVE (0x00000000u)
#define CSL_CCDC_SYN_MODE_FLDPOL_NEGATIVE (0x00000001u)

#define CSL_CCDC_SYN_MODE_HDPOL_MASK (0x00000008u)
#define CSL_CCDC_SYN_MODE_HDPOL_SHIFT (0x00000003u)
#define CSL_CCDC_SYN_MODE_HDPOL_RESETVAL (0x00000000u)
/*----HDPOL Tokens----*/
#define CSL_CCDC_SYN_MODE_HDPOL_POSITIVE (0x00000000u)
#define CSL_CCDC_SYN_MODE_HDPOL_NEGATIVE (0x00000001u)

#define CSL_CCDC_SYN_MODE_VDPOL_MASK (0x00000004u)
#define CSL_CCDC_SYN_MODE_VDPOL_SHIFT (0x00000002u)
#define CSL_CCDC_SYN_MODE_VDPOL_RESETVAL (0x00000000u)
/*----VDPOL Tokens----*/
#define CSL_CCDC_SYN_MODE_VDPOL_POSITIVE (0x00000000u)
#define CSL_CCDC_SYN_MODE_VDPOL_NEGATIVE (0x00000001u)

#define CSL_CCDC_SYN_MODE_FLDOUT_MASK (0x00000002u)
#define CSL_CCDC_SYN_MODE_FLDOUT_SHIFT (0x00000001u)
#define CSL_CCDC_SYN_MODE_FLDOUT_RESETVAL (0x00000000u)
/*----FLDOUT Tokens----*/
#define CSL_CCDC_SYN_MODE_FLDOUT_INPUT (0x00000000u)
#define CSL_CCDC_SYN_MODE_FLDOUT_OUTPUT (0x00000001u)

#define CSL_CCDC_SYN_MODE_VDHDOUT_MASK (0x00000001u)
#define CSL_CCDC_SYN_MODE_VDHDOUT_SHIFT (0x00000000u)
#define CSL_CCDC_SYN_MODE_VDHDOUT_RESETVAL (0x00000000u)
/*----VDHDOUT Tokens----*/
#define CSL_CCDC_SYN_MODE_VDHDOUT_INPUT (0x00000000u)
#define CSL_CCDC_SYN_MODE_VDHDOUT_OUTPUT (0x00000001u)

#define CSL_CCDC_SYN_MODE_RESETVAL (0x00000000u)

/* HD_VD_WID */


#define CSL_CCDC_HD_VD_WID_HDW_MASK (0x0FFF0000u)
#define CSL_CCDC_HD_VD_WID_HDW_SHIFT (0x00000010u)
#define CSL_CCDC_HD_VD_WID_HDW_RESETVAL (0x00000000u)


#define CSL_CCDC_HD_VD_WID_VDW_MASK (0x00000FFFu)
#define CSL_CCDC_HD_VD_WID_VDW_SHIFT (0x00000000u)
#define CSL_CCDC_HD_VD_WID_VDW_RESETVAL (0x00000000u)

#define CSL_CCDC_HD_VD_WID_RESETVAL (0x00000000u)

/* PIX_LINES */

#define CSL_CCDC_PIX_LINES_PPLN_MASK (0xFFFF0000u)
#define CSL_CCDC_PIX_LINES_PPLN_SHIFT (0x00000010u)
#define CSL_CCDC_PIX_LINES_PPLN_RESETVAL (0x00000000u)

#define CSL_CCDC_PIX_LINES_HLPFR_MASK (0x0000FFFFu)
#define CSL_CCDC_PIX_LINES_HLPFR_SHIFT (0x00000000u)
#define CSL_CCDC_PIX_LINES_HLPFR_RESETVAL (0x00000000u)

#define CSL_CCDC_PIX_LINES_RESETVAL (0x00000000u)

/* HORZ_INFO */


#define CSL_CCDC_HORZ_INFO_SPH_MASK (0x7FFF0000u)
#define CSL_CCDC_HORZ_INFO_SPH_SHIFT (0x00000010u)
#define CSL_CCDC_HORZ_INFO_SPH_RESETVAL (0x00000000u)


#define CSL_CCDC_HORZ_INFO_NPH_MASK (0x00007FFFu)
#define CSL_CCDC_HORZ_INFO_NPH_SHIFT (0x00000000u)
#define CSL_CCDC_HORZ_INFO_NPH_RESETVAL (0x00000000u)

#define CSL_CCDC_HORZ_INFO_RESETVAL (0x00000000u)

/* VERT_START */


#define CSL_CCDC_VERT_START_SLV0_MASK (0x7FFF0000u)
#define CSL_CCDC_VERT_START_SLV0_SHIFT (0x00000010u)
#define CSL_CCDC_VERT_START_SLV0_RESETVAL (0x00000000u)


#define CSL_CCDC_VERT_START_SLV1_MASK (0x00007FFFu)
#define CSL_CCDC_VERT_START_SLV1_SHIFT (0x00000000u)
#define CSL_CCDC_VERT_START_SLV1_RESETVAL (0x00000000u)

#define CSL_CCDC_VERT_START_RESETVAL (0x00000000u)

/* VERT_LINES */


#define CSL_CCDC_VERT_LINES_NLV_MASK (0x00007FFFu)
#define CSL_CCDC_VERT_LINES_NLV_SHIFT (0x00000000u)
#define CSL_CCDC_VERT_LINES_NLV_RESETVAL (0x00000000u)

#define CSL_CCDC_VERT_LINES_RESETVAL (0x00000000u)

/* CULLING */

#define CSL_CCDC_CULLING_CULHEVN_MASK (0xFF000000u)
#define CSL_CCDC_CULLING_CULHEVN_SHIFT (0x00000018u)
#define CSL_CCDC_CULLING_CULHEVN_RESETVAL (0x000000FFu)

#define CSL_CCDC_CULLING_CULHODD_MASK (0x00FF0000u)
#define CSL_CCDC_CULLING_CULHODD_SHIFT (0x00000010u)
#define CSL_CCDC_CULLING_CULHODD_RESETVAL (0x000000FFu)


#define CSL_CCDC_CULLING_CULV_MASK (0x000000FFu)
#define CSL_CCDC_CULLING_CULV_SHIFT (0x00000000u)
#define CSL_CCDC_CULLING_CULV_RESETVAL (0x000000FFu)

#define CSL_CCDC_CULLING_RESETVAL (0xFFFF00FFu)

/* HSIZE_OFF */


#define CSL_CCDC_HSIZE_OFF_LNOFST_MASK (0x0000FFFFu)
#define CSL_CCDC_HSIZE_OFF_LNOFST_SHIFT (0x00000000u)
#define CSL_CCDC_HSIZE_OFF_LNOFST_RESETVAL (0x00000000u)

#define CSL_CCDC_HSIZE_OFF_RESETVAL (0x00000000u)

/* SDOFST */


#define CSL_CCDC_SDOFST_FIINV_MASK (0x00004000u)
#define CSL_CCDC_SDOFST_FIINV_SHIFT (0x0000000Eu)
#define CSL_CCDC_SDOFST_FIINV_RESETVAL (0x00000000u)
/*----FIINV Tokens----*/
#define CSL_CCDC_SDOFST_FIINV_NONINVERSE (0x00000000u)
#define CSL_CCDC_SDOFST_FIINV_INVERSE (0x00000001u)

#define CSL_CCDC_SDOFST_FOFST_MASK (0x00003000u)
#define CSL_CCDC_SDOFST_FOFST_SHIFT (0x0000000Cu)
#define CSL_CCDC_SDOFST_FOFST_RESETVAL (0x00000000u)
/*----FOFST Tokens----*/
#define CSL_CCDC_SDOFST_FOFST_PLUS_1LINE (0x00000000u)
#define CSL_CCDC_SDOFST_FOFST_PLUS_2LINE (0x00000001u)
#define CSL_CCDC_SDOFST_FOFST_PLUS_3LINE (0x00000002u)
#define CSL_CCDC_SDOFST_FOFST_PLUS_4LINE (0x00000003u)

#define CSL_CCDC_SDOFST_LOFTS0_MASK (0x00000E00u)
#define CSL_CCDC_SDOFST_LOFTS0_SHIFT (0x00000009u)
#define CSL_CCDC_SDOFST_LOFTS0_RESETVAL (0x00000000u)
/*----LOFTS0 Tokens----*/
#define CSL_CCDC_SDOFST_LOFTS0_PLUS_1LINE (0x00000000u)
#define CSL_CCDC_SDOFST_LOFTS0_PLUS_2LINES (0x00000001u)
#define CSL_CCDC_SDOFST_LOFTS0_PLUS_3LINES (0x00000002u)
#define CSL_CCDC_SDOFST_LOFTS0_PLUS_4LINES (0x00000003u)
#define CSL_CCDC_SDOFST_LOFTS0_MINUS_1LINE (0x00000004u)
#define CSL_CCDC_SDOFST_LOFTS0_MINUS_2LINES (0x00000005u)
#define CSL_CCDC_SDOFST_LOFTS0_MINUS_3LINES (0x00000006u)
#define CSL_CCDC_SDOFST_LOFTS0_MINUS_4LINES (0x00000007u)

#define CSL_CCDC_SDOFST_LOFTS1_MASK (0x000001C0u)
#define CSL_CCDC_SDOFST_LOFTS1_SHIFT (0x00000006u)
#define CSL_CCDC_SDOFST_LOFTS1_RESETVAL (0x00000000u)
/*----LOFTS1 Tokens----*/
#define CSL_CCDC_SDOFST_LOFTS1_PLUS_1LINE (0x00000000u)
#define CSL_CCDC_SDOFST_LOFTS1_PLUS_2LINES (0x00000001u)
#define CSL_CCDC_SDOFST_LOFTS1_PLUS_3LINES (0x00000002u)
#define CSL_CCDC_SDOFST_LOFTS1_PLUS_4LINES (0x00000003u)
#define CSL_CCDC_SDOFST_LOFTS1_MINUS_1LINE (0x00000004u)
#define CSL_CCDC_SDOFST_LOFTS1_MINUS_2LINES (0x00000005u)
#define CSL_CCDC_SDOFST_LOFTS1_MINUS_3LINES (0x00000006u)
#define CSL_CCDC_SDOFST_LOFTS1_MINUS_4LINES (0x00000007u)

#define CSL_CCDC_SDOFST_LOFTS2_MASK (0x00000038u)
#define CSL_CCDC_SDOFST_LOFTS2_SHIFT (0x00000003u)
#define CSL_CCDC_SDOFST_LOFTS2_RESETVAL (0x00000000u)
/*----LOFTS2 Tokens----*/
#define CSL_CCDC_SDOFST_LOFTS2_PLUS_1LINE (0x00000000u)
#define CSL_CCDC_SDOFST_LOFTS2_PLUS_2LINES (0x00000001u)
#define CSL_CCDC_SDOFST_LOFTS2_PLUS_3LINES (0x00000002u)
#define CSL_CCDC_SDOFST_LOFTS2_PLUS_4LINES (0x00000003u)
#define CSL_CCDC_SDOFST_LOFTS2_MINUS_1LINE (0x00000004u)
#define CSL_CCDC_SDOFST_LOFTS2_MINUS_2LINES (0x00000005u)
#define CSL_CCDC_SDOFST_LOFTS2_MINUS_3LINES (0x00000006u)
#define CSL_CCDC_SDOFST_LOFTS2_MINUS_4LINES (0x00000007u)

#define CSL_CCDC_SDOFST_LOFTS3_MASK (0x00000007u)
#define CSL_CCDC_SDOFST_LOFTS3_SHIFT (0x00000000u)
#define CSL_CCDC_SDOFST_LOFTS3_RESETVAL (0x00000000u)
/*----LOFTS3 Tokens----*/
#define CSL_CCDC_SDOFST_LOFTS3_PLUS_1LINE (0x00000000u)
#define CSL_CCDC_SDOFST_LOFTS3_PLUS_2LINES (0x00000001u)
#define CSL_CCDC_SDOFST_LOFTS3_PLUS_3LINES (0x00000002u)
#define CSL_CCDC_SDOFST_LOFTS3_PLUS_4LINES (0x00000003u)
#define CSL_CCDC_SDOFST_LOFTS3_MINUS_1LINE (0x00000004u)
#define CSL_CCDC_SDOFST_LOFTS3_MINUS_2LINES (0x00000005u)
#define CSL_CCDC_SDOFST_LOFTS3_MINUS_3LINES (0x00000006u)
#define CSL_CCDC_SDOFST_LOFTS3_MINUS_4LINES (0x00000007u)

#define CSL_CCDC_SDOFST_RESETVAL (0x00000000u)

/* SDR_ADDR */

#define CSL_CCDC_SDR_ADDR_SDR_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CCDC_SDR_ADDR_SDR_ADDR_SHIFT (0x00000000u)
#define CSL_CCDC_SDR_ADDR_SDR_ADDR_RESETVAL (0x00000000u)

#define CSL_CCDC_SDR_ADDR_RESETVAL (0x00000000u)

/* CLAMP */

#define CSL_CCDC_CLAMP_CLAMPEN_MASK (0x80000000u)
#define CSL_CCDC_CLAMP_CLAMPEN_SHIFT (0x0000001Fu)
#define CSL_CCDC_CLAMP_CLAMPEN_RESETVAL (0x00000000u)
/*----CLAMPEN Tokens----*/
#define CSL_CCDC_CLAMP_CLAMPEN_DISABLE (0x00000000u)
#define CSL_CCDC_CLAMP_CLAMPEN_ENABLE (0x00000001u)

#define CSL_CCDC_CLAMP_OBSLEN_MASK (0x70000000u)
#define CSL_CCDC_CLAMP_OBSLEN_SHIFT (0x0000001Cu)
#define CSL_CCDC_CLAMP_OBSLEN_RESETVAL (0x00000000u)
/*----OBSLEN Tokens----*/
#define CSL_CCDC_CLAMP_OBSLEN__1PIXELS (0x00000000u)
#define CSL_CCDC_CLAMP_OBSLEN__2PIXELS (0x00000001u)
#define CSL_CCDC_CLAMP_OBSLEN__4PIXELS (0x00000002u)
#define CSL_CCDC_CLAMP_OBSLEN__8PIXELS (0x00000003u)
#define CSL_CCDC_CLAMP_OBSLEN__16PIXELS (0x00000004u)

#define CSL_CCDC_CLAMP_OBSLN_MASK (0x0E000000u)
#define CSL_CCDC_CLAMP_OBSLN_SHIFT (0x00000019u)
#define CSL_CCDC_CLAMP_OBSLN_RESETVAL (0x00000000u)
/*----OBSLN Tokens----*/
#define CSL_CCDC_CLAMP_OBSLN__1LINES (0x00000000u)
#define CSL_CCDC_CLAMP_OBSLN__2LINES (0x00000001u)
#define CSL_CCDC_CLAMP_OBSLN__4LINES (0x00000002u)
#define CSL_CCDC_CLAMP_OBSLN__8LINES (0x00000003u)
#define CSL_CCDC_CLAMP_OBSLN__16LINES (0x00000004u)

#define CSL_CCDC_CLAMP_OBST_MASK (0x01FFFC00u)
#define CSL_CCDC_CLAMP_OBST_SHIFT (0x0000000Au)
#define CSL_CCDC_CLAMP_OBST_RESETVAL (0x00000000u)


#define CSL_CCDC_CLAMP_OBGAIN_MASK (0x0000001Fu)
#define CSL_CCDC_CLAMP_OBGAIN_SHIFT (0x00000000u)
#define CSL_CCDC_CLAMP_OBGAIN_RESETVAL (0x00000010u)

#define CSL_CCDC_CLAMP_RESETVAL (0x00000010u)

/* DCSUB */


#define CSL_CCDC_DCSUB_DCSUB_MASK (0x00003FFFu)
#define CSL_CCDC_DCSUB_DCSUB_SHIFT (0x00000000u)
#define CSL_CCDC_DCSUB_DCSUB_RESETVAL (0x00000000u)

#define CSL_CCDC_DCSUB_RESETVAL (0x00000000u)

/* COLPTN */

#define CSL_CCDC_COLPTN_CP3LPC3_MASK (0xC0000000u)
#define CSL_CCDC_COLPTN_CP3LPC3_SHIFT (0x0000001Eu)
#define CSL_CCDC_COLPTN_CP3LPC3_RESETVAL (0x00000000u)
/*----CP3LPC3 Tokens----*/
#define CSL_CCDC_COLPTN_CP3LPC3_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP3LPC3_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP3LPC3_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP3LPC3_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP3LPC2_MASK (0x30000000u)
#define CSL_CCDC_COLPTN_CP3LPC2_SHIFT (0x0000001Cu)
#define CSL_CCDC_COLPTN_CP3LPC2_RESETVAL (0x00000000u)
/*----CP3LPC2 Tokens----*/
#define CSL_CCDC_COLPTN_CP3LPC2_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP3LPC2_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP3LPC2_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP3LPC2_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP3LPC1_MASK (0x0C000000u)
#define CSL_CCDC_COLPTN_CP3LPC1_SHIFT (0x0000001Au)
#define CSL_CCDC_COLPTN_CP3LPC1_RESETVAL (0x00000000u)
/*----CP3LPC1 Tokens----*/
#define CSL_CCDC_COLPTN_CP3LPC1_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP3LPC1_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP3LPC1_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP3LPC1_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP3LPC0_MASK (0x03000000u)
#define CSL_CCDC_COLPTN_CP3LPC0_SHIFT (0x00000018u)
#define CSL_CCDC_COLPTN_CP3LPC0_RESETVAL (0x00000000u)
/*----CP3LPC0 Tokens----*/
#define CSL_CCDC_COLPTN_CP3LPC0_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP3LPC0_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP3LPC0_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP3LPC0_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP2LPC3_MASK (0x00C00000u)
#define CSL_CCDC_COLPTN_CP2LPC3_SHIFT (0x00000016u)
#define CSL_CCDC_COLPTN_CP2LPC3_RESETVAL (0x00000000u)
/*----CP2LPC3 Tokens----*/
#define CSL_CCDC_COLPTN_CP2LPC3_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP2LPC3_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP2LPC3_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP2LPC3_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP2LPC2_MASK (0x00300000u)
#define CSL_CCDC_COLPTN_CP2LPC2_SHIFT (0x00000014u)
#define CSL_CCDC_COLPTN_CP2LPC2_RESETVAL (0x00000000u)
/*----CP2LPC2 Tokens----*/
#define CSL_CCDC_COLPTN_CP2LPC2_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP2LPC2_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP2LPC2_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP2LPC2_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP2LPC1_MASK (0x000C0000u)
#define CSL_CCDC_COLPTN_CP2LPC1_SHIFT (0x00000012u)
#define CSL_CCDC_COLPTN_CP2LPC1_RESETVAL (0x00000000u)
/*----CP2LPC1 Tokens----*/
#define CSL_CCDC_COLPTN_CP2LPC1_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP2LPC1_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP2LPC1_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP2LPC1_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP2LPC0_MASK (0x00030000u)
#define CSL_CCDC_COLPTN_CP2LPC0_SHIFT (0x00000010u)
#define CSL_CCDC_COLPTN_CP2LPC0_RESETVAL (0x00000000u)
/*----CP2LPC0 Tokens----*/
#define CSL_CCDC_COLPTN_CP2LPC0_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP2LPC0_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP2LPC0_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP2LPC0_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP1LPC3_MASK (0x0000C000u)
#define CSL_CCDC_COLPTN_CP1LPC3_SHIFT (0x0000000Eu)
#define CSL_CCDC_COLPTN_CP1LPC3_RESETVAL (0x00000000u)
/*----CP1LPC3 Tokens----*/
#define CSL_CCDC_COLPTN_CP1LPC3_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP1LPC3_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP1LPC3_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP1LPC3_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP1LPC2_MASK (0x00003000u)
#define CSL_CCDC_COLPTN_CP1LPC2_SHIFT (0x0000000Cu)
#define CSL_CCDC_COLPTN_CP1LPC2_RESETVAL (0x00000000u)
/*----CP1LPC2 Tokens----*/
#define CSL_CCDC_COLPTN_CP1LPC2_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP1LPC2_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP1LPC2_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP1LPC2_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP1LPC1_MASK (0x00000C00u)
#define CSL_CCDC_COLPTN_CP1LPC1_SHIFT (0x0000000Au)
#define CSL_CCDC_COLPTN_CP1LPC1_RESETVAL (0x00000000u)
/*----CP1LPC1 Tokens----*/
#define CSL_CCDC_COLPTN_CP1LPC1_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP1LPC1_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP1LPC1_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP1LPC1_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP1LPC0_MASK (0x00000300u)
#define CSL_CCDC_COLPTN_CP1LPC0_SHIFT (0x00000008u)
#define CSL_CCDC_COLPTN_CP1LPC0_RESETVAL (0x00000000u)
/*----CP1LPC0 Tokens----*/
#define CSL_CCDC_COLPTN_CP1LPC0_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP1LPC0_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP1LPC0_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP1LPC0_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP0LPC3_MASK (0x000000C0u)
#define CSL_CCDC_COLPTN_CP0LPC3_SHIFT (0x00000006u)
#define CSL_CCDC_COLPTN_CP0LPC3_RESETVAL (0x00000000u)
/*----CP0LPC3 Tokens----*/
#define CSL_CCDC_COLPTN_CP0LPC3_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP0LPC3_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP0LPC3_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP0LPC3_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP0LPC2_MASK (0x00000030u)
#define CSL_CCDC_COLPTN_CP0LPC2_SHIFT (0x00000004u)
#define CSL_CCDC_COLPTN_CP0LPC2_RESETVAL (0x00000000u)
/*----CP0LPC2 Tokens----*/
#define CSL_CCDC_COLPTN_CP0LPC2_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP0LPC2_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP0LPC2_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP0LPC2_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP0LPC1_MASK (0x0000000Cu)
#define CSL_CCDC_COLPTN_CP0LPC1_SHIFT (0x00000002u)
#define CSL_CCDC_COLPTN_CP0LPC1_RESETVAL (0x00000000u)
/*----CP0LPC1 Tokens----*/
#define CSL_CCDC_COLPTN_CP0LPC1_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP0LPC1_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP0LPC1_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP0LPC1_B (0x00000003u)

#define CSL_CCDC_COLPTN_CP0LPC0_MASK (0x00000003u)
#define CSL_CCDC_COLPTN_CP0LPC0_SHIFT (0x00000000u)
#define CSL_CCDC_COLPTN_CP0LPC0_RESETVAL (0x00000000u)
/*----CP0LPC0 Tokens----*/
#define CSL_CCDC_COLPTN_CP0LPC0_R (0x00000000u)
#define CSL_CCDC_COLPTN_CP0LPC0_GR (0x00000001u)
#define CSL_CCDC_COLPTN_CP0LPC0_GB (0x00000002u)
#define CSL_CCDC_COLPTN_CP0LPC0_B (0x00000003u)

#define CSL_CCDC_COLPTN_RESETVAL (0x00000000u)

/* BLKCMP */

#define CSL_CCDC_BLKCMP_R_MASK (0xFF000000u)
#define CSL_CCDC_BLKCMP_R_SHIFT (0x00000018u)
#define CSL_CCDC_BLKCMP_R_RESETVAL (0x00000000u)

#define CSL_CCDC_BLKCMP_GR_MASK (0x00FF0000u)
#define CSL_CCDC_BLKCMP_GR_SHIFT (0x00000010u)
#define CSL_CCDC_BLKCMP_GR_RESETVAL (0x00000000u)

#define CSL_CCDC_BLKCMP_GB_MASK (0x0000FF00u)
#define CSL_CCDC_BLKCMP_GB_SHIFT (0x00000008u)
#define CSL_CCDC_BLKCMP_GB_RESETVAL (0x00000000u)

#define CSL_CCDC_BLKCMP_B_MASK (0x000000FFu)
#define CSL_CCDC_BLKCMP_B_SHIFT (0x00000000u)
#define CSL_CCDC_BLKCMP_B_RESETVAL (0x00000000u)

#define CSL_CCDC_BLKCMP_RESETVAL (0x00000000u)

/* FPC */


#define CSL_CCDC_FPC_FPERR_MASK (0x00010000u)
#define CSL_CCDC_FPC_FPERR_SHIFT (0x00000010u)
#define CSL_CCDC_FPC_FPERR_RESETVAL (0x00000000u)
/*----FPERR Tokens----*/
#define CSL_CCDC_FPC_FPERR_NOERROR (0x00000000u)
#define CSL_CCDC_FPC_FPERR_ERROR (0x00000001u)

#define CSL_CCDC_FPC_FPCEN_MASK (0x00008000u)
#define CSL_CCDC_FPC_FPCEN_SHIFT (0x0000000Fu)
#define CSL_CCDC_FPC_FPCEN_RESETVAL (0x00000000u)
/*----FPCEN Tokens----*/
#define CSL_CCDC_FPC_FPCEN_DISABLED (0x00000000u)
#define CSL_CCDC_FPC_FPCEN_ENABLED (0x00000001u)

#define CSL_CCDC_FPC_FPNUM_MASK (0x00007FFFu)
#define CSL_CCDC_FPC_FPNUM_SHIFT (0x00000000u)
#define CSL_CCDC_FPC_FPNUM_RESETVAL (0x00000000u)

#define CSL_CCDC_FPC_RESETVAL (0x00000000u)

/* FPC_ADDR */

#define CSL_CCDC_FPC_ADDR_FPC_ADDR_MASK (0xFFFFFFFFu)
#define CSL_CCDC_FPC_ADDR_FPC_ADDR_SHIFT (0x00000000u)
#define CSL_CCDC_FPC_ADDR_FPC_ADDR_RESETVAL (0x00000000u)

#define CSL_CCDC_FPC_ADDR_RESETVAL (0x00000000u)

/* VDINT */


#define CSL_CCDC_VDINT_VDINT0_MASK (0x7FFF0000u)
#define CSL_CCDC_VDINT_VDINT0_SHIFT (0x00000010u)
#define CSL_CCDC_VDINT_VDINT0_RESETVAL (0x00000000u)


#define CSL_CCDC_VDINT_VDINT1_MASK (0x00007FFFu)
#define CSL_CCDC_VDINT_VDINT1_SHIFT (0x00000000u)
#define CSL_CCDC_VDINT_VDINT1_RESETVAL (0x00000000u)

#define CSL_CCDC_VDINT_RESETVAL (0x00000000u)

/* ALAW */


#define CSL_CCDC_ALAW_CCDTBL_MASK (0x00000008u)
#define CSL_CCDC_ALAW_CCDTBL_SHIFT (0x00000003u)
#define CSL_CCDC_ALAW_CCDTBL_RESETVAL (0x00000000u)
/*----CCDTBL Tokens----*/
#define CSL_CCDC_ALAW_CCDTBL_DISABLE (0x00000000u)
#define CSL_CCDC_ALAW_CCDTBL_ENABLE (0x00000001u)

#define CSL_CCDC_ALAW_GWDI_MASK (0x00000007u)
#define CSL_CCDC_ALAW_GWDI_SHIFT (0x00000000u)
#define CSL_CCDC_ALAW_GWDI_RESETVAL (0x00000004u)
/*----GWDI Tokens----*/
#define CSL_CCDC_ALAW_GWDI_BITS_15_6 (0x00000000u)
#define CSL_CCDC_ALAW_GWDI_BITS_14_5 (0x00000001u)
#define CSL_CCDC_ALAW_GWDI_BITS_13_4 (0x00000002u)
#define CSL_CCDC_ALAW_GWDI_BITS_12_3 (0x00000003u)
#define CSL_CCDC_ALAW_GWDI_BITS_11_2 (0x00000004u)
#define CSL_CCDC_ALAW_GWDI_BITS_10_1 (0x00000005u)
#define CSL_CCDC_ALAW_GWDI_BITS_09_0 (0x00000006u)

#define CSL_CCDC_ALAW_RESETVAL (0x00000004u)

/* REC656IF */


#define CSL_CCDC_REC656IF_ECCFVH_MASK (0x00000002u)
#define CSL_CCDC_REC656IF_ECCFVH_SHIFT (0x00000001u)
#define CSL_CCDC_REC656IF_ECCFVH_RESETVAL (0x00000000u)
/*----ECCFVH Tokens----*/
#define CSL_CCDC_REC656IF_ECCFVH_DISABLE (0x00000000u)
#define CSL_CCDC_REC656IF_ECCFVH_ENABLE (0x00000001u)

#define CSL_CCDC_REC656IF_R656ON_MASK (0x00000001u)
#define CSL_CCDC_REC656IF_R656ON_SHIFT (0x00000000u)
#define CSL_CCDC_REC656IF_R656ON_RESETVAL (0x00000000u)
/*----R656ON Tokens----*/
#define CSL_CCDC_REC656IF_R656ON_DISABLE (0x00000000u)
#define CSL_CCDC_REC656IF_R656ON_ENABLE (0x00000001u)

#define CSL_CCDC_REC656IF_RESETVAL (0x00000000u)

/* CCDCFG */


#define CSL_CCDC_CCDCFG_VDLC_MASK (0x00008000u)
#define CSL_CCDC_CCDCFG_VDLC_SHIFT (0x0000000Fu)
#define CSL_CCDC_CCDCFG_VDLC_RESETVAL (0x00000000u)
/*----VDLC Tokens----*/
#define CSL_CCDC_CCDCFG_VDLC_LATCHEDONVSYNC (0x00000000u)
#define CSL_CCDC_CCDCFG_VDLC_NOTLATCHEDONVSYNC (0x00000001u)


#define CSL_CCDC_CCDCFG_MSBINVI_MASK (0x00002000u)
#define CSL_CCDC_CCDCFG_MSBINVI_SHIFT (0x0000000Du)
#define CSL_CCDC_CCDCFG_MSBINVI_RESETVAL (0x00000000u)
/*----MSBINVI Tokens----*/
#define CSL_CCDC_CCDCFG_MSBINVI_NORMAL (0x00000000u)
#define CSL_CCDC_CCDCFG_MSBINVI_MSBINVERTED (0x00000001u)

#define CSL_CCDC_CCDCFG_BSWD_MASK (0x00001000u)
#define CSL_CCDC_CCDCFG_BSWD_SHIFT (0x0000000Cu)
#define CSL_CCDC_CCDCFG_BSWD_RESETVAL (0x00000000u)
/*----BSWD Tokens----*/
#define CSL_CCDC_CCDCFG_BSWD_NORMAL (0x00000000u)
#define CSL_CCDC_CCDCFG_BSWD_SWAPBYTES (0x00000001u)

#define CSL_CCDC_CCDCFG_Y8POS_MASK (0x00000800u)
#define CSL_CCDC_CCDCFG_Y8POS_SHIFT (0x0000000Bu)
#define CSL_CCDC_CCDCFG_Y8POS_RESETVAL (0x00000000u)
/*----Y8POS Tokens----*/
#define CSL_CCDC_CCDCFG_Y8POS_EVENPIXEL (0x00000000u)
#define CSL_CCDC_CCDCFG_Y8POS_ODDPIXEL (0x00000001u)



#define CSL_CCDC_CCDCFG_WENLOG_MASK (0x00000100u)
#define CSL_CCDC_CCDCFG_WENLOG_SHIFT (0x00000008u)
#define CSL_CCDC_CCDCFG_WENLOG_RESETVAL (0x00000000u)
/*----WENLOG Tokens----*/
#define CSL_CCDC_CCDCFG_WENLOG_AND (0x00000000u)
#define CSL_CCDC_CCDCFG_WENLOG_OR (0x00000001u)

#define CSL_CCDC_CCDCFG_FIDMD_MASK (0x000000C0u)
#define CSL_CCDC_CCDCFG_FIDMD_SHIFT (0x00000006u)
#define CSL_CCDC_CCDCFG_FIDMD_RESETVAL (0x00000000u)
/*----FIDMD Tokens----*/
#define CSL_CCDC_CCDCFG_FIDMD_LATCH_AT_VSYNC (0x00000000u)
#define CSL_CCDC_CCDCFG_FIDMD_NO_LATCH (0x00000001u)
#define CSL_CCDC_CCDCFG_FIDMD_LATCH_AT_VD_EDGE (0x00000002u)
#define CSL_CCDC_CCDCFG_FIDMD_LATCH_ON_VD_HD_PHASE (0x00000003u)

#define CSL_CCDC_CCDCFG_BW656_MASK (0x00000020u)
#define CSL_CCDC_CCDCFG_BW656_SHIFT (0x00000005u)
#define CSL_CCDC_CCDCFG_BW656_RESETVAL (0x00000000u)
/*----BW656 Tokens----*/
#define CSL_CCDC_CCDCFG_BW656__8_BITS (0x00000000u)
#define CSL_CCDC_CCDCFG_BW656__10_BITS (0x00000001u)

#define CSL_CCDC_CCDCFG_YCINSWP_MASK (0x00000010u)
#define CSL_CCDC_CCDCFG_YCINSWP_SHIFT (0x00000004u)
#define CSL_CCDC_CCDCFG_YCINSWP_RESETVAL (0x00000000u)
/*----YCINSWP Tokens----*/
#define CSL_CCDC_CCDCFG_YCINSWP_NO_YCIN_SWAP (0x00000000u)
#define CSL_CCDC_CCDCFG_YCINSWP_YCIN_SWAP (0x00000001u)





#define CSL_CCDC_CCDCFG_RESETVAL (0x00000000u)

/* FMTCFG */


#define CSL_CCDC_FMTCFG_VPIF_FRQ_MASK (0x00070000u)
#define CSL_CCDC_FMTCFG_VPIF_FRQ_SHIFT (0x00000010u)
#define CSL_CCDC_FMTCFG_VPIF_FRQ_RESETVAL (0x00000000u)
/*----VPIF_FRQ Tokens----*/
#define CSL_CCDC_FMTCFG_VPIF_FRQ_ONE_HALF (0x00000000u)
#define CSL_CCDC_FMTCFG_VPIF_FRQ_ONE_THIRDHALF (0x00000001u)
#define CSL_CCDC_FMTCFG_VPIF_FRQ_ONE_FOURTHHALF (0x00000002u)
#define CSL_CCDC_FMTCFG_VPIF_FRQ_ONE_FIFTHHALF (0x00000003u)
#define CSL_CCDC_FMTCFG_VPIF_FRQ_ONE_SIXTHHALF (0x00000004u)

#define CSL_CCDC_FMTCFG_VPEN_MASK (0x00008000u)
#define CSL_CCDC_FMTCFG_VPEN_SHIFT (0x0000000Fu)
#define CSL_CCDC_FMTCFG_VPEN_RESETVAL (0x00000000u)
/*----VPEN Tokens----*/
#define CSL_CCDC_FMTCFG_VPEN_DISABLE (0x00000000u)
#define CSL_CCDC_FMTCFG_VPEN_ENABLE (0x00000001u)

#define CSL_CCDC_FMTCFG_VPIN_MASK (0x00007000u)
#define CSL_CCDC_FMTCFG_VPIN_SHIFT (0x0000000Cu)
#define CSL_CCDC_FMTCFG_VPIN_RESETVAL (0x00000004u)
/*----VPIN Tokens----*/
#define CSL_CCDC_FMTCFG_VPIN_BITS_15_06 (0x00000000u)
#define CSL_CCDC_FMTCFG_VPIN_BITS_14_05 (0x00000001u)
#define CSL_CCDC_FMTCFG_VPIN_BITS_13_04 (0x00000002u)
#define CSL_CCDC_FMTCFG_VPIN_BITS_12_03 (0x00000003u)
#define CSL_CCDC_FMTCFG_VPIN_BITS_11_02 (0x00000004u)
#define CSL_CCDC_FMTCFG_VPIN_BITS_10_01 (0x00000005u)
#define CSL_CCDC_FMTCFG_VPIN_BITS_09_00 (0x00000006u)

#define CSL_CCDC_FMTCFG_RSV_MASK (0x00000FFFu)
#define CSL_CCDC_FMTCFG_RSV_SHIFT (0x00000000u)
#define CSL_CCDC_FMTCFG_RSV_RESETVAL (0x00000000u)

#define CSL_CCDC_FMTCFG_RESETVAL (0x00004000u)

/* FMT_HORZ */


#define CSL_CCDC_FMT_HORZ_FMTSPH_MASK (0x1FFF0000u)
#define CSL_CCDC_FMT_HORZ_FMTSPH_SHIFT (0x00000010u)
#define CSL_CCDC_FMT_HORZ_FMTSPH_RESETVAL (0x00000000u)


#define CSL_CCDC_FMT_HORZ_FMTLNH_MASK (0x00001FFFu)
#define CSL_CCDC_FMT_HORZ_FMTLNH_SHIFT (0x00000000u)
#define CSL_CCDC_FMT_HORZ_FMTLNH_RESETVAL (0x00000000u)

#define CSL_CCDC_FMT_HORZ_RESETVAL (0x00000000u)

/* FMT_VERT */


#define CSL_CCDC_FMT_VERT_FMTSLV_MASK (0x1FFF0000u)
#define CSL_CCDC_FMT_VERT_FMTSLV_SHIFT (0x00000010u)
#define CSL_CCDC_FMT_VERT_FMTSLV_RESETVAL (0x00000000u)


#define CSL_CCDC_FMT_VERT_FMTLNV_MASK (0x00001FFFu)
#define CSL_CCDC_FMT_VERT_FMTLNV_SHIFT (0x00000000u)
#define CSL_CCDC_FMT_VERT_FMTLNV_RESETVAL (0x00000000u)

#define CSL_CCDC_FMT_VERT_RESETVAL (0x00000000u)

/* VP_OUT */


#define CSL_CCDC_VP_OUT_VERT_NUM_MASK (0x7FFE0000u)
#define CSL_CCDC_VP_OUT_VERT_NUM_SHIFT (0x00000011u)
#define CSL_CCDC_VP_OUT_VERT_NUM_RESETVAL (0x00000000u)

#define CSL_CCDC_VP_OUT_HORZ_NUM_MASK (0x0001FFF0u)
#define CSL_CCDC_VP_OUT_HORZ_NUM_SHIFT (0x00000004u)
#define CSL_CCDC_VP_OUT_HORZ_NUM_RESETVAL (0x00000000u)

#define CSL_CCDC_VP_OUT_HORZ_ST_MASK (0x0000000Fu)
#define CSL_CCDC_VP_OUT_HORZ_ST_SHIFT (0x00000000u)
#define CSL_CCDC_VP_OUT_HORZ_ST_RESETVAL (0x00000000u)

#define CSL_CCDC_VP_OUT_RESETVAL (0x00000000u)

#endif
