// Queremos realizar un programa para intercambiar los contenidos de dos variables
// enteras. El programa leera desde teclado dos variables "edad_Pedro" y "edad_Juan"
// e intercambiara sus valores. A continuacion, mostrara en pantalla las variables ya
// modificadas. El siguiente codigo no funciona correctamente.
//
// 	edad_Pedro = edad_Juan;
// 	edad_Juan = edad_Pedro;
//
// ¿Por que no funciona? Buscad una solucion.
//
// Finalidad: Entender como funciona la asignacion entre variables. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    int edad_Pedro;
    int edad_Juan;
    int copia;

    cout << "Introduzca la edad de Pedro: ";
    cin >> edad_Pedro;
    cout << "Introduzca la edad de Juan: ";
    cin >> edad_Juan;

    copia = edad_Pedro;
    edad_Pedro = edad_Juan;
    edad_Juan = copia;

    cout << "\nLas edades de Pedro y Juan han sido intercambiadas.";
    cout << "\nEdad de Pedro: " << edad_Pedro;
    cout << "\nEdad de Juan: " << edad_Juan << "\n\n";
}
