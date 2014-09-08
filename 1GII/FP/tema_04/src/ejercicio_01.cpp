// En clase de teoria se ha visto la siguiente clase "MiVectorCaracteres".
//
//	class MiVectorCaracteres{
//	private:
//		static const int TAMANIO = 50;
//		char vector_privado[TAMANIO];
//		int total_utilizados;
//	public:
//		MiVectorCaracteres()
//			:total_utilizados(0)
//		{
//		}
//		int TotalUtilizados(){
//			return total_utilizados;
//		}
//		void Aniade(char nuevo){
//			if (total_utilizados < TAMANIO){
//				vector_privado[total_utilizados] = nuevo;
//				total_utilizados++;
//			}
//		}
//		char Elemento(int indice){
//			return vector_privado[indice];
//		}
//	};
//
// Añadir un metodo que nos diga si el vector es un palindromo, es decir, que
// se lee igual de izquierda a derecha que de derecha a izquierda. Por ejemplo,
// {'a','b','b','a'} seria un palindromo.
// 
// Finalidad: Ejemplo de metodo que accede a las componentes del vector. Dificultad
// Baja.


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

    bool esPalindromo() {
        bool esPalindromo = true;
        int valor_derecha = total_utilizados - 1;

        if (total_utilizados == 0) {
            esPalindromo = false;
        } else {
            for (int i = 0; i < total_utilizados / 2; i++) {
                if (vector_privado[i] != vector_privado[valor_derecha])
                    esPalindromo = false;

                valor_derecha--;
            }

        }

        return esPalindromo;

    }
};

int main() {
    MiVectorCaracteres vector;
    bool palindromo;

    vector.Aniade('a');
    vector.Aniade('b');
    vector.Aniade('b');
    vector.Aniade('a');

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    palindromo = vector.esPalindromo();

    if (palindromo == 1)
        cout << "\nEl vector es palindromo." << endl;
    else
        cout << "\nEl vector no es palindromo." << endl;

    cout << "\n";
}
