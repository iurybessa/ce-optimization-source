#define p 10000
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = 0.00000-0.0001;

	float X_prev[2] = {0.000,0.000};
		int x[3], i;
		float X[3];
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

		fobj = X[0]*X[0] + 2*X[1]*X[1] -0.3*cos2(3*PI*X[0]) -0.4*cos2(4*PI*X[1]) + 0.7;


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
