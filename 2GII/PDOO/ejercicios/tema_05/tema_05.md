Programación y Diseño Orientado a Objetos
=========================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Relación de problemas. Tema 5: Polimorfismo
### Germán Martínez Maldonado

**1. ¿Qué es el polimorfismo?**

El polimorfismo es la habilidad que tiene un identificador para referenciar a objetos de diferentes clases en tiempo de ejecución de un programa.

**2. ¿Bajo qué condición una variable puede referenciar a objetos de diferentes clases?**

Sólo cuando haya compatibilidad de tipos entre las respectivas clases, por lo que tiene que haber una relación de herencia.

**4. Explica con detalle el concepto casting.**

El casting consiste en hacerle creer al compilador que el valor devuelto por un objeto de tipo A, no es del tipo A, sino del tipo B.

Por ejemplo: Imaginemos que tenemos un superclase A, de la que heredan 2  subclases, B y C. Las subclases tienen redefinidos métodos de la superclase, y además, métodos propios que solo se encuentran en la misma clase, se podría dar el caso que quisiéramos aplicar un método de clase B sobre la clase C, para que esto no diera error de compilación, deberíamos usar el casting, que siempre que haya compatibilidad entre las respectivas clases, nos permitirá llevar a cabo dicha acción.

**5. ¿Es posible crear referencias a interfaces?**

Sí es posible crear referencia a interfaces. Por ejemplo: suponiendo que tenemos un interfaz A, que es implementada por una clase B, podríamos crear una referencia a la interfaz de la siguiente forma:

A objeto = new B();

**6. ¿Se pueden crear instancias de interfaces?**

No se pueden crear instancias de interfaces, solo referencias, esto es debido a que las interfaces son clases abstractas puras, todos sus métodos son abstractos, y en el caso de que existan atributos, estos son variables de clase o finales, por lo cual no tiene sentido instanciar una interfaz, solo tiene sentido crear instancias de clases que implementen dicha interfaz e implementen sus métodos.

Partiendo del ejemplo del ejercicio anterior, podríamos crear una referencia a una interfaz de la forma que se indica, pero lo que no podríamos hacer, es crear una instancia de la interfaz de la siguiente manera:

A objeto = new A();

**7. ¿Qué diferencia hay entre la ligadura dinámica y la ligadura estática, y cuál de ellas soporta mejor el polimorfismo? Pon un ejemplo.**

La diferencia entre la ligadura dinámica y la ligadura estática se encuentra en que la ligadura dinámica se resuelve en tiempo de ejecución, mientras que la ligadura estática lo hace en tiempo de compilación.

Como para realizar polimorfismo, en el caso de una variable, esta debe ser capaz de referenciar objetos de otra clase en tiempo de ejecución, o en el caso de un método, un mensaje debe ser ligado a un método u otro dependiendo de la clase del objeto receptor, pero también en tiempo de ejecución, para usar polimorfismo, será necesario usar ligadura dinámica.

Ejemplo:
Supongamos que tenemos una superclase Figura, de ella heredan las subclases Triangulo, Cuadrado y Círculo. Figura declara el método dibujar(), y a su vez todas las clases que heredan de esta clase, redefinen el mismo método. Si ahora creamos un vector F del tipo Figura, podremos rellenarlo de objetos tanto de la clase Triangulo, Cuadrado o Círculo, y además llamar a sus correspondientes métodos dibujar(), pues bien, esto se puede realizar gracias al uso de herencia, polimorfismo y ligadura dinámica.
