#define p 10000
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = 229387.86531-0.00001;

		int x[3], i;
		float X[2];
		float fobj;

		int lim[4] = {(3.000*1000-1)*10, (3.000*1000+1)*10, (-9.000*1000-1)*10, (-9.000*1000+1)*10};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_double();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
		}

		fobj = (1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625))*(1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625)) + (X[1]-1)*(X[1]-1);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}