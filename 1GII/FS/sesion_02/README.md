# Sesión 2: Órdenes de UNIX/Linux (Parte I)


## Ejercicio 1
### Con cada orden descrita en la Tabla 1 de la primera página de esta práctica y haciendo uso de la orden man, haga un pequeño manual de uso de cada una de las órdenes objeto de estudio de esta sesión.

* **man**: muestra un manual del sistema. Suele usarse para conocer la descripción y la sintaxis de alguna orden del shell.
```
man ORDEN
```

* **info**: lee documentos con formato Info.
```
info [OPCION] ... [MENU-ITEM...]
```

* **touch**: actualiza la fecha de acceso y modificación de cada archivo indicado a la fecha actual. Si el archivo indicado no existe, crea un archivo vacío con dicho nombre.
```
touch [OPCION] ... [ARCHIVO]
```

* **ls**: lista los archivos contenidos en un directorio. Sin argumentos muestra los archivos del directorio actual, también podemos hacer que muestre el contenido de otro directorio cualquiera que le indiquemos y que nos lo muestre con un formato específico.
```
ls [OPCION] [ARCHIVOS]
```
> **Opciones más comunes:**

> **-a**: muestra todo el contenido, aunque este esté marcado como oculto.

> **-B**: no muestra los archivos cuyo nombre termine en "~", estos archivos corresponde a copias de seguridad que están siendo usados en ese momento.

> **-C**: muestra el contenido en columnas.

> **-l**: muestra el contenido en formato largo, indicándonos todos los permisos de lectura, escritura y ejecución para todos los usuarios y el propietario entre otras propiedades.

> **-R**: muestra el contenido del directorio indicado y de todos los directorios existentes dentro de él de forma recursiva.

> **-S**: muestra el contenido ordenado por su tamaño.

* **pwd**: muestra el directorio actual de trabajo.
```
pwd [OPCION] ...
```

* **who**: muestra quien se encuentra logueado actualmente en el sistema.
```
who [OPCION] ... [ARCHIVO | ARGUMENTO1 ARGUMENTO2]
```

* **file**: indica el tipo de un archivo.
```
file [ARCHIVO]
```

* **cp**: copia archivo y directorios.
```
cp [OPCION] ... ORIGEN ... DESTINO
```

* **mv**: mueve un archivo a otro archivo, cambiando su ruta de acceso y, si se lo indicamos, el nombre.
```
mv [OPCION] ... ORIGEN ... DESTINO
```

* **rm**: borra archivos y directorios.
```
rm [OPCION] ... ARCHIVO ...
```
> **Opciones más comunes:**

> **-r, -R**: borra los directorios y sus contenido recursivamente.

* **mkdir**: crea un directorio.
```
mkdir [OPCION] ... DIRECTORIO ...
```
> **Opciones más comunes:**

> **-p**: si no existe el directorio padre de la ruta indicada, también lo crea.

* **rmdir**: borra directorios vacíos.
```
rmdir [OPCION] ... DIRECTORIO ...
```
> **Opciones más comunes:**

> **--ignore-fail-on-non-empty**: ignora que el directorio indicado no esté vacío.

> **-p**: borra el directorio indicado y además sus directorios padres.

* **cat**: muestra el contenido de un archivo.
```
cat [OPCION] ... [ARCHIVO] ...
```

* **more**: muestra de forma escalonado la salida generada por una orden.
```
ORDEN [OPCION] ... | more
```

* **tail**: muestra la última parte del contenido de un archivo.
```
tail [OPCION] ... [ARCHIVO] ...
```

* **sort**: ordena alfabéticamente la salida resultante de la ejecución de una orden o un archivo.
```
sort [OPCION] ... [ARCHIVO] ...
```
> **Opciones más comunes:**

> **-r**: ordena la salida en orden inverso.

* **tar**: utilidad que permitir archivar y/o comprimir varios archivos en un único archivo y viceversa.
**Comprimir:**
```
tar -cvf DESTINO ARCHIVO ...
```
**Descomprimir:**
```
tar -xvf DESTINO ARCHIVO ...
```
> **Opciones más comunes:**

> **-c**: crea un nuevo archivo.

> **-x**: extrae los archivos de uno existente.

> **-v**: se van mostrando los archivos que se van empaquetando o desempaquetando.

> **-f**: empaqueta los contenidos.


***
## Ejercicio 2
### La organización del espacio en directorios es fundamental para poder localizar fácilmente aquello que estemos buscando. En ese sentido, realice las siguientes acciones dentro de su home:

* Crear un directorio para cada asignatura en la que se van a realizar prácticas de laboratorio y, dentro de cada directorio, nuevos directorios para cada una de las prácticas realizadas hasta el momento. Vamos tomar como ruta de base nuestro directorio **HOME**.
```
cd
mkdir CA FFT ALEM FP FS
cd ca
mkdir PRACTICA1 PRACTICA2
cd ..
cd fft
mkdir PRACTICA1 PRACTICA2
cd ..
cd alem
mkdir PRACTICA1 PRACTICA2
cd ..
cd fp
mkdir PRACTICA1 PRACTICA2
cd ..
cd fs
mkdir PRACTICA1 PRACTICA2
```

* Dentro del directorio de la asignatura fundamentos del software (llamado fs) y dentro del directorio creado para esta sesión, copiar los archivos `/etc/hosts` y `/etc/passwd`.
```
cp /etc/hosts /etc/passwd ~/fs/PRACTICA2
```

* Mostrar el contenido de cada uno de los archivos.
```
cat ~/fs/PRACTICA2/hosts
cat ~/fs/PRACTICA2/passwd
```


***
## Ejercicio 3
### Desplacémonos hasta el directorio /bin, genere los siguientes listados de archivos (siempre de la forma más compacta y utilizando los metacaracteres apropiados):
```
cd /bin
```
* Todos los archivos que contengan sólo cuatro caracteres en su nombre.
```
ls ????
```
* Todos los archivos que comiencen por los caracteres d, f.
```
ls [d,f]*
```
* Todos los archivos que comiencen por las parejas de caracteres sa, se, ad.
```
ls {sa,se,ad}*
```
* Todos los archivos que comiencen por t y acaben en r.
```
ls t*r
```
