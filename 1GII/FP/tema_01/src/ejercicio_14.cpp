// Diseñar un programa que lea un caracter (supondremos que el usuario introduce una
// mayuscula), lo pase a minuscula y lo imprima en pantalla. Hacedlo sin usar las 
// funciones "toupper" ni "tolower" de la biblioteca "cctype". Para ello, debe considerarse
// la equivalencia en C++ entre los tipos enteros y caracteres.
//
// Finalidad: Entender la equivalencia de C++ entre tipos enteros y de caracter. Dificultad
// Baja.

#include <iostream>
using namespace std;

int main() {
    char letra;

    cout << "Introduzca un caracter en mayuscula para pasarlo a minuscula: ";
    cin >> letra;

    //letra = letra + 32;
    letra = letra + 'l' - 'L';

    cout << "Caracter introducido en mayuscula convertido a minuscula: " << letra << "\n\n";
}
