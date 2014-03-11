#include <std.h>
#include <gio.h>
#include <log.h>

#include "psp_vpfe.h"
#include "psp_vpbe.h"
#include "fvid.h"
#include "psp_tvp5146_extVidDecoder.h"

#include <soc.h>
#include <cslr_ccdc.h>

#define ALLOC_STATIC
//#define ALLOC_DYNAMIC
#define LARGEUR 500
#define HAUTEUR 400
#define NB_ELT_TRAIT LARGEUR*HAUTEUR


//pour logger ce qui se passe avec log.h (voir DSPBIOS)
extern LOG_Obj trace;  // BIOS LOG object
//--------- pour transferts EDMA3
//#include <cslr_edma3cc.h>
//#include <cslr_edma3tc.h>

// driver header : pour avoir toutes les fonctions EDMA3 et les 
//structures de données,pensez à ajouter le repertoire 
//dans build option, preprocesseur.
#include <bios_edma3_sample.h> 
extern EDMA3_DRV_Handle hEdma; // global driver handle 

// nous permet de savoir si des evenements n'ont pas été captés:
volatile int evtMiss;
volatile int trFinished;

//#include <bios_edma3_sample.h>
// call back struct
typedef struct MyCbData {
  EDMA3_DRV_Handle hEdma; // driver handle
  unsigned int chId; // channel id
  unsigned int numTrs; // number of interrupts to be received
  unsigned int numTrCnt;  // count of interrupts received so far
} MyCbData;

MyCbData myCbData[4];

int transfert_DMA( EDMA3_DRV_Handle hEdma, 
                              unsigned char *src, unsigned char *dst ) ;
//--------fin EDMA3 ----

/* extrait de l'exemple EDMA3 :
// 48K L1 SRAM [0x10f04000, 0x10f10000), 0xc000 length
// 32K L1 Dcache [0x10f10000, 0x10f18000), 0x8000 length
// 128K L2 SRAM [0x10800000, 0x10820000), 0x20000 length
// 128M DDR2 [0x80000000, 0x88000000), 0x8000000 length are cacheable
*/

#ifdef ALLOC_STATIC
#define EDMA3_CACHE_LINE_SIZE_IN_BYTES      (128u)
//Buffer : imagein
// buffer in L1 SRAM, 32K
//#pragma DATA_SECTION( imagein, ".L1Buffer" )
// buffer in L2 SRAM, 64K 
//#pragma DATA_SECTION( imagein, ".L2Buffer" )
// buffer in DDR2, 32M
#pragma DATA_SECTION( imagein, ".ExtBuffer" )
//#pragma DATA_ALIGN( imagein, EDMA3_CACHE_LINE_SIZE_IN_BYTES );
Uint8 imagein[NB_ELT_TRAIT];

//Buffer : imageout
//buffer in L1 SRAM, 32K
//#pragma DATA_SECTION( imageout, ".L1Buffer" )
// buffer in L2 SRAM, 64K 
//#pragma DATA_SECTION( imageout, ".L2Buffer" )
// buffer in DDR2, 32M
#pragma DATA_SECTION( imageout, ".ExtBuffer" )
//#pragma DATA_ALIGN( imageout, EDMA3_CACHE_LINE_SIZE_IN_BYTES );
Uint8 imageout[NB_ELT_TRAIT];
#endif


/* CODE D'ORIGINE POUR LE LOOPBACK*/
#define NO_OF_BUFFERS       (2u)

// Global Variable Defined 
static PSP_VPSSSurfaceParams *ccdcAllocFB[NO_OF_BUFFERS]={NULL};
static PSP_VPSSSurfaceParams *vidAllocFB[NO_OF_BUFFERS] ={NULL};

static FVID_Handle   ccdcHandle;
static FVID_Handle   vid0Handle;
static FVID_Handle   vencHandle;

static PSP_VPFE_TVP5146_ConfigParams tvp5146Params = {
  TRUE, // enable656Sync 
  PSP_VPFE_TVP5146_FORMAT_COMPOSITE, // format        
  PSP_VPFE_TVP5146_MODE_AUTO         // mode          
};

static PSP_VPFECcdcConfigParams ccdcParams = {
  PSP_VPFE_CCDC_YCBCR_8,  // dataFlow     
  PSP_VPSS_FRAME_MODE,    // ffMode       
  480,                    // height       
  720,                    // width        
  (720 *2),               // pitch        
  0,                      // horzStartPix 
  0,                      // vertStartPix 
  NULL,                   // appCallback  
  {
    PSP_VPFE_TVP5146_Open, // extVD Fxn    
    PSP_VPFE_TVP5146_Close,
    PSP_VPFE_TVP5146_Control,
  },
  0                       //segId         
};

