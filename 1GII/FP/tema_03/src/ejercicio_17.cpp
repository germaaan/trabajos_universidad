// Cread una clase para representar fracciones. El numerador y denominador seran enteros
// y debe proporcionar un metodo para normalizar la fraccion, es decir, encontrar
// la fraccion irreducible que sea equivalente. Para ello, tendra que dividir el numerador
// y denominador por su maximo comun divisor.
//
// Finalidad: Diseñar la interfaz de una clase. Dificultad Media.


#include <iostream>
using namespace std;

class Fracciones {
private:
    int numerador;
    int denominador;

    int MaximoComunDivisor() {
        bool hay_divisores, mcd_encontrado;
        int divisor, mcd = 0;

        if ((numerador == 0) || (denominador == 0))
            mcd = 0;
        else {

            if (numerador > denominador)
                divisor = denominador;
            else
                divisor = numerador;

            hay_divisores = true;
            mcd_encontrado = false;

            while (hay_divisores && !mcd_encontrado) {
                if (divisor == 1) {
                    hay_divisores = false;
                    mcd = 1;
                } else {

                    if ((numerador % divisor == 0) && (denominador % divisor == 0)) {
                        mcd_encontrado = true;
                        mcd = divisor;
                    }
                    else {
                        divisor--;
                    }
                }
            }
        }

        return mcd;
    }
public:

    Fracciones(int valor_numerador, int valor_denominador)
    : numerador(valor_numerador),
    denominador(valor_denominador) {
    }

    int getNumerador() {
        return numerador;
    }

    int getDenominador() {
        return denominador;
    }

    void NormalizarFraccion() {
        int mcd = MaximoComunDivisor();

        numerador = numerador / mcd;
        denominador = denominador / mcd;
    }
};

int main() {
    int valorNumerador;
    int valorDenominador;

    do {
        cout << "Introduzca el valor del numerador: ";
        cin >> valorNumerador;
    } while (valorNumerador == 0);

    do {
        cout << "Introduzca el valor del denominador: ";
        cin >> valorDenominador;
    } while (valorDenominador == 0);

    Fracciones fraccion(valorNumerador, valorDenominador);
    fraccion.NormalizarFraccion();

    cout << "\nValor de la fraccion normalizada: " << fraccion.getNumerador() << "/" << fraccion.getDenominador() << endl;

    cout << "\n";
}
