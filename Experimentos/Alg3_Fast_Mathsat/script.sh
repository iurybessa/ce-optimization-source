#!/bin/bash

	rm result_total.txt	


 	declare -a functions=(


								# EM TESTE
									
									#'Branin_RCOS,100'			# OK float ------	
									#'mishra4,100'				# Próximo float 						RAIZ
									#'mishra5,100'				# Próximo float 									 
									 					
								# Erro
									#'deckkers,100'				# Error ------------- overflow
									#'goldstein,100'			# Error ------------- overflow
									#'rosenbrock,100' 			# Error ------------- overflow
									#'damavandi,100'			# Error ------------- overflow nan 	
									#'csendes,100'				# Error ------------- nan
									#'keane,100'				# Error ------------- -nan (float) RAIZ
	
									#'bohachevsky1,100'			# Error	------------- Preso no 100 / Não é overflow 
									#'bohachevsky2,100'			# Error	------------- Preso no 100
									#'bohachevsky3,100'			# Error	------------- Preso no 100
									#'chen_bird,100'			# Error ------------- preso no -1961.53846 (double)
									#'salomon,100'				# OK float ------ Error Double Preso em 0.00314

									#'scahffer1,100'			# Error ------------- Desconhecido 					

								# Reavaliar
									#'giunta,100'				# Error ------------- Valores Diferentes 
									#'mc_cormick,100'			# Valores Diferentes (float) | Vai minimixar correto, demorando (double)
									#'chen_v,100'				# Error ------------- Valores Diferentes (float) (double)

								# OK
									#'adjiman,100'				# OK float double				
									#'bukin2,100'				# OK float double				
									#'cosine,100'				# OK float double													
									#'deb1,100'					# OK float double
									#'matyas,100'				# OK float double
									'rotated_ellipse,100'		# OK float double
									'rotated_ellipse2,100'		# OK float double
									#'styblinski_tang,100'		# OK float double
									#'trecanni,100'				# OK float double
									#'ursem1,100'				# OK float double
									#'venter,100'				# OK float ??????	
									#'zettl,100'				# OK float double
									#'zirilli,100'				# OK float double
								
							);

 	declare -a functions_positive=(	

								# EM TESTE

									#'bukin4,100' 				# float double /falta catalogar /rápido 	
									#'price1,100'				# float double /falta catalogar /rápido
									#'wayburn_seader_1,100'		# float double /falta catalogar /rápido

									#'el_attar,100'				# Vai minimixar correto, demorando (float)	demorando (double)
									#'bartels,100'				# Vai minimixar correto, demorando (float)  demorando (double)
									#'beale,100'				# Vai minimixar correto, demorando (float)	demorando (double)

								# Error
									#'camel_Three,100'			# Error	Reescrever entrada												

								# OK 
									#'alpine1,100'				# OK float double
									#'booth,100'				# OK float double
									#'chung,100' 				# OK float double
									#'cube,100'					# OK float double 		//Valor Diferente, acho q tá certo float
									#'dixon,100'				# OK float double
									#'egg_crate,100'			# OK float ------	  									
									#'himmelblau,100'			# OK float double			
									#'leon,100'					# OK float double								
									#'powell_sum,100'			# OK float double
									#'price4,100'				# OK float double
									#'quintic,100'				# OK float double 	
									#'schumer,100'				# OK float double
									#'schwefel,100'				# OK float double
									#'schwefel_2_23,100'		# OK float double
									#'schwefel_2_25,100'		# OK float double							
									#'sphere,100'				# OK float double
									#'step2,100'				# OK float double 		//Valor Diferente, acho q tá certo float
									#'step3,100'				# OK float double							
									#'sum_squares,100'			# OK float double
									#'wayburn_seader_2,100'		# OK float double							

								# Outros
									#'freudenstein,100'			# OK ----- double
									#'price3,100'				# OK ----- double 		//Valor Diferente, acho q tá certo float


									);


	for i in "${functions[@]}"
	do		
		line=$i
		func=${line//,*}       	
		fi=${line//*,}       	

		echo >> result_total.txt			
		echo >> result_total.txt			
		echo "###########################">> result_total.txt	
		echo "\/\/\/\/\/\/\/\/\/\/\/\/\/">> result_total.txt	

	    echo "Function $func f_i:$fi"

		cp 'regression/'$func $func

		(time ./mini $func $fi) 2>> result_total.txt  
		rm -r regression/$func'_result'/

		echo >> result_total.txt	
		echo "Function $func f_i:$fi" >> result_total.txt	
		cat output.txt >> result_total.txt

		mkdir regression/$func'_result'/	
		mv $func'.c' regression/$func'_result'/
		mv 'min_'$func'.c' regression/$func'_result'/
		mv output.txt regression/$func'_result'/
		mv log.txt regression/$func'_result'/
		mv x.txt regression/$func'_result'/
		rm $func

		echo
	done

	rm teste.txt
