#!/bin/bash

if test $# -ne 1;
 then 
	printf "\nTiene que introducir solo 1 argumento obligatoriamente: el proceso del que se va a almacenar el tiempo que tarda en ejecutarse.\n\n";
 else
	printf "\nTiempos de ejecucion del comando: $1\n"
	/usr/bin/time -f "%E real,%U user,%S sys" ls -Fs | head -0
fi
