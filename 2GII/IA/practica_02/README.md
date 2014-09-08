Inteligencia Artificial
=======================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 2: Métodos de búsqueda
### Germán Martínez Maldonado

### 1. Análisis del problema

En esta práctica vamos a realizar la implementación de agentes deliberativos con el objetivo de resolver el problema del robot aspirador de la mejor forma posible, para dicho objetivo, tomando como base el método de búsqueda en anchura que viene implementado y todos los métodos vistos en clase, deberemos desarrollar un método que use una técnica de búsqueda en profundidad y, también, un método que usa una solución heurística basada en una técnica de escalada.

El entorno en el que debe realizarse la acción es totalmente conocido en esta ocasión, conociendo tanto las dimensiones del mapa como las coordenadas de los diferentes obstáculos, puntos de suciedad y el punto de partida. El desplazamiento sólo se podrá hacer de una casilla en una casilla, no permitiéndose movimientos diagonales ni atravesar obstáculos. La suciedad se representa con valores enteros mayores que 0 y una vez que se ha limpiado en una casilla, no vuelve a generarse en la misma casilla.

Cada desplazamiento consume 1 punto de energía, cada unidad de suciedad limpiada consume 2 puntos de energía, el objetivo es limpiar todas las casillas de la habitación con el menor coste energético.


### 2. Descripción de la solución planteada

#### 2.1 Búsqueda en profundidad

Una búsqueda en profundidad es aquella en la que se van expandiendo todos los nodos según van apareciendo, hasta que se produzca la situación de que ya no haya más nodos que expandir en ese camino, produciéndose una vuelta atrás has un nodo hermano de uno ya expandido que tengo nodos sin explorar todavía.

Para la implementación de esta búsqueda nos basaremos en el tipo de dato “stack” (pila) de la STL para la exploración de los nodos y de un tipo de dato “list” (lista) de la STL para ir construyendo el camino resultante de nuestra búsqueda, construyendo un método que funciona de la siguiente forma:

1. Si un estado no es solución, profundizamos explorando el siguiente estado en el grafo, para ello lo primero que hacemos es generar todos los posibles estados descendientes de nuestro estado actual.
2. Mediante punteros enganchamos todos los estados generados a nuestro estado actual para luego poder movernos a través de ellos cuando sea necesario y, si el nodo no había sido previamente insertado en la lista de estados visitados, se inserta, y a continuación se añade a la pila.
3. Como en una búsqueda en profundidad se van explorando los nodos según van apareciendo, tomamos el estado que este en la cima de la pila, apuntamos hacía él, lo copiamos, y lo sacamos de la pila para explorarlo a continuación.

#### 2.2 Método de escalada

Para dimensiones de información relativamente grandes, tanto en la búsqueda en anchura como la búsqueda en profundidad, aumenta considerablemente la dificultad de la exploración total del grafo de estados posibles, por lo que en dichos casos la mejor opción es usar métodos de escalada, que partiendo de que se conoce la información sobre el mundo en el que se encuentra, intenta maximizar (o minimizar si es el caso) el valor obtenido de una función de evaluación implementada desde el conocimiento del problema, todo esto con el objetivo de obtener el resultado previsiblemente más óptimo.

Para esta práctica hemos optado por implementar un método de escalada de máxima pendiente, esto consiste en obtener el valor de la función objetivo de todos los estados descendientes de nuestro estado actual, tomando como siguiente estado a explorar el que nos devuelva un valor mejor que nuestro estado actual.

En este caso deberemos tener en cuenta dos aspectos para saber si hemos finalizado la búsqueda, que nuestro estado actual sea una solución, en cuyo caso habremos obtenido un camino para resolver nuestro problema, o que ningún estado descendiente mejore el estado actual, que se producirá en el caso de que nos encontremos en un óptimo local, obteniendo en este caso sólo una solución parcial al problema.

**2.2.1 Función heurística**

Como función de evaluación he implementado un método que lo que hace es calcular la suma de distancias, tanto vertical como horizontal, que hay desde nuestra posición actual en un estado, hasta un punto donde haya basura, aumentando paso a paso si es transitable, y penalizando en caso de que choque contra un obstáculo, a la vez que se bonifica el encontrarse en una casilla con suciedad que limpiar o al lado de una que cumpla dicha condición, ya que estos son estados que nos interesan. Finalmente nos quedaremos con la distancia hacia la casilla con basura más cercana, que es lo que nos interesa para obtener un mejor resultado.

Para implementar dicha función, hemos modificado la clase “state” incluyendo los siguientes métodos:

* int** Get_mundo() {return mundo;}: que devuelve la matriz que representa el mundo por el que se mueve la aspiradora.
* int Get_Tam_X() {return Tam_X;}: que devuelve el tamaño en filas de la matriz.
* int Get_Tam_Y() {return Tam_Y;}: que devuelve el tamaño en columnas de la matriz.
* int Get_posX() {return posX;}: que devuelve la posición de la fila en la que nos encontramos actualmente.
* int  Get_posY()  {return  posY;}:  que  devuelve  la  posición  de  la  columna  en  la  que  nos  encontramos actualmente.


### 3. Resultados obtenidos por la solución aportada en los distintos mapas.

#### 3.1 Búsqueda en profundidad

* **mapa10a.map**

![pra02_img01](imagenes/pra02_img01.png)

* **mapa10b.map**

![pra02_img02](imagenes/pra02_img02.png)

* **mapa10c.map**

![pra02_img03](imagenes/pra02_img03.png)

* **mapa10d.map**

![pra02_img04](imagenes/pra02_img04.png)

* **mapa20.map**

![pra02_img05](imagenes/pra02_img05.png)

Para los mapas “mapa40.map” y “mapa80.map” no se obtiene solución con este método por la gran dimensión de información que representan.

#### 3.2 Método de escalada

* **mapa10a.map**

![pra02_img06](imagenes/pra02_img06.png)

* **mapa10b.map**

![pra02_img07](imagenes/pra02_img07.png)

* **mapa10c.map**

![pra02_img08](imagenes/pra02_img08.png)

* **mapa10d.map**

![pra02_img09](imagenes/pra02_img09.png)

* **mapa20.map**

![pra02_img10](imagenes/pra02_img10.png)

* **mapa40.map**

![pra02_img11](imagenes/pra02_img11.png)

* **mapa80.map**

![pra02_img12](imagenes/pra02_img12.png)
