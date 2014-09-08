// Implementar la clase Cola.
// 
// Una cola es una estructura de datos que permite la gestion de problemas en los que la gestion se realiza empleando
// un protocolo FIFO (First in first out).
// 
// Proponer una representacion para la clase (basada en el almacenamiento de los nodos en memoria dinamica) e
// implementar los siguientes metodos:
// 
// 	a) Constructor sin argumentos, que crea una cola vacia.
// 
// 	b) Destructor.
// 
// 	c) Metodo (valor devuelto: bool) que consulta si la cola esta vacia.
// 
// 	d) Metodos para añadir un valor. La cola se modifica.
// 
// 	e) Metodos para sacar un valor. Obtiene (devuelve) el elemento extraido. La cola se modifica.
// 
// 	f) Metodo para consultar que elemento esta en la cabecera de la cola. La cola no se modifica.
// 
// Ampliar la clase Cola de datos de tipo TipoBase con los siguientes metodos:
// 
// 	a) Constructor de copia y sobrecarga del operador de asignacion, empleando codigo reutilizable. Reescribir el
//    destructor en base a esta estrategia.
// 
// 	b) Sobreescribir el operador <<.


#include "Cola.h"
#include <iostream>

using namespace std;

int main() {
    Cola estructura;

    if (estructura.estaVacia())
        cout << "La cola esta vacia." << endl;
    else
        cout << "La cola no esta vacia." << endl;

    estructura.push(2);
    estructura.push(4);
    estructura.push(6);
    estructura.push(3);
    estructura.push(5);

    cout << "\nElemento sacado de la cabecera de la cola: " << estructura.sacar() << endl;
    cout << "Elemento actual en la cabecera de la cola: " << estructura.cabecera() << endl;

    cout << "\nElementos en la pila original:\n" << estructura << endl;

    Cola cola2(estructura);
    cout << "\nElementos en la pila copiados mediante constructor de copia:\n" << cola2 << endl;

    Cola cola3;
    cola3 = cola2;
    cout << "\nElementos en la pila copiados mediante sobrecarga del metodo de asignacion:\n" << cola3 << endl;

    cout << endl << endl << endl << endl;

    return (0);
}
