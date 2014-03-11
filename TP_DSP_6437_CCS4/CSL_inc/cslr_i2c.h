/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *  Use of this software is controlled by the terms and conditions found in the
 *  license agreement under which this software has been supplied.
 *   ===========================================================================
 */ 
/** ============================================================================
 *   @file  cslr_i2c.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the Register Descriptions for I2C
 *          Reference: User Guide SPRU991A
 *  ============================================================================
 */
#ifndef _CSLR_I2C_H_
#define _CSLR_I2C_H_

#include <cslr.h>
#include <tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 ICOAR;
    volatile Uint32 ICIMR;
    volatile Uint32 ICSTR;
    volatile Uint32 ICCLKL;
    volatile Uint32 ICCLKH;
    volatile Uint32 ICCNT;
    volatile Uint32 ICDRR;
    volatile Uint32 ICSAR;
    volatile Uint32 ICDXR;
    volatile Uint32 ICMDR;
    volatile Uint32 ICIVR;
    volatile Uint32 ICEMDR;
    volatile Uint32 ICPSC;
    volatile Uint32 ICPID1;
    volatile Uint32 ICPID2;
} CSL_I2cRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_I2cRegs  *CSL_I2cRegsOvly;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* ICOAR */


#define CSL_I2C_ICOAR_OADDR_MASK         (0x000003FFu)
#define CSL_I2C_ICOAR_OADDR_SHIFT        (0x00000000u)
#define CSL_I2C_ICOAR_OADDR_RESETVAL     (0x00000000u)

#define CSL_I2C_ICOAR_RESETVAL           (0x00000000u)

/* ICIMR */


#define CSL_I2C_ICIMR_AAS_MASK           (0x00000040u)
#define CSL_I2C_ICIMR_AAS_SHIFT          (0x00000006u)
#define CSL_I2C_ICIMR_AAS_RESETVAL       (0x00000000u)
/*----AAS Tokens----*/
#define CSL_I2C_ICIMR_AAS_DISABLE        (0x00000000u)
#define CSL_I2C_ICIMR_AAS_ENABLE         (0x00000001u)

#define CSL_I2C_ICIMR_SCD_MASK           (0x00000020u)
#define CSL_I2C_ICIMR_SCD_SHIFT          (0x00000005u)
#define CSL_I2C_ICIMR_SCD_RESETVAL       (0x00000000u)
/*----SCD Tokens----*/
#define CSL_I2C_ICIMR_SCD_DISABLE        (0x00000000u)
#define CSL_I2C_ICIMR_SCD_ENABLE         (0x00000001u)

#define CSL_I2C_ICIMR_ICXRDY_MASK        (0x00000010u)
#define CSL_I2C_ICIMR_ICXRDY_SHIFT       (0x00000004u)
#define CSL_I2C_ICIMR_ICXRDY_RESETVAL    (0x00000000u)
/*----ICXRDY Tokens----*/
#define CSL_I2C_ICIMR_ICXRDY_DISABLE     (0x00000000u)
#define CSL_I2C_ICIMR_ICXRDY_ENABLE      (0x00000001u)

#define CSL_I2C_ICIMR_ICRRDY_MASK        (0x00000008u)
#define CSL_I2C_ICIMR_ICRRDY_SHIFT       (0x00000003u)
#define CSL_I2C_ICIMR_ICRRDY_RESETVAL    (0x00000000u)
/*----ICRRDY Tokens----*/
#define CSL_I2C_ICIMR_ICRRDY_DISABLE     (0x00000000u)
#define CSL_I2C_ICIMR_ICRRDY_ENABLE      (0x00000001u)

#define CSL_I2C_ICIMR_ARDY_MASK          (0x00000004u)
#define CSL_I2C_ICIMR_ARDY_SHIFT         (0x00000002u)
#define CSL_I2C_ICIMR_ARDY_RESETVAL      (0x00000000u)
/*----ARDY Tokens----*/
#define CSL_I2C_ICIMR_ARDY_DISABLE       (0x00000000u)
#define CSL_I2C_ICIMR_ARDY_ENABLE        (0x00000001u)

