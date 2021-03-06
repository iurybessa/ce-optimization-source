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
		

		fobj = -sin2(2*x[0] - 0.5*PI) - 3*cos2(x[1]) -0.5*x[0];


		fprintf(fp,"\n%.5f",fobj);
		fclose(fp);
		return 0;
	}
