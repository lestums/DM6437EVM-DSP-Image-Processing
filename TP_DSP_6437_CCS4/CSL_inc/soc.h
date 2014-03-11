/*  ============================================================================
 *  Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005, 2006
 *
 *  Use of this software is controlled by the terms and conditions found in the
 *  license agreement under which this software has been supplied.
 *  ===========================================================================
 */
/* =============================================================================
 *  Revision History
 *  ===============
 *  04-Sep-2006 Raghu File Created
 *  21-Sep-2006 NG    Updated the file.
 *  22-Sep-2006 Shiv  Updated EDMA related stuffs
 *  07-Oct-2006 NG    Updated VPSS related stuffs
 * =============================================================================
 */
#ifndef _SOC_H_
#define _SOC_H_

#include <cslr.h>
/**************************************************************************\
* 64 soc file
\**************************************************************************/

/*****************************************************************************\
* Static inline definition
\*****************************************************************************/
#ifndef CSL_IDEF_INLINE
#define CSL_IDEF_INLINE static inline
#endif

/**************************************************************************\
* Peripheral Instance count
\**************************************************************************/
/** @brief Number of DDR2 instances */
#define CSL_DDR2_PER_CNT                 1

/** @brief Number of EDMA CC instances */
#define CSL_EDMA3CC_CNT                  1
/** @brief Number of EDMA TC instances */
#define CSL_EDMA3TC_CNT                  3

/** @brief Number of Emac instances */
#define CSL_EMAC_PER_CNT                 1

/** @brief Number of EMIF  instances */
#define CSL_EMIF_PER_CNT                 1

/** @brief Number of GPIO instances */
#define CSL_GPIO_PER_CNT                 1

/** @brief Number of HECC instances */
#define CSL_HECC_PER_CNT                 1

/** @brief Number of HPI instances */
#define CSL_HPI_PER_CNT                  1

/** @brief Number of I2C instances */
#define CSL_I2C_PER_CNT                  1

/** @brief Number of MCASP instances */
#define CSL_MCASP_PER_CNT                2

/** @brief Number of MCBSP instances */
#define CSL_MCBSP_PER_CNT                2

/** @brief Number of MDIO instances */
#define CSL_MDIO_PER_CNT                 1

/** @brief Number of PCI instances */
#define CSL_PCI_PER_CNT                  1

/** @brief Number of PLLC instances */
#define CSL_PLLC_PER_CNT                 2

/** @brief Number of PSC instances */
#define CSL_PSC_PER_CNT                  1

/** @brief Number of PWM instances */
#define CSL_PWM_PER_CNT                  3

/** @brief Number of Timer instances */
#define CSL_TMR_PER_CNT                  3

/** @brief Number of UART instances */
#define CSL_UART_PER_CNT                 2

/** @brief Number of VLYNQ instances */
#define CSL_VLYNQ_PER_CNT                1

#ifdef CHIP_DM6437
/** @brief Number of VPSS instances */
#define CSL_VPSS_PER_CNT                 1
#endif

/** @brief Number of System module instances */
#define CSL_SYS_PER_CNT                 1

#ifdef CHIP_DM6437
/** @brief Number of instance for VPSS Front-End modules */
#define CSL_VPSS_CCDC_PER_CNT            1
#define CSL_VPSS_PREV_PER_CNT            1
#define CSL_VPSS_RESZ_PER_CNT            1
#define CSL_VPSS_HIST_PER_CNT            1
#define CSL_VPSS_H3A_PER_CNT             1
#define CSL_VPSS_VPSS_PER_CNT            1

/** @brief Number of instance for VPSS Back-End modules */
#define CSL_VPSS_VENC_PER_CNT            1
#define CSL_VPSS_OSD_PER_CNT             1
#define CSL_VPSS_VPBE_TOP_PER_CNT        1
#endif

/**************************************************************************\
* Peripheral Instance definitions.
\**************************************************************************/

/** @brief Peripheral Instance for DDR2 */
#define CSL_DDR2                        (0)

/** @brief Peripheral Instance of EDMA CC instances */
#define CSL_EDMA3                       (0)
/** @brief Peripheral Instance of EDMA TC instances */
#define CSL_EDMA3TC_0                   (0)
#define CSL_EDMA3TC_1                   (1)
#define CSL_EDMA3TC_2                   (2)

/** @brief Peripheral Instance for EMAC */
#define  CSL_EMAC                       (0)

/** @brief Peripheral Instance for EMIFA */
#define  CSL_EMIFA                      (0)

/** @brief Peripheral Instance for GPIO */
#define CSL_GPIO                        (0)

