// Supongamos el siguiente codigo:
//	int entero;
//	char caracter;
//
//	caracter = '7';
//	entero = caracter;
//
// La variable entero almacenara el valor "55" (el orden en la tabla ASCII del caracter
// '7'). Queremos construir una expresion que devuelva el entero '7', para asignarlo a la
// variable "entero". Formalmente:
//
// Supongamos una variable "car" de tipo caracter que contiene un valor entre '0' y '9'.
// Construid un programa que obtenga el correspondiente valor entero, se lo asigne a
// una variable de tipo "int" llamada "entero" y lo imprima en pantalla. Por ejemplo, si la
// variable "car" contiene '7' queremos asignarle a "entero" el valor numerico '7'.
// 
// Nota. La comilla simple para representar un literal de caracter es la que hay en el
// teclado del ordenador debajo de la interrogacion ?.
// 
// Finalidad: Entender la equivalencia de C++ entre tipos enteros y de caracter. Dificultad
// Baja.


#include <iostream>
using namespace std;

int main() {
    char car;
    int entero;

    cout << "Introduzca un numero entre el 0 y el 9: ";
    cin >> car;

    //entero = car - 48;
    entero = car - '0';

    cout << "Se ha introducido el numero: " << entero << "\n\n";
}
