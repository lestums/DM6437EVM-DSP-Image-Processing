/*   Do *not* directly modify this file.  It was    */
/*   generated by the Configuration Tool; any  */
/*   changes risk being overwritten.                */

/* INPUT TP_DSP.cdb */

/* MODULE PARAMETERS */
-u _FXN_F_nop
GBL_USERINITFXN = _FXN_F_nop;

-u DDR2
MEM_SEGZERO = DDR2;
-u DDR2
MEM_MALLOCSEG = DDR2;

-u _CLK_gethtime
CLK_TIMEFXN = _CLK_gethtime;
-u HWI_F_dispatch
CLK_HOOKFXN = HWI_F_dispatch;

-u _KNL_tick
PRD_THOOKFXN = _KNL_tick;

-u DDR2
RTDX_DATAMEMSEG = DDR2;

-u DDR2
HST_DSMBUFSEG = DDR2;

-u GBL_NULL
SWI_EHOOKFXN = GBL_NULL;
-u GBL_NULL
SWI_IHOOKFXN = GBL_NULL;
-u SWI_F_exec
SWI_EXECFXN = SWI_F_exec;
-u SWI_F_run
SWI_RUNFXN = SWI_F_run;

-u DDR2
TSK_STACKSEG = DDR2;
-u _FXN_F_nop
TSK_VCREATEFXN = _FXN_F_nop;
-u _FXN_F_nop
TSK_VDELETEFXN = _FXN_F_nop;
-u _FXN_F_nop
TSK_VEXITFXN = _FXN_F_nop;

-u IDL_F_stub
IDL_CALIBRFXN = IDL_F_stub;

-u _UTL_doAbort
SYS_ABORTFXN = _UTL_doAbort;
-u _UTL_doError
SYS_ERRORFXN = _UTL_doError;
-u _UTL_halt
SYS_EXITFXN = _UTL_halt;
-u _UTL_doPutc
SYS_PUTCFXN = _UTL_doPutc;

-u _FXN_F_nop
GIO_CREATEFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_DELETEFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_PENDFXN = _FXN_F_nop;
-u _FXN_F_nop
GIO_POSTFXN = _FXN_F_nop;