/** @brief Instance number of HECC module */
#define CSL_HECC                        (0)

/** @brief Peripheral Instance for HPI */
#define CSL_HPI                         (0)

/** @brief Peripheral Instance for I2C */
#define CSL_I2C                         (0)

/** @brief Instance number of INTC module */
#define CSL_INTC                        (0)

/** @brief Instance number of MCASP module */
#define CSL_MCASP_0                     (0)
#define CSL_MCASP_1                     (1)

/** @brief Peripheral Instances of MCBSP instances */
#define CSL_MCBSP_0                     (0)
#define CSL_MCBSP_1                     (1)

/** @brief Peripheral Instances for MDIO */
#define CSL_MDIO                        (0)

/** @brief Instance number of PCI module */
#define CSL_PCI                         (0)

/** @brief Instance number of PLL controller 1 */
#define CSL_PLLC_0                     (0)
/** @brief Instance number of PLL controller 2 */
#define CSL_PLLC_1                      (1)

/** @brief Instance number of PSC module */
#define CSL_PSC                         (0)

/** @brief Instance number of PWM module */
#define CSL_PWM_0                       (0)
#define CSL_PWM_1                       (1)
#define CSL_PWM_2                       (2)

/** @brief Peripheral Instances of Timer 64 instances */
#define CSL_TMR_0                       (0)
#define CSL_TMR_1                       (1)
#define CSL_TMR_2                       (2)

/** @brief Instance number of UART module */
#define CSL_UART_0                      (0)
#define CSL_UART_1                      (1)

/** @brief Peripheral Instance for VLYNQ */
#define CSL_VLYNQ                       (0)

#ifdef CHIP_DM6437
/** @brief Instance number of VPSS module */
#define CSL_VPSS                        (0)

/** @brief Instance number for VPSS Front-End modules */
#define CSL_VPSS_CCDC                   (0)
#define CSL_VPSS_PREV                   (0)
#define CSL_VPSS_RESZ                   (0)
#define CSL_VPSS_HIST                   (0)
#define CSL_VPSS_H3A                    (0)
#define CSL_VPSS_VPSS                   (0)

/** @brief Instance number for VPSS Back-End modules */
#define CSL_VPSS_VENC                   (0)
#define CSL_VPSS_OSD                    (0)
#define CSL_VPSS_VPBE_TOP               (0)
#endif

/**************************************************************************\
* Peripheral Base Address
\**************************************************************************/
/** #brief Cache Module memory mapped address  */
#define CSL_CACHE_0_REGS                (0x01840000u)

/** #brief DDR2 Module memory mapped address  */
#define CSL_DDR2_0_REGS                 (0x20000000u)

/** @brief Base address of Channel controller  memory mapped registers */
#define CSL_EDMA3CC_0_REGS              (0x01C00000u)

/** @brief Base address of Transfer controller  memory mapped registers */
#define CSL_EDMA3TC_0_REGS              (0x01C10000u)
#define CSL_EDMA3TC_1_REGS              (0x01C10400u)
#define CSL_EDMA3TC_2_REGS              (0x01C10800u)

/** @brief Base address of EMAC memory mapped registers */
#define CSL_EMAC_0_REGS                 (0x01C80000u)

/** #brief EMIF64 Module memory mapped address  */
#define CSL_EMIFA_0_REGS                (0x01E00000u)

/** @brief GPIO Module memory mapped address  */
#define CSL_GPIO_0_REGS                 (0x01C67000u)

/** @brief Base address of HECC register */
#define CSL_HECC_0_REGS                 (0x01C23000u)

/** @brief Base address of System module register */
#define CSL_SYS_0_REGS                  (0x01C40000u)

/** @brief HPI Module memory mapped address  */
#define CSL_HPI_0_REGS                  (0x01C67800u)

/** #brief I2C Module memory mapped address  */
#define CSL_I2C_0_REGS                  (0x01C21000u)

/** #brief IDMA Module memory mapped address  */
#define CSL_IDMA_0_REGS                 (0x01820000u)

/** @brief Base address of INTC memory mapped registers */
#define CSL_INTC_0_REGS                 (0x01800000u)

/** @brief Base address of MCASP memory mapped registers */
#define CSL_MCASP_0_REGS                (0x01D01000u)
#define CSL_MCASP_1_REGS                (0x01D01800u)

/** @brief Base address of MCBSP memory mapped registers */
#define CSL_MCBSP_0_REGS                (0x01D00000u)
#define CSL_MCBSP_1_REGS                (0x01D00800u)

/** @brief MDIO Module memory mapped address    */
#define CSL_MDIO_0_REGS                 (0x01C84000u)

