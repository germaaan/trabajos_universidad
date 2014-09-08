// A la hora de diseñar una clase debemos poner especial enfasis en intentar que sea lo
// mas reutilizable posible, intentando que su interfaz publica no este ligada a los detalles
// de la implementacion. Por ejemplo, en el ejercicio 10 de la relacion de problemas
// III se definio una clase para leer una opcion del usuario. Para ello, se definio una
// clase "Menu" con un metodo "LeeOpcion()" que devolvia un "char". ¿Y si quisiesemos
// modificar el criterio de entrada y que la opcion fuese un entero en vez de un caracter?
// Habria que cambiar la definicion de la clase "Menu" y por tanto el programa "main" en
// el que se utiliza. Para evitarlo, podemos definir el metodo "LeeOpcion()" para que
// devuelva algo mas generico que un "char" , por ejemplo, un enumerado que represente
// la opcion leida. De esta forma, si queremos cambiar la forma en la que se lee la
// opcion (por ejemplo '1' en vez de ’P’, '4' en vez de 'I' , etc), bastara modificar la
// implementacion interna de la clase "Menu", pero los clientes de dicha clase (en nuestro
// caso el programa principal "main") seguiran utilizandola de la misma forma, a traves
// del enumerado que devuelve el metodo.
//
// Recuperad la solucion al ejercicio 10 disponible en la web del departamento y realizad
// la transformacion pedida.
//
// Finalidad: Enfatizar la necesidad de abstraer la interfaz de una clase. Dificultad Baja.


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Pareja_de_Enteros {
private:
    int primero;
    int segundo;
public:

    Pareja_de_Enteros(int primer_valor, int segundo_valor)
    : primero(primer_valor),
    segundo(segundo_valor) {
    }

    int Primero() {
        return primero;
    }

    int Segundo() {
        return segundo;
    }

    bool SeDividen() {
        return (primero % segundo == 0 || segundo % primero == 0);
    }

    int Dividendo() {
        if (SeDividen())
            return ElMayor();
        else
            return 0;
    }

    int Divisor() {
        if (SeDividen())
            return ElMenor();
        else
            return 0;
    }

    int ElMenor() {
        if (primero < segundo)
            return primero;
        else
            return segundo;
    }

    int ElMayor() {
        if (primero < segundo)
            return segundo;
        else
            return primero;
    }

    void Intercambia() {
        int intermedia;

        intermedia = primero;
        primero = segundo;
        segundo = intermedia;
    }

    int MCD() {
        bool hay_divisores, mcd_encontrado;
        int divisor, mcd;

        if (primero == 0 || segundo == 0)
            mcd = 0;
        else {
            if (primero > segundo)
                divisor = segundo;
            else
                divisor = primero;

            hay_divisores = true;
            mcd_encontrado = false;

            while (hay_divisores && !mcd_encontrado) {
                if (divisor == 1) {
                    hay_divisores = false;
                    mcd = 1;
                } else {
                    if ((primero % divisor == 0) && (segundo % divisor == 0)) {
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

class Menu {
private:

    enum TipoDeOpcion {
        P, S, Y, N, C, I, D, O, R, X
    };

public:

    TipoDeOpcion LeeOpcion() {
        TipoDeOpcion opcionSeleccionada;


        return opcionSeleccionada;
    }
};

int main() {
    int uno, otro;
    char opcion_elegida;
    bool continuar_bucle_principal = true;
    Menu menu;

    cout << "\nIntroduzca un valor entero: ";
    cin >> uno;
    cout << "\nIntroduzca otro valor entero: ";
    cin >> otro;

    Pareja_de_Enteros pareja(uno, otro);

    do {
        cout << "\n\n\n";
        cout << "\nP -> Imprimir el valor Primero";
        cout << "\nS -> Imprimir el valor Segundo";
        cout << "\nY -> Calcular el maYor";
        cout << "\nN -> Calcular el meNor";
        cout << "\nC -> Calcular el mCd";
        cout << "\nI -> Intercambiar los valores";
        cout << "\nD -> ¿Se Dividen?";
        cout << "\nO -> Imprimir el dividendO";
        cout << "\nR -> Imprimir el divisoR";
        cout << "\nX -> eXit";

        cout << "\n\nIntroduzca la opcion elegida: ";

        do {
            cout << "\n--> ";
			cin >> opcion_elegida;
            opcion_elegida = toupper(opcion_elegida);
        } while (opcion_elegida != 'P' && opcion_elegida != 'S' && opcion_elegida != 'Y' && opcion_elegida != 'N' &&
                opcion_elegida != 'C' && opcion_elegida != 'I' && opcion_elegida != 'D' && opcion_elegida != 'O' &&
                opcion_elegida != 'R' && opcion_elegida != 'X');

        if (opcion_elegida == 'X')
            continuar_bucle_principal = false;
        else if (opcion_elegida == 'P')
            cout << "\nEl Primero es: " << pareja.Primero();
        else if (opcion_elegida == 'S')
            cout << "\nEl Segundo es: " << pareja.Segundo();
        else if (opcion_elegida == 'Y')
            cout << "\nEl Mayor es: " << pareja.ElMayor();
        else if (opcion_elegida == 'N')
            cout << "\nEl Menor es: " << pareja.ElMenor();
        else if (opcion_elegida == 'C')
            cout << "\nEl MCD es:   " << pareja.MCD();
        else if (opcion_elegida == 'I') {
            pareja.Intercambia();
            cout << "\nSe han intercambiado los valores";
        } else {
            bool se_dividen;

            se_dividen = pareja.SeDividen();

            if (!se_dividen)
                cout << "\nNo se dividen";
            else
                if (opcion_elegida == 'D')
                cout << "\nSe dividen";
            else if (opcion_elegida == 'O')
                cout << "\nDividendo = " << pareja.Dividendo();
            else if (opcion_elegida == 'R')
                cout << "\nDivisor   = " << pareja.Divisor();
        }
    } while (continuar_bucle_principal);

    cout << "\n\n";
}
