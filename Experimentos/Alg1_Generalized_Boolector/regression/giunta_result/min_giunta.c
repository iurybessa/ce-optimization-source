#define p 10
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = -0.49540-0.0001;

	float X_prev[2] = {0.500,0.400};
		int x[3], i;
		float X[3];
		float fobj;

		int lim[4] = {-1*p, 1*p, -1*p, 1*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
			__ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = sin2(16/15*X[0]-1) + sin2(16/15*X[0]-1)*sin2(16/15*X[0]-1) + (1/50)*sin2(4*(16/15*X[0]-1)) + sin2(16/15*X[1]-1) + sin2(16/15*X[1]-1)*sin2(16/15*X[1]-1) + (1/50)*sin2(4*(16/15*X[1]-1));


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
