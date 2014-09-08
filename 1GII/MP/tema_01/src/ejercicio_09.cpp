// Implemente las siguientes funciones sobre cadenas de caracteres “clasicas”:
//
//	a) Funcion longitud_cadena. Devuelve un entero con la longitud (numero de caracteres sin contar el nulo)
// 	   de la cadena.
// 
// 	b) Funcion comparar_cadenas. Compara dos cadenas. Devuelve un valor negativo si la primera es mas 
// 	   "pequeña”, positivo si es mas “grande” y cero si son “iguales”.
//
//	c) Funcion copiar_cadena. Copia una cadena de caracteres en otra. El resultado es el primer argumento.
//
//	d) Funcion encadenar_cadena. Añade una cadena de caracteres al final de otra. El resultado es el primer
//	   argumento.
//
// Se supone que hay suficiente memoria en las cadenas de destino y no es necesario pasar el tamaño de las 
// cadenas (recordad que el caracter nulo delimita el final de la cadena).


#include <iostream>
using namespace std;

int longitud_cadena(char *ptr_cadena) {
    int contador = 0;

    while (*ptr_cadena != '\0') {
        ptr_cadena++;
        contador++;
    }

    return contador;
}

int comparar_cadenas(char *ptr_cadena_1, char *ptr_cadena_2) {
    int comparacion;

    while ((*ptr_cadena_1 == *ptr_cadena_2) && ((*ptr_cadena_1 != '\0') || (*ptr_cadena_2 != '\0'))) {
        ptr_cadena_1++;
        ptr_cadena_2++;
    }

    if (*ptr_cadena_1 == *ptr_cadena_2)
        comparacion = 0;
    else if (*ptr_cadena_1 < *ptr_cadena_2)
        comparacion = -1;
    else
        comparacion = 1;

    return comparacion;
}

char* copiar_cadena(char *ptr_cadena_1, char *ptr_cadena_2) {
    char *puntero = ptr_cadena_1;

    while (*ptr_cadena_2 != '\0') {
        *puntero = *ptr_cadena_2;

        puntero++;
        ptr_cadena_2++;
    }

    *puntero = '\0';

    return ptr_cadena_1;
}

char* encadenar_cadena(char *ptr_cadena_1, char *ptr_cadena_2) {
    char *puntero = ptr_cadena_1;

    while (*puntero != '\0')
        puntero++;

    *puntero = ' ';
    puntero++;

    while (*ptr_cadena_2 != '\0') {
        *puntero = *ptr_cadena_2;

        puntero++;
        ptr_cadena_2++;
    }

    *puntero = '\0';

    return ptr_cadena_1;
}

int main() {
    const int TAMANIO = 100;
    char cadena_1[TAMANIO];
    char cadena_2[TAMANIO];
    int longitud_1, longitud_2, comparacion;

    cout << "Introduzca primera cadena: ";
    cin.getline(cadena_1, TAMANIO);

    cout << "Introduzca segunda cadena: ";
    cin.getline(cadena_2, TAMANIO);

    longitud_1 = longitud_cadena(cadena_1);
    longitud_2 = longitud_cadena(cadena_2);

    cout << "\nLongitud de la primera cadena: " << longitud_1 << endl;
    cout << "Longitud de la segunda cadena: " << longitud_2 << endl;

    comparacion = comparar_cadenas(cadena_1, cadena_2);

    if (comparacion == 0)
        cout << "\nLas dos cadenas son igual de grandes lexicograficamente." << endl;
    else if (comparacion < 0)
        cout << "\nLa segunda cadena es la mas grande lexicograficamente." << endl;
    else
        cout << "\nLa primera cadena es la mas grande lexicograficamente." << endl;

    encadenar_cadena(cadena_1, cadena_2);
    cout << "\nCadenas concatenadas: " << cadena_1 << endl;

    copiar_cadena(cadena_1, cadena_2);
    cout << "\nCadena copiada: " << cadena_1 << endl;

    cout << "\n";
}
