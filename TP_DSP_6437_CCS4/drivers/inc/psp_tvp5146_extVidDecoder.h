/******************************************************************************
**+-------------------------------------------------------------------------+**
**|                            ****                                         |**
**|                            ****                                         |**
**|                            ******o***                                   |**
**|                      ********_///_****                                  |**
**|                      ***** /_//_/ ****                                  |**
**|                       ** ** (__/ ****                                   |**
**|                           *********                                     |**
**|                            ****                                         |**
**|                            ***                                          |**
**|                                                                         |**
**|         Copyright (c) 2006-2010 Texas Instruments Incorporated          |**
**|                        ALL RIGHTS RESERVED                              |**
**|                                                                         |**
**| Permission is hereby granted to licensees of Texas Instruments          |**
**| Incorporated (TI) products to use this computer program for the sole    |**
**| purpose of implementing a licensee product based on TI products.        |**
**| No other rights to reproduce, use, or disseminate this computer         |**
**| program, whether in part or in whole, are granted.                      |**
**|                                                                         |**
**| TI makes no representation or warranties with respect to the            |**
**| performance of this computer program, and specifically disclaims        |**
**| any responsibility for any damages, special or consequential,           |**
**| connected with the use of this program.                                 |**
**|                                                                         |**
**+-------------------------------------------------------------------------+**
******************************************************************************/

/**
 *  \file   psp_tvp5146_extVidDecoder.h
 *
 *  \brief  TVP-5146 Video Decoder related parameters
 *
 *  This file contains the interfaces, data types and symbolic definitions
 *  that are required for the TVP-5146 video decoder driver.
 *
 *  (C) Copyright 2010, Texas Instruments, Inc
 *
 *  \author     Maulik Desai
 *
 *  \version    0.1     Created
 */
#ifndef _TVP5146_EXTVIDEO_DECODER_H
#define _TVP5146_EXTVIDEO_DECODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "psp_vpss_extvidDecoder.h"

/**< I2C TVP device slave address  */
#define I2C_TVP_SLAVE_ADDR          (0x5D)

