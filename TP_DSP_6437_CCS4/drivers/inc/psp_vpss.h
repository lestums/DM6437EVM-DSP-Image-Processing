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
 *  \file   psp_vpss.h
 *
 *  \brief  VPSS interface definition
 *
 *  This file contains the interfaces,data types and symbolic definitions
 *  that will be utilize by application to utilize the serivces of both VPFE
 *  and VPBE device driver.
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
#ifndef _PSP_VPSS_H
#define _PSP_VPSS_H
/******************************************************************************
                            Header File Inclusion
******************************************************************************/
#include <psp_common.h>
#include "tistdtypes.h"

/******************************************************************************
                                  Macros
******************************************************************************/
/**<  brief number of instances supported by  platform  */
#define PSP_VPSS_NUM_INSTANCES              1u
/**< First instance Id index                            */
#define PSP_VPSS_0_INSTANCE_ID              0u

/******************************************************************************
                               Enumerations
******************************************************************************/
/**
  * \brief Enum for the Queue/Dequeue Commands
  *
  */
typedef enum _PSP_VPSSSubmitCommand
{
    PSP_VPSS_DEQUEUE = 0,
    /**< DeQueue of FrameBuffer                                             */
    PSP_VPSS_QUEUE,
    /**< Queue of FrameBuffer                                               */
    PSP_VPSS_ALLOC,
    /**< Allocate memory to FrameBuffer                                        */
    PSP_VPSS_FREE
    /**< Frees memory of  FrameBuffer                                        */
} PSP_VPSSSubmitCommand;

/**
  * \brief Enum for the Field Frame Modes
  *
  */
typedef enum _PSP_VPSSFieldFrame
{
    PSP_VPSS_FIELD_MODE = 0,
    /**< Progressive Mode                                                   */
    PSP_VPSS_FRAME_MODE
    /**< Interlaced Mode                                                    */
} PSP_VPSSFieldFrame;

/**
  * \brief Enum for the Bits Per Pixel for different Module
  *
  *
  */
typedef enum _PSP_VPSSBitsPerPixel
{
    PSP_VPSS_BITS1  = 1,
    PSP_VPSS_BITS2  = 2,
    PSP_VPSS_BITS4  = 4,
    PSP_VPSS_BITS8  = 8,
    PSP_VPSS_BITS16 = 16,
    PSP_VPSS_BITS24 = 24
} PSP_VPSSBitsPerPixel;

/******************************************************************************
                              Data-Structures
******************************************************************************/
/**
  * \brief Structure for Surface Parameters object
  *
  */
typedef struct _PSP_VPSSSurfParams
{
    Uint                       pitch;
    /**< Pitch parameters for given plane                                    */
    Uint                       lines;
    /**< Line surface parameters for given plane                             */
    Ptr                        frameBufferPtr;
    /**< Pointer to frambuffer for given plane                               */
    PSP_VPSSBitsPerPixel       bpp;
    /**< Bits per pixel support                                              */
    Uint32                     timeStamp;
    /**<To register the TimeStamp                                            */
    Ptr                        userParams;
    /**<userParams is application specific to attached custom info attached
        by application.Driver themselves will never look at this parameter   */
} PSP_VPSSSurfaceParams;

#endif  /*_PSP_VPSS_H */
