// Supongamos que para definir matrices bidimensionales dinamicas usamos una estructura tipo Matriz2D-1.
// En los apuntes de clase se detalla como crear y liberar esta estructura.
// 
//	a) Construir un modulo que lea fils×cols valores y los copie en la matriz.
//
//	b) Construir un modulo que muestre los valores guardados en la matriz.
//
//	c) Construir un modulo que reciba una matriz de ese tipo, cree y devuelva una copia.
//
//	d) Construir un modulo que extraiga una submatriz de una matriz bidimensional Matriz2D-1. Como argumento
//	   de la funcion se introduce desde que fila y columna y hasta que fila y columna se debe realizar la
//	   copia de la matriz original. La submatriz devuelta es una nueva matriz.
//
//	e) Construir un modulo que elimine una fila de una matriz bidimensional Matriz2D-1. Obviamente, no se
//	   permiten “huecos” (filas vac ́ıas).
//
//	f) Construir un modulo como el anterior, pero que en vez de eliminar una fila, elimine una columna.
//
//	g) Construir un modulo que devuelva la traspuesta de una matriz. La matriz devuelta es una nueva matriz.
//
//	h) Construir un modulo que reciba una matriz y la modifique, de tal manera que “invierta” las filas: la primera
//	   sera la u ́ ltima, la segunda la penultima, y as ́ı sucesivamente.


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cstring>
using namespace std;

int** CrearMatriz(int filas, int columnas) {
    int **matriz;

    try {
        matriz = new int*[filas];
    } catch (runtime_error excepcion) {
        cout << "Error de memoria: " << excepcion.what();
    }

    for (int i = 0; i < filas; i++) {
        try {
            matriz[i] = new int[columnas];
        } catch (runtime_error excepcion) {
            cout << "Error de memoria: " << excepcion.what();
        }
    }

    return matriz;
}

void LiberarMatriz(char *mensaje, int **matriz, int filas, int columnas) {
    cout << mensaje << endl << endl;

    for (int i = 0; i < filas; i++)
        delete [] matriz[i];

    delete [] matriz;
}

int** ObtenerValores(int filas, int columnas) {
    int **matriz = CrearMatriz(filas, columnas);

    const int MAX = 100;

    time_t t;

    srand((int) time(&t));

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = rand() % MAX;

    return matriz;
}

void MostrarValores(char *mensaje, int **matriz, int filas, int columnas) {
    cout << "\n" << mensaje << endl;

    for (int i = 0; i < filas; i++) {
        cout << "Fila " << i << ": ";

        for (int j = 0; j < columnas; j++)
            cout << setw(3) << matriz[i][j];

        cout << endl;
    }

    cout << endl;
}

int** CopiarMatriz(int **matriz, int filas, int columnas) {
    int **copia = CrearMatriz(filas, columnas);

    for (int i = 0; i < filas; i++)
        memcpy(copia[i], matriz[i], columnas * sizeof (int));

    return copia;
}

int** ObtenerSubmatriz(int **matriz, int fila_inicio, int columna_inicio, int fila_final, int columna_final) {
    int num_filas = fila_final - fila_inicio + 1;
    int num_columnas = columna_final - columna_inicio + 1;

    int **submatriz = CrearMatriz(num_filas, num_columnas);

    for (int i_sub = 0, i_mat = fila_inicio; i_sub < num_filas; i_mat++, i_sub++)
        memcpy(submatriz[i_sub], &(matriz[i_mat][columna_inicio]), (num_columnas) * sizeof (int));

    return submatriz;
}

int** EliminarFila(int** matriz, int filas, int columnas, int fila_borrar) {
    int **matriz_final = CrearMatriz(filas - 1, columnas);
    int fila_reducida = 0;

    for (int i = 0; i < fila_borrar; i++, fila_reducida++)
        memcpy(matriz_final[fila_reducida], matriz[i], columnas * sizeof (int));

    for (int i = fila_borrar + 1; i < filas; i++, fila_reducida++)
        memcpy(matriz_final[fila_reducida], matriz[i], columnas * sizeof (int));

    return matriz_final;
}

