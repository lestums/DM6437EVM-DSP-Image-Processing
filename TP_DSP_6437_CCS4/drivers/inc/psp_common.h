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

/**
 *  \file   psp_common.h
 *
 *  \brief  Generic interface definitions
 *
 *  This file contains the interfaces, data types and symbolic definitions
 *  that are common across interfaces of all device drivers and visible to
 *  the application.
 *
 *  (C) Copyright 2006, Texas Instruments, Inc
 *
 *  \author     Gaurav Makkar
 *
 *  \note       Set tabstop to 4 (:se ts=4) while viewing this file in an
 *              editor
 *
 *  \version    0.1     Gauram Makkar   Created
 *              0.2     Anant Gole      Added more error defines
 */

#ifndef _PSP_COMMON_H_
#define _PSP_COMMON_H_

typedef int     PSP_Result;

#define PSP_SOK             (0)
#define PSP_SINPROGRESS     (1)
#define PSP_E_DRIVER_INIT   (-1)
#define PSP_E_NO_MEMORY     (-2)
#define PSP_E_RESOURCES     (-3)
#define PSP_E_INVAL_STATE   (-4)
#define PSP_E_INVAL_PARAM   (-5)
#define PSP_E_NOT_SUPPORTED (-6)
#define PSP_E_IO_CANCEL_FAIL   (-7)
#define PSP_E_FIFO_NOT_ENABLED (-8)
#define PSP_E_INVALID_MODE      (-9)
#define PSP_E_INVALID_CMD       (-10)
#define PSP_E_TIMEOUT           (-11)

typedef void    *PSP_Handle;

typedef void (*PSP_AppCallback)(void *cbkContext, char *buf, int xferSize);

typedef enum
{
    PSP_OPMODE_POLLED       = (0U),
    PSP_OPMODE_INTERRUPT    = (1U),
    PSP_OPMODE_DMA          = (2U),
    PSP_OPMODE_DMAINTERRUPT = (3U)
}PSP_OpMode;


typedef enum
{
    PSP_DRIVER_STATE_DELETED,
    PSP_DRIVER_STATE_CREATED,
    PSP_DRIVER_STATE_INITIALIZED,
    PSP_DRIVER_STATE_OPENED,
    PSP_DRIVER_STATE_CLOSED,
    PSP_DRIVER_STATE_DEINITIALIZED,
    PSP_DRIVER_STATE_POWERED_DOWN
} PSP_DriverState;


#include <_tistdtypes.h>
#include <std.h>

#ifndef NULL
#define NULL 0
#endif

typedef unsigned int    Uint;   /**< Unsigned base integer quantity */

#ifndef True
#define True    TRUE
#define False   FALSE
#endif

/**
 * \defgroup PALDefines PAL Defines
 *
 *  PAL Generic Defines - used by all modules using PAL services
 *  (including Drivers)
 */
/*@{*/

/* PAL Result - return value of a function  */
typedef Int             PAL_Result;

/* Type Macros */
#define PAL_False       ((Bool)0)
#define PAL_True        ((Bool)1)

/* General Macros */
#define PAL_MAX(a,b)    ((a) > (b) ? (a) : (b))
#define PAL_MIN(a,b)    ((a) < (b) ? (a) : (b))

/* Array Dimension */
#define PAL_DIM(array)  (sizeof(array)/sizeof(array[0]))

/* Endianness */

#define PAL_MK_UINT16(high8,low8)                               \
    ((Uint16)( ((Uint16)(high8) << 8) | (Uint16)(low8) ))

#define PAL_UINT16_LOW8(a)                                      \
    ((Uint8)((a) & 0x00FF))

#define PAL_UINT16_HIGH8(a)                                     \
    ((Uint8)(((a) >> 8) & 0x00FF))

#define PAL_MK_UINT32(high16,low16)                             \
    ((Uint32)( ((Uint32)(high16) << 16) | (Uint32)(low16) ))

#define PAL_MK_UINT32_FROM8S(high8,med_high8,med_low8,low8)     \
    PAL_MK_UINT32(PAL_MK_UINT16(high8,med_high8), PAL_MK_UINT16(med_low8, low8))

#define PAL_UINT32_LOW16(u32)                                   \
    ((Uint16)((u32) & 0xFFFF))

#define PAL_UINT32_HIGH16(u32)                                  \
    ((Uint16)(((u32) >> 16) & 0xFFFF))

#define PAL_UINT32_LOW8(u32)                                    \
    ((Uint8)((u32) & 0x00FF))

#define PAL_UINT32_MED_LOW8(u32)                                \
    ((Uint8)(((u32) >> 8) & 0xFF))

#define PAL_UINT32_MED_HIGH8(u32)                               \
    ((Uint8)(((u32) >> 16) & 0xFF))

#define PAL_UINT32_HIGH8(u32)                                   \
    ((Uint8)(((u32) >> 24) & 0xFF))

#define PAL_SWAP_UINT16(w)      \
    (PAL_MK_UINT16(PAL_UINT16_LOW8(w), PAL_UINT16_HIGH8(w)))

#define PAL_SWAP_UINT32(u32)                \
    (PAL_MK_UINT32_FROM8S(                  \
        PAL_UINT32_LOW8(u32),               \
        PAL_UINT32_MED_LOW8(u32),           \
        PAL_UINT32_MED_HIGH8(u32),          \
        PAL_UINT32_HIGH8(u32)))

