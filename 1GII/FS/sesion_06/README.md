# Sesión 6: Programación del shell


### ¿Qué pasa si eliminamos la redirección de la orden if?
Redirecciona el error del sistema a un dispositivo nulo para que no aparezca por pantalla, si se elimina lo mostrará por pantalla ya que es la salida estándar


***
## Copiar este ejercicio y probarlo en vuestro sistema para ver su funcionamiento. ¿Qué podemos modificar para que el giro se vea más rápido o más lento? ¿Qué hace la opción **–e** de las órdenes `echo` del guión?
```
#!/bin/bash
# rotor –- Randal M. Michael – Mastering Unix Shell Scripting, Wiley, 2003
function rotar_linea {
     INTERVAL=1     # Tiempo a dormir entre giro
     TCOUNT="0"     # Para cada TCOUNT la linea gira 45 grados
     while true     # Bucle infinito hasta que terminamos la funcion
do
     TCOUNT=`expr $TCOUNT + 1` # Incrementa TCOUNT
     case $TCOUNT in
          "1" ) echo -e "-""\b\c"
          sleep $INTERVAL
          ;;
          "2" ) echo -e '\\'"\b\c"
          sleep $INTERVAL
          ;;
          "3" ) echo -e "|""\b\c"
          sleep $INTERVAL
          ;;
          "4" ) echo -e "/""\b\c"
          sleep $INTERVAL
          ;;
          * ) TCOUNT="0" ;; # Pone a cero TCOUNT
     esac
done
}

######################################
######## Cuerpo principal ############
######################################

rotar_linea &     # Ejecuta la funcion rotar_linea de fondo
ROTAR_PID=$!     # Captura el PID del ultimo proceso de fondo

# Simulamos la ejecucion de una orden que consume mucha CPU
# durante la cual mostramos la linea rotando
for ((CONT=1; CONT<400000; CONT++ )); do
:
done

# Paramos la funcion rotar_linea
kill -9 $ROTAR_PID
# Limpiamos el trazo que queda tras finalizar
echo -e "\b\b"
```

Modificamos el valor de la variable **INTERVAL**, decrementándola para que vaya más rápido o incrementándola para que vaya más lento. La opción **-e** nos permite que la barra invertida sea reconocida como carácter de escape.


***
## Ejercicio 1
### Crea un guion que cree y muestre un vector. Este guion admite los siguientes argumentos: primero, el nombre del vector, segundo, el número de elementos, y tercero, el valor inicial de cada elemento (igual para todos los elementos). Por ejemplo, la ejecución inivec MV 3 aa creará un vector de 3 elementos de nombre MV y dará como salida aa aa aa. Comprobar que los argumentos son correctos y, si no lo son, invocar una función que muestre el uso correcto del guion.
```
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
```


***
## Ejercicio 2
### Construir un guion que detecte cuándo se inicia la ejecución de un proceso cuyo nombre se pasa como argumento. Cuando el proceso se inicia, indica al usuario el evento y finaliza. Si el proceso está ya activado cuando se inicia el guion, simplemente lo notifica y finaliza. Para su implementación utilizaremos la orden `ps -ef` para mostrar todos los procesos del sistema. Debemos de tener cuidado y eliminar del listado dado por `ps -ef` el proceso que ejecuta nuestro guion ya que en él aparece el nombre del proceso como argumento.
```
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
```


***
## Ejercicio 3
### Escribir un guion que almacene el tiempo que tarda una orden, que se pasa como argumento, en ejecutarse en las variables $REAL, $USER, $SYSTEM, correspondiente a los tres tiempos que la orden time da. El guion debe descartar la salida de la orden ejecutada, comprobar que solo hay un argumento, y si la orden pasada en el argumento es inválida debemos notificarlo.
```
#!/bin/bash

if test $# -ne 1;
 then 
     printf "\nTiene que introducir solo 1 argumento obligatoriamente: el proceso del que se va a almacenar el tiempo que tarda en ejecutarse.\n\n";
 else
     printf "\nTiempos de ejecucion del comando: $1\n"
     /usr/bin/time -f "%E real,%U user,%S sys" ls -Fs | head -0
fi
```


***
## Ejercicio 4
### Deseamos escribir un programa shell que admita como argumento el nombre de un shell (por ejemplo, `/bin/csh`, `/bin/sh`, `/bin/bash`, etc.) y nos dé un listado ordenado alfabéticamente de los usuarios que tiene dicho shell por defecto (definido en /etc/passwd). Para su construcción, nos será útil la orden `cut -d':' -f1` que corta el archivo por la columna 1 y donde el delimitador de columnas es el carácter “:”.
```
#!/bin/bash

if test $# -ne 1;
 then 
     printf "\nTiene que introducir solo 1 argumento obligatoriamente: el shell a comprobar por que usuarios es usado.\n\n";
 else
     printf "\nLista de usuarios que usan el shell \"$1\":\n"
     grep -w $1 /etc/passwd | cut -d':' -f1;
fi
```


***
## Ejercicio 5
### Dos órdenes frecuentes de Unix son tar y gzip. La orden tar permite almancenar/extraer varios archivos de otro archivo. Por ejemplo, podemos almacenar el contenido de un directorio en un archivo con `tar -cvf archivo.tar directorio` (la opción -x extrae los archivos de un archivo .tar). La orden gzip permite comprimir el contenido de un archivo para que ocupe menos espacio. Por ejemplo, `gzip archivo` comprime archivo y lo sustituye por otro con el mismo nombre y extensión .gz. La orden que hace lo contrario es gunzip. Dadas estas órdenes construir un guion, denominado cpback, que dado un directorio o lista de archivos como argumento(s) los archive y comprima en un archivo con nombre copiaYYMMDD, donde YY corresponde al año, la MM al mes y la DD al día, dentro de un directorio denominado CopiasSeguridad. El guión debe realizar las comprobaciones oportunas: los argumentos existen, el directorio de destino existe y si no, lo crea.
```
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
```