/** @brief Base address of PCI  register */
#define CSL_PCI_0_REGS                  (0x01C1A000u)

/** @brief Base address of PLLC 1 register */
#define CSL_PLLC_0_REGS                 (0x01C40800u)
/** @brief Base address of PLLC 2 register */
#define CSL_PLLC_1_REGS                 (0x01C40C00u)

/** @brief Base address of PSC register */
#define CSL_PSC_0_REGS                  (0x01C41000u)

/** @brief Base address of PWM 1 register */
#define CSL_PWM_0_REGS                  (0x01C22000u)
/** @brief Base address of PWM 2 register */
#define CSL_PWM_1_REGS                  (0x01C22400u)
/** @brief Base address of PWM 3 register */
#define CSL_PWM_2_REGS                  (0x01C22800u)

/** @brief Base address of timer64 memory mapped registers */
#define CSL_TMR_0_REGS                  (0x01C21400u)
#define CSL_TMR_1_REGS                  (0x01C21800u)
#define CSL_TMR_2_REGS                  (0x01C21C00u)

/** @brief Base address of UART 1 register */
#define CSL_UART_0_REGS                 (0x01C20000u)
/** @brief Base address of UART 2 register */
#define CSL_UART_1_REGS                 (0x01C20400u)

/** @brief VLYNQ Module memory mapped address  */
#define CSL_VLYNQ_0_REGS                (0x01E01000u)

#ifdef CHIP_DM6437
/** @brief Base address of VPSS register */
#define CSL_VPSS_0_REGS                 (0x01C70000u)

/******************************************************************************\
* VPSS Descriptor section
\******************************************************************************/
/* VPSS Front-End Base Addresses */
#define CSL_VPSS_CCDC_0_REGS            ((CSL_VPSS_0_REGS) + (0x00000400u))
#define CSL_VPSS_PREV_0_REGS            ((CSL_VPSS_0_REGS) + (0x00000800u))
#define CSL_VPSS_RESZ_0_REGS            ((CSL_VPSS_0_REGS) + (0x00000C00u))
#define CSL_VPSS_HIST_0_REGS            ((CSL_VPSS_0_REGS) + (0x00001000u))
#define CSL_VPSS_H3A_0_REGS             ((CSL_VPSS_0_REGS) + (0x00001400u))
#define CSL_VPSS_VFOC_0_REGS            ((CSL_VPSS_0_REGS) + (0x00001800u))
#define CSL_VPSS_SBL_0_REGS             ((CSL_VPSS_0_REGS) + (0x00003400u))

/* VPSS Back-End Base Addresses */
/*#define CSL_VPSS_VPBE_0_REGS            ((CSL_VPSS_0_REGS) + (0x00002400u))*/
#define CSL_VPSS_VENC_0_REGS            ((CSL_VPSS_0_REGS) + (0x00002400u))
#define CSL_VPSS_OSD_0_REGS             ((CSL_VPSS_0_REGS) + (0x00002600u))
#define CSL_VPSS_VPBE_TOP_0_REGS        ((CSL_VPSS_0_REGS) + (0x00002780u))
#endif

/** @brief Base address of PDC registers */
#define CSL_PWRDWN_PDC_REGS             (0x01810000u)
/** @brief Base address of L2 power Down registers */
#define CSL_PWRDWN_L2_REGS              (0x0184c000u)

/******************************************************************************\
* HECC Descriptor section
\******************************************************************************/
#define CSL_HECC_MAILBOX_BASE_ADDR      (0x01C24000u)
#define CSL_HECC_TCR_BASE_ADDR          (0x01C25000u)

/******************************************************************************\
* EMAC Descriptor section
\******************************************************************************/
#define CSL_ECTL_BASE_ADDR              (0x01C81000u)
#define CSL_EMAC_DSC_BASE_ADDR          (0x01C82000u)

/******************************************************************************\
* MCASP Descriptor section
\******************************************************************************/
#define CSL_MCASP_0_DATA_BASE_ADDR      (0x01D01400u)
#define CSL_MCASP_1_DATA_BASE_ADDR      (0x01D01C00u)

/*****************************************************************************\
* Interrupt Event IDs
\*****************************************************************************/
/**
 * @brief   Interrupt Event IDs
 */
/* Output of event combiner 0, for events 1 to 31  */
#define    CSL_INTC_EVENTID_EVT0            (0)
/* Output of event combiner 0, for events 32 to 63 */
#define    CSL_INTC_EVENTID_EVT1            (1)
/* Output of event combiner 0, for events 64 to 95 */
#define    CSL_INTC_EVENTID_EVT2            (2)
/* Output of event combiner 0, for events 96 to 127 */
#define    CSL_INTC_EVENTID_EVT3            (3)

