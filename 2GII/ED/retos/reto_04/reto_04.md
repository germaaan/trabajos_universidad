Estructuras de Datos
====================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Reto 4: Pilas
### Germán Martínez Maldonado


### PRIMER PROBLEMA

**1.- Demostrar que la eficiencia de la siguiente función de la clase Pila es O(1), pero cambiando el 4 por un 2, se convierte en O(n). Como dato, indicar que la función Resize tiene una eficiencia O(n).**

#### CASO A: REDIMENSIONAR CUANDO MENOS DE 1/4 DEL TOTAL ESTÁ OCUPADO

```
void Pila::Quitar()
    {
        assert (n>0);
        nelem--;
        if (nelem<reservados/4) Resize (reservados/2);
    }
```

Para empezar lo único que sabemos de manera segura es que la función Resize tendrá una eficiencia O(n), por lo que siempre que se cumpla la condición de la estructura condicional, la eficiencia del método será O(n).

Como hemos dicho, la eficiencia del método será O(n) siempre se produzca la condición, pero ¿y si no se entra en el bloque condicional?, si analizamos el resto de sentencias de la función, veremos que sólo hay una sentencia de comparación y una asignación, ambas O(1), por lo cual siempre que no entre en el bloque condicional, la eficiencia del método será O(1).

Partiendo de lo dicho en el punto anterior, antes de estudiar más en profundidad la eficiencia del método Pila::Quitar(), imaginemos como podría ser la implementación del método para poner valores en la pila. Al igual que la función Pila::Quitar() implementa una manera de controlar que se haga un uso eficiente de la memoria, el método Pila::Poner() también debería implementar una forma de control sobre esto, una implementación para dicho método podría ser la siguiente:

```
void Pila::Poner(TBase x)
    {
        if (nelem == (reservados-1)) Resize(reservados*2);
        datos[nelem] = c;
        nelem++;
    }
```

Vemos que la forma de funcionar de nuestro método es que cuando sólo quede un espacio reservado libre, automáticamente multiplicaremos la capacidad de espacio reservado al doble, esto se hará así en vista que cuando la pila se llene, seguramente querremos poder seguir insertando elementos, así que directamente aumentamos su tamaño. Ahora hagamos una ejemplificación de cómo podría funcionar la inserción y la extracción de elementos de nuestra pila; supongamos que tenemos una pila con 4 posiciones reservadas, de las cuales 3 están ocupadas, como solo tenemos una posición libre, al llamar al método Pila::Poner() para poner un nuevo elemento en la pila, esta automáticamente doblaría el espacio reservado para nuestra pila, pasando de 4 a 8 posiciones reservadas, teniendo de esas 8, 4 ocupadas, si ahora sacásemos el último valor puesto en la pila, nos quedaría la pila con 8 posiciones disponibles y tan sólo 3 ocupadas, ¿cuál era la condición para que al quitar un valor de la pila esta se redimensionará automáticamente? Que después de sacar el valor de la pila, el tamaño ocupado en la misma fuera menor que 1/4 del total de tamaño reservado, cuándo hemos hecho la extracción del elemento en el tope de la pila ¿se ha producido esta condición? No, por lo tanto nuestra función Pila::Quitar() se ha ejecutado con una eficiencia O(1), e incluso podríamos extraer otro valor de la pila, y como seguiría sin cumplirse la condición (ahora el número de elementos sería 2, que es mayor que 1/4 del tamaño reservado, también 2 en este caso), por lo que nuestra función Pila::Quitar() seguiría ejecutándose con eficiencia O(1), haría falta realizar otra extracción para que finalmente se cumpliera la condición (nos quedaríamos con 1 sólo elemento), y así finalmente, se realizaría la redimensión que provocara que la eficiencia de la función fuera O(n).

La conclusión a la que podemos llegar es que, claramente, la peor eficiencia posible del método Pila::Quitar() será O(n), pero en un funcionamiento normal de pilas, en el que se producen tanto inserciones de valores en la pila como extracciones de valores de la misma, deberemos hacer un número bastante mayor de extracciones que de inserciones para que se produzca el redimensionamiento, y esto produzca una eficiencia O(n) en la función, así que normalmente la eficiencia será O(1), y cuanto mayor sea el espacio reservado para la pila, más difícil será que se produzca está redimensión, porque el número de extracciones seguidas (sin realizar ninguna inserción entre medias) crecerá exponencialmente según crezca el tamaño reservado para la pila, podemos ver un ejemplo en la siguiente tabla:

| Tamaño reservado para pila | Nuevo tamaño al llenar la pila | Extracciones seguidas necesarias para que se produzca reducción de tamaño |
|:--------------------------:|:------------------------------:|:-------------------------------------------------------------------------:|
|              4             |                8               |                                     3                                     |
|              8             |               16               |                                     5                                     |
|             16             |               32               |                                     9                                     |
|             32             |               64               |                                     17                                    |
|             64             |               128              |                                     33                                    |

