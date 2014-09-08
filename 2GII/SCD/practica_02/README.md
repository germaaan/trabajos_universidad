Sistemas Concurrentes y Distribuidos
=========================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 2: Sincronización de hebras con semáforos
### Germán Martínez Maldonado

### 1 Objetivos

* Conocer cómo construir monitores en Java, tanto usando la API para manejo de hebras Java, como usando un conjunto de clases (el paquete monitor) que permite programar monitores siguiendo la misma semántica de los monitores de Hoare.
* Conocer varios problemas sencillos de sincronización y su solución basada en monitores en el lenguaje Java:
 * Diseñar una solución al problema del productor-consumidor con buffer acotado basada en moni- tores e implementarla con un programa Java multihebra, usando el paquete monitor.
 * Diseñar una solución al problema de los fumadores, visto en la práctica 1, basada en monitores e implementarla con un programa Java multihebra, usando el paquete monitor.
 * Diseñar e implementar una solución al problema del barbero durmiente usando el paquete monitor.


### 4 Productor-Consumidor con buffer limitado

**Ejercicio propuesto**

*Obtener una versión de la clase Buffer, que se desarrolló en una sección anterior para múltiples productores y consumidores, usando las clases vistas del paquete monitor.*

La principal diferencia entre la nueva clase Buffer y la anterior, es que como ahora son los monitores los que se encargan de gestionar la sincronización y el acceso en exclusión mutua, ya no es necesario que todos los métodos de la clase tengan la etiqueta “synchronized”, como el monitor sólo permite ser ejecutado por un sólo proceso, esta propiedad está garantizada. Como consecuencia de esto, no se deberán manejar posibles excepciones de interrupción, ni llamadas al método “notifyAll” para indicar que el proceso ya ha termina de ejecutar, esto es ahora gestionado por el monitor, por lo tanto solo deberemos hacer las llamadas a los método del monitor “enter()” y “leave()” para indicar a que zona del código se debe acceder en exclusión mutua.

Para este programa he usado dos objetos condicion “puede_depositar” y “puede_extraer”, que al igual que los semáforos que tenían los mismos nombres en la versión con semáforos de la práctica anterior, se encarga de gestionar el acceso en exclusión mutua de los métodos encargados de depositar y extraer datos del buffer.

*Salida del programa*:

```
germaaan@PC-G:~/Universidad/2º/SCD/practica2/Ejercicios/ProductorConsumidor$       java ProductorConsumidor 2 2 3 5 5
Produciendo 101.0
Produciendo 102.0
Produciendo 103.0
Produciendo 104.0
Consumidor 2 consumiendo 101.0
Consumidor 1 consumiendo 201.0
Produciendo 201.0
Consumidor 1 consumiendo 105.0
Consumidor 1 consumiendo 202.0
Consumidor 2 consumiendo 104.0
Produciendo 105.0
Consumidor 2 consumiendo 102.0
Consumidor 1 consumiendo 103.0
Produciendo 202.0
Consumidor 2 consumiendo 203.0
Produciendo 203.0
Consumidor 1 consumiendo 204.0
Produciendo 204.0
Consumidor 2 consumiendo 205.0
Produciendo 205.0
```

### 5 El problema de los fumadores

**El problema de los fumadores**

Considerar un estanco en el que hay tres fumadores y un estanquero. Cada fumador continuamente lía un cigarro y se lo fuma. Para liar un cigarro, el fumador necesita tres ingredientes: tabaco, papel y cerillas. Uno de los fumadores tiene solamente papel, otro tiene solamente tabaco, y el otro tiene solamente cerillas. El estanquero tiene una cantidad infinita de los tres ingredientes.

El estanquero coloca aleatoriamente dos ingredientes diferentes de los tres que se necesitan para hacer un cigarro, desbloquea al fumador que tiene el tercer ingrediente y después se bloquea. El fumador desblo- queado toma los dos ingredientes del mostrador, desbloqueando al estanquero, lía un cigarro y fuma durante un tiempo. El estanquero, una vez desbloqueado, vuelve a poner dos ingredientes aleatorios en el mostrador, y se repite el ciclo.

**Ejercicio propuesto**

*Escribir un programa Java que implemente el esquema de sincronización explicado. Se escribirá una clase hebra Estanquero y otra Fumador, especificando en el constructor de esta última clase el ingrediente que tiene el fumador. La interacción entre los fumadores y el estanquero será resuelta mediante un monitor Estanco basado en el paquete monitor. Usar las plantillas que se incluyen abajo.*

De la misma manera que en la versión con semáforos, en este programa gestionado por monitores, usaremos un variable condicion que se corresponderá a la gestión de la hebra del estanquero, que tendrá la función de poner los ingredientes sobre la mesa, avisando al fumador cuando ponga sus respectivos. Además también he usado un vector de variables condición, correspondiendo cada una de las condiciones de, gestionar los accesos al monitor para cada una de las hebras correspondientes a los fumadores, cuando reciban la señal de aviso de que se encuentran sus ingredientes en la mesa, cogiéndolos para irse a fumar, avisando al estanquero de tal acción.


*Salida del programa:*

