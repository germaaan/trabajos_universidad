// Sobre la clase MiVectorCaracteres, añadir un metodo para eliminar el
// exceso de caracteres en blanco, es decir, que suprima todas las secuencias
// de espacios en blanco mayor de 1. Por ejemplo, si el vector original es 
// (' ','a','h',' ',' ',' ','c'), el vector resultante debe ser
// (' ','a','h',' ',,'c'). Debe hacerse lo mas eficiente posible.
// 
// Finalidad: Recorrido de las componentes de un vector, en el que hay que recordar lo
// que ha pasado en la iteracion anterior. Dificultad Media.


#include <iostream>
using namespace std;

class MiVectorCaracteres {
private:
    static const int TAMANIO = 50;
    char vector_privado[TAMANIO];
    int total_utilizados;

public:

    MiVectorCaracteres()
    : total_utilizados(0) {
    }

    int TotalUtilizados() {
        return total_utilizados;
    }

    void Aniade(char nuevo) {
        if (total_utilizados < TAMANIO) {
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    char Elemento(int indice) {
        return vector_privado[indice];
    }

    void EliminarEspaciosBlancos() {
        char ultimoValor = 'a';

        for (int i = 0; i < total_utilizados; i++) {

            if ((vector_privado[i] == ' ')&&(ultimoValor == ' ')) {

                for (int j = i; j < total_utilizados; j++) {

                    if (vector_privado[j] != ' ') {
                        vector_privado[i] = vector_privado[j];
                        j = total_utilizados;
                        total_utilizados--;
                    }

                }

                total_utilizados--;
            }

            ultimoValor = vector_privado[i];

        }

    }
};

int main() {
    MiVectorCaracteres vector;

    vector.Aniade(' ');
    vector.Aniade('a');
    vector.Aniade('h');
    vector.Aniade(' ');
    vector.Aniade(' ');
    vector.Aniade(' ');
    vector.Aniade('c');

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    vector.EliminarEspaciosBlancos();

    cout << "\nValores del vector despues de eliminar el exceso de espacios en blanco:\n" << endl;

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    cout << "\n\n";
}
