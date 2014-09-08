// [maxminimos] Se pide construir un programa que lea una matriz y que calcule la posicion de
// aquel elemento que sea el mayor de entre los minimos de cada fila. El programa mostrara la
// posicion de dicho elemento (fila y columna).
// 
// Por ejemplo, dada la matriz M (3 × 4),
// 
// 	9	7	4	5
// 	2	18	2	12
// 	7	9	1	5
// 
// el maximo entre 4, 2 y 1 (los minimos de cada fila) es 4 que se encuentra en la posicion (0, 2).
// Los datos de entrada al programa se deben dar en el siguiente orden:
// 
// 	a) Numero de filas de la matriz.
// 
// 	b) Numero de columnas de la matriz.
// 
// 	c) Los elementos de la matriz.
// 
// Restricciones del problema:
// 
// 	a) Debe implementar una clase “Matriz”. Dicha clase debe incorporar la funcionalidad ne-
// 	   cesaria para resolver el problema.
// 
// 	b) No se admitira que la entrada o la salida de datos se realice dentro de la clase que incorpora
// 	   la funcionalidad para resolver este problema. Esas operaciones se resolveran fuera de la
// 	   clase.
// 
// Ejemplo de fichero de validacion:
// 	3
// 	4
// 	9 7 4 5
// 	2 18 2 12
// 	7 9 1 5
// 
// Salida del programa: Dos enteros que representan la fila y columna del elemento buscado:
// 	0 2


#include <iostream>
#include <stdexcept>
using namespace std;

class Matriz {
private:
    static const int TAMANIO = 50;
    int matrizPrivada[TAMANIO][TAMANIO];
    int totalFilasUtilizadas;
    int totalColumnasUtilizadas;

public:

    Matriz()
    : totalFilasUtilizadas(0),
    totalColumnasUtilizadas(0) {
    }

    void Aniade(int numColumnas, int valor) {
        if ((totalFilasUtilizadas < TAMANIO) && (totalColumnasUtilizadas < TAMANIO)) {
            matrizPrivada[totalFilasUtilizadas][totalColumnasUtilizadas] = valor;

            totalColumnasUtilizadas++;

            if (totalColumnasUtilizadas == numColumnas) {
                totalFilasUtilizadas++;
                totalColumnasUtilizadas = 0;
            }
        } else
            throw logic_error("No hay suficientes componentes");
    }

    int obtenerMinFila(int fila, int columnas) {
        int valorFila;
        int minValorFila = 0;
        int minFila = 0;

        for (int j = 0; j < columnas; j++) {
            valorFila = matrizPrivada[fila][j];

            if ((valorFila < minValorFila) || (minValorFila == 0)) {
                minValorFila = valorFila;
                minFila = j;
            }
        }

        return minFila;
    }
};

int main() {
    int filas;
    int columnas;
    int elemento;
    int minFila;
    int maximoMinimo = 0;
    int posFila = 0;
    int posColumna = 0;
    int i;

    Matriz matriz;

    cin >> filas;
    cin >> columnas;

    for (i = 0; i < (filas * columnas); i++) {
        cin >> elemento;

        try {
            matriz.Aniade(columnas, elemento);
        } catch (logic_error excepcion) {
            cout << "Error logico: " << excepcion.what();
        }
    }

    for (i = 0; i < filas; i++) {
        minFila = matriz.obtenerMinFila(i, columnas);

        if (minFila > maximoMinimo) {
            maximoMinimo = minFila;
            posFila = i;
            posColumna = minFila;
        }

    }

    cout << posFila << " " << posColumna;

    cout << "\n\n";
}
