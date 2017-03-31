#!/bin/bash


	rm result_total.txt	


 	declare -a functions=(
								# OK
									#'adjiman,80'				# OK float double				
									#'cosine,17'					# OK float double		
									#'deb1,22'					# OK float double
									#'matyas,75'					# OK float double
									#'rotated_ellipse,97'		# OK float double	 
									##'styblinski_tang,84'		# OK float double	 		 	
									#'trecanni,87'				# OK float double
									#'ursem1,45'					# OK float double	 
									#'zettl,33'					# OK float double
									##'zirilli,26'				# OK float double 		

							);

 	declare -a functions_positive=(	

								# OK 
									#'alpine1,10'				# OK float double
									#'booth,2'					# OK float double
									#'chung,90' 				# OK float double
									#'cube,99'					# OK float double 		//Valor Diferente, acho q tá certo
									#'dixon,43'				# OK float double
									#'egg_crate,14'				# OK float ------	  									
									#'himmelblau,62'			# OK float double			
									#'leon,84'					# OK float double								
									#'powell_sum,36'			# OK float double
									#'price4,75'				# OK float double
									#'quintic,53'				# OK float double 	
									#'schumer,31'				# OK float double
									#'schwefel,71'				# OK float double
									#'schwefel_2_23,87'		# OK float double
									#'schwefel_2_25,39'			# OK float double							
									#'sphere,88'				# OK float double
									#'step2,41'					# OK float double 		//Valor Diferente, acho q tá certo float
									#'step3,21'					# OK float double							
									#'sum_squares,40'			# OK float double
									#'wayburn_seader_2,57'		# OK float double							

									);

 	declare -a functions_convex=(	
									'booth,49'		
									'chung,96'
									'cube,98'
									'dixon,38'		
									'powell_sum,75'	
									'schumer,7'
									'sum_squares,37'
									'matyas,25'											
									'rotated_ellipse,26'		
									'zettl,98'					
									);


	for i in "${functions_convex[@]}"
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

		(time ./mini $func $fi --double ) 2>> result_total.txt  
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