/* Timer 0 lower counter interrupt     */
#define    CSL_INTC_EVENTID_TINTLO0         (4)
/* Timer 0 higher counter interrupt    */
#define    CSL_INTC_EVENTID_TINTHI0         (5)
/* Timer 1 lower counter interrupt     */
#define    CSL_INTC_EVENTID_TINTLO1         (6)
/* Timer 1 higher counter interrupt    */
#define    CSL_INTC_EVENTID_TINTHI1         (7)
/* Timer 2 Watchdog interrupt          */
#define    CSL_INTC_EVENTID_WDINT           (8)

/** EMU interrupt for:
  * 1. Host scan access
  * 2. DTDMA transfer complete
  * 3. AET interrupt
  */
#define    CSL_INTC_EVENTID_EMU_DTDMA       (9)

/* Event ID 10 is reserved */

/* EMU real time data exchange receive complete    */
#define    CSL_INTC_EVENTID_EMU_RTDXRX      (11)
/* EMU RTDX transmit complete   */
#define    CSL_INTC_EVENTID_EMU_RTDXTX      (12)
/* IDMA Channel 0 Interrupt */
#define    CSL_INTC_EVENTID_IDMA0           (13)
/* IDMA Channel 1 Interrupt */
#define    CSL_INTC_EVENTID_IDMA1           (14)

/* Event ID 15-23 are reserved */

/* VPSS_CCDC video-in 0  interrupt */
#define    CSL_INTC_EVENTID_VDINT0          (24)
/* VPSS_CCDC video-in 1  interrupt */
#define    CSL_INTC_EVENTID_VDINT1          (25)
/* VPSS_CCDC video-in 2  interrupt */
#define    CSL_INTC_EVENTID_VDINT2          (26)
/* VPSS Histogram interrupt */
#define    CSL_INTC_EVENTID_HISTINT         (27)
/* VPSS – AE/AWB/AF interrupt */
#define    CSL_INTC_EVENTID_H3AINT          (28)
/* VPSS – Previewer interrupt */
#define    CSL_INTC_EVENTID_PRVUINT         (29)
/* VPSS – Resizer interrupt */
#define    CSL_INTC_EVENTID_RSZINT          (30)
/* VPSS VFocus interrupt */
#define    CSL_INTC_EVENTID_VFOCINT         (31)
/* VPSS – VPBE interrupt */
#define    CSL_INTC_EVENTID_VENCINT         (32)

/* Event ID 33 is reserved */

/* TPCC Global interrupt */
#define    CSL_INTC_EVENTID_EDMA3CC_GINT    (34)

/* CC Completion Interrupt - Mask0 */
#define    CSL_INTC_EVENTID_EDMA3CC_INT0    (35)
/* CC Completion Interrupt - Mask1 */
#define    CSL_INTC_EVENTID_EDMA3CC_INT1    (36)

/* CC Error Interrupt    */
#define    CSL_INTC_EVENTID_EDMA3CC_ERRINT  (37)
/* TC0 Error Interrupt */
#define    CSL_INTC_EVENTID_EDMA3TC0_ERRINT (38)
/* TC1 Error Interrupt */
#define    CSL_INTC_EVENTID_EDMA3TC1_ERRINT (39)
/* TC2 Error Interrupt */
#define    CSL_INTC_EVENTID_EDMA3TC2_ERRINT (40)
/* PSC-ALLINT Interrupt */
#define    CSL_INTC_EVENTID_PSCINT          (41)

/* Event ID 42 is reserved */

/* CPGMAC Wrapper interrupt */
#define    CSL_INTC_EVENTID_EMACINT         (43)

/* Event ID's 44-46 are reserved */

/* UHPI interrupt */
#define  CSL_INTC_EVENTID_HPIINT            (47)
/* McBSP0 TX interrupt */
#define  CSL_INTC_EVENTID_MBXINT0           (48)
/* McBSP0 RX interrupt */
#define  CSL_INTC_EVENTID_MBRINT0           (49)
/* McBSP1 TX interrupt */
#define  CSL_INTC_EVENTID_MBXINT1           (50)
/* McBSP1 RX interrupt */
#define  CSL_INTC_EVENTID_MBRINT1           (51)

/* Event ID 52 is reserved */