/* OBJECT ALIASES */
_CACHE_L1P = CACHE_L1P;
_CACHE_L1D = CACHE_L1D;
_DDR2 = DDR2;
_L1DSRAM = L1DSRAM;
_IRAM = IRAM;
_PRD_clock = PRD_clock;
_RTA_fromHost = RTA_fromHost;
_RTA_toHost = RTA_toHost;
_HWI_RESET = HWI_RESET;
_HWI_NMI = HWI_NMI;
_HWI_RESERVED0 = HWI_RESERVED0;
_HWI_RESERVED1 = HWI_RESERVED1;
_HWI_INT4 = HWI_INT4;
_HWI_INT5 = HWI_INT5;
_HWI_INT6 = HWI_INT6;
_HWI_INT7 = HWI_INT7;
_HWI_INT8 = HWI_INT8;
_HWI_INT9 = HWI_INT9;
_HWI_INT10 = HWI_INT10;
_HWI_INT11 = HWI_INT11;
_HWI_INT12 = HWI_INT12;
_HWI_INT13 = HWI_INT13;
_HWI_INT14 = HWI_INT14;
_HWI_INT15 = HWI_INT15;
_EVENT4 = EVENT4;
_EVENT5 = EVENT5;
_EVENT6 = EVENT6;
_EVENT7 = EVENT7;
_EVENT8 = EVENT8;
_EVENT9 = EVENT9;
_EVENT10 = EVENT10;
_EVENT11 = EVENT11;
_EVENT12 = EVENT12;
_EVENT13 = EVENT13;
_EVENT14 = EVENT14;
_EVENT15 = EVENT15;
_EVENT16 = EVENT16;
_EVENT17 = EVENT17;
_EVENT18 = EVENT18;
_EVENT19 = EVENT19;
_EVENT20 = EVENT20;
_EVENT21 = EVENT21;
_EVENT22 = EVENT22;
_EVENT23 = EVENT23;
_EVENT24 = EVENT24;
_EVENT25 = EVENT25;
_EVENT26 = EVENT26;
_EVENT27 = EVENT27;
_EVENT28 = EVENT28;
_EVENT29 = EVENT29;
_EVENT30 = EVENT30;
_EVENT31 = EVENT31;
_EVENT32 = EVENT32;
_EVENT33 = EVENT33;
_EVENT34 = EVENT34;
_EVENT35 = EVENT35;
_EVENT36 = EVENT36;
_EVENT37 = EVENT37;
_EVENT38 = EVENT38;
_EVENT39 = EVENT39;
_EVENT40 = EVENT40;
_EVENT41 = EVENT41;
_EVENT42 = EVENT42;
_EVENT43 = EVENT43;
_EVENT44 = EVENT44;
_EVENT45 = EVENT45;
_EVENT46 = EVENT46;
_EVENT47 = EVENT47;
_EVENT48 = EVENT48;
_EVENT49 = EVENT49;
_EVENT50 = EVENT50;
_EVENT51 = EVENT51;
_EVENT52 = EVENT52;
_EVENT53 = EVENT53;
_EVENT54 = EVENT54;
_EVENT55 = EVENT55;
_EVENT56 = EVENT56;
_EVENT57 = EVENT57;
_EVENT58 = EVENT58;
_EVENT59 = EVENT59;
_EVENT60 = EVENT60;
_EVENT61 = EVENT61;
_EVENT62 = EVENT62;
_EVENT63 = EVENT63;
_EVENT64 = EVENT64;
_EVENT65 = EVENT65;
_EVENT66 = EVENT66;
_EVENT67 = EVENT67;
_EVENT68 = EVENT68;
_EVENT69 = EVENT69;
_EVENT70 = EVENT70;
_EVENT71 = EVENT71;
_EVENT72 = EVENT72;
_EVENT73 = EVENT73;
_EVENT74 = EVENT74;
_EVENT75 = EVENT75;
_EVENT76 = EVENT76;
_EVENT77 = EVENT77;
_EVENT78 = EVENT78;
_EVENT79 = EVENT79;
_EVENT80 = EVENT80;
_EVENT81 = EVENT81;
_EVENT82 = EVENT82;
_EVENT83 = EVENT83;
_EVENT84 = EVENT84;
_EVENT85 = EVENT85;
_EVENT86 = EVENT86;
_EVENT87 = EVENT87;
_EVENT88 = EVENT88;
_EVENT89 = EVENT89;
_EVENT90 = EVENT90;
_EVENT91 = EVENT91;
_EVENT92 = EVENT92;
_EVENT93 = EVENT93;
_EVENT94 = EVENT94;
_EVENT95 = EVENT95;
_EVENT96 = EVENT96;
_EVENT97 = EVENT97;
_EVENT98 = EVENT98;
_EVENT99 = EVENT99;
_EVENT100 = EVENT100;
_EVENT101 = EVENT101;
_EVENT102 = EVENT102;
_EVENT103 = EVENT103;
_EVENT104 = EVENT104;
_EVENT105 = EVENT105;
_EVENT106 = EVENT106;
_EVENT107 = EVENT107;
_EVENT108 = EVENT108;
_EVENT109 = EVENT109;
_EVENT110 = EVENT110;
_EVENT111 = EVENT111;
_EVENT112 = EVENT112;
_EVENT113 = EVENT113;
_EVENT114 = EVENT114;
_EVENT115 = EVENT115;
_EVENT116 = EVENT116;
_EVENT117 = EVENT117;
_EVENT118 = EVENT118;
_EVENT119 = EVENT119;
_EVENT120 = EVENT120;
_EVENT121 = EVENT121;
_EVENT122 = EVENT122;
_EVENT123 = EVENT123;
_EVENT124 = EVENT124;
_EVENT125 = EVENT125;
_EVENT126 = EVENT126;
_EVENT127 = EVENT127;
_KNL_swi = KNL_swi;
_TSK_idle = TSK_idle;
_echoTask = echoTask;
_IDL_cpuLoad = IDL_cpuLoad;
_LNK_dataPump = LNK_dataPump;
_RTA_dispatcher = RTA_dispatcher;
_LOG_system = LOG_system;
_trace = trace;
_DVTEvent_Log = DVTEvent_Log;
_IDL_busyObj = IDL_busyObj;

