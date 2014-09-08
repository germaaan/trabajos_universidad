// Implementa una clase Conjunto que permita manipular un conjunto de elementos de tipo TipoBase.
// 
// Para la representacion interna de los datos usar una lista de celdas enlazadas. El orden de los elementos no es
// importante desde un punto de vista teorico, pero aconsejamos que se mantengan los elementos ordenados para
// facilitar la implementacion de los metodos de la clase.
// 
// La clase Conjunto debe contener, al menos, las siguientes operaciones:
// 
// 	a) Constructor sin argumentos: crea un conjunto vacio.
// 
// 	b) Constructor con un argumento de tipo TipoBase: crea un conjunto con un u ́nico elemento (el proporcionado
//     como argumento).
// 
// 	c) Constructor de copia (empleando codigo reutilizable).
// 
// 	d) Destructor (empleando codigo reutilizable).
// 
// 	e) Metodo que consulta si el conjunto esta vacio.
// 
// 	f) Sobrecarga del operador de asignacion (empleando codigo reutilizable).
// 
// 	g) Metodo que nos diga cuantos elementos tiene el conjunto.
// 
// 	h) Metodo que reciba un dato de tipo TipoBase y consulte si pertence al conjunto.
// 
// 	i) Sobreescribir los operadores << y >> para leer/escribir un Conjunto.
//     Notas:
// 
// 		· Para la implementacion del operador >> leera una secuencia indefinida de valores, hasta que se introduzca
// 	  	  el valor *. Los valores se leeran en una cadena de caracteres, y solo se convertiran al tipo TipoBase
// 	  	  cuando se verifique que son validos para su almacenamiento (no se ha introducido el terminador (*)).
// 
// 		· Evidentemente, no se permiten elementos repetidos.
// 
// 	j) Metodo que devuelva un VectorDinamico con todos los elementos del conjunto.
// 
// 	k) Sobregargar los operadores relacionales binarios == y != para comparar dos conjuntos. Dos conjuntos seran
//     iguales si tienen el mismo numero de elementos y los mismos valores (independientemente de su posicion).
// 
// 	l) Sobreescribir el operador binario + para calcular la union de dos conjuntos. Respondera a las siguientes
// 	   situaciones:
// 
// 		· Si A y B son datos de tipo Conjunto, A+B sera otro dato de tipo Conjunto y contendra A ∪ B
// 
// 		· Si A es un dato de tipo Conjunto y a es un dato de tipo TipoBase, A+a sera un dato de tipo Conjunto
// 	  	  y contendra A ∪ {a}
// 
// 		· Si A es un dato de tipo Conjunto y a es un dato de tipo TipoBase, a+A sera un dato de tipo Conjunto
// 	  	  y contendra {a} ∪ A
// 
// 	m) Sobreescribir el operador binario - para calcular la diferencia de dos conjuntos. Respondera a las siguientes
//     situaciones:
// 
// 		· Si A y B son datos de tipo Conjunto, A-B sera otro dato de tipo Conjunto y contendra A − B, o sea, el
// 	  	  resultado de quitar de A los elementos que estan en B.
// 
// 		· Si A es un dato de tipo Conjunto y a es un dato de tipo TipoBase, A-a sera un dato de tipo Conjunto
// 	  	  y contendra A − {a}, o sea, el resultado de eleminar del conjunto A el elemento a.
// 
// 	n) Sobreescribir el operador binario * para calcular la interseccion de dos conjuntos. Respondera a las 
//     siguientes situaciones:
// 
// 		· Si A y B son datos de tipo Conjunto, A*B sera otro dato de tipo Conjunto y contendra A ∩ B
// 
// 		· Si A es un dato de tipo Conjunto y a es un dato de tipo TipoBase, A*a sera un dato de tipo Conjunto
// 	  	  y contendra A ∩ {a}
// 
// 		· Si A es un dato de tipo Conjunto y a es un dato de tipo TipoBase, a*A sera un dato de tipo Conjunto
// 	  	  y contendra {a} ∩ A


#include "Conjunto.h"
#include "VectorDinamico.h"
#include <iostream>

using namespace std;

int main() {
    Conjunto A;
    Conjunto B(10);
    Conjunto C(B);
    Conjunto D;
    D = C;

    if (A.estaVacio())
        cout << "A esta vacio." << endl;
    else
        cout << "A no esta vacio." << endl;
    if (B.estaVacio())
        cout << "B esta vacio." << endl;
    else
        cout << "B no esta vacio." << endl;
    if (C.estaVacio())
        cout << "C esta vacio." << endl;
    else
        cout << "C no esta vacio." << endl;

    A.push(10);
    A.push(5);
    A.push(8);
    A.push(9);
    A.push(4);

    cout << "\nCantidad de elementos en A: " << A.size() << endl;
    cout << "A: " << A << endl;
    cout << "\nCantidad de elementos en B: " << B.size() << endl;
    cout << "B: " << B << endl;
    cout << "\nCantidad de elementos en C: " << C.size() << endl;
    cout << "C: " << C << endl;
    cout << "\nCantidad de elementos en D: " << D.size() << endl;
    cout << "D: " << D << endl;

    if (A != B)
        cout << "\nA no es igual a B." << endl;
    else
        cout << "\nA es igual a B." << endl;

    if (C == D)
        cout << "C es igual a D." << endl;
    else
        cout << "C no es igual a D." << endl;

    Conjunto union1;
    union1 = A + B;
    cout << "\nUnion de A y B: " << union1 << endl;

    Conjunto union2;
    union2 = A + 50;
    cout << "Union de A y 50: " << union2 << endl;

    Conjunto union3;
    union3 = 100 + A;
    cout << "Union de 100 y A: " << union3 << endl;

    Conjunto diferencia1;
    diferencia1 = A - B;
    cout << "\nDiferencia de A y B: " << diferencia1 << endl;

    Conjunto interseccion1;
    interseccion1 = A * B;
    cout << "\nInterseccion de A y B: " << interseccion1 << endl;

    cout << endl << endl << endl << endl;

    return (0);
}

