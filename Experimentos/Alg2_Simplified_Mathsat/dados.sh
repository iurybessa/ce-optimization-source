#!/bin/bash
chmod 777 -R dados.sh
#inicialização das variáveis
f_i=21
f_c=0 
p=1
check=0

#define a função a ser minimizada
#i=0  minimiza a função de himmelblau1
#i=1  minimiza a função de goldstein-price
#i=2  minimiza a função de styblinski-tang
#fun=("chung.c")
i=0
fun=("scahffer4.c")
var=("float")

sed -i 1s/.*/'#define p '$p/ 'min_'${fun[i]}
sed -i 8s/.*/'	'${var[i]}' f_c = '$f_c';'/ 'min_'${fun[i]}
sed -i 9s/.*/'	'${var[i]}' f_i = '$f_i';'/ 'min_'${fun[i]}

#gcc tratamento.c -o tratamento -lm
#gcc verifica.c -o verifica
gcc ${fun[i]} -o valor_fun -lm

while [ $p -ne 10000 ]
do
	echo '------------------------'
	while [ $check -eq 0 ]
	do
		echo "$f_i"	#escreve o último valor da função encontrado como mínimo
		{ time ./esbmc_3.1 'min_'${fun[i]} --floatbv --mathsat\
		> log.txt;
		} 2>> log.txt

		#verifica se houve sucesso ou falha na verificação
		grep "VERIFICATION" log.txt | tac | head -n1 | sed "s/ nil,//g" > teste.txt
		./verifica
		check=$?
		if [ $check -eq 1 ]
		then	break
		fi
		
		#grava os valores do ponto mínimo atual e calcula o valor da função
		grep ":X=" log.txt | tac | head -n1 | sed "s/ nil,//g" > x.txt		#pegar x1 e x2
		./tratamento														#pegar x1 e x2	
		./valor_fun
		f_i=$(tail -1 output.txt)

		sed -i 9s/.*/'	'${var[i]}' f_i = '$f_i-0.00001';'/ 'min_'${fun[i]}
	done
	check=0
	p=$(($p*10))
	sed -i 1s/.*/'#define p '$p/ 'min_'${fun[i]}
done
#os valores das variáveis e valor função estão no arquivo output.txt, ao final da execução do código este conterá o ponto de mínimo e valor mínimo da função
