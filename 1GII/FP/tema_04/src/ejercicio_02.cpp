// Sobre la clase "MiVectorCaracteres", añadir un metodo con la cabecera
//
//	void Modifica (int indice_componente, char nuevo)
//
// para que modifique la componente con indice "indice_componente" y ponga en su
// lugar el valor "nuevo". En el caso de que la componente no este dentro del rango
// correcto, no se modificara nada.
//
// Finalidad: Ejemplo de metodo que modifica el estado del objeto. Gestion de precondi-
// ciones. Dificultad Baja.


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

    void Modifica(int indice_componente, char nuevo) {
        if ((indice_componente > 0)&&(indice_componente < total_utilizados))
            vector_privado[indice_componente] = nuevo;
    }
};

int main() {
    MiVectorCaracteres vector;
    int indice_modificar;
    char valor_nuevo;

    vector.Aniade('a');
    vector.Aniade('b');
    vector.Aniade('c');
    vector.Aniade('d');

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    do {
        cout << "\nIntroduzca el valor del indice del vector a modificar: ";
        cin >> indice_modificar;
    } while (indice_modificar < 0);

    cout << "Introduzca valor nuevo del indice: ";
    cin >> valor_nuevo;

    vector.Modifica(indice_modificar, valor_nuevo);

    cout << "\nEl valor del vector solo se habra modificado si se ha introducido un indice valido." << endl;

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    cout << "\n";
}
