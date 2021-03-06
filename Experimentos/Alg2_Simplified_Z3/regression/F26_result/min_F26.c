#define p 10000
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = -0.15000;

	float X_prev[2] = {1.000,0.000};
		int x[3], i;
		float X[2];
		float fobj;

		int lim[4] = {-10*p, 10*p, -10*p, 10*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
			__ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = 0.25*X[0]*X[0]*X[0]*X[0] -0.5*X[0]*X[0] + 0.1*X[0] + 0.5*X[1]*X[1] ;


		__ESBMC_assume(fobj < f_i );

		float delta = (f_i-f_c)/5;
		if ((f_i-f_c) > 0.001){
			while (f_c <= f_i){
				assert(fobj > f_c);
				f_c += delta;
			}
		}

		return 0;
	}
