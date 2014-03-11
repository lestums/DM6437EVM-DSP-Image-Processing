#ifndef _EDMA3_DRV_H_
#define _EDMA3_DRV_H_

/* For the Resource Manager part */
#include "edma3_rm.h"


/**
 * \defgroup Edma3DrvMain EDMA3 Driver Interface Definition
 *
 * Top-level Encapsulation of all documentation for EDMA3 Driver
 *
 * @{
 */


/*---------------------------------------------------------------------------*/
/*------------------Usage Guidelines Start-----------------------------------*/
/*---------------------------------------------------------------------------*/

/**
 * \defgroup Edma3DrvUsage Usage of Edma3 Driver Layer
 *
 * Guidelines for typical usage of Edma3 Driver Layer
 *
 * @{
 */


/**
  \brief Usage of EDMA3 Driver Layer.

    -# Create Edma3 Driver Object (one for each EDMA3 hardware instance)
        - EDMA3_DRV_Result result = EDMA3_DRV_SOK;
        - unsigned int edma3HwInstanceId = 0;
        - EDMA3_DRV_GblConfigParams *gblCfgParams;
        - Init-time Configuration structure for EDMA3 controller, to provide
            Global SoC specific Information. This could be NULL also. In that
            case, static configuration will be taken.
        - result = EDMA3_DRV_create (edma3HwInstanceId, NULL, NULL);
    -# Open Edma3 driver Instance
        - Steps
            - EDMA3_DRV_InitConfig initCfg;
            - EDMA3_DRV_Handle hEdma = NULL;
            - EDMA3_DRV_Result edmaResult;
                -To get the error code while opening driver instance

            -# initCfg.regionId = One of the possible regions available
               for eg, (EDMA3_RM_RegionId)0 or (EDMA3_RM_RegionId)1 etc, for
               different processors.
            -# initCfg.isMaster = True or False (Whether this EDMA3 driver
               instance is Master or not. Only the master instance shadow
               region will receive the EDMA3 interrupts, if enabled.);
            -# initCfg.drvInstInitConfig =
               Init-time Region Specific Configuration Structure. It can be
               provided by the user at run-time. If not provided by the user,
               this info will be taken from the config file edma3Cfg.c.
            -# initCfg.drvSemHandle =
               EDMA3 Driver Instance specific semaphore handle. It should
               be provided by the user for proper sharing of resources.
            -# initCfg.gblerrCb =
               Instance wide callback function to catch non-channel specific
               errors;
            -# initCfg.gblerrData =
               Application data to be passed back to the callback function;

            -# hEdma = EDMA3_DRV_open(edma3HwInstanceId, &initCfg, &edmaResult);

    -# Edma3 driver APIs
        - EDMA3_RM_ResDesc      resObj;
        - EDMA3_DRV_Result      result;
        - unsigned int          ch1Id = 0;
        - unsigned int          ch2Id = 0;
        - unsigned int          tcc1 = 0;
        - unsigned int          tcc2 = 0;
        - unsigned int          qCh1Id = 0;
        - unsigned int          qTcc1 = 0;
        - unsigned int          qCh2Id = 0;
        - unsigned int          qTcc2 = 0;
        - unsigned int          paRAMId;
        - int                   srcbidx = 0;
        - int                   desbidx = 0;
        - int                   srccidx = 0;
        - int                   descidx = 0;
        - unsigned int          acnt = 0;
        - unsigned int          bcnt = 0;
        - unsigned int          ccnt = 0;
        - unsigned int          bcntreload = 0;
        - EDMA3_DRV_SyncType    synctype;
        - EDMA3_RM_TccCallback  tccCb;
        - void *cbData;
        -
        - Use Case 1: Memory to memory transfer on any available
        -             DMA Channel\n\n
            - tcc1   = EDMA3_DRV_TCC_ANY;
            - ch1Id  = EDMA3_DRV_DMA_CHANNEL_ANY;
            - result = EDMA3_DRV_requestChannel (hEdma, &ch1Id, &tcc1,
                               (EDMA3_RM_EventQueue)0, &callback1, NULL);

            - result = EDMA3_DRV_setSrcParams (hEdma, ch1Id,
                                                (unsigned int)(srcBuff1),
                                                EDMA3_DRV_ADDR_MODE_INCR,
                                                EDMA3_DRV_W8BIT);
            - result = EDMA3_DRV_setDestParams (hEdma, ch1Id,
                                                (unsigned int)(dstBuff1),
                                                EDMA3_DRV_ADDR_MODE_INCR,
                                                EDMA3_DRV_W8BIT);

            - Set EDMA transfer parameters (aCnt, bCnt, cCnt, bCntReload,
                                            SyncType)
              acnt = 256; bcnt = 1; ccnt = 1, bcntreload = 0;
              synctype = EDMA3_DRV_SYNC_A;
            - result = EDMA3_DRV_setTransferParams (hEdma, ch1Id, acnt, bcnt,
                                                    ccnt, bcntreload, synctype);

            - Set srcbidx and srccidx to the appropriate values
            - srcbidx = acnt; srccidx = acnt;
            - result = EDMA3_DRV_setSrcIndex  (hEdma, ch1Id, srcbidx, srccidx);

            - Set desbidx and descidx to the appropriate values
            - desbidx = acnt; descidx = acnt;
            - result = EDMA3_DRV_setDestIndex (hEdma, ch1Id, desbidx, descidx);

            - Enable the final completion interrupt.
            - result = EDMA3_DRV_setOptField (hEdma, ch1Id,
                               EDMA3_DRV_OPT_FIELD_TCINTEN, 1);

            - Enable the transfer
            - result = EDMA3_DRV_enableTransfer (hEdma, ch1Id,
                                        EDMA3_DRV_TRIG_MODE_MANUAL);

        - Use Case 2: Linked memory to memory transfer on any available
        -             DMA Channel\n\n
            - Perform steps as for Use Case 1 for the Master logical channel
                ch1Id for configuration. DONOT enable the transfer for ch1Id.
            - Configure link channel, ch2Id.
            - tcc2   = EDMA3_DRV_TCC_ANY;
            - ch2Id  = EDMA3_DRV_LINK_CHANNEL;
            - result = EDMA3_DRV_requestChannel (hEdma, &ch2Id, &tcc2,
                               (EDMA3_RM_EventQueue)0, &callback2, NULL);

            - result = EDMA3_DRV_setSrcParams (hEdma, ch2Id,
                                            (unsigned int)(srcBuff2),
                                            EDMA3_DRV_ADDR_MODE_INCR,
                                            EDMA3_DRV_W8BIT);
            - result = EDMA3_DRV_setDestParams (hEdma, ch2Id,(
                                            unsigned int)(dstBuff2),
                                            EDMA3_DRV_ADDR_MODE_INCR,
                                            EDMA3_DRV_W8BIT);

            - result = EDMA3_DRV_setSrcIndex  (hEdma, ch2Id, srcbidx, srccidx);
            - result = EDMA3_DRV_setDestIndex (hEdma, ch2Id, desbidx, descidx);

            - result = EDMA3_DRV_setTransferParams (hEdma, ch2Id, acnt, bcnt,
                                ccnt, bcntreload, synctype);

            - Link both the channels
            - result = EDMA3_DRV_linkChannel (hEdma, ch1Id, ch2Id);

            - Enable the final completion interrupts on both the channels
            - result = EDMA3_DRV_setOptField (hEdma, ch1Id,
                               EDMA3_DRV_OPT_FIELD_TCINTEN, 1);
            - result = EDMA3_DRV_setOptField (hEdma, ch2Id,
                               EDMA3_DRV_OPT_FIELD_TCINTEN, 1);

            - Enable the transfer on channel 1.
            - result = EDMA3_DRV_enableTransfer (hEdma, ch1Id,
                                        EDMA3_DRV_TRIG_MODE_MANUAL);
            - Wait for the completion interrupt on Ch1 and then enable the
              transfer again for the LINK channel, to provide the required
              sync event.
            - result = EDMA3_DRV_enableTransfer (hEdma, ch1Id,
                                        EDMA3_DRV_TRIG_MODE_MANUAL);

            - Note: Enabling of transfers on channel 1 (for master and link
              channel) is required as many number of times as the sync events
              are required. For ASync mode, number of sync events=(bcnt * ccnt)
              and for ABSync mode, number of sync events = ccnt.

        - Use Case 3: Memory to memory transfer on any available
        -             QDMA Channel\n\n
            - qTcc1  = EDMA3_DRV_TCC_ANY;
            - qCh1Id = EDMA3_DRV_QDMA_CHANNEL_ANY;

            - result = EDMA3_DRV_requestChannel (hEdma, &qCh1Id, &qTcc1,
                               (EDMA3_RM_EventQueue)0, &callback1, NULL);

            - Set the QDMA trigger word.
            - result =  EDMA3_DRV_setQdmaTrigWord (hEdma, qCh1Id,
                                                    EDMA3_RM_QDMA_TRIG_DST);
            - Note: DONOT write the destination address (trigger word) before
                    completing the configuration as it will trigger the
                    transfer. Also, DONOT use EDMA3_DRV_setDestParams() to set
                    the destination address as it also sets other parameters.
                    Use EDMA3_DRV_setPaRAMEntry() to set the destination address

            - result = EDMA3_DRV_setSrcParams (hEdma, qCh1Id,
                                                (unsigned int)(srcBuff1),
                                                EDMA3_DRV_ADDR_MODE_INCR,
                                                EDMA3_DRV_W8BIT);

            - Set QDMA transfer parameters (aCnt, bCnt, cCnt, bCntReload,
                                            SyncType)
              acnt = 256; bcnt = 1; ccnt = 1, bcntreload = 0;
              synctype = EDMA3_DRV_SYNC_A;
            - result = EDMA3_DRV_setTransferParams (hEdma, qCh1Id, acnt, bcnt,
                                                    ccnt, bcntreload, synctype);

            - srcbidx = acnt; srccidx = acnt; desbidx = acnt; descidx = acnt;
            - result = EDMA3_DRV_setSrcIndex  (hEdma, qCh1Id, srcbidx, srccidx);
            - result = EDMA3_DRV_setDestIndex (hEdma, qCh1Id, desbidx, descidx);

            - Enable the final completion interrupt.
            - result = EDMA3_DRV_setOptField  (hEdma, qCh1Id,
                               EDMA3_DRV_OPT_FIELD_TCINTEN, 1);

            - Set the Destination Addressing Mode as Increment
            - result = EDMA3_DRV_setOptField (hEdma, qCh1Id,
                                            EDMA3_DRV_OPT_FIELD_DAM,
                                            EDMA3_DRV_ADDR_MODE_INCR);

            - Trigger the QDMA channel by writing the destination address
            - result = EDMA3_DRV_setPaRAMEntry (hEdma, qCh1Id,
                                                EDMA3_DRV_PARAM_ENTRY_DST,
                                                (unsigned int)(dstBuff1));

        -
        - Use Case 4: Linked memory to memory transfer on any available
        -             QDMA Channel\n\n
            - Setup for any QDMA Channel
            - qTcc1  = EDMA3_DRV_TCC_ANY;
            - qCh1Id = EDMA3_DRV_QDMA_CHANNEL_ANY;
            - result = EDMA3_DRV_requestChannel (hEdma, &qCh1Id, &qTcc1,
                               (EDMA3_RM_EventQueue)0, &callback1, NULL);

            - Setup for Channel 2
            - qCh2Id = EDMA3_DRV_LINK_CHANNEL;
            - qTcc2  = EDMA3_DRV_TCC_ANY;
            - result = EDMA3_DRV_requestChannel (hEdma, &qCh2Id, &qTcc2,
                                                (EDMA3_RM_EventQueue)0,
                                                &callback2, NULL);

            - result = EDMA3_DRV_setSrcParams (hEdma, qCh2Id,
                                                (unsigned int)(srcBuff2),
                                                EDMA3_DRV_ADDR_MODE_INCR,
                                                EDMA3_DRV_W8BIT);
            - result = EDMA3_DRV_setDestParams(hEdma, qCh2Id,
                                                (unsigned int)(dstBuff2),
                                                EDMA3_DRV_ADDR_MODE_INCR,
                                                EDMA3_DRV_W8BIT);

            - acnt = 256; bcnt = 1; ccnt = 1, bcntreload = 0;
              synctype = EDMA3_DRV_SYNC_A;
            - result = EDMA3_DRV_setTransferParams (hEdma, qCh2Id, acnt, bcnt,
                                                    ccnt, BRCnt,
                                                    EDMA3_DRV_SYNC_A);

            - srcbidx = acnt; srccidx = acnt; desbidx = acnt; descidx = acnt;
            - result = EDMA3_DRV_setSrcIndex  (hEdma, qCh2Id, srcbidx, srccidx);
            - result = EDMA3_DRV_setDestIndex (hEdma, qCh2Id, desbidx, descidx);

            - result = EDMA3_DRV_setOptField (hEdma, qCh2Id,
                               EDMA3_DRV_OPT_FIELD_TCINTEN, 1);

            - Make the PaRAM Set associated with qCh2Id as Static
            - result = EDMA3_DRV_setOptField (hEdma, qCh2Id,
                                            EDMA3_DRV_OPT_FIELD_STATIC, 1u);

            - Link both the channels
            - result = EDMA3_DRV_linkChannel (hEdma,qCh1Id,qCh2Id);

            - Set the QDMA trigger word.
            - result = EDMA3_DRV_setQdmaTrigWord (hEdma, qCh1Id,
                               EDMA3_DRV_QDMA_TRIG_DST);
            - Note: DONOT write the destination address (trigger word) before
                    completing the configuration as it'll trigger the transfer.
                    Also, DONOT use EDMA3_DRV_setDestParams () function to set
                    the destination address as it also sets other parameters.
                    Use EDMA3_DRV_setPaRAMEntry() to set the dest address.

            - result = EDMA3_DRV_setSrcParams (hEdma, qCh1Id,
                                                (unsigned int)(srcBuff1),
                                                EDMA3_DRV_ADDR_MODE_INCR,
                                                EDMA3_DRV_W8BIT);

            - Set QDMA transfer parameters (aCnt, bCnt, cCnt, bCntReload,
                                            SyncType)
              acnt = 256; bcnt = 1; ccnt = 1, bcntreload = 0;
              synctype = EDMA3_DRV_SYNC_A;
            - result = EDMA3_DRV_setTransferParams (hEdma, qCh1Id, acnt, bcnt,
                                                ccnt, bcntreload, synctype);

            - srcbidx = acnt; srccidx = acnt; desbidx = acnt; descidx = acnt;
            - result = EDMA3_DRV_setSrcIndex  (hEdma, qCh1Id, srcbidx, srccidx);
            - result = EDMA3_DRV_setDestIndex (hEdma, qCh1Id, desbidx, descidx);

            - result = EDMA3_DRV_setOptField (hEdma, qCh1Id,
                               EDMA3_DRV_OPT_FIELD_TCINTEN, 1);

            - Set the Destination Addressing Mode as Increment
            - result = EDMA3_DRV_setOptField (hEdma, qCh1Id,
                                            EDMA3_DRV_OPT_FIELD_DAM,
                                            EDMA3_DRV_ADDR_MODE_INCR);

            - Trigger the QDMA channel by writing the destination address
            - result = EDMA3_DRV_setPaRAMEntry (hEdma, qCh1Id,
                                                EDMA3_DRV_PARAM_ENTRY_DST,
                                                (unsigned int)(dstBuff1));

*/
/* @} Edma3DrvUsage */

