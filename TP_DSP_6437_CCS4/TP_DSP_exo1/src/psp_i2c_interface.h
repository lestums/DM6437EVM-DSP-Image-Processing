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
 *  \file   psp_i2c_interface.h
 *
 *  \brief  This file contains the related dependencies to psp_i2c_interface.c
 *          file.
 *
 *  (C) Copyright 2010, Texas Instruments, Inc
 *
 *  \author     Maulik Desai
 *
 *  \version    0.1     created
 */
#ifndef _PSP_I2C_INTERFACE_H
#define _PSP_I2C_INTERFACE_H

#include "psp_common.h"

/******************************************************************************
                                    Functions
******************************************************************************/
/**
 *  \brief  creates and opens an instance of i2c
 * 
 *  \Returns                SUCCESS/FAILURE status.
 */
Int i2c_init();
/**
 *  \brief  closes and Deletes an instance of i2c
 
 *  \Returns               SUCCESS/FAILURE status.
 */
Bool i2c_deInit();

/**
 *  \brief  Performs write operation on to addressed i2c slave
 *
 *  \param  SlaveAddr   [IN}        SlaveAddress for Write
 *  
 *  \param  buffer      [IN]       Pointer from which data needs to be
 *                                 written on to slave device. This buffer
 *                                 has first parameter as Offset address
 *                                 from where data has to be written
 *
 *  \param length       [IN]       Number of bytes of data included in the
 *                                 buffer above. The interface function
 *                                 takes this as an input to write the
 *                                 number of bytes of data on the device
 *                                 addressed.
 *
 *                                 The Number of bytes of data that will
 *                                 be written on the device is equal to
 *                                 (length - 1)
 *
 *  \Returns                       SUCCESS/FAILURE status.
 */
Bool i2c_writeReg(Uint8 SlaveAddr,Uint8 *buffer, Uint32 length);
/**
 *  \brief  Performs write operation on to addressed i2c slave
 *
 *  \param  SlaveAddr  [IN]       SlaveAddr for Read
 *
 *  \param  buffer      [IN]      Pointer to which data needs to be
 *                                read from slave. This buffer has first
 *                                parameter as Offset address from where
 *                                data has to be read.
 *
 *  \param  length      [IN]      Number of bytes of data included in the
 *                                buffer above. The interface function
 *                                takes this as an input to read the
 *                                number of bytes of data on the device
 *                                addressed.
 *
 *                                The Number of bytes of data that will
 *                                be read from the device is equal to
 *                                (length - 1)
 *
 *  \Returns                      SUCCESS/FAILURE status.
 */
Bool i2c_readReg(Uint8 SlaveAddr,Uint8 *buffer, Uint32 length);

#endif /*_PSP_I2C_INTERFACE_H */

