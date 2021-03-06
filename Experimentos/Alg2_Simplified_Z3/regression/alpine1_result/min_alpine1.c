#define p 10000
#include "math2.h"
int nondet_int();
double nondet_double();

	int main() {

	double f_c = 0;
	double f_i = 0.00000-0.001;

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
		}

		fobj = abs2(X[0]*sin2(X[0]) + 0.1*X[0]) + abs2(X[1]*sin2(X[1]) + 0.1*X[1]);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
