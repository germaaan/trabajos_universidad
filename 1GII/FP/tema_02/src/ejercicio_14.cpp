// Se pide leer un caracter desde teclado, obligando al usuario a que sea una letra ma-
// yúscula. Para ello habrá que usar una estructura repetitiva "do while", de forma que
// si el usuario introduce un carácter que no sea una letra mayúscula, se le volvera a
// pedir otro carácter. Calculad la minúscula correspondiente e imprimidla en pantalla.
// No pueden usarse las funciones "tolower" ni "toupper" de la biblioteca "cctype". Si se
// quiere, se puede usar como base el proyecto que resolvio el ejercicio 14 de la relacion
// de problemas I.
//
// Finalidad: Trabajar con bucles con condiciones compuestas. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    char letra_original, letra_convertida;
    const int AMPLITUD = 'a' - 'A';

    do {
        cout << "Introduzca una letra mayuscula: ";
        cin >> letra_original;
    } while (letra_original < 'A' || letra_original > 'Z');

    letra_convertida = letra_original + AMPLITUD;

    cout << "\nLetra introducida convertida a minuscula: " << letra_convertida;

    cout << "\n\n";
}
