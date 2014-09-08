// Sobre la clase MiVectorCaracteres, se quieren añadir un metodo
// EliminaMayusculas para eliminar todas las mayusculas. Por ejemplo, 
// despues de aplicar dicho metodo al vector {'S','o','Y',' ','y','o'}, este debe
// quedarse con {'o',' ','y'}. Se pide hacerlo de dos formas:
// 
// 	• Implementando el siguiente algoritmo:
// 		
// 		Recorrer todas las componentes del vector
// 			Si la componente es una mayuscula, borrarla
// 
// 	  Para borrar la mayuscula, se desplazan una posicion a la izquierda todas las
// 	  componentes que hay a su derecha. Para ello, llamad al metodo "Elimina" que
// 	  se ha definido en el ejercicio 4 de esta relacion de problemas, de la siguiente
// 	  forma:
// 
// 	  class MiVectorCaracteres{
// 		...........
// 		void EliminaMayuscula(){
// 			for (int i=0; i<total_utilizados; i++)
// 				if (isupper(vector_privado[i]))
// 					Elimina(i);
// 		}
// 	  };
// 
// 	  El anterior codigo tiene un fallo. ¿Cual? Probarlo con cualquier vector que tenga
// 	  dos mayusculas consecutivas, proponer una solucion e implementarla.
// 
// 	• El algoritmo anterior es muy ineficiente ya que requiere trasladar muchas veces
// 	  muchas posiciones. Proponer un algoritmo para resolver eficientemente este pro-
// 	  blema e implementarlo.
// 
// 	Consejo: Una forma de hacerlo es utilizar dos variables, posicion_lectura y
// 	posicion_escritura que nos vayan indicando, en cada momento, la componente
// 	que se esta leyendo y el sitio donde tiene que escribirse.
// 
// Finalidad: Modificar un vector a traves de dos apuntadores. Dificultad Media.


#include <iostream>
using namespace std;

class MiVectorCaracteres {
private:
    static const int TAMANIO = 50;
    char vector_privado[TAMANIO];
    int total_utilizados;

    void Elimina(int indice_componente) {
        if (indice_componente < total_utilizados) {
            for (int i = indice_componente; i < total_utilizados; i++)
                vector_privado[i] = vector_privado[i + 1];

            total_utilizados--;
        }
    }

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

    /*VERSION INEFICIENTE
	
    void EliminaMayuscula(){
            for (int i=0;i<total_utilizados;i++)
                    if (isupper(vector_privado[i]))
                            Elimina(i);
    }*/

    void EliminaMayuscula() {
        int posicion_lectura;
        int posicion_escritura = 0;

        for (posicion_lectura = 0; posicion_lectura < total_utilizados; posicion_lectura++) {

            if (!isupper(vector_privado[posicion_lectura])) {
                vector_privado[posicion_escritura] = vector_privado[posicion_lectura];

                posicion_escritura++;
            }

        }

        total_utilizados = posicion_escritura;

    }
};

int main() {
    MiVectorCaracteres vector;

    vector.Aniade('S');
    vector.Aniade('O');
    vector.Aniade('Y');
    vector.Aniade(' ');
    vector.Aniade('y');
    vector.Aniade('O');

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    vector.EliminaMayuscula();

    cout << "\nValores del vector despues de eliminar todas las mayusculas:\n" << endl;

    for (int i = 0; i < vector.TotalUtilizados(); i++)
        cout << "Valor en [" << i << "]: " << vector.Elemento(i) << endl;

    cout << "\n\n";
}
