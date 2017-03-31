#define p 10000
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = -0.20000-0.001;

		int x[3], i;
		float X[2];
		float fobj;

		int lim[4] = {-1*p, 1*p, -1*p, 1*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
		}

		fobj = -0.1*(cos2(5*PI*X[0]) + cos2(5*PI*X[1])) +(X[0]*X[0] + X[1]*X[1]);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
