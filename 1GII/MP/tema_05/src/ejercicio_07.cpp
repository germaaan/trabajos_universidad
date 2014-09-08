// Escribir un programa que lea una serie indefinida de numeros enteros de la entrada estandar (terminada por
// EOF) y los copie, en orden inverso, en la salida estandar.
//
// 	· En la secuencia de entrada se pueden usar espacios, tabuladores o saltos de lineas (en cualquier numero y
//	  combinacion) para separar dos numeros enteros consecutivos.
//
// 	· En la secuencia de salida se separan dos enteros consecutivos con un salto de linea.
//
// 	· Usar un objeto Pila para invertir la secuencia.


#include <iostream>
#include "Pila.h"

using namespace std;

int main(int argc, char **argv) {
    const int TAM_BUFFER = 100;
    char buffer[TAM_BUFFER];
    Pila pila;
    bool primero = false;
    char valor;
    int i = 0;

    while (!cin.eof()) {
        cin >> valor;
        pila.push(valor);

        i = 0;
        primero = false;

        while (buffer[i] != '\0') {
            if ((buffer[i] >= '0') && (buffer[i] <= '9')) {
                cout << buffer[i];
                primero = true;
            } else if (primero == true) {
                cout << '\n';
                primero = false;
            }

            i++;
        }
    }

    return (0);
}
