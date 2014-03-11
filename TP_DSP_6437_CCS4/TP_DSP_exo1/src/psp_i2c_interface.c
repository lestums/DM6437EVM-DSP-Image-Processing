#include <std.h>
#include <gio.h>

#include "psp_common.h"
#include "psp_i2c.h"
#include "psp_i2cApi.h"
#include "psp_i2c_interface.h"

PSP_Handle i2cHandle1 = NULL;

#define I2C_OWN_ADDR        (0x10u)
#define I2C_BUS_FREQ        (20000u)
#define I2C_INPUT_BUS_FREQ      (27000000u)
#define I2C_NUM_BITS        (8u)

static Uint32 i2cInstanceId =   0x0;

static void delay_loop (volatile Uint32 delay) {
  volatile Uint32 out_count = 0;
  volatile Uint32 in_count = 0;

  for(out_count = 0; out_count < delay; out_count ++) {
    for(in_count = 0; in_count < 100; in_count ++) {
    }
  }
}

Int i2c_init() {
  Bool retVal = TRUE;

  if ( TRUE == retVal ) {
    // open an instance
    i2cHandle1 = PSP_i2cOpen(i2cInstanceId, NULL, NULL);
    if ( i2cHandle1 == NULL ) {
      PSP_i2cDelete(i2cInstanceId);
      retVal = FALSE;
    }
  }

  return retVal;
}

// I2C Write Function to write data to the Slave device
Bool i2c_writeReg(Uint8 SlaveAddr,Uint8 *buffer, Uint32 length) {
  Int retCode = -1;
  Bool retVal= FALSE;
  // Write to Slave Device
  if( NULL != buffer ) {
    delay_loop(100);
    retCode = PSP_i2cTransfer( i2cHandle1, SlaveAddr,
                               buffer, length, PSP_I2C_DEFAULT_WRITE,
                               -1, NULL);
  }
  if(retCode == length) {
    retVal = TRUE;
  }
  return retVal;
}

// Function used to read the I2C data from the I2C device
Bool i2c_readReg(Uint8 SlaveAddr,Uint8 *buffer, Uint32 length) {
  Int retCode = -1;
  Bool retVal = FALSE;
  
  // Write Subaddress of Slave Device
  if ( NULL != buffer ) {
    delay_loop(100);
    retCode = PSP_i2cTransfer( i2cHandle1,SlaveAddr,
                               &buffer[0],1u,PSP_I2C_DEFAULT_WRITE,
                               -1, NULL );
  }
  
  // Read from Slave Device
  if( retCode == 1u ) {
    delay_loop(100);
    retCode = PSP_i2cTransfer( i2cHandle1,SlaveAddr,&buffer[1],
                               (length - 1u),PSP_I2C_DEFAULT_READ,
                               -1, NULL);
  }
  if (retCode == (length - 1u)) {
    retVal = TRUE;
  }
  return retVal;
}

// Function used to Deinitialize I2C
Bool i2c_deInit() {
  Bool retVal = FALSE;
  // Close driver and delete it
  if (PSP_SOK == PSP_i2cClose(i2cHandle1)) {
    retVal = TRUE;
  }
  if (retVal == TRUE) {
    // Delete the I2C Instance
    if (PSP_SOK != PSP_i2cDelete(i2cInstanceId)) {
      retVal = FALSE;
    }
  }
  return retVal;
}
