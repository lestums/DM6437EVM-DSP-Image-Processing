/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.
 *   ===========================================================================
 */
/** ============================================================================
 *   @file  cslr_psc.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for PSC
 *          Reference: User Guide SPRU978B
 * ============================================================================
 */
#ifndef _CSLR_PSC_H_
#define _CSLR_PSC_H_

#include <cslr.h>
#include <tistdtypes.h>

typedef enum {
    CSL_PSC_VPSS_MASTER = 0,
    CSL_PSC_VPSS_SLAVE  = 1,
    CSL_PSC_TPCC        = 2,
    CSL_PSC_TPTC0       = 3,
    CSL_PSC_TPTC1       = 4,
    CSL_PSC_TPTC2       = 5,
    CSL_PSC_EMAC_WR     = 6,
    CSL_PSC_MDIO        = 7,
    CSL_PSC_EMAC        = 8,
    CSL_PSC_MCASP0      = 9,
	CSL_PSC_MCASP1      = 10,
    CSL_PSC_VLYNQ       = 11,
    CSL_PSC_HPI         = 12,
    CSL_PSC_DDR2        = 13,
    CSL_PSC_EMIF        = 14,
    CSL_PSC_PCI         = 15,
    CSL_PSC_MCBSP0      = 16,
    CSL_PSC_MCBSP1      = 17,
    CSL_PSC_I2C         = 18,
    CSL_PSC_UART0       = 19,
    CSL_PSC_UART1       = 20,
    CSL_PSC_VPSS_DAC    = 21,
    CSL_PSC_HECC        = 22,
    CSL_PSC_PWM0        = 23,
    CSL_PSC_PWM1        = 24,
    CSL_PSC_PWM2        = 25,
    CSL_PSC_GPIO        = 26,
    CSL_PSC_TIMER0      = 27,
    CSL_PSC_TIMER1      = 28,
    CSL_PSC_TIMER2      = 29,
    CSL_PSC_SYSTEM      = 30,
    CSL_PSC_SCR_SS_AUX  = 31,
    CSL_PSC_SCR_SS_SLOW = 32,
    CSL_PSC_SCR_SS_FAST = 33,
    CSL_PSC_SCR_SS_MST  = 34,
    CSL_PSC_EMU_SS      = 35,
    CSL_PSC_CHIPDFT_SS  = 36,
    CSL_PSC_PBIST_SS    = 37,
    CSL_PSC_VDAC_ATPG   = 38,
    CSL_PSC_GEM         = 39
} CSL_PscPeripheral;

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 PID;
    volatile Uint8 RSVD0[20];
    volatile Uint32 INTEVAL;
    volatile Uint8 RSVD1[40];
    volatile Uint32 MERRPR1;
    volatile Uint8 RSVD2[12];
    volatile Uint32 MERRCR1;
    volatile Uint8 RSVD3[200];
    volatile Uint32 PTCMD;
    volatile Uint8 RSVD4[4];
    volatile Uint32 PTSTAT;
    volatile Uint8 RSVD5[212];
    volatile Uint32 PDSTAT0;
    volatile Uint8 RSVD6[252];
    volatile Uint32 PDCTL0;
    volatile Uint8 RSVD7[1276];
    volatile Uint32 MDSTAT[40];
    volatile Uint8 RSVD8[352];
    volatile Uint32 MDCTL[40];
} CSL_PscRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_PscRegs             *CSL_PscRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */

#define CSL_PSC_PID_SCHEME_MASK          (0xC0000000u)
#define CSL_PSC_PID_SCHEME_SHIFT         (0x0000001Eu)
#define CSL_PSC_PID_SCHEME_RESETVAL      (0x00000001u)


#define CSL_PSC_PID_FUNC_MASK            (0x0FFF0000u)
#define CSL_PSC_PID_FUNC_SHIFT           (0x00000010u)
#define CSL_PSC_PID_FUNC_RESETVAL (0x00000482u)
/*----FUNC Tokens----*/
#define CSL_PSC_PID_FUNC_PSC2.0          (0x00000001u)

