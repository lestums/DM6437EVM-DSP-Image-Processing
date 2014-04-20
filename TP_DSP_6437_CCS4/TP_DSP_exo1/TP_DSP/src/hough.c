/* =========================================================================

	HOUGH.C		Implemente la transformée de Hough dans le cadre d'une
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

void hough_nonopt(Uint8 *in, Uint8 *out, int maxrho, Uint32 largeur, Uint32 hauteur, Uint32 votes) { 
	//We assume here that the dimensions of in and the ones of the RGB image are the same 
	int i,j,x,y,rho=0,angle=0,AccMax=0,rho_idx=0;

	// Accumulator initialization 
	Uint32 *Acc = (Uint32*)malloc(MAXTHETA*maxrho*sizeof(Uint32)); 
	for(j=0; j<maxrho*MAXTHETA;j++){ 
		Acc[j]=0; 
	} 
	// Compute Hough transform for every in(x,y)>0 
	for (j=1; j<hauteur-2; j++) { 
		for (i=1; i<largeur-2; i++) { 
			if (in[j*largeur+i] == 255) { 
				for (angle=0; angle<= MAXTHETA; angle++) { 
					rho_idx = (int)((((double)j*sin(angle) + (double)i*cos(angle) + (double)maxrho)/2) + 0.9); 
					if (rho_idx<maxrho && rho_idx>0) { 
						Acc[rho_idx*MAXTHETA+angle]++; 
						if (Acc[rho_idx*MAXTHETA+angle] > AccMax) { 
							AccMax = Acc[rho_idx*MAXTHETA+angle]; 
						} 
					} 
				} 
			} 
		}
	}
	AccMax -= votes;
	// Draw Hough lines 
	for (rho_idx=0; rho_idx< maxrho; rho_idx++) { 
		// Quand Theta = 0 
 		if (Acc[rho_idx*180] > AccMax){ 
 			rho = rho_idx*2 - maxrho; 
			for(x = 0;x < WIDTH;x++){ 
 				out[x]=255; 
 			} 
 		} 
		// Sinon
 		for (angle = 1; angle < 180; angle++){ 
 			if (Acc[rho_idx*180+angle] > AccMax){ 
				rho = rho_idx*2 - maxrho; 
 				for(x = 0;x < WIDTH;x++){ 
 					y = (int)((((double)rho - (double)x*cos(angle))/sin(angle))+0.9);  
 					if(y < HEIGHT && y > 0){ 
 						out[y*HEIGHT+x] = 255; 
 					} 
 				} 
			} 
 		} 
	} 
	free(Acc); 
}

void hough_optimise(Uint8 *in, Uint8 *out, int maxrho, Uint32 largeur, Uint32 hauteur, Int32 vote, double *Gx, double *Gy, double *tSin, double *tCos) { 
	
	//We assume here that the dimensions of in and the ones of the RGB image are the same 
	int rho=0,angle=0,rho_idx=0;
	Uint32 i,j,x,y,ctr=largeur; 
	const Uint32 NB_ELMT = maxrho*MAXTHETA; 
	const Uint32 TAILLE = hauteur*largeur; 
	//Int32 AccMax=0;
	double angler=0; 
	
	// Accumulator initialization 
	Uint32 *Acc = (Uint32*)malloc(NB_ELMT*sizeof(Uint32)); 
	for(j=0; j<NB_ELMT;j++){ 
		Acc[j]=0; 
	}
	
	// Compute Hough transform for every in(x,y)>0 
	for (j=1; j<hauteur-1; j++) { 
		for (i=1; i<largeur-1; i++) { 
			if (in[++ctr] == 255) { 
				angler = atan2(Gy[ctr],Gx[ctr]); 
				angler += (angler<0)*PI; 
				angle = (angler*I_PI)*MAXTHETA; 
				rho_idx = (Int32)((double)j*tSin[angle] + (double)i*tCos[angle] + (double)maxrho + 1) >>1; 
				Acc[(Uint32)((angle+(rho_idx>0)*PI)*maxrho+valeur_absolue(rho_idx))]++; 
			 } 
		} 
		ctr += 2; 
	} 
	
	// Draw Hough lines 
	// Case theta = 0 
	for (rho_idx=0; rho_idx<maxrho; rho_idx++) { 
		if (Acc[rho_idx] > vote) { 
			rho = (Int32)(rho_idx<<1) - maxrho; 
			for(y=rho; y<TAILLE; y+=largeur) { 
				out[y]=0; 
			} 
		} 
	} // Others angles 
	ctr = maxrho; 
	for (angle=1; angle<MAXTHETA; angle++) { 
		for (rho_idx=0; rho_idx<maxrho; rho_idx++) { 
			if (Acc[ctr++] > vote) { 
				angler = (Uint32)angle*PI/MAXTHETA; 
				rho = (Int32)(rho_idx<<1) - maxrho; 
				for(x=0;x<largeur;x++) { 
					y = (Int32)(((double)rho - (double)x*cos(angler))/sin(angler)+0.5); 
					if(y<hauteur && y>0) { 
						out[y*largeur+x]=0; 
					} 
				}
			} 
		} 
	} 
	free(Acc); 
}
