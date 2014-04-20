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

void hough_nonopt(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 votes) { 
	//We assume here that the dimensions of in and the ones of the RGB image are the same 
	Uint32 i,j,x,y,rho=0,angle=0,AccMax=0,rho_idx=0,maxrho = (Uint32)ceil(sqrt(largeur*largeur + hauteur*hauteur)); 
	double angler=0; 
	// Accumulator initialization 
	Uint32 *Acc = (Uint32*)malloc(MAXTHETA*maxrho*sizeof(Uint32)); 
	for(j=0; j<maxrho*MAXTHETA;j++){ 
		Acc[j]=0; 
	} 
	// Compute Hough transform for every in(x,y)>0 
	for (j=1; j<hauteur-2; j++) { 
		for (i=1; i<largeur-2; i++) { 
			if (in[j*largeur+i] == 255) { 
				for (angle=0; angle<MAXTHETA; angle++) { 
					angler = angle*PI/MAXTHETA; rho_idx = (Uint32)((double)j*sin(angler) + (double)i*cos(angler) + (double)maxrho)/2; 
					if (rho_idx<maxrho && rho_idx>0) { Acc[rho_idx*MAXTHETA+angle]++; 
						if (Acc[rho_idx*MAXTHETA+angle] > AccMax) { 
							AccMax = Acc[rho_idx*MAXTHETA+angle]; 
						} 
					} 
				} 
			} 
		}
	}
	// Draw Hough lines 
	for (rho_idx=0; rho_idx<maxrho; rho_idx++) { 
		for (angle=1; angle<MAXTHETA; angle++) { 
			if (Acc[rho_idx*MAXTHETA+angle] > AccMax-30) { 
				angler = angle*PI/MAXTHETA; rho = rho_idx*2 - maxrho; 
				for(x=0;x<largeur;x++) { 
					y = (Uint32)((double)rho - (double)x*cos(angler))/sin(angler); 
					if(y<hauteur && y>0) { 
						out[y*largeur+x]=0; 
					} 
				} 
			} 
		} 
	} 
	free(Acc); 
}

void hough_optimise(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Int32 vote, double *Gx, double *Gy, double *tSin, double *tCos) { 
	
	//We assume here that the dimensions of in and the ones of the RGB image are the same 
	int rho=0,angle=0,rho_idx=0,maxrho = (Int32)(fastSqrtD(hauteur*hauteur+largeur*largeur) + 0.9); 
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

void TracerLine(Uint8 *out,float coeff, float ori){
	int i,j;
	coeff=-coeff;
	ori=HEIGHT-ori;
	for(i=0;i<WIDTH;i++){
		j=(int)(coeff*i+ori);
		if(j>=HEIGHT ||j<0) continue;
		out[j*WIDTH+i]=255;
	}
	for(i=0;i<HEIGHT;i++){
		j=(int)((i-ori)/coeff);
		if(j>=WIDTH || j<0) continue;
		out[i*WIDTH+j]=255;
	}
}


void hough_test(Uint8 *in, Uint8 *out, Uint32 largeur, Uint32 hauteur, Uint32 vote, Uint32 seuil, double *tSin, double *tCos) { 
	
	int rho=0;
  	int maxrho=(int)sqrt(WIDTH*WIDTH + HEIGHT*HEIGHT);
  	int angle=0, i,j;
  	
  	int* Accu = (int*) calloc(sizeof(int)*180*865,0);
	// Accumulator calc
	for(i=1;i<hauteur-1;i++){
		for(j=1;j<largeur-1;j++){
			if(in[i*largeur+j]>0){
				for(angle=1;angle<=180;angle++){
					rho=(int)((j*tCos[angle]+i*tSin[angle])/2+maxrho/2);
					if(rho>0 &&	*(Accu+rho*180+angle-1)<255){
						Accu[rho*180+angle-1] += 1;
					} else {
						break;
					}
				}	
			}	
		}	
	}
 
 	// Drawing lines
	for(i=0;i<180;i++){
		for(j=0;j<maxrho;j++){
			if(*(Accu+i+j*180)>seuil){
				TracerLine(out,tCos[i+1]/tSin[i+1],HEIGHT-((j+1)*2-maxrho)/tSin[angle]);
			}	
		}
	}
}

