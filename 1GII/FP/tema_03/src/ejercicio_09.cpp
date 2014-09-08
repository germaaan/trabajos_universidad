// Cread una clase llamada "ParejaEnteros" que represente una pareja de enteros
// cualesquiera. Añadid un constructor y los metodos que se estimen oportunos para
// asignarles valores a los enteros y para devolver el valor que tengan. Las operaciones
// que pueden realizarse sobre el conjunto de estos dos valores son calcular el mayor,
// el menor, comprobar si se dividen, ver quien es el dividendo y quien el divisor, inter-
// cambiarlos y calcular el maximo comun divisor. Cread un "main" que llame a dichos
// metodos, para comprobar que estan bien implementados.
// 
// ¿Le añadiria a la clase "ParejaEnteros" un metodo para calcular el factorial de un
// numero? ¿Por que?
//
// Finalidad: Diseñar la interfaz de una clase. Dificultad Baja.


#include <iostream>
using namespace std;

class ParejaEnteros {
private:
    int uno;
    int dos;

public:

    ParejaEnteros(int primero = 0, int segundo = 0)
    : uno(primero),
    dos(segundo) {
    }

    void setPrimero(int primero) {
        uno = primero;
    }

    void setSegundo(int segundo) {
        dos = segundo;
    }

    int getPrimero() {
        return uno;
    }

    int getSegundo() {
        return dos;
    }

    int Mayor() {
        int mayor = uno;

        if (dos > mayor)
            mayor = dos;

        return mayor;
    }

    int Menor() {
        int menor = uno;

        if (dos < menor)
            menor = dos;

        return menor;
    }

    bool Divisibles(int primero, int segundo) {
        bool son_divisibles = false;

        if (primero % segundo == 0)
            son_divisibles = true;

        return son_divisibles;
    }

    int Dividendo() {
        int dividendo;

        if (Divisibles(uno, dos))
            dividendo = uno;
        else
            dividendo = dos;

        return dividendo;
    }

    int Divisor() {
        int divisor;

        if (Divisibles(uno, dos))
            divisor = dos;
        else
            divisor = uno;

        return divisor;
    }

    void Intercambio() {
        int copia_temporal;

        copia_temporal = uno;
        uno = dos;
        dos = copia_temporal;
    }

    int MaximoComunDivisor() {
        int primero = uno;
        int segundo = dos;
        int mcd = 1;
        int i = 2;

        if (uno > dos)
            Intercambio();

        do {
            if ((uno % i == 0)&&(dos % i == 0)) {
                mcd = mcd*i;
                uno = uno / i;
                dos = dos / i;
                i = 2;
            } else {
                i++;
            }
        } while (i <= uno);

        uno = primero;
        dos = segundo;

        return mcd;
    }

};

int main() {
    ParejaEnteros pareja_enteros;
    int primero;
    int segundo;

    cout << "\nIntroduzca el primer valor de la pareja de enteros: ";
    cin >> primero;
    cout << "Introduzca el segundo valor de la pareja de enteros: ";
    cin >> segundo;

    pareja_enteros.setPrimero(primero);
    pareja_enteros.setSegundo(segundo);

    cout << "\nValores de la pareja de enteros: " << pareja_enteros.getPrimero() << " " << pareja_enteros.getSegundo() << endl;

    cout << "\tEl mayor valor es: " << pareja_enteros.Mayor() << endl;
    cout << "\tEl menor valor es: " << pareja_enteros.Menor() << endl;

    if ((pareja_enteros.Divisibles(pareja_enteros.getPrimero(), pareja_enteros.getSegundo())) || (pareja_enteros.Divisibles(pareja_enteros.getSegundo(), pareja_enteros.getPrimero()))) {
        cout << "\tLos valores de la pareja son divisibles." << endl;
        cout << "\t" << pareja_enteros.Dividendo() << " es el dividendo y " << pareja_enteros.Divisor() << " es el divisor." << endl;
    } else {
        cout << "\tLos valores de la pareja no son divisibles. " << endl;
    }

    pareja_enteros.Intercambio();
    cout << "\tValores de la pareja intercambiados: " << pareja_enteros.getPrimero() << " " << pareja_enteros.getSegundo() << endl;

    cout << "\tMaximo comun divisor de la pareja: " << pareja_enteros.MaximoComunDivisor() << endl;

    cout << "\n";
}
