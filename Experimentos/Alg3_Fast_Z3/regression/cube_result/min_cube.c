#define p 1
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = 627710168277262181992328436787501243831616673685046296576000.00000-0.00001;
 float X_prev[2] = {4294967290.000,4294967292.000};
           int x[3], i;
           float X[3];
           float fobj;

		int lim[4] = {-10*p, 10*p, -10*p, 10*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_double();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
                   __ESBMC_assume( X[i] != X_prev[i] );
		}

		fobj = 100*(X[1] - X[0]*X[0]*X[0])*(X[1] - X[0]*X[0]*X[0]) + (1-X[0])*(1-X[0]);


		__ESBMC_assume(fobj < f_i );

		assert(fobj > f_i);
		return 0;
	}
