// [cercana] Dada una matriz y un vector de enteros, al que llamaremos referencia, se pide
// buscar la fila de la matriz que mas se parece al vector. La similitud entre dos vectores x =
// (x1 ··· xp) e y = (y1 ··· yp) vendra dada por la distancia euclidea entre ambos:
// 
// 	dist(x,y) = √((x1 − y1)² + ··· + (xp − yp)²)
// 
// Ademas, la busqueda solo se hara sobre las filas de la matriz enumeradas en un segundo vector
// llamado filas_a_comparar.
// 
// Por ejemplo, dada la matriz M(7×4),
// 
// 	→	3 1 0 8
// 	  	4 5 1 5 
// 	→	5 7 1 7
// 		7 9 6 1
// 	→	2 8 2 2
// 	→	7 3 2 5
// 
// y los vectores referencia = 2, 8, 1, 1 y filas_a_comparar = 0, 2, 4, 5, el programa
// debera encontrar 5 como la fila mas cercana al vector referencia. En el dibujo anterior se
// han marcado con una flecha las filas indicadas por el vector filas_a_comparar.
// 
// Consideraciones:
// 
// 	a) Se debe comprobar que el tamaño de los vectores y la matriz son adecuados.
// 
// 	b) Se debe comprobar que los numeros de fila indicados en el vector filas_a_comparar
// 	   son correctos.
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
// Los datos de entrada al programa se deben dar en el siguiente orden:
// 
// 	a) Numero de elementos del vector referencia (que coincide con el numero de columnas
// 	   de la matriz).
// 
// 	b) Elementos del vector referencia: una secuencia de numeros enteros.
// 
// 	c) Numero de elementos del vector filas_a_comparar.
// 
// 	d) Elementos del vector filas_a_comparar: una secuencia de numeros enteros.
// 
// 	e) Numero de filas de la matriz M .
// 
// 	f) Numero de columnas de la matriz M .
// 
// 	g) Los elementos de la matriz (primero se da la fila 0, luego la fila 1, y asi sucesivamente):
// 	   una secuencia de numeros enteros.
// 
// Ejemplo de fichero de validacion:
// 	4
// 	2 8 1 1
// 	4
// 	0 2 4 5
// 	7 4
// 	3 1 0 8
// 	4 5 1 5
// 	5 7 1 7
// 	7 9 6 1
// 	4 9 5 5
// 	2 8 2 2
// 	7 3 2 5
// 
// Salida del programa: El entero que representa la fila mas cercana.
// 	5


#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class Matriz {
private:
    static const int TAMANIO = 50;
    int matrizPrivada[TAMANIO][TAMANIO];
    int vectorReferencia[TAMANIO];
    int vectorFilasComparar[TAMANIO];
    int totalFilasUtilizadas;
    int totalColumnasUtilizadas;
    int totalUtilizadosReferencia;
    int totalUtilizadosFilasComparar;

    double CalcularDistanciaEuclidea(int fila, int numColumnas) {
        double distanciaEuclidea = 0;

        for (int j = 0; j < numColumnas; j++)
            distanciaEuclidea = distanciaEuclidea + pow((vectorReferencia[j] - matrizPrivada[fila][j]) * 1.0, 2);

        distanciaEuclidea = sqrt(distanciaEuclidea);

        return distanciaEuclidea;
    }

public:

    Matriz()
    : totalFilasUtilizadas(0),
    totalColumnasUtilizadas(0),
    totalUtilizadosReferencia(0),
    totalUtilizadosFilasComparar(0) {
    }

    void AniadeMatriz(int numColumnas, int valor) {
        if ((totalFilasUtilizadas < TAMANIO) && (totalColumnasUtilizadas < TAMANIO)) {
            matrizPrivada[totalFilasUtilizadas][totalColumnasUtilizadas] = valor;

            totalColumnasUtilizadas++;

            if (totalColumnasUtilizadas == numColumnas) {
                totalFilasUtilizadas++;
                totalColumnasUtilizadas = 0;
            }
        } else
            throw logic_error("No hay suficientes componentes.");
    }

    void AniadeVector(int vector, int valor) {
        if (vector == 0) {

            if (totalUtilizadosReferencia < TAMANIO) {
                vectorReferencia[totalUtilizadosReferencia] = valor;

                totalUtilizadosReferencia++;
            } else
                throw logic_error("No hay suficientes componentes.");
        } else if (vector == 1) {

            if (totalUtilizadosFilasComparar < TAMANIO) {
                vectorFilasComparar[totalUtilizadosFilasComparar] = valor;

                totalUtilizadosFilasComparar++;
            } else
                throw logic_error("No hay suficientes componentes.");

        } else
            throw logic_error("Vector al que añadir componente no valido.");

    }

    int ObtenerFilaMasCercana(int numColumnas) {
        int filaMasCercana = -1;
        double distanciaEuclidea = 0.0;
        double distanciaEuclideaMinima = 0.0;

        for (int i = 0; i < totalUtilizadosFilasComparar; i++) {

            if (vectorFilasComparar[i] < totalFilasUtilizadas) {
                distanciaEuclidea = CalcularDistanciaEuclidea(vectorFilasComparar[i], numColumnas);

                if ((distanciaEuclidea < distanciaEuclideaMinima) || (distanciaEuclideaMinima == 0.0)) {
                    distanciaEuclideaMinima = distanciaEuclidea;
                    filaMasCercana = vectorFilasComparar[i];
                }
            } else
                throw logic_error("Fila seleccionada para comparacion no valida.");
        }

        return filaMasCercana;
    }
};

int main() {
    int elementosReferencia;
    int componenteReferencia;
    int elementosFilasComparar;
    int componenteFilasComparar;
    int filas;
    int columnas;
    int componenteMatriz;
    int i;
    int filaMasCercana;

    Matriz matriz;

    cin >> elementosReferencia;

    for (i = 0; i < elementosReferencia; i++) {
        cin >> componenteReferencia;

        try {
            matriz.AniadeVector(0, componenteReferencia);
        } catch (logic_error excepcion) {
            cout << "Error logico: " << excepcion.what();
        }
    }

    cin >> elementosFilasComparar;

    for (i = 0; i < elementosFilasComparar; i++) {
        cin >> componenteFilasComparar;

        try {
            matriz.AniadeVector(1, componenteFilasComparar);
        } catch (logic_error excepcion) {
            cout << "Error logico: " << excepcion.what();
        }
    }

    cin >> filas;
    cin >> columnas;

    if (elementosReferencia == columnas) {
        for (i = 0; i < (filas * columnas); i++) {
            cin >> componenteMatriz;

            try {
                matriz.AniadeMatriz(columnas, componenteMatriz);
            } catch (logic_error excepcion) {
                cout << "Error logico: " << excepcion.what();
            }
        }

        filaMasCercana = matriz.ObtenerFilaMasCercana(columnas);
    } else
        filaMasCercana = -1;

    cout << filaMasCercana;

    cout << "\n\n";
}