/*---------------------------------------------------------------------------*/
/*------------------Usage Guidelines End-------------------------------------*/
/*---------------------------------------------------------------------------*/


/**
 * \defgroup Edma3DrvErrorCode EDMA3 Driver Error Codes
 *
 * Error Codes returned by the EDMA3 Driver
 *
 * @{
 */
/** Edma3 Driver Error Codes Base define */
#define EDMA3_DRV_E_BASE                        (-128)

/**
 * Edma3 Driver Object Not Deleted yet.
 * So it cannot be created.
 */
#define EDMA3_DRV_E_OBJ_NOT_DELETED             (EDMA3_DRV_E_BASE)

/**
 * Edma3 Driver Object Not Closed yet.
 * So it cannot be deleted.
 */
#define EDMA3_DRV_E_OBJ_NOT_CLOSED              (EDMA3_DRV_E_BASE-1)

/**
 * Edma3 Driver Object Not Opened yet
 * So it cannot be closed.
 */
#define EDMA3_DRV_E_OBJ_NOT_OPENED              (EDMA3_DRV_E_BASE-2)

/**
 * While closing EDMA3 Driver, Resource Manager
 * Close Failed.
 */
#define EDMA3_DRV_E_RM_CLOSE_FAIL               (EDMA3_DRV_E_BASE-3)

/** The requested DMA Channel not available */
#define EDMA3_DRV_E_DMA_CHANNEL_UNAVAIL         (EDMA3_DRV_E_BASE-4)

/** The requested QDMA Channel not available */
#define EDMA3_DRV_E_QDMA_CHANNEL_UNAVAIL        (EDMA3_DRV_E_BASE-5)

/** The requested PaRAM Set not available */
#define EDMA3_DRV_E_PARAM_SET_UNAVAIL           (EDMA3_DRV_E_BASE-6)

/** The requested TCC not available */
#define EDMA3_DRV_E_TCC_UNAVAIL                 (EDMA3_DRV_E_BASE-7)

/** The registration of TCC failed */
#define EDMA3_DRV_E_TCC_REGISTER_FAIL           (EDMA3_DRV_E_BASE-8)

/** The binding of Channel and PaRAM Set failed */
#define EDMA3_DRV_E_CH_PARAM_BIND_FAIL          (EDMA3_DRV_E_BASE-9)

/**
 * The address of the memory location passed as argument
 * is not properly aligned. It should be 32 bytes aligned.
 */
#define EDMA3_DRV_E_ADDRESS_NOT_ALIGNED         (EDMA3_DRV_E_BASE-10)

/** Invalid Parameter passed to API */
#define EDMA3_DRV_E_INVALID_PARAM               (EDMA3_DRV_E_BASE-11)

/** Invalid State of EDMA3 HW Obj */
#define EDMA3_DRV_E_INVALID_STATE                (EDMA3_DRV_E_BASE-12)

/** EDMA3 Driver instance already exists for the specified region */
#define EDMA3_DRV_E_INST_ALREADY_EXISTS         (EDMA3_DRV_E_BASE-13)

/** FIFO width not supported by the requested TC */
#define EDMA3_DRV_E_FIFO_WIDTH_NOT_SUPPORTED        (EDMA3_DRV_E_BASE-14)

/** Semaphore related error */
#define EDMA3_DRV_E_SEMAPHORE                       (EDMA3_DRV_E_BASE-15)

/* @} Edma3DrvErrorCode */


/**
 * This define is used when specifying the mapping for each DMA
 * channel to a specific PaRAM set, in dmaChannelPaRAMMap[EDMA3_RM_NUM_DMA_CH],
 * via config file edma3Cfg.c.
 * This value should mandatorily be used to mark DMA channels
 * with no initial mapping to a specific PaRAM Set.
 */
#define EDMA3_DRV_CH_NO_PARAM_MAP           1000u

/**
 * This define is used when specifying the mapping for each DMA
 * channel to a specific TCC, in dmaChannelTccMap[EDMA3_RM_NUM_DMA_CH],
 * via config file edma3Cfg.c.
 * This value should mandatorily be used to mark DMA channels
 * with no initial mapping to a specific TCC.
 */
#define EDMA3_DRV_CH_NO_TCC_MAP             1001u

/**
 * Number of PaRAM Sets in the specific SoC. It is initialized with the
 * maximum possible PaRAM Sets. But it is modified later
 * with the actual PaRAM Sets available on the SoC.
 */
extern unsigned int edma3NumPaRAMSets;

