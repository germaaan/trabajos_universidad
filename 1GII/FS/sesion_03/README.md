# Sesión 3: Permisos y redirecciones


## Modificación de los permisos de acceso a archivos
### Se debe utilizar solamente una vez la orden chmod en cada apartado. Los cambios se harán en un archivo concreto del directorio de trabajo (salvo que se indique otra cosa). Cambiaremos uno o varios permisos en cada apartado (independientemente de que el archivo ya tenga o no dichos permisos) y comprobaremos que funciona correctamente:

* Dar permiso de ejecución al “resto de usuarios”.
```
chmod o+x archivo
```
* Dar permiso de escritura y ejecución al “grupo”.
```
chmod g+wx archivo
```
* Quitar el permiso de lectura al “grupo” y al “resto de usuarios”.
```
chmod go-r archivo
```
* Dar permiso de ejecución al “propietario” y permiso de escritura el “resto de usuarios”.
```
chmod u+x,o+r archivo
```
* Dar permiso de ejecución al “grupo” de todos los archivos cuyo nombre comience con la letra “e”. Si no hay más de dos archivos que cumplan esa condición, se deberán crear a chivos que empiecen con “e” y/o modificar el nombre de archivos ya existentes para que cumplan esa condición.
```
chmod g+x e*
```


***
## Redirección de salida estándar
### Utilizando solamente las órdenes de la sesión anterior y los metacaracteres de redirección de salida:

* Crear un archivo llamado ej31, que contendrá el nombre de los archivos del directorio padre del directorio de trabajo.
```
ls ../ > ej31
```
* Crear un archivo llamado ej32, que contendrá las dos últimas líneas del archivo creado en el ejercicio anterior.
```
tail -2 ej31 > ej32
```
* Añadir al final del archivo ej32, el contenido del archivo ej31.
```
cat ej31 >> ej32
```


***
## Creación de cauces ( | )
### Utilizando el metacarácter de creación de cauces y sin utilizar la orden cd:

* Mostrar por pantalla, el listado (en formato largo) de los últimos 6 archivos del directorio padre al directorio de trabajo.
```
ls -l ../ | tail -6
```
* La orden wc muestra por pantalla el número de líneas, palabras y caracteres de un archivo (consulta la orden man para conocer más sobre ella). Utilizando dicha orden, mostrar por pantalla el número de caracteres (sólo ese número) de los archivos del directorio de trabajo que comiencen por los caracteres “e” o “f”.
```
wc -m [d,f]*
```


***
## Ejercicio 1
### Crear un archivo llamado ejercicio1, que contenga las 17 últimas líneas del texto que proporciona la orden man para la orden chmod (se debe hacer en una única línea de órd nes y sin utilizar el metacarácter “;”).
```
man chmod | tail -17 > ejercicio1
```


***
## Ejercicio 2
### Al final del archivo ejercicio1, añadir la ruta completa del directorio de trabajo actual.
```
pwd >> ejercicio1
```


***
## Ejercicio 3
### Usando la combinación de órdenes mediante paréntesis, crear un archivo llamado ejercicio3 que contendrá el listado de usuarios conectados al sistema (orden who) y la lista de archivos del directorio actual.
```
(who; ls) > ejercicio3
```


***
## Ejercicio 4
### Añadir, al final del archivo ejercicio3, el número de líneas, palabras y caracteres del archivo ejercicio1. Asegúrese de que, por ejemplo, si no existiera ejercicio1, los mensajes de error también se añadieran al final de ejercicio3.
```
wc ejercicio1 >> ejercicio3 2>&1
```


***
## Ejercicio 5
### Con una sola orden chmod, cambiar los permisos de los archivos ejercicio1 y ejercicio3, de forma que se quite el permiso de lectura al “grupo” y se dé permiso de ejecución a las tres categorías de usuarios.
```
chmod g-r,a+x ejercicio1 ejercicio3
```
