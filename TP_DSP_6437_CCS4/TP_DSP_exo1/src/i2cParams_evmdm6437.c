#include <psp_i2c.h>

// Initialization Parameters 
#define I2C_OWN_ADDR                (0x10u)
#define I2C_BUS_FREQ                (200000u)
#define I2C_INPUT_BUS_FREQ          (27000000u)
#define I2C_NUM_BITS                (8u)

// Default Initial Parameters
PSP_I2cConfig I2C_devParams =   {
  /** Driver operation mode */
  PSP_OPMODE_POLLED,
  /**< Own address (7 or 10 bit) */
  I2C_OWN_ADDR,
  /**< Number of bits/byte to be sent/received */
  I2C_NUM_BITS,
  /**< I2C Bus Frequency */
  I2C_BUS_FREQ,
  /**< Module input clock freq */
  I2C_INPUT_BUS_FREQ,
  /**< 7bit/10bit Addressing mode */
  FALSE,
  /**< Digital Loob Back (DLB) mode enabled */
  FALSE
};
