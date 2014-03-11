#include <std.h>
#include <gio.h>

#include <soc.h>
#include <cslr_sysctl.h>



// Externs 
extern void start_boucle(void);

// Local Declaration 
static CSL_SysctlRegsOvly sysModuleRegs = (CSL_SysctlRegsOvly )CSL_SYS_0_REGS;

// Video Usage Instructions:
// 1. Requires I2C driver for TVP configuration
// 2. Requires VPBE & VPFE drivers for Video record & playback
//  This function is used to Initialize the I2C Bus Driver
void I2C_INIT() {
  return;
}

void main() {
  return;
}

void tachevideo() {
  // VPSS PinMuxing 
  // CI10SEL   - No CI[1:0]                       
  // CI32SEL   - No CI[3:2]                       
  // CI54SEL   - No CI[5:4]                       
  // CI76SEL   - No CI[7:6]                       
  // CFLDSEL   - No C_FIELD                       
  // CWENSEL   - No C_WEN                         
  // HDVSEL    - CCDC HD and VD enabled           
  // CCDCSEL   - CCDC PCLK, YI[7:0] enabled       
  // AEAW      - EMIFA full address mode          
  // VPBECKEN  - VPBECLK enabled                  
  // RGBSEL    - No digital outputs               
  // CS3SEL    - LCD_OE/EM_CS3 disabled           
  // CS4SEL    - CS4/VSYNC enabled                
  // CS5SEL    - CS5/HSYNC enabled                
  // VENCSEL   - VCLK,YOUT[7:0],COUT[7:0] enabled 
  // AEM       - 8bEMIF + 8bCCDC + 8 to 16bVENC   
  sysModuleRegs -> PINMUX0 &= (0x005482A3u);
  sysModuleRegs -> PINMUX0 |= (0x005482A3u);

  // PCIEN = 0: PINMUX1 - Bit 0 
  sysModuleRegs -> PINMUX1 &= (0xFFFFFFFEu);

  sysModuleRegs -> VPSSCLKCTL = (0x18u);

  // Start of VPSS Test Application 
  start_boucle();

  return;
}
