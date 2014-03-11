/*  ============================================================================
 *  Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005
 *
 *  Use of this software is controlled by the terms and conditions found in the
 *  license agreement under which this software has been supplied.
 *  ============================================================================
 */
/** ============================================================================
 *   @file  csl_version.h
 *
 *   @path  $(CSLPATH)\inc
 *
 *   @desc  This file contains the version number of different chips
 *
 */
/* =============================================================================
 *  Revision History
 *  ===============
 *  21-Sep-2006 NG  File Created
 * =============================================================================
 */

#ifndef _CSL_VERSION_H_
#define _CSL_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <tistdtypes.h>

/* 0xAABBCCDD -> Arch (AA); API Changes (BB); Major (CC); Minor (DD) */
#define CSL_VERSION_ID          (0x01000000)
#define CSL_VERSION_STR         "@(#) CSL Revision: 1.00.00.00;"

#define CSL_CHIP_ID             (0x64)
#define CSL_CHIP_STR            "DM6437 PG 1.1"

/**
  @brief    Retrieves the version ID
*/
Uint32 CSL_versionGetID (
    void
);


/**
  @brief    Retrieves the version string
*/
const char *
    CSL_versionGetStr (
        void
);


#ifdef __cplusplus
}
#endif

#endif /* _CSL_VERSION_H_ */

