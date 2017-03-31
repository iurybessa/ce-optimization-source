#define p 10
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = 3.37375-0.00001;

		int x[3], i;
		float X[2];
		float fobj;

		int lim[4] = {-2*p, 2*p, -2*p, 2*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
		}

		fobj = abs2(X[0]*X[0]*X[0]*X[0]*X[0] -3*X[0]*X[0]*X[0]*X[0] +4*X[0]*X[0]*X[0] + 2*X[0]*X[0] -10*X[0] -4) + abs2(X[1]*X[1]*X[1]*X[1]*X[1] -3*X[1]*X[1]*X[1]*X[1] +4*X[1]*X[1]*X[1] + 2*X[1]*X[1] -20*X[1] -4);


		__ESBMC_assume(fobj < f_i );

		float delta = (f_i-f_c)/5;
		if ((f_i-f_c) > 0.001){
			while (f_c <= f_i){
				assert(fobj > f_c);
				f_c += delta;
			}
		}

		return 0;
	}