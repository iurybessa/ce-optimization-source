#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[ ]){

	double fobj,x1,x2;
	x1 = atof(argv[1]);
	x2 = atof(argv[2]);



	fobj = (x1 -1)*(x1 -1) + 2*(2*x2*x2 - x1)*(2*x2*x2 - x1);

	printf("\nfobj: %f,%f %f\n\n",x1, x2, fobj);

	return 0;
}
