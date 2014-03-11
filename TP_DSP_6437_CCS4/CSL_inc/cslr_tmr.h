/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** ============================================================================
 *   @file  cslr_tmr.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for TMR
 *          Reference: User Guide SPRU989
 *  ============================================================================
 */
#ifndef _CSLR_TMR_H_
#define _CSLR_TMR_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID12;
    volatile Uint32 EMUMGT;
    volatile Uint8 RSVD0[8];
    volatile Uint32 TIM12;
    volatile Uint32 TIM34;
    volatile Uint32 PRD12;
    volatile Uint32 PRD34;
    volatile Uint32 TCR;
    volatile Uint32 TGCR;
    volatile Uint32 WDTCR;
} CSL_TmrRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_TmrRegs  *CSL_TmrRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID12 */


#define CSL_TMR_PID12_TYPE_MASK (0x007F0000u)
#define CSL_TMR_PID12_TYPE_SHIFT (0x00000010u)
#define CSL_TMR_PID12_TYPE_RESETVAL (0x00000001u)

#define CSL_TMR_PID12_CLASS_MASK (0x0000FF00u)
#define CSL_TMR_PID12_CLASS_SHIFT (0x00000008u)
#define CSL_TMR_PID12_CLASS_RESETVAL (0x00000007u)

#define CSL_TMR_PID12_REVISION_MASK (0x000000FFu)
#define CSL_TMR_PID12_REVISION_SHIFT (0x00000000u)
#define CSL_TMR_PID12_REVISION_RESETVAL (0x00000001u)

#define CSL_TMR_PID12_RESETVAL (0x00010701u)

/* EMUMGT */


#define CSL_TMR_EMUMGT_SOFT_MASK (0x00000002u)
#define CSL_TMR_EMUMGT_SOFT_SHIFT (0x00000001u)
#define CSL_TMR_EMUMGT_SOFT_RESETVAL (0x00000000u)
/*----SOFT Tokens----*/
#define CSL_TMR_EMUMGT_SOFT_IMMEDIATE (0x00000000u)
#define CSL_TMR_EMUMGT_SOFT_INCREMENT (0x00000001u)

#define CSL_TMR_EMUMGT_FREE_MASK (0x00000001u)
#define CSL_TMR_EMUMGT_FREE_SHIFT (0x00000000u)
#define CSL_TMR_EMUMGT_FREE_RESETVAL (0x00000000u)
/*----FREE Tokens----*/
#define CSL_TMR_EMUMGT_FREE_SOFT (0x00000000u)
#define CSL_TMR_EMUMGT_FREE_FREE (0x00000001u)

#define CSL_TMR_EMUMGT_RESETVAL (0x00000000u)

/* TIM12 */

#define CSL_TMR_TIM12_TIM12_MASK (0xFFFFFFFFu)
#define CSL_TMR_TIM12_TIM12_SHIFT (0x00000000u)
#define CSL_TMR_TIM12_TIM12_RESETVAL (0x00000000u)

#define CSL_TMR_TIM12_RESETVAL (0x00000000u)

/* TIM34 */

#define CSL_TMR_TIM34_TIM34_MASK (0xFFFFFFFFu)
#define CSL_TMR_TIM34_TIM34_SHIFT (0x00000000u)
#define CSL_TMR_TIM34_TIM34_RESETVAL (0x00000000u)

#define CSL_TMR_TIM34_RESETVAL (0x00000000u)

/* PRD12 */

#define CSL_TMR_PRD12_PRD12_MASK (0xFFFFFFFFu)
#define CSL_TMR_PRD12_PRD12_SHIFT (0x00000000u)
#define CSL_TMR_PRD12_PRD12_RESETVAL (0x00000000u)

#define CSL_TMR_PRD12_RESETVAL (0x00000000u)

/* PRD34 */

#define CSL_TMR_PRD34_PRD34_MASK (0xFFFFFFFFu)
#define CSL_TMR_PRD34_PRD34_SHIFT (0x00000000u)
#define CSL_TMR_PRD34_PRD34_RESETVAL (0x00000000u)

#define CSL_TMR_PRD34_RESETVAL (0x00000000u)