/**
 * \brief Init-time Configuration structure for EDMA3
 * controller, to provide Global SoC specific Information.
 *
 * This configuration info can be provided by the user at run-time,
 * while calling EDMA3_DRV_create(). If not provided at run-time,
 * this info will be taken from the config file edma3Cfg.c, for the specified
 * platform.
 */
typedef struct  {
    /** Total number of DMA Channels supported by the EDMA3 Controller */
    unsigned int        numDmaChannels;
    /** Total number of QDMA Channels supported by the EDMA3 Controller */
    unsigned int        numQdmaChannels;
    /** Total number of TCCs supported by the EDMA3 Controller */
    unsigned int        numTccs;
    /** Total number of PaRAM Sets supported by the EDMA3 Controller */
    unsigned int        numPaRAMSets;
    /** Total number of Event Queues in the EDMA3 Controller */
    unsigned int        numEvtQueue;
    /** Total number of Transfer Controllers (TCs) in the EDMA3 Controller */
    unsigned int        numTcs;
    /** Number of Regions on this EDMA3 controller */
    unsigned int        numRegions;

    /**
     * \brief Channel mapping existence
     * A value of 0 (No channel mapping) implies that there is fixed association
     * for a channel number to a parameter entry number or, in other words,
     * PaRAM entry n corresponds to channel n.
     */
    unsigned short dmaChPaRAMMapExists;

    /** Existence of memory protection feature */
    unsigned short memProtectionExists;

    /** Pointer to Global Register Region of CC Registers */
    void                 *globalRegs;
    /** Pointer to Transfer Controller Registers */
    void                 *tcRegs[EDMA3_MAX_TC];
    /** Interrupt no. for Transfer Completion */
    unsigned int        xferCompleteInt;
    /** Interrupt no. for CC Error */
    unsigned int        ccError;
    /** Interrupt no. for TCs Error */
    unsigned int        tcError[EDMA3_MAX_TC];

    /**
     * \brief EDMA3 TC priority setting
     *
     * User can program the priority of the Event Queues
     * at a system-wide level.  This means that the user can set the
     * priority of an IO initiated by either of the TCs (Transfer Controllers)
     * relative to IO initiated by the other bus masters on the
     * device (ARM, DSP, USB, etc)
     */
    unsigned int evtQPri [EDMA3_MAX_EVT_QUE];
    /**
     * \brief To Configure the Threshold level of number of events
     * that can be queued up in the Event queues. EDMA3CC error register
     * (CCERR) will indicate whether or not at any instant of time the
     * number of events queued up in any of the event queues exceeds
     * or equals the threshold/watermark value that is set
     * in the queue watermark threshold register (QWMTHRA).
     */
    unsigned int evtQueueWaterMarkLvl [EDMA3_MAX_EVT_QUE];

    /**
     * \brief To Configure the Default Burst Size (DBS) of TCs.
     * An optimally-sized command is defined by the transfer controller
     * default burst size (DBS). Different TCs can have different
     * DBS values. It is defined in Bytes.
     */
    unsigned int tcDefaultBurstSize[EDMA3_MAX_TC];


    /**
     * \brief Mapping from each DMA channel to a Parameter RAM set
     * Useful only if mapping exists, otherwise of no use.
     */
    unsigned int dmaChannelPaRAMMap [EDMA3_MAX_DMA_CH];

     /**
      * \brief Mapping from each DMA channel to a TCC. This specific
      * TCC code will be returned when the transfer is completed
      * on the mapped channel.
      */
     unsigned int dmaChannelTccMap [EDMA3_MAX_DMA_CH];

    /**
     * \brief Mapping of DMA channels to Hardware Events from
     * various peripherals, which use EDMA for data transfer.
     * All channels need not be mapped, some can be free also.
     */
    unsigned int dmaChannelHwEvtMap [EDMA3_MAX_DMA_CHAN_DWRDS];
    } EDMA3_DRV_GblConfigParams;


/**
 * \brief Init-time Region Specific Configuration structure for
 * EDMA3 controller, to provide region specific Information.
 *
 * This configuration info can be provided by the user at run-time,
 * while calling EDMA3_DRV_open(). If not provided at run-time,
 * this info will be taken from the config file edma3Cfg.c.
 */
typedef struct
{
    /**
     * \brief PaRAM Sets owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each PaRAM Set to a master (Region) using this
     * array.  This assignment should ensure that the same PaRAM Set
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical PaRAM Set may have
     * catastrophic consequences.
     *
     */
    unsigned int ownPaRAMSets[EDMA3_MAX_PARAM_DWRDS];

    /**
     * \brief DMA Channels owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each channel to a master (Region) using this
     * array.  This assignment should ensure that the same channel
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical channel may have
     * catastrophic consequences.
     */
    unsigned int ownDmaChannels[EDMA3_MAX_DMA_CHAN_DWRDS];

    /**
     * \brief QDMA Channels owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each QDMA channel to a master (Region) using this
     * array.  This assignment should ensure that the same QDMA channel
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical QDMA channel may have
     * catastrophic consequences.
     */
    unsigned int ownQdmaChannels[EDMA3_MAX_QDMA_CHAN_DWRDS];

    /**
     * \brief TCCs owned by the specific region.
     *
     * Regions are
     *       - ARM
     *       - DSP
     *       - Video co-processor \n
     * User can assign each TCC to a master (Region) using this
     * array.  This assignment should ensure that the same TCC
     * is not assigned to more than 1 Region.  Any assignment which
     * assigns multiple Regions to an identical TCC may have
     * catastrophic consequences.
     */
    unsigned int ownTccs[EDMA3_MAX_TCC_DWRDS];

    /** Reserved PaRAM Sets - Which are mapped to any DMA/QDMA channel
     *  - these are not given to 'EDMA3_DRV_DMA_CHANNEL_ANY/
     *     EDMA3_DRV_QDMA_CHANNEL_ANY' request
     */
    unsigned int        resvdPaRAMSets[EDMA3_MAX_PARAM_DWRDS];

    /** Reserved DMA Channels - Channels mapped to HW events
     *  - these are not given to 'EDMA3_DRV_DMA_CHANNEL_ANY' request
     */
    unsigned int        resvdDmaChannels[EDMA3_MAX_DMA_CHAN_DWRDS];

    /** Reserved DMA Channels - Channels mapped to HW events
     *  - these are not given to 'EDMA3_DRV_QDMA_CHANNEL_ANY' request
     */
    unsigned int        resvdQdmaChannels[EDMA3_MAX_QDMA_CHAN_DWRDS];

    /** Reserved TCCs- Which are mapped to any DMA channel
     *  - these are not given to 'EDMA3_DRV_TCC_ANY' request
     */
    unsigned int        resvdTccs[EDMA3_MAX_TCC_DWRDS];
}EDMA3_DRV_InstanceInitConfig;



/**
 * \brief EDMA3 Driver Instance Init Configuration.
 * Initial configuration to be passed while opening the driver instance.
 */
typedef struct
{
    /** Region Identification */
    EDMA3_RM_RegionId       regionId;

    /**
     * Whether EDMA3 driver instance is Master or not.
     * Only the master instance shadow region will receive the
     * EDMA3 interrupts, if enabled.
     */
    unsigned short          isMaster;

    /**
     * EDMA3 Driver Instance (Shadow Region) specific
     * init configuration.
     * If NULL, static values will be taken
     */
    EDMA3_DRV_InstanceInitConfig    *drvInstInitConfig;

    /**
     * EDMA3 Driver Instance specific semaphore handle.
     * Used to share resources (DMA/QDMA channels, PaRAM Sets, TCCs etc)
     * among different users.
     */
    void                    *drvSemHandle;

    /**
     * Instance wide global callback function to catch non-channel
     * specific errors from the Channel controller. for eg, TCC
     * error, queue threshold exceed error etc.
     */
    EDMA3_RM_GblErrCallback gblerrCb;

    /** Application data to be passed back to the callback function */
    void                    *gblerrData;
} EDMA3_DRV_InitConfig;


/**
 * \brief EDMA3 Driver Object creation
 *
 * Use this API to create the EDMA3 Driver Object. It should be called
 * only ONCE for each EDMA3 hardware instance. After successful completion of
 * this API, driver object's state changes to EDMA3_DRV_CREATED.
 *
 * \param phyCtrllerInstId  [IN]    EDMA3 Phy Controller Instance Id (Hardware
 *                                  instance id, starting from 0).
 * \param gblCfgParams      [IN]    SoC specific configuration structure for the
 *                                  EDMA3 Hardware. If not provided at run-time,
 *                                  this info will be taken from the config file
 *                                   edma3Cfg.c, for the specified platform.
 * \param param             [IN]    For possible future use.
 *
 * \return EDMA3_DRV_SOK or EDMA3_DRV Error code
 */
EDMA3_DRV_Result EDMA3_DRV_create (unsigned int phyCtrllerInstId,
                                const EDMA3_DRV_GblConfigParams *gblCfgParams,
                                const void *param);


/**
 * \brief EDMA3 Driver instance deletion
 *
 * Use this API to delete the EDMA3 Driver Object. It should be called only
 * ONCE for each EDMA3 hardware instance. It should be called ONLY after
 * closing all the EDMA3 Driver Instances.
 *
 * \param phyCtrllerInstId  [IN]    EDMA3 Phy Controller Instance Id (Hardware
 *                                  instance id, starting from 0).
 * \param param             [IN]    For possible future use.
 *
 * \return EDMA3_DRV_SOK or EDMA3_DRV Error code
 */
EDMA3_DRV_Result EDMA3_DRV_delete (unsigned int phyCtrllerInstId,
                                    const void *param);



/**
 * \brief Open EDMA3 Driver Instance.
 *
 * Use this API to open an Instance of the EDMA3 Driver. It could be
 * called for each possible EDMA3 shadow region ONLY once. Multiple
 * instances on the same shadow region are NOT allowed.
 *
 * \param phyCtrllerInstId  [IN]    EDMA3 Phy Controller Instance Id (Hardware
 *                                  instance id, starting from 0).
 * \param initCfg           [IN]    EDMA3_DRV_InitConfig *initCfg.
 *                                  EDMA3 Driver Instance Init Configuration.
 * \param errorCode         [OUT]   Error code is returned here while opening
 *                                  driver instance.
 *
 * \return EDMA3_DRV_Handle : If successfully opened, the API will return the
 *                            associated driver's instance handle.
 *
 * \note    This function disables the global interrupts while modifying
 *          the global Driver data structures, to make it re-entrant.
 */
