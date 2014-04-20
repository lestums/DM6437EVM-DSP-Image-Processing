/* =========================================================================

	VARS.C		Ensemble des variables utilisées au sein du projet DSP C6437
	
	AUTEURS :
	
				JOUVENCE	Pierre-Marie
				LE STUM 	Sébastien
	
	Ce fichier à été élaboré dans le cadre du projet de E4 - INF4303C

	========================================================================
*/
#ifndef VARS_H_
#define VARS_H_

/* IMAGE RELATED CONSTANTS */
#define WIDTH 720
#define HEIGHT 480
#define NB_PIXELS WIDTH*HEIGHT
#define ITERNUM 10000

/* MISC */
#define GAMMA 0.20
#define SEUIL 130
#define MAX_VOTES 200

/* MATHS CONSTANTS */
#define MAXTHETA 180 
#define PI 3.14159265 
#define I_PI 0.31830989
#define SQRT_MAGIC_D 0x5fe6ec85e7de30da

/* VERSION FLAG */
#define OPTIMISE 1

#endif /*VARS_H_*/
