Estructuras de Datos
====================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Reto 2: Abstracción
### Germán Martínez Maldonado
### José Rubén Sánchez Iruela
### Pablo Sánchez Robles

**Dado un conjunto de 6 enteros sacados aleatoriamente del conjunto:**

**C = {1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 25; 50; 75; 100}**

**Podemos plantearnos conseguir otro entero aleatorio de 3 cifras usando para ello solo las operaciones de suma, resta, producto y división entera, teniendo en cuenta que solo se puede usar cada número (de los 6) como mucho una vez, aunque es posible que no todos se usen para conseguir el número de 3 cifras.**

**El reto consiste en crear un algoritmo para resolver el problema de las cifras. La idea es que deis (si es posible) un algoritmo (secuencia de pasos) para resolver el problema.**

**No quiero un programa, quiero una solución que haga uso de vuestra capacidad de abstracción. Animo con las soluciones. Veamos en que punto está vuestra creatividad y vuestra capacidad de abstracción cara a resolver un problema. Es un reto intelectualmente interesante para un ingeniero informático.**


### IMPLEMENTACION

Tenemos un conjunto C de enteros almacenado en un vector de 14 posiciones. Sacamos aleatoriamente 6 números del conjunto y los almacenamos en otro vector. Esto lo haremos con un bucle for con 6 iteraciones y para cada iteración generaremos un número aleatorio entre 0 y 13 para así acceder a ese número y extraerlo del conjunto.

Nuestra estructura de datos será una clase con atributos: un vector de enteros de 6 posiciones en el que almacenaremos los valores extraídos de forma aleatoria, otro atributo será un vector de tipo char de 6 posiciones que almacenará las operaciones realizadas, un vector con 6 enteros con los números que hemos ido utilizando, un vector de 6 enteros con el resultado de las operaciones realizadas, un entero con la solución objetiva que será la que queramos conseguir y por ultimo un entero que contiene la solución obtenida.

En el main contendremos un vector de 14 enteros que representa el conjunto de enteros del que obtenemos los valores, un vector de enteros que almacenaran los números extraídos aleatoriamente y un entero que será el valor objetivo. Los valores de las variables no cambiaran durante toda la ejecución. Serán recibidos al inicio y concretamente al vector con los valores aleatorios y el entero objetivo será pasado a cada objeto creado para crear una nueva solución, creando también un vector de objetos de nuestra clase que almacenara todas las soluciones para posteriormente comparar cual es la más cercana a nuestro entero objetivo.

Tendremos una función que irá creando objetos para cada una de las posibles soluciones, cada una de estas soluciones consistirá en ir probando los distintos tipos de diferentes combinaciones de operadores y de operaciones que hay. La función está compuesta por un bucle while que dará 20 iteraciones como máximo ya que como mucho tenemos 5 diferentes parejas con los que operar y 4 posibles operaciones, esto quiere decir que con las 20 iteraciones cubrimos todos los posibles resultados. Cada resultado será guardado en su correspondiente objeto de la clase. El while tendrá una condición que será que de 20 iteraciones o que el resultado del objeto sea el mismo que el buscado, en ese caso finalizara el programa y mostrara la combinación acertada. En el caso de que no encontremos el resultado exacto tendremos que recorrer el vector comparando todas las soluciones y la que más se acerque será la elegida.
