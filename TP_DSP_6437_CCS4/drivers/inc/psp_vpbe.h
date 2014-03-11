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
 *  \file   psp_vpbe.h
 *
 *  \brief  VPBE interface definition
 *
 *  This file contains the interfaces, data types and symbolic definitions
 *  that are needed by the application to utilize the serivces of the VPBE
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
#ifndef _PSP_VPBE_H
#define _PSP_VPBE_H

/**
 * Header File Inclusion
 */
#include <psp_vpss.h>

/**
 * Defines 
 */
#define PSP_VPBE_MAX_MAIN_CLUT_ENTRIES      256u

#define PSP_VPBE_MAX_BMP_CLUT_ENTRIES       16u
/**
 * Enumerations
 */

/**
 * VPBE Channel Id
 */
 
/**
  * \brief Enum defines the channnel id for different plane
  *
  */
typedef enum _PSP_VPBE_Id
{
    /**< Invalid VPBE id                                                     */
    PSP_VPBE_INVALID_ID = -1,
    /**< Video 0 plane  id                                                   */
    PSP_VPBE_VIDEO_0,
    /**< Video 1 plane  id                                                   */
    PSP_VPBE_VIDEO_1,
    /**< OSD 0 plane  id                                                     */
    PSP_VPBE_OSD_0,
    /**< OSD 1 plane  id                                                     */
    PSP_VPBE_OSD_1,
    /**< Cursor plane  id                                                    */
    PSP_VPBE_CURSOR,
    /**< Venc plane  id                                                      */
    PSP_VPBE_VENC,  
    /**< Maximum Interfaces Supported                                        */
    PSP_VPBE_MAX_INTERFACES_SUPPORTED
    
} PSP_VPBE_Id;

/**
  * \brief Enum for Vpbe related IOCTL
  *
  */
typedef enum _PSP_VPBEIoctlCommand
{
    PSP_VPBE_IOCTL_OSD_BOUNDARY,
    /**< IOCTL for OSD Windows Boundary Parameters                          */
    PSP_VPBE_IOCTL_OSD_BLENDING,
    /**< IOCTL for OSD Windows Blending Factor                              */
    /**< Applicable for OSD-0 and OSD-1 Windows                             */ 
    PSP_VPBE_IOCTL_OSD_TRANSPARENCY,
    /**< IOCTL for OSD Windows Tranparency color                            */
    /**< Applicable for OSD-0 and OSD-1 Windows                             */ 
    PSP_VPBE_IOCTL_OSD_ZOOM,
    /**< IOCTL for Zooming OSD Windows                                      */
    PSP_VPBE_IOCTL_OSD_PROGRAM_MAIN_CLUT,
    /**< IOCTL for Program Main CLUT                                        */
    PSP_VPBE_IOCTL_OSD_PROGRAM_BMP_CLUT,
    /**< IOCTL for Program BMP CLUT                                         */
    PSP_VPBE_IOCTL_OSD_VALIDATE_BUFFER
    /**< IOCTL for Validate Buffer                                          */
    
} PSP_VPBEIoctlCommand;

/**
 * Blending Ratio
 */
 /**
  * \brief Enum for the Blending Ratio factor for different planes
  *        (VIDEO/OSD)  
  *
  */
typedef enum _PSP_VPBE_BlendingFactor
{
    PSP_VPBE_BLEND0 = 0,
    PSP_VPBE_BLEND1,
    PSP_VPBE_BLEND2,
    PSP_VPBE_BLEND3,
    PSP_VPBE_BLEND4,
    PSP_VPBE_BLEND5,
    PSP_VPBE_BLEND6,
    PSP_VPBE_BLEND7
} PSP_VPBEBlendingFactor;
/**
  * \brief Enum for the different Scaling Factors for specified planes
  *        
  */
typedef enum _PSP_VPBE_Scalingfactor
{
    /**< No Scaling                                                          */
    PSP_VPBE_ZOOM_IDENTITY = 1,
    /**< Scaling by 2x                                                       */
    PSP_VPBE_ZOOM_2X,
    /**< Scaling by 4x                                                       */
    PSP_VPBE_ZOOM_4X
    
} PSP_VPBEScalingFactor;

/**
  * \brief Enum for the Expansion format in different planes
  *        (Horizontal & Vertical)
  *
  */
