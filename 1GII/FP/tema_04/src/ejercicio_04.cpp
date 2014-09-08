// Sobre la clase "MiVectorCaracteres", añadir un metodo "Elimina" para eliminar el
// caracter que se encuentre en una determinada posicion, de forma que si el vector
// contenia los caracteres {'h','o','l','a'}, despues de eliminar la componente
// con indice 2 (la tercera) se quedara con {'h','o','a'}.
// 
// ¿Que deberia hacer el metodo si el indice de componente no es correcto?
// 
// Finalidad: Ejemplo de metodo que modifica el estado del objeto. Gestion de 
// precondiciones. Dificultad Baja.


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

    void Elimina(int indice_componente) {
        if ((indice_componente >= 0)&&(indice_componente < total_utilizados)) {
            for (int i = indice_componente; i < total_utilizados - 1; i++)
                vector_privado[i] = vector_privado[i + 1];

            total_utilizados--;
        }
    }
};

int main() {
    MiVectorCaracteres vector;
    int indice_eliminar_vector;

    vector.Aniade('h');
    vector.Aniade('o');
    vector.Aniade('l');
    vector.Aniade('a');

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    cout << "\n";

    do {
        cout << "Introduzca el valor del indice del vector a eliminar: ";
        cin >> indice_eliminar_vector;
    } while (indice_eliminar_vector < 0);

    vector.Elimina(indice_eliminar_vector);

    cout << "\nEl valor del indice solo se habra eliminado si el valor introducido era valido." << endl;

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    cout << "\n";
}