/* DDR EMIF interrupt */
#define  CSL_INTC_EVENTID_DDRINT            (53)
/* Async EMIF interrupt */
#define  CSL_INTC_EVENTID_AEMIFINT          (54)
/* VLYNQ interrupt */
#define  CSL_INTC_EVENTID_VLQINT            (55)
/* PCI interrupt */
#define  CSL_INTC_EVENTID_PCIINT            (56)
/* HECC0 interrupt */
#define  CSL_INTC_EVENTID_HECC0INT          (57)
/* HECC1 interrupt */
#define  CSL_INTC_EVENTID_HECC1INT          (58)
/* MCASP0 TX interrupt */
#define  CSL_INTC_EVENTID_AXINT0            (59)
/* MCASP0 RX interrupt */
#define  CSL_INTC_EVENTID_ARINT0            (60)
/* MCASP1 TX interrupt */
#define  CSL_INTC_EVENTID_AXINT1            (61)
/* MCASP1 RX interrupt */
#define  CSL_INTC_EVENTID_ARINT1            (62)

/* Event ID 63 is reserved */

/* GPIO 0 interrupt */
#define  CSL_INTC_EVENTID_GPIO0             (64)
/* GPIO 1 interrupt */
#define  CSL_INTC_EVENTID_GPIO1             (65)
/* GPIO 2 interrupt */
#define  CSL_INTC_EVENTID_GPIO2             (66)
/* GPIO 3 interrupt */
#define  CSL_INTC_EVENTID_GPIO3             (67)
/* GPIO 4 interrupt */
#define  CSL_INTC_EVENTID_GPIO4             (68)
/* GPIO 5 interrupt */
#define  CSL_INTC_EVENTID_GPIO5             (69)
/* GPIO 6 interrupt */
#define  CSL_INTC_EVENTID_GPIO6             (70)
/* GPIO 7 interrupt */
#define  CSL_INTC_EVENTID_GPIO7             (71)
/* GPIO Bank 0 interrupt */
#define  CSL_INTC_EVENTID_GPIOBNK0          (72)
/* GPIO Bank 1 interrupt */
#define  CSL_INTC_EVENTID_GPIOBNK1          (73)
/* GPIO Bank 2 interrupt */
#define  CSL_INTC_EVENTID_GPIOBNK2          (74)
/* GPIO Bank 3 interrupt */
#define  CSL_INTC_EVENTID_GPIOBNK3          (75)
/* GPIO Bank 4 interrupt */
#define  CSL_INTC_EVENTID_GPIOBNK4          (76)
/* GPIO Bank 5 interrupt */
#define  CSL_INTC_EVENTID_GPIOBNK5          (77)
/* GPIO Bank 6 interrupt */
#define  CSL_INTC_EVENTID_GPIOBNK6          (78)

/* Event ID 79 is reserved */

/* PWM0 interrupt */
#define  CSL_INTC_EVENTID_PWM0              (80)
/* PWM1 interrupt */
#define  CSL_INTC_EVENTID_PWM1              (81)
/* PWM2 interrupt */
#define  CSL_INTC_EVENTID_PWM2              (82)
/* I2C interrupt */
#define  CSL_INTC_EVENTID_I2CINT            (83)
/* UART0 interrupt */
#define  CSL_INTC_EVENTID_UARTINT0          (84)
/* UART1 interrupt */
#define  CSL_INTC_EVENTID_UARTINT1          (85)

/* Event ID's 86-89 are reserved */

/* PBIST interrupt */
#define  CSL_INTC_EVENTID_PBISTINT          (98)

/* Event ID 91-95 is reserved */

/* Dropped CPU interrupt event */
#define    CSL_INTC_EVENTID_INTERR          (96)
/* EMC Invalid IDMA parameters     */
#define    CSL_INTC_EVENTID_EMC_IDMAERR     (97)

/* Event ID 99 is reserved */

/* EFI Interrupt from side A    */
#define    CSL_INTC_EVENTID_EFIINTA         (100)
/* EFI Interrupt from side B    */
#define    CSL_INTC_EVENTID_EFIINTB         (101)

/* Event ID 102-112 is reserved */

/* L1P Single bit error detected during DMA read */
#define    CSL_INTC_EVENTID_L1P_ED          (113)

/* Event ID 114-115 is reserved */

/* L2 single bit error detected */
#define    CSL_INTC_EVENTID_L2_ED1          (116)
/* L2 two bit error detected */
#define    CSL_INTC_EVENTID_L2_ED2          (117)
/* Power Down sleep interrupt */
#define    CSL_INTC_EVENTID_PDC_INT         (118)

/* Event ID 119 is reserved */

