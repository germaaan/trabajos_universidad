Sistemas Concurrentes y Distribuidos
=========================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 1: Sincronización de hebras con semáforos
### Germán Martínez Maldonado

### 1 Objetivos

En esta práctica se realizarán dos implementaciones de dos problemas sencillos de sincronización usando librerías abiertas para programación multihebra y semáforos. Los objetivos son:

* Conocer el problema del productor-consumidor y sus aplicaciones.
 * Diseñar una solución al problema basada en semáforos.
 * Implementar esa solución en un programa C/C++ multihebra, usando la funcionalidad de la librería POSIX para:
  * la creación y destrucción de hebras
  * la sincronización de hebras usando semáforos

* Conocer un problema sencillo de sincronización de hebras (el problema de los fumadores)
 * Diseñar una solución basada en semáforos, teniendo en cuenta los problemas que pueden aparecer.
 * Implementar la solución a dicho problema en C/C++ usando hebras y semáforos POSIX.


### 2 El problema del productor-consumidor

#### 2.1 Descripción del problema.

**Problema y aplicaciones**

El problema del productor consumidor surge cuando se quiere diseñar un programa en el cual un proceso o hebra produce items de datos en memoria que otro proceso o hebra consume.

* Un ejemplo sería una aplicación de reproducción de vídeo:
 * El productor se encarga de leer de disco o la red y descodificar cada cuadro de vídeo.
 * El consumidor lee los cuadros descodificados y los envía a la memoria de vídeo para que se muestren en pantalla

Hay muchos ejemplos de situaciones parecidas.

* En general, el productor calcula o produce una secuencia de items de datos (uno a uno), y el consumidor lee o consume dichos items (tambien uno a uno).
* El tiempo que se tarda en producir un item de datos puede ser variable y en general distinto al que se tarda en consumirlo (también variable).

**Solución de dos hebras con un vector de items**

Para diseñar un programa que solucione este problema:

* Suele ser conveniente implementar el productor y el consumidor como dos hebras independientes, ya que esto permite tener ocupadas las CPUs disponibles el máximo de tiempo.
* Se puede usar una variable compartida que contiene un ítem de datos.
* Las esperas asociadas a la lectura y la escritura pueden empeorar la eficiencia. Esto puede mejorarse usando un vector que pueda contener muchos items de datos producidos y pendientes de leer.

**Condición de sincronización**
En esta situación, la implementación debe asegurar que:

* Cada ítem producido es leído (ningún ítem se pierde)
* Ningún ítem se lee más de una vez. 

Lo cual implica:

* El productor tendrá que esperar antes de poder escribir en el vector cuando haya creado un ítem pero el vector esté completamente ocupado por ítems pendientes de leer.

* El consumidor debe esperar cuando vaya a leer un ítem del vector pero dicho vector no contenga ningún ítem pendiente de leer.

* En algunas aplicaciones el orden de lectura debe coincidir con el de escritura, en otras podría ser irrelevante.

#### 2.3 Actividades

**Lista de actividades**

Debes realizar las siguientes actividades en el orden indicado:

*1. Diseña una solución que permita conocer qué entradas del vector están ocupadas y qué entradas están libres.*

Para almacenar los valores que se irán produciendo y consumiendo, usaremos un tipo struct que llamaremos “Buffer”, esta se compondrá de un vector de enteros que será el Buffer en sí mismo y, un entero que nos indicará el uso actual del buffer, para conocer en todo momento la ocupación del mismo y donde se deberán insertar los datos.

*2. Diseña una solución, mediante semáforos, que permita realizar las esperas necesarias para cumplir los requisitos descritos.*

Declararemos 3 semáforos  (sem_t) con  los nombres “puede_producir” (que gestionara cuando se pueden escribir nuevos valores en el buffer), “puedo_consumir” (que gestionara cuando se pueden leer los valores existentes en el buffer) y “mutex” (que gestionara el acceso en exclusión mutua a la sección critica para los procesos productor y consumidor).

