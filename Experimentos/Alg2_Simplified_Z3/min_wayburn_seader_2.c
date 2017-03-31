#define p 1
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = 51747.53244-0.00001;
		float X_prev[2] = {0.000,0.000};
	float X_prev[2] = {2.000,9.000};
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

		fobj = (1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625))*(1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625)) + (X[1]-1)*(X[1]-1);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
