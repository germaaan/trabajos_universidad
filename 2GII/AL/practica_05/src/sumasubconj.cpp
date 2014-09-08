#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void escribe(const vector<int> &S, const vector<int> &s_optima, const int &M, const int &cont) {
    int i;

    cout << "Valores:\t\t";

    for (i = 0; i < S.size(); i++)
        cout << S[i] << " ";

    cout << "\nSolucion óptima:\t";

    if (s_optima.size() > 0)
        for (i = 0; i < s_optima.size(); i++)
            cout << s_optima[i] << " ";
    else
        cout << "IN ";

    cout << "= " << M << endl;

    cout << "Nodos generados:\t" << cont << endl << endl;
}

int elem_seleccionados(const vector<char> &X) {
    int i, cont = 0;

    for (i = 0; i < X.size(); i++)
        if (X[i] == 1)
            cont++;

    return cont;
}

// Funcion de poda.
bool criterio(const vector<int> &S, const int &M, const int &suma) {
    bool valido = true;

    if (suma > M)
        valido = false; // Si la suma de los elementos actuales es mayor que valor buscado, se poda.
    else if ((S.back() + suma) > M)
        valido = false; // Si la suma de los elementos actuales más el elemento de menor valor es mayor que el valor buscado, se poda.

    return valido;
}

// Función para obtener resultado óptimo.
void solucion(int &v_optimo, vector<int> &s_optima, const vector<int> &S, const vector<char> &X, const int &M) {
    int i, solucion = elem_seleccionados(X);

    if (solucion < v_optimo) {
        v_optimo = solucion;

        s_optima.clear();

        for (i = 0; i < X.size(); i++)
            if (X[i] == 1)
                s_optima.push_back(S[i]);
    }
}

void suma_subconj(int i, const vector<int> &S, vector<char> &X, const int &M, int suma, int &cont, int &v_optimo, vector<int> &s_optima) {
    int j;

    for (j = i; j < X.size(); j++) {

        if (criterio(S, M, suma)) {

            cont++;

            if (i < X.size()) {
                X[i] = 1;

                if (suma + S[i] == M)
                    solucion(v_optimo, s_optima, S, X, M);

                suma_subconj(i + 1, S, X, M, suma + S[i], cont, v_optimo, s_optima);

                X[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    int aux1[8] = {0}, aux2[8] = {0}, aux3[8] = {0}, num;
    bool insertado = false;

    srand(time(NULL));

    for (int i = 0; i < 8; i++) {

        while (!insertado) {
            num = 1 + rand() % (21 - 1);

            for (int j = 0; (j < 8) && !insertado; j++)
                if (aux1[j] == num)
                    insertado = true;

            // Si un valor ya se encuentra en el conjunto, forzamos que se vuelva a generar otro valor aleatorio.
            if (insertado)
                insertado = false;
            else {
                aux1[i] = num;
                insertado = true;
            }
        }

        insertado = false;

        while (!insertado) {
            num = 1 + rand() % (21 - 1);

            for (int j = 0; (j < 8) && !insertado; j++)
                if (aux2[j] == num)
                    insertado = true;

            if (insertado)
                insertado = false;
            else {
                aux2[i] = num;
                insertado = true;
            }
        }

        insertado = false;

        while (!insertado) {
            num = 1 + rand() % (21 - 1);

            for (int j = 0; (j < 8) && !insertado; j++)
                if (aux3[j] == num)
                    insertado = true;

            if (insertado)
                insertado = false;
            else {
                aux3[i] = num;
                insertado = true;
            }
        }

        insertado = false;
    }

    vector<int> S1(aux1, aux1 + 8);
    vector<int> S2(aux2, aux2 + 8);
    vector<int> S3(aux3, aux3 + 8);

    // Los ordenamos en orden descendente, porque en caso contrario, nuestra función de poda no funcionará correctamente.
    sort(S1.begin(), S1.end());
    reverse(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    reverse(S2.begin(), S2.end());
    sort(S3.begin(), S3.end());
    reverse(S3.begin(), S3.end());

    int aux21[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int aux22[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int aux23[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

    vector<char> X1(aux21, aux21 + 8);
    vector<char> X2(aux22, aux22 + 8);
    vector<char> X3(aux23, aux23 + 8);

    int M = 30;
    int cont1 = 1, cont2 = 1, cont3 = 1;
    int v_optimo1 = (S1.size() + 1), v_optimo2 = (S2.size() + 1), v_optimo3 = (S3.size() + 1);

    vector<int> s_optima1, s_optima2, s_optima3;

    suma_subconj(0, S1, X1, M, 0, cont1, v_optimo1, s_optima1);
    suma_subconj(0, S2, X2, M, 0, cont2, v_optimo2, s_optima2);
    suma_subconj(0, S3, X3, M, 0, cont3, v_optimo3, s_optima3);

    escribe(S1, s_optima1, M, cont1);
    escribe(S2, s_optima2, M, cont2);
    escribe(S3, s_optima3, M, cont3);

    return 0;
}