#define CSL_I2C_ICIMR_NACK_MASK          (0x00000002u)
#define CSL_I2C_ICIMR_NACK_SHIFT         (0x00000001u)
#define CSL_I2C_ICIMR_NACK_RESETVAL      (0x00000000u)
/*----NACK Tokens----*/
#define CSL_I2C_ICIMR_NACK_DISABLE       (0x00000000u)
#define CSL_I2C_ICIMR_NACK_ENABLE        (0x00000001u)

#define CSL_I2C_ICIMR_AL_MASK            (0x00000001u)
#define CSL_I2C_ICIMR_AL_SHIFT           (0x00000000u)
#define CSL_I2C_ICIMR_AL_RESETVAL        (0x00000000u)
/*----AL Tokens----*/
#define CSL_I2C_ICIMR_AL_DISABLE         (0x00000000u)
#define CSL_I2C_ICIMR_AL_ENABLE          (0x00000001u)

#define CSL_I2C_ICIMR_RESETVAL           (0x00000000u)

/* ICSTR */


#define CSL_I2C_ICSTR_SDIR_MASK          (0x00004000u)
#define CSL_I2C_ICSTR_SDIR_SHIFT         (0x0000000Eu)
#define CSL_I2C_ICSTR_SDIR_RESETVAL      (0x00000000u)
/*----SDIR Tokens----*/
#define CSL_I2C_ICSTR_SDIR_MASTER (0x00000000u)
#define CSL_I2C_ICSTR_SDIR_SLAVE (0x00000001u)
#define CSL_I2C_ICSTR_SDIR_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_NACKSNT_MASK       (0x00002000u)
#define CSL_I2C_ICSTR_NACKSNT_SHIFT      (0x0000000Du)
#define CSL_I2C_ICSTR_NACKSNT_RESETVAL   (0x00000000u)
/*----NACKSNT Tokens----*/
#define CSL_I2C_ICSTR_NACKSNT_NO_ACK (0x00000000u)
#define CSL_I2C_ICSTR_NACKSNT_NACK (0x00000001u)
#define CSL_I2C_ICSTR_NACKSNT_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_BB_MASK            (0x00001000u)
#define CSL_I2C_ICSTR_BB_SHIFT           (0x0000000Cu)
#define CSL_I2C_ICSTR_BB_RESETVAL        (0x00000000u)
/*----BB Tokens----*/
#define CSL_I2C_ICSTR_BB_FREE (0x00000000u)
#define CSL_I2C_ICSTR_BB_BUSY (0x00000001u)
#define CSL_I2C_ICSTR_BB_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_RSFULL_MASK        (0x00000800u)
#define CSL_I2C_ICSTR_RSFULL_SHIFT       (0x0000000Bu)
#define CSL_I2C_ICSTR_RSFULL_RESETVAL    (0x00000000u)
/*----RSFULL Tokens----*/
#define CSL_I2C_ICSTR_RSFULL_NO_OVERRUN (0x00000000u)
#define CSL_I2C_ICSTR_RSFULL_OVERRUN (0x00000001u)

#define CSL_I2C_ICSTR_XSMT_MASK          (0x00000400u)
#define CSL_I2C_ICSTR_XSMT_SHIFT         (0x0000000Au)
#define CSL_I2C_ICSTR_XSMT_RESETVAL      (0x00000001u)
/*----XSMT Tokens----*/
#define CSL_I2C_ICSTR_XSMT_UNDERFLOW (0x00000000u)
#define CSL_I2C_ICSTR_XSMT_NO_UNDERFLOW (0x00000001u)

#define CSL_I2C_ICSTR_AAS_MASK           (0x00000200u)
#define CSL_I2C_ICSTR_AAS_SHIFT          (0x00000009u)
#define CSL_I2C_ICSTR_AAS_RESETVAL       (0x00000000u)
/*----AAS Tokens----*/
#define CSL_I2C_ICSTR_AAS_CLEAR (0x00000000u)
#define CSL_I2C_ICSTR_AAS_SET (0x00000001u)