El semáforo “puede_consumir” se inicializará a 0, porque al estar el buffer vacío de inicio, no habrá datos que consumir. El semáforo “puede_producir” se inicializará con valor 10, ya que como nuestro buffer es de tamaño 10, podríamos insertar 10 valores seguidos sin que se tuvieran que consumir antes. El semáforo “mutex” se inicializara a 1, para que uno de los procesos puede acceder a la sección critica.

Solo los métodos productor y consumidor modificaran los valores de los semáforos “puede _producir” y “puede_consumir”  mediante “sem_wait” y “sem_signal”, mientras que el semáforo “mutex”, será modificado por los dos. En el semáforo “puede_producir” se hará “sem_wait” desde el método productor para controlar que el buffer no se desborde cuando esté lleno, y se hará “sem_post” siempre que se consuma un valor en el método consumidor, porque dada esa situación, es seguro que mínimo habrá un hueco libre en el buffer que se podrá llenar con un nuevo valor. De forma análoga, en el semáforo “puede_consumir” se hará “sem_wait” desde el método consumidor para controlar que no se intente sacar un valor del buffer cuando este se encuentre vacío, y como en el caso anterior, ahora se hará “sem_signal” desde el método productor siempre que se produzca un nuevo valor, porque eso significara que existirá un nuevo dato a consumir. En cuanto al semáforo “mutex” como su función es gestionar la exclusión mutua, se hará sobre él “sem_wait” (antes de) y “sem_signal” (después de), siempre que vayamos a trabajar con el buffer contenedor de los valores, tanto en el método productor como en el consumidor, para asegurarnos que los accesos al mismo se hacen en exclusión mutua.

*3. Implementa la solución descrita en un programa C/C++ con hebras y semáforos POSIX, completando las plantillas incluidas en este guión. Ten en cuenta que el programa debe escribir la palabra ’fin’ cuando hayan terminado las dos hebras.*

Una vez diseñado el objeto de la sección critica para almacenar los valores en un buffer, y definidos los semáforos que usaremos para gestionar el funcionamiento del programa, debemos declarar las hebras. Crearemos dos hebras “hebra_productora” y “hebra_consumidora” que serán las encargadas de soportar los correspondientes procesos “productor” y “consumidor”, las crearemos, las sincronizaremos y, una vez finalizada su función, las destruiremos.

Como queremos que el programa gestione un numero determinada de elementos, tanto el método “productor” como el “consumidor” se compondrán simplemente de un bucle for, que para cada elemento decidirá si se produce/consume (lo correspondiente según el método) un dato del buffer de forma controlada por los semáforos específicos de cada método y a su vez por el semáforo de la exclusión mutua.

Los datos serán producidos por un método que incrementara secuencialmente una variable global usada como contador, mostrando antes de devolverlo el valor generado. Cuando se consumen los datos, se llamara a un método que mostrar el valor que se consumirá.

*4. Comprueba que tu programa es correcto: verifica que cada número natural producido es consumido exactamente una vez.*

Comprobamos el correcto funcionamiento del programa viendo la salida del programa:

