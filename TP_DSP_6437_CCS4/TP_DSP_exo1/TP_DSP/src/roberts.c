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

void roberts_nonopt(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur) {
	Uint32 i,j; 
	double Gx, Gy;
	Uint32 totalG;
	for (j=0; j<hauteur; j++) { 
		for (i=0; i<largeur; i++) { 
			Gx = pow(in[j*largeur+i] - in[(j+1)*largeur+i+1],2);
			Gy = pow(in[(j+1)*largeur+i] - in[j*largeur+i+1],2);
			totalG = valeur_absolue(Gx + Gy);
			if(totalG > 255) totalG = 255;
			out[j*largeur+i] = (Uint8)totalG;
		} 
	} 
}

void roberts_optimise(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 threshold, double* Gx, double* Gy) { 
	const Uint32 NB_ELMT = largeur*hauteur; 
	Uint32 i,G; 
	Uint8 *pi, *ps; 
		 
	pi = in; ps = pi + largeur; 
	 
	for (i=0; i<NB_ELMT; i++) { 
		Gx[i] = pi[0] - ps[1]; 
		Gy[i] = pi[1] - ps[0]; 
		G = (Uint32)(valeur_absolue(Gx[i]*Gx[i]) + valeur_absolue(Gy[i]*Gy[i])); 
		out[i] = (G > threshold) ? 255 : 0; 
		++pi;++ps; 
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
