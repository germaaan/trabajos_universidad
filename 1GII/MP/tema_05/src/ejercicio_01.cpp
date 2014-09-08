// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estandar (terminada por EOF)
// y los copie literalmente en la salida estandar.


#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    char cad;

    cout << "Introducir caracter mientras que no se encuentre EOF: " << endl;

    cad = cin.get();

    while (!cin.eof()) {
        cout.put(cad);
        cad = cin.get();
    }
}
