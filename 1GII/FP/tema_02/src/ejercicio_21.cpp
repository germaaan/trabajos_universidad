// El metodo RLE (Run Length Encoding) codifica una secuencia de datos formada por
// series de valores identicos consecutivos como una secuencia de parejas de numeros
// (valor de la secuencia y numero de veces que se repite). Esta codificacion es un
// mecanismo de compresion de datos (zip) sin perdidas. Se aplica, por ejemplo, para
// comprimir los ficheros de imagenes en las que hay zonas con los mismos datos (fondo
// blanco, por ejemplo). Realizar un programa que lea una secuencia de numeros naturales
// terminada con un numero negativo y la codifique mediante el metodo RLE. Leed
// los datos desde un fichero externo.
//
// 	Entrada: 1 1 1 2 2 2 2 2 3 3 3 3 3 3 5 -1
//			 (tres veces 1, cinco veces 2, seis veces 3, una vez 5)
//
//	Salida:  31526315
//
// Finalidad: Controlar en una iteracion lo que ha pasado en la anterior. Dificultad Media.

#include <iostream>
using namespace std;

int main() {

    int entero, enteroAnterior;
    char caracter1, caracter2;
    int repeticiones;


    cout << "\nVoy a leer un enteros hasta leer un numero negativo.\n";
    cout << "\n\n";

    repeticiones = 1;
    cin >> entero;
    enteroAnterior = -1;
    while (entero >= 0) {
        if (enteroAnterior == entero) {
            repeticiones++;
        } else {
            if (enteroAnterior>-1)
                cout << repeticiones << " " << enteroAnterior << " ";
            enteroAnterior = entero;
            repeticiones = 1;
        }
        cin >> entero;
    }
    if (enteroAnterior >= 0)
        cout << repeticiones << enteroAnterior;

    cout << "\n\n";
}
