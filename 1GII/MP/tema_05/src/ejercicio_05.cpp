// Escribir un programa que que lea una secuencia indefinida de caracteres de la entrada estandar (terminada por
// EOF) y copie en la salida estandar las lineas que no comiencen por el caracter #


#include <iostream>

using namespace std;

int main() {

    const int TAM_BUFFER = 100;
    char buffer[TAM_BUFFER];

    cout << "Introducir caracter mientras que no se encuentre EOF: " << endl;
    cin.getline(buffer, TAM_BUFFER);

    while (!cin.eof()) {
        if (buffer[0] != '#')
            cout << buffer << endl;

        cin.getline(buffer, TAM_BUFFER);
    }

    cout << endl;
}
