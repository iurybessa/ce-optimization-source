#define p 1
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

           
           float f_i = 75;
           float X_prev[2] = {0.000,0.000};
           int x[3], i;
           float X[3];
           float fobj;

		int lim[4] = {-1*p, 1*p, -1*p, 1*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_double();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
                   __ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = abs2(X[0])*abs2(X[0]) + abs2(X[1])*abs2(X[1])*abs2(X[1]);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
