// Desarrolle un programa para que lea una secuencia de un numero indefinido de valores double hasta que se
// introduzca un valor negativo. Estos valores (excepto el negativo) los almacenara en una estructura de celdas
// enlazadas y despues mostara los valores almacenados.
// 
// Escribir un programa para solucionar este problema, con dos funciones:
// 
// 	• Una para leer y almacenar los valores.
// 
// 	• Otra para mostrarlos.


#include <iostream>
#include <stdexcept>
using namespace std;

struct Nodo {
    double valor;
    Nodo *siguiente;
};

typedef Nodo *PNodo;
typedef Nodo *Lista;

Lista LeerValores() {
    PNodo inicio = 0, fin, nuevo;
    double valor;

    cout << "Introduzca un valor double (introducir un valor negativo para finalizar): ";
    cin >> valor;

    if (valor >= 0) {

        try {
            inicio = new Nodo;
        } catch (runtime_error excepcion) {
            cout << "Error de memoria: " << excepcion.what();
        }

        inicio->valor = valor;
        inicio->siguiente = 0;

        fin = inicio;

        cout << "Introduzca un valor double (introducir un valor negativo para finalizar): ";
        cin >> valor;

        while (valor >= 0) {

            try {
                nuevo = new Nodo;
            } catch (runtime_error excepcion) {
                cout << "Error de memoria: " << excepcion.what();
            }

            nuevo->valor = valor;

            fin->siguiente = nuevo;
            fin = nuevo;

            cout << "Introduzca un valor double (introducir un valor negativo para finalizar): ";
            cin >> valor;
        }

        fin->siguiente = 0;
    }

    return inicio;
}

void MostrarValores(const Lista valores) {
    PNodo puntero;

    cout << endl;

    cout << "Valores: ";

    for (puntero = valores; puntero != 0; puntero = puntero->siguiente)
        cout << puntero->valor << " ";

    cout << endl;
}

void LiberarMemoriaValores(Lista valores) {
    PNodo puntero, anterior;

    if (valores != 0) {

        anterior = valores;
        puntero = valores->siguiente;

        while (puntero != 0) {
            delete anterior;
            anterior = puntero;
            puntero = puntero->siguiente;
        }

        delete anterior;
    }
}

int main() {
    Lista valores;

    valores = LeerValores();

    MostrarValores(valores);

    LiberarMemoriaValores(valores);

    cout << "\n";

    return (0);
}
