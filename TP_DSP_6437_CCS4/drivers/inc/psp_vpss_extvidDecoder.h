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
 *  \file   psp_vpss_extVidDecoder.h
 *
 *  \brief  VPSS external video decoder related functionality dependencies
 *
 *  This file contains the dependencies related to external video decoder.
 *
 *  (C) Copyright 2010, Texas Instruments, Inc
 *
 *  \author     Maulik Desai
 *
 *  \version    0.1     created
 */

#ifndef _PSP_VPSS_EXTVIDEODECODER_H
#define _PSP_VPSS_EXTVIDEODECODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "_tistdtypes.h"

#define EVD_FAIL        (0u)
#define EVD_SUCCESS     (1u)

typedef void * EVD_Handle;

typedef enum _PSP_VPSS_ExtVideoDecoderIoctlCmd
{
    PSP_VPSS_EXT_VIDEO_DECODER_CONFIG = 1,
    /** Configure the External Video Decoder        */
    PSP_VPSS_EXT_VIDEO_DECODER_STATUS,
    /** To get status of status parameters          */
    PSP_VPSS_EXT_VIDEO_DECODER_CONTROL
    /** To control the control parameters           */
}PSP_VPSS_ExtVideoDecoderIoctlCmd;

/*-----------------------------------------------------------------------------
                    External Video Decoder Interface
-----------------------------------------------------------------------------*/
typedef struct _PSP_VPSS_ExtVideoDecoderFxns
{
    EVD_Handle  (*Open)();
    Int         (*Close)(Ptr handle);
    Int         (*Control)(Ptr handle,Uint32 Cmd,Ptr CmdArg);

}PSP_VPSS_ExtVideoDecoderFxns;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /*_PSP_VPSS_EXTVIDEODECODER_H */