/* System  CPU memory protection fault */
#define    CSL_INTC_EVENTID_SYS_CMPA        (119)
/* L1P CPU memory protection fault */
#define    CSL_INTC_EVENTID_L1P_CMPA        (120)
/* L1P DMA memory protection fault */
#define    CSL_INTC_EVENTID_L1P_DMPA        (121)
/* L1D CPU memory protection fault */
#define    CSL_INTC_EVENTID_L1D_CMPA        (122)
/* L1D DMA memory protection fault */
#define    CSL_INTC_EVENTID_L1D_DMPA        (123)
/* L2 CPU memory protection fault */
#define    CSL_INTC_EVENTID_L2_CMPA         (124)
/* L2 DMA memory protection fault */
#define    CSL_INTC_EVENTID_L2_DMPA         (125)
/* IDMA CPU memory protection fault */
#define    CSL_INTC_EVENTID_IDMA_CMPA       (126)
/* IDMA Bus error interrupt  */
#define    CSL_INTC_EVENTID_IDMA_BUSERR     (127)

/**** CACHE RELATED DEFINES  *********/
#define     CSL_CACHE_LINE_LEN              (128)

/**** EDMA RELATED DEFINES  *********/

/**************************************************************************\
*  Parameterizable Configuration:- These are fed directly from the RTL
*  parameters for the given SOC
\**************************************************************************/
#define CSL_EDMA3_NUM_DMACH             64
#define CSL_EDMA3_NUM_QDMACH            8
#define CSL_EDMA3_NUM_PARAMSETS         128
#define CSL_EDMA3_NUM_EVQUE             2
#define CSL_EDMA3_CHMAPEXIST            0
#define CSL_EDMA3_NUM_REGIONS           4
#define CSL_EDMA3_MEMPROTECT            0

/**************************************************************************\
* Channel Instance count
\**************************************************************************/
#define CSL_EDMA3_CHA_CNT              72

/* EDMA channel synchronization events */

/** EDMA3 event 0 not used  */
/** EDMA3 event 1 not used  */
/** McBSP0 transmit event */
#define CSL_EDMA3_CHA_XEVT0         2
/** McBSP0 receive event  */
#define CSL_EDMA3_CHA_REVT0         3
/** McBSP1 transmit event */
#define CSL_EDMA3_CHA_XEVT1         4
/** McBSP1 receive event  */
#define CSL_EDMA3_CHA_REVT1         5
/** VPSS histogram event */
#define CSL_EDMA3_CHA_HISTEVT       6
/** VPSS H3A event */
#define CSL_EDMA3_CHA_H3AEVT        7
/** VPSS PRVU event */
#define CSL_EDMA3_CHA_PRVUEVT       8
/** VPSS RSZ event */
#define CSL_EDMA3_CHA_RSZEVT        9
/** McASP0 transmit event (even) */
#define CSL_EDMA3_CHA_AXEVTE0       10
/** McASP0 transmit event (odd)*/
#define CSL_EDMA3_CHA_AXEVTO0       11
/** McASP0 transmit event */
#define CSL_EDMA3_CHA_AXEVT0        12
/** McASP0 receive event (even)  */
#define CSL_EDMA3_CHA_AREVTE0       13
/** McASP0 receive event (0dd) */
#define CSL_EDMA3_CHA_AREVTO0       14
/** McASP0 receive event  */
#define CSL_EDMA3_CHA_AREVT0        15
/** McASP1 transmit event (even) */
#define CSL_EDMA3_CHA_AXEVTE1       16
/** McASP1 transmit event (odd)*/
#define CSL_EDMA3_CHA_AXEVTO1       17
/** McASP1 transmit event */
#define CSL_EDMA3_CHA_AXEVT1        18
/** McASP1 receive event (even)  */
#define CSL_EDMA3_CHA_AREVTE1       19
/** McASP1 receive event (0dd) */
#define CSL_EDMA3_CHA_AREVTO1       20
/** McASP1 receive event  */
#define CSL_EDMA3_CHA_AREVT1        21
/** UART0 receive event */
#define CSL_EDMA3_CHA_URXEVT0       22
/** UART0 transmit event */
#define CSL_EDMA3_CHA_UTXEVT0       23
/** UART1 receive event */
#define CSL_EDMA3_CHA_URXEVT1       24
/** UART1 transmit event */
#define CSL_EDMA3_CHA_UTXEVT1       25
/** EDMA3 event 26 not used */
/** EDMA3 event 27 not used */
/** I2C receive event  */
#define CSL_EDMA3_CHA_ICREVT        28
/** I2C transmit event */
#define CSL_EDMA3_CHA_ICXEVT        29
/** EDMA3 event 30 not used */
/** EDMA3 event 31 not used */
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT0        32
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT1        33
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT2        34
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT3        35
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT4        36
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT5        37
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT6        38
/** GPIO event */
#define CSL_EDMA3_CHA_GPINT7        39
/** GPIO event */
#define CSL_EDMA3_CHA_GPBNKINT0     40
/** GPIO event */
#define CSL_EDMA3_CHA_GPBNKINT1     41
/** GPIO event */
#define CSL_EDMA3_CHA_GPBNKINT2     42
/** GPIO event */
#define CSL_EDMA3_CHA_GPBNKINT3     43
/** GPIO event */
#define CSL_EDMA3_CHA_GPBNKINT4     44
/** GPIO event */
#define CSL_EDMA3_CHA_GPBNKINT5     45
/** GPIO event */
#define CSL_EDMA3_CHA_GPBNKINT6     46
/** EDMA3 event 47 not used */
/** Timer0 Low event  */
#define CSL_EDMA3_CHA_TEVTLO0       48
/** Timer0 high event */
#define CSL_EDMA3_CHA_TEVTHI0       49
/** Timer1 Low event  */
#define CSL_EDMA3_CHA_TEVTLO1       50
/** Timer1 high event */
#define CSL_EDMA3_CHA_TEVTHI1       51
/** PWM event */
#define CSL_EDMA3_CHA_PWM0          52
/** PWM event */
#define CSL_EDMA3_CHA_PWM1          53
/** EDMA3 event 54 to 63 not used */

