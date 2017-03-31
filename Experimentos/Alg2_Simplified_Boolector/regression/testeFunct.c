#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[ ]){

	double fobj,x1,x2;
	x1 = atof(argv[1]);
	x2 = atof(argv[2]);


	fobj = (1.613 -4*(x1 -0.3125)*(x1 -0.3125) -4*(x2-1.625)*(x2-1.625))*(1.613 -4*(x1 -0.3125)*(x1 -0.3125) -4*(x2-1.625)*(x2-1.625)) + (x2-1)*(x2-1);


	printf("\nfobj: %f,%f %f\n\n",x1, x2, fobj);

	return 0;
}
