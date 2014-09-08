// Se desea una funcion que reciba un vector de numeros enteros junto 
// con su longitud y que devuelva un puntero al elemento mayor.
// 
// Escriba dos versiones:
// 
// 	a) Devuelve el resultado como resultado de la funcion (return).
// 
// 	b) Devuelve el resultado a traves de un parametro (funcion void).
// 
// Considere la siguiente declaracon:
// 
// 	int vector [100];
// 	int usados;			// 0 <= usados < 100
// 
// Haga uso de la primera funcion para mostrar en la salida estandar:
// 
// 	a) El elemento mayor del vector.
// 
// 	b) El elemento mayor de la primera mitad.
// 
// 	c) El elemento mayor de la segunda mitad.


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int obtener_mayor_v1(int *vector, int longitud) {
    int mayor = 0;
    int *puntero;

    for (puntero = vector; puntero < (vector + longitud); puntero++) {

        if (*puntero > mayor)
            mayor = *puntero;

    }

    return mayor;
}

void* obtener_mayor_v2(int *vector, int longitud) {
    int *mayor = vector;
    int *puntero;

    *mayor = 0;

    for (puntero = vector; puntero < (vector + longitud); puntero++) {

        if (*puntero > *mayor)
            mayor = puntero;

    }

    return mayor;
}

int main() {
    int vector[100];
    int usados = 0;
    int mayor;

    const int MY_MAX_RAND = 100;
    int *p_inicio;

    time_t t;

    srand((int) time(&t));

    for (int i = 0; i < 20; i++) {
        vector[i] = (rand() % MY_MAX_RAND);
        usados++;
    }

    cout << "Valores del vector:" << endl;
    for (p_inicio = vector; p_inicio < (vector + usados); p_inicio++)
        cout << *p_inicio << " ";

    p_inicio = vector;
    mayor = obtener_mayor_v1(p_inicio, usados);
    cout << "\nMayor valor del vector: " << mayor << endl;

    cout << "\nValores de la primera mitad del vector: " << endl;
    for (p_inicio = vector; p_inicio < (vector + (usados / 2)); p_inicio++)
        cout << *p_inicio << " ";

    p_inicio = vector;
    mayor = obtener_mayor_v1(p_inicio, (usados / 2));
    cout << "\nMayor valor de la primera mitad: " << mayor << endl;

    cout << "\nValores de la segunda mitad del vector: " << endl;
    for (p_inicio = (vector + (usados / 2)); p_inicio < (vector + usados); p_inicio++)
        cout << *p_inicio << " ";

    p_inicio = (vector + (usados / 2));
    mayor = obtener_mayor_v1(p_inicio, (usados / 2));
    cout << "\nMayor valor de la segunda mitad: " << mayor << endl;

    cout << "\n\n";
}
