#include "psp_i2c_interface.h"
#include "psp_tvp5146_extVidDecoder.h"
#include "pal_osWait.h"

// TVP device object
static PSP_VPFE_TVP5146_Object   tvp5146Object;
                
static Bool setTVP5146Control( PSP_VPFE_TVP5146_Object *tvp5146handle,
                               PSP_VPFE_TVP5146_ControlParams *cntrlParamSC );
static Bool getTVP5146Status(Ptr statusGS);
static Bool setTVP5146Mode(Uint32 modeSTM);
static Bool setTVP5146Format(Uint32 formatSTF);
static Bool setTVP5146Sync656(Bool enable656Sync);
static Int TVP5146Config( PSP_VPFE_TVP5146_Object *tvp5146handle,
                          PSP_VPFE_TVP5146_ConfigParams *tvp5146configParams);
//  TVP5146_Open
EVD_Handle PSP_VPFE_TVP5146_Open() {
  EVD_Handle handle = NULL;
  if(TRUE == i2c_init()) {
    handle = &tvp5146Object;
  }   
  return handle;
}

// TVP5146 Close function
Int PSP_VPFE_TVP5146_Close(EVD_Handle handle) {   
  Int result = EVD_FAIL;
  if(NULL==handle) {
    result = EVD_FAIL;
  } else {
    if( TRUE == i2c_deInit() ) {
      handle = NULL;
      result = EVD_SUCCESS;
    }   
  }   
  return result;
}

//  TVP5146 Control Function
Int PSP_VPFE_TVP5146_Control(EVD_Handle handle,Uint32 Cmd,Ptr CmdArg ) {
  PSP_VPFE_TVP5146_Object    *extVDhandle    = NULL;
  PSP_VPFE_TVP5146_ConfigParams  *extVDconfigParams  = NULL;
  PSP_VPFE_TVP5146_StatusParams  *extVDstatusParams  = NULL;
  PSP_VPFE_TVP5146_ControlParams *extVDCtrlParams  = NULL;
  PSP_VPFE_TVP5146_StatusParams  status;
  Int result = EVD_SUCCESS;

  // Validate the Input parameters
  if( (NULL == handle) || (NULL == CmdArg) ) {
    result = EVD_FAIL;  
  } else {   
    extVDhandle = (PSP_VPFE_TVP5146_Object *)handle;
    switch(Cmd) {
      // To configure the External Video Decoder
      case PSP_VPSS_EXT_VIDEO_DECODER_CONFIG :
        extVDconfigParams  = (PSP_VPFE_TVP5146_ConfigParams *)CmdArg;
        if(NULL!= extVDconfigParams) {
          result = TVP5146Config(extVDhandle,extVDconfigParams);
        }
        break;

      // To get the Status of status params   
      case PSP_VPSS_EXT_VIDEO_DECODER_STATUS :   
        extVDstatusParams = (PSP_VPFE_TVP5146_StatusParams *)CmdArg;
        if(NULL != extVDstatusParams) {
          if(TRUE == getTVP5146Status(&status)) {
            extVDstatusParams->fieldRate     = status.fieldRate;
            extVDstatusParams->hLock       = status.hLock;
            extVDstatusParams->vLock       = status.vLock;
            extVDstatusParams->lostLock        = status.lostLock;
            extVDstatusParams->colSubCarrier_lock = status.colSubCarrier_lock;
          }
        }           
        break;  

      // To control the Control parameters of Video Decoder 
      case PSP_VPSS_EXT_VIDEO_DECODER_CONTROL:
        extVDCtrlParams = (PSP_VPFE_TVP5146_ControlParams*)CmdArg;
        if(NULL != extVDCtrlParams) {
          if(FALSE == setTVP5146Control(extVDhandle,extVDCtrlParams)) {
            result = EVD_FAIL;  
          }   
        }   
        break;

      default :
        result = EVD_FAIL;
        break;        
    }               
  }
  return result;
}   

static Int TVP5146Config( PSP_VPFE_TVP5146_Object *tvp5146handle,
                        PSP_VPFE_TVP5146_ConfigParams *tvp5146configParams ) {
  Int result = EVD_SUCCESS;
    
  if((NULL == tvp5146handle)||(NULL == tvp5146configParams)) {
    result = EVD_FAIL;
  } else {   
    // Set Video Decoder Mode  
    if(TRUE == setTVP5146Mode(tvp5146configParams->mode)) {
      tvp5146handle->config.mode  = tvp5146configParams->mode;
    } else {
      result = FALSE;
    }

    // Set Video Decoder Format 
    if ( TRUE ==setTVP5146Format(tvp5146configParams->format) ) {
      tvp5146handle->config.format = tvp5146configParams->format;
    } else {
      result = FALSE;
    }

    // Set Video Decoder SYNC656    
    if ( TRUE == setTVP5146Sync656(tvp5146configParams->enable656Sync)) {
      tvp5146handle->config.enable656Sync = tvp5146configParams->enable656Sync;
    } else {
      result = FALSE;
    }
  }   
  return result;
}

