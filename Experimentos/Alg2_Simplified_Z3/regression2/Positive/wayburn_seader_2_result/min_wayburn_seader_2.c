#define p 10000
#include "math2.h"
int nondet_int();
float nondet_float();

	int main() {

	float f_c = 0;
	float f_i = 544451784474817676840261823252922368.00000-0.001;

		int x[3], i;
		float X[2];
		double fobj;

		int lim[4] = {-10*p, 10*p, -10*p, 10*p};

		for (i = 0; i<2; i++){
			x[i] = nondet_int();
			X[i] = nondet_float();
		}

		for (i = 0; i<2; i++){
			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );
			__ESBMC_assume( X[i] == (float) x[i]/p	);
		}

		fobj = (1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625))*(1.613 -4*(X[0] -0.3125)*(X[0] -0.3125) -4*(X[1]-1.625)*(X[1]-1.625)) + (X[1]-1)*(X[1]-1);


		__ESBMC_assume(fobj < f_i );

		float delta = (f_i-f_c)/10;
		if ((f_i-f_c) > 0.001){
			while (f_c <= f_i){
				assert(fobj > f_c);
				f_c += delta;
			}
		}

		return 0;
	}
