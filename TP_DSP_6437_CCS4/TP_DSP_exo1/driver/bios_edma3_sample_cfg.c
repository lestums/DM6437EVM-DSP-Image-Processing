/* DM643X Specific EDMA3 Information */
#ifdef  DM643X_SOC_BUILD

/** Number of Transfer Controllers available */
#define EDMA3_NUM_TC 3u

/** Interrupt no. for Transfer Completion */
#define EDMA3_CC_XFER_COMPLETION_INT                    36u

/** Interrupt no. for CC Error */
#define EDMA3_CC_ERROR_INT                              37u

/** Interrupt no. for TCs Error */
#define EDMA3_TC0_ERROR_INT                             38u
#define EDMA3_TC1_ERROR_INT                             39u
#define EDMA3_TC2_ERROR_INT                             40u
#define EDMA3_TC3_ERROR_INT                             0u
#define EDMA3_TC4_ERROR_INT                             0u
#define EDMA3_TC5_ERROR_INT                             0u
#define EDMA3_TC6_ERROR_INT                             0u
#define EDMA3_TC7_ERROR_INT                             0u

#endif  /* #ifdef DM643X_SOC_BUILD */


/* Variable which will be used internally for referring number of TCs. */
unsigned int numEdma3Tc = EDMA3_NUM_TC;

/**
 * Variable which will be used internally for referring transfer completion
 * interrupt.
 */
unsigned int ccXferCompInt = EDMA3_CC_XFER_COMPLETION_INT;

/**
 * Variable which will be used internally for referring channel controller's
 * error interrupt.
 */
unsigned int ccErrorInt = EDMA3_CC_ERROR_INT;

/**
 * Variable which will be used internally for referring transfer controllers'
 * error interrupts.
 */
unsigned int tcErrorInt[8] =    {
                                EDMA3_TC0_ERROR_INT, EDMA3_TC1_ERROR_INT,
                                EDMA3_TC2_ERROR_INT, EDMA3_TC3_ERROR_INT,
                                EDMA3_TC4_ERROR_INT, EDMA3_TC5_ERROR_INT,
                                EDMA3_TC6_ERROR_INT, EDMA3_TC7_ERROR_INT
                                };

/* End of File */