```
germaaan@PC-G:~/Universidad/2º/SCD/practica1$      ./productor_consumidor Dato producido: 1
Dato consumido: 1
Dato producido: 2
Dato producido: 3
Dato consumido: 3
Dato consumido: 2
Dato producido: 4
Dato consumido: 4
Dato producido: 5
Dato producido: 6
Dato consumido: 5
Dato producido: 7
Dato consumido: 7
Dato consumido: 6
Dato producido: 8
Dato producido: 9
Dato consumido: 9
Dato producido: 10
Dato producido: 11
Dato consumido: 11
Dato producido: 12
Dato producido: 13
Dato consumido: 13
Dato producido: 14
Dato producido: 15
Dato consumido: 15
Dato producido: 16
Dato consumido: 16
Dato producido: 17
Dato producido: 18
Dato consumido: 18
Dato consumido: 17
Dato consumido: 14
Dato producido: 19
Dato consumido: 19
Dato producido: 20
Dato producido: 21
Dato consumido: 21
Dato consumido: 20
Dato consumido: 12
Dato producido: 22
Dato consumido: 22
Dato consumido: 10
Dato consumido: 8
Dato producido: 23
Dato producido: 24
Dato consumido: 24
Dato consumido: 23
Dato producido: 25
Dato producido: 26
Dato consumido: 26
Dato producido: 27
Dato producido: 28
Dato consumido: 28
Dato producido: 29
Dato producido: 30
Dato producido: 31
Dato producido: 32
Dato consumido: 32
Dato consumido: 31
Dato producido: 33
Dato producido: 34
Dato producido: 35
Dato producido: 36
Dato producido: 37
Dato consumido: 37
Dato consumido: 36
Dato consumido: 35
Dato producido: 38
Dato consumido: 38
Dato consumido: 34
Dato consumido: 33
Dato consumido: 30
Dato consumido: 29
Dato producido: 39
Dato consumido: 39
Dato producido: 40
Dato consumido: 40
Dato producido: 41
Dato producido: 42
Dato producido: 43
Dato producido: 44
Dato producido: 45
Dato producido: 46
Dato consumido: 46
Dato consumido: 45
Dato producido: 47
Dato consumido: 47
Dato consumido: 44
Dato producido: 48
Dato producido: 49
Dato producido: 50
Dato consumido: 50
Dato consumido: 49
Dato consumido: 48
Dato consumido: 43
Dato consumido: 42
Dato consumido: 41
Dato consumido: 27
Dato consumido: 25

Fin
```

* *Orden de aparición de los números:*

Aunque los números son generados secuencialmente, no serán mostrados en el mismo orden, esto se debe a que como se está insertando y sacando en el mismo buffer, el valor que indica la posición accesible es la misma, por lo tanto si se insertan dos valores de forma consecutiva, sin que ninguno sea sacado entre medias, hasta que no se saque el valor más nuevo, no se podrá sacar el insertado en el momento anterior, por eso se produce un listado como el que se muestra en la salida del programa.


###3 El problema de los fumadores.

#### 3.1 Descripción del problema.

**Descripción del problema (1)**

En este apartado se intenta resolver un problema algo más complejo usando hebras y semáforos POSIX. 

Considerar un estanco en el que hay tres fumadores y un estanquero.

1.1. Cada fumador representa una hebra que realiza una actividad (fumar), invocando a una función fumar(), en un bucle infinito.

1.2. Cada fumador debe esperar antes de fumar a que se den ciertas condiciones (tener suministros para fumar), que dependen de la actividad del proceso que representa al estanquero.

1.3. El estanquero produce suministros para que los fumadores puedan fumar, también en un bucle infinito.

1.4. Para asegurar concurrencia real, es importante tener en cuenta que la solución diseñada debe permitir que varios fumadores fumen simultáneamente.

**Descripción del problema (2)**

A continuación se describen los requisitos para que los fumadores puedan fumar y el funcionamiento del proceso estanquero:

2.1. Antes de fumar es necesario liar un cigarro, para ello el fumador necesita tres ingredientes: tabaco, papel y cerillas.

2.2. Uno de los fumadores tiene solamente papel, otro tiene solamente tabaco, y el otro tiene solamente cerillas.

2.3. El estanquero coloca aleatoriamente dos ingredientes diferentes de los tres que se necesitan para hacer un cigarro, desbloquea al fumador que tiene el tercer ingrediente y después se bloquea.

2.4. El fumador desbloqueado toma los dos ingredientes del mostrador, desbloquea al estanquero para que pueda seguir sirviendo ingredientes y fuma durante un tiempo después de liarse el cigarro.

