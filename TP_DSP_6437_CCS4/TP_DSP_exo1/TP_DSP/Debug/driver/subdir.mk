################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LIB_SRCS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/edma3_drv_bios_dbg.lib \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/edma3_drv_bios_rel.lib \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/edma3_rm_bios_dbg.lib \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/edma3_rm_bios_rel.lib \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/timer.lib 

C_SRCS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_cfg.c \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_cs.c \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_init.c 

OBJS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cfg.obj \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cs.obj \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_init.obj 

C_DEPS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cfg.pp \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cs.pp \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_init.pp 

OBJS__QTD += \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\bios_edma3_sample_cfg.obj" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\bios_edma3_sample_cs.obj" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\bios_edma3_sample_init.obj" 

C_DEPS__QTD += \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\bios_edma3_sample_cfg.pp" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\bios_edma3_sample_cs.pp" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\bios_edma3_sample_init.pp" 

C_SRCS_QUOTED += \
"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_cfg.c" \
"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_cs.c" \
"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_init.c" 


# Each subdirectory must supply rules for building sources it contributes
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cfg.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_cfg.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cfg.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cs.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_cs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_cs.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_init.obj: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver/bios_edma3_sample_init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/bios_edma3_sample_init.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


