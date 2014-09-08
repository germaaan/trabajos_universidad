Fundamentos de Ingeniería del Software
======================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Práctica 1: Ingeniería de requisitos. Lista estructurada de requisitos
### Jesús Gómez Obregón
### Germán Martínez Maldonado 
### Ramón Rueda Delgado
### José Rubén Sánchez Iruela
### Pablo Sánchez Robles

### Descripción del problema a abordar

En esta primera práctica se describirá el supuesto práctico o problema a abordar no solo en esta práctica, sino también durante el resto de prácticas de la asignatura. Se trata de un sistema de gestión de la Liga Regular de Baloncesto (ACB), que informatice toda la gestión de información sobre jugadores y clubes, la programación de partidos en las distintas jornadas de una temporada, la generación de la clasificación de equipos y de jugadores en función de los resultados de cada partido, y las consultas de dichos resultados.

A continuación se da una breve descripción inicial del problema:

* En una temporada se definen una serie de jornadas, de modo que en cada una de ellas se jugarán determinados partidos, en los que se enfrentan dos clubes distintos, uno como visitante y otro como local.
* Los clubes están formados por jugadores, teniendo cada jugador unas determinadas características, que determinan la posición en la que puede jugar.
* En un partido pueden intervenir tantos jugadores de un equipo como el entrenador considere oportuno, pero en un determinado momento sólo habrá cinco jugadores de cada equipo en pista, cada uno de ellos ocupando una posición concreta.
* En cada partido jugado se contabilizan tanto el número de puntos anotados, como los rebotes, asistencias, tapones y faltas cometidas y recibidas por cada jugador que ha disputado el partido, así como por cada equipo contendiente en su conjunto.
* Los resultados globales de cada equipo en un partido sirven para establecer la clasificación general del club en el apartado correspondiente.
* Los resultados obtenidos por cada jugador influyen en la clasificación de jugadores, de modo que cada jornada se elige al jugador más valioso o MVP (Most Valuable Player) de todos los partidos jugados en esa jornada, y al final del campeonato se elige al MVP de esa temporada.
* Cualquier usuario de la aplicación a desarrollar podrá hacer consultas sobre la clasificación de jugadores y clubes, mientras que el resto de operaciones del sistema deberán ser realizadas por los administradores del mismo.

Se necesita desarrollar una aplicación que permita llevar a cabo toda la funcionalidad requerida para realizar la programación de los partidos en las distintas jornadas, actualizar la información cada vez que se juegue un partido, consultar los resultados sobre los jugadores y los clubes.


### Actividades a realizar

Partiendo de la descripción inicial del problema a abordar que se acaba de dar, en esta primera práctica se deben realizar las siguientes actividades:

1. Estudio del dominio del problema y descripción general del sistema.
2. Obtención de una lista estructurada de requisitos.
3. Glosario de términos.


### Objetivo

Este proyecto tiene como principal objetivo desarrollar un sistema informático, que gestione la liga regular de baloncesto (ACB), que informatice toda la administración de la liga regular de baloncesto ACB. La aplicación llevara estadística de los clubes, jugadores, la programación de los distintos partidos de la temporada, la clasificación de los equipos, así como el reconocimiento del MVP. Al final de la liga nos mostrara las estadísticas más destacadas del campeonato.


### Descripción de los implicados

Entornos de usuarios. Nuestra aplicación constara de dos tipos de usuarios:
* Usuario administrador, el cual se encargaría de la introducción, manejo y actualización de datos en el sistema así como la creación de nuevos usuarios administradores. Este es el único usuario que debe loguearse en el sistema.
* Usuario final, es el que visualizara la información actual en el sistema. Este tipo de usuario no podrá modificar ni añadir datos nuevos, solo consultarlos, al igual que no necesitara loguearse en el sistema


### Descripción general del sistema