2.5. El estanquero, cuando se desbloquea, vuelve a poner dos ingredientes aleatorios en el mostrador, y se repite el ciclo.

#### 3.2 Actividades

**Diseño de la solución**

*Diseña e implementa una solución al problema en C/C++ usando cuatro hebras y los semáforos necesarios. La solución debe cumplir los requisitos incluidos en la descripción, y además debe:*

* *Evitar interbloqueos entre las distintas hebras.*
* *Producir mensajes en la salida estándar que permitan hacer un seguimiento de la actividad de las hebras:*
 * *El estanquero debe indicar cuándo produce suministros y qué suministros produce. Para es- tablecer los ingredientes concretos (o directamente el fumador que podría usarlos), se debe usar también la función rand().*
 * *Cada fumador debe indicar cuándo espera, qué producto o productos espera, y cuándo comienza y finaliza de fumar.*

Para el problema de los fumadores usaremos un semáforo individual (sem_estanquero) y un vector de 3 semáforos (sem_fumadores[3]), el semáforo individual se corresponderá con el único estanquero que será el que reparta los ingredientes irán cogiendo según sean los que necesiten, y en el vector de semáforos, cada uno de sus semáforos, se corresponderán con cada uno de los fumadores que esperan a que el estanquero ponga los ingredientes que le faltan para irse a fumar.

Todos los semáforos se inicializaran a 0, para que los 3 fumadores se tengan que esperar a que el estanquero les de la señal que le indique que tiene los ingredientes necesarios para que puedan irse a fumar.

Cada hebra de un fumador solo podrá hacer “sem_wait” sobre su correspondiente semáforo del vector de fumadores, al semáforo que le corresponda como fumador, ya que ningún fumador puede decidir que otro que no puede fumar, esto solo lo puede decidir el estanquero. Lo que sí tendrán en común todas las hebras de fumadores, es que todas podrán hacer “sem_post” sobre el semáforo del estanquero para indicarle que ya puede repartir nuevos ingredientes, ya que el fumador correspondiente habrá cogido los suyos, cuando se hayan encontrado disponibles, y se habrá ido a fumar.

La hebra del estanquero por su parte, hará “sem_post” sobre el semáforo correspondiente al fumador del que se han puesto los ingredientes en la mesa, para indicarle que puede cogerlos e irse a fumar, y también hará “sem_wait” sobre su propio semáforo, para esperar a que el fumador recoja los ingredientes antes de poner otros nuevos.

* *Salida del programa*

```
germaaan@PC-G:~/Universidad/2º/SCD/practica1$ ./fumador 
El estanquero pone tabaco y papel en el mostrador.
El segundo fumador coge el tabaco y el papel y se va a fumar.

El estanquero pone papel y cerillas en el mostrador.
El primer fumador coge el papel y las cerillas y se va a fumar.

El estanquero pone cerillas y tabaco en el mostrador.
El tercer fumador coge las cerillas y el tabaco y se va a fumar.

El estanquero pone tabaco y papel en el mostrador.
El segundo fumador coge el tabaco y el papel y se va a fumar.

El estanquero pone papel y cerillas en el mostrador.
El primer fumador coge el papel y las cerillas y se va a fumar.

El estanquero pone cerillas y tabaco en el mostrador.
El tercer fumador coge las cerillas y el tabaco y se va a fumar.

El estanquero pone papel y cerillas en el mostrador.
El primer fumador coge el papel y las cerillas y se va a fumar.

El estanquero pone papel y cerillas en el mostrador.
El primer fumador coge el papel y las cerillas y se va a fumar.

El estanquero pone tabaco y papel en el mostrador.
El segundo fumador coge el tabaco y el papel y se va a fumar.

El estanquero pone tabaco y papel en el mostrador.
El segundo fumador coge el tabaco y el papel y se va a fumar.

El estanquero pone tabaco y papel en el mostrador.
El segundo fumador coge el tabaco y el papel y se va a fumar.
```