/* MODULE GBL */

SECTIONS {
   .vers (COPY): {} /* version information */
}

-priority
--trampolines
-llnkrtdx.a64P
-ldrivers.a64P         /* device drivers support */
-lsioboth.a64P         /* supports both SIO models */
-lbiosDM420.a64P       /* BIOS clock specific library */
-lbios.a64P            /* DSP/BIOS support */
-lrtdx64xplus.lib      /* RTDX support */
-lrts64plus.lib        /* C and C++ run-time library support */

_GBL_CACHE = GBL_CACHE;
_BCACHE_bootInit=_FXN_F_nop;

/* MODULE MEM */
-stack 0x8000
MEMORY {
   CACHE_L1P   : origin = 0x10e08000,  len = 0x8000
   CACHE_L1D   : origin = 0x10f10000,  len = 0x8000
   DDR2        : origin = 0x80000000,  len = 0x8000000
   L1DSRAM     : origin = 0x10f04000,  len = 0xc000
   IRAM        : origin = 0x10800000,  len = 0x20000
}
/* MODULE CLK */
SECTIONS {
   .clk: {
        
        CLK_F_gethtime = _CLK_gethtime;
        CLK_A_TABBEG = .;
        *(.clk)
        CLK_A_TABEND = .;
        CLK_A_TABLEN = (. - CLK_A_TABBEG) / 4;
   } > DDR2 
}
_CLK_PRD = CLK_PRD;
_CLK_COUNTSPMS = CLK_COUNTSPMS;
_CLK_REGS = CLK_REGS;
_CLK_USETIMER = CLK_USETIMER;
_CLK_TIMERNUM = CLK_TIMERNUM;
_CLK_TDDR = CLK_TDDR;

/* MODULE PRD */
SECTIONS {
   .prd: {
        PRD_A_TABBEG = .;
        /* no PRD objects */
        PRD_A_TABEND = .;
        PRD_A_TABLEN = (. - PRD_A_TABBEG) / 32;
   } > DDR2
}

/* MODULE RTDX */
_RTDX_interrupt_mask = 0x0;

/* MODULE HST */
_LNK_dspFrameReadyMask = LNK_dspFrameReadyMask; 
_LNK_dspFrameRequestMask = LNK_dspFrameRequestMask; 
_LNK_readDone = LNK_readDone; 
_LNK_readFail = LNK_readFail; 
_LNK_readPend = LNK_readPend; 
_LNK_writeFail = LNK_writeFail;
_HWI_CFGDISPATCHED = HWI_CFGDISPATCHED;

/* MODULE SWI */
SECTIONS {
   .swi: {
        SWI_A_TABBEG = .;
        *(.swi)
        SWI_A_TABEND = .;
        SWI_A_TABLEN = (. - SWI_A_TABBEG) / 44;
   } > DDR2
}

/* MODULE TSK */
SECTIONS {
   .tsk: {
        TSK_A_TABBEG = .;
        *(.tsk)
        TSK_A_TABEND = .;
        TSK_A_TABLEN = (. - TSK_A_TABBEG) / 96;
   } > DDR2
}

/* MODULE IDL */
SECTIONS {
   .idl: {
        IDL_A_TABBEG = .;
        *(.idl)
        IDL_A_TABEND = .;
        IDL_A_TABLEN = (. - IDL_A_TABBEG) / 4;
        IDL_A_CALBEG = .;
        *(.idlcal)
        IDL_A_CALEND = .;
        IDL_A_CALLEN = (. - IDL_A_CALBEG) / 4;
   } > DDR2
}



