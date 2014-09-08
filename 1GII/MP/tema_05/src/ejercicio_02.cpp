// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estandar (terminada por EOF)
// y los copie en la salida estandar, exceptuando las vocales.


#include <iostream>

using namespace std;

int main() {
    char cad;

    cout << "Introducir caracter mientras que no se encuentre EOF (no se muestran las vocales): " << endl;

    cad = cin.get();

    while (!cin.eof()) {
        if ((cad != 'a') && (cad != 'e') && (cad != 'i') && (cad != 'o') && (cad != 'u') && (cad != 'A') && (cad != 'E') && (cad != 'I') && (cad != 'O') && (cad != 'U'))
            cout.put(cad);
        cad = cin.get();
    }
}
