#define p 1
#include "math2.h"
int nondet_int();
double nondet_double();

	int main() {

		
		double f_i = 32;

		double X_prev[2] = {0.000,0.000};
		int x[3], i;
		double X[3];
		double fobj;

		int lim[4] = {-10*p, 10*p, -10*p, 10*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_double();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (double) x[i]/p	);
			__ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = (1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625))*(1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625)) + (X[1]-1)*(X[1]-1);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