SECTIONS {
        .bss:     {} > DDR2

        .hwi_vec: {
            HWI_A_VECS = .;
            *(.hwi_vec)
        } align = 0x400 > DDR2

        .far:     {} > DDR2

        .sysdata: {} > DDR2

        .dsm: {} > DDR2

        .udev: {} > DDR2

        frt:    {} > DDR2

        .mem: 	  {} > DDR2

        .bios:    {} > DDR2

        .cio:     {} > DDR2

        .data:    {} > DDR2

        .gio:     {} > DDR2

        .pinit:   {} > DDR2

        .sys:     {} > DDR2

        .sysregs: {} > DDR2

        .text:    {} > DDR2

        .cinit:    {} > DDR2

        .devtable: {} > DDR2

        .switch:    {} > DDR2

        .gblinit:    {} > DDR2

        .sysinit:    {} > DDR2

        .trcdata:    {} > DDR2

        .hwi: {}  > DDR2

        .rtdx_text: {}  > DDR2

        .TSK_idle$stk: {
            *(.TSK_idle$stk)
        } > DDR2

        .echoTask$stk: {
            *(.echoTask$stk)
        } > DDR2

        .rtdx_data: align = 0x40 { . += 0x80; *(.rtdx_data) }   > DDR2

       /* RTA_fromHost buffer */
       .hst1: align = 0x4 {} > DDR2

       /* RTA_toHost buffer */
       .hst0: align = 0x4 {} > DDR2

        GROUP {
         .const: align = 0x8 {} 
         .printf (COPY): {} 
        } > DDR2

        .args: align=4 fill=0 {
            *(.args)
            . += 0x4;
        } > DDR2

        .trace: fill = 0x0  align = 0x4 {
           _SYS_PUTCBEG = .;
           . += 0x200;
           _SYS_PUTCEND = . - 1;
        } > DDR2

        .stack: {
            GBL_stackbeg = .;
            *(.stack)
            GBL_stackend = GBL_stackbeg + 0x8000 - 1;
            _HWI_STKBOTTOM = GBL_stackbeg + 0x8000 - 4 & ~7;
            _HWI_STKTOP = GBL_stackbeg;
        } > DDR2

        .hst: {
             HST_A_TABBEG = .;
            _HST_A_TABBEG = .;
            *(.hst)
            HST_A_TABEND = .;
            _HST_A_TABEND = .;
             HST_A_TABLEN = (. - _HST_A_TABBEG) / 20;
            _HST_A_TABLEN = (. - _HST_A_TABBEG) / 20;
        } > DDR2

        .log: {
             LOG_A_TABBEG = .;
            _LOG_A_TABBEG = .;
            *(.log)
            LOG_A_TABEND = .;
            _LOG_A_TABEND = .;
             LOG_A_TABLEN = (. - _LOG_A_TABBEG) / 24;
            _LOG_A_TABLEN = (. - _LOG_A_TABBEG) / 24;
        } > DDR2

        .pip: {
             PIP_A_TABBEG = .;
            _PIP_A_TABBEG = .;
            *(.pip)
            PIP_A_TABEND = .;
            _PIP_A_TABEND = .;
             PIP_A_TABLEN = (. - _PIP_A_TABBEG) / 100;
            _PIP_A_TABLEN = (. - _PIP_A_TABBEG) / 100;
        } > DDR2

        .sts: {
             STS_A_TABBEG = .;
            _STS_A_TABBEG = .;
            *(.sts)
            STS_A_TABEND = .;
            _STS_A_TABEND = .;
             STS_A_TABLEN = (. - _STS_A_TABBEG) / 16;
            _STS_A_TABLEN = (. - _STS_A_TABBEG) / 16;
        } > DDR2

        .DDR2$heap: {
            DDR2$B = .;
            _DDR2_base = .;
            DDR2$L = 0x1000000;
            _DDR2_length = 0x1000000;
            . += 0x1000000;
        } > DDR2

        /* LOG_system buffer */
        .LOG_system$buf: align = 0x1000 {} > IRAM

        /* trace buffer */
        .trace$buf: align = 0x1000 {} > IRAM

        /* DVTEvent_Log buffer */
        .DVTEvent_Log$buf: align = 0x8000 {} > IRAM

}

