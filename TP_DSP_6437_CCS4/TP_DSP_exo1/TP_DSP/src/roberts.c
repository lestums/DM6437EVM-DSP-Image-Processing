/* =========================================================================

	ROBERTS.C	Implemente le gradient de roberts dans le cadre d'une
				utilisation sur DSP C6xxx.
				Contiens les versions optimisées et non optimisées des
				algorithmes implémentés
	
	AUTEURS :
				JOUVENCE	Pierre-Marie
				LE STUM 	Sébastien
	
	Ce fichier à été élaboré dans le cadre du projet de E4 - INF4303C

	========================================================================
*/
#include "projet_dsp.h"

Uint32 valeur_absolue(double d) { 
	Uint32 abs = (Uint32) d, mask = abs >> 31;  
	return abs = (abs ^ mask) - mask; 
}

void roberts_nonopt(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur) {
	Uint32 i,j; 
	double Gx, Gy;
	Uint32 totalG;
	for (j=0; j<hauteur; j++) { 
		for (i=0; i<largeur; i++) { 
			Gx  = pow(-in[j*largeur+i] + in[j*largeur+i+1] - in[(j+1)*largeur+i] + in[(j+1)*largeur+i+1],2);
			Gy = pow(-in[j*largeur+i] + in[(j+1)*largeur+i] - in[j*largeur+i+1] + in[(j+1)*largeur+(i+1)],2);
			if(Gx < 0) Gx = -Gx;
			if(Gy < 0) Gy = -Gy;
			totalG = (Uint32)(valeur_absolue(Gx) + valeur_absolue(Gy));
			if(totalG > 255) totalG = 255;
			out[j*largeur+i] = (Uint8)totalG;
		} 
	} 
}

void binarisation(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 threshold) {
	Uint32 j;
	for( j = 0; j < hauteur*largeur; j++ ) { 
		if (in[j] > threshold) { 
			out[j] = 255; 
		} else { 
			out[j] = 0; 
		} 
	} 
}