#define CSL_PSC_PID_RTL_MASK             (0x0000F800u)
#define CSL_PSC_PID_RTL_SHIFT            (0x0000000Bu)
#define CSL_PSC_PID_RTL_RESETVAL (0x00000004u)
/*----RTL Tokens----*/
#define CSL_PSC_PID_RTL_PSC1.0           (0x00000000u)

#define CSL_PSC_PID_MAJOR_MASK (0x00000700u)
#define CSL_PSC_PID_MAJOR_SHIFT (0x00000008u)
#define CSL_PSC_PID_MAJOR_RESETVAL (0x00000001u)

#define CSL_PSC_PID_CUSTOM_MASK          (0x000000C0u)
#define CSL_PSC_PID_CUSTOM_SHIFT         (0x00000006u)
#define CSL_PSC_PID_CUSTOM_RESETVAL      (0x00000000u)

#define CSL_PSC_PID_MINOR_MASK (0x0000003Fu)
#define CSL_PSC_PID_MINOR_SHIFT (0x00000000u)
#define CSL_PSC_PID_MINOR_RESETVAL (0x00000005u)

#define CSL_PSC_PID_RESETVAL (0x44822105u)

/* INTEVAL */


#define CSL_PSC_INTEVAL_ALLEV_MASK       (0x00000001u)
#define CSL_PSC_INTEVAL_ALLEV_SHIFT      (0x00000000u)
#define CSL_PSC_INTEVAL_ALLEV_RESETVAL   (0x00000000u)
/*----ALLEV Tokens----*/
#define CSL_PSC_INTEVAL_ALLEV_NO_EFFECT (0x00000000u)
#define CSL_PSC_INTEVAL_ALLEV_RE_EVALUATE (0x00000001u)

#define CSL_PSC_INTEVAL_RESETVAL         (0x00000000u)

/* MERRPR1 */


#define CSL_PSC_MERRPR1_M39_MASK (0x00000080u)
#define CSL_PSC_MERRPR1_M39_SHIFT (0x00000007u)
#define CSL_PSC_MERRPR1_M39_RESETVAL (0x00000000u)
/*----M39 Tokens----*/
#define CSL_PSC_MERRPR1_M39_NO_ERR (0x00000000u)
#define CSL_PSC_MERRPR1_M39_ERROR (0x00000001u)


#define CSL_PSC_MERRPR1_RESETVAL (0x00000000u)

/* MERRCR1 */


#define CSL_PSC_MERRCR1_M39_MASK (0x00000080u)
#define CSL_PSC_MERRCR1_M39_SHIFT (0x00000007u)
#define CSL_PSC_MERRCR1_M39_RESETVAL (0x00000000u)
/*----M39 Tokens----*/
#define CSL_PSC_MERRCR1_M39_NO_ERR (0x00000000u)
#define CSL_PSC_MERRCR1_M39_ERROR (0x00000001u)


#define CSL_PSC_MERRCR1_RESETVAL (0x00000000u)

/* PTCMD */


#define CSL_PSC_PTCMD_GO0_MASK (0x00000001u)
#define CSL_PSC_PTCMD_GO0_SHIFT (0x00000000u)
#define CSL_PSC_PTCMD_GO0_RESETVAL (0x00000000u)
/*----GO0 Tokens----*/
#define CSL_PSC_PTCMD_GO0_SET (0x00000001u)

#define CSL_PSC_PTCMD_RESETVAL           (0x00000000u)

/* PTSTAT */


#define CSL_PSC_PTSTAT_GOSTAT0_MASK      (0x00000001u)
#define CSL_PSC_PTSTAT_GOSTAT0_SHIFT     (0x00000000u)
#define CSL_PSC_PTSTAT_GOSTAT0_RESETVAL  (0x00000000u)
/*----GOSTAT0 Tokens----*/
#define CSL_PSC_PTSTAT_GOSTAT0_NO_PROGRESS (0x00000000u)
#define CSL_PSC_PTSTAT_GOSTAT0_IN_PROGRESS (0x00000001u)

#define CSL_PSC_PTSTAT_RESETVAL          (0x00000000u)

/* PDSTAT0 */


