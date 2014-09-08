#!/bin/bash

if test $# -ne 1;
 then 
	printf "\nTiene que introducir 1 argumento obligatoriamente: el proceso del que se quiere detectar cuando inicia la ejecucion.\n\n";
 else
	while :
	 do
		if test `ps -ef | grep -v grep | grep -v ejercicio2 | grep -w $1 | wc -l` -eq 0;
		 then
			printf "\nNo se ha encontrado el proceso \"$1\" en ejecucion.\n\n"
		else
			printf "\nSe ha encontrado el proceso \"$1\" en ejecucion.\n\n" 
			exit
		fi

		sleep 10
	done
fi
