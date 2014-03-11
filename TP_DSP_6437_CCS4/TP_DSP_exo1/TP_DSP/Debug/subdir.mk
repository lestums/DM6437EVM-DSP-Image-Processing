################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LIB_SRCS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPBE/lib/vpbe_bios_drv_dbg.lib \
C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPBE/lib/vpbe_bios_drv_rel.lib \
C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPFE/lib/vpfe_bios_drv_dbg.lib \
C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPFE/lib/vpfe_bios_drv_rel.lib 

GEN_SRCS += \
./TP_DSPcfg.cmd \
./TP_DSPcfg.s?? \
./TP_DSPcfg_c.c 

GEN_CMDS += \
./TP_DSPcfg.cmd 

OBJS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg.obj \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg_c.obj 

GEN_MISC_FILES += \
./TP_DSPcfg.h \
./TP_DSPcfg.h?? \
./TP_DSP.cdb \
./vpbe_bios_drv_dbg.out \
./vpbe_bios_drv_rel.out \
./vpfe_bios_drv_dbg.out \
./vpfe_bios_drv_rel.out 

S??_DEPS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg.pp 

C_DEPS += \
C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg_c.pp 

OBJS__QTD += \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\TP_DSPcfg.obj" \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\TP_DSPcfg_c.obj" 

S??_DEPS__QTD += \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\TP_DSPcfg.pp" 

GEN_SRCS__QTD += \
".\TP_DSPcfg.cmd" \
".\TP_DSPcfg.s??" \
".\TP_DSPcfg_c.c" 

C_DEPS__QTD += \
"C:\tmp\TP_DSP_6437\TP_DSP_6437\TP_DSP_exo1\Debug\TP_DSPcfg_c.pp" 

GEN_MISC_FILES__QTD += \
".\TP_DSPcfg.h" \
".\TP_DSPcfg.h??" \
".\TP_DSP.cdb" \
".\vpbe_bios_drv_dbg.out" \
".\vpbe_bios_drv_rel.out" \
".\vpfe_bios_drv_dbg.out" \
".\vpfe_bios_drv_rel.out" 

GEN_CMDS_QUOTED += \
-l"./TP_DSPcfg.cmd" 


# Each subdirectory must supply rules for building sources it contributes
TP_DSPcfg.cmd: C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP.tcf
	@echo 'Building file: $<'
	@echo 'Invoking: TConf Script Compiler'
	"C:/CCSv4/xdctools_3_20_03_63/tconf" -b -Dconfig.importPath="C:/CCSv4/bios_5_41_07_24/packages;C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1;C:/CCStudio_v3.3/bios_5_31_02/packages/ti/bios/examples/common;C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1;C:/CCStudio_v3.3/bios_5_31_02/packages/ti/bios/examples/common;;" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TP_DSPcfg.s??: TP_DSPcfg.cmd
TP_DSPcfg_c.c: TP_DSPcfg.cmd
TP_DSPcfg.h: TP_DSPcfg.cmd
TP_DSPcfg.h??: TP_DSPcfg.cmd
TP_DSP.cdb: TP_DSPcfg.cmd

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg.obj: ./TP_DSPcfg.s?? $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg_c.obj: ./TP_DSPcfg_c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCSv4/ccsv4/tools/compiler/c6000/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/bios/include" --include_path="C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/include/c6000" --include_path="C:/CCSv4/xdais_7_10_00_06/packages/ti/xdais" --include_path="c:/CCSTUD~1.3/C6000/csl/include" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/pal_os/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/i2c/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/previewer/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/inc" --include_path="C:/tmp/TP_DSP_6437/TP_DSP_6437/CSL_inc" --diag_warning=225 --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP_DSPcfg_c.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