#define CSL_I2C_ICSTR_AD0_MASK           (0x00000100u)
#define CSL_I2C_ICSTR_AD0_SHIFT          (0x00000008u)
#define CSL_I2C_ICSTR_AD0_RESETVAL       (0x00000000u)
/*----AD0 Tokens----*/
#define CSL_I2C_ICSTR_AD0_NO (0x00000000u)
#define CSL_I2C_ICSTR_AD0_YES (0x00000001u)


#define CSL_I2C_ICSTR_SCD_MASK           (0x00000020u)
#define CSL_I2C_ICSTR_SCD_SHIFT          (0x00000005u)
#define CSL_I2C_ICSTR_SCD_RESETVAL       (0x00000000u)
/*----SCD Tokens----*/
#define CSL_I2C_ICSTR_SCD_NO (0x00000000u)
#define CSL_I2C_ICSTR_SCD_YES (0x00000001u)
#define CSL_I2C_ICSTR_SCD_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_ICXRDY_MASK        (0x00000010u)
#define CSL_I2C_ICSTR_ICXRDY_SHIFT       (0x00000004u)
#define CSL_I2C_ICSTR_ICXRDY_RESETVAL    (0x00000001u)
/*----ICXRDY Tokens----*/
#define CSL_I2C_ICSTR_ICXRDY_FALSE (0x00000000u)
#define CSL_I2C_ICSTR_ICXRDY_TRUE (0x00000001u)
#define CSL_I2C_ICSTR_ICXRDY_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_ICRRDY_MASK        (0x00000008u)
#define CSL_I2C_ICSTR_ICRRDY_SHIFT       (0x00000003u)
#define CSL_I2C_ICSTR_ICRRDY_RESETVAL    (0x00000000u)
/*----ICRRDY Tokens----*/
#define CSL_I2C_ICSTR_ICRRDY_FALSE (0x00000000u)
#define CSL_I2C_ICSTR_ICRRDY_TRUE (0x00000001u)
#define CSL_I2C_ICSTR_ICRRDY_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_ARDY_MASK          (0x00000004u)
#define CSL_I2C_ICSTR_ARDY_SHIFT         (0x00000002u)
#define CSL_I2C_ICSTR_ARDY_RESETVAL      (0x00000000u)
/*----ARDY Tokens----*/
#define CSL_I2C_ICSTR_ARDY_FALSE (0x00000000u)
#define CSL_I2C_ICSTR_ARDY_TRUE (0x00000001u)
#define CSL_I2C_ICSTR_ARDY_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_NACK_MASK          (0x00000002u)
#define CSL_I2C_ICSTR_NACK_SHIFT         (0x00000001u)
#define CSL_I2C_ICSTR_NACK_RESETVAL      (0x00000000u)
/*----NACK Tokens----*/
#define CSL_I2C_ICSTR_NACK_FALSE (0x00000000u)
#define CSL_I2C_ICSTR_NACK_TRUE (0x00000001u)
#define CSL_I2C_ICSTR_NACK_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_AL_MASK            (0x00000001u)
#define CSL_I2C_ICSTR_AL_SHIFT           (0x00000000u)
#define CSL_I2C_ICSTR_AL_RESETVAL        (0x00000000u)
/*----AL Tokens----*/
#define CSL_I2C_ICSTR_AL_FALSE (0x00000000u)
#define CSL_I2C_ICSTR_AL_TRUE (0x00000001u)
#define CSL_I2C_ICSTR_AL_CLEAR (0x00000001u)

#define CSL_I2C_ICSTR_RESETVAL           (0x00000410u)

/* ICCLKL */


#define CSL_I2C_ICCLKL_ICCL_MASK         (0x0000FFFFu)
#define CSL_I2C_ICCLKL_ICCL_SHIFT        (0x00000000u)
#define CSL_I2C_ICCLKL_ICCL_RESETVAL     (0x00000000u)