static PSP_VPBEOsdConfigParams  vid0Params = {
  PSP_VPSS_FRAME_MODE,                // ffmode       
  PSP_VPSS_BITS16,                    // bitsPerPixel 
  //PSP_VPBE_RGB_888,  //ajout TG
 PSP_VPBE_YCbCr422,                  // colorFormat  
  (720 *  (16/8u)),                   // pitch        
  0,                                  // leftMargin   
  0,                                  // topMargin    
  720,                                // width        
  480,                                // height       
  0,                                  // segId        
  PSP_VPBE_ZOOM_IDENTITY,             // hScaling     
  PSP_VPBE_ZOOM_IDENTITY,             // vScaling     
  PSP_VPBE_EXP_IDENTITY,              // hExpansion   
  PSP_VPBE_EXP_IDENTITY,              // vExpansion   
  NULL                                // appCallback  
};

static PSP_VPBEVencConfigParams vencParams = {
  PSP_VPBE_DISPLAY_NTSC_INTERLACED_COMPOSITE // Display Standard 
};


void start_vpss_test() {
  PSP_VPBEChannelParams beinitParams;
  PSP_VPFEChannelParams feinitParams;
  GIO_Attrs gioAttrs = GIO_ATTRS;
  PSP_VPSSSurfaceParams *FBAddr = NULL;
  Uint32 i = 0;
  Uint32 numOfIterations = 10000;
  unsigned int ts, te;
  PSP_VPSSSurfaceParams *FBAddrImage2 = NULL,*FBAddrImage1=NULL;
  Uint16 *l_ptr_short   = NULL;
  Uint16 *ptrs,*ptrd;
  Uint16  grayvalue     = 0;
  Uint32 j=0,k=0,l;
  #ifdef ALLOC_DYNAMIC
  Uint8 *imagein,*imageout; //[720*480];//,imageout[720*480];
  imagein = (Uint8 *) malloc (720*480);
  imageout = (Uint8 *) malloc (720*480);
  #endif
  //Init CSL du DMA
  edma3init();


  // Create ccdc channel
  feinitParams.id = PSP_VPFE_CCDC;
  feinitParams.params = (PSP_VPFECcdcConfigParams*)&ccdcParams;
  ccdcHandle = FVID_create( "/VPFE0", IOM_INOUT, NULL, &feinitParams, 
                            &gioAttrs);
  if ( NULL == ccdcHandle) {
    return;
  }

  // Configure the TVP5146 video decoder
  if( FVID_control( ccdcHandle, 
                    VPFE_ExtVD_BASE + PSP_VPSS_EXT_VIDEO_DECODER_CONFIG,
                    &tvp5146Params) != IOM_COMPLETED ) {
	return;
  } else {
    for ( i=0; i < NO_OF_BUFFERS; i++ ) {
      if ( IOM_COMPLETED == FVID_alloc( ccdcHandle, &ccdcAllocFB[i] ) ) {
        if ( IOM_COMPLETED != FVID_queue(ccdcHandle, ccdcAllocFB[i] ) ) {
          return;
        }
      }
    }
  }

  // Create video channel
  beinitParams.id = PSP_VPBE_VIDEO_0;
  beinitParams.params = (PSP_VPBEOsdConfigParams*)&vid0Params;
  vid0Handle = FVID_create( "/VPBE0", IOM_INOUT,NULL, &beinitParams, 
                            &gioAttrs );
  if ( NULL == vid0Handle ) {
    return;
  } else {
    for ( i=0; i<NO_OF_BUFFERS; i++ )  {
      if ( IOM_COMPLETED == FVID_alloc( vid0Handle, &vidAllocFB[i] ) ) {
        if ( IOM_COMPLETED != FVID_queue( vid0Handle, vidAllocFB[i]) ) {
          return;
        }
      }
    }
  }

  // Create venc channel
  beinitParams.id = PSP_VPBE_VENC;
  beinitParams.params = (PSP_VPBEVencConfigParams *)&vencParams;
  vencHandle = FVID_create( "/VPBE0", IOM_INOUT, NULL, &beinitParams, 
                            &gioAttrs);
  if ( NULL == vencHandle ) {
    return;
  }

  FVID_alloc( ccdcHandle, &FBAddr );
  FVID_alloc( ccdcHandle, &FBAddrImage1 );
  FVID_alloc( ccdcHandle, &FBAddrImage2 );

  //BOUCLE ACQUISITION & COPIE & AFFICHAGE DES IMAGES
  // 1)Acquisition
  for( i = 0; i < numOfIterations; i++ ) {
    if ( IOM_COMPLETED != FVID_exchange( ccdcHandle, &FBAddr ) ) {
	 return;
    }
        BCACHE_inv(FBAddr->frameBufferPtr,(720*480*2),TRUE);
         
	//recopie d'une portion LARGEUR*HAUTEUR de l'image dans imagein
	ptrs=(Uint16 *)FBAddr->frameBufferPtr;
	l=0;
	for (k=0; k<HAUTEUR;k++) {
		for (j=0;j<LARGEUR;j++) {
			*(imagein+j+k*LARGEUR) =  *(ptrs+l)>>8;
			l++;
			}
		l=k*720;
      }
	 
	//côpie DMA de imagein --> imageout avant traitement
	
	if ( transfert_DMA( hEdma, imagein, imageout) != EDMA3_DRV_SOK ) {
	    	LOG_printf( &trace, "transfert_dma() failed!\n");
		  } else {
		    LOG_printf( &trace, "transfert_dma() passed!\n");
		  }		

	//copie de imageout -> FBAddrImage1
	ptrd=(Uint16 *)FBAddrImage1->frameBufferPtr;// *(FBAddr->frameBufferPtr);
	l=0;
	for	(k=0; k<HAUTEUR;k++) {
		for (j=0;j<LARGEUR;j++) {
			*(ptrd+l)=*(imageout+j+k*LARGEUR)<<8 | 0x0080; 
			l++;
		}
		l=k*720;
    }
	BCACHE_wb(FBAddr->frameBufferPtr,(720*480*2),TRUE); 
        
	// 3)Affichage :
    if ( IOM_COMPLETED != FVID_exchange( vid0Handle, &FBAddrImage1 ) ) {
      return;
    }
  }

  FVID_free(vid0Handle,  FBAddr);
  FVID_free(vid0Handle,  FBAddrImage1);
  FVID_free(vid0Handle,  FBAddrImage2);

  // Free Memory Buffers
  for( i=0; i< NO_OF_BUFFERS; i++ ) {
    FVID_free( ccdcHandle, ccdcAllocFB[i] );
    FVID_free( vid0Handle, vidAllocFB[i] );
  }

  // Delete Channels
  FVID_delete( ccdcHandle );
  FVID_delete( vid0Handle );
  FVID_delete( vencHandle );

  return;
}
//pour utiliser le CSL DMA:
/*
1) inclure le repertoire driver de spraan4.zip
2) ajouter #include <bios_edma3_sample.h>
3) maj du chemin du linker et ajout des libs

4) ajouter les 3 fichiers driver/.c  au projet (specifiques à cette carte)
5) AJOUTER le symbol DM643X_SOC_BUILD (lu par les .c)

6) ajouter la fonction callback au projet
7) edma3init();

Pour chronometrer :
7) ajouter la lib timer.lib au projet
Pour utiliser le log d'evt grace à la var trace de DSPBIOS:
extern LOG_Obj trace;  // BIOS LOG object
et s'utilise avec
LOG_printf( &trace, "    cache operation cycles = %u", te - ts );
*/

