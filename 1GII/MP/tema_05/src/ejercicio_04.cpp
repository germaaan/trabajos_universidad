// Escribir un programa que que lea una secuencia indefinida de caracteres de la entrada estandar (terminada por
// EOF) y muestre en la salida estandar el numero de lineas no vacias que hay en esa secuencia.
// 
// Nota: Se entendera que una linea es vacia si contiene u ́ nicamente el caracter ’\n’


#include <iostream>

using namespace std;

int main() {
    const int TAM_BUFFER = 100;
    char buffer[TAM_BUFFER];
    int cont = 0;

    cout << "Introducir caracter mientras que no se encuentre EOF: " << endl;
    cin.getline(buffer, TAM_BUFFER);

    while (!cin.eof()) {

        if (cin.gcount() > 1)
            cont++;

        cin.getline(buffer, TAM_BUFFER);
    }

    cout << endl;
    cout << "Numero de lineas no vacias en la secuencia: " << cont << endl;
}