/******************************************************************************
                            Register Overlay Macros
******************************************************************************/
/**< Input select register */
#define INPUT_SELECT_REG                            (0x00)
/**< Gain control register */
#define AFE_GAIN_CONTROL_REG                        (0x01)
/**< video standard register */
#define VIDEO_STANDARD_REG                          (0x02)
/**< Vpss operation mode register */
#define OPERATION_MODE_REG                          (0x03)
/**< Vpss Auto switch mask register */
#define AUTOSWITCH_MASK_REG                         (0x04)
/**< video colour killer register */
#define COLOR_KILLER_REG                            (0x05)
/**< Luminance processing control 1 register */
#define LUMINANCE_PROCESSING_CONTROL_1_REG          (0x06)
/**< Luminance processing control 2 register */
#define LUMINANCE_PROCESSING_CONTROL_2_REG          (0x07)
/**< Luminance processing control 3 register */
#define LUMINANCE_PROCESSING_CONTROL_3_REG          (0x08)
/**< Luminance bightness register */
#define LUMINANCE_BRIGHTNESS_REG                    (0x09)
/**< Luminance contrast register */
#define LUMINANCE_CONTRAST_REG                      (0x0A)
/**< Chrominance saturation register */
#define CHROMINANCE_SATURATION_REG                  (0x0B)
/**< Chrominance hue register */
#define CHROMINANCE_HUE_REG                         (0x0C)
/**< Chrominance processing control 1 register */
#define CHROMINANCE_PROCESSING_CONTROL_1_REG        (0x0D)
/**< Chrominance processing control 2 register */
#define CHROMINANCE_PROCESSING_CONTROL_2_REG        (0x0E)
/**< Reserved 1 register */
#define RESERVED_1_REG                              (0x0F)
/**< Component pr saturation register */
#define COMPONENT_Pr_SATURATION_REG                 (0x10)
/**< Component Y contrast  register */
#define COMPONENT_Y_CONTRAST_REG                    (0x11)
/**< Component Pb saturation register */
#define COMPONENT_Pb_SATURATION_REG                 (0x12)
/**< Reserved 2 register */
#define RESERVED_2_REG                              (0x13)
/**< Component Y brightness register */
#define COMPONENT_Y_BRIGHTNESS_REG                  (0x14)
/**< Reserved 3 register */
#define RESERVED_3_REG                              (0x15)
/**< Video start pixel LSB register */
#define AVID_START_PIXEL_LSB_REG                    (0x16)
/**< Video start pixel MSB register */
#define AVID_START_PIXEL_MSB_REG                    (0x17)
/**< Video stop pixel LSB register */
#define AVID_STOP_PIXEL_LSB_REG                     (0x18)
/**< Video stop pixel MSB register */
#define AVID_STOP_PIXEL_MSB_REG                     (0x19)
/**< Horizonatl sync start pixel LSB register */
#define HSYNC_START_PIXEL_LSB_REG                   (0x1A)
/**< Horizonatl sync start pixel MSB register */
#define HSYNC_START_PIXEL_MSB_REG                   (0x1B)
/**< Horizonatl sync stop pixel LSB register */
#define HSYNC_STOP_PIXEL_LSB_REG                    (0x1C)
/**< Horizonatl sync stop pixel MSB register */
#define HSYNC_STOP_PIXEL_MSB_REG                    (0x1D)
/**< Vertical sync start pixel LSB register */
#define VSYNC_START_PIXEL_LSB_REG                   (0x1E)
/**< Vertical sync start pixel MSB register */
#define VSYNC_START_PIXEL_MSB_REG                   (0x1F)
/**< Vertical sync stop pixel LSB register */
#define VSYNC_STOP_PIXEL_LSB_REG                    (0x20)
/**< Vertical sync stop pixel MSB register */
#define VSYNC_STOP_PIXEL_MSB_REG                    (0x21)
/**< Vertical blinking start pixel LSB register */
#define VBLK_START_PIXEL_LSB_REG                    (0x22)
/**< Vertical blinking start pixel MSB register */
#define VBLK_START_PIXEL_MSB_REG                    (0x23)
/**< Vertical blinking stop pixel LSB register */
#define VBLK_STOP_PIXEL_LSB_REG                     (0x24)
/**< Vertical blinking stop pixel MSB register */
#define VBLK_STOP_PIXEL_MSB_REG                     (0x25)
/**< Reserved 4 register */
#define RESERVED_4_REG                              (0x26)
/**< Reserved 5 register */
#define RESERVED_5_REG                              (0x27)
/**< Fast switch control register */
#define FAST_SWITCH_CONTROL_REG                     (0x28)
/**< Reserved 6 register */
#define RESERVED_6_REG                              (0x29)
/**< Fast switch scart delay register */
#define FAST_SWITCH_SCART_DELAY_REG                 (0x2A)
/**< Reserved 7 register */
#define RESERVED_7_REG                              (0x2B)
/**< scart delay register */
#define SCART_DELAY_REG                             (0x2C)
/**< CTI delay register */
#define CTI_DELAY_REG                               (0x2D)
/**< CTI contol register */
#define CTI_CONTROL_REG                             (0x2E)
/**< Reserved 8 register */
#define RESERVED_8_REG                              (0x2F)
/**< Reserved 9 register */
#define RESERVED_9_REG                              (0x30)
/**< RTC  register */
#define RTC_REG                                     (0x31)
/**< Sync control register */
#define SYNC_CONTROL_REG                            (0x32)
/**< output formatting 1 register */
#define OUTPUT_FORMATTER_1_REG                      (0x33)
/**< output formatting 2 register */
#define OUTPUT_FORMATTER_2_REG                      (0x34)
/**< output formatting 3 register */
#define OUTPUT_FORMATTER_3_REG                      (0x35)
/**< output formatting 4 register */
#define OUTPUT_FORMATTER_4_REG                      (0x36)
/**< output formatting 5 register */
#define OUTPUT_FORMATTER_5_REG                      (0x37)
/**< output formatting 6 register */
#define OUTPUT_FORMATTER_6_REG                      (0x38)
/**< Clear lost lock detect register */
#define CLEAR_LOST_LOCK_DETECT_REG                  (0x39)
/**< status 1 register */
#define STATUS_1_REG                                (0x3A)
/**< status 2 register */
#define STATUS_2_REG                                (0x3B)
/**< Automatic gain contol status LSB register */
#define AGC_GAIN_STATUS_LSB_REG                     (0x3C)
/**< Automatic gain contol status MSB register */
#define AGC_GAIN_STATUS_MSB_REG                     (0x3D)
/**< Reserved 10 register */
#define RESERVED_10_REG                             (0x3E)
/**< Video standard status register */
#define VIDEO_STANDARD_STATUS_REG                   (0x3F)
/**< General purpose input 1 register */
#define GPIO_INPUT_1_REG                            (0x40)
/**< General purpose input 2 register */
#define GPIO_INPUT_2_REG                            (0x41)
/**< Vertical line count LSB register */
#define VERTICAL_LINE_COUNT_LSB_REG                 (0x42)
/**< Vertical line count MSB register */
#define VERTICAL_LINE_COUNT_MSB_REG                 (0x43)
/**< Reserved 11 register */
#define RESERVED_11_REG                             (0x44)
/**< Reserved 12 register */
#define RESERVED_12_REG                             (0x45)
/**< Front-End coarse gain channel 1 register */
#define AFE_COARSE_GAIN_CH1_REG                     (0x46)
/**< Front-End coarse gain channel 2 register */
#define AFE_COARSE_GAIN_CH2_REG                     (0x47)
/**< Front-End coarse gain channel 3 register */
#define AFE_COARSE_GAIN_CH3_REG                     (0x48)
/**< Front-End coarse gain channel 4register */
#define AFE_COARSE_GAIN_CH4_REG                     (0x49)
/**< Front-End fine gain Pb_B LSB register */
#define AFE_FINE_GAIN_Pb_B_LSB_REG                  (0x4A)
/**< Front-End fine gain Pb_B MSB register */
#define AFE_FINE_GAIN_Pb_B_MSB_REG                  (0x4B)
/**< Front-End fine gain Y_G LSB register */
#define AFE_FINE_GAIN_Y_G_LSB_REG                   (0x4C)
/**< Front-End fine gain Y_G MSB register */
#define AFE_FINE_GAIN_Y_G_MSB_REG                   (0x4D)
/**< Front-End fine gain Pr_R LSB register */
#define AFE_FINE_GAIN_Pr_R_LSB_REG                  (0x4E)
/**< Front-End fine gain Pr_R MSB register */
#define AFE_FINE_GAIN_Pr_R_MSB_REG                  (0x4F)
/**< Front-End fine gain CVBS_LUMA LSB register */
#define AFE_FINE_GAIN_CVBS_LUMA_LSB_REG             (0x50)
/**< Front-End fine gain CVBS_LUMA MSB register */
#define AFE_FINE_GAIN_CVBS_LUMA_MSB_REG             (0x51)
/**< Reserved 13 register */
#define RESERVED_13_REG                             (0x52)
/**< Reserved 14 register */
#define RESERVED_14_REG                             (0x53)
/**< Reserved 15 register */
#define RESERVED_15_REG                             (0x54)
/**< Reserved 16 register */
#define RESERVED_16_REG                             (0x55)
/**< Reserved 17 register */
#define RESERVED_17_REG                             (0x56)
/**< Reserved 18 register */
#define RESERVED_18_REG                             (0x57)
/**< Reserved 19 register */
#define RESERVED_19_REG                             (0x58)
/**< Reserved 20 register */
#define RESERVED_20_REG                             (0x59)
/**< Reserved 21 register */
#define RESERVED_21_REG                             (0x5A)
/**< Reserved 22 register */
#define RESERVED_22_REG                             (0x5B)
/**< Reserved 23 register */
#define RESERVED_23_REG                             (0x5C)
/**< Reserved 24 register */
#define RESERVED_24_REG                             (0x5D)
/**< Reserved 25 register */
#define RESERVED_25_REG                             (0x5E)
/**< Reserved 26 register */
#define RESERVED_26_REG                             (0x5F)
/**< Reserved 27 register */
#define RESERVED_27_REG                             (0x60)
/**< Reserved 28 register */
#define RESERVED_28_REG                             (0x61)
/**< Reserved 29 register */
#define RESERVED_29_REG                             (0x62)
/**< Reserved 30 register */
#define RESERVED_30_REG                             (0x63)
/**< Reserved 31 register */
#define RESERVED_31_REG                             (0x64)
/**< Reserved 32 register */
#define RESERVED_32_REG                             (0x65)
/**< Reserved 33 register */
#define RESERVED_33_REG                             (0x66)
/**< Reserved 34 register */
#define RESERVED_34_REG                             (0x67)
/**< Reserved 35 register */
#define RESERVED_35_REG                             (0x68)
/**< Reserved 36 register */
#define RESERVED_36_REG                             (0x69)
/**< Reserved 37 register */
#define RESERVED_37_REG                             (0x6A)
/**< Reserved 38 register */
#define RESERVED_38_REG                             (0x6B)
/**< Reserved 39 register */
#define RESERVED_39_REG                             (0x6C)
/**< Reserved 40 register */
#define RESERVED_40_REG                             (0x6D)
/**< Reserved 41 register */
#define RESERVED_41_REG                             (0x6E)
/**< Reserved 42 register */
#define RESERVED_42_REG                             (0x6F)
/**< Rom version register */
#define ROM_VERSION_REG                             (0x70)
/**< Reserved 43 register */
#define RESERVED_43_REG                             (0x71)
/**< Reserved 44 register */
#define RESERVED_44_REG                             (0x72)
/**< Reserved 45 register */
#define RESERVED_45_REG                             (0x73)
/**< AGC white peak processing register */
#define AGC_WHITE_PEAK_PROCESSING_REG               (0x74)
/**< Reserved 46 register */
#define RESERVED_46_REG                             (0x75)
/**< Reserved 47 register */
#define RESERVED_47_REG                             (0x76)
/**< Reserved 48 register */
#define RESERVED_48_REG                             (0x77)
/**< AGC incremet speed register */
#define AGC_INCREMENT_SPEED_REG                     (0x78)
/**< AGC incremet delay register */
#define AGC_INCREMENT_DELAY_REG                     (0x79)
/**< Reserved 49 register */
#define RESERVED_49_REG                             (0x7A)
/**< Reserved 50 register */
#define RESERVED_50_REG                             (0x7B)
/**< Reserved 51 register */
#define RESERVED_51_REG                             (0x7C)
/**< Reserved 52 register */
#define RESERVED_52_REG                             (0x7D)
/**< Reserved 53 register */
#define RESERVED_53_REG                             (0x7E)
/**< Reserved 54 register */
#define RESERVED_54_REG                             (0x7F)
/**< Chip id MSB register */
#define CHIP_ID_MSB_REG                             (0x80)
/**< Chip id LSB register */
#define CHIP_ID_LSB_REG                             (0x81)
/**< Reserved 55 register */
#define RESERVED_55_REG                             (0x82)
/**< Reserved 101 register */
#define RESERVED_101_REG                            (0xB0)
/**< VDP filter 1 mask 1 register */
#define VDP_TTX_FILTER_1_MASK_1_REG                 (0xB1)
/**< VDP filter 1 mask 2 register */
#define VDP_TTX_FILTER_1_MASK_2_REG                 (0xB2)
/**< VDP filter 1 mask 3 register */
#define VDP_TTX_FILTER_1_MASK_3_REG                 (0xB3)
/**< VDP filter 1 mask 4 register */
#define VDP_TTX_FILTER_1_MASK_4_REG                 (0xB4)
/**< VDP filter 1 mask 1 register */
#define VDP_TTX_FILTER_5_MASK_5_REG                 (0xB5)
/**< VDP filter 2 mask 1 register */
#define VDP_TTX_FILTER_2_MASK_1_REG                 (0xB6)
/**< VDP filter 2 mask 2 register */
#define VDP_TTX_FILTER_2_MASK_2_REG                 (0xB7)
/**< VDP filter 2 mask 3 register */
#define VDP_TTX_FILTER_2_MASK_3_REG                 (0xB8)
/**< VDP filter 2 mask 4 register */
#define VDP_TTX_FILTER_2_MASK_4_REG                 (0xB9)
/**< VDP filter 2 mask 5 register */
#define VDP_TTX_FILTER_2_MASK_5_REG                 (0xBA)
/**< VDP filter control register */
#define VDP_TTX_FILTER_CONTROL_REG                  (0xBB)
/**< VDP FIFO word count register */
#define VDP_FIFO_WORD_COUNT_REG                     (0xBC)
/**< VDP filter FIFO interrupt threshold register */
#define VDP_FIFO_INTERRUPT_THRESHOLD_REG            (0xBD)
/**< Reserved 102 register */
#define RESERVED_102_REG                            (0xBE)
/**< VDP_FIFO_RESET register */
#define VDP_FIFO_RESET_REG                          (0xBF)
/**< VDP FIFO output control register */
#define VDP_FIFO_OUTPUT_CONTROL_REG                 (0xC0)
/**< VDP Line number interrupt register */
#define VDP_LINE_NUMBER_INTERRUPT_REG               (0xC1)
/**< VDP pixel alignment LSB register */
#define VDP_PIXEL_ALIGNMENT_LSB_REG                 (0xC2)
/**< VDP pixel alignment MSB register */
#define VDP_PIXEL_ALIGNMENT_MSB_REG                 (0xC3)
/**< Reserved 103 register */
#define RESERVED_103_REG                            (0xC4)
/**< Reserved 120 register */
#define RESERVED_120_REG                            (0xD5)
/**< VDP line start register */
#define VDP_LINE_START_REG                          (0xD6)
/**< VDP line stop register */
#define VDP_LINE_STOP_REG                           (0xD7)
/**< VDP global line mode register */
#define VDP_GLOBAL_LINE_MODE_REG                    (0xD8)
/**< VDP full field enable  register */
#define VDP_FULL_FIELD_ENABLE_REG                   (0xD9)
/**< VDP full field mode register */
#define VDP_FULL_FIELD_MODE_REG                     (0xDA)
/**< Reserved 121 register */
#define RESERVED_121_REG                            (0xDB)
/**< Reserved 122 register */
#define RESERVED_122_REG                            (0xDC)
/**< Reserved 123 register */
#define RESERVED_123REG                             (0xDD)
/**< Reserved 124 register */
#define RESERVED_124_REG                            (0xDE)
/**< Reserved 125 register */
#define RESERVED_125_REG                            (0xDF)
/**< Vbus data Access no vbus address inc register */
#define VBUS_DATA_ACCESS_NO_VBUS_ADDRESS_INC_REG    (0xE0)
/**< Vbus data Access vbus address inc register */
#define VBUS_DATA_ACCESS_VBUS_ADDRESS_INC_REG       (0xE1)
/**< FIFO read data register */
#define FIFO_READ_DATA_REG                          (0xE2)
/**< Reserved 126 register */
#define RESERVED_126_REG                            (0xE3)
/**< Reserved 127 register */
#define RESERVED_127_REG                            (0xE4)
/**< Reserved 128 register */
#define RESERVED_128_REG                            (0xE5)
/**< Reserved 129 register */
#define RESERVED_129_REG                            (0xE6)
/**< Reserved 130 register */
#define RESERVED_130_REG                            (0xE7)
/**< Vbus adress access LSB register */
#define VBUS_ADDRESS_ACCESS_LSB_REG                 (0xE8)
/**< Vbus adress access MSB8 register */
#define VBUS_ADDRESS_ACCESS_MSB8_REG                (0xE9)
/**< Vbus adress access MSB16 register */
#define VBUS_ADDRESS_ACCESS_MSB16_REG               (0xEA)
/**< Reserved 120 register */
#define RESERVED_131_REG                            (0xEB)
/**< Reserved 120 register */
#define RESERVED_132_REG                            (0xEC)
/**< Reserved 120 register */
#define RESERVED_133_REG                            (0xED)
/**< Reserved 120 register */
#define RESERVED_134_REG                            (0xEE)
/**< Reserved 120 register */
#define RESERVED_135_REG                            (0xEF)
/**< Interrupt raw status 0 register */
#define INTERRUPT_RAW_STATUS_0_REG                  (0xF0)
/**< Interrupt raw status 1 register */
#define INTERRUPT_RAW_STATUS_1_REG                  (0xF1)
/**< INTERRUPT STATUS 0 register */
#define INTERRUPT_STATUS_0_REG                      (0xF2)
/**< Interrupt status 1 register */
#define INTERRUPT_STATUS_1_REG                      (0xF3)
/**< Interrupt mask 0 register */
#define INTERRUPT_MASK_0_REG                        (0xF4)
/**< Interrupt mask 1 register */
#define INTERRUPT_MASK_1_REG                        (0xF5)
/**< Interrupt clear 0 register */
#define INTERRUPT_CLEAR_0_REG                       (0xF6)
/**< Interrupt clear 1 register */
#define INTERRUPT_CLEAR_1_REG                       (0xF7)
/**< Reserved 136 register */
#define RESERVED_136_REG                            (0xF8)
/**< Reserved 137 register */
#define RESERVED_137_REG                            (0xF9)
/**< Reserved 138 register */
#define RESERVED_138_REG                            (0xFA)
/**< Reserved 139 register */
#define RESERVED_139_REG                            (0xFB)
/**< Reserved 140 register */
#define RESERVED_140_REG                            (0xFC)
/**< Reserved 141 register */
#define RESERVED_141_REG                            (0xFD)
/**< Reserved 142 register */
#define RESERVED_142_REG                            (0xFE)
/**< Reserved 143 register */
#define RESERVED_143_REG                            (0xFF)

