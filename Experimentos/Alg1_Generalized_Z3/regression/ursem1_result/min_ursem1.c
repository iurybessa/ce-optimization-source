#define p 10
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = -4.81680-0.0001;

	float X_prev[2] = {1.700,0.000};
		int x[3], i;
		float X[3];
		float fobj;

		int lim[4] = {-3*p, 3*p, -2*p, 2*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
			__ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = -sin2(2*X[0] - 0.5*PI) - 3*cos2(X[1]) -0.5*X[0];


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
