/*******************************************************************************
**+--------------------------------------------------------------------------+**
**|                            ****                                          |**
**|                            ****                                          |**
**|                            ******o***                                    |**
**|                      ********_///_****                                   |**
**|                      ***** /_//_/ ****                                   |**
**|                       ** ** (__/ ****                                    |**
**|                           *********                                      |**
**|                            ****                                          |**
**|                            ***                                           |**
**|                                                                          |**
**|         Copyright (c) 1998-2006 Texas Instruments Incorporated           |**
**|                        ALL RIGHTS RESERVED                               |**
**|                                                                          |**
**| Permission is hereby granted to licensees of Texas Instruments           |**
**| Incorporated (TI) products to use this computer program for the sole     |**
**| purpose of implementing a licensee product based on TI products.         |**
**| No other rights to reproduce, use, or disseminate this computer          |**
**| program, whether in part or in whole, are granted.                       |**
**|                                                                          |**
**| TI makes no representation or warranties with respect to the             |**
**| performance of this computer program, and specifically disclaims         |**
**| any responsibility for any damages, special or consequential,            |**
**| connected with the use of this program.                                  |**
**|                                                                          |**
**+--------------------------------------------------------------------------+**
*******************************************************************************/

/** \file   pal_osCache.h
    \brief  OsLIST Services Header File

    This file declares APIs for handling simple bi-directional linked
    list that works with arbitrary data objects in a thread-safe manner.
    Movement of elements within the OsLIST is FIFO mode. 

    Only requirement on Elements strung onto the OsLIST is that they
    must begin with an OsLIST header comprising of a forward and reverse
    pointers. No Memory allocation or freeing is performed by these APIs.
    Memory allocation/freeing must be handled outside by the caller
    
    The list is assumed to be circular linked list and the calls are protected
    from interrupts.
    
    (C) Copyright 2006, Texas Instruments, Inc

    @author     PSP Architecture Team
    @version    1.0 - Original from PSPF1.0
                1.1 - Added macro version (non-protected)
                1.2 - Converted macro version to functions so that return value can be obtained
                      Thus at this stage no macros supported now
                1.3 - Add a few more API's
 */

#ifndef __PAL_OS_CACHE_H__
#define __PAL_OS_CACHE_H__

#include "psp_common.h"

/**
 * \defgroup PalOSCache PAL OS Cache Interface
 * 
 * PAL OS Cache Interface
 * \{
 */

/** \name PAL OS Cache Interface 
 *  PAL OS Cache Interface 
 * \{
 */

 typedef enum
 {
    PAL_osCache_NOT_DEFINED
 } PAL_osCacheMemAddrSpace;



/**
 * \brief   PAL OS Cache Invalidate
 * 
 * This function invalidates the D cache.
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  mem_start_ptr [IN]      Starting adress of memory. Please note that this should be 32 bytes alinged.
 *  \param  num_bytes [IN]         length of buffer
 * \return  nil return value
 */
void PAL_osCacheInvalidate(PAL_osCacheMemAddrSpace  cache,
                           Uint32                   mem_start_ptr,
                           Uint32                   num_bytes);

/**
 * \brief   PAL OS Cache Flush
 * 
 * This function flushes (cleans) the Cache
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  mem_start_ptr [IN]      Starting adress of memory. Please note that this should be 32 bytes alinged.
 *  \param  num_bytes [IN]         length of buffer
 * \return  nil return value
 */
void PAL_osCacheFlush(PAL_osCacheMemAddrSpace   cache,
                      Uint32                    mem_start_ptr,
                      Uint32                    num_bytes);


/**
 * \brief   PAL OS Cache Flush and Invalidate
 * 
 * This function flushes (cleans) and invalidates the Cache
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  mem_start_ptr [IN]      Starting adress of memory. Please note that this should be 32 bytes alinged.
 *  \param  num_bytes [IN]         length of buffer
 * \return  nil return value
 */
void PAL_osCacheFlushAndInvalidate(PAL_osCacheMemAddrSpace  cache,
                                   Uint32                   mem_start_ptr,
                                   Uint32                   num_bytes);


/**
 * \brief   PAL OS Set Cache line Length
 * 
 * This function sets the cache line
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  Cache
 * \return  nil return value
 */
void PAL_osCacheSetCacheLineLength(PAL_osCacheMemAddrSpace  cache,
                                   Uint8                    length);

/**
 * \brief   PAL OS GEt Cache line Length
 * 
 * This function returns the length of cache line
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  void
 * \return  Cache Length
 */
Uint8 PAL_osCacheGetCacheLineLength(PAL_osCacheMemAddrSpace cache);


/**
 *  \brief Drain the write buffer
 *
 *  This function Drain the write buffer
 *
 *  NOTE : cacheAddrSpace is not cared in this API
 *  \parm   cacheAddrSpace[IN]      Cache address space
 *  \param  waitForInt [IN]        if TRUE -- Drains the writebuffer and put processor in low
                                              power mode till next interrupts occurs.
                                    if FALSE -- Drains the writebuffer and stops excuting further 
                                                till buffer is drained. 
 */
void PSP_cacheDrainWriteBuffer(PAL_osCacheMemAddrSpace  cache,
                               Bool                     waitForInt);


/*\}*/

/*\}*/

#endif /* __PAL_OS_CACHE_H__ */
