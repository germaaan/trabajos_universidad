#ifndef __EXPRESION_H_
#define __EXPRESION_H_

/**
   TDA expresion.

   Representa una expresion matemática construida con forma de árbol, donde todos los nodos seran tipo string.
   Los valores de dichos nodos podrán igualarse a:
                - Tipos numéricos (int, float...) si el nodo representa un operando;
                - Tipo caracter si el nodo representa un operador o una variable; 

   T debe tener definidas las operaciones:
           - T & operator=(const T & e);
           - T operator+(const T & e);
           - T operator-(const T & e);
           - T operator*(const T & e);
           - T operator/(const T & e);

   Al estar básado en el TDA bintree, comparte sus mismas propiedas:
        - Son mutables.
        - Residen en memoria dinámica.
   
   Un ejemplo de su uso:
   @include usoEpresion.cpp
 */

#include "bintree.h"
#include <string>

using namespace std;

template <typename T>
class expresion {
public:
    /**
       @brief Constructor por defecto de la clase.
     
       Crea una expresión nulo.
     */
    expresion();

    /**
       @brief Constructor que permite generar una expresión con un único valor.
     
       @param v Etiqueta para la raíz.
     
       Crea una expresión con un único operando con valor v.
     */
    expresion(const T & v);

    /**
       @brief Constructor que permite generar una expresión asociada a la cadena c.
     
       @param c Cadena de texto con una expresión completa.
     
       Crea una expresión asociada la cadena c, donce c es una expresión en prefijo y, los operandos y operadores estan separados por espacios.
     */
    expresion(const string & c);

    /**
       @brief Operador de asignación.
     
       @param e: expresión que se asigna.
     
       @return devuelve el resultado de destruir el contenido precio del receptor y asignarle un duplicado de e.
     */
    expresion & operator=(const expresion & e);

    /**
       @brief Operador de suma.
     
       @param e: expresión que se suma.
     
       @return devuelve la expresión que se obtiene al considerar en infijo (*this + e).
     */
    expresion operator+(const expresion & e) const;

    /**
       @brief Operador de resta.
     
       @param e: expresión que se resta.
     
       @return devuelve la expresión que se obtiene al considerar en infijo (*this - e).
     */
    expresion operator-(const expresion & e) const;

    /**
       @brief Operador de multiplicación.
     
       @param e: expresión que se multiplica.
     
       @return devuelve la expresión que se obtiene al considerar en infijo (*this * e).
     */
    expresion operator*(const expresion & e) const;

    /**
       @brief Operador de división.
     
       @param e: expresión que se divide.
     
       @return devuelve la expresión que se obtiene al considerar en infijo (*this / e).
     */
    expresion operator/(const expresion & e) const;

    /**
       @brief Obtener expresión en infijo.
     
       @return devuelve la expresión en infijo, completamente parentizada.
     */
    string infijo() const;

    /**
       @brief Obtener expresión en postfijo.
     
       @return devuelve la expresión en postfijo.
     */
    string postfijo() const;

    /**
       @brief Obtener expresión en prefijo.
     
       @return devuelve la expresión en prefijo.
     */
    string prefijo() const;

    /**
       @brief Obtener expresión en por niveles.
     
       @return devuelve la expresión al hacer un recorrido por niveles.
     */
    string niveles() const;

    /**
       @brief Evalua una expresión.
     
       @param valores: vector con las parejas varible-valor de la expresion.
     
       @return devuelve el resultado de evaluar la expresión.
     */
    T evalua(const vector< pair<char, T> > & valores) const;

private:
    // Usamos un bintree de tipo string para poder trabajar facilmente con números con decimales.
    bintree<string> arbol;

    /**
       @brief Obtiene expresión en infijo de forma recursiva.
       
       @param n: nodo desde el que partimos para obtener la expresión en inorden.
     
       @return devuelve la expresión en infijo, completamente parentizada.
       
       Obtiene la expresión en inorden de forma recursiva partiendo desde el nodo raíz, hasta recorrer todos los nodos.
     */
    string parentesisInfijo(const bintree<string>::node & n) const;

    /**
       @brief Obtiene el valor de calcular la evaluación de la expresión.
       
       @param n: nodo desde el cuál se está evaluando una subexpresión.
       @param valores: vector con las parejas varible-valor de la expresion.
     
       @return devuelve el resultado de evaluar la expresión.
       
       Obtiene el resultado de la evaluación de la expresión de forma recursiva, partiendo desde la raíz hasta evaluar todas las subexpresiones.
     */
    T calculo(const bintree<string>::node & n, const vector< pair<char, T> > & valores) const;

    /**
       @brief Obtiene el valor numérico de un operando.
       
       @param etiqueta: operando del que se va a obtener el valor numérico.
       @param valores: vector con las parejas varible-valor de la expresion.
     
       @return devuelve el valor númerico del operando.
       
       Obtiene el valor númerico de un operando, si es una variable, busca su valor númerico asociado.
     */
    T buscaValor(const string & etiqueta, const vector< pair<char, T> > & valores) const;
};

#include "expresion.hxx"

#endif
