//Leed desde teclado tres variables correspondientes a un numero de horas, minutos
//y segundos, respectivamente. Diseñar un algoritmo que calcule las horas, minutos
//y segundos dentro de su rango correspondiente. Por ejemplo, dadas 10 horas, 119
//minutos y 280 segundos, deberia dar como resultado 12 horas, 3 minutos y 40 
//segundos. En el caso de que nos salgan mas de 24 horas, daremos tambien los dias
//correspondientes (pero ya no pasamos a ver los meses, años, etc)
// Como consejo, utilizad el operador ✴ que cuando trabaja sobre datos enteros, 
// representa la division entera. Para calcular el resto de la division entera, usad 
// el operador %.
//
// Finalidad: Trabajar con expresiones numericas y con variables para no repetir compu-
// tos. Dificultad Media.


#include<iostream>
using namespace std;

int main() {
    int dias;
    int horas;
    int minutos;
    int segundos;

    cout << "Introduzca el numero de horas: ";
    cin >> horas;
    cout << "Introduzca el numero de minutos: ";
    cin >> minutos;
    cout << "Introduzca el numero de segundos: ";
    cin >> segundos;

    minutos = minutos + (segundos / 60);
    segundos = segundos % 60;

    horas = horas + (minutos / 60);
    minutos = minutos % 60;

    dias = horas / 24;
    horas = horas % 24;

    cout << "\nLos valores introducidos equivalen a: " << dias << " dias, " << horas << " horas, " << minutos << " minutos y " << segundos << " segundos.\n";
}
