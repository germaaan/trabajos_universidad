# Sesión 4: Variables, Alias y Órdenes de Búsqueda


## Tipos de variables
### Escribe, al menos, cinco variables de entorno y cuál es su valor.

* **SHELL**: indica el shell del sistema. Su valor es `/bin/bash`.
* **PWD**: indica el directorio de trabajo actual del usuario. Su valor es `/home/germaaan`.
* **HOME**: indica el directorio de trabajo del usuario. Su valor es `/home/germaaan`.
* **USERNAME**: indica el nombre de usuario del usuario. Su valor es `germaaan`.
* **DESKTOP_SESSION**: indica el entorno de escritorio que se está usando. Su valor es `gnome`.


***
## Creación y visualización de variables
### Prueba la siguiente asignación:
```
% numero=$numero + 1
% echo $numero
```
### ¿Qué ha ocurrido?

Añade al valor de la variable $numero los caracteres "+1".


***
## Exportar variables
### Ejecute las órdenes del cuadro e indique qué ocurre y cómo puede resolver la situación para que la variable NOMBRE se reconozca en el shell hijo.

Después de la declaración de la variable y antes de llamar al shell hijo exportamos la variable con la orden `export`.


***
## Ejercicio 1
### Crea tres variables llamadas VAR1, VAR2 y VAR3 con los siguientes valores respectivamente “hola”, “adios”, “14”.
```
VAR1=hola VAR2=adios VAR3=14
```
* **Visualiza los valores de las tres variables en tres columnas de 15 caracteres de ancho.**

```
printf "%15s %15s %15d\n" $VAR1 $VAR2 $VAR3
```

* **¿Son variables locales o globales?**

Son variables locales porque sólo son visibles en el shell donde se han definido.

* **Borra la variable VAR**

```
unset VAR2
```

* **Abre otra ventana de tipo terminal, ¿puedes visualizar las dos variables restantes?**

No, porque para que puedan ser visibles en otras terminales debemos exportar su valor al sistema con la orden export.

* **Crea una variable de tipo vector con los valores iniciales de las tres variables.**

```
vector=($VAR1 $VAR2 $VAR3)
```

* **Muestra el segundo elemento del vector creado en el apartado anterior.**
```
echo ${vector[1]}
```


***
## Ejercicio 2
### Crea un alias que se llame ne (número de elementos) que devuelva el número de archivos que existen en el directorio actual. ¿Qué cambiaría si queremos que haga lo mismo pero en el directorio home del usuario que lo ejecuta?

Para que haga devuelva el número de archivos del directorio home del usuario, añadimos la variable `$HOME` a la orden anterior.
```
alias ne='find $HOME -print | wc -l'
```


***
## Ejercicio 3
### Indica la línea de orden necesaria para buscar todos los archivos a partir de tu directorio home que tengan un tamaño menor de un bloque. ¿Cómo lo modificarías para que además se imprima el resultado en un archivo que se cree en el directorio actual llamado archivosP?
```
find $HOME -size -1
```
Para que además imprima el resultado en archivo usaremos el redireccionamiento de salida.
```
find $HOME -size -1 > archivosP
```


***
## Ejercicio 4
### Indica cómo buscarías todos aquellos archivos de tu directorio actual que contengan la palabra **“ejemplo”**.
```
find . -name "*ejemplo*"
```


***
## Ejercicio 5
### Completa la información de find y grep utilizando para ello la orden man.

**Opciones de `find`:**
* **-amin n**: Archivos a los que se accedió hace n minutos.
* **-anewer archivo**: Archivos a los que se accedió más recientemente que la última modificación de archivo.
* **-cmin n**: Archivos cuyo estado hayan sido modificado hace n minutos.
* **-cnewer archivo**: Archivos cuyo estado hayan sido modificado más recientemente que la última modificación de archivo.
* **-mmin n**: Archivos que fueron modificados hace n minutos.
* **-newer archivo**: Archivos que fueron modificados más recientemente que la última modificación de archivo.
* **-empty**: Archivos o directorios vacíos.
* **-executables**: Archivos ejecutables y directorios navegables.
* **-readable**: Archivos que se pueden leer.
* **-fstype tipo**: Archivos en sistemas de archivos tipo (ejemplo vfat).
* **-uid n**: Archivos cuyo identificador de usuario es n.
* **-gid n**: Archivos cuyo identificador de grupo es n.
* **-group grupo**: Archivos pertenecientes a grupo.
* **-nogroup**: Archivos que no pertenezcan a ningún grupo.
* **-nouser**: Archivos que no pertenezcan a ningún usuario.
* **-delete**: Eliminar archivos.

**Opciones de `grep`:**
* **-e PATRON**: nos permite especificar varios patrones de búsqueda o poder usar otros signo -.
* **-r**: busca recursivamente dentro de todos los subdirectorios del directorio actual.
* **-E**: nos permite usar expresiones regulares. Equivalente a usar egrep.
* **-o**: le indica a grep que nos muestre sólo la parte de la línea que coincide con el patrón.
* **-H**: nos muestra el nombre del archivo con cada coincidencia.