vpbe_bios_drv_dbg.out: C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPBE/lib/vpbe_bios_drv_dbg.lib $(OBJS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	$(shell echo -mv6400+ > "ccsLinker.opt")
	$(shell echo -g >> "ccsLinker.opt")
	$(shell echo --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" >> "ccsLinker.opt")
	$(shell echo --diag_warning=225 >> "ccsLinker.opt")
	$(shell echo --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" >> "ccsLinker.opt")
	$(shell echo -z >> "ccsLinker.opt")
	$(shell echo -m"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP-DSP.map" >> "ccsLinker.opt")
	$(shell echo --warn_sections >> "ccsLinker.opt")
	$(shell echo -i"C:/CCSv4/ccsv4/tools/compiler/c6000/lib" -i"C:/CCSv4/ccsv4/tools/compiler/c6000/include" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/lib/c6000" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/bios/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1" -i"c:/CCSTUD~1.3/C6000/csl/lib" -i"C:/CCStudio_v3.3/c6400/imglib/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" >> "ccsLinker.opt")
	$(shell echo --reread_libs >> "ccsLinker.opt")
	$(shell echo --rom_model >> "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell type "ccsObjs.opt" >> "ccsLinker.opt")
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

vpbe_bios_drv_rel.out: C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPBE/lib/vpbe_bios_drv_rel.lib $(OBJS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	$(shell echo -mv6400+ > "ccsLinker.opt")
	$(shell echo -g >> "ccsLinker.opt")
	$(shell echo --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" >> "ccsLinker.opt")
	$(shell echo --diag_warning=225 >> "ccsLinker.opt")
	$(shell echo --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" >> "ccsLinker.opt")
	$(shell echo -z >> "ccsLinker.opt")
	$(shell echo -m"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP-DSP.map" >> "ccsLinker.opt")
	$(shell echo --warn_sections >> "ccsLinker.opt")
	$(shell echo -i"C:/CCSv4/ccsv4/tools/compiler/c6000/lib" -i"C:/CCSv4/ccsv4/tools/compiler/c6000/include" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/lib/c6000" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/bios/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1" -i"c:/CCSTUD~1.3/C6000/csl/lib" -i"C:/CCStudio_v3.3/c6400/imglib/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" >> "ccsLinker.opt")
	$(shell echo --reread_libs >> "ccsLinker.opt")
	$(shell echo --rom_model >> "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell type "ccsObjs.opt" >> "ccsLinker.opt")
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

vpfe_bios_drv_dbg.out: C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPFE/lib/vpfe_bios_drv_dbg.lib $(OBJS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	$(shell echo -mv6400+ > "ccsLinker.opt")
	$(shell echo -g >> "ccsLinker.opt")
	$(shell echo --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" >> "ccsLinker.opt")
	$(shell echo --diag_warning=225 >> "ccsLinker.opt")
	$(shell echo --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" >> "ccsLinker.opt")
	$(shell echo -z >> "ccsLinker.opt")
	$(shell echo -m"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP-DSP.map" >> "ccsLinker.opt")
	$(shell echo --warn_sections >> "ccsLinker.opt")
	$(shell echo -i"C:/CCSv4/ccsv4/tools/compiler/c6000/lib" -i"C:/CCSv4/ccsv4/tools/compiler/c6000/include" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/lib/c6000" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/bios/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1" -i"c:/CCSTUD~1.3/C6000/csl/lib" -i"C:/CCStudio_v3.3/c6400/imglib/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" >> "ccsLinker.opt")
	$(shell echo --reread_libs >> "ccsLinker.opt")
	$(shell echo --rom_model >> "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell type "ccsObjs.opt" >> "ccsLinker.opt")
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

vpfe_bios_drv_rel.out: C:/tmp/TP_DSP_6437/TP_DSP_6437/drivers/VPFE/lib/vpfe_bios_drv_rel.lib $(OBJS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	$(shell echo -mv6400+ > "ccsLinker.opt")
	$(shell echo -g >> "ccsLinker.opt")
	$(shell echo --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" >> "ccsLinker.opt")
	$(shell echo --diag_warning=225 >> "ccsLinker.opt")
	$(shell echo --obj_directory="C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug" >> "ccsLinker.opt")
	$(shell echo -z >> "ccsLinker.opt")
	$(shell echo -m"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/Debug/TP-DSP.map" >> "ccsLinker.opt")
	$(shell echo --warn_sections >> "ccsLinker.opt")
	$(shell echo -i"C:/CCSv4/ccsv4/tools/compiler/c6000/lib" -i"C:/CCSv4/ccsv4/tools/compiler/c6000/include" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/rtdx/lib/c6000" -i"C:/CCSv4/bios_5_41_07_24/packages/ti/bios/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/TP_DSP" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1" -i"c:/CCSTUD~1.3/C6000/csl/lib" -i"C:/CCStudio_v3.3/c6400/imglib/lib" -i"C:/tmp/TP_DSP_6437/TP_DSP_6437/TP_DSP_exo1/driver" >> "ccsLinker.opt")
	$(shell echo --reread_libs >> "ccsLinker.opt")
	$(shell echo --rom_model >> "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell type "ccsObjs.opt" >> "ccsLinker.opt")
	"C:/CCSv4/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