EDMA3_DRV_Handle EDMA3_DRV_open (unsigned int phyCtrllerInstId,
                        const EDMA3_DRV_InitConfig *initCfg,
                        EDMA3_DRV_Result *errorCode);


/**
 * \brief Close the EDMA3 Driver Instance.
 *
 * Use this API to close an already opened EDMA3 Driver Instance.
 *
 * \param hEdma             [IN]    Handle to the opened EDMA3 Driver Instance.
 * \param param             [IN]    For possible future use
 *
 * \return EDMA3_DRV_SOK or EDMA3_DRV Error code
 *
 * \note    This function disables the global interrupts while modifying
 *          the global Driver data structures, to make it re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_close (EDMA3_DRV_Handle hEdma,
                                const void *param);



/**
 * \defgroup Edma3DrvChannelSetup EDMA3 Driver Channel Setup
 *
 * Channel related Interface of the EDMA3 Driver
 *
 * @{
 */

/* Defines for Logical Channel Values */
/*---------------------------------------------------------------------------*/
/**
 * Used to specify any available DMA Channel while requesting
 * one. Used in the API EDMA3_DRV_requestChannel().
 */
#define EDMA3_DRV_DMA_CHANNEL_ANY                   1002u

/**
 * Used to specify any available QDMA Channel while requesting
 * one. Used in the API EDMA3_DRV_requestChannel().
 */
#define EDMA3_DRV_QDMA_CHANNEL_ANY                  1003u

/**
 * Used to specify any available TCC while requesting
 * one. Used in the API EDMA3_DRV_requestChannel(), for
 * both DMA and QDMA channels.
 */
#define EDMA3_DRV_TCC_ANY                           1004u

/**
 * Used as the value of channelId
 * when requesting for any available PaRAM set for Linking.
 * Used in the API EDMA3_DRV_requestChannel().
 */
#define EDMA3_DRV_LINK_CHANNEL                      1005u
/*---------------------------------------------------------------------------*/

/**
 * \brief DMA Channels assigned to different Hardware Events.
 * They should be used while requesting a specific DMA channel.
 * One possible usage is to maintain a SoC specific file, which will
 * contain the mapping of these hardware events to the respective
 * peripherals for better understanding and lesser probability of
 * errors. Also, if any event associated with a particular peripheral
 * gets changed, only that SoC specific file needs to be changed.
 *
 * for eg, the sample SoC specific file "soc.h" can have these defines:
 *
 * #define EDMA3_DRV_HW_CHANNEL_MCBSP_TX        EDMA3_DRV_HW_CHANNEL_EVENT_2
 * #define EDMA3_DRV_HW_CHANNEL_MCBSP_RX        EDMA3_DRV_HW_CHANNEL_EVENT_3
 *
 * These defines will be used by the MCBSP driver. The same event
 * EDMA3_DRV_HW_CHANNEL_EVENT_2/3 could be mapped to some other
 * peripheral also.
 */
typedef enum
{
    /** Channel assigned to EDMA3 Event 0 */
    EDMA3_DRV_HW_CHANNEL_EVENT_0 = 0,
    /** Channel assigned to EDMA3 Event 1 */
    EDMA3_DRV_HW_CHANNEL_EVENT_1,
    /** Channel assigned to EDMA3 Event 2 */
    EDMA3_DRV_HW_CHANNEL_EVENT_2,
    /** Channel assigned to EDMA3 Event 3 */
    EDMA3_DRV_HW_CHANNEL_EVENT_3,
    /** Channel assigned to EDMA3 Event 4 */
    EDMA3_DRV_HW_CHANNEL_EVENT_4,
    /** Channel assigned to EDMA3 Event 5 */
    EDMA3_DRV_HW_CHANNEL_EVENT_5,
    /** Channel assigned to EDMA3 Event 6 */
    EDMA3_DRV_HW_CHANNEL_EVENT_6,
    /** Channel assigned to EDMA3 Event 7 */
    EDMA3_DRV_HW_CHANNEL_EVENT_7,
    /** Channel assigned to EDMA3 Event 8 */
    EDMA3_DRV_HW_CHANNEL_EVENT_8,
    /** Channel assigned to EDMA3 Event 9 */
    EDMA3_DRV_HW_CHANNEL_EVENT_9,
    /** Channel assigned to EDMA3 Event 10 */
    EDMA3_DRV_HW_CHANNEL_EVENT_10,
    /** Channel assigned to EDMA3 Event 11 */
    EDMA3_DRV_HW_CHANNEL_EVENT_11,
    /** Channel assigned to EDMA3 Event 12 */
    EDMA3_DRV_HW_CHANNEL_EVENT_12,
    /** Channel assigned to EDMA3 Event 13 */
    EDMA3_DRV_HW_CHANNEL_EVENT_13,
    /** Channel assigned to EDMA3 Event 14 */
    EDMA3_DRV_HW_CHANNEL_EVENT_14,
    /** Channel assigned to EDMA3 Event 15 */
    EDMA3_DRV_HW_CHANNEL_EVENT_15,
    /** Channel assigned to EDMA3 Event 16 */
    EDMA3_DRV_HW_CHANNEL_EVENT_16,
    /** Channel assigned to EDMA3 Event 17 */
    EDMA3_DRV_HW_CHANNEL_EVENT_17,
    /** Channel assigned to EDMA3 Event 18 */
    EDMA3_DRV_HW_CHANNEL_EVENT_18,
    /** Channel assigned to EDMA3 Event 19 */
    EDMA3_DRV_HW_CHANNEL_EVENT_19,
    /** Channel assigned to EDMA3 Event 20 */
    EDMA3_DRV_HW_CHANNEL_EVENT_20,
    /** Channel assigned to EDMA3 Event 21 */
    EDMA3_DRV_HW_CHANNEL_EVENT_21,
    /** Channel assigned to EDMA3 Event 22 */
    EDMA3_DRV_HW_CHANNEL_EVENT_22,
    /** Channel assigned to EDMA3 Event 23 */
    EDMA3_DRV_HW_CHANNEL_EVENT_23,
    /** Channel assigned to EDMA3 Event 24 */
    EDMA3_DRV_HW_CHANNEL_EVENT_24,
    /** Channel assigned to EDMA3 Event 25 */
    EDMA3_DRV_HW_CHANNEL_EVENT_25,
    /** Channel assigned to EDMA3 Event 26 */
    EDMA3_DRV_HW_CHANNEL_EVENT_26,
    /** Channel assigned to EDMA3 Event 27 */
    EDMA3_DRV_HW_CHANNEL_EVENT_27,
    /** Channel assigned to EDMA3 Event 28 */
    EDMA3_DRV_HW_CHANNEL_EVENT_28,
    /** Channel assigned to EDMA3 Event 29 */
    EDMA3_DRV_HW_CHANNEL_EVENT_29,
    /** Channel assigned to EDMA3 Event 30 */
    EDMA3_DRV_HW_CHANNEL_EVENT_30,
    /** Channel assigned to EDMA3 Event 31 */
    EDMA3_DRV_HW_CHANNEL_EVENT_31,
    /** Channel assigned to EDMA3 Event 32 */
    EDMA3_DRV_HW_CHANNEL_EVENT_32,
    /** Channel assigned to EDMA3 Event 33 */
    EDMA3_DRV_HW_CHANNEL_EVENT_33,
    /** Channel assigned to EDMA3 Event 34 */
    EDMA3_DRV_HW_CHANNEL_EVENT_34,
    /** Channel assigned to EDMA3 Event 35 */
    EDMA3_DRV_HW_CHANNEL_EVENT_35,
    /** Channel assigned to EDMA3 Event 36 */
    EDMA3_DRV_HW_CHANNEL_EVENT_36,
    /** Channel assigned to EDMA3 Event 37 */
    EDMA3_DRV_HW_CHANNEL_EVENT_37,
    /** Channel assigned to EDMA3 Event 38 */
    EDMA3_DRV_HW_CHANNEL_EVENT_38,
    /** Channel assigned to EDMA3 Event 39 */
    EDMA3_DRV_HW_CHANNEL_EVENT_39,
    /** Channel assigned to EDMA3 Event 40 */
    EDMA3_DRV_HW_CHANNEL_EVENT_40,
    /** Channel assigned to EDMA3 Event 41 */
    EDMA3_DRV_HW_CHANNEL_EVENT_41,
    /** Channel assigned to EDMA3 Event 42 */
    EDMA3_DRV_HW_CHANNEL_EVENT_42,
    /** Channel assigned to EDMA3 Event 43 */
    EDMA3_DRV_HW_CHANNEL_EVENT_43,
    /** Channel assigned to EDMA3 Event 44 */
    EDMA3_DRV_HW_CHANNEL_EVENT_44,
    /** Channel assigned to EDMA3 Event 45 */
    EDMA3_DRV_HW_CHANNEL_EVENT_45,
    /** Channel assigned to EDMA3 Event 46 */
    EDMA3_DRV_HW_CHANNEL_EVENT_46,
    /** Channel assigned to EDMA3 Event 47 */
    EDMA3_DRV_HW_CHANNEL_EVENT_47,
    /** Channel assigned to EDMA3 Event 48 */
    EDMA3_DRV_HW_CHANNEL_EVENT_48,
    /** Channel assigned to EDMA3 Event 49 */
    EDMA3_DRV_HW_CHANNEL_EVENT_49,
    /** Channel assigned to EDMA3 Event 50 */
    EDMA3_DRV_HW_CHANNEL_EVENT_50,
    /** Channel assigned to EDMA3 Event 51 */
    EDMA3_DRV_HW_CHANNEL_EVENT_51,
    /** Channel assigned to EDMA3 Event 52 */
    EDMA3_DRV_HW_CHANNEL_EVENT_52,
    /** Channel assigned to EDMA3 Event 53 */
    EDMA3_DRV_HW_CHANNEL_EVENT_53,
    /** Channel assigned to EDMA3 Event 54 */
    EDMA3_DRV_HW_CHANNEL_EVENT_54,
    /** Channel assigned to EDMA3 Event 55 */
    EDMA3_DRV_HW_CHANNEL_EVENT_55,
    /** Channel assigned to EDMA3 Event 56 */
    EDMA3_DRV_HW_CHANNEL_EVENT_56,
    /** Channel assigned to EDMA3 Event 57 */
    EDMA3_DRV_HW_CHANNEL_EVENT_57,
    /** Channel assigned to EDMA3 Event 58 */
    EDMA3_DRV_HW_CHANNEL_EVENT_58,
    /** Channel assigned to EDMA3 Event 59 */
    EDMA3_DRV_HW_CHANNEL_EVENT_59,
    /** Channel assigned to EDMA3 Event 60 */
    EDMA3_DRV_HW_CHANNEL_EVENT_60,
    /** Channel assigned to EDMA3 Event 61 */
    EDMA3_DRV_HW_CHANNEL_EVENT_61,
    /** Channel assigned to EDMA3 Event 62 */
    EDMA3_DRV_HW_CHANNEL_EVENT_62,
    /** Channel assigned to EDMA3 Event 63 */
    EDMA3_DRV_HW_CHANNEL_EVENT_63
} EDMA3_DRV_HW_CHANNEL_EVENT;


