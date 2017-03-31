#define p 1
#include "math2.h"
int nondet_int();
double nondet_double();

	int main() {

		
		double f_i = 65;

		double X_prev[2] = {0.000,0.000};
		int x[3], i;
		double X[3];
		double fobj;

		int lim[4] = {-5*p, 10*p, 0*p, 15*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_double();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (double) x[i]/p	);
			__ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = (X[1] -((5.1*X[0]*X[0])/(4*PI*PI)) +((5*X[0])/PI) -6)*(X[1] -((5.1*X[0]*X[0])/(4*PI*PI)) +((5*X[0])/PI) -6) + 10*(1-(1/(8*PI)))*cos2(X[0]) + 10;


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
