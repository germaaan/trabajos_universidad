// Implementar la clase Matriz2D-2.
// 
// Empleando la representacion basica conocida, se trata de implementar los mismos metodos que en el problema 3.
// 
// Ampliar la clase Matriz2D-2.
// 
// Empleando la representacion basica conocida, se trata de implementar los mismos metodos que en el problema 3.


#include "Matriz2D-2.h"
#include <iostream>

using namespace std;

int main() {
    Matriz2D_2 matriz1;
    Matriz2D_2 matriz2(2, 3);
    Matriz2D_2 matriz3(4, 5, 10);

    if (matriz1.estaVacia())
        cout << "La matriz1 esta vacia." << endl;
    else
        cout << "La matriz1 no esta vacia." << endl;
    if (matriz2.estaVacia())
        cout << "La matriz2 esta vacia." << endl;
    else
        cout << "La matriz2 no esta vacia." << endl;
    if (matriz3.estaVacia())
        cout << "La matriz3 esta vacia." << endl;
    else
        cout << "La matriz3 no esta vacia." << endl;

    matriz3.PonValor(1, 1, 5);

    cout << "\nValor en matriz3[1][1]: " << matriz3.LeeValor(1, 1) << endl << endl;

    cout << "Contenido de matriz1:\n" << matriz1 << endl;
    cout << "Contenido de matriz2:\n" << matriz2 << endl;
    cout << "Contenido de matriz3:\n" << matriz3 << endl;

    Matriz2D_2 matriz4(matriz3);
    cout << "Contenido de matriz4 (copia de matriz3):\n" << matriz4 << endl;

    Matriz2D_2 matriz5;
    matriz5 = matriz3;
    cout << "Contenido de matriz5 (por asignacion de matriz3):\n" << matriz5 << endl;

    cout << "+matriz3 =\n" << +matriz3 << endl;

    if (matriz4 == matriz5)
        cout << "Las matrices 4 y 5 son iguales." << endl;
    else
        cout << "Las matrices 4 y 5 no son iguales." << endl;

    if (matriz2 != matriz3)
        cout << "Las matrices 2 y 3 no son iguales." << endl;
    else
        cout << "Las matrices 2 y 3 son iguales." << endl;

    cout << endl << endl << endl << endl;

    return (0);
}