* Una temporada tendrá un máximo de 34 jornadas, 18 equipos y 9 partidos por jornada, en la que se enfrentan dos clubes distintos, uno como visitante y otro como local.
* Los clubes están formados por un máximo de 15 jugadores, de los cuales se convocan a un máximo de 12 jugadores por partido y un mínimo de 8. Cada equipo durante la temporada podrá hacer fichajes de nuevos jugadores y desprenderse de otros jugadores que estén en plantilla. Los clubes pueden ascender y descender según su posición en la tabla.
* En un partido pueden intervenir 12 jugadores elegidos previamente por el entrenador, pero en un determinado momento solo habrá cinco jugadores de cada equipo en pista, cada uno de ellos ocupando una posición concreta.
* En cada partido jugado se contabilizan tanto el número de puntos anotados (+1), como los rebotes (+1), asistencias (+1), canastas falladas (-1), balón recuperado(+1), balón perdido (-1), tapón realizado (+1), tapón recibido (-1), faltas recibidas (+1) y faltas realizadas (-1) por cada jugador que ha disputado el partido, así como por cada equipo contendiente en su conjunto.
* Los resultados globales de cada equipo en un partido sirven para establecer la clasificación general del club en el apartado correspondiente y pudiendo hacer estadística de cada equipo según puntos anotados, como los rebotes, asistencias, tapones, canastas falladas, balones recuperados, balones perdidos, tapón realizado, tapón recibido, faltas recibidas y faltas realizada.
* Los resultados obtenidos por cada jugador influyen en la clasificación de jugadores, de modo que cada jornada se elige al jugador mas valioso o MVP de todos los
partidos jugados en esa jornada, utilizando los valores citados en el punto anterior  y al final del campeonato se elige al MVP de esa temporada.
* Tendremos 2 tipos de usuarios, los cuales serán el usuario final y un usuario en cargado de introducir los datos correspondientes a cada jornada.


### Obtención de una lista estructurada de requisitos

#### Requisitos funcionales

* **RF-1 Gestión de jugadores**

 * RF-1.1 Se llevara un control de las estadísticas de cada jugador. 
 * RF-1.2 Selección del MVP.

* **RF-2 Gestión de clubes**

 * RF-2.1 Se tendrá una capacidad de gestión de estadísticas de clubes. 
 * RF-2.2 Capacidad de gestión fichajes.

* **RF-3 Gestión de liga**

 * RF-3.1 Capacidad de gestión de estadísticas de jornada. 
 * RF-3.2 Capacidad de gestión de estadísticas de liga.
 * RF-3.3 Gestión de ascenso y descenso de clubes.

#### Requisitos no funcionales

* **RN-1 Fiabilidad**

 * RN-1.1 Gestión de errores.

* **RN-2 Seguridad**

 * RN-2.1 Copias de seguridad.
 * RN-2.2 Capacidad de gestión de servicios a nivel de usuario y administrador. 
 * RN-2.3 Ley de protección de datos.

* **RN-3 Usabilidad**

 * RN-3.1 Organización de las estadísticas en tablas. 
 * RN-3.2 Diseño de interfaz grafica.
 * RN-3.3 Flexibilidad en los requerimientos técnicos de instalación.

* **RN-4 Soporte**

 * RN-4.1 Multiplataforma.

#### Requisitos de información

* **RI-1 Jugador**

La información de cada jugador será : puntos anotados, rebotes, asistencias, canastas falladas, balones recuperados, balones perdidos, tapones realizados, tapones recibidos, faltas recibidas, faltas realizadas, puntos anotados, puntos fallados, nombre jugador, posición natural, altura, procedencia, nacionalidad, fecha nacimiento y licencia

* **RI-2 Clubes**

Jugadores, puntos, partidos jugados, partidos ganados, partidos perdidos, puntos a favor, puntos en contra, año de fundación, dirección, teléfono, email, pabellón, horario de juego, uniforme titular, uniforme reserva y web.

* **RI-3 Partidos**

Equipo local, equipo visitante, puntos local, rebotes local, asistencia local, faltas local, puntos visitante, rebotes visitante, asistencia visitante, faltas visitante.

 * RI-3.1 Jornadas. Colección de partidos. 
 * RI-3.2 Liga ACB.


### Glosario de términos

* **Clubes**: se refiere al conjunto de miembros que forma un equipo de baloncesto, desde el equipo directivo, entrenador y jugadores.

* **Estadísticas de liga**: está formado por los datos mas característicos de la temporada, puntos anotados, rebotes, asistencias, etc, con el objetivo de reconocer a los mejores equipos y jugadores de la temporada.

* **Fichajes**: un fichaje es el traspaso de un jugador de un equipo a otro a cambio de una remuneración económica.

* **Jornada**: es un concepto vinculado a un determinado período temporal. El término puede utilizarse para hacer referencia a un día.

* **Liga regular**: es el período que transcurre durante un año en el que se enfrentan todos los equipos entre sí.

* **Loguearse**: consiste en identificarse con un nombre de usuario y contraseña en el sistema.

* **MVP**: En el ámbito deportivo, un premio MVP equivale al de Mejor jugador de la temporada.

* **Plantilla**: es el conjunto de jugadores que forman el equipo de baloncesto.

* **Temporada**: espacio temporal en el que transcurre un acontecimiento. En términos de la ACB, una temporada es un período de un año.
