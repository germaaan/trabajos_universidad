// Escriba una funcion a la que le damos una cadena de caracteres, una posicion de inicio p y una longitud l. Como
// resultado, devuelve una subcadena que comienza en p y que tiene longitud l.
// 
// Nota: Si la longitud es demasiado grande (se sale de la cadena original), se devolvera una cadena de menor
// tamaño. No se debe usar el operador [], es decir, se debe resolver mediante aritmetica de punteros.


#include <iostream>
using namespace std;

char* subcadena(char *cadena, int p, int l) {
    char *puntero;
    int tamanio = 0;

    for (puntero = cadena; *puntero != '\0'; puntero++)
        tamanio++;

    puntero = cadena;

    if ((cadena + tamanio) >= (cadena + p + l)) {
        puntero = puntero + p;
        *(puntero + l) = '\0';
    } else {
        puntero = puntero + p;
        *(puntero + tamanio) = '\0';
    }

    return puntero;
}

int main() {
    const int TAMANIO = 100;
    char cadena[TAMANIO];
    char *puntero;
    int p;
    int l;

    cout << "Introduzca cadena: ";
    cin.getline(cadena, TAMANIO);

    cout << "Introduzca la posicion de inicio de la subcadena: ";
    cin >> p;

    cout << "Introduzca longitud de la subcadena: ";
    cin >> l;

    puntero = subcadena(cadena, p, l);

    cout << "\nSubcadena obtenida: ";
    cout << puntero;

    cout << "\n\n";
}
