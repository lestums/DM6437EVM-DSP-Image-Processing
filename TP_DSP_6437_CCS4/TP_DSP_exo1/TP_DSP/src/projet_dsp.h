#ifndef PROJET_DSP_H_
#define PROJET_DSP_H_

#include <std.h>
#include <gio.h>
#include <log.h>
#include <stdlib.h>
#include <math.h>
#include "psp_vpfe.h"
#include "psp_vpbe.h"
#include "fvid.h"
#include "psp_tvp5146_extVidDecoder.h"

#include "../TP_DSP/src/vars.h"

#include <soc.h>
#include <cslr_ccdc.h>

//Implémentées

//FONCTIONNE
void deriche_nonopt(Uint8* in, Uint8* out, Uint32 largeur, Uint32 hauteur, float gamma);
void deriche_optimise(Uint8* in, Uint8* out, Uint32 largeur, Uint32 hauteur, float gamma);

void roberts_nonopt(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur);
void roberts_optimise(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 threshold, double* Gx, double* Gy);

void hough_nonopt(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 votes);
void hough_optimise(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Int32 vote, double *Gx, double *Gy, double *tSin, double *tCos);

void binarisation(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 threshold);

// FONCTIONS ANNEXES

double fastAtan2(double y, double x);
Uint32 fastSqrtD(const double x);
double invSqrtD(const double x);
Uint32 valeur_absolue(double d);

#endif /*PROJET_DSP_H_*/