/**< Enable the sync 656    */
#define ENABLE_SYNC_656                             (0x01)
/**< Disable the sync 656   */
#define DISABLE_SYNC_656                            (0x00)

/*-----------------------------------------------------------------------------
                    TVP5146 Video Decoder Format
-----------------------------------------------------------------------------*/
typedef enum _TVP5146_Format
{
    PSP_VPFE_TVP5146_FORMAT_COMPOSITE = 0,
    PSP_VPFE_TVP5146_FORMAT_SVIDEO,
    PSP_VPFE_TVP5146_FORMAT_COMPONENT
} PSP_VPFE_TVP5146_Format;

/*-----------------------------------------------------------------------------
                    TVP5146 Video Decoder Mode
-----------------------------------------------------------------------------*/
typedef enum _TVP5146_Mode
{
    PSP_VPFE_TVP5146_MODE_INV            = -1,
    PSP_VPFE_TVP5146_MODE_AUTO           = 0x0,  /* autoswitch mode (default) */
    PSP_VPFE_TVP5146_MODE_NTSC           = 0x1,  /* (M, J) NTSC      525-line */
    PSP_VPFE_TVP5146_MODE_PAL            = 0x2,  /* (B, D, G, H, I, N) PAL    */
    PSP_VPFE_TVP5146_MODE_PAL_M          = 0x3,  /* (M) PAL          525-line */
    PSP_VPFE_TVP5146_MODE_PAL_CN         = 0x4,  /* (Combination-N) PAL       */
    PSP_VPFE_TVP5146_MODE_NTSC_443       = 0x5,  /* NTSC 4.43        525-line */
    PSP_VPFE_TVP5146_MODE_SECAM          = 0x6,  /* SECAM                     */
    PSP_VPFE_TVP5146_MODE_PAL_60         = 0x7,  /* PAL 60          525-line  */

    PSP_VPFE_TVP5146_MODE_AUTO_SQP       = 0x8,  /* autoswitch mode (default) */
    PSP_VPFE_TVP5146_MODE_NTSC_SQP       = 0x9,  /* (M, J) NTSC      525-line */
    PSP_VPFE_TVP5146_MODE_PAL_SQP        = 0xA,  /* (B, D, G, H, I, N) PAL    */
    PSP_VPFE_TVP5146_MODE_PAL_M_SQP      = 0xB,  /* (M) PAL          525-line */
    PSP_VPFE_TVP5146_MODE_PAL_CN_SQP     = 0xC,  /* (Combination-N) PAL       */
    PSP_VPFE_TVP5146_MODE_NTSC_443_SQP   = 0xD,  /* NTSC 4.43        525-line */
    PSP_VPFE_TVP5146_MODE_SECAM_SQP      = 0xE,  /* SECAM                     */
    PSP_VPFE_TVP5146_MODE_PAL_60_SQP     = 0xF   /* PAL 60          525-line  */
} PSP_VPFE_TVP5146_Mode;


