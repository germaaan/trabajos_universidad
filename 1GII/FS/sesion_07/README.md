# Sesión 7: Depuración y Control de trabajos


***
## Ejercicio 2
### Escribir un guión que nos dé el nombre del proceso del sistema que consume más memoria.
```
#!/bin/bash

printf "\nProceso del sistema que consume mas memoria:\n\n"
printf "`ps -eo cmd,size --sort=-size | head -2`\n\n"
```


***
## Ejercicio 3
### Crear un guión que elimine un trabajo pasándole como argumento el nombre de la orden y a continuación espere al resto de los trabajos en segundo plano.
```
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
```
