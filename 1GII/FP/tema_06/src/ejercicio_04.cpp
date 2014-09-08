// Sobre la clase "MiVectorCaracteres", definir un metodo recursivo que nos diga si
// es un palindromo, es decir, que se lee igual de izquierda a derecha que de derecha a
// izquierda. Por ejemplo, {'a','b','b','a'} seria un palindromo.
// 
// Pasad al metodo como parametros las posiciones izquierda y derecha sobre las que
// trabajara.


#include <iostream>
#include <stdexcept>
using namespace std;

class MiVectorCaracteres {
private:
    static const int TAMANIO = 50;
    char vectorPrivado[TAMANIO];
    int totalUtilizados;

public:

    MiVectorCaracteres()
    : totalUtilizados(0) {
    }

    int TotalUtilizados() {
        return totalUtilizados;
    }

    void Aniade(char nuevo) {
        if (totalUtilizados < TAMANIO) {
            vectorPrivado[totalUtilizados] = nuevo;
            totalUtilizados++;
        } else
            throw logic_error("No hay componentes suficientes");
    }

    char Elemento(int indice) {
        return vectorPrivado[indice];
    }

    bool EsPalindromo(int posIzda, int posDcha) {
        bool resultado;

        if (posIzda > posDcha)
            resultado = true;
        else {

            if (vectorPrivado[posIzda] == vectorPrivado[posDcha])
                resultado = EsPalindromo(posIzda + 1, posDcha - 1);
            else
                resultado = false;
        }

        return resultado;
    }

};

int main() {
    MiVectorCaracteres vector;
    bool palindromo;

    try {
        vector.Aniade('a');
        vector.Aniade('b');
        vector.Aniade('b');
        vector.Aniade('a');
    } catch (logic_error excepcion) {
        cout << "Error logico: " << excepcion.what();
    }

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    palindromo = vector.EsPalindromo(0, (vector.TotalUtilizados()) - 1);

    if (palindromo)
        cout << "\nEl vector es palindromo." << endl;
    else
        cout << "\nEl vector no es palindromo." << endl;
}