#### CASO B: REDIMENSIONAR CUANDO MENOS DE 1/2 DEL TOTAL ESTÁ OCUPADO

Planteémonos ahora otro caso, ¿y si para redimensionar después de realizar una extracción, fuera necesario que se encuentre ocupado sólo 1/2 del total del espacio reservado? Partiendo de que contamos con el mismo método para insertar valores en la pila que teníamos en el caso anterior, ahora será mucho más fácil que se dé la situación de que el método reduzca el tamaño reservado de la pila, pero no sólo porque el tamaño objetivo para reducir ahora sea mayor, también deberemos tener en cuenta como se produce el aumento de tamaño reservado de la pila.

En el caso anterior, como el tamaño aumentaba el doble y sólo se reducía cuando este estaba por debajo de 1/4 del total, había menos posibilidades de que se redujese a que se aumentase, por eso decíamos que la función Pila::Quitar() a efectos prácticos, siempre iba a tener una eficiencia O(1) (y sobretodo que a mayor tamaño, mayor posibilidad de esto), pero ahora eso  cambia totalmente, porque el tamaño  de la pila al aumentar se doblará, pero cuando la ocupación esté por debajo de la mitad se reducirá, ¿cómo afecta esto en la eficiencia del método? Mucho. Antes decíamos que era muy difícil que en el uso normal de una pila, de la forma que estaban implementados los métodos de inserción y extracción de valores, fuera necesario recurrir a reducir el espacio de memoria reservado de la pila, esto era así porque, para que eso se produjese, se necesitaban realizar muchas extracciones seguidas sin realizar ninguna sola inserción, lo que en la práctica parece poco común, pero en este caso es diferente, partamos de un ejemplo similar al del caso anterior; supongamos que tenemos una pila con 4 espacios de memoria reservados, de los cuales 3 están ocupados, insertamos un nuevo elemento, como en nuestra pila sólo teníamos un espacio libre, automáticamente el tamaño reservado de la pila se dobla, teniendo ahora un pila con 8 posiciones de memoria reservadas y 4 de ellas ocupadas, si ahora borrásemos uno de los elementos, nos quedaría una pila con 8 posiciones reservadas y sólo 3 usadas, produciéndose la condición para que se reduzca el espacio en memoria reservado para la pila, ¿cuál es el problema? Que después de aumentar el tamaño reservado para la pila (función con eficiencia O(n)), justo en la siguiente instrucción hemos tenido que reducir el tamaño de memoria reservado (la misma función con la misma eficiencia O(n)), por lo que se darán muchos más casos en los que se tengan que reducir el tamaño reservado, así que fácilmente se podría dar el caso de que cada vez que llamemos a la función Pila::Quitar(), está produzca un redimensionamiento, con lo que prácticamente cada que llamemos a este función, su eficiencia será O(n).


### SEGUNDO PROBLEMA

**2.- Supongamos que disponemos del siguiente segmento de código programado para operar con el TDA Pila.**

```
n=3;
pila p(n); //p es una pila con capacidad para albergar n elementos enteros

for (int i=1; i<n; i++)
    if (TEST(i))
        cout << i;
    else p.poner(i);

while (!p.vacia())
    {
        int i=p.tope();
        p.quitar();
        cout<<i;
    }
```

**Con TEST una función booleana con protocolo:**

```
bool TEST (int i);
```

**De la que desconocemos su implementación y de la que solo sabemos que procesa un valor entero y devuelve TRUE o FALSE.**

* **Indicar cuál es la eficiencia del código supuesto que la implementación de la clase pila se hace con vectores dinámicos.**

```
for (int i=1; i<n; i++)
    if (TEST(i))
        cout << i; --------> O(1)
    else p.poner(i); ------> O(1)
```

O(n*1)=O(n) -> O(max(O(n),O(n))) = O(n)

```
while (!p.vacia())
    {
        int i=p.tope(); --> O(1) 
        p.quitar(); ------> O(1)
        cout<<i; ---------> O(1)
    }
```

O(n*1)=O(n). Como dentro de los bucles todas las instrucciones a ejecutar son O(1), y los propios bucles están condicionados por el tamaño de la pila, la eficiencia final del código será O(n).

* **Indicar cuales de las siguientes salidas sería posibles y cuales imposibles si ejecutamos ese código:**

**(a) 1 2 3**

**(b) 1 3 2**

**(c) 2 1 3**

**(d) 3 1 2**

**(e) 2 3 1**

**(f) 3 2 1**

Para averiguar cuáles de estas salidas sería posible que fueran producidas por el código, aprovechando que son pocos valores, podemos simular cual sería el comportamiento exacto del programa para cada una de las posibles combinaciones, aunque esto no se podría hacer con un número de valores más elevado, nos ayudará a comprender como funciona el código, lo que es necesario para resolver el siguiente caso de este problema.