#define CSL_PSC_PDSTAT0_PORDONE_MASK (0x00000200u)
#define CSL_PSC_PDSTAT0_PORDONE_SHIFT (0x00000009u)
#define CSL_PSC_PDSTAT0_PORDONE_RESETVAL (0x00000001u)
/*----PORDONE Tokens----*/
#define CSL_PSC_PDSTAT0_PORDONE_NOT_DONE (0x00000000u)
#define CSL_PSC_PDSTAT0_PORDONE_DONE (0x00000001u)

#define CSL_PSC_PDSTAT0_POR_MASK (0x00000100u)
#define CSL_PSC_PDSTAT0_POR_SHIFT (0x00000008u)
#define CSL_PSC_PDSTAT0_POR_RESETVAL (0x00000001u)
/*----POR Tokens----*/
#define CSL_PSC_PDSTAT0_POR_ASSERT (0x00000000u)
#define CSL_PSC_PDSTAT0_POR_DEASSERT (0x00000001u)


#define CSL_PSC_PDSTAT0_STATE_MASK       (0x0000001Fu)
#define CSL_PSC_PDSTAT0_STATE_SHIFT      (0x00000000u)
#define CSL_PSC_PDSTAT0_STATE_RESETVAL (0x00000001u)
/*----STATE Tokens----*/
#define CSL_PSC_PDSTAT0_STATE_OFF        (0x00000000u)
#define CSL_PSC_PDSTAT0_STATE_ON         (0x00000001u)

#define CSL_PSC_PDSTAT0_RESETVAL (0x00000301u)

/* PDCTL0 */


#define CSL_PSC_PDCTL0_NEXT_MASK         (0x00000001u)
#define CSL_PSC_PDCTL0_NEXT_SHIFT        (0x00000000u)
#define CSL_PSC_PDCTL0_NEXT_RESETVAL     (0x00000001u)
/*----NEXT Tokens----*/
#define CSL_PSC_PDCTL0_NEXT_OFF          (0x00000000u)
#define CSL_PSC_PDCTL0_NEXT_ON           (0x00000001u)

#define CSL_PSC_PDCTL0_RESETVAL (0x00000001u)

/* MDSTAT */


#define CSL_PSC_MDSTAT_EMUIHB_MASK (0x00020000u)
#define CSL_PSC_MDSTAT_EMUIHB_SHIFT (0x00000011u)
#define CSL_PSC_MDSTAT_EMUIHB_RESETVAL   (0x00000000u)
/*----EMUIHB Tokens----*/
#define CSL_PSC_MDSTAT_EMUIHB_DISABLE (0x00000000u)
#define CSL_PSC_MDSTAT_EMUIHB_ENABLE (0x00000001u)

#define CSL_PSC_MDSTAT_EMURST_MASK (0x00010000u)
#define CSL_PSC_MDSTAT_EMURST_SHIFT (0x00000010u)
#define CSL_PSC_MDSTAT_EMURST_RESETVAL   (0x00000000u)
/*----EMURST Tokens----*/
#define CSL_PSC_MDSTAT_EMURST_DISABLE (0x00000000u)
#define CSL_PSC_MDSTAT_EMURST_ENABLE (0x00000001u)


#define CSL_PSC_MDSTAT_MCKOUT_MASK (0x00001000u)
#define CSL_PSC_MDSTAT_MCKOUT_SHIFT (0x0000000Cu)
#define CSL_PSC_MDSTAT_MCKOUT_RESETVAL (0x00000000u)
/*----MCKOUT Tokens----*/
#define CSL_PSC_MDSTAT_MCKOUT_OFF (0x00000000u)
#define CSL_PSC_MDSTAT_MCKOUT_ON (0x00000001u)



#define CSL_PSC_MDSTAT_MRST_MASK (0x00000400u)
#define CSL_PSC_MDSTAT_MRST_SHIFT (0x0000000Au)
#define CSL_PSC_MDSTAT_MRST_RESETVAL (0x00000000u)
/*----MRST Tokens----*/
#define CSL_PSC_MDSTAT_MRST_ASSERT (0x00000000u)
#define CSL_PSC_MDSTAT_MRST_DEASSERT (0x00000001u)

