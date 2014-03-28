#ifndef PROJET_DSP_H_
#define PROJET_DSP_H_

#include <std.h>
#include <gio.h>
#include <log.h>
#include <stdlib.h>
#include "psp_vpfe.h"
#include "psp_vpbe.h"
#include "fvid.h"
#include "psp_tvp5146_extVidDecoder.h"

#include <soc.h>
#include <cslr_ccdc.h>

//Implémentées

//FONCTIONNE
void deriche_nonopt(Uint8* in, Uint8* out, Uint32 largeur, Uint32 hauteur, float gamma);

/*Non implémentées
void deriche_optimise(Uint16* in, Uint16* out, Uint32 largeur, Uint32 hauteur, float gamma);
void 
*/
#endif /*PROJET_DSP_H_*/
