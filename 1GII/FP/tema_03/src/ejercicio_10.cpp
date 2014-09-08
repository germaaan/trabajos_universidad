// Sobre el ejercicio 9 de esta relacion de problemas se pide crear un programa prin-
// cipal mas completo, de la siguiente forma. En el "main" se leeran dos enteros y a
// continuacion se ofrecera al usuario un menu con las opciones para realizar cualquiera
// de las operaciones definidas en la clase "ParejaEnteros". Tambien se ofrecera la
// posibilidad de imprimir el valor de cada uno de los dos enteros. Una vez ejecutada
// la operacion, se volvera a mostrar el mismo menu, hasta que el usuario decida salir
// (pulsando la tecla 'X', por ejemplo)


#include <iostream>
#include <cctype>
using namespace std;

class ParejaEnteros {
private:
    int uno;
    int dos;

public:

    ParejaEnteros(int primero, int segundo)
    : uno(primero),
    dos(segundo) {
    }

    int GetPrimero() {
        return uno;
    }

    int GetSegundo() {
        return dos;
    }

    int Mayor() {
        if (uno < dos)
            return dos;
        else
            return uno;
    }

    int Menor() {
        if (uno < dos)
            return uno;
        else
            return dos;
    }

    bool Divisibles() {
        return ((uno % dos == 0) || (dos % uno == 0));
    }

    int Dividendo() {
        if (Divisibles())
            return Mayor();
        else
            return 0;
    }

    int Divisor() {
        if (Divisibles())
            return Menor();
        else
            return 0;
    }

    void Intercambio() {
        int copia_temporal;

        copia_temporal = uno;
        uno = dos;
        dos = copia_temporal;
    }

    int MaximoComunDivisor() {
        bool hay_divisores, mcd_encontrado;
        int divisor, mcd = 0;

        if ((uno == 0) || (dos == 0))
            mcd = 0;
        else {

            if (uno > dos)
                divisor = dos;
            else
                divisor = uno;

            hay_divisores = true;
            mcd_encontrado = false;

            while (hay_divisores && !mcd_encontrado) {
                if (divisor == 1) {
                    hay_divisores = false;
                    mcd = 1;
                } else {

                    if ((uno % divisor == 0) && (dos % divisor == 0)) {
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

};

int main() {
    int primero;
    int segundo;
    char opcion_elegida;
    bool continuar_bucle_principal = true;

    cout << "\nIntroduzca el primer valor de la pareja de enteros: ";
    cin >> primero;
    cout << "Introduzca el segundo valor de la pareja de enteros: ";
    cin >> segundo;

    ParejaEnteros pareja_enteros(primero, segundo);

    while (continuar_bucle_principal) {
        cout << "\n\nMENu PRINCIPAL:" << endl;
        cout << "\tP \tMostrar el (P)rimer valor" << endl;
        cout << "\tS \tMostrar el (S)egundo valor" << endl;
        cout << "\tY \tCalcular el ma(Y)or valor" << endl;
        cout << "\tN \tCalcular el me(N)or valor" << endl;
        cout << "\tC \tCalcular el maximo (C)omun divisor" << endl;
        cout << "\tI \t(I)ntercambiar los valores" << endl;
        cout << "\tD \tSon (D)ivisibles entre si?" << endl;
        cout << "\tO \tMostrar el dividend(O)" << endl;
        cout << "\tR \tMostrar el diviso(R)" << endl;
        cout << "\tX \tE(X)it" << endl;

        cout << "\nIntroduzca la opcion elegida: ";

        do {
            cout << "\n\tOpcion: ";
            cin >> opcion_elegida;
            opcion_elegida = toupper(opcion_elegida);
        } while ((opcion_elegida != 'P') && (opcion_elegida != 'S') && (opcion_elegida != 'Y') && (opcion_elegida != 'N') && (opcion_elegida != 'C') &&
                (opcion_elegida != 'I') && (opcion_elegida != 'D') && (opcion_elegida != 'O') && (opcion_elegida != 'R') && (opcion_elegida != 'X'));

        if (opcion_elegida == 'X') {
            cout << "\nSaliendo del programa..." << endl;
            continuar_bucle_principal = false;
        } else {

            if (opcion_elegida == 'P') {
                cout << "\nEl primer valor es: " << pareja_enteros.GetPrimero() << endl;
            } else {

                if (opcion_elegida == 'S') {
                    cout << "\nEl segundo valor es: " << pareja_enteros.GetSegundo() << endl;
                } else {

                    if (opcion_elegida == 'Y') {
                        cout << "\nEl mayor valor es: " << pareja_enteros.Mayor() << endl;
                    } else {

                        if (opcion_elegida == 'N') {
                            cout << "\nEl menor valor es: " << pareja_enteros.Menor() << endl;
                        } else {

                            if (opcion_elegida == 'C') {
                                cout << "\nEl maximo comun divisor es: " << pareja_enteros.MaximoComunDivisor() << endl;
                            } else {

                                if (opcion_elegida == 'I') {
                                    pareja_enteros.Intercambio();
                                    cout << "\nSe han intercambiado los valores." << endl;
                                } else {
                                    bool se_dividen;

                                    se_dividen = pareja_enteros.Divisibles();

                                    if (!se_dividen) {
                                        cout << "\nLos valores no son divisibles entre si." << endl;
                                    } else {

                                        if (opcion_elegida == 'D') {
                                            cout << "\nLos valores si son divisibles entre si." << endl;
                                        } else {

                                            if (opcion_elegida == 'O') {
                                                cout << "\nEl dividendo es: " << pareja_enteros.Dividendo() << endl;
                                            } else {

                                                if (opcion_elegida == 'R') {
                                                    cout << "\nEl divisor es: " << pareja_enteros.Divisor() << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