// To set the TVP6146 mode
Bool setTVP5146Mode(Uint32 modeSTM ) {
  Bool resultSTM      = FALSE;
  Uint8 videoStandardSTM  = 0;
  Uint8 bufferSTM[2]    = {0};

  PAL_osWaitMsecs(100u);

  if ( TRUE == i2c_readReg( I2C_TVP_SLAVE_ADDR, bufferSTM, 2u) ) {
    bufferSTM[0] = OUTPUT_FORMATTER_1_REG;
    bufferSTM[1] |= ((Uint8)((modeSTM & 0x8) << 4)); // 4th-bit for squre pixel sampling 
    if(TRUE == i2c_writeReg( I2C_TVP_SLAVE_ADDR, bufferSTM, 2u)) {
      resultSTM = TRUE;
    }
  }

  if ( resultSTM == TRUE ) {
    resultSTM = FALSE;
    bufferSTM[0] = VIDEO_STANDARD_REG;
    bufferSTM[1] = (Uint8)( modeSTM & 0x7);
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR, bufferSTM, 2u)) {
      resultSTM = TRUE;
    }
  }

  if ( resultSTM == TRUE )  {
    resultSTM = FALSE;
    if ( PSP_VPFE_TVP5146_MODE_AUTO == videoStandardSTM ) {
      bufferSTM[0] = AUTOSWITCH_MASK_REG;
      bufferSTM[1] = 0x3F; // enable autoswitch for all standards 
      if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,bufferSTM,2u)) {
        resultSTM = TRUE;
      }
    } else {
      bufferSTM[0] = AUTOSWITCH_MASK_REG;
      bufferSTM[1] = 0x23; // For NTSC and PAL 
      if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,bufferSTM,2u)) {
        resultSTM = TRUE;
      }
    }
  }

  return(resultSTM);
}

// To set the TVP6146 Format
Bool setTVP5146Format(Uint32 formatSTF) {
  Bool  resultSTF   = FALSE;
  Uint8 bufferSTF[2]  = {0};

  PAL_osWaitMsecs(100u);

  if (PSP_VPFE_TVP5146_FORMAT_COMPOSITE == formatSTF) {
    bufferSTF[0]  = INPUT_SELECT_REG;
    bufferSTF[1]  = 0x05;
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,bufferSTF,2u)) {
      resultSTF   = TRUE;
    }
  } else if (PSP_VPFE_TVP5146_FORMAT_SVIDEO == formatSTF ) {
    bufferSTF[0]  = INPUT_SELECT_REG;
    bufferSTF[1]  = 0x46;
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,bufferSTF,2u)) {
      resultSTF   = TRUE;
    }
  } else {
    resultSTF = FALSE;
  }

  return(resultSTF);
}

// brief To set the TVP6146 Sync 656  
Bool setTVP5146Sync656(Bool enable656Sync) {
  Bool  resultSTS         = FALSE;
  Uint8 output1BufferSTS[2]     = {0};
  Uint8 output2BufferSTS[2]     = {0};
  Uint8 lumProcCntrlBufferSTS[2]  = {0};
  Uint8 output4BufferSTS[2]     = {0};
  Uint8 chrProcCntrlBufferSTS[2]  = {0};
  Uint8 syncCntBufferSTS[2]     = {0};

  PAL_osWaitMsecs(100u);

  output2BufferSTS[0]       = OUTPUT_FORMATTER_2_REG;
  output2BufferSTS[1]       = 0x11;

  lumProcCntrlBufferSTS[0]    = LUMINANCE_PROCESSING_CONTROL_3_REG;
  lumProcCntrlBufferSTS[1]    = 0x00;

  chrProcCntrlBufferSTS[0]    = CHROMINANCE_PROCESSING_CONTROL_2_REG;
  chrProcCntrlBufferSTS[1]    = 0x04;

  switch(enable656Sync) {
    case ENABLE_SYNC_656:
      output1BufferSTS[0]   = OUTPUT_FORMATTER_1_REG;
      output1BufferSTS[1]   = 0x40;

      output4BufferSTS[0]   = OUTPUT_FORMATTER_4_REG;
      output4BufferSTS[1]   = 0xFF;

      syncCntBufferSTS[0]   = SYNC_CONTROL_REG;
      syncCntBufferSTS[1]   = 0x00;
      break;
    case DISABLE_SYNC_656:
      output1BufferSTS[0]   = OUTPUT_FORMATTER_1_REG;
      output1BufferSTS[1]   = 0x43;

      output4BufferSTS[0]   = OUTPUT_FORMATTER_4_REG;
      output4BufferSTS[1]   = 0xAF;

      syncCntBufferSTS[0]   = SYNC_CONTROL_REG;
      syncCntBufferSTS[1]   = 0x1E;

      break;
    
    default:
      break;
  }

  if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,output1BufferSTS,2u)) {
    resultSTS = TRUE;
  }

  if(resultSTS == TRUE) {
    resultSTS = FALSE;
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,output4BufferSTS,2u)) {
      resultSTS = TRUE;
    }
  }

  if ( resultSTS == TRUE) {
    resultSTS = FALSE;
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,lumProcCntrlBufferSTS,2u)) {
      resultSTS = TRUE;
    }
  }

  if ( resultSTS == TRUE ) {
    resultSTS = FALSE;
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,chrProcCntrlBufferSTS,2u)) {
      resultSTS = TRUE;
    }
  }

  if ( resultSTS == TRUE) {
    resultSTS = FALSE;
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,syncCntBufferSTS,2u)) {
      resultSTS = TRUE;
    }
  }

  if ( resultSTS == TRUE) {
    resultSTS = FALSE;
    if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,output2BufferSTS,2u)) {
      resultSTS = TRUE;
    }
  }

  return(resultSTS);
}