typedef enum _PSP_VPBE_Expansionfactor
{
    /**< No expansion                                                        */
    PSP_VPBE_EXP_IDENTITY   = 1,
    /**< Square Pixel Expansion by 9/8(Horizontal Direction only)            */ 
    PSP_VPBE_EXP_NINE_BY_EIGHT,
    /**< Square Pixel Expansion by 6/5(Vertical Direction only)              */ 
    PSP_VPBE_EXP_SIX_BY_FIVE
    
} PSP_VPBEExpansionFactor;

/**
  * \brief Enum for the CLUT SOURCE 
  *
  */
typedef enum _PSP_VPBE_CLUTSOURCE
{
    PSP_VPBE_CLUTSOURCE_ROM = 0,
    /**< CLUT source to be from ROM */    
    PSP_VPBE_CLUTSOURCE_RAM
    /**< CLUT source to be from RAM */    
}PSP_VPBE_CLUTSOURCE;
/**
  * \brief Enum for the different colour format 
  *
  */
typedef enum _PSP_VPBEColorFormat
{
    PSP_VPBE_YCbCr422 = 0,
    /* Applicable to VIDEO-0 and VIDEO-1 planes only */
    PSP_VPBE_YCrCb422,
    /* Applicable to VIDEO-0 and VIDEO-1 planes only */
    PSP_VPBE_YCbCr444,
    /* Applicable to VIDEO-0 and VIDEO-1 planes only */
    PSP_VPBE_YCrCb444,
    /* Applicable to VIDEO-0 and VIDEO-1 planes only */
    PSP_VPBE_RGB_888,
    /* Applicable to VIDEO-0 and VIDEO-1 planes only */
    PSP_VPBE_RGB565,
    /* Applicable to OSD-0 and OSD-1 planes only     */
    PSP_VPBE_DVD_MODE,
    /* Applicable to OSD-0 and OSD-1 planes only     */
    PSP_VPBE_CLUT_INDEXED,
    /* Applicable to OSD-0 and OSD-1 planes only     */
    PSP_VPBE_ATTRIBUTE,
    /*Applicable to OSD1 Attribute Only              */
    PSP_VPBE_INVALID
} PSP_VPBEColorFormat;

/**
  * \brief Enum for the Video Standard
  *
  */
typedef enum _PSP_VPBETimings
{
    PSP_VPBE_AUTO_MODE                          = 0,
    PSP_VPBE_DISPLAY_NTSC_INTERLACED_COMPOSITE  = 1,
    PSP_VPBE_DISPLAY_NTSC_INTERLACED_S_VIDEO    = 2,
    PSP_VPBE_DISPLAY_NTSC_INTERLACED_COMPONENT  = 3,
    PSP_VPBE_DISPLAY_NTSC_PROGRESSIVE_COMPONENT = 4,
    PSP_VPBE_DISPLAY_PAL_INTERLACED_COMPOSITE   = 5,
    PSP_VPBE_DISPLAY_PAL_INTERLACED_S_VIDEO     = 6,
    PSP_VPBE_DISPLAY_PAL_INTERLACED_COMPONENT   = 7,
    PSP_VPBE_DISPLAY_PAL_PROGRESSIVE_COMPONENT  = 8

    /* Add others as and when necessary  */
    /* HDTV etc*/
} PSP_VPBETimings;

typedef enum _PSP_VPBERAMWRMode
{
    PSP_VPBE_RAMWR_NORMAL_MODE                  = 0,
    /**<RAM WR in NORMAL MODE                                       */
    PSP_VPBE_RAMWR_DVD_MODE                     = 1
    /**<RAM WR in DVD MODE                                          */
}PSP_VPBERAMWRMode;

/******************************************************************************
                                Data-Structures
******************************************************************************/

/**
 * Callback Function Prototype
 */
/**
  * /brief Prototype for callback function
  *
  */
typedef void (*PSP_VPBEAppCallback)(Ptr * cbkContext,Ptr param, Int status);

/**
  * \ brief structure for OSD Config Parameters object
  *
  */