/** Endian Utility Macros
 * PAL_UINT16_LE(w) converts a Little-Endian 16bit word to current endian word
 * PAL_UINT16_BE(w) converts a Big-Endian 16bit word to current endian word
 * PAL_UINT32_LE(d) converts a Little-Endian 32bit dword to current endian dword
 * PAL_UINT32_BE(d) converts a Big-Endian 32bit dword to current endian dword
 */

#ifdef PAL_NATIVE_ENDIAN_BIG
/* Native CPU accesses to memory locations are big-endian style */
#define PAL_UINT16_LE(w)    PAL_SWAP_UINT16(w)
#define PAL_UINT16_BE(w)    (w)
#define PAL_UINT32_LE(d)    PAL_SWAP_UINT32(d)
#define PAL_UINT32_BE(d)    (d)

#else
/* Native CPU accesses to memory locations are little-endian style */
#define PAL_UINT16_LE(w)    (w)
#define PAL_UINT16_BE(w)    PAL_SWAP_UINT16(w)
#define PAL_UINT32_LE(d)    (d)
#define PAL_UINT32_BE(d)    PAL_SWAP_UINT32(d)

#endif /* Endian switch */

/**
 * \defgroup PALErrorCodes PAL Error Codes
 *
 * PAL Error code bit fields follow a standard format. This format is used by
 * all PAL components, Services and Device Drivers.
 *
 * The following bitfield diagram depicts the PAL error code format:
 * \n
 * |<----------------32----------------->|
 * \n
 * |1(A)| 3(B) |  4(C) |    8(D)   |   8(E)  |   8(F)  |
 * - A - MSB - Set if Error / 0 if Success
 * - B - Error level - 0=Informational, 1=Warning, 2=Minor, 3=Major, 4=Critical
 * - C - PSP Architecture Component - 0=Reserved, 1=CSL, 2=Driver, 3=PAL, 4=SRV etc
 * - D - Device specific - eg Instance Id of DDC, PAL component (e.g. OSMEM etc)
 * - E,F - Error number - based upon implementation.
 */

/*@{*/

/** Error severity levels  */
#define PAL_INFO                (0)
#define PAL_WARNING             (1)
#define PAL_MINOR_ERROR         (2)
#define PAL_MAJOR_ERROR         (3)
#define PAL_CRITICAL_ERROR      (4)

/** PAL Error Sources (PSP Architectural Components) */
#define PAL_ERROR_SRC_CSL       (0)
#define PAL_ERROR_SRC_DRV       (1)
#define PAL_ERROR_SRC_PAL       (2)
#define PAL_ERROR_SRC_SRV       (3)

#define PAL_ERROR_FLAG          (0x80000000)    /**< PAL Error occured sentinel flag */

/** Successful Return Code for PAL_Result */

#define PAL_SOK                 (0x0)
#define PAL_SINPROGRESS         (0x1)


/**
 * \note PAL Error bit manipulation masks and shift values
 */
#define PAL_ERROR_SEVERITY_SHIFT    (28)
#define PAL_ERROR_SEVERITY_MASK     (0x70000000)

#define PAL_ERROR_SRC_SHIFT         (24)
#define PAL_ERROR_SRC_MASK          (0x0F000000)

#define PAL_ERROR_QUAL_SHIFT        16
#define PAL_ERROR_QUAL_MASK         (0x00FF0000)

#define PAL_ERROR_NUM_SHIFT         (0)
#define PAL_ERROR_NUM_MASK          (0x0000FFFF)

/**
 * \brief PAL_ERROR() macro composes a final 32bit error code per the
 * above described format. It inputs the severity, source of error,
 * source qualifier and the specific error number of interest
 *
 * \sa PAL_ERROR_CSLSTATUS()
 */
#define PAL_ERROR(severity, src, qual, num) \
    ( PAL_ERROR_FLAG | \
    (PAL_ERROR_SEVERITY_MASK & (severity << PAL_ERROR_SEVERITY_SHIFT)) | \
    (PAL_ERROR_SRC_MASK & (src << PAL_ERROR_SRC_SHIFT)) | \
    (PAL_ERROR_QUAL_MASK & (qual << PAL_ERROR_QUAL_SHIFT)) | \
    (PAL_ERROR_NUM_MASK & (num << PAL_ERROR_NUM_SHIFT)))

/**
 * \brief The following 4 macros allow to extract relevant portions of
 * the 32bit PAL error code.
 */
#define PAL_ERROR_NUM(code)         ((code & PAL_ERROR_NUM_MASK) >> PAL_ERROR_NUM_SHIFT)
#define PAL_ERROR_QUAL(code)        ((code & PAL_ERROR_QUAL_MASK) >> PAL_ERROR_QUAL_SHIFT)
#define PAL_ERROR_SRC(code)         ((code & PAL_ERROR_SRC_MASK) >> PAL_ERROR_SRC_SHIFT)
#define PAL_ERROR_SEVERITY(code)    ((code & PAL_ERROR_SEVERITY_MASK) >> PAL_ERROR_SEVERITY_SHIFT)

/**
 * \brief   PAL_ERROR_CSLSTATUS() macros constructs a fully embodied
 *      32bit PAL error code, given a 16bit CSL_Status number
 * \note    CSL Errors are always ascribed severity level MAJOR.
 */
#define PAL_ERROR_CSLSTATUS(cslerr) \
    PAL_ERROR(PAL_MAJOR_ERROR, PAL_ERROR_SRC_CSL, 0, (cslerr & 0x7F))

/*@}*/
/*@}*/

#endif  /* _PSP_COMMON_H_ */

