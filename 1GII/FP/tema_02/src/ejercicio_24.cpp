// Se dice que un numero natural es feliz si cumple que si sumamos los cuadrados de
// sus digitos y seguimos el proceso con los resultados obtenidos, finalmente obtenemos
// uno (1) como resultado. Por ejemplo, el numero 203 es un numero feliz ya que 2² +
// 0² + 3² = 13 → 1² + 3² = 10 → 1² + 0² = 1.
//
// Se dice que un numero es feliz de grado k si se ha podido demostrar que es feliz en
// un maximo de k iteraciones. Se entiende que una iteracion se produce cada vez que
// se elevan al cuadrado los digitos del valor actual y se suman. En el ejemplo anterior,
// 203 es un numero feliz de grado 3 (ademas, es feliz de cualquier grado mayor o igual
// que 3)
//
// Escribir un programa que diga si un numero natural n es feliz para un grado k dado
// de antemano. Tanto n como k son valores introducidos por el usuario.
//
// Finalidad: Ejercitar los bucles anidados. Dificultad Media.

#include <iostream>
using namespace std;

int main() {
    int tope_ciclos, ciclo, num_digitos;
    int n, n_copia, suma, n_div_10, ultimo_digito;
    bool es_feliz, tope_ciclos_alcanzado;

    cout << "\nIntroduzca el entero a comprobar si es feliz: ";
    cin >> n;
    cout << "\nIntroduzca el tope de ciclos permitido: ";
    cin >> tope_ciclos;

    n_copia = n;
    ciclo = 0;
    es_feliz = false;
    tope_ciclos_alcanzado = false;

    while (!es_feliz && !tope_ciclos_alcanzado) {
        n_div_10 = n_copia;
        suma = 0;

        while (n_div_10 != 0) {
            ultimo_digito = n_div_10 % 10;
            suma = suma + ultimo_digito * ultimo_digito;
            n_div_10 = n_div_10 / 10;
        }

        ciclo++;

        if (suma == 1)
            es_feliz = true;
        else
            if (ciclo == tope_ciclos)
            tope_ciclos_alcanzado = true;
        else
            n_copia = suma;
    }

    if (es_feliz)
        cout << "\nEs Feliz";
    else
        cout << "\nNo es Feliz";
    cout << "\n\n";
}