typedef struct _PSP_VPBEOsdConfigParams
{
    /* Mode  */
    PSP_VPSSFieldFrame     ffMode;
    /**<field frame mode(Interlaced/Progressive)                    */
    PSP_VPSSBitsPerPixel   bitsPerPixel;
    /**< Bits per pixel in different planes                         */
    PSP_VPBEColorFormat    colorFormat;
    /**< Color format in different planes                           */
    Uint                   pitch; 
    /**< Pitch or offset for given plane(offset)                    */
    Uint                    leftMargin;
    /**<  Left margin of the window                                 */
    Uint                    topMargin;
    /**<  Top margin of the window                                  */
    Uint                    width;
    /**<  Width of the window                                       */
    Uint                    height;
    /**<  Height of the window                                      */
    int                             segId;    
    /** SegId passed from Application to allocate memory              */
    /* SCALING(ZOOM)/EXPANSION */
    PSP_VPBEScalingFactor   hScaling;
    /**<Scaling the plane in the horizontal direction                */
    PSP_VPBEScalingFactor   vScaling;
    /**<Scaling the plane in the vertical direction                  */
    PSP_VPBEExpansionFactor hExpansion;
    /**< Expanding the plane in the horizontal direction             */
    PSP_VPBEExpansionFactor vExpansion;
    /**< Expanding the plane in the vertical direction               */ 
    
    /* Application Callback */

    PSP_VPBEAppCallback     appCallback;
    /**< Handle for callback from osd plane operation                */

    /* Blending*/

    PSP_VPBEBlendingFactor     blending; 
    /**< blending factor to config for OSD plane(0-8)                    */
    /** Blending is Applicable to OSD 0 and OSD 1 Plane Only         */    
    /* Transparency */
    Bool                   transparency;
    Uint                   transparencyColor;
    /**< Transparency for OSD-0 and OSD-1 plane only                   */
    /* CLUT sources */
    PSP_VPBE_CLUTSOURCE       CLUTSource;
    /**< CLUTSORUCE for OSD-0 and OSD-1 plane only                   */
    
} PSP_VPBEOsdConfigParams;
/**
  * \ brief structure for CURSOR Config Parameters object
  *
  */
typedef struct _PSP_VPBECursorConfigParams
{
    Uint                    leftMargin;
    /**<  Left margin of the window                                 */
    Uint                    topMargin;
    /**<  Top margin of the window                                  */
    Uint                    width;
    /**<  Width of the window                                       */
    Uint                    height;
    /**<  Height of the window                                      */
    PSP_VPBE_CLUTSOURCE         CursorCLUTS;    
    /**< CLUT source for Cursor                                          */
} PSP_VPBECursorConfigParams;

/**
  * \brief structure for VENC Config Parameters
  *
  */
typedef struct _PSP_VPBEVENCConfigParams
{
    PSP_VPBETimings         displayStandard;
    /**< Config the display Standard for Venc(Video Encoder)        */
} PSP_VPBEVencConfigParams;

typedef struct _PSP_VPBEValidateParams
{
    PSP_VPSSSurfaceParams       InParams;
    PSP_VPSSSurfaceParams       OutParams;

}PSP_VPBEValidateParams;

/**
 *  Channel Parameters
 */

/**
  * \brief structure for object for Channel Params
  *
  */
typedef struct _PSP_VPBEChannelParams {
    PSP_VPBE_Id             id;
    /**< VPBE plane id                                              */
    Ptr                     params;
    /**< Handle to access params (SurfaceParams)                    */
} PSP_VPBEChannelParams;


/**
  * \brief  Structure for Color Space Parameters object
  *
  */
typedef struct _PSP_VPBEColorSpaceParams
{
    Uint8         Y;
    /**< Luma Color Space                                           */
    Uint8         Cb;
    /**< Chroma Color Space-Blue                                    */
    Uint8         Cr;
    /**< Chroma Color Space-Red                                     */
} PSP_VPBEColorSpaceParams;

/**
  * \brief  Structure for CLUT Parameters object
  *
  */
typedef struct _PSP_VPBEMainClutParams
{
    PSP_VPBEColorSpaceParams   MainClut_val[PSP_VPBE_MAX_MAIN_CLUT_ENTRIES];
    /**< Main clut values                                                */
    PSP_VPBERAMWRMode          mode;
    /**< RAM WR Mode                                                    */
} PSP_VPBEMainClutParams;


/**
 * BMP CLUT Parameters
 */
typedef struct _PSP_VPBE_BMPClutParams
{
    Uint8                  BMPClut_val[PSP_VPBE_MAX_BMP_CLUT_ENTRIES];
    /**< BMP clut values                                                */
    PSP_VPBERAMWRMode      mode;
    /**< RAM WR Mode                                                    */
} PSP_VPBEBMPClutParams;


#endif /* _PSP_VPBE_H */
