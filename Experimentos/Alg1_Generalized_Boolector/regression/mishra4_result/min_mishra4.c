#define p 10
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = -0.10132-0.0001;

	float X_prev[2] = {-8.100,-9.600};
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

		fobj = sqrt2(abs2(sin2(sqrt2(abs2(X[0]*X[0]+X[1]*X[1]))))) +0.01*(X[0]+X[1]);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
