// Implementar la clase VectorDinamico para trabajar con vectores de enteros de tamaño arbitrario, y no definido
// a priori.
// 
// Proponer una representacion para la clase e implementar los siguientes metodos:
// 
// 	a) Constructor sin argumentos, que crea un vector dinamico vacio.
// 
// 	b) Constructor con un argumento, que crea un vector dinamico con un numero de casillas indicado en el
// 	argumento. Inicia todas la casillas a cero.
// 
// 	c) Constructor con dos argumentos, que crea un vector dinamico con un numero de casillas indicado en el
// 	primer argumento. Inicia todas la casillas al valor indicado en el segundo argumento.
// 
// 	d) Destructor.
// 
// 	e) Metodo (valor devuelto: bool) que consulta si el vector dimamico esta vacio.
// 
// 	f) Metodo para consultar el numero de casillas ocupadas en el vector.
// 
// 	g) Metodos para leer/escribir un valor.
// 
// 	h) Metodo para escribir el contenido del vector dinamico.
// 
// 	i) Metodo para redimensionar un vector dinamico. Recibira un solo argumento: el nuevo numero de casillas,
// 	   que suponemos siempre sera mayor que el actual. El “nuevo” vector debe mantener los valores almacenados
// 	   anteriormente, en las mismas posiciones.
//
//Ampliar la clase VectorDinamico de datos de tipo TipoBase con los siguientes metodos:
//
//	a) Constructor de copia y sobrecarga del operador de asignacion, empleando codigo reutilizable. Reescribir el
//	   destructor en base a esta estrategia.
//
//	b) Sobregargar el operador [] para que sirva de operador de acceso a los elementos del vector dinamico y
//	   pueda actuar tanto como lvalue como rvalue.
//
//	c) Sobregargar los operadores relacionales binarios == y != para comparar dos vectores dinamicos. Dos vectores
//	   seran iguales si tienen el mismo numero de casillas ocupadas y los contenidos son iguales y en las mismas
//	   posiciones.
//
//	d) Sobregargar los operadores relacionales binarios >, <, >= y <= para poder comparar dos vectores dinamicos.
//	   Usar un criterio similar al que se sigue en la comparacion de dos cadenas de caracteres clasicas.
//
//	e) Considerar una implementacion nueva para redimensionar un vector dinamico: emplear los operadores
//	   binarios +, -, += y -= de manera que, por ejemplo:
//	   Si v es un VectorDinamico, la instruccion v = v+1 crea un VectorDinamico con una casilla mas que v, lo
//	   rellena a partir de este y lo devuelve; a continuacion se asigna a v. Si v es un VectorDinamico, la instruccion
//	   VectorDinamico v2 = v+1 crea un vector dinamico con una casilla mas que v, lo rellena a partir de v y lo
//	   devuelve; a continuacion se se crea v2 a partir del vector dinamico asi construido.
//	   Si v es un VectorDinamico, la instruccion v -= 10 crea un VectorDinamico con 10 casillas menos que
//	   v, lo rellena a partir de este (descartando las 10 ultimas) y lo devuelve; a continuacion se asigna a v.
//	   Se sobreentiende que antes de realizar esta operacion estamos seguros que el numero de casillas ocupadas
//	   seguira siendo menor o igual que el numero maximo de casillas disponibles que tendremos despues de la
//	   reduccion.
//
//	f) Sobreescribir los operadores << y >> para leer/escribir un vector dinamico.
//	   Notas:
//
//		· Para la implementacion del operador >> leera una secuencia indefinida de valores, hasta que se introduzca
//		  el valor *. Los valores se leeran en una cadena de caracteres, y solo se convertiran al tipo TipoBase
//		  cuando se verifique que son validos para su almacenamiento (no se ha introducido el terminador (*)).
//
//		· El nuevo valor siempre se guardara al final.


#include "VectorDinamico.h"
#include <iostream>

using namespace std;

