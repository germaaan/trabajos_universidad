// Modifique el codigo del problema 3 para controlar el final del bucle con un puntero a la posicion siguiente a la
// ultima.


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int v[1000];
    int *p;
    int *fin;

    fin = v + 1000;

    const int MY_MAX_RAND = 50;
    time_t t;

    srand((int) time(&t));

    for (int i = 0; i < 1000; i++)
        v[i] = (rand() % ((2 * MY_MAX_RAND) + 1)) - MY_MAX_RAND;

    cout << "Vector con valores aleatorios:" << endl;

    for (p = v; p != fin; p++)
        cout << *p << " ";

    for (p = v; p != fin; p++) {
        if (*p < 0)
            *p = (*p) * (-1);
    }

    cout << "\n\nVector sin valores negativos:" << endl;

    for (p = v; p != fin; p++)
        cout << *p << " ";

    cout << "\n\n";
}