/**
 * \brief QDMA Channel defines
 * They should be used while requesting a specific QDMA channel.
 */
/** QDMA Channel 0 */
#define EDMA3_DRV_QDMA_CHANNEL_0                 (edma3NumPaRAMSets)
/** QDMA Channel 1 */
#define EDMA3_DRV_QDMA_CHANNEL_1                 (EDMA3_DRV_QDMA_CHANNEL_0+1u)
/** QDMA Channel 2 */
#define EDMA3_DRV_QDMA_CHANNEL_2                 (EDMA3_DRV_QDMA_CHANNEL_0+2u)
/** QDMA Channel 3 */
#define EDMA3_DRV_QDMA_CHANNEL_3                 (EDMA3_DRV_QDMA_CHANNEL_0+3u)
/** QDMA Channel 4 */
#define EDMA3_DRV_QDMA_CHANNEL_4                 (EDMA3_DRV_QDMA_CHANNEL_0+4u)
/** QDMA Channel 5 */
#define EDMA3_DRV_QDMA_CHANNEL_5                 (EDMA3_DRV_QDMA_CHANNEL_0+5u)
/** QDMA Channel 6 */
#define EDMA3_DRV_QDMA_CHANNEL_6                 (EDMA3_DRV_QDMA_CHANNEL_0+6u)
/** QDMA Channel 7 */
#define EDMA3_DRV_QDMA_CHANNEL_7                 (EDMA3_DRV_QDMA_CHANNEL_0+7u)



/**
 *  \brief Request for a DMA channel
 *
 *  Each channel (DMA/QDMA/Link) must be requested  before initiating a DMA
 *  transfer on that channel.
 *
 *  Specify the event queue to which the requested channel should be mapped.
 *  Generally, event queue 0 has higher priority than event queue 1.
 *
 *  \param  hEdma            [IN]     Handle to the EDMA Driver Instance.
 *
 *  \param  pLCh             [IN/OUT] Requested logical channel number.
 *                                    Examples:
 *                                      - EDMA3_DRV_HW_CHANNEL_EVENT_0
 *                                      - To request a DMA Master Channel
 *                                        mapped to EDMA Event 0.
 *
 *                                      - EDMA3_DRV_DMA_CHANNEL_ANY
 *                                      - For requesting any DMA Master channel
 *                                        with no event mapping.
 *
 *                                      - EDMA3_DRV_QDMA_CHANNEL_ANY
 *                                      - For requesting any QDMA Master channel
 *
 *                                      - EDMA3_DRV_QDMA_CHANNEL_0
 *                                      - For requesting the QDMA Channel 0.
 *
 *                                      - EDMA3_DRV_LINK_CHANNEL
 *                                      - For requesting a DMA Slave Channel,
                                        - to be linked to some other Master
                                        - channel.
 *
 *  \note To request  a PaRAM Set (plus associated TCC) for the purpose of
 *        linking to another channel,  call the function with
 *
 *        *pLCh = EDMA3_DRV_LINK_CHANNEL;
 *
 *         This function will update *pLCh with the allocated PaRAM Set Id
 *
 *  \param  pTcc             [IN/OUT] The channel number on which the
 *                                    completion/error interrupt is generated
 *                                    Examples:
 *                                      - EDMA3_DRV_HW_CHANNEL_EVENT_0
 *                                      - To request TCC associated with
 *                                      - DMA Master Channel mapped to EDMA
 *                                      - event 0.
 *
 *                                      - EDMA3_DRV_TCC_ANY
 *                                      - For requesting any TCC with no
 *                                      - channel mapping.
 *
 *  \param  evtQueue         [IN]     Event Queue Number to which the channel
 *                                    will be mapped (valid only for the Master
 *                                    Channel request)
 *
 *  \param tccCb             [IN]     TCC callback - caters to channel-specific
 *                                    events like "Event Miss Error" or
 *                                    "Transfer Complete"
 *
 *  \param cbData            [IN]     Data which will be passed directly to the
 *                                    tccCb callback function
 *
 *  \return EDMA3_DRV_SOK or EDMA3_DRV Error code
 *
 *  \note    This function internally uses EDMA3 Resource Manager, which
 *           acquires a RM Instance specific semaphore
 *           to prevent simultaneous access to the global pool of resources.
 *           It also disables the global interrupts while modifying
 *           the global CC registers.
 *           It is re-entrant, but SHOULD NOT be called from the user callback
 *           function (ISR context).
 */
EDMA3_DRV_Result EDMA3_DRV_requestChannel (
        EDMA3_DRV_Handle hEdma,
        unsigned int *pLCh,
        unsigned int *pTcc,
        EDMA3_RM_EventQueue evtQueue,
        EDMA3_RM_TccCallback tccCb,
        void *cbData);


/**
 *  \brief Free the specified channel (DMA/QDMA/Link) and its associated
 *  resources (PaRAM Set, TCC etc) and removes various mappings.
 *
 *  \param  hEdma            [IN]     Handle to the EDMA Driver Instance.
 *  \param  channelId        [IN]     Logical Channel number to be freed.
 *
 *  \return EDMA3_DRV_SOK or EDMA3_DRV Error code
 *
 *  \note    This function disables the global interrupts while modifying
 *           the global CC registers and while modifying global data structures,
 *           to prevent simultaneous access to the global pool of resources.
 *           It is re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_freeChannel (EDMA3_DRV_Handle hEdma,
                                                unsigned int channelId);



/**
 *  \brief  It clears Event Registers and Error Registers for a specific
 *  channel and brings back EDMA3 to its initial state.
 *
 *  \param  hEdma            [IN]     Handle to the EDMA Driver Instance.
 *  \param  channelId        [IN]     Logical Channel number to be cleaned.
 *
 *  \return EDMA3_DRV_SOK or EDMA3_DRV Error code
 *
 *  \note    This function is re-entrant for unique channelId values. It is non-
 *          re-entrant for same channelId value.
 */
EDMA3_DRV_Result EDMA3_DRV_clearErrorBits (EDMA3_DRV_Handle hEdma,
                                                    unsigned int channelId);

/**
 * \brief  Link two logical channels.
 *
 * \note   After linking the channels, user should not update any
 *         PaRAM Set of the channel.
 *
 * \param   hEdma           [IN]    Handle to the EDMA Driver Instance.
 * \param   lCh1            [IN]    Logical Channel to which particular channel
 *                                  will be linked.
 * \param   lCh2            [IN]    Logical Channel which needs to be linked to
 *                                  the first channel.
 *                                  After the transfer based on the PaRAM set
 *                                  of lCh1 is over, the PaRAM set of lCh2 will
 *                                  be copied to the PaRAM set of lCh1 and
 *                                  transfer will resume.
 *                                  For DMA channels, another sync event is
 *                                  required to initiate
 *                                  the transfer on Link channel.
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh1 & lCh2 values. It is
 *          non-re-entrant for same lCh1 & lCh2 values.
 */
EDMA3_DRV_Result EDMA3_DRV_linkChannel ( EDMA3_DRV_Handle hEdma,
                                                unsigned int lCh1,
                                                unsigned int lCh2);

/**
 * \brief  Unlink the channel from the earlier linked logical channel.
 *
 *         This function breaks the link between the specified
 *         channel and the earlier linked logical channel
 *         by clearing the Link Address field.
 *
 * \param  hEdma             [IN]    Handle to the EDMA Driver Instance.
 * \param  lCh               [IN]    Channel for which linking has to be removed
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_unlinkChannel (EDMA3_DRV_Handle hEdma,
                                                    unsigned int lCh);

/* @} Edma3DrvChannelSetup */



/**
 * \defgroup Edma3DrvTransferSetupType EDMA3 Driver Typical EDMA Transfer Setup
 *
 * The typical EDMA transfer related Interface of the EDMA3 Driver
 *
 * @{
 */

/**
 * \brief OPT Field Offset.
 *
 * Use this enum to set or get any of the
 * Fields within an OPT of a Parameter RAM set.
 */
