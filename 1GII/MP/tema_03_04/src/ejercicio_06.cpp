// Implementar la clase Pila.
// 
// Una pila es una estructura de datos que permite la gestion de problemas en los que la gestion se realiza empleando
// un protocolo LIFO (last in first out).
// 
// Proponer una representacion para la clase (basada en el almacenamiento de los nodos en memoria dinamica) e
// implementar los siguientes metodos:
// 
// 	a) Constructor sin argumentos, que crea una pila vacia.
// 
// 	b) Destructor.
// 
// 	c) Metodo (valor devuelto: bool) que consulta si la pila esta vacia.
// 
// 	d) Metodos para añadir un valor. La pila se modifica.
// 
// 	e) Metodos para sacar un valor. Obtiene (devuelve) el elemento extraido. La pila se modifica.
// 
// 	f) Metodo para consultar que elemento esta en el tope de la pila. La pila no se modifica.
// 
// Ampliar la clase Pila de datos de tipo TipoBase con los siguientes metodos:
// 
// 	a) Constructor de copia y sobrecarga del operador de asignacion, empleando codigo reutilizable. Reescribir el
// 	   destructor en base a esta estrategia.
// 
// 	b) Sobreescribir el operador <<.


#include "Pila.h"
#include <iostream>

using namespace std;

int main() {
    Pila estructura;

    if (estructura.estaVacia())
        cout << "La pila esta vacia." << endl;
    else
        cout << "La pila no esta vacia." << endl;

    estructura.push(2);
    estructura.push(4);
    estructura.push(6);
    estructura.push(3);
    estructura.push(5);

    cout << "\nElemento sacado del tope de la pila: " << estructura.sacar() << endl;
    cout << "Elemento actual en el tope de la pila: " << estructura.tope() << endl;

    cout << "\nElementos en la pila original:\n" << estructura << endl;

    Pila pila2(estructura);
    cout << "\nElementos en la pila copiados mediante constructor de copia:\n" << pila2 << endl;

    Pila pila3;
    pila3 = pila2;
    cout << "\nElementos en la pila copiados mediante sobrecarga del metodo de asignacion:\n" << pila3 << endl;

    cout << endl << endl << endl << endl;

    return (0);
}
