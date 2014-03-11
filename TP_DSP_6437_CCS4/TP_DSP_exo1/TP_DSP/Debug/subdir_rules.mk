################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
TP_DSPcfg.cmd: C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP.tcf
	@echo 'Building file: $<'
	@echo 'Invoking: TConf Script Compiler'
	"C:/CCS/xdctools_3_22_01_21/tconf" -b -Dconfig.importPath="C:/CCS/bios_5_41_10_36/packages;C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1;/packages/ti/bios/examples/common;C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1;/packages/ti/bios/examples/common;;" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TP_DSPcfg.s??: TP_DSPcfg.cmd
TP_DSPcfg_c.c: TP_DSPcfg.cmd
TP_DSPcfg.h: TP_DSPcfg.cmd
TP_DSPcfg.h??: TP_DSPcfg.cmd
TP_DSP.cdb: TP_DSPcfg.cmd

C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP_DSPcfg.obj: .//TP_DSPcfg.s?? $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCS/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCS/ccsv4/tools/compiler/c6000/include" --include_path="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCS/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/CCS/bios_5_41_10_36/packages/ti/rtdx/include/c6000" --include_path="C:/CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="/include" --include_path="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --include_path="C:/Temp/TP_DSP_6437_CCS4/pal_os/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/drivers/i2c/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/drivers/previewer/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/drivers/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/CSL_inc" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="TP_DSPcfg.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP_DSPcfg_c.obj: .//TP_DSPcfg_c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/CCS/ccsv4/tools/compiler/c6000/bin/cl6x" -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --include_path="C:/CCS/ccsv4/tools/compiler/c6000/include" --include_path="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP/Debug" --include_path="C:/CCS/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/CCS/bios_5_41_10_36/packages/ti/rtdx/include/c6000" --include_path="C:/CCS/xdais_7_10_00_06/packages/ti/xdais" --include_path="/include" --include_path="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --include_path="C:/Temp/TP_DSP_6437_CCS4/pal_os/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/drivers/i2c/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/drivers/previewer/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/drivers/inc" --include_path="C:/Temp/TP_DSP_6437_CCS4/CSL_inc" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" --preproc_with_compile --preproc_dependency="TP_DSPcfg_c.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

vpbe_bios_drv_dbg.out: C:/Temp/TP_DSP_6437_CCS4/drivers/VPBE/lib/vpbe_bios_drv_dbg.lib $(GEN_CMDS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	@echo 'Flags: -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model'
	$(shell echo -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model > "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	"C:/CCS/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

vpbe_bios_drv_rel.out: C:/Temp/TP_DSP_6437_CCS4/drivers/VPBE/lib/vpbe_bios_drv_rel.lib $(GEN_CMDS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	@echo 'Flags: -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model'
	$(shell echo -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model > "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	"C:/CCS/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

vpfe_bios_drv_dbg.out: C:/Temp/TP_DSP_6437_CCS4/drivers/VPFE/lib/vpfe_bios_drv_dbg.lib $(GEN_CMDS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	@echo 'Flags: -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model'
	$(shell echo -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model > "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	"C:/CCS/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

vpfe_bios_drv_rel.out: C:/Temp/TP_DSP_6437_CCS4/drivers/VPFE/lib/vpfe_bios_drv_rel.lib $(GEN_CMDS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	@echo 'Flags: -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model'
	$(shell echo -mv6400+ -g --define="_DEBUG" --define="CHIP_DM6437" --define="DM643X_SOC_BUILD" --define="BIOS_BUILD" --diag_warning=225 --obj_directory="C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug" -z -m"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/Debug/TP-DSP.map" --warn_sections -i"C:/CCS/ccsv4/tools/compiler/c6000/lib" -i"C:/CCS/ccsv4/tools/compiler/c6000/include" -i"C:/CCS/bios_5_41_10_36/packages/ti/rtdx/lib/c6000" -i"C:/CCS/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/TP_DSP" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1" -i"/lib" -i"C:/Temp/TP_DSP_6437_CCS4/TP_DSP_exo1/driver" --reread_libs --rom_model > "ccsLinker.opt")
	$(shell echo $< >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpbe_bios_drv_rel.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_dbg.lib >> "ccsLinker.opt")
	$(shell echo ../vpfe_bios_drv_rel.lib >> "ccsLinker.opt")
	"C:/CCS/ccsv4/tools/compiler/c6000/bin/cl6x" -@"ccsLinker.opt" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


