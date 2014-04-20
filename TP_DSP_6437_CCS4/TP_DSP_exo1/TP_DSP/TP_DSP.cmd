-l TP_DSPcfg.cmd

SECTIONS {
  .L1Buffer > L1DSRAM
  .L2Buffer > IRAM
  .ExtBuffer > DDR2 
  .CACHE_L1D > CACHE_L1D
}

