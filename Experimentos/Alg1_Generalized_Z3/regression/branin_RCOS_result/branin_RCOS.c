#include<stdio.h>
#include"math2.h"
#include<stdlib.h>

	int main(int argc, char *argv[]) {

		FILE * fp;
		double fobj;
		char aux[100];
		double x[2];
		int i;

		if (argc != 1)
			return 1;

		fp = fopen("output.txt","rw+");
		if (fp == NULL)
			return 0;
		else{
			for ( i = 0; i < 2; i++){
				fscanf(fp,"%s",aux);
				x[i] = atof(aux);
			}
		}
		

		fobj = (x[1] -((5.1*x[0]*x[0])/(4*PI*PI)) +((5*x[0])/PI) -6)*(x[1] -((5.1*x[0]*x[0])/(4*PI*PI)) +((5*x[0])/PI) -6) + 10*(1-(1/(8*PI)))*cos2(x[0]) + 10;


		fprintf(fp,"\n%.5f",fobj);
		fclose(fp);
		return 0;
	}
