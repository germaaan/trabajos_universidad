#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void escribe(const vector<int> &S, const int &M, vector< vector<int> > &tabla, vector<int> &solucion) {
    int i, j, k;

    cout << "\n\nConjunto de enteros S = {";
    for (k = 0; k < S.size(); k++) {
        if (k == S.size() - 1) {
            cout << S[k] << "}";
        } else {
            cout << S[k] << ",";
        }
    }

    cout << "\tValor M = " << M << "\n\nTabla resultado:" << endl;

    for (j = 0; j < tabla[0].size(); j++) {
        cout << setw(4) << j;
    }

    cout << endl;

    for (i = 0; i < tabla.size(); i++) {
        for (j = 0; j < tabla[0].size(); j++) {

            if (tabla[i][j] == M + 1) {
                cout << setw(4) << "IN";
            } else {
                cout << setw(4) << tabla[i][j];
            }
        }

        cout << endl;
    }

    //El valor óptimo es tabla[S.size()-1][M], por lo que si este tiene el valor inicial, no hay solución.
    if (tabla[S.size() - 1][M] == M + 1) {
        cout << "\nNo es posible obtener el valor exacto de M mediante la combinacion de valores del conjunto S.";
    } else {
        cout << "\nSe puede obtener el valor exacto de M mediante la combinación mínima de " << tabla[S.size() - 1][M] << " valores del conjunto S: ";

        for (i = 0; i < solucion.size(); i++) {
            cout << solucion[i] << " ";
        }
    }

    cout << endl;
}

void suma_subconjuntos(const vector<int> &S, const int &M, vector< vector<int> > &tabla, vector<int> &solucion) {
    int i, j;

    //Caso base de valor 0 para la primera columna
    for (i = 0; i < S.size(); i++) {
        tabla[i][0] = 0;
    }

    //Caso base de valor 1 para la primera fila
    for (j = 1; j < M + 1; j++) {
        if (j == S[0]) {
            tabla[0][j] = 1;
        }
    }

    //Rellenamos la tabla
    for (i = 1; i < S.size(); i++) {
        for (j = 1; j < M + 1; j++) {

            if (j < S[i]) {
                tabla[i][j] = tabla[i - 1][j];
            } else {

                //Aplicamos la ecuación
                if (tabla[i - 1][j] < tabla[i - 1][j - S[i]] + 1) {
                    tabla[i][j] = tabla[i - 1][j];
                } else {
                    tabla[i][j] = tabla[i - 1][j - S[i]] + 1;
                }
            }
        }
    }

    //Recomponemos la solución óptima
    j = M;

    for (i = S.size() - 1; i > 0; i--) {

        if (i == 1) {
            solucion.push_back(S[0]);
        } else if (tabla[i][j] != tabla[i - 1][j]) {
            solucion.push_back(S[i]);
            j = j - S[i];
        }
    }
}

int main() {
    int valores[8] = {24, 15, 13, 11, 10, 8, 7, 1};
    int valores2[8] = {1, 7, 8, 10, 11, 13, 15, 24};
    vector<int> S(valores, valores + 8);
    vector<int> S2(valores2, valores2 + 8);

    int M = 31;

    vector< vector<int> > tabla(8, vector<int>(M + 1, M + 1));
    vector< vector<int> > tabla2(8, vector<int>(M + 1, M + 1));
    vector<int> solucion;
    vector<int> solucion2;

    suma_subconjuntos(S, M, tabla, solucion);
    escribe(S, M, tabla, solucion);

    suma_subconjuntos(S2, M, tabla2, solucion2);
    escribe(S2, M, tabla2, solucion2);

    return 0;
}