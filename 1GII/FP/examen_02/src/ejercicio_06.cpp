// [ordenar] Escriba un programa para ordenar las filas de una matriz de enteros positivos. Para
// hacer dicha ordenacion, debemos calcular la media de los valores de cada fila. A continuacion
// ordenaremos las filas de la matriz de acuerdo a los valores de sus medias (de menor a mayor).
// Por ejemplo, dada la siguiente matriz:
// 
// 	1	5	32	5
// 	3	22	8	4
// 	5	0	10	9
// 	1	20	17	8
// 	16	11	0	2
// 
// Las medias de las filas (de arriba a abajo) son 10.75, 9.25, 6, 11.5, y 7.25 respectivamente.
// Entonces, la matriz ordenada deberia quedar asi:
// 
// 	5	0	10	9
// 	16	11	0	2
// 	3	22	8	4
// 	1	5	32	5
// 	1	20	17	8
// 
// Los datos de entrada al programa se deben dar en el siguiente orden: Numero de filas, numero
// de columnas, datos de la matriz (primero la fila 0, luego la fila 1, etc.).
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
// 	5 4
// 	1 5 32 5
// 	3 22 8 4
// 	5 0 10 9
// 	1 20 17 8
// 	16 11 0 2
// 
// Salida del programa: El tamaño de la matriz y las componentes de la matriz por filas:
// 	5 4
// 	5 0 10 9
// 	16 11 0 2
// 	3 22 8 4
// 	1 5 32 5
// 	1 20 17 8


#include <iostream>
#include <stdexcept>
using namespace std;

class Matriz {
private:
    static const int TAMANIO = 50;
    int vectorPrivado[TAMANIO][TAMANIO];
    double vectorMedias[TAMANIO];
    int totalUtilizadosFila;
    int totalUtilizadosColumna;
    int totalUtilizadosMedias;

    void IntercambiarFilas(int columnas, int a, int b) {
        int intercambio;

        intercambio = vectorMedias[a];
        vectorMedias[a] = vectorMedias[b];
        vectorMedias[b] = intercambio;

        for (int j = 0; j < columnas; j++) {
            intercambio = vectorPrivado[a][j];
            vectorPrivado[a][j] = vectorPrivado[b][j];
            vectorPrivado[b][j] = intercambio;
        }
    }

public:

    Matriz()
    : totalUtilizadosFila(0),
    totalUtilizadosColumna(0),
    totalUtilizadosMedias(0) {
    }

    void Aniade(int numColumnas, int valor) {
        if (totalUtilizadosColumna < TAMANIO) {
            vectorPrivado[totalUtilizadosFila][totalUtilizadosColumna] = valor;
            totalUtilizadosColumna++;

            if (totalUtilizadosColumna == numColumnas) {
                totalUtilizadosFila++;
                totalUtilizadosColumna = 0;
            }
        } else
            throw logic_error("No hay suficientes componentes.");
    }

    void ordenarPorFilas(int filas, int columnas) {
        double valorMedioFila = 0.0;
        int i;
        int j;
        int izda;
        int dcha;
        bool cambio = true;

        for (i = 0; i < filas; i++) {
            valorMedioFila = 0.0;

            for (j = 0; j < columnas; j++)
                valorMedioFila = valorMedioFila + (vectorPrivado[i][j])*1.0;

            valorMedioFila = valorMedioFila / (columnas * 1.0);

            vectorMedias[totalUtilizadosMedias] = valorMedioFila;
            totalUtilizadosMedias++;
        }

        for (izda = 0; (izda < totalUtilizadosMedias) && cambio; izda++) {
            cambio = false;

            for (dcha = (totalUtilizadosMedias - 1); dcha > izda; dcha--) {
                if (vectorMedias[dcha] < vectorMedias[dcha - 1]) {
                    IntercambiarFilas(columnas, dcha, (dcha - 1));

                    cambio = true;
                }
            }
        }

    }

    int GetValor(int fila, int columna) {
        return vectorPrivado[fila][columna];
    }
};

int main() {
    int filas;
    int columnas;
    int valorAniadir;

    Matriz matriz;

    cin >> filas;
    cin >> columnas;

    for (int i = 0; i < (filas * columnas); i++) {
        cin >> valorAniadir;

        try {
            matriz.Aniade(columnas, valorAniadir);
        } catch (logic_error excepcion) {
            cout << "Error logico: " << excepcion.what();
        }
    }

    try {
        matriz.ordenarPorFilas(filas, columnas);
    } catch (logic_error excepcion) {
        cout << "Error logico: " << excepcion.what();
    }

    cout << "\n\n";

    cout << filas << " " << columnas << endl;

    for (int i = 0; i < filas; i++) {

        for (int j = 0; j < columnas; j++)
            cout << matriz.GetValor(i, j) << " ";

        cout << endl;
    }

    cout << "\n\n";
}
