#include "../TP_DSP/src/projet_dsp.h"

#define WIDTH 720
#define HEIGHT 480
#define GAMMA 0.25
#define SEUIL 160

#define NO_OF_BUFFERS       (2u)

// External functions 

extern LOG_Obj trace;  // BIOS LOG object
extern Uint32 C64P_getltime();
extern void deriche_nonopt(Uint8* in, Uint8* out, Uint32 largeur, Uint32 hauteur, float gamma);
extern void roberts_nonopt(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur);
extern void binarisation(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 threshold);

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
  WIDTH,                                // width        
  HEIGHT,                                // height       
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

void start_boucle() {
  PSP_VPBEChannelParams beinitParams;
  PSP_VPFEChannelParams feinitParams;
  GIO_Attrs gioAttrs = GIO_ATTRS;
  PSP_VPSSSurfaceParams *FBAddr = NULL;
  PSP_VPSSSurfaceParams *FBAddrOut = NULL;
  
  Uint32 i = 0, j = 0, k = 0, ts = 0, te = 0;
  Uint32 largeur = WIDTH;
  Uint32 hauteur = HEIGHT;
  Uint32 numOfIterations = 10000;

  Uint8* imageIn = NULL;
  Uint8* imageOut = NULL;
  Uint8* imageSaved = NULL;

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

  //Allocation memoire et la structure qui contiendra l'image
  FVID_alloc( ccdcHandle, &FBAddr );
  FVID_alloc( ccdcHandle, &FBAddrOut);
  //Allocation mémoire des conteneurs pour le traitement des images
  imageIn = (Uint8*) malloc(WIDTH*HEIGHT*sizeof(Uint8));
  imageOut = (Uint8*) malloc(WIDTH*HEIGHT*sizeof(Uint8));
  imageSaved = (Uint8*) malloc(WIDTH*HEIGHT*sizeof(Uint8));
  //================BOUCLE ACQUISITION & COPIE & AFFICHAGE DES IMAGES========================
  //1)Acquisition
  	for( i = 0; i < numOfIterations; i++ ) {
  		if ( IOM_COMPLETED != FVID_exchange( ccdcHandle, &FBAddr ) ) {
			return;
    	}
    	
    	//Conversion en Uint8, l'octet de poids fort étant la composante de luminance (Y)
    	for( j = 0; j < HEIGHT; j++ ) { 
    		for( k = 0; k < WIDTH ; k++ ) { 
    			imageIn[j*WIDTH + k] = (Uint8) ((((Uint16*)FBAddr->frameBufferPtr)[j*WIDTH + k]) >> 8); 
    		} 
    	}
    	
    	//Sauvegarde de l'image en niveau de gris
    	memcpy(imageSaved, imageIn, WIDTH*HEIGHT);
    	
  		ts = C64P_getltime(); 
  		deriche_nonopt(imageIn, imageOut, largeur, hauteur, GAMMA);
  		te = C64P_getltime();
  		ts = C64P_getltime(); 
  		roberts_nonopt(imageOut, imageIn, largeur, hauteur);
  		te = C64P_getltime();
  		ts = C64P_getltime(); 
  		binarisation(imageIn, imageOut, largeur, hauteur, SEUIL);
  		te = C64P_getltime();
  		
  		LOG_printf( &trace, " Nombre de cycles : Fonction deriche_nonopt = %u", te - ts );
  		
  	    LOG_printf( &trace, "Affichage iteration = %u", i );
  	    
  	    //Conversion en Uint16 pour affichage et mise à 0x80 (mise à zéro) de la chrominance 
  	    for( j = 0; j < HEIGHT; j++ ) { 
  	    	for( k = 0; k < WIDTH ; k++ ) { 
  	    		((Uint16*)FBAddrOut->frameBufferPtr)[j*WIDTH + k] = ((((Uint16)imageIn[j*WIDTH + k])<<8) | 0x0080); 
  	    	}
  	    }
  // 2)Affichage :
  		if ( IOM_COMPLETED != FVID_exchange( vid0Handle, &FBAddrOut ) ) {
    		return;
    	}
  } //fin Acquisition
  //================FIN BOUCLE ACQUISITION & COPIE & AFFICHAGE DES IMAGES======================
  FVID_free(vid0Handle,  FBAddr);
 
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
