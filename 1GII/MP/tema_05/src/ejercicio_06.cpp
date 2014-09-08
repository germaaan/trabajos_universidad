// Escribir un programa que lea una serie indefinida de numeros enteros de la entrada estandar (terminada por
// EOF) y los copie, en el mismo orden, en la salida estandar.
// 
// 	· En la secuencia de entrada se pueden usar espacios, tabuladores o saltos de lineas (en cualquier numero y
// 	  combinacion) para separar dos numeros enteros consecutivos.
// 
// 	· En la secuencia de salida se separan dos enteros consecutivos con un salto de linea.


#include <iostream>

using namespace std;

int main() {
    const int TAM_BUFFER = 100;
    char buffer[TAM_BUFFER];
    bool primero = false;
    int i = 0;

    while (!cin.eof()) {
        cin.getline(buffer, TAM_BUFFER);
        cout << buffer << endl;

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
