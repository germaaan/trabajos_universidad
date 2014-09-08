Fundamentos de Ingeniería del Software
======================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Práctica 2: Ingeniería de requisitos. Modelos de casos de uso
### Jesús Gómez Obregón
### Germán Martínez Maldonado 
### Ramón Rueda Delgado
### José Rubén Sánchez Iruela
### Pablo Sánchez Robles

### Actividades a realizar

A partir de la descripción inicial del sistema realizada en la práctica anterior, en esta práctica se deben realizar las siguientes actividades:

1. Elaboración de los diagramas de casos de uso, previa identificación de los actores y de los casos de uso a incluir en ellos.
2. Agrupación de los casos de uso en paquetes.
3. Descripción de todos los casos de uso a nivel general, usando la plantilla básica.
4. Descripción de los casos de uso usando la plantilla extendida.
5. Realización de algunos diagramas de actividades, para los casos de uso más complejos.
6. Extensión del glosario de términos.
8. Realización de los diagramas de actividades, para todos los casos de uso del paquete Gestión de resultados y clasificaciones.


### Revisión histórica

| Fecha      | Versión | Descripción                                                        | Autor                              |
|------------|---------|--------------------------------------------------------------------|------------------------------------|
| 20-03-2012 | 1.0     | Versión inicial del informe de casos de uso                        | Jesús, Germán, Ramón, Rubén, Pablo |
| 27-03-2012 | 2.0     | Revisión                                                           | Jesús, Germán, Ramón, Rubén, Pablo |


### 1. Introducción

El objetivo de este documento es mostrar el modelo de Casos de Uso obtenidos mediante un proceso de análisis del sistema para la gestión de una liga de baloncesto ACB. El modelo se divide en cinco paquetes que agrupan las cinco funcionalidades básicas del sistema.


### 2. Jerarquía de casos de uso

**1. Gestión de sistema**

Descripción: Escenarios asociados con acciones sobre el sistema.

Casos de Uso: Alta de administrador, Baja de administrador

Actores: Administrador

**2. Gestión de Jugadores**

Descripción: Escenarios asociados con acciones sobre los jugadores.

Casos de Uso: Alta de jugador, Baja de jugador

Actores: Administrador

**3. Gestión de Equipos**

Descripción: Escenarios asociados con acciones sobre los equipos.

Casos de Uso: Alta de equipo, Baja de equipo

Actores: Administrador

**4. Gestión de Partidos**

Descripción: Escenarios asociados con acciones sobre los partidos.

Casos de Uso: Alta de partido, Baja de partido, Consultar estadísticas de partido, Calcular MVP partido

Actores: Administrador, Consultor, Temporizador

**5. Gestión de Jornadas**

Descripción: Escenarios asociados con acciones sobre las jornadas.

Casos de Uso: Alta de jornada, Baja de jornada, Consultar información de jornada, Calcular MVP jornada

Actores: Administrador, Consultor, Temporizador

**6. Gestión de Ligas**

Descripción: Escenarios asociados con acciones sobre las ligas.

Casos de Uso: Consultar histórico, Consultar estadísticas liga, Calcular MVP liga

Actores: Consultor, Temporizador


### 3. Diagramas del modelo de casos de uso

#### Diagrama de paquetes

![pra02_img01](imagenes/pra02_img01.png)

#### Diagrama de casos de uso: gestión de sistema

![pra02_img02](imagenes/pra02_img02.png)

#### Diagrama de casos de uso: gestión de jugadores

![pra02_img03](imagenes/pra02_img03.png)

#### Diagrama de casos de uso: gestión de equipos

![pra02_img04](imagenes/pra02_img04.png)

#### Diagramas de casos de uso: gestión de partidos

![pra02_img05](imagenes/pra02_img05.png)

#### Diagramas de casos de uso: gestión de jornadas

![pra02_img06](imagenes/pra02_img06.png)

#### Diagrama de casos de uso: gestión de ligas

![pra02_img07](imagenes/pra02_img07.png)


### 4. Descripción básica de actores y casos de uso de alto nivel

![pra02_img08](imagenes/pra02_img08.png)

![pra02_img09](imagenes/pra02_img09.png)

![pra02_img10](imagenes/pra02_img10.png)

![pra02_img13](imagenes/pra02_img13.png)

![pra02_img14](imagenes/pra02_img14.png)

![pra02_img15](imagenes/pra02_img15.png)

![pra02_img16](imagenes/pra02_img16.png)

![pra02_img17](imagenes/pra02_img17.png)

![pra02_img18](imagenes/pra02_img18.png)

![pra02_img19](imagenes/pra02_img19.png)

