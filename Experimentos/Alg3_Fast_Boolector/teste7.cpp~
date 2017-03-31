#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

	string line[5];
	string line_min[5];

	void take_function(string name);
	void create_function(string name);
	void create_mini_function(string name,double f_i, string type);
	void create_mini_function_positive(string name,double f_i, string type);

	int main(int argc, char *argv[ ]){

		
		//Variáveis Controle de Flag
		int i;
		int flag_double=0;
		int flag_float=0;
		int flag_positive=0;
		int flag_error=0;

		double F_I;
		string name_function, command;

		//Variáveis Parâmetros Básicos
		name_function = argv[1];
		F_I = atof(argv[2]);

		i=3;

		while(i<argc){
			if("--float" != string(argv[i]) && "--double" != string(argv[i]) && "--positive" != string(argv[i])){
				flag_error++;
			}			

			if("--float" == string(argv[i])){
				flag_float++;
			}			

			if("--double" == string(argv[i])){
				flag_double++;
			}			

			if("--positive" == string(argv[i])){
				flag_positive++;	
			}						
			i++;
		}

		if(flag_error != 0){
			cout << "Invalid Input!" << endl;
		}else{

			command  = "sed -i 15s/.*/'fun=(\"" + name_function + ".c"  + "\")'/ dados.sh";	
			system(command.c_str());
			command  = "sed -i 4s/.*/'f_i=" + string(argv[2]) + "'/ dados.sh";	
			system(command.c_str());
			command  = "sed -i 5s/.*/'f_c=0 '/ dados.sh";	
			system(command.c_str());

			switch(argc){

				case 3:
					take_function(name_function);
					create_function(name_function);				
					create_mini_function(name_function,F_I,"float");
					command  = "sed -i 16s/.*/'var=(\"float\")'/ dados.sh";	
					break;

				case 4:

					if(flag_positive==1 && flag_double==0 && flag_float==0 ){
						take_function(name_function);
						create_function(name_function);
						create_mini_function_positive(name_function,F_I,"float");
						command  = "sed -i 16s/.*/'var=(\"float\")'/ dados.sh";

					}else if(flag_positive==0 && flag_double==1 && flag_float==0 ){
						take_function(name_function);
						create_function(name_function);				
						create_mini_function(name_function,F_I,"double");
						command  = "sed -i 16s/.*/'var=(\"double\")'/ dados.sh";	
					
					}else if(flag_positive==0 && flag_double==0 && flag_float==1 ){
						take_function(name_function);
						create_function(name_function);				
						create_mini_function(name_function,F_I,"float");
						command  = "sed -i 16s/.*/'var=(\"float\")'/ dados.sh";	

					}
					break;

				case 5:

					if(flag_positive==1 && flag_double==1 && flag_float==0 ){
						take_function(name_function);
						create_function(name_function);
						create_mini_function_positive(name_function,F_I,"double");
						command  = "sed -i 16s/.*/'var=(\"double\")'/ dados.sh";	
	
					}else if(flag_positive==1 && flag_double==0 && flag_float==1 ){
						take_function(name_function);
						create_function(name_function);
						create_mini_function_positive(name_function,F_I,"float");
						command  = "sed -i 16s/.*/'var=(\"float\")'/ dados.sh";	

					}
					break;

				default :
					printf("Invalid Input!\n");
					return 0;
			}
			system(command.c_str());
		}

		command = "./dados.sh";	
		system(command.c_str());

		return 0;
	}

	void take_function(string name){

		int i=0;
		int prox = 0;

		char letter;
		ifstream file_min;
		
		file_min.open(name.c_str());

		if(!file_min.is_open( )){
			cout<<"Não foi possível abrir arquivo! Programa será terminado!\n";
			file_min.clear( ); //reseta o objeto leitura, para limpar memória do sistema}
		}

		while (file_min.get(letter)) {
			
			if(prox){
				if(letter == '1'){
					line[i] = line[i] + "[0]";					
					line_min[i] = line_min[i] + "[0]";					
				}else{
					line[i] = line[i] + "[1]";
					line_min[i] = line_min[i] + "[1]";				
				}
				prox = 0;					
			}else{
				if(letter == 'x'){
					line[i] = line[i] + letter;
					line_min[i] = line_min[i] + 'X';
					prox = 1;
				}else{
					line[i] = line[i] + letter;
					line_min[i] = line_min[i] + letter;
				}			
			}

			if(letter == '\n'){
				i++;
			}

		}

		line[0] = line[0].substr (0,line[0].size()-1); 			
		line[1] = line[1].substr (0,line[1].size()-1); 	
		line[2] = line[2].substr (0,line[2].size()-1); 	
		line[3] = line[3].substr (0,line[3].size()-1); 	
		line[4] = line[4].substr (0,line[4].size()-1); 	

		file_min.close();	
	}

	void create_function(string name){

		name = name + ".c";
		ofstream file_min;
		file_min.open(name.c_str());

		file_min << "#include<stdio.h>\n";
		file_min << "#include\"math2.h\"\n";
		file_min << "#include<stdlib.h>\n\n";

		file_min << "	int main(int argc, char *argv[]) {\n\n";
		file_min << "		FILE * fp;\n";
		file_min << "		double fobj;\n";
		file_min << "		char aux[100];\n";
		file_min << "		double x[2];\n";
		file_min << "		int i;\n\n";

		file_min << "		if (argc != 1)\n";
		file_min << "			return 1;\n\n";

		file_min << "		fp = fopen(\"output.txt\",\"rw+\");\n";
		file_min << "		if (fp == NULL)\n";
		file_min << "			return 0;\n";
		file_min << "		else{\n";
		file_min << "			for ( i = 0; i < 2; i++){\n";
		file_min << "				fscanf(fp,\"%s\",aux);\n";
		file_min << "				x[i] = atof(aux);\n";
		file_min << "			}\n";
		file_min << "		}\n";

		file_min << "		\n\n";
		file_min << "		" + line[0] + "\n\n\n";
		file_min << "		fprintf(fp,\"\\n%.5f\",fobj);\n";
		file_min << "		fclose(fp);\n";

		file_min << "		return 0;\n";
		file_min << "	}\n";
		file_min.close();
	}

	void create_mini_function(string name,double f_i, string type){
		
		name = "min_" + name + ".c";
		ofstream file_min;
		file_min.open(name.c_str());

		file_min << "#define p 1\n";
		file_min << "#include \"math2.h\"\n";
		file_min << "int nondet_int();\n";
		file_min << type + " nondet_"+type+"();\n";
		file_min << "\n";
		file_min << "	int main() {\n\n";

                file_min << "           \n";
                file_min << "           "+type+" f_i = "<< f_i << ";\n";
                file_min << "           "+type+" X_prev[2] = {0.000,0.000};\n";
                file_min << "           int x[3], i;\n";
                file_min << "           "+type+" X[3];\n";
                file_min << "           "+type+" fobj;\n\n";

		file_min << "		int lim[4] = {"+ line[1] +"*p, "+ line[2] +"*p, " + line[3] + "*p, " + line[4] + "*p};\n\n";

		file_min << "		for (i = 0; i<2; i++){\n";
		file_min << "			x[i] = nondet_int();\n";
		file_min << "			X[i] = nondet_double();\n";
		file_min << "		}\n\n";

		file_min << "		for (i = 0; i<2; i++){\n";
		file_min << "			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );\n";
		file_min << "			__ESBMC_assume( X[i] == ("+type+") x[i]/p	);\n";
		file_min << "                   __ESBMC_assume( X[i] != X_prev[i] );\n";
		file_min << "		}\n\n";

		file_min << "		" + line_min[0] + "\n\n";

		file_min << "		__ESBMC_assume(fobj < f_i );\n\n";

		file_min << "		assert(fobj > f_i);\n";

		file_min << "		return 0;\n";
		file_min << "	}\n";
		file_min.close();

	}


	void create_mini_function_positive(string name,double f_i, string type){
		
		name = "min_" + name + ".c";
		ofstream file_min;		
		file_min.open(name.c_str());

		file_min << "#define p 1\n";
		file_min << "#include \"math2.h\"\n";
		file_min << "int nondet_int();\n";
		file_min << type+" nondet_"+type+"();\n";
		file_min << "\n";
		file_min << "	int main() {\n\n";

		file_min << "		"+type+" f_c = 0;\n";
		file_min << "		"+type+" f_i = "<< f_i << ";\n\n";

		file_min << "		int x[3], i;\n";
		file_min << "		"+type+" X[2];\n";
		file_min << "		double fobj;\n\n";

		file_min << "		int lim[4] = {"+ line[1] +"*p, "+ line[2] +"*p, " + line[3] + "*p, " + line[4] + "*p};\n\n";

		file_min << "		for (i = 0; i<2; i++){\n";
		file_min << "			x[i] = nondet_int();\n";
		file_min << "			X[i] = nondet_"+type+"();\n";
		file_min << "		}\n\n";

		file_min << "		for (i = 0; i<2; i++){\n";
		file_min << "			__ESBMC_assume( (x[i]>=lim[2*i]) && (x[i]<=lim[2*i+1]) );\n";
		file_min << "			__ESBMC_assume( X[i] == ("+type+") x[i]/p	);\n";
		file_min << "		}\n\n";

		file_min << "		" + line_min[0] + "\n\n";

		file_min << "		__ESBMC_assume(fobj < f_i );\n\n";

		file_min << "		"+type+" delta = (f_i-f_c)/10;\n";
		file_min << "		if ((f_i-f_c) > 0.001){\n";
		file_min << "			while (f_c <= f_i){\n";
		file_min << "				assert(fobj > f_c);\n";
		file_min << "				f_c += delta;\n";
		file_min << "			}\n";
		file_min << "		}\n\n";

		file_min << "		return 0;\n";
		file_min << "	}\n";
		file_min.close();

	}



