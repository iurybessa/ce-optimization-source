#define p 10000
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = 2135987021001212990101422441508084670198079319342968246026610084608300418985855639646960820944896.00000-0.001;

		int x[3], i;
		float X[2];
		double fobj;

		int lim[4] = {-10*p, 10*p, -10*p, 10*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
		}

		fobj = X[0]*X[0]*X[0]*X[0]*X[0]*X[0]*X[0]*X[0]*X[0]*X[0] + X[1]*X[1]*X[1]*X[1]*X[1]*X[1]*X[1]*X[1]*X[1]*X[1];


		__ESBMC_assume(fobj < f_i );

		float delta = (f_i-f_c)/10;
		if ((f_i-f_c) > 0.001){
			while (f_c <= f_i){
				assert(fobj > f_c);
				f_c += delta;
			}
		}

		return 0;
	}
