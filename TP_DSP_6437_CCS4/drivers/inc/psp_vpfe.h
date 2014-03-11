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
 *  \file   psp_vpfe.h
 *
 *  \brief  VPFE interface definition
 *
 *  This file contains the interfaces, data types and symbolic definitions
 *  that are needed by the application to utilize the serivces of the VPFE
 *  device driver.
 *
 *  (C) Copyright 2010, Texas Instruments, Inc
 *
 *  \note       Set tabstop to 4 (:se ts=4) while viewing this file in an
 *              editor
 *  
 *  \author     Maulik Desai
 *
 *  \version    0.1     Created
 */

#ifndef _PSP_VPFE_H
#define _PSP_VPFE_H
/**
 * Header File Inclusion
 */
#include <psp_vpss.h>
#include "psp_vpss_extvidDecoder.h"

/* External Peripheral Command base */
#define VPFE_ExtVD_BASE         (0x800000u)
/* Enable Video Path for H3A,HISTOGRAM and PREVIEWER(on-the-fly) */
#define PSP_VIDEO_PATH_ENABLE

/**
 * Enumerations
 */
/**
 * \brief Enum for Vpfe related IOCTL
 *
 */
typedef enum _PSP_VPFEIoctlCommand
{
    PSP_VPFE_IOCTL_CCDC_VALIDATE_BUFFER = 0,
    PSP_VPFE_IOCTL_CCDC_BLACK_ADJUST    = 1,
    PSP_VPFE_IOCTL_CCDC_FPC                = 2,
    PSP_VPFE_IOCTL_EXTVIDDECODER_CONFIG = 3
} PSP_VPFEIoctlCommand;
/**
 * \brief Enum defines the data flow for different vpfe modes
 *
 */
typedef enum _PSP_VPFE_CCDC_InputMode
{
    PSP_VPFE_CCDC_YCBCR_8 = 0,
    /**< Input is YUV mode from ext encoder */
    PSP_VPFE_CCDC_RAW    = 1
    /**< RAW mode input                                                 */
} PSP_VPFE_CCDC_InputMode;


typedef enum _PSP_VPFE_CCDC_DataFlow
{
    PSP_VPFE_DECODER_CCDC           =   0,
    /**< DataFlow path from Decoder to CCDC */
    PSP_VPFE_SENSOR_CCDC_RAM        =   1,
    /**< DataFlow path from Sensor->CCDC->RAM */
    PSP_VPFE_SENSOR_CCDC_PREVIEWER  =   2
        /**< DataFlow path from Sensor->CCDC->Previewer */
}PSP_VPFE_CCDC_DataFlow;

/**
  * \brief Enum defines bits per pixel
  *
  */
typedef enum _PSP_VPFEBitsPerPixel
{
    PSP_VPFE_BITS16     = 0,
    /**< 16 bits   Note: do not change the value.                       */
    PSP_VPFE_BITS15     = 1,
    /**< 15 bits   Note: do not change the value.                       */
    PSP_VPFE_BITS14     = 2,
    /**< 14 bits   Note: do not change the value.                       */
    PSP_VPFE_BITS13     = 3,
    /**< 13 bits   Note: do not change the value.                       */
    PSP_VPFE_BITS12     = 4,
    /**< 12 bits   Note: do not change the value.                       */
    PSP_VPFE_BITS11     = 5,
    /**< 11 bits   Note: do not change the value.                       */
    PSP_VPFE_BITS10     = 6,
    /**< 10 bits   Note: do not change the value.                       */
    PSP_VPFE_BITS9      = 7,
    /**< 9 bits   Note: do not change the value.                        */
    PSP_VPFE_BITS8      = 8
    /**< 8 bits   Note: do not change the value.                        */
} PSP_VPFEBitsPerPixel;

/**
  * \brief Enum defines packing nature of data
  *
  */
typedef enum _PSP_VPFEPack 
{
    PSP_VPFE_PACK8_16BITS_PIXEL     = 0,
    /**< No pack. Keep it 16 bits Note: do not change the value.        */
    PSP_VPFE_PACK8_8BITS_PIXEL      = 1
    /**< Pack to 8 bits.         Note: do not change the value.         */
}PSP_VPFEPack;

/**
 * \brief Enum defines the data polarity
 *
 */
typedef enum _PSP_VPFE_Datapol
{
    PSP_VPFE_DataPol_Normal             = 0,
    /**< datapolarity : Normal                                          */
    PSP_VPFE_DataPol_OnesComplement     = 1
    /**< datapolarity : Ones complement                                 */
}PSP_VPFE_Datapol;

/**
  * \brief Enum defines the sync polarity
  *
  */
typedef enum _PSP_VPFE_SyncPolarity
{
    PSP_VPFE_SyncPol_Positive           = 0,
    /**< Sync polarity : Positive                                           */
    PSP_VPFE_SyncPol_Negative           = 1
    /**< Sync polarity : Negetive                                           */
}PSP_VPFE_SyncPolarity;