/******************************************************************************
                                Data-Structures
******************************************************************************/
/*-----------------------------------------------------------------------------
                    TVP5146 Video Decoder Configuration
-----------------------------------------------------------------------------*/
typedef struct _PSP_VPFE_TVP5146_ConfigParams
{
    Bool                enable656Sync;
    PSP_VPFE_TVP5146_Format     format;
    PSP_VPFE_TVP5146_Mode       mode;
} PSP_VPFE_TVP5146_ConfigParams;

/*-----------------------------------------------------------------------------
                    TVP5146 Video Decoder Control Params
-----------------------------------------------------------------------------*/
typedef struct _PSP_VPFE_TVP5146_ControlParams
{
    Bool         autoGain;
    Uint8        brightness;
    Uint8        contrast;
    Uint8        saturation;
    Uint8        hue;
} PSP_VPFE_TVP5146_ControlParams;

/*-----------------------------------------------------------------------------
                    TVP5146 Video Decoder Status Params
-----------------------------------------------------------------------------*/
typedef struct _PSP_VPFE_TVP5146_StatusParams
{
    Uint8        fieldRate;
    Uint8        lostLock;
    Uint8        colSubCarrier_lock;
    Uint8        vLock;
    Uint8        hLock;
} PSP_VPFE_TVP5146_StatusParams;