```
germaaan@PC-G:~/Universidad/2º/SCD/practica2/Ejercicios/Fumadores$ java Fumadores 
El estanquero pone tabaco y cerillas en la mesa.
El primer fumador coge el tabaco y las cerillas y se va a fumar. 
La mesa del estanco está vacía.
El estanquero pone papel y cerillas en la mesa.
El segundo fumador coge el papel y las cerillas y se va a fumar.
El primer fumador está fumando...
La mesa del estanco está vacía.
El estanquero pone papel y cerillas en la mesa. 
El segundo fumador está fumando...
El segundo fumador coge el papel y las cerillas y se va a fumar. 
La mesa del estanco está vacía.
El segundo fumador está fumando...
El estanquero pone tabaco y papel en la mesa.
El tercer fumador coge el tabaco y el papel y se va a fumar. 
El tercer fumador está fumando...
La mesa del estanco está vacía.
El estanquero pone papel y cerillas en la mesa.
El segundo fumador coge el papel y las cerillas y se va a fumar. 
La mesa del estanco está vacía.
El segundo fumador está fumando...
El estanquero pone tabaco y cerillas en la mesa.
El primer fumador coge el tabaco y las cerillas y se va a fumar. 
El primer fumador está fumando...
La mesa del estanco está vacía.
El estanquero pone tabaco y papel en la mesa.
El tercer fumador coge el tabaco y el papel y se va a fumar. 
El tercer fumador está fumando...
La mesa del estanco está vacía.
El estanquero pone tabaco y cerillas en la mesa.
El primer fumador coge el tabaco y las cerillas y se va a fumar. 
La mesa del estanco está vacía.
El estanquero pone papel y cerillas en la mesa.
El segundo fumador coge el papel y las cerillas y se va a fumar. 
El segundo fumador está fumando...
El primer fumador está fumando... 
La mesa del estanco está vacía.
```

### 6 El problema del barbero durmiente.

**El problema del barbero durmiente (1)**

El problema del barbero durmiente es representativo de cierto tipo de problemas reales: ilustra perfectamente la relación de tipo cliente-servidor que a menudo aparece entre los procesos.

* Una barbería tiene dos puertas y unas cuantas sillas. Los clientes entran por una puerta y salen por otra.
* Solamente un cliente o el barbero pueden moverse por el local en cada momento.
* El barbero continuamente sirve clientes, uno cada vez. Cuando no hay ningún cliente en la barbería, el barbero está durmiendo en su silla.
* Cuando un cliente entra en la barbería y encuentra al barbero durmiendo, lo despierta, se sienta en su silla, y espera a que el barbero termine de pelarlo.
* Si el barbero está ocupado cuando un nuevo cliente entra, el cliente se sienta en una silla de la sala de espera y espera a que el barbero lo despierte.

**El problema del barbero durmiente(2)**

* Cuando el barbero termina de pelar al cliente actual, lo despierta, abre la puerta de salida, y espera a que el cliente salga y cierre la puerta para pasar al siguiente cliente.
* A continuación, si hay clientes esperando, el barbero despierta a uno y espera a que se siente en la silla para pelarlo.
* Si no hay clientes esperando, el barbero se sienta en su silla y duerme hasta que llegue algún cliente y lo despierte.

**Ejercicio propuesto**

*Escribir un programa Java para el problema del barbero durmiente. Los clientes y el barbero son hebras, y la barbería es un monitor que implementa la interacción entre éstos. Los clientes llaman a cortarPelo para obtener servicio del barbero, despertándolo o esperando a que termine con el cliente anterior. El barbero llama a siguienteCliente para esperar la llegada de un nuevo cliente y servirlo. Cuando termina de pelar al cliente actual llama a finCliente, indicándole que puede salir de la barbería y esperando a que lo haga para pasar al siguiente cliente. Usar las plantillas que se incluyen abajo.*

Para este problema he usado los siguientes objetos condición:

* **barbero**: este objeto condición representa el acceso, en exclusión mutua, al recurso que es como tal el barbero, servirá para gestionar cuando el barbero está pelando a una persona, ya que el barbero no puede encontrarse cortando el pelo a más de una persona simultáneamente.

* **silla**: este objeto condicion tiene el propósito de “gestionar” el sueño del barbero, si la silla esta vacía, significa que el barbero no tiene trabajo y puede echarse a dormir, si la silla está ocupada se mandará al barbero la señal para que despierte y se ponga a trabajar.

* **puerta**: mientras que un cliente no haya salido de la barbería, el barbero recibirá a un nuevo cliente al que pelar, por eso mientras la puerta este abierta, no se producirá el aviso a un nuevo cliente de que puede ser pelado.

* **siguienteCliente**: esta variable condición sirve para gestionar cuando un nuevo cliente debe ser llamado, indicara que un cliente espere, mientras que no se produzcan las condiciones para que pueda pasar a cortarse el pelo.

*Salida del programa:*

```
germaaan@PC-G:~/Universidad/2º/SCD/practica2/Ejercicios/BarberoDurmiente/1$       java BarberoDurmiente

Un nuevo cliente entra en la barbería.
El cliente despierta al barbero para que le corte el pelo.
...
El cliente que acaba de pelarse ha salido por la puerta. 
El barbero no tiene trabajo y se pone a dormir.

Un nuevo cliente entra en la barbería.
El cliente despierta al barbero para que le corte el pelo.
...
El cliente que acaba de pelarse ha salido por la puerta. 
El barbero no tiene trabajo y se pone a dormir.

Un nuevo cliente entra en la barbería.
El cliente despierta al barbero para que le corte el pelo.
...
El cliente que acaba de pelarse ha salido por la puerta. 
El barbero no tiene trabajo y se pone a dormir.

Un nuevo cliente entra en la barbería.
El cliente despierta al barbero para que le corte el pelo.
...
El cliente que acaba de pelarse ha salido por la puerta. 
El barbero no tiene trabajo y se pone a dormir.

Un nuevo cliente entra en la barbería.
El cliente despierta al barbero para que le corte el pelo.
```