#define CSL_I2C_ICCLKL_RESETVAL          (0x00000000u)

/* ICCLKH */


#define CSL_I2C_ICCLKH_ICCH_MASK         (0x0000FFFFu)
#define CSL_I2C_ICCLKH_ICCH_SHIFT        (0x00000000u)
#define CSL_I2C_ICCLKH_ICCH_RESETVAL     (0x00000000u)

#define CSL_I2C_ICCLKH_RESETVAL          (0x00000000u)

/* ICCNT */


#define CSL_I2C_ICCNT_ICDC_MASK          (0x0000FFFFu)
#define CSL_I2C_ICCNT_ICDC_SHIFT         (0x00000000u)
#define CSL_I2C_ICCNT_ICDC_RESETVAL      (0x00000000u)

#define CSL_I2C_ICCNT_RESETVAL           (0x00000000u)

/* ICDRR */


#define CSL_I2C_ICDRR_D_MASK             (0x000000FFu)
#define CSL_I2C_ICDRR_D_SHIFT            (0x00000000u)
#define CSL_I2C_ICDRR_D_RESETVAL         (0x00000000u)

#define CSL_I2C_ICDRR_RESETVAL           (0x00000000u)

/* ICSAR */


#define CSL_I2C_ICSAR_SADDR_MASK         (0x000003FFu)
#define CSL_I2C_ICSAR_SADDR_SHIFT        (0x00000000u)
#define CSL_I2C_ICSAR_SADDR_RESETVAL     (0x000003FFu)

#define CSL_I2C_ICSAR_RESETVAL           (0x000003FFu)

/* ICDXR */


#define CSL_I2C_ICDXR_D_MASK             (0x000000FFu)
#define CSL_I2C_ICDXR_D_SHIFT            (0x00000000u)
#define CSL_I2C_ICDXR_D_RESETVAL         (0x00000000u)

#define CSL_I2C_ICDXR_RESETVAL           (0x00000000u)

/* ICMDR */


#define CSL_I2C_ICMDR_NACKMOD_MASK       (0x00008000u)
#define CSL_I2C_ICMDR_NACKMOD_SHIFT      (0x0000000Fu)
#define CSL_I2C_ICMDR_NACKMOD_RESETVAL   (0x00000000u)
/*----NACKMOD Tokens----*/
#define CSL_I2C_ICMDR_NACKMOD_SLAVE_RX (0x00000000u)
#define CSL_I2C_ICMDR_NACKMOD_MASTER_SLAVE_RX (0x00000001u)

#define CSL_I2C_ICMDR_FREE_MASK          (0x00004000u)
#define CSL_I2C_ICMDR_FREE_SHIFT         (0x0000000Eu)
#define CSL_I2C_ICMDR_FREE_RESETVAL      (0x00000000u)
/*----FREE Tokens----*/
#define CSL_I2C_ICMDR_FREE_FALSE (0x00000000u)
#define CSL_I2C_ICMDR_FREE_TRUE (0x00000001u)

#define CSL_I2C_ICMDR_STT_MASK           (0x00002000u)
#define CSL_I2C_ICMDR_STT_SHIFT          (0x0000000Du)
#define CSL_I2C_ICMDR_STT_RESETVAL       (0x00000000u)
/*----STT Tokens----*/
#define CSL_I2C_ICMDR_STT_CLEAR (0x00000000u)
#define CSL_I2C_ICMDR_STT_SET (0x00000001u)


#define CSL_I2C_ICMDR_STP_MASK           (0x00000800u)
#define CSL_I2C_ICMDR_STP_SHIFT          (0x0000000Bu)
#define CSL_I2C_ICMDR_STP_RESETVAL       (0x00000000u)
/*----STP Tokens----*/
#define CSL_I2C_ICMDR_STP_CLEAR (0x00000000u)
#define CSL_I2C_ICMDR_STP_SET (0x00000001u)

