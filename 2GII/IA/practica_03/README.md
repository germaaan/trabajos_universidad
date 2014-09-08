Inteligencia Artificial
=======================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 3: Métodos de búsqueda con adversario (juegos)
### Germán Martínez Maldonado


### 1. Análisis del problema

En esta práctica vamos a realizar el diseño y la implementación de técnicas de búsqueda con adversario en un entorno de juegos. El juego en cuestión será ASPIRADORAS TRON, un juego por turnos para dos jugadores que pueden moverse por un tablero de NxN casillas en búsqueda de suciedad que aspirar. Para el comportamiento inteligente de las aspiradoras se tendrá que implementar un algoritmo de búsqueda MINIMAX, con una profundidad limitada a 10.

El entorno es totalmente conocido, cada casilla puede contener una o varias unidades de suciedad, y además, es posible que algunas casillas se traten de obstáculos no transitables. La suciedad en el tablero toma un valor inicial que sólo variará cuando una aspiradora succione la suciedad en una casilla, no volviendo a generarse suciedad en una casilla ya aspirada.

Las aspiradoras sólo podrán realizar cuatro movimientos diferentes, cada uno correspondiente a moverse en una dirección determinada: hacia arriba, hacia abajo, hacia la izquierda o hacia la derecha. Una vez que una de las aspiradoras pasa por una casilla, automáticamente esa casilla pasa a considerarse una casilla no transitable. En este caso, la acción de aspirar la suciedad se hace automáticamente, añadiéndose las unidades limpiadas al marcador de la aspiradora correspondiente.

Para que el juego se pueda dar por finalizado, se deben dar algunas de las siguientes condiciones:

* No hay más casillas con suciedad en el tablero.
* El marcador de una de las aspiradoras es superior a la suma del marcado de su rival más la cantidad suciedad restante en el tablero.
* Las dos aspiradoras quedan bloqueadas.
* La aspiradora que quede bloqueada tiene un marcador menor que su rival.


### 2. Descripción de la solución planteada

Como hemos indicado en el punto anterior, para el problema del juego a desarrollar, hemos  implementado  un algoritmo MINIMAX. El algoritmo MINIMAX implementada sigue el esquema general de la toma de decisiones Minimax, se busca realizar el mejor movimiento para uno mismo teniendo en cuenta que nuestro rival seleccionará el que nos resulte peor. Por ello, para esta solución se han implementado 6 métodos:

* Environment::ActionType Player::MiniMax(const Environment &actual, int jug, int limite_profundidad)
* double   Player::ValorMax(const   Environment   &actual,   int   jug,   int   limite_profundidad,   Environment::ActionType
&accion)
* double Player::ValorMin(const Environment &actual, int jug, int limite_profundidad)
* double Player::Min(double a, double b)
* double Player::Heuristica (const Environment & actual, int jug)
* double Player::Valoracion(const Environment &actual, int jug)

#### 2.1 MiniMax(const	Environment &actual, int jug, int limite_profundidad)

Recibe como parámetros el estado actual del tablero (const Environment &actual), el jugador para el que se busca el mejor movimiento (int jug) y, la profundidad límite hasta que adentrarse en la búsqueda del mejor movimiento (int limite_profundidad).

Este método será el que devuelva el siguiente movimiento a realizar, después de haber obtenido el movimiento más prometedor calculado en base a la función heurística implementada.

#### 2.2 ValorMax (const Environment &actual, int jug, int limite_profundidad, Environment::ActionType &accion)

Recibe como parámetros el estado actual del tablero (const Environment &actual), el jugador para el que se busca obtener el movimiento con máximo valor (int jug), el límite de profundidad hasta el que buscar en la previsión (int limite_profundidad) y, el movimiento que llevaremos a cabo dependiendo de los resultados obtenidos (Environment::ActionType
&acción).

Este método buscará de entre todos los posibles movimientos, el que tenga un mayor valor en base a que el rival siempre intentará minimizar nuestra acciones en busca de que perdamos. Devolveremos el valor máximo obtenido de entre los mínimos devueltos por nuestro rival, habiendo modificado la acción a realizar cuando se encontrará el valor máximo.

#### 2.3 ValorMin (const Environment &actual, int jug, int limite_profundidad)

Recibe como parámetros el estado actual del tablero (const Environment &actual), el jugador para el que se busca minimizar los resultados a obtener (int jug) y, la profundidad límite para realizar dicha búsqueda (int limite_profundidad).

Este método será el opuesto al método anterior, su función es la de que entre todos los movimientos posibles de nuestro rival, obtener el que minimice en mayor grado nuestros movimientos.

#### 2.4 Min (double a, double b)

Este es un método auxiliar que utilizaremos para comparar la bondad de los movimientos del rival, en búsqueda de obtener el que minimice nuestras acciones.

#### 2.5 Heuristica (const Environment & actual, int jug)

Recibe como parámetros el estado actual del tablero (const Environment & actual) y, el jugador para el que se quiere calcular la bondad del estado actual del tablero en base a sus interés de ganar el juego (int jug).

Se obtendrá el valor del marcador tanto del jugador como del rival, así como una valoración sobre lo prometedor que puede parecer el estado actual del tablero.

Si el marcador del jugador es mayor que el marcador del rival más la cantidad de suciedad restante, significa que el jugador habrá ganado, y como este es el estado más deseado, se devolverá un valor muy alto.

Si el marcado del rival es mayor que el marcado del jugador más la cantidad de suciedad restante, significa que el jugado habrá perdido, y como este es el estado menos deseado, se devolverá un valor muy bajo.

Si el estado actual del tablero, no declara un vencedor definitivo, para saber cómo de bueno le puede resultar el estado actual del tablero al jugador, se devuelve el valor de la estimación para el jugador al que le restamos el valor de la estimación para el rival. Así aunque un movimiento nos pueda proporcionar muchos “puntos”, si al rival también se los proporciona, es posible que nos interese, pero si un movimiento que es menos bueno para nosotros, en compensación es todavía peor para el rival, puede que nos resulte más interesante seleccionar este movimiento, porque nos da menos puntuación, pero más ventaja sobre el rival.

2.6 Valoracion (const Environment &actual, int jug)
Recibe como parámetros el estado actual del tablero (const Environment &actual) y, el jugador para que se quiere estimar como de beneficioso es el estado actual del tablero (int jug).

Lo primero que hacemos es obtener el estado actual del tablero, para poder examinarlo, seguido de obtener la posición actual del jugador y,  después, buscaremos todos los  puntos con suciedad en el tablero, almacenando simultáneamente las coordenadas de la suciedad y la cantidad de suciedad.

Una vez conocemos la ubicación de toda la suciedad, calculamos para cada punto su distancia euclídea respecto a la posición actual del jugador, almacenando cuando proceda la menor encontrada, así como  la  cantidad  de  suciedad correspondiente a ese punto.

Por último devolveremos la distancia a la suciedad más cercana multiplicado por la cantidad de suciedad que tiene, y para que el valor sea significativo, lo multiplicamos por 100. El hecho de multiplicar el valor de distancia por la cantidad de suciedad nos asegura que, en el caso de que dos suciedades se encuentren a una misma distancia, como nos interesa obtener un mayor número de puntos, consideraremos más positivo ir a por la suciedad que nos dé más puntos.
