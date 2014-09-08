// Deseamos guardar un numero indefinido de valores double (como en el problema 4). Despues de la lectura (usar
// la misma funcion que el problema 4) se realiza el calculo de la media y la varianza, y finalmente se muestran
// estos valores.
// 
// Realice tres funciones, para:
// 
// 	a) calcular el numero de celdas enlazadas.
// 
// 	b) calcular la media.
// 
// 	c) calcular la varianza.


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

    cout << endl << endl;
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

int CalcularCeldasEnlazadas(const Lista valores) {
    int contador = 0;

    for (PNodo puntero = valores; puntero != 0; contador++, puntero = puntero->siguiente);

    return contador;
}

double CalcularMedia(const Lista valores) {
    double suma = 0.0;
    int num_elementos = CalcularCeldasEnlazadas(valores);

    for (PNodo puntero = valores; puntero != 0; suma = suma + puntero->valor, puntero = puntero->siguiente);

    return (suma / num_elementos);
}

double CalcularVarianza(const Lista valores) {
    PNodo puntero = valores;
    double suma = 0.0;
    int num_elementos = CalcularCeldasEnlazadas(valores);
    double media = CalcularMedia(valores);

    while (puntero != 0) {
        double dif = puntero->valor - media;
        double sqrdif = dif*dif;

        suma = suma + sqrdif;
        puntero = puntero->siguiente;
    }

    return (suma / num_elementos);
}

int main() {
    Lista valores;
    int num_celdas;
    double media, varianza;

    valores = LeerValores();

    MostrarValores(valores);

    num_celdas = CalcularCeldasEnlazadas(valores);
    media = CalcularMedia(valores);
    varianza = CalcularVarianza(valores);

    cout << "Hay " << num_celdas << " celdas enlazadas." << endl;
    cout << "\nEl valor medio es " << media << endl;
    cout << "El valor de la varianza " << varianza << endl;

    LiberarMemoriaValores(valores);

    cout << "\n";

    return (0);
}
