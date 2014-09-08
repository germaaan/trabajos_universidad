// Realizar un programa que lea reales desde teclado y calcule cuantos se han introduci-
// do y cual es el minimo de dichos valores (pueden ser positivos o negativos). Se dejara
// de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de los reales
// dentro de un bucle sobre una unica variable llamada "dato". Es importante controlar los
// casos extremos, como por ejemplo, que el primer valor leido fuese ya el terminador de
// entrada (en este caso, el cero).
// 
// Finalidad: Destacar la importancia de las inicializaciones antes de entrar al bucle.
// Ejemplo de lectura anticipada. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    double dato = 0, minimo = 0;
    int contador = 0;
    bool parada = false;

    while (!parada) {
        cout << "Introduzca un numero real (pulse 0 para salir): ";
        cin >> dato;

        if (dato == 0) {
            parada = true;
        } else {

            if (minimo == 0 || dato < minimo)
                minimo = dato;

            contador++;
        }
    }

    cout << "\nHa introducido " << contador << " numeros.\nEl menor numero introducido ha sido " << minimo << ".";

    cout << "\n\n";
}