#define CSL_I2C_ICMDR_MST_MASK           (0x00000400u)
#define CSL_I2C_ICMDR_MST_SHIFT          (0x0000000Au)
#define CSL_I2C_ICMDR_MST_RESETVAL       (0x00000000u)
/*----MST Tokens----*/
#define CSL_I2C_ICMDR_MST_SLAVE (0x00000000u)
#define CSL_I2C_ICMDR_MST_MASTER (0x00000001u)

#define CSL_I2C_ICMDR_TRX_MASK           (0x00000200u)
#define CSL_I2C_ICMDR_TRX_SHIFT          (0x00000009u)
#define CSL_I2C_ICMDR_TRX_RESETVAL       (0x00000000u)
/*----TRX Tokens----*/
#define CSL_I2C_ICMDR_TRX_RX_MODE (0x00000000u)
#define CSL_I2C_ICMDR_TRX_TX_MODE (0x00000001u)

#define CSL_I2C_ICMDR_XA_MASK            (0x00000100u)
#define CSL_I2C_ICMDR_XA_SHIFT           (0x00000008u)
#define CSL_I2C_ICMDR_XA_RESETVAL        (0x00000000u)
/*----XA Tokens----*/
#define CSL_I2C_ICMDR_XA_7BIT (0x00000000u)
#define CSL_I2C_ICMDR_XA_ (0x0000000Au)

#define CSL_I2C_ICMDR_RM_MASK            (0x00000080u)
#define CSL_I2C_ICMDR_RM_SHIFT           (0x00000007u)
#define CSL_I2C_ICMDR_RM_RESETVAL        (0x00000000u)
/*----RM Tokens----*/
#define CSL_I2C_ICMDR_RM_DISABLE (0x00000000u)
#define CSL_I2C_ICMDR_RM_ENABLE (0x00000001u)

#define CSL_I2C_ICMDR_DLB_MASK           (0x00000040u)
#define CSL_I2C_ICMDR_DLB_SHIFT          (0x00000006u)
#define CSL_I2C_ICMDR_DLB_RESETVAL       (0x00000000u)
/*----DLB Tokens----*/
#define CSL_I2C_ICMDR_DLB_DISABLE (0x00000000u)
#define CSL_I2C_ICMDR_DLB_ENABLE (0x00000001u)

#define CSL_I2C_ICMDR_IRS_MASK           (0x00000020u)
#define CSL_I2C_ICMDR_IRS_SHIFT          (0x00000005u)
#define CSL_I2C_ICMDR_IRS_RESETVAL       (0x00000000u)
/*----IRS Tokens----*/
#define CSL_I2C_ICMDR_IRS_RESET (0x00000000u)
#define CSL_I2C_ICMDR_IRS_DISABLE (0x00000000u)
#define CSL_I2C_ICMDR_IRS_ENABLE (0x00000001u)

#define CSL_I2C_ICMDR_STB_MASK           (0x00000010u)
#define CSL_I2C_ICMDR_STB_SHIFT          (0x00000004u)
#define CSL_I2C_ICMDR_STB_RESETVAL       (0x00000000u)
/*----STB Tokens----*/
#define CSL_I2C_ICMDR_STB_DISABLE (0x00000000u)
#define CSL_I2C_ICMDR_STB_ENABLE (0x00000001u)

#define CSL_I2C_ICMDR_FDF_MASK           (0x00000008u)
#define CSL_I2C_ICMDR_FDF_SHIFT          (0x00000003u)
#define CSL_I2C_ICMDR_FDF_RESETVAL       (0x00000000u)
/*----FDF Tokens----*/
#define CSL_I2C_ICMDR_FDF_DISABLE (0x00000000u)
#define CSL_I2C_ICMDR_FDF_ENABLE (0x00000001u)