/**
 * \brief Enum defines the sync direction
 *
 */
typedef enum _PSP_VPFE_SyncDirection
{
    PSP_VPFE_SyncDir_Input          = 0,
    /**< Sync Direction : Input                                         */
    PSP_VPFE_SyncDir_Output         = 1
    /**< Sync Direction : Output                                            */
}PSP_VPFE_SyncDirection;

/**
  * \brief Enum Black compensation enable/ Disable
  *
  */
typedef enum _PSP_VPFE_BlkComp
{
    PSP_VPFE_BlkCompEnable          = 0,
    /**< Black compensation enable                                          */
    PSP_VPFE_BlkCompDisable         = 1
    /**< Black compensation Disable                                         */
}PSP_VPFE_BlkComp;

/**
  * \brief Enum Black compensation pixel length
  *
  */
typedef enum _PSP_VPFE_BlkComp_Pixlen
{
    PSP_VPFE_BlkComp1Pixel          = 0,
    /**< Black compensation 1 pixel                                             */
    PSP_VPFE_BlkComp2Pixel          = 1,
    /**< Black compensation 2 pixels                                            */
    PSP_VPFE_BlkComp4Pixel          = 2,
    /**< Black compensation 4 pixels                                            */
    PSP_VPFE_BlkComp8Pixel          = 3,
    /**< Black compensation 8 pixels                                            */
    PSP_VPFE_BlkComp16Pixel         = 4
    /**< Black compensation 16 pixels                                           */
}PSP_VPFE_BlkComp_Pixlen;

typedef enum _PSP_VPFE_ALaw
{
    PSP_VPFE_ALaw_Disable = 0,
    /**< Alaw  to pak data into 8bits Disable                               */
    PSP_VPFE_ALaw_Enable = 1
    /**< Alaw  to pak data into 8bits Enable                                */
}PSP_VPFE_ALaw;

typedef enum _PSP_VPFE_ALaw_Width
{
    PSP_VPFE_ALaw_bits15_6  = 0,
    /**< ALAW Width - from bits 15 to bits 6                                */
    PSP_VPFE_ALaw_bits14_5  = 1,
    /**< ALAW Width - from bits 14 to bits 5                                */
    PSP_VPFE_ALaw_bits13_4  = 2,
    /**< ALAW Width - from bits 13 to bits 4                                */
    PSP_VPFE_ALaw_bits12_3  = 3,
    /**< ALAW Width - from bits 12 to bits 3                                */
    PSP_VPFE_ALaw_bits11_2  = 4,
    /**< ALAW Width - from bits 11 to bits 2                                */
    PSP_VPFE_ALaw_bits10_1  = 5,
    /**< ALAW Width - from bits 10 to bits 1                                */
    PSP_VPFE_ALaw_bits9_0  = 6
    /**< ALAW Width - from bits 9 to bits 0                             */
}PSP_VPFE_ALaw_Width;

/**
 *      VPFE Channel Id |
 */
 
/**
  * \brief Enum defines the channnel id for different vpfe modules
  *
  */
typedef enum _PSP_VPFE_Id
{
    PSP_VPFE_INVALID_ID = -1,
    /**< Invalid VPFE id                                    */
    PSP_VPFE_CCDC,
    /**< Ccdc YCbCr and RAW                                 */
    PSP_VPFE_MAX_INTERFACES_SUPPORTED

} PSP_VPFE_Id;


typedef enum _PSP_VPFE_Err
{
    PSP_VPFE_Err_Noreset            = 0,
    /**< Do not reset the FPC error */
    PSP_VPFE_Err_reset              = 1
    /**< reset the FPC error */

} PSP_VPFE_Err;
        
typedef enum _PSP_VPFE_Fpc
{
    PSP_VPFE_Fpc_Disable    = 0,
    /**< Disable the Fault Pixel Correction             */
    PSP_VPFE_Fpc_Enable     = 1
    /**< Enable the Fault Pixel Correction          */
}PSP_VPFE_Fpc;

/**
 * Callback Function Prototype
 */
 
/**
  * /brief Prototype for callback function
  *
  */
typedef void (*PSP_VPFEAppCallback)(Ptr * cbkContext,Ptr param, Int status);


/**
 * Data-Structures
 */

/**
  * \brief structure for the Ccdc RAW Parameters object
  *         
  */