typedef enum
{
        /**
         * The SAM field (Bit 0)
         */
        EDMA3_DRV_OPT_FIELD_SAM = 0,

        /**
         * The DAM field (Bit 1)
         */
        EDMA3_DRV_OPT_FIELD_DAM = 1,

        /**
         * The SYNCDIM field (Bit 2)
         */
        EDMA3_DRV_OPT_FIELD_SYNCDIM = 2,

        /**
         * The STATIC field (Bit 3)
         */
        EDMA3_DRV_OPT_FIELD_STATIC  = 3,

        /**
         * The FWID field (Bitfield 8-10)
         */
        EDMA3_DRV_OPT_FIELD_FWID = 4,

        /**
         * The TCCMODE field (Bit 11)
         */
        EDMA3_DRV_OPT_FIELD_TCCMODE = 5,

        /**
         * The TCC field (Bitfield 12-17)
         */
        EDMA3_DRV_OPT_FIELD_TCC = 6,

        /**
         * The TCINTEN field (Bit 20)
         */
        EDMA3_DRV_OPT_FIELD_TCINTEN = 7,

        /**
         * The ITCINTEN field (Bit 21)
         */
        EDMA3_DRV_OPT_FIELD_ITCINTEN = 8,

        /**
         * The TCCHEN field (Bit 22)
         */
        EDMA3_DRV_OPT_FIELD_TCCHEN = 9,

        /**
         * The ITCCHEN field (Bit 23)
         */
        EDMA3_DRV_OPT_FIELD_ITCCHEN = 10

} EDMA3_DRV_OptField;


/**
 * \brief EDMA Addressing modes
 *
 * The EDMA3 TC supports two addressing modes
 *           -# Increment transfer
 *           -# FIFO transfer
 *
 * The SAM (Source Addressing Mode) and the DAM (Destination Addressing Mode)
 * can be independently set to either of the two via the OPT register.
 *
 */
typedef enum
{
        /** Addressing within an array increments */
        EDMA3_DRV_ADDR_MODE_INCR            = 0,

        /** Addressing within an array wraps around upon reaching fifo width */
        EDMA3_DRV_ADDR_MODE_FIFO            = 1
} EDMA3_DRV_AddrMode;



/**
 * \brief EDMA Transfer Synchronization type.
 *
 * Two types of Synchronization of transfers are possible
 *     -# A Synchronized
 *     -# AB Syncronized
 * - A Sync
 *     -# Each Array is submitted as one TR
 *     -# (BCNT*CCNT) number of sync events are needed to completely service
 *        a PaRAM set. (Where BCNT = Num of Arrays in a Frame;
 *                            CCNT = Num of Frames in a Block)
 *     -# (S/D)CIDX = (Addr of First array in next frame)
 *              minus (Addr of Last array in present frame)
 *     (Where CIDX is the Inter-Frame index)
 *
 * - AB Sync
 *     -# Each Frame is submitted as one TR
 *     -# Only CCNT number of sync events are needed to completely service
 *        a PaRAM set
 *     -# (S/D)CIDX = (Addr of First array in next frame)
 *              minus (Addr of First array of present frame)
 *
 * \note ABC sync transfers can be achieved logically by chaining multiple
 *       AB sync transfers
 *
 */
typedef enum
{
        /**
         * A-synchronized.
         * Each event triggers the transfer of a single array of ACNT bytes
         */
        EDMA3_DRV_SYNC_A = 0 ,

        /**
         * AB-synchronized.
         * Each event triggers the transfer of BCNT arrays of ACNT bytes
         */
    EDMA3_DRV_SYNC_AB = 1

} EDMA3_DRV_SyncType;


/**
 * \brief True/False: PaRAM set is Static or not. A Static PaRAM set
 * is updated or linked after TR is submitted.
 */
typedef enum
{
    /**
     * PaRAM set is not Static. PaRAM set is updated or linked
     * after TR is submitted. A value of 0 should be used for
     * DMA channels and for nonfinal transfers in a linked list
     * of QDMA transfers
     */
    EDMA3_DRV_STATIC_DIS      = 0,

    /**
     * PaRAM set is Static. PaRAM set is not updated or linked
     * after TR is submitted. A value of 1 should be used for
     * isolated QDMA transfers or for the final transfer in a
     * linked list of QDMA transfers.
     */
    EDMA3_DRV_STATIC_EN       = 1
} EDMA3_DRV_StaticMode;


/**
 * \brief EDMA3 FIFO width.
 *
 * The user can set the width of the FIFO using this enum.
 * This is done via the OPT register.
 * This is valid only if the EDMA3_DRV_ADDR_MODE_FIFO value is used for the
 * enum EDMA3_DRV_AddrMode.
 */
typedef enum
{
        /** FIFO width is 8-bit. */
        EDMA3_DRV_W8BIT = 0,

        /** FIFO width is 16-bit. */
        EDMA3_DRV_W16BIT = 1,

        /** FIFO width is 32-bit. */
        EDMA3_DRV_W32BIT = 2,

        /** FIFO width is 64-bit. */
        EDMA3_DRV_W64BIT = 3,

        /** FIFO width is 128-bit. */
        EDMA3_DRV_W128BIT = 4,

        /** FIFO width is 256-bit. */
        EDMA3_DRV_W256BIT = 5

} EDMA3_DRV_FifoWidth;




/**
 * \brief Transfer complete code mode.
 * Indicates the point at which a transfer is considered completed for
 * chaining and interrupt generation
 */
typedef enum
{
    /** A transfer is considered completed after transfer of data */
    EDMA3_DRV_TCCMODE_NORMAL      = 0,

    /**
     * A transfer is considered completed after the EDMA3CC submits a TR
     * to the EDMA3TC. TC may still be transferring data when interrupt/chain
     * is triggered.
     */
    EDMA3_DRV_TCCMODE_EARLY       = 1
} EDMA3_DRV_TccMode;


/**
 * \brief Transfer complete interrupt enable.
 */
typedef enum
{
    /** Transfer complete interrupt is disabled */
    EDMA3_DRV_TCINTEN_DIS      = 0,

    /** Transfer complete interrupt is enabled */
    EDMA3_DRV_TCINTEN_EN       = 1
} EDMA3_DRV_TcintEn;


/**
 * \brief Intermediate Transfer complete interrupt enable.
 */
typedef enum
{
    /** Intermediate Transfer complete interrupt is disabled */
    EDMA3_DRV_ITCINTEN_DIS      = 0,

    /** Intermediate Transfer complete interrupt is enabled */
    EDMA3_DRV_ITCINTEN_EN       = 1
} EDMA3_DRV_ItcintEn;


/**
 * \brief Transfer complete chaining enable.
 */
typedef enum
{
    /** Transfer complete chaining is disabled */
    EDMA3_DRV_TCCHEN_DIS      = 0,

    /** Transfer complete chaining is enabled */
    EDMA3_DRV_TCCHEN_EN       = 1
} EDMA3_DRV_TcchEn;


/**
 * \brief Intermediate Transfer complete chaining enable.
 */
typedef enum
{
    /** Intermediate Transfer complete chaining is disabled */
    EDMA3_DRV_ITCCHEN_DIS      = 0,

    /** Intermediate Transfer complete chaining is enabled */
    EDMA3_DRV_ITCCHEN_EN       = 1
} EDMA3_DRV_ItcchEn;


/**
 * \brief Structure to be used to configure interrupt generation
 * and chaining options.
 */
typedef struct
{
    /** Transfer complete chaining enable */
    EDMA3_DRV_TcchEn    tcchEn;

    /** Intermediate Transfer complete chaining enable */
    EDMA3_DRV_ItcchEn   itcchEn;

    /** Transfer complete interrupt enable */
    EDMA3_DRV_TcintEn   tcintEn;

    /** Intermediate Transfer complete interrupt enable */
    EDMA3_DRV_ItcintEn  itcintEn;
} EDMA3_DRV_ChainOptions;



