// [maximin] Se pide construir un programa que lea una matriz y que indique si existe algun
// elemento que sea maximo de su fila y minimo de su columna a la vez. En caso afirmativo, el
// programa mostrara la posicion (fila y columna) de dicho elemento. Si existen varios podemos
// devolver uno cualquiera. Si no hay ningun elemento que cumpla la condicion el programa
// mostrara la posicion -1 -1
// 
// Por ejemplo, dada la matriz M (3 × 4),
// 
// 4	9	5	5
// 2	18	2	2
// 7	13	2	5
// 
// el valor 9 que esta en la posicion (0, 1) es maximo de su fila y minimo de su columna (podria
// haber mas).
// 
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
// 3
// 4
// 4 9 5 5
// 2 18 2 2
// 7 13 2 5
// 
// Salida del programa: Dos enteros que representan la fila y columna del elemento buscado.
// 0 1


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

    int obtenerMaxFila(int fila, int columnas) {
        int valorFila;
        int maxValorFila = 0;
        int maxFila = 0;

        for (int j = 0; j < columnas; j++) {
            valorFila = matrizPrivada[fila][j];

            if ((valorFila > maxValorFila) || (maxValorFila == 0)) {
                maxValorFila = valorFila;
                maxFila = j;
            }
        }

        return maxFila;
    }

    int obtenerMinColumna(int columna, int filas) {
        int valorColumna;
        int minValorColumna = 0;
        int minColumna = 0;

        for (int i = 0; i < filas; i++) {
            valorColumna = matrizPrivada[i][columna];

            if ((valorColumna < minValorColumna) || (minValorColumna == 0)) {
                minValorColumna = valorColumna;
                minColumna = i;
            }
        }

        return minColumna;
    }

    int GetValor(int fila, int columna) {
        return matrizPrivada[fila][columna];
    }
};

int main() {
    int filas;
    int columnas;
    int elemento;
    int maxFila;
    int minColumna;
    int posFila = -1;
    int posColumna = -1;
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
        maxFila = matriz.obtenerMaxFila(i, columnas);
        minColumna = matriz.obtenerMinColumna(maxFila, filas);

        if ((matriz.GetValor(i, maxFila)) == (matriz.GetValor(minColumna, maxFila))) {
            posFila = minColumna;
            posColumna = maxFila;
        }
    }

    cout << posFila << " " << posColumna;

    cout << "\n\n";
}