/* TCR */


#define CSL_TMR_TCR_ENAMODE34_MASK (0x00C00000u)
#define CSL_TMR_TCR_ENAMODE34_SHIFT (0x00000016u)
#define CSL_TMR_TCR_ENAMODE34_RESETVAL (0x00000000u)
/*----ENAMODE34 Tokens----*/
#define CSL_TMR_TCR_ENAMODE34_DISABLE (0x00000000u)
#define CSL_TMR_TCR_ENAMODE34_EN_ONCE (0x00000001u)
#define CSL_TMR_TCR_ENAMODE34_EN_CONT (0x00000002u)


#define CSL_TMR_TCR_CLKSRC12_MASK (0x00000100u)
#define CSL_TMR_TCR_CLKSRC12_SHIFT (0x00000008u)
#define CSL_TMR_TCR_CLKSRC12_RESETVAL (0x00000000u)
/*----CLKSRC12 Tokens----*/
#define CSL_TMR_TCR_CLKSRC12_INTERNAL (0x00000000u)
#define CSL_TMR_TCR_CLKSRC12_TIMER (0x00000001u)

#define CSL_TMR_TCR_ENAMODE12_MASK (0x000000C0u)
#define CSL_TMR_TCR_ENAMODE12_SHIFT (0x00000006u)
#define CSL_TMR_TCR_ENAMODE12_RESETVAL (0x00000000u)
/*----ENAMODE12 Tokens----*/
#define CSL_TMR_TCR_ENAMODE12_DISABLE (0x00000000u)
#define CSL_TMR_TCR_ENAMODE12_EN_ONCE (0x00000001u)
#define CSL_TMR_TCR_ENAMODE12_EN_CONT (0x00000002u)

#define CSL_TMR_TCR_PWID_MASK (0x00000030u)
#define CSL_TMR_TCR_PWID_SHIFT (0x00000004u)
#define CSL_TMR_TCR_PWID_RESETVAL (0x00000000u)
/*----PWID Tokens----*/
#define CSL_TMR_TCR_PWID_ONE_CLK (0x00000000u)
#define CSL_TMR_TCR_PWID_TWO_CLK (0x00000001u)
#define CSL_TMR_TCR_PWID_THREE_CLK (0x00000002u)
#define CSL_TMR_TCR_PWID_FOUR_CLK (0x00000003u)

#define CSL_TMR_TCR_CP_MASK (0x00000008u)
#define CSL_TMR_TCR_CP_SHIFT (0x00000003u)
#define CSL_TMR_TCR_CP_RESETVAL (0x00000000u)
/*----CP Tokens----*/
#define CSL_TMR_TCR_CP_PULSE (0x00000000u)
#define CSL_TMR_TCR_CP_CLOCK (0x00000001u)

#define CSL_TMR_TCR_INVINP_MASK (0x00000004u)
#define CSL_TMR_TCR_INVINP_SHIFT (0x00000002u)
#define CSL_TMR_TCR_INVINP_RESETVAL (0x00000000u)
/*----INVINP Tokens----*/
#define CSL_TMR_TCR_INVINP_NON_INVERTED (0x00000000u)
#define CSL_TMR_TCR_INVINP_INVERTED (0x00000001u)

#define CSL_TMR_TCR_INVOUTP_MASK (0x00000002u)
#define CSL_TMR_TCR_INVOUTP_SHIFT (0x00000001u)
#define CSL_TMR_TCR_INVOUTP_RESETVAL (0x00000000u)
/*----INVOUTP Tokens----*/
#define CSL_TMR_TCR_INVOUTP_NON_INVERTED (0x00000000u)
#define CSL_TMR_TCR_INVOUTP_INVERTED (0x00000001u)

#define CSL_TMR_TCR_TSTAT_MASK (0x00000001u)
#define CSL_TMR_TCR_TSTAT_SHIFT (0x00000000u)
#define CSL_TMR_TCR_TSTAT_RESETVAL (0x00000000u)
/*----TSTAT Tokens----*/
#define CSL_TMR_TCR_TSTAT_LOW (0x00000000u)
#define CSL_TMR_TCR_TSTAT_HIGH (0x00000001u)

