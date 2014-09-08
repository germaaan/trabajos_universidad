// Construir un programa que reconstruya un fichero a partir de una serie de ficheros que contienen sus “partes”.
// Los ficheros que pueden emplearse como origen se han creado con los programas descritos en los problemas 10
// y 11 y por ese motivo se emplara el fichero de control creado por esos programas.
// 
// Por ejemplo, la ejecucion de reconstruye Fichero genera como resultado Fichero. Usara .Fichero.ctrl para
// conocer los ficheros que debe usar y el orden en que se debe hacer la reconstruccion.
// 
// Nota: Utilizad cadenas para construir los nombres de los ficheros que intervienen.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    const int TAM_BUFFER = 512;
    const int TAM_NOMBRE_FICHERO = 10;
    const int TAM_NOMBRE_FICHERO_OCULTO = 14;
    const int TAM_NOMBRE_FICHERO_ORIGINAL = 50;
    char buffer[TAM_BUFFER];
    char nombreFichero[TAM_NOMBRE_FICHERO];
    char nombreFicheroOculto[TAM_NOMBRE_FICHERO_OCULTO];
    char nombreFicheroOriginal[TAM_NOMBRE_FICHERO_ORIGINAL];
    char valorLeido;
    ifstream fi;
    ofstream fo;
    int contPartes = 1;
    int partesTotales;
    int contBytes;

    if (argc != 2) {
        cerr << "Error: numero de parametros insuficiente.";
        cerr << "Uso: " << argv[0] << " [Fichero]" << endl;
        exit(1);
    }

    fi.open(".Fichero.ctrl", ios::in);

    if (!fi) {
        cerr << "Error: no se pudo abrir el fichero " << ".Fichero.ctrl" << endl;
        exit(1);
    }

    fi.getline(nombreFicheroOriginal, TAM_NOMBRE_FICHERO_ORIGINAL);
    fi >> partesTotales;

    fi.close();

    fo.open("Fichero", ios::out);

    if (!fo) {
        cerr << "Error: no se pudo crear el fichero de salida " << "Fichero" << endl;
        exit(1);
    }

    strcpy(nombreFichero, "Fichero__");

    nombreFichero[8] = '0' + contPartes;

    fi.open(nombreFichero, ios::in);

    if (!fi) {
        cerr << "Error: no se pudo acceder al fichero " << nombreFichero << endl;
        exit(1);
    }

    while (contPartes <= partesTotales) {

        while (!fi.eof()) {
            fi.read((char *) &buffer, TAM_BUFFER);
            fo.write((char *) &buffer, TAM_BUFFER);
        }

        fi.close();

        contPartes++;

        if (contPartes <= partesTotales) {

            nombreFichero[8] = '0' + contPartes;

            fi.open(nombreFichero, ios::in);

            if (!fi) {
                cerr << "Error: no se pudo acceder al fichero " << nombreFichero << endl;
                exit(1);
            }
        }
    }

    fo.close();

    return (0);
}
