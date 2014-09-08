// Implementar la clase Racional para trabajar con numeros fraccionarios de la forma a/b donde a y b son numeros
// enteros.
// 
// Proponer una representacion para la clase e implementar los siguientes metodos:
// 
// 	a) Constructor sin argumentos, que inicia un numero racional con valor cero.
// 
// 	b) Constructor que crea un racional a partir de un numero entero.
// 
// 	c) Constructor que crea un racional a partir de dos enteros: el primero sera el numerador y el segundo el
// 	   denominador.
// 
// 	d) Destructor.
// 
// 	e) Metodos para leer/escribir el valor del numerador/denominador.
// 
// 	f) Metodo para escribir de manera “natural” en la salida estandar un numero racional (separando numerador
// 	   y denominador con una barra inclinada /)
// 
// Ampliar la clase Racional con los siguientes metodos:
// 
// 	a) Sobregargar los operadores unarios + y -.
// 
// 	b) Sobregargar los operadores aritmeticos binarios +, -, * y / para poder operar entre dos racionales y racionales
// 	   con enteros (en cualquier orden).
// 
// 	c) Sobregargar los operadores aritmeticos binarios +=, -=, *= y /=.
// 
// 	d ) Sobregargar los operadores relacionales binarios ==, !=, >, < , >= y <= para poder comparar racionales con
// 	   racionales y racionales con enteros (en cualquier orden).
// 
// 	e) Sobreescribir los operadores << y >> para insertar un numero racional en un flujo y extraer un numero
// 	   racional de un flujo. La insercion/extraccion se realizara de la siguiente manera. Si r es un dato de la clase
// 	   Racional:
// 
// 		· Si r contiene el valor 3/5, la instrucion cout << r mostrara 3/5
// 
// 		· La ejecucion de cin >> r hara que se lea una cadena de caracteres y se procese adecuadamente para
// 	  	  aislar el numerador y el denominador (usar como referencia el caracter /).
// 	  	  La cadena no puede contener espacios en blanco.
// 	  	  Por ejemplo, cuando el usuario escriba 3/5 se procesara esa palabra y r tomara el valor 3/5.


#include "Racional.h"
#include <iostream>

using namespace std;

int main() {
    Racional numero1;
    Racional numero2(2);
    Racional numero3(3, 4);
    Racional numero4(2, 3);
    Racional numero5();

    cout << "Valor del primer numerador: " << numero1.getNumerador() << endl;
    cout << "Valor del primer denominador: " << numero1.getDenominador() << endl;
    cout << "Valor del segundo numerador: " << numero2.getNumerador() << endl;
    cout << "Valor del segundo denominador: " << numero2.getDenominador() << endl;
    cout << "Valor del tercer numerador: " << numero3.getNumerador() << endl;
    cout << "Valor del tercer denominador: " << numero3.getDenominador() << endl;

    numero1.setNumerador(1);
    numero2.setDenominador(4);

    cout << "\nNumeros racionales: " << endl;
    numero1.mostrar();
    numero2.mostrar();
    numero3.mostrar();

    cout << "\nOperaciones: " << endl;

    cout << "+" << numero3 << " = " << +numero3 << endl;
    cout << "-" << numero3 << " = " << -numero3 << endl;

    cout << numero3 << " + " << numero4 << " = " << (numero3 + numero4) << endl;
    cout << 3 << " + " << numero4 << " = " << (3 + numero4) << endl;
    cout << numero3 << " + " << 2 << " = " << (numero3 + 2) << endl;

    cout << numero3 << " - " << numero4 << " = " << (numero3 - numero4) << endl;
    cout << 3 << " - " << numero4 << " = " << (3 - numero4) << endl;
    cout << numero3 << " - " << 2 << " = " << (numero3 - 2) << endl;

    cout << numero3 << " * " << numero4 << " = " << (numero3 * numero4) << endl;
    cout << 3 << " * " << numero4 << " = " << (3 * numero4) << endl;
    cout << numero3 << " * " << 2 << " = " << (numero3 * 2) << endl;

    cout << numero3 << " / " << numero4 << " = " << (numero3 / numero4) << endl;
    cout << 3 << " / " << numero4 << " = " << (3 / numero4) << endl;
    cout << numero3 << " / " << 2 << " = " << (numero3 / 2) << endl;

    cout << numero3 << " += " << numero4 << " = " << (numero3 += numero4) << endl;

    cout << numero3 << " -= " << numero4 << " = " << (numero3 -= numero4) << endl;

    cout << numero3 << " *= " << numero4 << " = " << (numero3 *= numero4) << endl;

    cout << numero3 << " /= " << numero4 << " = " << (numero3 /= numero4) << endl;

    cout << numero3 << " == " << numero4 << " = " << (numero3 == numero4) << endl;
    cout << 3 << " == " << numero4 << " = " << (3 == numero4) << endl;
    cout << numero3 << " == " << 2 << " = " << (numero3 == 2) << endl;

    cout << numero3 << " != " << numero4 << " = " << (numero3 != numero4) << endl;
    cout << 3 << " != " << numero4 << " = " << (3 != numero4) << endl;
    cout << numero3 << " != " << 2 << " = " << (numero3 != 2) << endl;

    cout << numero3 << " > " << numero4 << " = " << (numero3 > numero4) << endl;
    cout << 3 << " > " << numero4 << " = " << (3 > numero4) << endl;
    cout << numero3 << " > " << 2 << " = " << (numero3 > 2) << endl;

    cout << numero3 << " < " << numero4 << " = " << (numero3 < numero4) << endl;
    cout << 3 << " < " << numero4 << " = " << (3 < numero4) << endl;
    cout << numero3 << " < " << 2 << " = " << (numero3 < 2) << endl;

    cout << numero3 << " >= " << numero4 << " = " << (numero3 >= numero4) << endl;
    cout << 3 << " >= " << numero4 << " = " << (3 >= numero4) << endl;
    cout << numero3 << " >= " << 2 << " = " << (numero3 >= 2) << endl;

    cout << numero3 << " <= " << numero4 << " = " << (numero3 <= numero4) << endl;
    cout << 3 << " <= " << numero4 << " = " << (3 <= numero4) << endl;
    cout << numero3 << " <= " << 2 << " = " << (numero3 <= 2) << endl;

    cout << endl << endl << endl << endl;

    return (0);
}