int** EliminarColumna(int** matriz, int filas, int columnas, int columna_borrar) {
    int **matriz_final = CrearMatriz(filas, columnas - 1);

    for (int i = 0; i < filas; i++) {
        memcpy(matriz_final[i], matriz[i], columna_borrar * sizeof (int));

        memcpy(&(matriz_final[i][columna_borrar]), &(matriz[i][columna_borrar + 1]), (columnas - columna_borrar - 1) * sizeof (int));
    }

    return matriz_final;
}

int **ObtenerTraspuesta(int **matriz, int filas, int columnas) {
    int filas_t = columnas;
    int columnas_t = filas;
    int **traspuesta = CrearMatriz(filas_t, columnas_t);

    for (int i = 0; i < filas_t; i++)
        for (int j = 0; j < columnas_t; j++)
            traspuesta[i][j] = matriz[j][i];

    return traspuesta;
}

int **InvertirFilas(int **matriz, int filas, int columnas) {
    int **invertida = CopiarMatriz(matriz, filas, columnas);

    int *aux;

    for (int inicio = 0, final = filas - 1; inicio < final; inicio++, final--) {
        aux = invertida[inicio];
        invertida[inicio] = invertida[final];
        invertida[final] = aux;
    }

    return invertida;
}

int main() {
    int filas, columnas, fila_inicio, fila_final, columna_inicio, columna_final, fila_borrar, columna_borrar;

    cout << "Introduzca numero de filas: ";
    cin >> filas;
    cout << "Introduzca numero de columnas: ";
    cin >> columnas;

    int **matriz = ObtenerValores(filas, columnas);

    MostrarValores("Valores aleatorios almacenados en la matriz: ", matriz, filas, columnas);

    int **copia = CopiarMatriz(matriz, filas, columnas);

    MostrarValores("Valores de la matriz copiada: ", copia, filas, columnas);

    LiberarMatriz("Liberando memoria de matriz copiada...", copia, filas, columnas);

    cout << "\nIntroduzca fila inicio submatriz: ";
    cin >> fila_inicio;
    cout << "Introduzca fila final submatriz: ";
    cin >> fila_final;
    cout << "\nIntroduzca columna inicio submatriz: ";
    cin >> columna_inicio;
    cout << "Introduzca columna final submatriz: ";
    cin >> columna_final;

    int **submatriz = ObtenerSubmatriz(matriz, fila_inicio, fila_final, columna_inicio, columna_final);

    MostrarValores("Valores de la submatriz obtenida: ", submatriz, (fila_final - fila_inicio + 1), (columna_final - columna_inicio + 1));

    LiberarMatriz("Liberando memoria de submatriz generada...", submatriz, (fila_final - fila_inicio + 1), (columna_final - columna_inicio + 1));

    cout << "\nIntroduzca el numero de la fila a borrar: ";
    cin >> fila_borrar;

    int **matriz_fila_borrada = EliminarFila(matriz, filas, columnas, fila_borrar);

    MostrarValores("Valores de la matriz con fila borrada: ", matriz_fila_borrada, filas - 1, columnas);

    LiberarMatriz("Liberando memoria de matriz con una fila borrada...", matriz_fila_borrada, filas - 1, columnas);

    cout << "\nIntroduzca el numero de la columna a borrar: ";
    cin >> columna_borrar;

    int **matriz_columna_borrada = EliminarColumna(matriz, filas, columnas, columna_borrar);

    MostrarValores("Valores de la matriz con columna borrada: ", matriz_columna_borrada, filas, columnas - 1);

    LiberarMatriz("Liberando memoria de matriz con una columna borrada...", matriz_columna_borrada, filas, columnas - 1);

    int **traspuesta = ObtenerTraspuesta(matriz, filas, columnas);

    MostrarValores("Valores de la matriz traspuesta: ", traspuesta, filas, columnas);

    LiberarMatriz("Liberando memoria de matriz traspuesta...", traspuesta, filas, columnas);

    int **invertida = InvertirFilas(matriz, filas, columnas);

    MostrarValores("Valores de la matriz invertida: ", invertida, filas, columnas);

    LiberarMatriz("Liberando memoria de matriz invertida...", invertida, filas, columnas);

    LiberarMatriz("Liberando memoria de matriz original...", matriz, filas, columnas);

    cout << "\n";

    return (0);
}
