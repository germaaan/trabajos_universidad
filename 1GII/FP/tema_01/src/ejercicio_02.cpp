// Un banco presenta la siguiente oferta. Si se deposita una cantidad de euros "capital"
// durante un año a plazo fijo, se dara un interes dado por la variable "interes". Realizad
// un programa que lea una cantidad "capital" y un interes "interes" desde teclado y
// calcule en una variable "total" el dinero que se tendra al cabo de un año, aplicando la
// formula:
// 
// 	total = capital + capital * (interes/100)
//
// Es importante destacar que el compilador primero evaluara la expresion de la parte
// derecha de la anterior asignacion (usando el valor que tuviese la variable "capital") y
// a continuacion ejecutara la asignacion, escribiendo el valor resultante de la expresion
// dentro de la variable "total").
//
// A continuacion, el programa debe imprimir en pantalla el valor de la variable "total".
// Tanto el capital como el interes seran valores reales. Supondremos que el usuario
// introduce el interes como un valor real entre 0 y 100, es decir, un interes del 5,4%
// se introducira como 5.4. Tambien supondremos que lo introduce correctamente, es
// decir, que solo introducira valores entre 0 y 100.
//
// Supongamos que queremos modificar la variable original "capital" con el nuevo valor
// de "total". ¿Es posible hacerlo directamente en la expresion de arriba?
// 
// Nota: El operador de division en C++ es /
//
// Finalidad: Resolver un problema real sencillo, usando varias sentencias. Dificultad
// Baja.


#include <iostream>
using namespace std;

int main() {
    double capital;
    double interes;
    double total;

    cout << "Introduzca la cantidad en euros a depositar: ";
    cin >> capital;
    cout << "Introduzca porcentaje de interes a aplicar: ";
    cin >> interes;

    total = capital + capital * (interes / 100);

    cout << "\nEl valor del total de capital acumulado sera: " << total << "\n\n";
}
