#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[ ]){

	double fobj,x1,x2;
	x1 = atof(argv[1]);
	x2 = atof(argv[2]);



	fobj = (-(1/2))*(pow(sin(5*M_PI*x1),6)+ pow(sin(5*M_PI*x2),6));

	printf("\nfobj: %f,%f %f\n\n",x1, x2, fobj);

	return 0;
}
