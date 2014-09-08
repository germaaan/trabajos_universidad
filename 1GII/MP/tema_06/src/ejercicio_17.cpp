// Un fichero de texto contiene numeros enteros que se disponen en lineas y en cada linea estan separados por
// espacios en blanco. Se trata de construir una funcion que reciba el nombre del fichero y devuelva un dato de
// tipo Matriz2D con los datos leidos del fichero.
// 
// Las restricciones que se imponen, y que se deben cumplir en la resolucion son:
// 
// 	a) El fichero solo puede ser leido una u ́nica vez, y no pueden copiarse completo en memoria.
// 
// 	b) Se desconoce a priori el numero de lineas del fichero.
// 
// 	c) Las lineas del fichero tiene una longitud indeterminada, aunque nunca mayor de 500.
// 
// 	d) El numero de datos de cada linea es indeterminado, aunque este es comun para todas las lineas.
// 
// 	e) No puede emplearse una matriz con un numero de filas “tentativo” sino que la matriz ocupara en cada
// 	   momento el espacio estrictamente necesario y los datos se copiaran conforme se lean cada una de las filas.
// 
// Nota: Es posible que sea necesario a ̃nadir un nuevo metodo a la clase Matriz2D que permita redimensionar la
// matriz, a ̃nadiendo una nueva linea.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Matriz2D.h"

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    int numColumnas = 1;
    int contadorFilas = 0;
    int contadorColumnas = 0;
    int valorLeido;

    fi.open(argv[1], ios::in);

    if (!fi) {
        cerr << "Error: no se pudo acceder al fichero: " << argv[1] << endl;
        exit(1);
    }

    fi >> valorLeido;

    while ((!fi.eof()) && (fi.peek() != '\n')) {
        numColumnas++;

        fi >> valorLeido;
    }

    fi.seekg(0, ios::beg);

    Matriz2D matriz(1, numColumnas);

    fi >> valorLeido;

    while (!fi.eof()) {
        matriz.PonValor(contadorFilas, contadorColumnas, valorLeido);
        contadorColumnas++;

        if (fi.peek() == '\n') {
            matriz.aumentarFilas();

            contadorFilas++;
            contadorColumnas = 0;
        }

        fi >> valorLeido;
    }

    cout << endl;

    cout << matriz;

    cout << endl;

    return (0);
}