En la siguiente tabla consideraremos los posibles valores obtenidos  por la función TEST() y, la salida asociada que se produciría en dicho caso:

| Número combinación | Posibles combinaciones | Salida generada |
|:------------------:|:----------------------:|:---------------:|
|          1         |    False False False   |      3 2 1      |
|          2         |    False False True    |      3 2 1      |
|          3         |    False True False    |      2 3 1      |
|          4         |     False True True    |      2 3 1      |
|          5         |    True False False    |      1 3 2      |
|          6         |     True False True    |      1 3 2      |
|          7         |     True True False    |      1 2 3      |
|          8         |     True True True     |      1 2 3      |

Como vemos, la salida (a) se puede producir con las combinaciones 7 u 8, la salida (b) se puede producir con las combinaciones 5 o 6, la salida (e) se puede producir con las combinaciones 3 o 4, y la salida (f) se puede producir con las combinaciones 1 o 2. Las salidas
(c) y (d) es imposible que se produzcan.

¿Por qué unas salidas si son posibles y otras no? Veamos cómo está implementado el código: para cada uno de los enteros de una serie de tamaño n (n el mismo tamaño que la pila creada) empezando en 1, le pasamos un  número  de la serie a la función TEST(), si esta devuelve true, el número se muestra en pantalla, si devuelve false, el número es puesto en el tope de la pila, una vez finalizado este bucle, se inicia otro con el que mientras que la pila no este vacía, se saca el número que se encuentre en el tope de la pila y se muestra por pantalla.

Una vez que conocemos como funciona el código implementado, vemos claramente porque es imposible obtener las 2 salidas mencionadas:

 * La salida (c) [2 1 3] es imposible de obtener, porque para que  fuera  posible mostrar ese orden, 2 debería devolver true, para poder ser mostrado el primero, y 1 y 3 deberían devolver false, el problema está en que si 1 y 3 devuelven false, por la propia forma de funcionar de una pila, siempre el 3 será mostrado antes que el 1, porque el 3 está por encima del 1 en la pila, por lo cual será mostrado antes siempre. Para que el 1 fuera mostrado antes que el 3, la estructura en vez de una pila, debería ser una cola, ya que en una cola, el primero que entra también es el primero en salir.

 * La salida (d) [3 1 2] es imposible que salga por el mismo motivo que la combinación anterior, suponiendo que 3 devuelve true y por eso es mostrado el primero, al estar trabajando con una pila, si se inserta primero el 1 y luego el 2, porque ambos devuelvan false, siempre será mostrado primero el que está en el tope, el 2 en este caso. Como en el caso anterior, con la implementación dada, para poder producir esta salida deberíamos usar colas.

* **¿Cómo identificaríais si una salida es posible o imposible para un n arbitrario? Es decir, si n es p.ej. un millón, y por tanto tenéis una salida con un millón de números ¿Cómo sabríais si es posible o imposible?**

Para identificar si una salida es posible tenemos que basarnos en la explicación que hemos hecho del funcionamiento de la implementación del código, hecho que también podemos comprobar si nos fijamos en las salidas que hemos dicho que son válidas y las que hemos dicho que no son válidas, pudiendo distinguir las siguientes posibilidades:

 * Que en todas las llamadas a la función TEST, esta devuelve true en todas las ocasiones, lo que ocasionaría que obtuviésemos una salida con todos los valores ordenados de menor a mayor, ya que se habrían ido mostrando directamente.

 * Que en todas las llamadas a la función TEST, esta devuelve false en todas las ocasiones, lo que produciría que la salida obtenida fuera de todos los valores ordenados de mayor a menor, ya que se habrían almacenado de menor a mayor en la pila, siendo sacadas de esta forma en orden inverso de la pila.

 * Si la función TEST devuelve true y false de forma alternada, para comprobar que la salida es posible, fijémonos primero en las salidas (b) [1 3 2] y (e) [2 3 1], estas 2 salidas hemos comprobado que son válidas, y en ellas está la clave para entender como averiguar si una salida es correcta, si nos fijamos, las dos salidas tienen su valor más alto en la posición de en medio, esto siempre se dará porque siempre el valor más alto se mostrará en medio o por ser el último de la sucesión mostrado directamente por dar true, justo antes de empezar a sacar los valores almacenados en pila; o, precisamente por ser el último en dar false, lo que lo posicionará en el tope de la pila, siendo el primero de los valores de la pila en ser mostrado, justo después de haber mostrado por pantalla todos los valores que devolvían true. Una vez entendido esto, vemos que en todas las posibles salidas válidas, las series siempre tomarán la misma forma, primero se irán mostrando en forma ascendente y una vez que llegue al final de los valores que han devuelto true, los siguientes siempre se irán mostrando de forma descendente, y esto no podrá cambiar, porque estaremos mostrando los valores almacenados en la pila, y si los valores han sido almacenados en la pila en orden ascendente, siempre serán mostrados de forma descendente.