#define CSL_I2C_ICMDR_BC_MASK            (0x00000007u)
#define CSL_I2C_ICMDR_BC_SHIFT           (0x00000000u)
#define CSL_I2C_ICMDR_BC_RESETVAL        (0x00000000u)
#define CSL_I2C_ICMDR_BC_8BIT (0x00000000u)
#define CSL_I2C_ICMDR_BC_1BIT (0x00000001u)
#define CSL_I2C_ICMDR_BC_2BIT (0x00000002u)
#define CSL_I2C_ICMDR_BC_3BIT (0x00000003u)
#define CSL_I2C_ICMDR_BC_4BIT (0x00000004u)
#define CSL_I2C_ICMDR_BC_5BIT (0x00000005u)
#define CSL_I2C_ICMDR_BC_6BIT (0x00000006u)
#define CSL_I2C_ICMDR_BC_7BIT (0x00000007u)

#define CSL_I2C_ICMDR_RESETVAL           (0x00000000u)

/* ICIVR */


#define CSL_I2C_ICIVR_INTCODE_MASK       (0x00000007u)
#define CSL_I2C_ICIVR_INTCODE_SHIFT      (0x00000000u)
#define CSL_I2C_ICIVR_INTCODE_RESETVAL   (0x00000000u)
/*----INTCODE Tokens----*/
#define CSL_I2C_ICIVR_INTCODE_NONE       (0x00000000u)
#define CSL_I2C_ICIVR_INTCODE_AL         (0x00000001u)
#define CSL_I2C_ICIVR_INTCODE_NACK       (0x00000002u)
#define CSL_I2C_ICIVR_INTCODE_ARDY       (0x00000003u)
#define CSL_I2C_ICIVR_INTCODE_ICRRDY     (0x00000004u)
#define CSL_I2C_ICIVR_INTCODE_ICXRDY     (0x00000005u)
#define CSL_I2C_ICIVR_INTCODE_SCD        (0x00000006u)
#define CSL_I2C_ICIVR_INTCODE_AAS        (0x00000007u)

#define CSL_I2C_ICIVR_RESETVAL           (0x00000000u)

/* ICEMDR */


#define CSL_I2C_ICEMDR_IGNACK_MASK       (0x00000002u)
#define CSL_I2C_ICEMDR_IGNACK_SHIFT      (0x00000001u)
#define CSL_I2C_ICEMDR_IGNACK_RESETVAL   (0x00000000u)
/*----IGNACK Tokens----*/
#define CSL_I2C_ICEMDR_IGNACK_DISABLE (0x00000000u)
#define CSL_I2C_ICEMDR_IGNACK_ENABLE (0x00000001u)

#define CSL_I2C_ICEMDR_BCM_MASK          (0x00000001u)
#define CSL_I2C_ICEMDR_BCM_SHIFT         (0x00000000u)
#define CSL_I2C_ICEMDR_BCM_RESETVAL      (0x00000001u)

#define CSL_I2C_ICEMDR_RESETVAL          (0x00000001u)

/* ICPSC */


#define CSL_I2C_ICPSC_IPSC_MASK          (0x000000FFu)
#define CSL_I2C_ICPSC_IPSC_SHIFT         (0x00000000u)
#define CSL_I2C_ICPSC_IPSC_RESETVAL      (0x00000000u)

#define CSL_I2C_ICPSC_RESETVAL           (0x00000000u)

/* ICPID1 */


#define CSL_I2C_ICPID1_CLASS_MASK        (0x0000FF00u)
#define CSL_I2C_ICPID1_CLASS_SHIFT       (0x00000008u)
#define CSL_I2C_ICPID1_CLASS_RESETVAL    (0x00000001u)

#define CSL_I2C_ICPID1_REVISION_MASK     (0x000000FFu)
#define CSL_I2C_ICPID1_REVISION_SHIFT    (0x00000000u)
#define CSL_I2C_ICPID1_REVISION_RESETVAL (0x00000006u)

#define CSL_I2C_ICPID1_RESETVAL (0x00000106u)

/* ICPID2 */


#define CSL_I2C_ICPID2_TYPE_MASK         (0x000000FFu)
#define CSL_I2C_ICPID2_TYPE_SHIFT        (0x00000000u)
#define CSL_I2C_ICPID2_TYPE_RESETVAL     (0x00000005u)

#define CSL_I2C_ICPID2_RESETVAL          (0x00000005u)

#endif

