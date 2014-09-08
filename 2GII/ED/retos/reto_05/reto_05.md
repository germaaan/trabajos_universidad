Estructuras de Datos
====================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Reto 5: Colas y listas
### Germán Martínez Maldonado

El reto 5 tiene un planteamiento muy sencillo. Se trata de implementar la clase Cola a partir de la clase Lista. La idea es que disponeis de la clase lista con toda la implementación ya hecha y teneis que construir la clase cola a partir de esa implementación sin tener que implementar nuevo código, es decir que la implementación de las funciones se hará simplemente llamando a funciones ya implementadas de las listas. P.ej la función quitar de la cola se podría construir a partir de la función borrar de las listas, sin más que activarla como c.borrar(c.begin()), supuesto que c es de tipo lista (que se comporta como una cola).

* [cola.h](codigo/cola.h)
* [cola.hxx](codigo/cola.hxx)
* [usocola.cpp](codigo/usocola.cpp)
