/* =========================================================================

	PROJET_MATHS.C	Implemente l'algorithme de Deriche dans le cadre d'une
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

double invSqrtD(const double x) { 
	const double xhalf = 0.5F*x; 
	union { 
		double x; 
		long i; 
	} u; 
	u.x = x; 
	u.i = SQRT_MAGIC_D - (u.i >> 1); 
	return u.x*(1.5F - xhalf*u.x*u.x);
} 

Uint32 fastSqrtD(const double x) { 
	return (Uint32)(x * invSqrtD(x)); 
}
