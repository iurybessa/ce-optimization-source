#define p 1
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = -inf-0.0001;

	float X_prev[2] = {-2.000,-6.000};
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

		fobj = -(0.001/(floor2(0.001*0.001 + (X[0]-0.4*X[1]-0.1)*(X[0]-0.4*X[1]-0.1)))) -(0.001/(floor2(0.001*0.001 + (2*X[0] + X[1] -1.5)*(2*X[0] + X[1] -1.5)))) ;


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