//Fonction utilisée pour la config. DMA
void callback ( unsigned int tcc, EDMA3_RM_TccStatus status, void *appData ) {
  MyCbData *cbData = (MyCbData*)appData;
  (void)tcc;

  switch ( status ) {
  case EDMA3_RM_XFER_COMPLETE:
    cbData->numTrCnt++;
	if ( cbData->numTrCnt < cbData->numTrs ) {
      EDMA3_DRV_enableTransfer ( cbData->hEdma, cbData->chId, 
	                             EDMA3_DRV_TRIG_MODE_MANUAL );	  
	} else {
      trFinished++;
	}
    break;
  case EDMA3_RM_E_CC_DMA_EVT_MISS:
    evtMiss++;
    break;
  case EDMA3_RM_E_CC_QDMA_EVT_MISS:
    break;
  default:
    break;
  }
}


int transfert_DMA( EDMA3_DRV_Handle hEdma, 
                              unsigned char *src, unsigned char *dst ) {
  unsigned int chId = 0;
  unsigned int tcc = 0;
  int i;
  unsigned int count;
  int fail = 0;
  unsigned int ts, te; //pour mesure de temps

  count = LARGEUR*HAUTEUR; //720*480;
  LOG_printf( &trace, "transfert DMA : start" );
  evtMiss = 0; // clear event miss count

/*
  ts = C64P_getltime();
  // write back src
  BCACHE_wb ( (void *)src, count, 1 ); // wait for it to finish
  // invalidate dst
  BCACHE_inv( (void *)dst, count, 1 ); // wait for it to finish
  te = C64P_getltime();
  LOG_printf( &trace, "    cache operation cycles = %u", te - ts );
*/
  // request channel
  tcc = EDMA3_DRV_TCC_ANY;
  chId = EDMA3_DRV_DMA_CHANNEL_ANY;
  if( EDMA3_DRV_requestChannel ( hEdma, &chId, &tcc, (EDMA3_RM_EventQueue)0,
                                 callback, &myCbData[0] ) != EDMA3_DRV_SOK ) {
	fail = -1;
	LOG_printf( &trace, "transfert DMA : fail request chanel" );;
  }

  // Fill the PaRAM Set for transferring Y 
  // Ideally we only need to do a 2-D transfer: acnt = 1 and bcnt = 720*480.
  // however, since bcnt and bindex has to be 16 bits, the transfer is
  // splited to 3-D transfer: acnt = 1, bcnt = 720, ccnt = 480
  
  myCbData[0].chId = chId;
  myCbData[0].hEdma = hEdma;
  myCbData[0].numTrs = HAUTEUR; //480;
  myCbData[0].numTrCnt = 0;

  if ( EDMA3_DRV_setSrcParams ( hEdma, chId, (unsigned int)(src),
                                EDMA3_DRV_ADDR_MODE_INCR,
                                EDMA3_DRV_W8BIT ) != EDMA3_DRV_SOK ) {
	fail=-1;LOG_printf( &trace, "transfert DMA : fail setSrcParams" );}
  if ( EDMA3_DRV_setDestParams ( hEdma, chId, (unsigned int)(dst),
                                 EDMA3_DRV_ADDR_MODE_INCR,
                                 EDMA3_DRV_W8BIT ) != EDMA3_DRV_SOK ) {
	fail=-1;LOG_printf( &trace, "transfert DMA : fail setDestParams" );}
  if ( EDMA3_DRV_setSrcIndex ( hEdma, chId, 1, LARGEUR /*720*/ ) != EDMA3_DRV_SOK ) {
	fail=-1;LOG_printf( &trace, "transfert DMA : fail setSrcIndex" );}
  if ( EDMA3_DRV_setDestIndex ( hEdma, chId, 1, LARGEUR /*720*/ ) != EDMA3_DRV_SOK ) {
	fail=-1;LOG_printf( &trace, "transfert DMA : fail setDestIndex" );}
  if ( EDMA3_DRV_setTransferParams ( hEdma, chId, 1,  LARGEUR /*720*/, HAUTEUR /*480*/,  LARGEUR /*720*/, 
                                     EDMA3_DRV_SYNC_AB ) != EDMA3_DRV_SOK ) {
	fail=-1;LOG_printf( &trace, "transfert DMA : fail setTransferParams" );}
  if ( EDMA3_DRV_setOptField ( hEdma, chId, EDMA3_DRV_OPT_FIELD_TCINTEN, 1u )
                               != EDMA3_DRV_SOK ) {
	fail=-1;LOG_printf( &trace, "transfert DMA : fail setOptField TCINT" );}
  if ( EDMA3_DRV_setOptField ( hEdma, chId, EDMA3_DRV_OPT_FIELD_ITCINTEN, 1u )
                               != EDMA3_DRV_SOK ) {
	fail=-1;LOG_printf( &trace, "transfert DMA : fail setOptField ITC INT" );}

  trFinished = 0;
  ts = C64P_getltime();
  if ( EDMA3_DRV_enableTransfer ( hEdma, chId, EDMA3_DRV_TRIG_MODE_MANUAL )
       != EDMA3_DRV_SOK ) {
	fail = -2;
	LOG_printf( &trace, "transfert DMA : fail enable Transfer" );;
  }
  while ( trFinished == 0 ); // wait for transferring Y to finish
  te = C64P_getltime();
  LOG_printf( &trace, "    Tran(Y) cycles = %u", te - ts );

  if ( evtMiss ) { // is there any event miss?
    fail = -2;
    LOG_printf( &trace, "transfert DMA : fail : event missed" );;
  }

  if ( chId != EDMA3_DRV_DMA_CHANNEL_ANY ) {
    EDMA3_DRV_freeChannel ( hEdma, chId );
  }
  return fail;
}

