// Escribid una expresion logica que sea verdadera si una variable de tipo caracter
// llamada "letra" es una letra minuscula y falso en otro caso.
//
// Escribid una expresion logica que sea verdadera si una variable de tipo entero llamada
// "edad" es menor de 18 o mayor de 65.
//
// Escribid una expresion logica que nos informe cuando un año es bisiesto. Los años
// bisiestos son aquellos que o bien son divisibles por 4 pero no por 100, o bien son
// divisibles por 400.
//
// Nota: Cuando se imprime por pantalla (con "cout") una expresion logica que es true,
// se imprime 1. Si es false, se imprime un 0. En el tema 2 veremos la razon.
//
// Finalidad: Empezar a trabajar con expresiones logicas, muy usadas en el tema 2.
// Dificultad Baja.

#include <iostream>
using namespace std;

int main() {
    char letra;
    int edad;
    int anio;
    bool comprobar_letra;
    bool comprobar_edad;
    bool comprobar_anio;

    cout << "Introduzca un caracter para comprobar si esta en mayuscula o minuscula: ";
    cin >> letra;

    comprobar_letra = letra > 96;

    cout << "Es minuscula si el valor es 1 y mayuscula si el valor es 0: " << comprobar_letra;

    cout << "\n\nIntroduzca la edad de una persona, para comprobar si es menor de 18 o mayor de 65 años: ";
    cin >> edad;

    comprobar_edad = edad < 18 || edad > 65;

    cout << "Es menor de 18 años o mayor de 65 si el valor es 1, y 0 en caso contrario: " << comprobar_edad;

    cout << "\n\nIntroduzca un año para calcular si es bisiesto: ";
    cin >> anio;

    comprobar_anio = (anio % 4 == 0 && anio % 100 != 0);

    cout << "Es bisiesto si el valor es 1 y 0 en caso contrario: " << comprobar_anio << "\n\n";
}