typedef struct _PSP_VPFECCDCRawParams
{
    Uint32 dataSize;      
    /**< Input data width; 8-16 bits                    */  
    PSP_VPFEPack pack8;         
    /**< Data stored as 16bit/pixel or 8bit/pixel       */
    PSP_VPFE_Datapol dataPol;       
    /**< Data polarity; Normal/1's compliment               */
    PSP_VPFE_SyncPolarity VDSyncPol;     
    /**< VD Sync polarity                               */
    PSP_VPFE_SyncPolarity HDSyncPol;     
    /**< HD Sync polarity                               */
    PSP_VPFE_SyncDirection HDVDMaster;    
    /**< Master or slave mode for VD and HD signals         */
    Uint32 HDSyncWidth;   
    /**< Width of HD Sync pulse                             */
    Uint32 VDSyncWidth;   
    /**< Width of the VD Sync pulse                         */
    Uint32 numPxlPerLine; 
    /**< Number of pixel clock periods in one line      */
    Uint32 numLinPerFld;  
    /**< Number of lines per field                      */
    PSP_VPFE_ALaw   ALawEnable;
    /**< This parameters enables/Disables ALaw packig   */
    PSP_VPFE_ALaw_Width ALaw_Width;
    /**< This parameter sets the ALaw gamma bit selection   */

} PSP_VPFECcdcRawParams;

/**
  * \brief structure for the Ccdc Config Parameters object
  *         
  */
typedef struct _PSP_VPFECCDCConfigParams
{
    PSP_VPFE_CCDC_InputMode  inpmod;
    /**< Enum that describes the inputMode of CCDC */
    PSP_VPSSFieldFrame      ffMode;
    /**<InterLaced or Progressive Mode  .Ignored for RAW Mode*/
    Uint                    height;
    /**< Height for Front-End Mode Capture                  */
    Uint                    width;
    /**<  Width for Front-End Mode Capture                   */
    Uint                    pitch;
    /**< Pitch/offset value                                 */
    Uint                    horzStartPix;
    /**< Sets pixel at which data output begins horizontally */
    Uint                    vertStartPix;
    /**< Sets line at which data output begins          */
    PSP_VPFEAppCallback             appCallback;
    /** Application Callback Handle                                  */    
    PSP_VPSS_ExtVideoDecoderFxns extVDFxn;
    /** External Video Deocder Interface                          */    
    Int segId;
    /** SegId passed from Application to allocate memory          */
    PSP_VPFECcdcRawParams rawParams;
    /**< parameters for Raw input                           */

    
} PSP_VPFECcdcConfigParams;

/**
 *Data-Structures for IOCTLs
 */

 /**
  * \brief structure for the black Adjust IOCTL Parameters object
  *         
  */
typedef struct _PSP_VPFECCDC_BlackAdj 
{
    PSP_VPFE_BlkComp clampEn;       
    /**<  Enable/disable black level clamping */
    PSP_VPFE_BlkComp_Pixlen blackSampLen;  
    /**<  Num Black Sample pixels per line to include in the calculation */
    PSP_VPFE_BlkComp_Pixlen blackSampLine; 
    /**<  Num Black Sample lines to include in the calculation */
    Uint16 blackPixStart; 
    /**<  Start black pixel position */
    Uint8 blackGain;     
    /**<  Gain to be applied to optical black average */
    Uint16 dcSub;         
    /**<  Constant DC value to subtract if clampEn is disabled */
    Uint colPtn;        
    /**<  CCDC color pattern */
    Uint8 blkCmpR;       
    /**<  Black level compensation for R color pixels */
    Uint8 blkCmpGR;      
    /**<  Black level compensation for GR color pixels */
    Uint8 blkCmpGB;      
    /**<  Black level compensation for GB color pixels */
    Uint8 blkCmpB;       
    /**<  Black level compensation for B color pixels */
} PSP_VPFECCDC_BlackAdj;


/**
  * \brief structure for the Fault Pixel Correction IOCTL Parameters object
  *         
  */
typedef struct _PSP_VPFE_CCDC_Fpc 
{
    PSP_VPFE_Fpc        fpcEnable;
    /**<  CCDC Fault Pixel Correction enable/disable */
    Uint8               fpcnum;
    /**< number of Fault Pixels to be corrected     */
    Uint32              fpcAddr;
    /**< Address of the FPC Table                   */
    PSP_VPFE_Err    fpcreset;
    /**< use this parameter to reset the FPC error  */
}PSP_VPFE_CCDC_Fpc;

/**
 * Channel Parameters
 */

/**
  * \brief structure for object for Channel Params
  *
  */
typedef struct _PSP_VPFEChannelParams {
    PSP_VPFE_Id            id;
    /**< VPFE  plane id                                      */
    Ptr                    params;
    /**< Handle to access params                             */ 
} PSP_VPFEChannelParams;

typedef struct _PSP_VPFEValidateParams
{
    PSP_VPSSSurfaceParams       InParams;
    /**< Pass the Surface params as input to validate       */
    /**< Presently Pitch validataion is only done           */
    PSP_VPSSSurfaceParams       OutParams;
    /**< If the Pitch given as Input doesnot validate then 
         appropriate pitch is given as this Params.Pass NULL 
         params to this element                             */
}PSP_VPFEValidateParams;


#endif /* _PSP_VPFE_H */
