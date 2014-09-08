// Redactar un algoritmo para calcular la media aritmetica muestral y la desviacion
// estandar (o tipica) muestral de las alturas de tres personas. estos valores seran reales
// (de tipo "double")
// X = (1/3) * (Σ3,i=1 xi) , σ = √((1/3) * (Σ3,i=1 xi-X)²)
// X representa la media aritmetica y σ la desviacion estandar. Para resolver este 
// problema es necesario usar la funcion "sqrt" (raiz cuadrada) que se encuentra en la 
// biblioteca "cmath".
// 
// Finalidad: Trabajar con expresiones numericas y con variables para no repetir 
// computos. Dificultad Baja.
//


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

    cout << "\n\nEl valor de la media aritmetica muestral es: " << media;
    cout << "\nEl valor de la desviacion estandar muestral es: " << desviacion << "\n\n";
}
