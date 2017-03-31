#include<stdio.h>
#include<math.h>
#include<stdlib.h>

	double main(int argc, char *argv[ ]){

		double fobj;
		double x[2];

		x[0] = atof(argv[1]);
		x[1] = atof(argv[2]);

		fobj = - 0.001/( 0.001*0.001 + (x[0]*x[0] + x[1]*x[1] -1)*(x[0]*x[0] + x[1]*x[1] -1)) - 0.001/( 0.001*0.001 + (x[0]*x[0] + x[1]*x[1] -0.5)*(x[0]*x[0] + x[1]*x[1] -0.5)) - 0.001/( 0.001*0.001 + (x[0]*x[0] + x[1]*x[1])*(x[0]*x[0] + x[1]*x[1]));

		printf("%f",fobj);
		return 0;
	}
