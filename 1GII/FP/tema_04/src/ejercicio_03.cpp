// Sobre la clase "MiVectorCaracteres", añadir un metodo
// "IntercambiaComponentes" para intercambiar dos componentes del vector.
// Por ejemplo, si el vector contiene {'h','o','l','a'}, despues de intercambiar
// las componentes 1 y 3, se quedaria con {'h','a','l','o'}.
// 
// Añadid otro metodo para invertir el vector, de forma que si el vector contenia 
// los caracteres {'a','g','t','b','i','o'}, despues de llamar al metodo se quedara 
// con {'o','i','b','t','g','a'}. Para implementar este metodo, llamad el metodo
// anterior "IntercambiaComponentes".
// 
// ¿Que deberian hacer los metodos si los indices de componentes no son correctos?
// 
// Imprimir las componentes del vector desde el "main", antes y despues de llamar a
// dicho metodo. Observad que se repite el mismo tipo de codigo cuando se imprimen
// las componentes del vector. Ya lo arreglaremos en el tema siguiente.
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

    void IntercambiaComponentes(int primer_indice, int segundo_indice) {
        char copia_intermedia;

        if ((primer_indice >= 0)&&(primer_indice < total_utilizados)&&(segundo_indice >= 0)&&(segundo_indice < total_utilizados)) {
            copia_intermedia = vector_privado[primer_indice];
            vector_privado[primer_indice] = vector_privado[segundo_indice];
            vector_privado[segundo_indice] = copia_intermedia;
        }

    }

    void InvertirVector() {
        int valor_derecha = total_utilizados - 1;

        for (int i = 0; i < total_utilizados / 2; i++) {
            IntercambiaComponentes(i, valor_derecha);

            valor_derecha--;
        }

    }
};

int main() {
    MiVectorCaracteres vector1;
    MiVectorCaracteres vector2;
    int indice_intercambio_primero;
    int indice_intercambio_segundo;

    vector1.Aniade('h');
    vector1.Aniade('o');
    vector1.Aniade('l');
    vector1.Aniade('a');

    cout << "PRIMER VECTOR:\n" << endl;

    for (int i = 0; i < vector1.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector1.Elemento(i) << endl;

    cout << "\n";

    do {
        cout << "Introduzca el valor del primero de los indices a intercambiar: ";
        cin >> indice_intercambio_primero;
    } while (indice_intercambio_primero < 0);

    do {
        cout << "Introduzca el valor del segundo de los indices a intercambiar: ";
        cin >> indice_intercambio_segundo;
    } while (indice_intercambio_segundo < 0);

    vector1.IntercambiaComponentes(indice_intercambio_primero, indice_intercambio_segundo);

    cout << "\nLos valores de los indices solo se habran intercambiado si los dos valores introducidos eran validos.\n" << endl;

    for (int i = 0; i < vector1.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector1.Elemento(i) << endl;

    vector2.Aniade('a');
    vector2.Aniade('g');
    vector2.Aniade('t');
    vector2.Aniade('b');
    vector2.Aniade('i');
    vector2.Aniade('o');
    vector2.Aniade('z');

    cout << "\n\nSEGUNDO VECTOR:\n" << endl;

    for (int i = 0; i < vector2.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector2.Elemento(i) << endl;

    vector2.InvertirVector();

    cout << "\nValores del vector invertidos.\n" << endl;

    for (int i = 0; i < vector2.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector2.Elemento(i) << endl;

    cout << "\n";
}
