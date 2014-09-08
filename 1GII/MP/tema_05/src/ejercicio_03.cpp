// Escribir un programa que que lea una secuencia indefinida de caracteres de la entrada estandar (terminada por
// EOF) y muestre en la salida estandar el numero total de caracteres leidos.


#include <iostream>

using namespace std;

int main() {
    char cad;
    int cont = 0;

    cout << "Introducir caracter mientras que no se encuentre EOF: " << endl;

    cad = cin.get();

    while (!cin.eof()) {
        cont += cin.gcount();
        cad = cin.get();
    }

    cout << endl;
    cout << "Numero total de caracteres introducidos: " << cont << endl;
}