/*-----------------------------------------------------------------------------
                    TVP5146 Video Decoder Device Object
-----------------------------------------------------------------------------*/
typedef struct _PSP_VPFE_TVP5146_Object
{
    Int                             tvp5146ChipId;
    /**<  chip id  for video decoders          */
    PSP_VPFE_TVP5146_ConfigParams            config;
    /**<  video decoder config params          */
    PSP_VPFE_TVP5146_ControlParams           control;
    /**< video decoder control params          */
    PSP_VPFE_TVP5146_StatusParams            status;
    /**< video decoder status params           */
} PSP_VPFE_TVP5146_Object;

/*-----------------------------------------------------------------------------
                    Functions Defined
-----------------------------------------------------------------------------*/
/**
 *  \brief TVP5146_Open
 *
 *  This Function is used to initialize the TVP5146 chip.It creates TVp5146
 *  handle.It also initializes the I2C Driver.
 *
 *  \return EVD_Handle
 */

EVD_Handle PSP_VPFE_TVP5146_Open();
/**
 *  \brief TVP5146_Close
 *
 *  This Function is used to deinitialize the TVP5146 chip.It deinitialize the
 *  I2C Driver
 *
 *  \param handle           Handle of TVp5146 video decoder
 */

Int PSP_VPFE_TVP5146_Close(EVD_Handle handle);
/**
 *  \brief TVP5146_Control
 *
 *  This Function is to configure and change parameters of TVP5146 chip runtime.
 *
 *  \param  handle          Handle of TVp5146 video decoder
 *  \param  Cmd             Command for TVP5146 video decoder
 *  \param  CmdArg          Commandarg for TVP5146 video decoder
 */
Int PSP_VPFE_TVP5146_Control(EVD_Handle handle,Uint32 Cmd,Ptr CmdArg);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /*_TVP5146_EXTVIDEO_DECODER_H*/

