// Escribir un programa similar a grep que busque una cadena en una serie de ficheros de texto. La cadena a buscar
// y los ficheros en los que buscar se proporcionan en la linea de ordenes. Por ejemplo:
// 
// 	busca Olga fich1 fich2 fich3
// 
// busca la cadena Olga en los ficheros fich1, fich2 y fich3.
// 
// Cada vez que encuentre la cadena buscada, debe indicar el fichero en el que es localizada, el numero de linea y
// la linea completa que la contiene. Un ejemplo de salida de este programa es:
// 
// fich1 (linea 33): Mi amiga Olga ha aprobado MP aunque no se
// fich3 (linea 2): ya se lo dije ayer a Pepe, pero ni caso
// fich3 (linea 242): finalmente, Olga se puso a estudiar
// 
// Las restricciones que se imponen, y que se deben cumplir en la resolucion son:
// 
// 	a) El numero de ficheros que se pueden proporcionar es ilimitado.
// 
// 	b) Cada uno de los ficheros solo puede ser leido una u ́nica vez, y no pueden copiarse completos en memoria.
// 
// 	c) Se desconoce a priori el numero de lineas de los ficheros.
// 
// 	d ) Las lineas de los ficheros tienen una longitud indeterminada, aunque nunca mayor de 500.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    const int TAMANIO_CADENA = 500;
    char cadenaBuscada[TAMANIO_CADENA];
    int tamanioBuscado;
    ifstream fi;
    char valorLeido;
    int contadorCadena;
    int contadorLinea;
    int contadorLetra;
    int posInicioLinea;
    int contadorFichero = 2;
    bool encontrado = false;

    if (argc < 3) {
        cerr << "Error: numero de parametros incorrectos, minimo 1 obligatoriamente." << endl;
        cerr << "Uso: " << argv[0] << " [cadena] [fich_1] ... [fich_n]" << endl;
        exit(1);
    }

    strcpy(cadenaBuscada, argv[1]);

    tamanioBuscado = strlen(cadenaBuscada);

    while (contadorFichero < argc) {

        contadorCadena = 0;
        contadorLetra = 0;
        contadorLinea = 1;
        posInicioLinea = 0;
        encontrado = false;

        fi.open(argv[contadorFichero], ios::in);

        if (!fi) {
            cerr << "Error: no se pudo acceder al fichero " << argv[contadorFichero] << endl;
            exit(1);
        }

        valorLeido = fi.get();

        while ((!fi.eof()) && !encontrado) {

            if (valorLeido == '\n') {
                contadorLinea++;
                posInicioLinea = fi.tellg();
            }

            if (valorLeido == cadenaBuscada[contadorCadena]) {
                contadorLetra++;
                contadorCadena++;

                if (contadorLetra == tamanioBuscado)
                    encontrado = true;
            } else {
                contadorLetra = 0;
                contadorCadena = 0;
            }

            valorLeido = fi.get();
        }

        if (encontrado) {
            fi.seekg(posInicioLinea, ios::beg);

            cout << argv[contadorFichero] << " (linea " << contadorLinea << "): ";

            valorLeido = fi.get();

            while ((!fi.eof()) && (valorLeido != '\n')) {
                cout << valorLeido;

                valorLeido = fi.get();
            }

            cout << endl;
        }

        contadorFichero++;

        fi.close();
    }

    return (0);
}
