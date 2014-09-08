// Sobre la clase "MiVectorCaracteres", definir un metodo recursivo que construya
// otro vector de caracteres con las mismas componentes pero en sentido inverso, de
// forma que si el vector contenia los caracteres {'a','g','t','b','i','o'}, el
// metodo construira el vector {'o','i','b','t','g','a'}.
// 
// Pasad al metodo como parametros las posiciones izquierda y derecha sobre las que
// trabajara.
// 
// Analizad la eficiencia de esta solucion.


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

    void Invertir(int posIzda, int posDcha) {
        char copia;

        copia = vectorPrivado[posIzda];
        vectorPrivado[posIzda] = vectorPrivado[posDcha];
        vectorPrivado[posDcha] = copia;

        if (posIzda < ((totalUtilizados / 2) - 1))
            Invertir(posIzda + 1, posDcha - 1);
    }

};

int main() {
    MiVectorCaracteres vector;
    bool palindromo;

    try {
        vector.Aniade('a');
        vector.Aniade('g');
        vector.Aniade('t');
        vector.Aniade('b');
        vector.Aniade('i');
        vector.Aniade('o');
    } catch (logic_error excepcion) {
        cout << "Error logico: " << excepcion.what();
    }

    cout << "Vector original: " << endl;
    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    vector.Invertir(0, (vector.TotalUtilizados()) - 1);

    cout << "Vector invertido: " << endl;
    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;
}
