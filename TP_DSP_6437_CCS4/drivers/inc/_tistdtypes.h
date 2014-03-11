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
**|         Copyright (c) 1998-2004 Texas Instruments Incorporated           |**
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

/** \file   _tistdtypes.h
 *  \brief  TI Standard defines for primitive "C" types only
 *
 *  This file provides TI Standard defines for primitive "C" types only
 *
 *  (C) Copyright 2004, Texas Instruments, Inc
 *
 *  \author     PSP Architecture Team
 *  \version    1.0
 */

/*
 * NOTE: This is soc specific file and will be moved to
 * directory psp\soc\arch<name>\soc<name>\src
 *
 * Each soc will have its own _tistdtypes.h file.
 */

#ifndef _TI_STD_TYPES
#define _TI_STD_TYPES


/**
 * \defgroup TIBasicTypes TI Basic Types
 *
 * All components - PAL, SRV, DDC, CSL shall use TI basic types
 * to maintain compatibility of code with all systems.
 * \n File _tistdtypes.h will adapt the types to the native compiler.
 */
/*@{*/

/*
 * This '#ifndef STD_' is needed to protect from duplicate definitions
 * of Int, Uns, etc. in DSP/BIOS v4.x (e.g. 4.90, 4.80) since these versions
 * of DSP/BIOS did not contain the '#ifndef_TI_STD_TYPES' logic.
 */
#ifndef STD_

/*
 * Aliases for standard C types
 */
typedef int                 Int;        /**< Signed base integer quanity */
typedef unsigned            Uns;        /**< This is depricated support only */
typedef char                Char;       /**< Character quantity */

/* pointer to null-terminated character sequence */
typedef char                *String;    /**< Character pointer quantity */

typedef void                *Ptr;       /**< Arbitrary (void) pointer (works for pointing to any datum) */

typedef unsigned short      Bool;       /* boolean */

#endif /* STD_ */

/*
 * Uint8, Uint16, Uint32, etc are defined to be "smallest unit of
 * available storage that is large enough to hold unsigned or integer
 * of specified size".
 */
#ifndef TRUE
  #define TRUE  1
  #define FALSE 0
#endif

/* Handle the 6x ISA */
#if defined(_TMS320C6X)
    /* Unsigned integer definitions (32bit, 16bit, 8bit) follow... */
    typedef unsigned int    Uint32;
    typedef unsigned short  Uint16;
    typedef unsigned char   Uint8;

    /* Signed integer definitions (32bit, 16bit, 8bit) follow... */
    typedef int             Int32;
    typedef short           Int16;
    typedef char            Int8;

/* Handle the 54x, 55x and 28x ISAs */
#elif defined(_TMS320C5XX) || defined(__TMS320C55X__) || defined(_TMS320C28X)
    /* Unsigned integer definitions (32bit, 16bit, 8bit) follow... */
    typedef unsigned long   Uint32;
    typedef unsigned short  Uint16;
    typedef unsigned char   Uint8;

    /* Signed integer definitions (32bit, 16bit, 8bit) follow... */
    typedef long            Int32;
    typedef short           Int16;
    typedef char            Int8;

#else
    /* Other ISAs not supported */
    #error <tistdtypes.h> is not supported for this target
#endif  /* defined(_6x_) */

/*@}*/
#endif /* _TI_STD_TYPES */
