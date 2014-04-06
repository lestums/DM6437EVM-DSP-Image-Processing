/* =========================================================================

	ROBERTS.C	Implemente le gradient de roberts dans le cadre d'une
				utilisation sur DSP C6xxx.
				Contiens les versions optimis�es et non optimis�es des
				algorithmes impl�ment�s
	
	AUTEURS :
				JOUVENCE	Pierre-Marie
				LE STUM 	S�bastien
	
	Ce fichier � �t� �labor� dans le cadre du projet de E4 - INF4303C

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
			totalG = (Uint32)(valeur_absolue(Gx) + valeur_absolue(Gy));
			if(totalG > 255) totalG = 255;
			out[j*largeur+i] = (Uint8)totalG;
		} 
	} 
}

void roberts_optimise(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur) { 
	const Uint32 NB_ELMT = largeur*hauteur; 
	Uint32 i,G,Gx,Gy; 
	Uint8 *pi, *ps; 
		 
	pi = in; ps = pi + largeur; 
	 
	for (i=0; i<NB_ELMT; i++) { 
		Gx = - pi[0] + pi[1] - ps[0] + ps[1]; 
		Gy = - pi[0] - pi[1] + ps[0] + ps[1]; 
		G = (Uint32)(valeur_absolue(Gx*Gx) + valeur_absolue(Gy*Gy)); 
		if(G > 255) G = 255;
		out[i] = (Uint8)G;
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
