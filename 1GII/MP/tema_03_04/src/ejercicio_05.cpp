// Implementar la clase Lista para trabajar con listas dinamicas (de tamaño arbitrario, y no definido a priori,
// cuyos nodos residen en el heap) de datos de tipo TipoBase.
// 
// Proponer una representacion para la clase (basada en el almacenamiento de los nodos en memoria dinamica) e
// implementar los siguientes metodos:
// 
// 	a) Constructor sin argumentos, que crea una lista vacia.
// 
// 	b) Constructor con un argumento, que crea una lista con un numero de nodos indicado en el argumento. Inicia
// 	   todos los nodos de la lista a cero.
// 
// 	c) Constructor con dos argumentos, que crea una lista con un numero de nodo indicado en el primer argumento.
// 	Inicia todos los nodos de la lista al valor indicado en el segundo argumento.
// 
// 	d) Destructor.
// 
// 	e) Metodo (valor devuelto: bool) que consulta si la lista esta vacia.
// 
// 	f) Metodo para consultar el numero de nodos de la lista.
// 
// 	g) Metodo para escribir el contenido de una lista.
// 
// 	h) Metodo para insertar un valor en la lista. Modifica la lista. Respondera al siguiente prototipo:
// 	   void Insertar (TipoBase val, int pos);
// 	   de manera que inserta un nuevo nodo en la lista con valor val en la posicion pos. La posicion seguira el
// 	   siguiente convenio: pos indica el numero de orden del nodo actual tras el que se insertara el nuevo nodo.
// 	   Tras la insercion, el nuevo nodo ocupara la posicion pos+1
// 	   Algunos ejemplos (si TipoBase es int):
// 	   Antes: <6, 8, 4, 3, 2, 9> Insertar (5, 1) Despues: <6, 5, 8, 4, 3, 2, 9>
// 	   Antes: <6, 8, 4, 3, 2, 9> Insertar (5, 6) Despues: <6, 8, 4, 3, 2, 9, 5>
// 	   Antes: <6, 8, 4, 3, 2, 9> Insertar (5, 0) Despues: <5, 6, 8, 4, 3, 2, 9>
// 
// 	i) Metodo para borrar un nodo en la lista. Respondera al siguiente prototipo:
// 	   void Borrar (int pos);
// 	   de manera que borra el nodo que ocupa la posicion pos (1 para el primer nodo, 2 para el segundo, etc.)
// 	   Evidentemente, modifica la lista.
// 
// 	j) Metodos para leer/escribir un valor.
// 	   TipoBase ObtenerValor (int pos);
// 	   void PonerValor (int pos, TipoBase val);
// 	   de tal manera que pos indica la posicion del nodo (1 para el primer nodo, 2 para el segundo, etc.)
//
//Ampliar la clase Lista de datos de tipo TipoBase con los siguientes metodos:
//
//a) Constructor de copia y sobrecarga del operador de asignacion, empleando codigo reutilizable. Reescribir el
//   destructor en base a esta estrategia.
//
//b) Sobregargar el operador [] para que sirva de operador de acceso a los elementos de la lista y pueda actuar
//   tanto como lvalue como rvalue. El indice hace referencia a la posicion, de tal manera que 1 indica el primer
//   nodo, 2 el segundo, etc.)
//
//c) Sobreescribir los operadores << y >> para leer/escribir una lista.
//   Notas:
//
//		· Para la implementacion del operador >> leera una secuencia indefinida de valores, hasta que se introduzca
//	  	  el valor *. Los valores se leeran en una cadena de caracteres, y solo se convertiran al tipo TipoBase
//	  	  cuando se verifique que son validos para su almacenamiento (no se ha introducido el terminador (*)).
//
//		· El nuevo valor siempre se guardara al final.

#include "Lista.h"
#include <iostream>

using namespace std;

int main() {
    Lista lista1;
    Lista lista2(5);
    Lista lista3(10, 5);

    if (lista1.estaVacia())
        cout << "lista1 esta vacia." << endl;
    else
        cout << "lista1 no esta vacia." << endl;
    if (lista2.estaVacia())
        cout << "lista2 esta vacia." << endl;
    else
        cout << "lista2 no esta vacia." << endl;
    if (lista3.estaVacia())
        cout << "lista3 esta vacia." << endl;
    else
        cout << "lista3 no esta vacia." << endl;

    lista1.Insertar(1, 0);
    lista2.Insertar(2, 5);
    lista3.Insertar(0, 8);

    lista1.Borrar(0);
    lista2.Borrar(6);
    lista3.Borrar(6);

    lista1.PonerValor(1, 9);
    lista2.PonerValor(2, 1);
    lista3.PonerValor(10, 3);

    cout << "\nValor de la posición 1 de lista1: " << lista1.ObtenerValor(1) << endl;
    cout << "Valor de la posición 2 de lista2: " << lista2.ObtenerValor(2) << endl;
    cout << "Valor de la posición 3 de lista3: " << lista3.ObtenerValor(3) << endl;

    cout << "\nNumero de nodos de lista1: " << lista1.size() << endl;
    cout << "Numero de nodos de lista2: " << lista2.size() << endl;
    cout << "Numero de nodos de lista3: " << lista3.size() << endl;

    cout << "\nContenido de lista1: " << endl;
    lista1.escribeLista();
    cout << "Contenido de lista2: " << endl;
    lista2.escribeLista();
    cout << "Contenido de lista3: " << endl;
    lista3.escribeLista();

    cout << "\nContenido de lista1: " << lista1 << endl;
    cout << "Contenido de lista2: " << lista2 << endl;
    cout << "Contenido de lista3: " << lista3 << endl;

    Lista lista4(lista2);
    cout << "Contenido de lista4 (creada mediante constructor de copia): " << lista4 << endl;

    Lista lista5;
    lista5 = lista2;
    cout << "Contenido de lista5 (creada mediante constructor de copia): " << lista2 << endl;

    cout << "Valor de la posición 2 de lista2: " << lista2[2] << endl;
    cout << "Valor de la posición 3 de lista3: " << lista3[3] << endl;

    cout << endl << endl << endl << endl;

    return (0);
}