![pra02_img20](imagenes/pra02_img20.png)

![pra02_img21](imagenes/pra02_img21.png)

![pra02_img22](imagenes/pra02_img22.png)

![pra02_img23](imagenes/pra02_img23.png)

![pra02_img24](imagenes/pra02_img24.png)

![pra02_img25](imagenes/pra02_img25.png)

![pra02_img26](imagenes/pra02_img26.png)

![pra02_img27](imagenes/pra02_img27.png)

![pra02_img28](imagenes/pra02_img28.png)

![pra02_img29](imagenes/pra02_img29.png)


### 5. Casos de uso extendido

![pra02_img30](imagenes/pra02_img30.png)

![pra02_img31](imagenes/pra02_img31.png)

![pra02_img32](imagenes/pra02_img32.png)

![pra02_img33](imagenes/pra02_img33.png)

![pra02_img34](imagenes/pra02_img34.png)

![pra02_img35](imagenes/pra02_img35.png)

![pra02_img36](imagenes/pra02_img36.png)


### 6. Diagramas de actividad de los casos de uso del paquete Gestión de resultados y clasificaciones

#### Diagramas de casos de uso propuestos 

![pra02_img37](imagenes/pra02_img37.png)

![pra02_img38](imagenes/pra02_img38.png)

![pra02_img39](imagenes/pra02_img39.png)

![pra02_img40](imagenes/pra02_img40.png)

#### Introducir datos jornada

![pra02_img41](imagenes/pra02_img41.png)

#### Calcular MVP jornada

![pra02_img42](imagenes/pra02_img42.png)

#### Calcular clasificación de clubes

![pra02_img43](imagenes/pra02_img43.png)

#### Calcular clasificación jugadores

![pra02_img44](imagenes/pra02_img44.png)

#### Calcular MVP temporada

![pra02_img45](imagenes/pra02_img45.png)

#### Consultar resultados jornada

![pra02_img46](imagenes/pra02_img46.png)

#### Consultar datos partido

![pra02_img47](imagenes/pra02_img47.png)

#### Consultar datos jugador

![pra02_img48](imagenes/pra02_img48.png)

#### Consultar clasificación clubes

![pra02_img49](imagenes/pra02_img49.png)

#### Consultar clasificación jugadores

![pra02_img50](imagenes/pra02_img50.png)


### 7. Glosario extendido de términos

* **Administrador**: es el encargado manipular nuestro sistema de gestión de ACB.

* **Anotador**: será el elemento encargado de proporcionarnos los datos sobre toda la información que vamos a manejar en nuestro sistema.

* **Calendario de jornadas**: guía de todos los enfrentamientos programados durante toda la liga.

* **Clasificación**: relación posición-elemento según un orden establecido en función de los puntos, refleja el resultado de la competición.

* **Clubes**: se refiere al conjunto de miembros que forma un equipo de baloncesto, desde el equipo directivo, técnico y jugadores.

* **Estadísticas de liga**: está formado por los datos más característicos de la temporada: puntos anotados, rebotes, asistencias, etc.; con el objetivo de gestionar todos los aspectos numéricos de todos los elementos que componen y participan en la liga.

* **Fichajes**: es el traspaso de un jugador de un equipo a otro a cambio de una compensación económica.

* **Histórico**: archivo que está compuesto por toda la información que se generó en su momento sobre pasadas temporadas, se almacena en el sistema para labores de documentación.

* **Inscribir**: una vez fichado a un jugador, este debe ser apuntado como integrante del equipo para poder disputar los partidos con el mismo.

* **Jornada**: es el periodo de tiempo en el que se disputan los partidos de una serie previamente programada y repartida a lo largo de una temporada.

* **Jugadores**: son cada uno de los componentes de los equipos que se enfrentan en la competición.

* **Liga regular**: es la competición anual en el que se enfrentan todos los equipos entre sí para disputarse el título de campeón de liga.

* **Loguearse**: consiste en identificarse con un nombre de usuario y contraseña en el sistema.

* **MVP**: En el ámbito deportivo, un premio MVP (Most Valuable Player o Jugador Más Valioso) es la distinción que se le da al jugador que ha tenido un mayor rendimiento en un periodo concreto.

* **Plantilla**: es el conjunto de jugadores que forman el equipo de baloncesto.

* **Temporizador**: mecanismo que  nos permitirá calcular las estadísticas de  todos los jugadores de la liga en el mismo momento que esta se dé por finalizada.

* **Temporada**: periodo de tiempo que abarca la competición de una liga.

* **Usuario**: persona que utilizará nuestro sistema para realizar distintas consultas sobre la información almacenada en nuestro sistema sobre la liga.