/**
 * \brief   Set a particular OPT field of specified PaRAM set.
 *
 *
 * \param   hEdma       [IN]    Handle to the EDMA Instance object
 * \param   lCh         [IN]    Logical Channel bound to the Parameter RAM set
 *                              whose OPT field needs to be set
 * \param   optField    [IN]    The particular field of OPT that needs setting
 * \param   newOptFieldVal [IN]    The new OPT field setting
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setOptField (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_DRV_OptField optField,
                    unsigned int newOptFieldVal);


/**
 * \brief   Get the particular field of specified PaRAM set.
 *
 *
 * \param   hEdma           [IN]    Handle to the EDMA Instance object
 * \param   lCh             [IN]    Logical Channel bound to the PaRAM set
 *                                  whose OPT field is needed
 * \param   optField        [IN]    The particular field of OPT that is needed
 * \param   optFieldVal     [IN/OUT]Value of the field
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_getOptField (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_DRV_OptField optField,
                    unsigned int *optFieldVal);


/**
 * \brief  DMA source parameters setup
 *
 * \param   hEdma       [IN]    Handle to the EDMA Driver Instance
 * \param   lCh         [IN]    Logical Channel for which the source parameters
 *                              are to be configured
 * \param   srcAddr     [IN]    Source address
 * \param   addrMode    [IN]    Address mode [FIFO or Increment]
 * \param   fifoWidth   [IN]    Width of FIFO (Valid only if addrMode is FIFO)
 *                                  -# 0 - 8 bit
 *                                  -# 1 - 16 bit
 *                                  -# 2 - 32 bit
 *                                  -# 3 - 64 bit
 *                                  -# 4 - 128 bit
 *                                  -# 5 - 256 bit
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setSrcParams ( EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    unsigned int srcAddr,
                    EDMA3_DRV_AddrMode addrMode,
                    EDMA3_DRV_FifoWidth fifoWidth);


/**
 * \brief  DMA Destination parameters setup
 *
 * \param   hEdma       [IN]    Handle to the EDMA Driver Instance
 * \param   lCh         [IN]    Logical Channel for which the destination
 *                              parameters are to be configured
 * \param   destAddr    [IN]    Destination address
 * \param   addrMode    [IN]    Address mode [FIFO or Increment]
 * \param   fifoWidth   [IN]    Width of FIFO (Valid only if addrMode is FIFO)
 *                                  -# 0 - 8 bit
 *                                  -# 1 - 16 bit
 *                                  -# 2 - 32 bit
 *                                  -# 3 - 64 bit
 *                                  -# 4 - 128 bit
 *                                  -# 5 - 256 bit
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setDestParams ( EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    unsigned int destAddr,
                    EDMA3_DRV_AddrMode addrMode,
                    EDMA3_DRV_FifoWidth fifoWidth );

/**
 * \brief   DMA source index setup
 *
 * \param   hEdma       [IN] Handle to the EDMA Driver Instance
 * \param   lCh         [IN] Logical Channel for which source indices
 *                           are to be configured
 * \param   srcBIdx     [IN] The source index which gives the offset
 *                           between successive Arrays to be transferred
 *                           This index is used for source address
 *                           modification in the 2nd Dimension
 *                           Valid range : -32768 to 32767
 * \param   srcCIdx     [IN] The source index which gives the offset between
 *                           successive frames to be transferred.
 *                           This index is used for source address
 *                           modification in the 3rd Dimension
 *                           Valid range : -32768 to 32767
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setSrcIndex ( EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    int srcBIdx,
                    int srcCIdx );


/**
 * \brief   DMA destination index setup
 *
 * \param   hEdma       [IN] Handle to the EDMA Driver Instance
 * \param   lCh         [IN] Logical Channel for which dest indices
 *                           are to be configured
 * \param   destBIdx    [IN] The dest. index which gives the offset between
 *                           successive Arrays to be transferred
 *                           This index is used for dest address
 *                           modification in the 2nd Dimension
 *                           Valid range : -32768 to 32767
 * \param   destCIdx    [IN] The dest. index which gives the offset between
 *                           successive frames to be transferred
 *                           This index is used for dest address
 *                           modification in the 3rd Dimension
 *                           Valid range : -32768 to 32767
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result  EDMA3_DRV_setDestIndex (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    int destBIdx,
                    int destCIdx);


/**
 * \brief       DMA transfer parameters setup
 *
 * \param   hEdma           [IN] Handle to the EDMA Driver Instance
 * \param       lCh         [IN] Logical Channel for which transfer parameters
 *                              are to be configured
 * \param       aCnt        [IN] Count for 1st Dimension.  This is the number of
 *                              bytes in an array. Valid range : 1 to 65535
 *                              Value of 0 will result in a null/dummy transfer
 * \param       bCnt        [IN] Count for 2nd Dimension.  This is the number of
 *                              arrays in a frame. Valid range : 1 to 65535
 *                              Value of 0 will result in a null/dummy transfer
 * \param       cCnt        [IN] Count for 3rd Dimension.  This is the number of
 *                              frames in a block. Valid range : 1 to 65535
 *                              Value of 0 will result in a null/dummy transfer
 * \param       bCntReload  [IN] Reload value for bCnt.  It is used to reload
 *                              the BCNT field once the last array in the 2nd
 *                              dimension is transferred. This field is only
 *                              used for A-synchronized transfers. For
 *                              AB-synchronized transfers, BCNTRLD is not used.
 * \param       syncType    [IN] Selection between A-Sync and AB-Sync Transfer
 *
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setTransferParams (
                        EDMA3_DRV_Handle hEdma,
                        unsigned int lCh,
                        unsigned int aCnt,
                        unsigned int bCnt,
                        unsigned int cCnt,
                        unsigned int bCntReload,
                        EDMA3_DRV_SyncType syncType);



/**
 * \brief   Chain the two specified channels.
 *
 * \param   hEdma               [IN]    Handle to the EDMA Driver Instance.
 *
 * \param   lCh1                [IN]    Channel to which particular channel
 *                                      will be chained.
 * \param   lCh2                [IN]    Channel which needs to be chained to
 *                                      the first channel.
 * \param   chainOptions        [IN]    Options such as intermediate interrupts
 *                                      are required or not.
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh1 & lCh2 values. It is
 *          non-re-entrant for same lCh1 & lCh2 values.
 */
EDMA3_DRV_Result EDMA3_DRV_chainChannel (EDMA3_DRV_Handle hEdma,
                                        unsigned int lCh1,
                                        unsigned int lCh2,
                                        EDMA3_DRV_ChainOptions chainOptions);


/**
 * \brief   Unchain the two channels.
 *
 * \param   hEdma               [IN]    Handle to the EDMA Driver Instance.
 * \param   lCh                 [IN]    Channel whose chaining with the other
 *                                      channel has to be removed.
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_unchainChannel (EDMA3_DRV_Handle hEdma,
                        unsigned int lCh);


/**
 * \brief EDMA Trigger Mode Selection
 *
 * Use this enum to select the EDMA trigger mode while enabling
 * the EDMA transfer
 */
typedef enum
{
        /**
         * Set the Trigger mode to Manual .
         * The CPU manually triggers a transfer by writing a 1 to the
         * corresponding bit in the event set register (ESR/ESRH).
         */
        EDMA3_DRV_TRIG_MODE_MANUAL = 0,

        /**
         * Set the Trigger mode to QDMA.
         * A QDMA transfer is triggered when a CPU (or other EDMA3
         * programmer) writes to the trigger word of the
         * QDMA channel parameter set (autotriggered) or when the
         * EDMA3CC performs a link update on a PaRAM
         * set that has been mapped to a QDMA channel (link triggered).
         */
        EDMA3_DRV_TRIG_MODE_QDMA = 1,

        /**
         * Set the Trigger mode to Event.
         * Allows for a peripheral, system, or externally-generated
         * event to trigger a transfer request.
         */
        EDMA3_DRV_TRIG_MODE_EVENT = 2

} EDMA3_DRV_TrigMode;


/**
 * \brief       Start EDMA transfer on the specified channel.
 *
 * \param  hEdma        [IN]    Handle to the EDMA Driver Instance
 * \param  lCh          [IN]    Channel on which transfer has to be started
 * \param  trigMode     [IN]    Mode of triggering start of transfer (Manual,
 *                              QDMA or Event)
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_enableTransfer (EDMA3_DRV_Handle hEdma,
                        unsigned int lCh,
                        EDMA3_DRV_TrigMode trigMode);


/**
 * \brief       Disable DMA transfer on the specified channel
 *
 * \param   hEdma       [IN]    Handle to the EDMA Driver Instance
 * \param   lCh         [IN]    Channel on which transfer has to be stopped
 * \param   trigMode    [IN]    Mode of triggering start of transfer
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_disableTransfer (EDMA3_DRV_Handle hEdma,
                        unsigned int lCh,
                        EDMA3_DRV_TrigMode trigMode);

/* @} Edma3DrvTransferSetupType */

/**
 * \defgroup Edma3DrvTransferSetupOpt EDMA3 Driver Optional Setup for EDMA
 * Transfer.
 *
 * The Optional EDMA transfer related Interface of the EDMA3 Driver
 *
 * @{
 */

/**
 * \brief PaRAM Set Entry type
 *
 * Use this enum to set or get any of the
 * 8 DWords(unsigned int) within a Parameter RAM set
 */
typedef enum
{
    /**
     * The OPT field (Offset Address 0h Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_OPT                       = 0,
    /**
     * The SRC field (Offset Address 4h Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_SRC                       = 1,
    /**
     * The (ACNT+BCNT) field (Offset Address 8h Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_ACNT_BCNT                 = 2,
    /**
     * The DST field (Offset Address Ch Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_DST                       = 3,
    /**
     * The (SRCBIDX+DSTBIDX) field (Offset Address 10h Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_SRC_DST_BIDX              = 4,
    /**
     * The (LINK+BCNTRLD) field (Offset Address 14h Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_LINK_BCNTRLD              = 5,
    /**
     * The (SRCCIDX+DSTCIDX) field (Offset Address 18h Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_SRC_DST_CIDX              = 6,
    /**
     * The (CCNT+RSVD) field (Offset Address 1Ch Bytes)
     */
    EDMA3_DRV_PARAM_ENTRY_CCNT                      = 7
} EDMA3_DRV_PaRAMEntry;


/**
 * \brief PaRAM Set Field type
 *
 * Use this enum to set or get any of the PaRAM set fields
 */
typedef enum
{
    /** OPT field of PaRAM Set */
    EDMA3_DRV_PARAM_FIELD_OPT           = 0,
    /**
     * \brief Starting byte address of Source
     * For FIFO mode, srcAddr must be a 256-bit aligned address.
     */
    EDMA3_DRV_PARAM_FIELD_SRCADDR       = 1,
    /**
     * \brief Number of bytes in each Array (ACNT)
     */
    EDMA3_DRV_PARAM_FIELD_ACNT          = 2,
    /**
     * \brief Number of Arrays in each Frame (BCNT)
     */
    EDMA3_DRV_PARAM_FIELD_BCNT          = 3,
    /**
     * \brief Starting byte address of destination
     * For FIFO mode, destAddr must be a 256-bit aligned address.
     */
    EDMA3_DRV_PARAM_FIELD_DESTADDR      = 4,
    /**
     * \brief Index between consec. arrays of a Source Frame (SRCBIDX)
     * If SAM is set to 1 (via channelOptions) then srcInterArrIndex should
     * be an even multiple of 32 bytes.
     */
    EDMA3_DRV_PARAM_FIELD_SRCBIDX       = 5,

    /**
     * \brief Index between consec. arrays of a Destination Frame (DSTBIDX)
     * If DAM is set to 1 (via channelOptions) then destInterArrIndex should
     * be an even multiple of 32 bytes
     */
    EDMA3_DRV_PARAM_FIELD_DESTBIDX      = 6,
    /**
     * \brief Address for linking (AutoReloading of a PaRAM Set)
     * This must point to a valid aligned 32-byte PaRAM set
     * A value of 0xFFFF means no linking
     * Linking is especially useful for use with ping-pong buffers and
     * circular buffers
     */
    EDMA3_DRV_PARAM_FIELD_LINKADDR      = 7,
    /**
     * \brief Reload value of the numArrInFrame (BCNT)
     * Relevant only for A-sync transfers
     */
    EDMA3_DRV_PARAM_FIELD_BCNTRELOAD    = 8,
    /**
     * \brief Index between consecutive frames of a Source Block (SRCCIDX)
     */
    EDMA3_DRV_PARAM_FIELD_SRCCIDX       = 9,
    /**
     * \brief Index between consecutive frames of a Dest Block (DSTCIDX)
     */
    EDMA3_DRV_PARAM_FIELD_DESTCIDX      = 10,
    /**
     * \brief Number of Frames in a block (CCNT)
     */
    EDMA3_DRV_PARAM_FIELD_CCNT          = 11
} EDMA3_DRV_PaRAMField;


