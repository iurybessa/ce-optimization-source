#!/bin/bash


	rm result_total.txt	

 	declare -a functions_general=(

								# OK


									#'alpine1,10'				# OK float double
									#'booth,2'					# OK float double
									#'chung,90' 					# OK float double
									#'cube,99'					# OK float double 		//Valor Diferente, acho q tá certo
									#'dixon,43' # Trava					# OK float double
									#'egg_crate,14'				# OK float ------	  									
									'himmelblau,62'			# OK float double			
									'leon,84'					# OK float double								
									'powell_sum,36'			# OK float double
									'price4,75'				# OK float double
									'engvall,84'
									'schumer,31'				# OK float double
									'tsoulos,37'
									'branin_RCOS,65'
									'schwefel_2_25,39'			# OK float double							
									'sphere,88'					# OK float double
									'step2,41'					# OK float double 		//Valor Diferente, acho q tá certo float
									'scahffer4,24'
									'sum_squares,40'			# OK float double
									'wayburn_seader_2,32'		# OK float double		
									'adjiman,80'				# OK float double				
									'cosine,17'					# OK float double		
									'S2,74'					# OK float double
									'matyas,75'					# OK float double
									'rotated_ellipse,97'		# OK float double	 
									'styblinski_tang,84'		# OK float double	 		 	
									'trecanni,87'				# OK float double
									'ursem1,45'					# OK float double	 
									'zettl,33'					# OK float double
									'zirilli,26'				# OK float double 		

                                                                        #'engvall,84'
                                                                        #'stenger,26'
                                                                        #'bartels,16'
									#'beale,78'
									#'S2,74'
									#'F26,44'
									#'six_hump_camel_back,69'
									#'tsoulos,37'
									#'banana,96'
									#'drop_wave,35'


									#'branin_RCOS,65'
									#
#'mishra5,34'
#'giunta,45'
#'mc_cormick,78'
#'chenV,23'
#'chen_bird,38'
#'camelsixHump,25'
#'bohachevsky1,45'
#'El_attar,34'
#'keane,24'
#'quadratic,56'
#'scahffer3,78'
#'scahffer4,24'
#'trigonometric02,15'
							);

 	declare -a functions=(

								# OK
									#'adjiman,80'				# OK float double				
									#'cosine,17'					# OK float double		
									'deb1,22'					# OK float double
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
									#'bartels,16'
									#'stenger,26'
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

                                                                        'engvall,84'
                                                                        'stenger,26'
                                                                        'bartels,16'
                                                                        'beale,78'
                                                                        'S2,74'
                                                                        'F26,44'

									);


	for i in "${functions_general[@]}"
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

		(time ./mini $func $fi --double) 2>> result_total.txt  
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
