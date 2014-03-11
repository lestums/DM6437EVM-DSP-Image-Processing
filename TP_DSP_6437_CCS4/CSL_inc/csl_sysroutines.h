/*  ============================================================================
 *   Copyright (c) Texas Instruments Inc 2002, 2003, 2004, 2005                 
 *                                                                              
 *   Use of this software is controlled by the terms and conditions found in the
 *   license agreement under which this software has been supplied.             
 *   ===========================================================================
 */

#ifndef _CSL_SYSROUTINES_H
#define _CSL_SYSROUTINES_H
#include <cslr_chip.h>


inline Uint32 CSL_sysGlobalInterruptDisable()
{
    extern cregister volatile unsigned int TSR;
    asm(" DINT"); 
    return (TSR & 0x00000002);
}

inline void CSL_sysGlobalInterruptRestore(Uint32 restoreVal)
{
    extern cregister volatile unsigned int TSR;
    TSR |= restoreVal;
    asm(" RINT"); 
}
#endif /*_CSL_SYSROUTINES_H*/
