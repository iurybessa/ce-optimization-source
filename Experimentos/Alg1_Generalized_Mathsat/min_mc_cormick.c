#define p 1
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = -0.90930-0.00001;

		int x[3], i;
		float X[2];
		float fobj;

		int lim[4] = {-2*p, 4*p, -3*p, 3*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
		}

		fobj = sin2(X[0] + X[1]) + (X[0]-X[1])*(X[0]-X[1]) -(3/2)*X[0] + (5/2)*X[1] + 1;


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
