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
**|         Copyright (c) 1998-2006 Texas Instruments Incorporated          |**
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

/*!
 *  \file   psp_i2cApi.h
 *
 *  \brief  Wrapper APIs called by DDA to access DDC
 *
 *  This file contains APIs defination of APIs that are wrapper APIs for DDC 
 *  layer. These APIs will be called by DDA layer.
 *
 *  (C) Copyright 2006, Texas Instruments, Inc
 *
 *  \author     PSP Team
 *
 *  \version    1.0 - Created
 */

#ifndef _PSP_I2C_API_
#define _PSP_I2C_API_



/*! 
 *  \brief CallBack function for I2C 
 *   
 *  This function will be called when any transaction has been completed and 
 *  driver is operating in asynch mode.
 *
 *  \param  appHandle [OUT]     Registered by application and will be returned 
 *                              along with call back.
 *  \param  event     [OUT]     event associated for which call back has been 
 *                              called
 *  \param  Param     [OUT]     Any parameter returned from driver
 *
 *  \Note :- This function is not supported currently as driver does not support async 
 *           mode of operation.
 */
typedef void (*PSP_I2cAppCallback)(Ptr appHandle,Int event, Ptr param);

/*! 
 *  \brief hwEventCallBack function for I2C.  
 *
 *
 *  This function will be called when any transaction has been completed when 
 *  driver is operating in asynch mode.
 *
 *  \param  appSlvHandle [OUT]  Registered by application and will be returned 
 *                              along with call back.
 *  \param  event        [OUT]  event associated for which call back has been 
 *                              called
 *  \param  data         [OUT]  Data returned from driver
 *
 *  \Note :- This function is not supported currently as driver does not support slave 
 *           mode of operation 
 */
typedef void (*PSP_I2cHwEventCallback)(Ptr appSlvHandle, Int8 event, Uint8 data);
/*!
 *  \brief Initialize I2C driver (instance)
 *
 *  Typically,software bookkeeping functions are performed in this call.Configuration 
 *  information is passed in the call and initialization is done based upon the information.    
 *
 *  \param  instanceId [IN]     I2C instance number
 *  \param  initConfig [IN]     Initialization configuration
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result  PSP_i2cCreate(Uint32  instanceId,const PSP_I2cConfig *initConfig);

/*!
 *  \brief Delete I2C driver (instance)
 *
 *  The I2C instance is deleted in software. If there are open handles then they are invalidated
 *
 *  \param  instanceId [IN]     I2C instance number
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result PSP_i2cDelete(Uint32 instanceId);

/*! 
 *  \brief Open Instance of the I2C device
 *
 *   This function prepares the device hardware for data transfers and usage by the upper layer 
 *   driver software.It returns an handle to the driver instance.
 *
 *   
 *  \param  instanceId  [IN]    I2C instance number
 *  \param  callback    [IN]    Callback function for events notification
 *  \param  appHandle   [IN]    This appHandle will be provided by user and will 
 *                              be returned along with call back    
 *  \return PSP_Handle  [OUT]   If successful returns driver instance Handle
 *                              else negative error code
 *
 *  \Note:- The driver can be opened multiple times
 */ 
PSP_Handle  PSP_i2cOpen(Uint32 instanceId, PSP_I2cAppCallback callback, Ptr appHandle);

/*!
 *  \brief Close Instance of the I2C device
 *
 *  This function closes the device for data transfers and used by the
 *  upper layer driver software. The hardware is programmed to stop/abort data
 *  transfer (depending upon the type of device and its specifics) and the
 *  device ISR is "disabled" by the upper layer driver software after the
 *  completion of this call. After the successful completion of this call, the
 *  device cannot perform any data IO.
 *
 *  \param  handle [IN]         I2C Driver Instance Handle
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result  PSP_i2cClose(PSP_Handle handle);

/*!
 *  \brief Read/Write (single transaction) using I2C
 *
 *  This function read/writes single transaction data using the I2C peripheral.
 *
 *  \param  handle      [IN]    I2C Driver Instance Handle
 *  \param  slaveAddr   [IN]    Slave address (only valid in Master mode)
 *  \param  buffer      [IN]    Buffer (to read into or write from)
 *  \param  bufLen      [IN]    Buffer length - number of bytes to transfer
 *  \param  flags       [IN]    Flags to specify mode of operation
 *  \param  timeout     [IN]    Timeout for i2c transaction
 *  \param  param       [IN]    Extra paramter for future usage
 *  \return On success returns number of bytes transmitted, else negative error code
 */
Int PSP_i2cTransfer (PSP_Handle handle,
                     Uint32     slaveAddr,
                     Uint8      *buffer,
                     Uint32     bufLen,
                     Uint32     flags,
                     Int32      timeout,
                     Ptr        param);

/*!
 *  \brief Read/Write multiple transactions using I2C
 *
 *  This function read/writes multiple transactions data using the I2C peripheral.
 *  Though nothing prevents the user from using multiple invocations of the
 *  single transaction transfer function, this function helps in making sure that
 *  all the transactions are completed in one go before another application gets
 *  hold of the i2c bus (from the applications perspective)
 *
 *  \param  handle  [IN]    I2C Driver Instance Handle
 *  \param  xfer    [IN]    I2C Transaction array - first element pointer
 *  \param  numXfer [IN]    Number of transactions to be done
 *  \param  param   [IN]    Extra paramter for future usage
 *  \param  timeout [IN]    Timeout for whole i2c transaction
 *  \return PSP_SOK or PSP Error code
 */
PSP_Result  PSP_i2cTransferMultiple (PSP_Handle     handle,
                                     PSP_I2cTransaction *xfer,
                                     Uint32         numXfer,
                                     Int32          timeout,
                                     Ptr            param);
/*!
 *  \brief IO Control for I2C controller.
 *
 *  This function supports various IOCTLs for the I2C controller.
 *
 *  \param  handle  [IN]    I2C Driver Instance Handle
 *  \param  cmd     [IN]    IOCTL command
 *  \param  cmdArg  [IN]    Arguments, if any, for the command
 *  \param  param   [IN]    IOCTL specific parameter (driver specific).
 *  \return PSP_SOK or PSP Error code.
 *
 */
PSP_Result  PSP_i2cIoctl(PSP_Handle     handle,
                        PSP_I2cIoctlCmd cmd,
                        Ptr             cmdArg,
                        Ptr             param);
#endif /*_PSP_I2C_API_*/
