// Realizad el ejercicio del calculo de la desviacion tipica, pero cambiando el tipo de dato
// de las variables xi a int.
//
// Nota: Para no tener problemas en la llamada a la funcion "pow" (en el caso de que se
// haya utilizado para implementar el cuadrado de las diferencias de los datos con la
// media), obligamos a que la base de la potencia sea un real multiplicando por 1.0, por
// lo que la llamada quedaria en la forma "pow(base*1.0, exponente)
// 
// Finalidad: Trabajar con expresiones numericas que involucren distintos tipos de datos.
// Dificultad Baja.


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int altura1;
    int altura2;
    int altura3;
    double media;
    double desviacion;

    cout << "Introduzca la altura de la primera persona: ";
    cin >> altura1;
    cout << "Introduzca la altura de la segunda persona: ";
    cin >> altura2;
    cout << "Introduzca la altura de la tercera persona: ";
    cin >> altura3;

    media = (altura1 + altura2 + altura3) / 3;
    desviacion = sqrt((pow((altura1 - media) * 1.0, 2) + pow((altura2 - media) * 1.0, 2) + pow((altura3 - media) * 1.0, 2)) / 3);

    cout << "\n\nEl valor de la media aritmetica muestral es: " << media;
    cout << "\nEl valor de la desviacion estandar muestral es: " << desviacion << "\n\n";
}