int main() {
    VectorDinamico vector1;
    VectorDinamico vector2(10);
    VectorDinamico vector3(5, 20);
    VectorDinamico vector4();

    if (vector1.estaVacio())
        cout << "vector1 esta vacio." << endl;
    else
        cout << "vector1 no esta vacio." << endl;

    if (vector2.estaVacio())
        cout << "vector2 esta vacio." << endl;
    else
        cout << "vector2 no esta vacio." << endl;

    if (vector3.estaVacio())
        cout << "vector3 esta vacio." << endl;
    else
        cout << "vector3 no esta vacio." << endl;

    vector1.push(40);
    vector2.push(50);
    vector3.push(60);

    cout << "\nNumero de casillas ocupadas en vector1: " << vector1.size() << endl;
    cout << "Numero de casillas ocupadas en vector2: " << vector2.size() << endl;
    cout << "Numero de casillas ocupadas en vector3: " << vector3.size() << endl;

    cout << "\nValor en la posición 0 de vector1: " << vector1.at(0) << endl;
    cout << "Valor en la posición 1 de vector2: " << vector2.at(1) << endl;
    cout << "Valor en la posición 2 de vector3: " << vector3.at(2) << endl;

    cout << "\nValores en el vector 1: " << endl;
    vector1.escribirVector();
    cout << "\nValores en el vector 2: " << endl;
    vector2.escribirVector();
    cout << "\nValores en el vector 3: " << endl;
    vector3.escribirVector();
    cout << endl;

    cout << "\nValor en la posicion 0 del vector 1: " << vector1[0] << endl;

    if (vector2 == vector3)
        cout << "Los vectores 2 y 3 son iguales." << endl;
    else
        cout << "Los vectores 2 y 3 son diferentes." << endl;

    if (vector2 != vector3)
        cout << "Los vectores 2 y 3 son diferentes." << endl;
    else
        cout << "Los vectores 2 y 3 son iguales." << endl;

    if (vector2 > vector3)
        cout << "\nEl vector 2 es mayor que el vector 3." << endl;
    else
        cout << "\nEl vector 2 es menor que el vector 3." << endl;

    if (vector2 < vector3)
        cout << "El vector 2 es menor que el vector 3." << endl;
    else
        cout << "El vector 2 es mayor que el vector 3." << endl;

    if (vector2 >= vector3)
        cout << "El vector 2 es mayor o igual que el vector 3." << endl;
    else
        cout << "El vector 2 es menor o igual que el vector 3." << endl;

    if (vector2 <= vector3)
        cout << "El vector 2 es menor o igual que el vector 3." << endl;
    else
        cout << "El vector 2 es mayor o igual que el vector 3." << endl;

    cout << "\nCOMPROBACIONES DE AUMENTO DE CAPACIDAD:" << endl;

    cout << "\nContenido de vector2: " << vector2 << endl;
    cout << "Celdas totales de vector2: " << vector2.capacity() << endl;

    vector2 = vector2 + 1;
    cout << "\nContenido de vector2: " << vector2 << endl;
    cout << "Celdas totales de vector2: " << vector2.capacity() << endl;

    vector2 = vector2 + 2;
    cout << "\nContenido de vector2: " << vector2 << endl;
    cout << "Celdas totales de vector2: " << vector2.capacity() << endl;

    VectorDinamico vector5 = vector2 + 1;
    cout << "\nContenido de vector5: " << vector5 << endl;
    cout << "Celdas totales de vector5: " << vector5.capacity() << endl;

    cout << "\nCOMPROBACIONES DE REDUCCION DE CAPACIDAD:" << endl;

    cout << "\nContenido de vector3: " << vector3 << endl;
    cout << "Celdas totales de vector3: " << vector3.capacity() << endl;

    VectorDinamico vector6 = vector3 - 1;
    cout << "\nContenido de vector6: " << vector6 << endl;
    cout << "Celdas totales de vector6: " << vector6.capacity() << endl;

    vector6 = vector6 - 1;
    cout << "\nContenido de vector6: " << vector6 << endl;
    cout << "Celdas totales de vector6: " << vector6.capacity() << endl;

    cout << "\nCOMPROBACIONES DE COPIA Y AUMENTO DE CAPACIDAD:" << endl;

    cout << "\nContenido de vector2: " << vector2 << endl;
    cout << "Celdas totales de vector2: " << vector2.capacity() << endl;

    vector2 += 10;
    cout << "\nContenido de vector2: " << vector2 << endl;
    cout << "Celdas totales de vector2: " << vector2.capacity() << endl;

    cout << "\nCOMPROBACIONES DE COPIA Y REDUCCION DE CAPACIDAD:" << endl;

    cout << "\nContenido de vector3: " << vector3 << endl;
    cout << "Celdas totales de vector3: " << vector3.capacity() << endl;

    vector3 -= 5;
    cout << "\nContenido de vector3: " << vector3 << endl;
    cout << "Celdas totales de vector3: " << vector3.capacity() << endl;

    cout << endl << endl << endl << endl;

    return (0);
}

