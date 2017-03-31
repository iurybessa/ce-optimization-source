#!/bin/bash
chmod 777 -R dados.sh
#inicialização das variáveis
f_i=49
f_c=0 
p=1
check=0

#define a função a ser minimizada
#i=0  minimiza a função de himmelblau1
#i=1  minimiza a função de goldstein-price
#i=2  minimiza a função de styblinski-tang
#fun=("chung.c")
i=0
fun=("booth.c")
var=("float")

sed -i 1s/.*/'#define p '$p/ 'min_'$fun
sed -i 8s/.*/'	'${var}' f_c = '$f_c';'/ 'min_'$fun
sed -i 9s/.*/'	'${var}' f_i = '$f_i';'/ 'min_'$fun
sed -i 15s/.*/'		int lim[4] = {-10*p, 10*p, -10*p, 10*p};'/ 'min_'$fun

#gcc tratamento.c -o tratamento -lm
#gcc verifica.c -o verifica

gcc $fun -o valor_fun -lm

while [ $p -ne 10000 ]
do
	echo '------------------------'
	while [ $check -eq 0 ]
	do
		echo "$f_i"
		{ time ./esbmc 'min_'$fun --z3 --floatbv\
		> log.txt;
		} 2>> log.txt

		#verifica se houve sucesso ou falha
		grep "VERIFICATION" log.txt | tac | head -n1 | sed "s/ nil,//g" > teste.txt
		./verifica
		check=$?
		if [ $check -eq 1 ]
		then	break
		fi

		#grava os valores do ponto mínimo atual
		grep ":x=" log.txt | tac | head -n1 | sed "s/ nil,//g" > x.txt

		./tratamento #$p
		x1=$(head -1 output.txt)
		x2=$(tail -1 output.txt)
		./valor_fun
		f_i=$(tail -1 output.txt)
		sed -i 10s/.*/' '${var}' X_prev[2] = {'$x1','$x2'};'/ 'min_'${fun}
		sed -i 9s/.*/'	'${var}' f_i = '$f_i-0.00001';'/ 'min_'$fun
	done
	sed -i 15s/.*/'		int lim[4] = {('$x1*$p-1')*10, ('$x1*$p+1')*10, ('$x2*$p-1')*10, ('$x2*$p+1')*10};'/ 'min_'$fun
	#break	
	check=0
	p=$(($p*10))
	sed -i 1s/.*/'#define p '$p/ 'min_'$fun
done
