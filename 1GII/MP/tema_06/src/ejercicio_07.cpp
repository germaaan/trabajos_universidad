// Escribir un programa que reciba como parametros tres nombres de ficheros de texto. Los dos primeros ficheros
// contienen numeros reales y estan ordenados. El programa tomara los datos de esos ficheros y los ira copiando
// ordenadamente en el tercer fichero, de forma que al finalizar este tambien ordenado.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi1;
    ifstream fi2;
    ofstream fo;
    float valor1;
    float valor2;

    if (argc != 4) {
        cerr << "Error: numero de parametros incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " [ficheroEntrada_1] [ficheroEntrada_2] [ficheroSalida]" << endl;
        exit(1);
    }

    fi1.open(argv[1], ios::in);

    if (!fi1) {
        cerr << "Error: no se pudo acceder al fichero de entrada " << argv[1] << endl;
        exit(1);
    }

    fi2.open(argv[2], ios::in);

    if (!fi1) {
        cerr << "Error: no se pudo acceder al fichero de entrada " << argv[2] << endl;
        exit(1);
    }

    fo.open(argv[3], ios::out);

    if (!fo) {
        cerr << "Error: no se pudo crear el fichero de salida " << argv[3] << endl;
        exit(1);
    }

    fi1 >> valor1;
    fi2 >> valor2;

    while (!fi1.eof() || !fi2.eof()) {

        if (fi1.eof()) {
            while (!fi2.eof()) {
                fo << valor2 << endl;
                fi2 >> valor2;
            }
        }
        else if (fi2.eof()) {
            while (!fi1.eof()) {
                fo << valor1 << endl;
                fi1 >> valor1;
            }
        }
        else if (valor1 < valor2) {
            fo << valor1 << endl;
            fi1 >> valor1;
        } else {
            fo << valor2 << endl;
            fi2 >> valor2;
        }
    }

    fi1.close();
    fi2.close();
    fo.close();

    return (0);
}
