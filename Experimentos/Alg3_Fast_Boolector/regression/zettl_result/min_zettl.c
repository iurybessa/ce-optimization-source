#define p 10000
#include "math2.h"
int nondet_int();
double nondet_double();

	int main() {

	double f_c = 0;
	double f_i = -0.00378-0.0001;
 double X_prev[2] = {-0.030,0.010};
           int x[3], i;
           double X[3];
           double fobj;

		int lim[4] = {(-0.030*1000-1)*10, (-0.030*1000+1)*10, (0.010*1000-1)*10, (0.010*1000+1)*10};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_double();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (double) x[i]/p	);
                   __ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = (X[0]*X[0] + X[1]*X[1] -2*X[0])*(X[0]*X[0] + X[1]*X[1] -2*X[0]) + 0.25*X[0];


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
