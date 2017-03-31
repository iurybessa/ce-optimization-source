#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
        FILE * fp;
        FILE * fp2;
        char aux;
        char p[100];

        int prec;
        int n = 2;

        if (argc != 2) return 1;
        sscanf(argv[1], "%d", &prec);

        double x[n];
        int i;

        fp2 = fopen("output.txt","w+");
        if (fp2==NULL){
                printf("Erro, nao foi possivel abrir o arquivo\n");
                return 0;
        }       
        fp = fopen ("x.txt", "r");
        if (fp == NULL){
                printf("Erro, nao foi possivel abrir o arquivo\n");
                fclose(fp2);
                return 0;
        }
        else {
                fscanf(fp,"%c",&aux);
                while (aux != '{'){
                        fscanf(fp,"%c",&aux);
                }
                for ( i = 0; i < n; i++){
                        fscanf(fp,"%s",p);
                        if (i != n-1) p[(strlen(p)-1)] = '\0';
                        x[i] = atoi(p);
                        if (x[i]/prec > 1000){
                                x[i] = (x[i]-4294967297)/prec;
                        }
                        else x[i] = x[i]/prec;
                        fprintf(fp2,"%.3f\n",x[i]);
                }
        }
        fclose(fp);
        fclose(fp2);
        return 0;
}

