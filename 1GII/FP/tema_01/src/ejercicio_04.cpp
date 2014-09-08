// Cread un programa que nos pida la longitud del radio, calcule el area del circulo y
// la longitud de la circunferencia correspondientes, y nos muestre los resultados en
// pantalla. Recordad que:
//
// 	long. circunf = 2 * π * r				area circ = π * (r²)
//
// Usad el literal "3.1416" a lo largo del codigo, cuando se necesite multiplicar por π.
// Una vez hecho el programa, cambiad las apariciones de "3.1416" por "3.14159", 
// recompilad y ejecutad (La parte de compilacion y ejecucion se realizara cuando se vea
// en clase de practicas el entorno de programacion).
//
// ¿No hubiese sido mejor declarar un dato constante PI con un valor igual a "3.14159",
// y usar dicho dato donde fuese necesario? Hacedlo tal y como se explica en las 
// transparencias de los apuntes de clase.
// 
// Cambiad ahora el valor de la constante PI por el de "3.145927", recompilad y ejecu-
// tad.
//
// Finalidad: Entender la importancia de las constantes. Dificultad Baja.

#include <iostream>
using namespace std;

int main() {
    const double PI = 3.145927;
    double radio;
    double longitud;
    double area;

    cout << "Introduzca el valor del radio de la circunferencia: ";
    cin >> radio;

    longitud = 2 * 3.1416 * radio;
    area = 3.1416 * (radio * radio);

    cout << "\nEl valor de la longitud de la circunferencia es: " << longitud;
    cout << "\nEl valor del area de la circunferencia es: " << area << "\n\n";
}
