// Consideremos una cadena de caracteres “clasica”. Escriba un trozo de codigo que lea una cadena y la imprima
// pero saltandose la primera palabra, evitando escribirla caracter a caracter.
// 
// Considere que puede haber una o mas palabras, y si hay mas de una palabra, estan separadas por espacios en
// blanco.


#include <iostream>
using namespace std;

int main() {

    const int TAMANIO = 100;
    char cadena[TAMANIO], *p;
    bool encontrado = false;

    cout << "Introduzca texto: ";
    cin.getline(cadena, TAMANIO);

    for (p = cadena; (*p != '\0') && !encontrado; p++) {

        if (*p == ' ') {
            encontrado = true;
            cout << "\nPrimera palabra de la cadena eliminada. Resultado:\n" << p + 1 << endl;
        }

    }

    cout << "\n";
}