#define CSL_TMR_TCR_RESETVAL (0x00000000u)

/* TGCR */


#define CSL_TMR_TGCR_TDDR34_MASK (0x0000F000u)
#define CSL_TMR_TGCR_TDDR34_SHIFT (0x0000000Cu)
#define CSL_TMR_TGCR_TDDR34_RESETVAL (0x00000000u)

#define CSL_TMR_TGCR_PSC34_MASK (0x00000F00u)
#define CSL_TMR_TGCR_PSC34_SHIFT (0x00000008u)
#define CSL_TMR_TGCR_PSC34_RESETVAL (0x00000000u)


#define CSL_TMR_TGCR_TIMMODE_MASK (0x0000000Cu)
#define CSL_TMR_TGCR_TIMMODE_SHIFT (0x00000002u)
#define CSL_TMR_TGCR_TIMMODE_RESETVAL (0x00000000u)
/*----TIMMODE Tokens----*/
#define CSL_TMR_TGCR_TIMMODE_64BIT_GPT (0x00000000u)
#define CSL_TMR_TGCR_TIMMODE_32BIT_UNCHAIN (0x00000001u)
#define CSL_TMR_TGCR_TIMMODE_64BIT_WDT (0x00000002u)
#define CSL_TMR_TGCR_TIMMODE_32_CHAIN (0x00000003u)

#define CSL_TMR_TGCR_TIM34RS_MASK (0x00000002u)
#define CSL_TMR_TGCR_TIM34RS_SHIFT (0x00000001u)
#define CSL_TMR_TGCR_TIM34RS_RESETVAL (0x00000000u)
/*----TIM34RS Tokens----*/
#define CSL_TMR_TGCR_TIM34RS_RESET (0x00000000u)
#define CSL_TMR_TGCR_TIM34RS_NO_RESET (0x00000001u)

#define CSL_TMR_TGCR_TIM12RS_MASK (0x00000001u)
#define CSL_TMR_TGCR_TIM12RS_SHIFT (0x00000000u)
#define CSL_TMR_TGCR_TIM12RS_RESETVAL (0x00000000u)
/*----TIM12RS Tokens----*/
#define CSL_TMR_TGCR_TIM12RS_RESET (0x00000000u)
#define CSL_TMR_TGCR_TIM12RS_NO_RESET (0x00000001u)

#define CSL_TMR_TGCR_RESETVAL (0x00000000u)

/* WDTCR */

#define CSL_TMR_WDTCR_WDKEY_MASK (0xFFFF0000u)
#define CSL_TMR_WDTCR_WDKEY_SHIFT (0x00000010u)
#define CSL_TMR_WDTCR_WDKEY_RESETVAL (0x00000000u)
/*----WDKEY Tokens----*/
#define CSL_TMR_WDTCR_WDKEY_CMD1 (0x0000A5C6u)
#define CSL_TMR_WDTCR_WDKEY_CMD2 (0x0000DA7Eu)

#define CSL_TMR_WDTCR_WDFLAG_MASK (0x00008000u)
#define CSL_TMR_WDTCR_WDFLAG_SHIFT (0x0000000Fu)
#define CSL_TMR_WDTCR_WDFLAG_RESETVAL (0x00000000u)
/*----WDFLAG Tokens----*/
#define CSL_TMR_WDTCR_WDFLAG_NO_TIMEOUT (0x00000000u)
#define CSL_TMR_WDTCR_WDFLAG_TIMEOUT (0x00000001u)

#define CSL_TMR_WDTCR_WDEN_MASK (0x00004000u)
#define CSL_TMR_WDTCR_WDEN_SHIFT (0x0000000Eu)
#define CSL_TMR_WDTCR_WDEN_RESETVAL (0x00000000u)
/*----WDEN Tokens----*/
#define CSL_TMR_WDTCR_WDEN_DISABLE (0x00000000u)
#define CSL_TMR_WDTCR_WDEN_ENABLE (0x00000001u)



#define CSL_TMR_WDTCR_RESETVAL (0x00000000u)

#endif

