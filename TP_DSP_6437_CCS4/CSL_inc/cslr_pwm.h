/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** ============================================================================
 *   @file  cslr_pwm.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for PWM
 *          Reference: User Guide SPRU995
 * ============================================================================
 */
#ifndef _CSLR_PWM_H_
#define _CSLR_PWM_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint32 PCR;
    volatile Uint32 CFG;
    volatile Uint32 START;
    volatile Uint32 RPT;
    volatile Uint32 PER;
    volatile Uint32 PH1D;
} CSL_PwmRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_PwmRegs    *CSL_PwmRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */


#define CSL_PWM_PID_TID_MASK             (0x00FF0000u)
#define CSL_PWM_PID_TID_SHIFT            (0x00000010u)
#define CSL_PWM_PID_TID_RESETVAL (0x00000002u)

#define CSL_PWM_PID_CID_MASK             (0x0000FF00u)
#define CSL_PWM_PID_CID_SHIFT            (0x00000008u)
#define CSL_PWM_PID_CID_RESETVAL (0x00000007u)

#define CSL_PWM_PID_REV_MASK             (0x000000FFu)
#define CSL_PWM_PID_REV_SHIFT            (0x00000000u)
#define CSL_PWM_PID_REV_RESETVAL         (0x00000000u)

#define CSL_PWM_PID_RESETVAL (0x00020700u)

/* PCR */


#define CSL_PWM_PCR_FREE_MASK            (0x00000001u)
#define CSL_PWM_PCR_FREE_SHIFT           (0x00000000u)
#define CSL_PWM_PCR_FREE_RESETVAL        (0x00000000u)
/*----FREE Tokens----*/
#define CSL_PWM_PCR_FREE_STOP            (0x00000000u)
#define CSL_PWM_PCR_FREE_RUN             (0x00000001u)

#define CSL_PWM_PCR_RESETVAL             (0x00000000u)

/* CFG */


#define CSL_PWM_CFG_OPST_MASK            (0x00020000u)
#define CSL_PWM_CFG_OPST_SHIFT           (0x00000011u)
#define CSL_PWM_CFG_OPST_RESETVAL        (0x00000000u)
/*----OPST Tokens----*/
#define CSL_PWM_CFG_OPST_IDLE            (0x00000000u)
#define CSL_PWM_CFG_OPST_RUN             (0x00000001u)

#define CSL_PWM_CFG_CURLEV_MASK          (0x00010000u)
#define CSL_PWM_CFG_CURLEV_SHIFT         (0x00000010u)
#define CSL_PWM_CFG_CURLEV_RESETVAL      (0x00000000u)
/*----CURLEV Tokens----*/
#define CSL_PWM_CFG_CURLEV_LOW           (0x00000000u)
#define CSL_PWM_CFG_CURLEV_HIGH          (0x00000001u)


#define CSL_PWM_CFG_INTEN_MASK           (0x00000040u)
#define CSL_PWM_CFG_INTEN_SHIFT          (0x00000006u)
#define CSL_PWM_CFG_INTEN_RESETVAL       (0x00000000u)
/*----INTEN Tokens----*/
#define CSL_PWM_CFG_INTEN_DISABLE        (0x00000000u)
#define CSL_PWM_CFG_INTEN_ENABLE         (0x00000001u)

#define CSL_PWM_CFG_INACTOUT_MASK        (0x00000020u)
#define CSL_PWM_CFG_INACTOUT_SHIFT       (0x00000005u)
#define CSL_PWM_CFG_INACTOUT_RESETVAL    (0x00000000u)
/*----INACTOUT Tokens----*/
#define CSL_PWM_CFG_INACTOUT_LOW         (0x00000000u)
#define CSL_PWM_CFG_INACTOUT_HIGH        (0x00000001u)

#define CSL_PWM_CFG_P1OUT_MASK           (0x00000010u)
#define CSL_PWM_CFG_P1OUT_SHIFT          (0x00000004u)
#define CSL_PWM_CFG_P1OUT_RESETVAL       (0x00000000u)
/*----P1OUT Tokens----*/
#define CSL_PWM_CFG_P1OUT_LOW            (0x00000000u)
#define CSL_PWM_CFG_P1OUT_HIGH           (0x00000001u)

#define CSL_PWM_CFG_EVTRIG_MASK          (0x0000000Cu)
#define CSL_PWM_CFG_EVTRIG_SHIFT         (0x00000002u)
#define CSL_PWM_CFG_EVTRIG_RESETVAL      (0x00000000u)
/*----EVTRIG Tokens----*/
#define CSL_PWM_CFG_EVTRIG_DISABLE       (0x00000000u)
#define CSL_PWM_CFG_EVTRIG_PEDGE         (0x00000001u)
#define CSL_PWM_CFG_EVTRIG_NEDGE         (0x00000002u)

#define CSL_PWM_CFG_MODE_MASK            (0x00000003u)
#define CSL_PWM_CFG_MODE_SHIFT           (0x00000000u)
#define CSL_PWM_CFG_MODE_RESETVAL        (0x00000000u)
/*----MODE Tokens----*/
#define CSL_PWM_CFG_MODE_DISABLE         (0x00000000u)
#define CSL_PWM_CFG_MODE_ONESHOT (0x00000001u)
#define CSL_PWM_CFG_MODE_CONT            (0x00000002u)

#define CSL_PWM_CFG_RESETVAL             (0x00000000u)

/* START */


#define CSL_PWM_START_START_MASK         (0x00000001u)
#define CSL_PWM_START_START_SHIFT        (0x00000000u)
#define CSL_PWM_START_START_RESETVAL     (0x00000000u)
/*----START Tokens----*/
#define CSL_PWM_START_START_START        (0x00000001u)

#define CSL_PWM_START_RESETVAL           (0x00000000u)

/* RPT */


#define CSL_PWM_RPT_RPT_MASK             (0x000000FFu)
#define CSL_PWM_RPT_RPT_SHIFT            (0x00000000u)
#define CSL_PWM_RPT_RPT_RESETVAL         (0x00000000u)

#define CSL_PWM_RPT_RESETVAL             (0x00000000u)

/* PER */

#define CSL_PWM_PER_PER_MASK             (0xFFFFFFFFu)
#define CSL_PWM_PER_PER_SHIFT            (0x00000000u)
#define CSL_PWM_PER_PER_RESETVAL         (0x00000000u)

#define CSL_PWM_PER_RESETVAL             (0x00000000u)

/* PH1D */

#define CSL_PWM_PH1D_PH1D_MASK           (0xFFFFFFFFu)
#define CSL_PWM_PH1D_PH1D_SHIFT          (0x00000000u)
#define CSL_PWM_PH1D_PH1D_RESETVAL       (0x00000000u)

#define CSL_PWM_PH1D_RESETVAL            (0x00000000u)

#endif

