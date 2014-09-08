// Implementar un programa que similar a tail que muestre las u ́ltimas lineas de un fichero de texto.
// 
// Por ejemplo, la ejecucion de final 15 reconstruye.cpp mostrara las u ́ltimas 15 lineas del fichero de texto
// reconstruye.cpp
// 
// Se aplican las mismas restricciones que las indicadas en el problema 14 (excepto la primera, evidentemente).


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    char valorLeido;
    int contadorLinea = 0;
    int posicionActual;
    int contador = 1;

    if (argc != 3) {
        cerr << "Error: numero de parametros incorrectos." << endl;
        cerr << "Uso: " << argv[0] << " [numLineas] [fichero]" << endl;
        exit(1);
    }

    fi.open(argv[2], ios::in);

    if (!fi) {
        cerr << "Error: no se pudo acceder al fichero " << argv[2] << endl;
        exit(1);
    }

    fi.seekg(-2, ios::end);
    posicionActual = fi.tellg();

    valorLeido = fi.get();

    while ((posicionActual > 2) && (contadorLinea <= atoi(argv[1]))) {
        if ((valorLeido == '\n') || (fi.peek() == '\n'))
            contadorLinea++;

        if (contadorLinea <= atoi(argv[1])) {
            posicionActual -= 2;
            fi.seekg(posicionActual, ios::beg);

            valorLeido = fi.get();
        }
    }

    if (posicionActual == 1)
        fi.seekg(0, ios::beg);
    else
        fi.seekg(posicionActual + 2, ios::beg);

    valorLeido = fi.get();

    while (!fi.eof()) {
        cout << valorLeido;

        valorLeido = fi.get();
    }

    fi.close();

    cout << endl;

    return (0);
}
