################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
OBJS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/fonctions.obj \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/i2cParams_evmdm6437.obj \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/main.obj \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/psp_i2c_interface.obj \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/tvp5146_extDecoder.obj 

C_DEPS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/fonctions.pp \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/i2cParams_evmdm6437.pp \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/main.pp \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/psp_i2c_interface.pp \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/tvp5146_extDecoder.pp 

OBJS__QTD += \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\fonctions.obj" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\i2cParams_evmdm6437.obj" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\main.obj" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\psp_i2c_interface.obj" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\tvp5146_extDecoder.obj" 

C_DEPS__QTD += \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\fonctions.pp" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\i2cParams_evmdm6437.pp" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\main.pp" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\psp_i2c_interface.pp" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\tvp5146_extDecoder.pp" 


# Each subdirectory must supply rules for building sources it contributes
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/fonctions.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src/fonctions.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/fonctions.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/i2cParams_evmdm6437.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src/i2cParams_evmdm6437.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/i2cParams_evmdm6437.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/main.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/psp_i2c_interface.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src/psp_i2c_interface.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/psp_i2c_interface.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/tvp5146_extDecoder.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src/tvp5146_extDecoder.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/src" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/tvp5146_extDecoder.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