Bool getTVP5146Status(Ptr statusGS) {
  Bool  resultGS      = FALSE;
  Uint8 bufferGS[2]     = {0};
  PSP_VPFE_TVP5146_StatusParams * statusParamGS;
  
  if (NULL != statusGS) {
    statusParamGS = (PSP_VPFE_TVP5146_StatusParams *)statusGS;
    bufferGS[0] = STATUS_1_REG;
    if(TRUE == i2c_readReg(I2C_TVP_SLAVE_ADDR,bufferGS,2u)) {
      statusParamGS->fieldRate = (Uint8)((bufferGS[1] & 0x20u) ? 50u: 60u);
      statusParamGS->hLock = (Uint8)((bufferGS[1] & 0x02u) >> 1);
      statusParamGS->vLock = (Uint8)((bufferGS[1] & 0x04u) >> 2);
      statusParamGS->lostLock = (Uint8)((bufferGS[1] & 0x10u) >> 4);
      statusParamGS->colSubCarrier_lock = (Uint8)((bufferGS[1] & 0x08u) >> 3);
      resultGS = TRUE;
    }
  }
  return(resultGS);
}

// To set the TVP6146 control operation
Bool setTVP5146Control( PSP_VPFE_TVP5146_Object *tvp5146Handle,
                        PSP_VPFE_TVP5146_ControlParams *cntrlParamSC ) {
  Bool  resultSC        = FALSE;
  Uint8 controlBufferSC[2]  = {0};
  
  if((NULL==tvp5146Handle)||(NULL == cntrlParamSC)) {
    resultSC = FALSE;
  } else {     
    // Set AFE Gain 
    resultSC = FALSE;
    controlBufferSC[0]  = AFE_GAIN_CONTROL_REG;
    controlBufferSC[1]  = (Uint8)(cntrlParamSC->autoGain);
    if ( TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR, controlBufferSC, 2u) ) {
      tvp5146Handle->control.autoGain = cntrlParamSC->autoGain;
      resultSC = TRUE;
    }

    // Set Luminance Brightness 
    if ( TRUE == resultSC ) {
      controlBufferSC[0]  = LUMINANCE_BRIGHTNESS_REG;
      controlBufferSC[1]  = cntrlParamSC->brightness;
      if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,controlBufferSC,2u)) {
        tvp5146Handle->control.brightness = cntrlParamSC->brightness;
        resultSC = TRUE;
      }
    }

    // Set Luminance Contrast 
    if(TRUE == resultSC) {
      resultSC = FALSE;
      controlBufferSC[0]  = LUMINANCE_CONTRAST_REG;
      controlBufferSC[1]  = cntrlParamSC->contrast;
      if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,controlBufferSC,2u)) {
        tvp5146Handle->control.contrast = cntrlParamSC->contrast;
        resultSC = TRUE;
      }
    }

    // Set Chrominance Hue 
    if(TRUE == resultSC ) {
      resultSC = FALSE;
      controlBufferSC[0]  = CHROMINANCE_HUE_REG;
      controlBufferSC[1]  = cntrlParamSC->hue;
      if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,controlBufferSC,2u)) {
        tvp5146Handle->control.hue = cntrlParamSC->hue;
        resultSC = TRUE;
      }
    }

    // Set Chrominance Saturation 
    if(TRUE == resultSC ) {
      resultSC = FALSE;
      controlBufferSC[0]  = CHROMINANCE_SATURATION_REG;
      controlBufferSC[1]  = cntrlParamSC->saturation;
      if(TRUE == i2c_writeReg(I2C_TVP_SLAVE_ADDR,controlBufferSC,2u)) {
        tvp5146Handle->control.saturation = cntrlParamSC->saturation;
        resultSC = TRUE;
      }
    }
  }

  return(resultSC);
}

