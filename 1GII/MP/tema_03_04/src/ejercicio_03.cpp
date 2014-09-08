// Implementar la clase Matriz2D-1.
// 
// Empleando la representacion basica conocida, se trata de implementar los siguientes metodos:
// 
// 	a) Constructor sin argumentos, que crea una matriz vacia.
// 
// 	b) Constructor con dos argumentos, que crea una matriz con el numero de filas indicado en el primer argumento
// 	   y con el numero de columnas indicado en el segundo argumento. Inicia todas las casillas a cero.
// 
// 	c) Constructor con dos argumentos, que crea una matriz con el numero de filas indicado en el primer argumento
// 	   y con el numero de columnas indicado en el segundo argumento. Ademas inicia todas las casillas de la matriz
// 	   al valor especificado con el tercer argumento.
// 
// 	d) Destructor.
// 
// 	e) Metodo (valor devuelto: bool) que consulta si la matriz esta vacia.
// 
// 	f) Metodos para escribir/leer un valor. Responderan a los prototipos:
// 	   void PonValor(int fila, int col, int val);
// 	   int LeeValor(int fila, int col);
// 	   
// Ampliar la clase Matriz2D-1 con los siguientes metodos:
// 
// 	a) Constructor de copia y sobrecarga del operador de asignacion, empleando codigo reutilizable. Reescribir el
// 	   destructor en base a esta estrategia.
// 
// 	b) Una sobrecarga alternativa del operador de asignacion, que recibe como argumento un dato de tipo TipoBase
// 	   e inicia toda la matriz al valor especificado.
// 
// 	c) Sobregargar el operador [] para que sirva de operador de acceso a los elementos de la matriz dinamica y
// 	   pueda actuar tanto como lvalue como rvalue.
// 	   Muy importante: Queremos realizar el acceso aplicando por dos veces el operador [] de manera que si m
// 	   es de tipo Matriz2D-1 podamos acceder a los elementos almacenados con la expresion m[f ][c]
// 
// 	d) Sobregargar los operadores unarios + y -.
// 
// 	e) Sobregargar los operadores relacionales binarios == y != para comparar dos matrices dinamicas: seran iguales
// 	   si tienen el mismo numero de filas y columnas, y los contenidos son iguales y en las mismas posiciones.
// 
// 	f) Sobreescribir el operador << para mostrar el contenido de una matriz dinamica.


#include "Matriz2D-1.h"
#include <iostream>

using namespace std;

int main() {
    Matriz2D_1 matriz1;
    Matriz2D_1 matriz2(2, 3);
    Matriz2D_1 matriz3(4, 5, 10);

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

    Matriz2D_1 matriz4(matriz3);
    cout << "Contenido de matriz4 (copia de matriz3):\n" << matriz4 << endl;

    Matriz2D_1 matriz5;
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
