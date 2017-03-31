#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[ ]){

	double fobj,x1,x2;
	x1 = atof(argv[1]);
	x2 = atof(argv[2]);

	fobj = 0.6 + ( sin(1 - (16/15)*x1)*sin(1 - (16/15)*x1) - (1/50)*sin(4 -(64/15)*x1) - sin(1 -(16/15)*x1) ) + ( sin(1 - (16/15)*x2)*sin(1 - (16/15)*x2) - (1/50)*sin(4 -(64/15)*x2) - sin(1 -(16/15)*x2) );

	printf("\nfobj: %f\n\n",fobj);

	return 0;
}