/* QDMA channels */
#define CSL_EDMA3_QCHA_0            64   /* QDMA Channel 0*/
#define CSL_EDMA3_QCHA_1            65   /* QDMA Channel 1*/
#define CSL_EDMA3_QCHA_2            66   /* QDMA Channel 2*/
#define CSL_EDMA3_QCHA_3            67   /* QDMA Channel 3*/
#define CSL_EDMA3_QCHA_4            68   /* QDMA Channel 4*/
#define CSL_EDMA3_QCHA_5            69   /* QDMA Channel 5*/
#define CSL_EDMA3_QCHA_6            70   /* QDMA Channel 6*/
#define CSL_EDMA3_QCHA_7            71   /* QDMA Channel 7*/


/* Enumerations for EDMA Event Queues */
typedef enum {
    CSL_EDMA3_QUE_0 = 0, /* Queue 0 */
    CSL_EDMA3_QUE_1 = 1  /* Queue 1 */
} CSL_Edma3Que;

/* Enumerations for EDMA Transfer Controllers
 *
 * There are 3 Transfer Controllers. Typically a one to one mapping exists
 * between Event Queues and Transfer Controllers.
 *
 */
typedef enum {
    CSL_EDMA3_TC_0 = 0, /* TC 0 */
    CSL_EDMA3_TC_1 = 1, /* TC 1 */
    CSL_EDMA3_TC_2 = 2  /* TC 2 */
} CSL_Edma3Tc;

#define CSL_EDMA3_REGION_GLOBAL  -1
#define CSL_EDMA3_REGION_0        0
#define CSL_EDMA3_REGION_1        1
#define CSL_EDMA3_REGION_2        2
#define CSL_EDMA3_REGION_3        3


/**
 * @brief Logical DMA Channels assigned to different Hardware Events.
 * They should be used while requesting a specific DMA channel.
 */


