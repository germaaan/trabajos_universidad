// Sobre la solucion del ejercicio 12 de esta relacion de problemas, se pide lo siguiente.
// Supondremos que solo pueden introducirse intereses enteros (1, 2, 3, etc). Se pide
// calcular el capital obtenido al termino de cada año, pero realizando los calculos para
// todos los tipos de interes enteros menores o iguales que el introducido (en pasos de
// 1). Por ejemplo, si el usuario introduce un interes de 5, y un numero de años igual a 3,
// hay que mostrar el capital ganado al termino de cada uno de los tres años a un interes
// del 1 %; a continuacion, lo mismo para un interes del 2 %, y asi sucesivamente hasta
// llegar al 5 %. El programa debe mostrar una salida del tipo:
// 
// 	Calculos realizados al 1%:
// 
// 		Dinero obtenido en el año n�mero 1 = 2020
// 		Dinero obtenido en el año n�mero 2 = 2040.2
// 		Dinero obtenido en el año n�mero 3 = 2060.6
// 
// 	C�lculos realizados al 2%:
// 
// 		Dinero obtenido en el año n�mero 1 = 2040
// 		Dinero obtenido en el año n�mero 2 = 2080.0
// 		Dinero obtenido en el año n�mero 3 = 2122.42
// 
// 	........
// 
// Finalidad: Empezar a trabajar con bucles anidados. Dificultad Baja.


#include <iostream>
using namespace std;

int main() {
    float capital, capitalAcumulado;
    int interes, interesReducido, topeAnios, anio;

    cout << "Dame el capital " << endl;
    cin >> capital;
    cout << "Dame el interes " << endl;
    cin >> interes;
    cout << "Dame el numero de anios " << endl;
    cin >> topeAnios;

    for (interesReducido = 1; interesReducido <= interes; interesReducido++) {
        capitalAcumulado = capital;
        cout << " Calculos realizados al " << interesReducido << "%" << endl;
        for (anio = 1; anio <= topeAnios; anio++) {
            capitalAcumulado = capitalAcumulado + capitalAcumulado * interesReducido / 100.0;
            cout << "\tCapital para el anio " << anio << ": " << capitalAcumulado << endl;
        }
    }

    cout << "\n\n";
}
