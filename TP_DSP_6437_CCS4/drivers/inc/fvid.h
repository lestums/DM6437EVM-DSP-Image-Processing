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

/** \file   FVID.h
 *
 *  \brief  This file is used by the Application to call the GIO functions
 *   
 *
 *  (C) Copyright 2006, Texas Instruments, Inc
 *
 *  \author     Maulik Desai
 *
 *  \version    0.1     Created
 */
#ifndef FVID_
#define FVID_

/*******Header File Inclusion *******/
#include <gio.h>
#include <iom.h>

#define FVID_QUEUE      (1u)
#define FVID_DEQUEUE    (2u)
#define FVID_EXCHANGE   (3u)
#define FVID_ALLOC        (4u)
#define FVID_FREE        (5u)

typedef GIO_Handle FVID_Handle;
/*
 *  ======== FVID_create ========
 */
#define  FVID_create(name, mode, status, optArgs, attrs)\
            GIO_create(name, mode, status, optArgs, attrs)
/*
 *  ======== FVID_delete ========
 */
#define FVID_delete(giochan) \
            GIO_delete(giochan)
/*
 *  ======== FVID_queue ========
 */

#define FVID_queue(giochan,bufp) \
            GIO_submit(giochan,FVID_QUEUE,bufp,NULL,NULL)
/*
 *  ======== FVID_dequeue ========
 */
#define FVID_dequeue(giochan,bufp) \
            GIO_submit(giochan,FVID_DEQUEUE,bufp,NULL,NULL)
/*
 *  ======== FVID_exchange ========
 */       
#define FVID_exchange(giochan,bufp) \
            GIO_submit(giochan,FVID_EXCHANGE,bufp,NULL,NULL)
/*
 *  ======== FVID_alloc ========
 */
#define FVID_alloc(giochan,bufp) \
        GIO_submit(giochan,FVID_ALLOC,bufp,NULL,NULL)
/*
 *  ======== FVID_free ========
 */
#define FVID_free(giochan,bufp) \
        GIO_submit(giochan,FVID_FREE,bufp,NULL,NULL)
        
/*
 *  ======== FVID_control ========
 */             
#define FVID_control(giochan, cmd, args) \
            GIO_control(giochan, cmd, args)

#endif /*FVID_*/