/** Channel assigned to McBSP0 Tx Event */
#define EDMA3_DRV_HW_CHANNEL_MCBSP0_TX                          (2)
/** Channel assigned to McBSP0 Rx Event */
#define EDMA3_DRV_HW_CHANNEL_MCBSP0_RX                          (3)
/** Channel assigned to McBSP1 Tx Event */
#define EDMA3_DRV_HW_CHANNEL_MCBSP1_TX                          (4)
/** Channel assigned to McBSP1 Rx Event */
#define EDMA3_DRV_HW_CHANNEL_MCBSP1_RX                          (5)
/** Channel assigned to Video Port Subsystem Histogram Event */
#define EDMA3_DRV_HW_CHANNEL_VPSS_HIST                          (6)
/** Channel assigned to Video Port Subsystem H3A Event */
#define EDMA3_DRV_HW_CHANNEL_VPSS_H3A                           (7)
/** Channel assigned to Video Port Subsystem Preview Event */
#define EDMA3_DRV_HW_CHANNEL_VPSS_PRVU                          (8)
/** Channel assigned to Video Port Subsystem Resizer Event */
#define EDMA3_DRV_HW_CHANNEL_VPSS_RSZ                           (9)
/** Channel assigned to McASP0 AXEVTE0 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP0_AXEVTE0                     (10)
/** Channel assigned to McASP0 AXEVTO0 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP0_AXEVTO0                     (11)
/** Channel assigned to McASP0 AXEVT0 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP0_TX                          (12)
/** Channel assigned to McASP0 AREVTE0 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP0_AREVTE0                     (13)
/** Channel assigned to McASP0 AREVTO0 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP0_AREVTO0                     (14)
/** Channel assigned to McASP0 AREVT0 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP0_RX                          (15)
/** Channel assigned to McASP1 AXEVTE1 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP1_AXEVTE1                     (16)
/** Channel assigned to McASP1 AXEVTO1 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP1_AXEVTO1                     (17)
/** Channel assigned to McASP1 AXEVT1 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP1_TX                          (18)
/** Channel assigned to McASP1 AREVTE1 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP1_AREVTE1                     (19)
/** Channel assigned to McASP1 AREVTO1 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP1_AREVTO1                     (20)
/** Channel assigned to McASP1 AREVT1 Event */
#define EDMA3_DRV_HW_CHANNEL_MCASP1_RX                          (21)
/** Channel assigned to UART0 Rx */
#define EDMA3_DRV_HW_CHANNEL_UART0_URXEVT0                      (22)
/** Channel assigned to UART0 Tx */
#define EDMA3_DRV_HW_CHANNEL_UART0_UTXEVT0                      (23)
/** Channel assigned to UART1 Rx */
#define EDMA3_DRV_HW_CHANNEL_UART1_URXEVT1                      (24)
/** Channel assigned to UART1 Tx */
#define EDMA3_DRV_HW_CHANNEL_UART1_UTXEVT1                      (25)
/** Channel assigned to I2C Rx */
#define EDMA3_DRV_HW_CHANNEL_I2C_ICREVT                         (28)
/** Channel assigned to I2C Tx */
#define EDMA3_DRV_HW_CHANNEL_I2C_ICXEVT                         (29)
/** Channel assigned to GPIO0 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT0                        (32)
/** Channel assigned to GPIO1 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT1                        (33)
/** Channel assigned to GPIO2 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT2                        (34)
/** Channel assigned to GPIO3 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT3                        (35)
/** Channel assigned to GPIO4 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT4                        (36)
/** Channel assigned to GPIO5 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT5                        (37)
/** Channel assigned to GPIO6 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT6                        (38)
/** Channel assigned to GPIO7 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPINT7                        (39)
/** Channel assigned to GPIO Bank0 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPBNKINT0                     (40)
/** Channel assigned to GPIO Bank1 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPBNKINT1                     (41)
/** Channel assigned to GPIO Bank2 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPBNKINT2                     (42)
/** Channel assigned to GPIO Bank3 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPBNKINT3                     (43)
/** Channel assigned to GPIO Bank4 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPBNKINT4                     (44)
/** Channel assigned to GPIO Bank5 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPBNKINT5                     (45)
/** Channel assigned to GPIO Bank6 Event */
#define EDMA3_DRV_HW_CHANNEL_GPIO_GPBNKINT6                     (46)
/** Channel assigned to Timer0 TEVTL0 */
#define EDMA3_DRV_HW_CHANNEL_TIMER0_TEVTL0                      (48)
/** Channel assigned to Timer0 TEVTH0 */
#define EDMA3_DRV_HW_CHANNEL_TIMER0_TEVTH0                      (49)
/** Channel assigned to Timer1 TEVTL1 */
#define EDMA3_DRV_HW_CHANNEL_TIMER1_TEVTL1                      (50)
/** Channel assigned to Timer1 TEVTH1 */
#define EDMA3_DRV_HW_CHANNEL_TIMER1_TEVTH1                      (51)
/** Channel assigned to PWM0 */
#define EDMA3_DRV_HW_CHANNEL_PWM0                               (52)
/** Channel assigned to PWM1 */
#define EDMA3_DRV_HW_CHANNEL_PWM1                               (53)
/** Channel assigned to PWM2 */
#define EDMA3_DRV_HW_CHANNEL_PWM2                               (54)

/**
 * @brief Represents the HWI Interrupt number to event combiner
 * mapping
 */

/** IRQ assignment for EVT Combiner 01 */
#define        HWI_EVT01_CMB_IRQ                                    (0x0080u)
/** IRQ assignment for EVT Combiner 02 */
#define        HWI_EVT02_CMB_IRQ                                    (0x0100u)
/** IRQ assignment for EVT Combiner 03 */
#define        HWI_EVT03_CMB_IRQ                                    (0x0200u)
/** IRQ assignment for EVT Combiner 04 */
#define        HWI_EVT04_CMB_IRQ                                    (0x0400u)

#endif  /* _SOC_H_ */

