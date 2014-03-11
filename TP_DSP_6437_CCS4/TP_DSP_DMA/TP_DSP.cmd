-l TP_DSPcfg.cmd

SECTIONS {
  .L1Buffer > L1DSRAM
  .L2Buffer > IRAM
  .ExtBuffer > DDR2
}

