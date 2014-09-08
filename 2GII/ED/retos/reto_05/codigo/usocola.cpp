/**
 * @file usocola.cpp
 * @brief Fichero ejemplo de uso de la implementación del TDA Cola
 *
 */

#include <iostream>
#include "cola.h"

using namespace std;

int main() {

    cout << "\n###################################################" << endl;
    cout << "# TDA Cola basado en List de STL usando templates #" << endl;
    cout << "###################################################" << endl;

    Cola<int> p;

    cout << "\nTRABAJANDO CON UNA COLA DE ENTEROS: ";
    for (int i = 0; i < 10; i++) {
        p.poner(i);
        cout << "[" << i << "]";
    }
    cout << "\n----------------------------------" << endl;
    cout << "\t- Número de elementos en la cola de enteros: " << p.num_elementos() << endl;
    cout << "\t- El elemento al frente de nuestra cola de enteros es: " << p.frente() << endl;
    cout << "\t- Creando una copia de la cola de enteros..." << endl;
    Cola<int> auxp;
    auxp = p;
    p.frente() = 22;
    cout << "\t- Elemento al frente de la cola de enteros cambiado, ahora es: " << p.frente() << endl;
    cout << "\t- Elemento al frente de la copia de la cola de enteros: " << auxp.frente() << endl;
    p.quitar();
    cout << "\t- Quitado primer elemento de la cola de enteros, el nuevo frente de la cola de enteros es: " << p.frente() << endl;
    cout << "\t- Vaciando cola de enteros..." << endl;
    p.limpiar();
    cout << "\t- Número de elementos en la cola de enteros: " << p.num_elementos() << endl;

    Cola<float> q;
    float aux;

    cout << "\nTRABAJANDO CON UNA COLA DE FLOTANTES: ";
    for (int i = 0; i < 10; i++) {
        aux = i / 10.0;
        q.poner(aux);
        cout << "[" << aux << "]";
    }
    cout << "\n----------------------------------" << endl;
    cout << "\t- Número de elementos en la cola de flotantes: " << q.num_elementos() << endl;
    cout << "\t- El elemento al frente de nuestra cola de flotantes es: " << q.frente() << endl;
    cout << "\t- Creando una copia de la cola de flotantes..." << endl;
    Cola<float> auxq;
    auxq = q;
    q.frente() = 5.5;
    cout << "\t- Elemento al frente de la cola de flotantes cambiado, ahora es: " << q.frente() << endl;
    cout << "\t- Elemento al frente de la copia de la cola de flotantes: " << auxq.frente() << endl;
    q.quitar();
    cout << "\t- Quitado primer elemento de la cola de flotantes, el nuevo frente de la cola de flotantes es: " << q.frente() << endl;
    cout << "\t- Vaciando cola de flotantes..." << endl;
    q.limpiar();
    cout << "\t- Número de elementos en la cola de flotantes: " << q.num_elementos() << endl;

    Cola<char> r;
    char caux = 'a' - 1;

    cout << "\nTRABAJANDO CON UNA COLA DE CARACTERES: ";
    for (int i = 0; i < 10; i++) {
        caux += 1;
        r.poner(caux);
        cout << "[" << caux << "]";
    }
    cout << "\n----------------------------------" << endl;
    cout << "\t- Número de elementos en la cola de caracteres: " << r.num_elementos() << endl;
    cout << "\t- El elemento al frente de nuestra cola de caracteres es: " << r.frente() << endl;
    cout << "\t- Creando una copia de la cola de caracteres..." << endl;
    Cola<char> auxr(r);
    r.frente() = 'z';
    cout << "\t- Elemento al frente de la cola de caracteres cambiado, ahora es: " << r.frente() << endl;
    cout << "\t- Elemento al frente de la copia de la cola de caracteres: " << auxr.frente() << endl;
    r.quitar();
    cout << "\t- Quitado primer elemento de la cola de caracteres, el nuevo frente de la cola de caracteres es: " << r.frente() << endl;
    cout << "\t- Vaciando cola de caracteres..." << endl;
    r.limpiar();
    cout << "\t- Número de elementos en la cola de caracteres: " << r.num_elementos() << endl;

    cout << endl;

    return 0;
}
