// Construir un programa que divida un fichero de cualquier tipo en diferentes ficheros, indicando como argumentos
// el nombre del fichero original y el maximo numero de bytes que contendra cada fichero resultante.
// 
// Por ejemplo, si el tama ̃no de Fichero es 1800 bytes, la ejecucion de parte_bytes Fichero 500 genera como
// resultado los ficheros Fichero_1, Fichero_2, Fichero_3 y Fichero_4. Los tres primeros contienen 500 bytes
// de Fichero y el u ́ ltimo, los 300 restantes. Se creara un fichero oculto llamado .Fichero.ctrl que contendra
// (formato texto, en dos lineas separadas): nombre del fichero original y numero de ficheros resultantes de la
// particion.
// 
// Nota: Utilizad cadenas para construir los nombres de los ficheros resultantes.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    const int TAM_BUFFER = 512;
    const int TAM_NOMBRE_FICHERO = 10;
    const int TAM_NOMBRE_FICHERO_OCULTO = 14;
    char buffer[TAM_BUFFER];
    char nombreFichero[TAM_NOMBRE_FICHERO];
    char nombreFicheroOculto[TAM_NOMBRE_FICHERO_OCULTO];
    char valorLeido;
    ifstream fi;
    ofstream fo;
    int contPartes = 1;
    int contBytes;

    if (argc != 3) {
        cerr << "Error: numero de parametros insuficiente.";
        cerr << "Uso: " << argv[0] << " [fichero] [numBytes]" << endl;
        exit(1);
    }

    fi.open(argv[1], ios::in);

    if (!fi) {
        cerr << "Error: no se pudo abrir el fichero " << argv[1] << endl;
        exit(1);
    }

    strcpy(nombreFichero, "Fichero__");

    while (!fi.eof()) {

        contBytes = 0;

        nombreFichero[8] = '0' + contPartes;

        fo.open(nombreFichero, ios::out);

        if (!fo) {
            cerr << "Error: no se pudo crear el fichero " << nombreFichero << endl;
            exit(1);
        }

        while (!fi.eof() && (contBytes < atoi(argv[2]))) {
            if ((contBytes + TAM_BUFFER) < atoi(argv[2])) {
                fi.read((char *) &buffer, TAM_BUFFER);
                contBytes += fi.gcount();
                fo.write((char *) &buffer, TAM_BUFFER);
            } else {
                fi.read((char *) &buffer, atoi(argv[2]) - contBytes);
                contBytes += fi.gcount();
                fo.write((char *) &buffer, atoi(argv[2]) - contBytes);
            }
        }

        fo.close();

        contPartes++;
    }

    fi.close();

    strcpy(nombreFicheroOculto, ".Fichero.ctrl");

    fo.open(nombreFicheroOculto, ios::out);

    if (!fo) {
        cerr << "Error: no se pudo crear el fichero " << nombreFicheroOculto << endl;
        exit(1);
    }

    fo << argv[1] << endl;
    fo << contPartes - 1;

    fo.close();

    return (0);
}
