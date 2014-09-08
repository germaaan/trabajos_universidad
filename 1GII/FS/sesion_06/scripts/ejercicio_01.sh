#!/bin/bash

if test $# -ne 3;
 then 
	printf "\nTiene que introducir 3 argumentos obligatoriamente: nombre de vector, numero de elementos y valor inicial de cada elemento.\n\n";
 else
	vector=$1
	num_elementos=$2
	valor_elemento=$3

	for((i=0;i<num_elementos;i++)); 
	 do
		vector[$i]=$valor_elemento
	 done

	printf "\nValores contenido en el vector: \n"

	for((j=0;j<num_elementos;j++)); 
	 do
		printf "\t${vector[$j]}\n"
	 done

	printf "\n";
fi
