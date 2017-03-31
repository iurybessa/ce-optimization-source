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
		

		fobj = -3803.84 -138.08*x[0] -232.92*x[1] +128.08*x[0]*x[0] + 203.64*x[1]*x[1] + 182.25*x[0]*x[1];


		fprintf(fp,"\n%.5f",fobj);
		fclose(fp);
		return 0;
	}
