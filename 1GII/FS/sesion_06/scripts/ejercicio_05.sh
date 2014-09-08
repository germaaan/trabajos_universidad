#!/bin/bash

if test $# -lt 1;
 then 
	printf "\nTiene que introducir 1 argumento como minimo: uno o varios archivos o directorios para ser comprimidos.\n\n";

 else
	for i in $*
	 do
		if test -a $i;
		 then
			lista_elementos="$lista_elementos $i"
		else
			printf "\nEl archivo \"$i\" no existe, se cancela la ejecución del script.\n\n"
			exit;
		fi	
	 done 

	printf "\nLista de archivos a comprimir:$lista_elementos\n"

	if test ! -d $HOME/CopiasSeguridad;
	 then
		mkdir $HOME/CopiasSeguridad
	fi

	nombre_empaquetado=$HOME/CopiasSeguridad/copia`date "+%y%m%d"`.tar

	printf "\nEmpaquetando archivos...\n"

	tar -cf $nombre_empaquetado $lista_elementos

	printf "\nComprimiendo archivo empaquetado...\n\n"
	
	gzip $nombre_empaquetado

	printf "\nCompresion finalizada correctamente. Archivo creado en:\n$nombre_empaquetado\n\n"
fi
