# Sesión 1: Introducción a un entorno gráfico de Unix


## Ejercicio 3
### Edita los siguientes ficheros de texto con los editores vistos en clase:
```
/etc/passwd
/etc/group
```
### Comenta brevemente para qué sirven ambos ficheros del sistema.

El archivo `/etc/passwd` almacena información sobre los usuarios que existen en el sistema. Por ejemplo:
```
germaaan:x:1000:1000:germaaan,,,:/home/germaaan:/bin/bash
```
* El primer campo representa el nombre de usuario.
* El segundo campo representa la contraseña del usuario encriptada en el sistema.
* El tercer campo representa el número de identificación en el sistema del usuario.
* El cuarto campo representa el número de identificación en el sistema del grupo al que pertenece el usuario.
* El quinto campo representa información personal del usuario separada por comas, contiene datos
* como el nombre completo del usuario.
* El sexto campo representa el directorio de trabajo del usuario.
* El séptimo y último campo, representa el shell que utiliza el usuario.

El archivo `/etc/group/` almacena información sobre los grupos de usuarios que existen en el sistema. Por ejemplo:
```
root:x:0:
```
* El primer campo representa el nombre del grupo
* El segundo campo representa el campo especial
* El tercero campo representa el número de identificación del grupo
* El cuarto campo representa los usuarios que pertenecen a dicho grupo separados por comas.

***
## Ejercicio 4
### Modifica los ficheros anteriores para que aparezca la siguiente información:
```
root:x:0:0:root:/root:/bin/csh
nobody:x:99:“tu usuario aquí”
```
### Reemplazando "tu usuario aquí” por el nombre de tu usuario. Explica que modificaciones habrías hecho al sistema de haberlos guardado en sus respectivos lugares.
```
root:x:0:0:root:/root:/bin/csh
```
Con esta modificación en el archivo /etc/passwd hemos cambiado el shell del usuario a csh.
```
nobody:x:99:germaaan
```
Con esta modificación en el archivo /etc/passwd hemos creado un grupo llamado nobody con el número de identificación 99 y añadido nuestro usuario a dicho grupo.
