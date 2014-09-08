// Ampliad el ejercicio 7 de la relacion de problemas I, para que, una vez calculada la
// media y la desviacion, el programa imprima por cada uno de los valores introducidos
// previamente, si esta por encima o por debajo de la media. Por ejemplo:
// 
//	33 es menor que su media
//	48 es mayor o igual que su media
// 	......
// 
// Nota. Los valores introducidos son enteros, pero la media y la desviación son reales.
// Finalidad: Plantear un ejemplo basico con varias estructuras condicionales indepen-


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double altura1;
    double altura2;
    double altura3;
    double media;
    double desviacion;

    cout << "Introduzca la altura de la primera persona: ";
    cin >> altura1;
    cout << "Introduzca la altura de la segunda persona: ";
    cin >> altura2;
    cout << "Introduzca la altura de la tercera persona: ";
    cin >> altura3;

    media = (altura1 + altura2 + altura3) / 3;
    desviacion = sqrt((pow(altura1 - media, 2) + pow(altura2 - media, 2) + pow(altura3 - media, 2)) / 3);

    cout << "\nEl valor de la media aritmotica muestral es: " << media;
    cout << "\nEl valor de la desviacion estandar muestral es: " << desviacion << "\n\n";

    if (altura1 < media)
        cout << "La altura de la primera persona: " << altura1 << ", es menor que la media." << endl;
    else
        cout << "La altura de la primera persona: " << altura1 << ", es igual o mayor que la media." << endl;

    if (altura2 < media)
        cout << "La altura de la segunda persona: " << altura2 << ", es menor que la media." << endl;
    else
        cout << "La altura de la segunda persona: " << altura2 << ", es igual o mayor que la media." << endl;

    if (altura3 < media)
        cout << "La altura de la tercera persona: " << altura3 << ", es menor que la media.\n" << endl;
    else
        cout << "La altura de la tercera persona: " << altura3 << ", es igual o mayor que la media.\n" << endl;

    cout << "\n\n";
}
