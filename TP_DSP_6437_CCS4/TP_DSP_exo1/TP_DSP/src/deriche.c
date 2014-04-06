/* =========================================================================

	DERICHE.C	Implemente l'algorithme de Deriche dans le cadre d'une
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

void deriche_nonopt(Uint8* in, Uint8* out, Uint32 largeur, Uint32 hauteur, float gamma){
	int i,j;
	double g1 = (1 - gamma)*(1 - gamma);
	double g2 = 2 * gamma;
	double gg = gamma * gamma;
	
	double* X;
	double* Y;
	
	X = (double*) malloc(largeur*hauteur*sizeof(double));
	Y = (double*) malloc(largeur*hauteur*sizeof(double));
	
	// Smoothing horizontal
	for(i = 0; i < largeur; i++){
		
		//Filtre causal
		X[i] = g1*((double)in[i]);
		X[largeur + i] = g1*((double)in[largeur+i]+(g2*X[i]));
		for(j = 2; j < hauteur; j++){
			X[j*largeur+i]=(g1*((double)in[j*largeur+i])+(g2*X[(j-1)*largeur + i]) + (gg*X[(j-2)*largeur+i]));
		}
		
		//Filtre Anti-causal
		Y[((hauteur-1)*largeur+i)] = g1*X[(hauteur-1)*largeur+i];
		Y[(hauteur-2)*largeur+i] = g1*X[(hauteur-2)*largeur+i] + g2*Y[(hauteur-1)*largeur+i];
		for(j=hauteur-3; j >=0; j--){
				Y[j*largeur+i] = g1*X[j*largeur+i] + g2*Y[(j+1)*largeur+i] + gg*Y[(j+2)*largeur+i];
		}
	}
	for(j = 0; j< largeur*hauteur; j++){
		out[j] = (Uint8)Y[j];
	}
	
	// Transvasement de la matrice Y dans la matrice X
	for(i = 0; i<largeur; i++){
		for(j = 0; j< hauteur; j++){
			X[j*largeur+i] = Y[i*hauteur+j];
		}
	}
	
	// Smoothing vertical
	for(j = 0; j<hauteur; j++){
	
		//Filtre causal
		Y[j] = g1*X[j];
		Y[hauteur+j] = g1*X[hauteur+j] + (g2 * Y[j]);
		for(i = 2; i<largeur; i++){
			Y[i*hauteur+j] = (g1*X[i*hauteur+j]) + (g2*Y[(i-1)*hauteur+j]) + (gg*Y[(i-2)*hauteur+j]);
		}
	
		//Filtre Anti-causal
		out[(largeur-1)*hauteur+j] = g1*Y[(largeur-1)*hauteur+j];
		out[(largeur-2)*hauteur+j] = g1*Y[(largeur-2)*hauteur+j] + g2*out[(largeur-1)*hauteur+j];
		for(i = largeur-3; i<=0; i--){
			out[i*largeur+j] = g1*Y[i*largeur+j] + g2*out[(i+1)*hauteur+j] + gg*out[(i+2)*hauteur+j];
		}
	}
	free(X);
	free(Y);
}

void deriche_optimise(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, float gamma) { 
 
	int i,j,k; 
	float g1 = (1-gamma)*(1-gamma); 
	float g2 = 2*gamma; 
	float gg = gamma*gamma; 
	 
	double *X = (double*) malloc(largeur*hauteur*sizeof(double)); 
	double *Y = (double*) malloc(largeur*hauteur*sizeof(double)); 
	 
	k=0; 
	// Horizontal smoothing 
	for (j=0; j<hauteur; j++) { // for every line : 
		// Filtre causal 
		X[k] = g1*((double)in[k]);k++; 
		X[k] = g1*((double)in[k])+ g2*X[k-1];k++; 
		for (i=2; i<largeur; i++) { 
			X[k]= g1*((double)in[k]) + g2*X[k-1] + gg*X[k-2];k++; 
		} 
	
		// Filtre anticausal 
		k--; 
		Y[k] = g1*X[k];k--; 
		Y[k] = g1*X[k] + g2*Y[k+1];k--; 
		for (i=largeur-3; i>=0; i--) { 
			Y[k] = g1*X[k] + g2*Y[k+1] + gg*Y[k+2];k--; 
		} 
		k+=largeur+1; 
	} 
	// Transposing matrix Y into matrix X 
	 for(i = 0; i<largeur; i++){
		for(j = 0; j< hauteur; j++){
			X[j*largeur+i] = Y[i*hauteur+j];
		}
	}
	 
	 k=0; 
	// Vertical smoothing 
	for (i=0; i<largeur; i++) { // for every line : 
		// Filtre causal 
		Y[k] = g1*X[k];k++; 
		Y[k] = g1*X[k] + g2*Y[k-1];k++; 
		for (j=2; j<hauteur; j++) { 
			out[k]= g1*Y[k] + g2*X[k-1] + gg*X[k-2];k++; 
		} 
	
	  	// Filtre anticausal 
		k--; 
		out[k] = g1*Y[k];k--; 
		out[k] = g1*Y[k] + g2*out[k+1];k--; 
		for (j=hauteur-3; j>=0; j--) { 
			out[k] = g1*Y[k] + g2*out[k+1] + gg*out[k+2];k--; 
		} 
		k+=hauteur+1; 
	} 
	 
	free(X); 
	free(Y); 
 
} 
	
	