#define CSL_PSC_MDSTAT_LRSTDONE_MASK (0x00000200u)
#define CSL_PSC_MDSTAT_LRSTDONE_SHIFT (0x00000009u)
#define CSL_PSC_MDSTAT_LRSTDONE_RESETVAL (0x00000001u)
/*----LRSTDONE Tokens----*/
#define CSL_PSC_MDSTAT_LRSTDONE_NOT_DONE (0x00000000u)
#define CSL_PSC_MDSTAT_LRSTDONE_DONE (0x00000001u)

#define CSL_PSC_MDSTAT_LRST_MASK (0x00000100u)
#define CSL_PSC_MDSTAT_LRST_SHIFT (0x00000008u)
#define CSL_PSC_MDSTAT_LRST_RESETVAL (0x00000001u)
/*----LRST Tokens----*/
#define CSL_PSC_MDSTAT_LRST_ASSERT (0x00000000u)
#define CSL_PSC_MDSTAT_LRST_DEASSERT (0x00000001u)


#define CSL_PSC_MDSTAT_STATE_MASK        (0x0000003Fu)
#define CSL_PSC_MDSTAT_STATE_SHIFT       (0x00000000u)
#define CSL_PSC_MDSTAT_STATE_RESETVAL    (0x00000000u)
/*----STATE Tokens----*/
#define CSL_PSC_MDSTAT_STATE_SWRSTDISABLE (0x00000000u)
#define CSL_PSC_MDSTAT_STATE_SYNCRST     (0x00000001u)
#define CSL_PSC_MDSTAT_STATE_DISABLE     (0x00000002u)
#define CSL_PSC_MDSTAT_STATE_ENABLE      (0x00000003u)

#define CSL_PSC_MDSTAT_RESETVAL (0x00000B00u)

/* MDCTL */


#define CSL_PSC_MDCTL_EMUIHBIE_MASK      (0x00000400u)
#define CSL_PSC_MDCTL_EMUIHBIE_SHIFT     (0x0000000Au)
#define CSL_PSC_MDCTL_EMUIHBIE_RESETVAL  (0x00000000u)
/*----EMUIHBIE Tokens----*/
#define CSL_PSC_MDCTL_EMUIHBIE_DISABLE (0x00000000u)
#define CSL_PSC_MDCTL_EMUIHBIE_ENABLE (0x00000001u)

#define CSL_PSC_MDCTL_EMURSTIE_MASK      (0x00000200u)
#define CSL_PSC_MDCTL_EMURSTIE_SHIFT     (0x00000009u)
#define CSL_PSC_MDCTL_EMURSTIE_RESETVAL  (0x00000000u)
/*----EMURSTIE Tokens----*/
#define CSL_PSC_MDCTL_EMURSTIE_DISABLE (0x00000000u)
#define CSL_PSC_MDCTL_EMURSTIE_ENABLE (0x00000001u)

#define CSL_PSC_MDCTL_LRST_MASK (0x00000100u)
#define CSL_PSC_MDCTL_LRST_SHIFT (0x00000008u)
#define CSL_PSC_MDCTL_LRST_RESETVAL (0x00000001u)
/*----LRST Tokens----*/
#define CSL_PSC_MDCTL_LRST_ASSERT (0x00000000u)
#define CSL_PSC_MDCTL_LRST_DEASSERT (0x00000001u)


#define CSL_PSC_MDCTL_NEXT_MASK (0x00000007u)
#define CSL_PSC_MDCTL_NEXT_SHIFT         (0x00000000u)
#define CSL_PSC_MDCTL_NEXT_RESETVAL (0x00000000u)
/*----NEXT Tokens----*/
#define CSL_PSC_MDCTL_NEXT_SWRSTDISABLE  (0x00000000u)
#define CSL_PSC_MDCTL_NEXT_SYNCRST       (0x00000001u)
#define CSL_PSC_MDCTL_NEXT_DISABLE       (0x00000002u)
#define CSL_PSC_MDCTL_NEXT_ENABLE        (0x00000003u)

#define CSL_PSC_MDCTL_RESETVAL (0x00000100u)

#endif

