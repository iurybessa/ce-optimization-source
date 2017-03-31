#define p 10000
#include "math2.h"
int nondet_int();
double nondet_double();

	int main() {

	double f_c = 0;
	double f_i = 0.00047-0.00001;

	double X_prev[2] = {0.500,1.020};
		int x[3], i;
		double X[2];
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

		double delta = (f_i-f_c)/5;
		if ((f_i-f_c) > 0.001){
			while (f_c <= f_i){
				assert(fobj > f_c);
				f_c += delta;
			}
		}

		return 0;
	}
