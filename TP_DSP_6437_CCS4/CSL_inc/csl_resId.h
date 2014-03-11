/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */


/* ---- File: <csl_resId.h> ---- */
/* for the ARM-side of Hibari */
#ifndef _CSL_RESID_H_
#define _CSL_RESID_H_

/* ---- Total number of modues : CSL Abstraction ---- */
/* Module ID 0 is reserved. */
#define CSL_CHIP_NUM_MODULES   (14)

#define CSL_LCDC_ID                (1)
#define CSL_PWM_ID                 (2)
#define CSL_UART_ID                (3)
#define CSL_MMCSD_ID               (4)
#define CSL_I2C_ID                 (5)
#define CSL_ATA_ID                 (6)
#define CSL_DMA_ID                 (7)
#define CSL_SPI_ID                 (8)
#define CSL_INTC_ID                (9)
#define CSL_GPIO_ID                (10)
#define CSL_MS_ID                  (11)
#define CSL_EMIF_ID                (12)
#define CSL_NTSC_ID                (13)
#define CSL_NAND_ID                (14)
#define CSL_MCBSP_ID               (15)

/* ---- Total Number of Resource, one-to-one correspondence with H/W resource */
/* Resource ID - 0 is resvd. */
#define CSL_CHIP_NUM_RESOURCES  (20)

#define CSL_LCDC_0_UID              (1)
#define CSL_PWM_0_UID               (2)
#define CSL_PWM_1_UID               (3)
#define CSL_UART_0_UID              (4)
#define CSL_UART_1_UID              (5)
#define CSL_MMCSD_0_UID             (6)
#define CSL_I2C_0_UID               (7)
#define CSL_ATA_0_UID               (8)
#define CSL_DMA_0_UID               (9)
#define CSL_DMA_CHA0_UID            (10)
#define CSL_DMA_CHA1_UID            (11)
#define CSL_DMA_CHA2_UID            (12)
#define CSL_SPI_0_UID               (13)
#define CSL_INTC_0_UID              (14)
#define CSL_GPIO_UID                (15)
#define CSL_MGPIO_UID               (16)
#define CSL_MS_0_UID                (17)
#define CSL_EMIF_0_UID              (18)
#define CSL_NTSC_0_UID              (19)
#define CSL_NAND_0_UID              (20)


/*----  XIO masks for peripheral instances ---- */
#define CSL_LCDC_0_XIO              (0x00000000)
#define CSL_PWM_0_XIO               (0x00000000)
#define CSL_PWM_1_XIO               (0x00000000)
#define CSL_UART_0_XIO              (0x00000000)
#define CSL_UART_1_XIO              (0x00000000)
#define CSL_MMCSD_0_XIO             (0x00000000)
#define CSL_I2C_0_XIO               (0x00000000)
#define CSL_ATA_0_XIO               (0x00000000)
#define CSL_DMA_0_XIO               (0x00000000)
#define CSL_DMA_CHA0_XIO            (0x00000000)
#define CSL_DMA_CHA1_XIO            (0x00000000)
#define CSL_DMA_CHA2_XIO            (0x00000000)
#define CSL_SPI_0_XIO               (0x00000000)
#define CSL_INTC_0_XIO              (0x00000000)
#define CSL_GPIO_XIO                (0x00000000)
#define CSL_MGPIO_XIO               (0x00000000)
#define CSL_MS_0_XIO                (0x00000000)
#define CSL_EMIF_0_XIO              (0x00000000)
#define CSL_NTSC_0_XIO              (0x00000000)
#define CSL_NAND_0_XIO              (0x00000000)

#endif /* _CSL_RESOURCE_H_ */