/**
 * \brief EDMA3 Parameter RAM Set in User Configurable format
 *
 * This is a mapping of the EDMA3 PaRAM set provided to the user
 * for ease of modification of the individual fields
 */
typedef struct  {
        /** OPT field of PaRAM Set */
        volatile unsigned int opt;

        /**
         * \brief Starting byte address of Source
         * For FIFO mode, srcAddr must be a 256-bit aligned address.
         */
        volatile unsigned int srcAddr;

        /**
         * \brief Number of bytes in each Array (ACNT)
         */
        volatile unsigned short aCnt;

        /**
         * \brief Number of Arrays in each Frame (BCNT)
         */
        volatile unsigned short bCnt;

        /**
         * \brief Starting byte address of destination
         * For FIFO mode, destAddr must be a 256-bit aligned address.
         * i.e. 5 LSBs should be 0.
         */
        volatile unsigned int destAddr;

        /**
         * \brief Index between consec. arrays of a Source Frame (SRCBIDX)
         * If SAM is set to 1 (via channelOptions) then srcInterArrIndex should
         * be an even multiple of 32 bytes.
         */
        volatile short  srcBIdx;

        /**
         * \brief Index between consec. arrays of a Destination Frame (DSTBIDX)
         * If DAM is set to 1 (via channelOptions) then destInterArrIndex should
         * be an even multiple of 32 bytes
         */
        volatile short  destBIdx;

        /**
         * \brief Address for linking (AutoReloading of a PaRAM Set)
         * This must point to a valid aligned 32-byte PaRAM set
         * A value of 0xFFFF means no linking
         * Linking is especially useful for use with ping-pong buffers and
         * circular buffers
         */
        volatile unsigned short linkAddr;

        /**
         * \brief Reload value of the numArrInFrame (BCNT)
         * Relevant only for A-sync transfers
         */
        volatile unsigned short bCntReload;

        /**
         * \brief Index between consecutive frames of a Source Block (SRCCIDX)
         */
        volatile short  srcCIdx;

        /**
         * \brief Index between consecutive frames of a Dest Block (DSTCIDX)
         */
        volatile short  destCIdx;

        /**
         * \brief Number of Frames in a block (CCNT)
         */
        volatile unsigned short cCnt;

} EDMA3_DRV_PaRAMRegs;


/**
 * \brief Event queue priorities setup
 *
 * It allows to change the priority of the individual queues and the
 * priority of the transfer request (TR) associated with the
 * events queued in the queue.
 */
typedef struct
{
    /**
     * \brief Event Queue Priorities
     */
    unsigned int evtQPri[EDMA3_MAX_EVT_QUE];
}EDMA3_DRV_EvtQuePriority;



/**
 * \brief  Assign a Trigger Word to the specified QDMA channel
 *
 *
 * \param   hEdma      [IN]    Handle to the EDMA Instance object
 * \param   lCh        [IN]    QDMA Channel which needs to be assigned
 *                             the Trigger Word
 * \param   trigWord   [IN]    The Trigger Word for the QDMA channel.
 *                             Trigger Word is the word in the PaRAM
 *                             Register Set which, when written to by CPU,
 *                             will start the QDMA transfer automatically.
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setQdmaTrigWord (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_RM_QdmaTrigWord trigWord);


/**
 * \brief   Copy new Parameter RAM set to specified logical channel
 *
 * \param   hEdma       [IN]  Handle to the EDMA Instance object
 * \param   lCh         [IN]  Logical Channel for which new PaRAM set is
 *                            specified
 * \param   newPaRAM    [IN]  Parameter RAM set to be copied onto existing PaRAM
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setPaRAM ( EDMA3_DRV_Handle hEdma,
                        unsigned int lCh,
                        const EDMA3_DRV_PaRAMRegs *newPaRAM);


/**
 * \brief   Retrieve existing PaRAM set associated with specified logical
 *          channel
 *
 * \param   hEdma           [IN]     Handle to the EDMA Instance object
 * \param   lCh             [IN]     Logical Channel whose PaRAM set is
 *                                   requested
 * \param   currPaRAM       [IN/OUT] User gets the existing PaRAM into this
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_getPaRAM (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_DRV_PaRAMRegs *currPaRAM);

/**
 * \brief   Set a particular PaRAM set entry of the specified PaRAM set
 *
 *
 * \param   hEdma       [IN]    Handle to the EDMA Driver Instance
 * \param   lCh         [IN]    Logical Channel bound to the Parameter RAM set
 *                              whose specified field needs to be set
 * \param   paRAMEntry  [IN]    Specify the PaRAM set entry which needs
 *                              to be set
 * \param   newPaRAMEntryVal [IN]    The new field setting
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This API should be used while setting the PaRAM set entry
 *          for QDMA channels. If EDMA3_DRV_setPaRAMField () used,
 *          it will trigger the QDMA channel before complete
 *          PaRAM set entry is written. For DMA channels, no such
 *          constraint is there.
 *
 *          This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setPaRAMEntry (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_DRV_PaRAMEntry paRAMEntry,
                    unsigned int newPaRAMEntryVal);


/**
 * \brief   Get a particular PaRAM set entry of the specified PaRAM set
 *
 *
 * \param   hEdma       [IN]    Handle to the EDMA Driver Instance
 * \param   lCh         [IN]    Logical Channel bound to the Parameter RAM set
 *                              whose specified field value is needed
 * \param   paRAMEntry  [IN]    Specify the PaRAM set entry which needs
 *                              to be obtained
 * \param   paRAMEntryVal [IN]  The value of the field
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_getPaRAMEntry (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_DRV_PaRAMEntry paRAMEntry,
                    unsigned int *paRAMEntryVal);


/**
 * \brief   Set a particular PaRAM set field of the specified PaRAM set
 *
 *
 * \param   hEdma               [IN]    Handle to the EDMA Driver Instance
 * \param   lCh                 [IN]    Logical Channel bound to the PaRAM set
 *                                      whose specified field needs to be set
 * \param   paRAMField          [IN]    Specify the PaRAM set field which needs
 *                                      to be set
 * \param   newPaRAMFieldVal    [IN]    The new field setting
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This API CANNOT be used while setting the PaRAM set
 *          field for QDMA channels. It can trigger the QDMA channel before
 *          complete PaRAM set ENTRY (4-bytes field) is written (for eg, as
 *          soon one sets the ACNT field for QDMA channel, transfer is started,
 *          before one modifies the BCNT field). For DMA channels, no such
 *          constraint is there.
 *
 *          This function is re-entrant for unique lCh values. It is non-
 *          re-entrant for same lCh value.
 */
EDMA3_DRV_Result EDMA3_DRV_setPaRAMField (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_DRV_PaRAMField paRAMField,
                    unsigned int newPaRAMFieldVal);


/**
 * \brief   Get a particular PaRAM set field of the specified PaRAM set
 *
 *
 * \param   hEdma               [IN]    Handle to the EDMA Driver Instance
 * \param   lCh                 [IN]    Logical Channel bound to the PaRAM set
 *                                      whose specified field value is needed
 * \param   paRAMField          [IN]    Specify the PaRAM set field which needs
 *                                      to be obtained
 * \param   currPaRAMFieldVal   [IN]    The value of the field
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_getPaRAMField (EDMA3_DRV_Handle hEdma,
                    unsigned int lCh,
                    EDMA3_DRV_PaRAMField paRAMField,
                    unsigned int *currPaRAMFieldVal);


/**
 * \brief   Sets EDMA TC priority
 *          User can program the priority of the Event Queues
 *          at a system-wide level.  This means that the user can set the
 *          priority of an IO initiated by either of the TCs (Transfer Ctrllers)
 *          relative to IO initiated by the other bus masters on the
 *          device (ARM, DSP, USB, etc)
 *
 * \param   hEdma           [IN]    Handle to the EDMA Driver Instance
 * \param   evtQPriObj     [IN]    Priority of the Event Queues
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function disables the global interrupts while modifying
 *          the global CC Registers, to make it re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_setEvtQPriority (EDMA3_DRV_Handle hEdma,
                    const EDMA3_DRV_EvtQuePriority *evtQPriObj);


/**
 * \brief   Associate Channel to Event Queue
 *
 *
 * \param   hEdma       [IN]     Handle to the EDMA Driver Instance
 * \param   channelId   [IN]     Logical Channel to which the Event
 *                               Queue is to be mapped
 * \param   eventQ      [IN]     The Event Queue which is to be mapped
 *                               to the DMA channel
 *
 * \return      EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note        There should not be any data transfer going on
 *              while setting the mapping. Results could be unpredictable.
 *
 *              This function disables the global interrupts while modifying
 *              the global CC Registers, to make it re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_mapChToEvtQ (EDMA3_DRV_Handle hEdma,
                    unsigned int channelId,
                    EDMA3_RM_EventQueue eventQ);


/**
 * \brief   Get the Event Queue mapped to the specified DMA channel
 *
 *
 * \param   hEdma       [IN]     Handle to the EDMA Driver Instance
 * \param   channelId   [IN]     Logical Channel whose associated
 *                               Event Queue is needed
 * \param   mappedEvtQ  [IN/OUT] The Event Queue which is mapped
 *                               to the DMA channel
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_getMapChToEvtQ ( EDMA3_DRV_Handle hEdma,
                    unsigned int channelId,
                    unsigned int *mappedEvtQ);


/**
 * \brief   Get the Channel Controller (CC) Register value
 *
 * \param   hEdma       [IN]     Handle to the EDMA Driver Instance
 * \param   regOffset   [IN]     CC Register offset whose value is needed
 * \param   regValue    [IN/OUT] CC Register Value
 *
 * \return  EDMA3_DRV_OK or EDMA3_DRV Error Code
 *
 * \note    This function is re-entrant.
 */
EDMA3_DRV_Result EDMA3_DRV_getCCRegister ( EDMA3_DRV_Handle hEdma,
                    unsigned int regOffset,
                    unsigned int *regValue);



/* @} Edma3DrvTransferSetupOpt */


/* @} Edma3DrvMain */

#endif         /* _EDMA3_DRV_H_ */
