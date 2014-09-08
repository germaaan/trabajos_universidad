#!/bin/bash

if test $# -ne 1;
 then 
	printf "\nTiene que introducir 1 argumento obligatoriamente: el proceso que se va a eliminar.\n\n";
 else
	if test `pgrep $1 | head -1 | wc -l` -eq 0;
	 then
		printf "\nNo se ha encontrado el proceso \"$1\" en ejecucion.\n\n"
	else
		printf "\nNombre del proceso a eliminar: $1\n"
		printf "NOTA: Si el proceso se está ejecutando mas de una vez, solo se eliminara el mas antiguo.\n\n"
		printf "PID del proceso: `pgrep $1 | head -1`\n"
		printf "Esperando al resto de procesos en segundo plano..."
		(kill -9 `pgrep $1 | head -1`) &
		wait %1
	fi
fi
