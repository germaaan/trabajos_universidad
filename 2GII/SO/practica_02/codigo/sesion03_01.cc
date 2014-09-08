#include <sys/stat.h>
#include <fcntl.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    if (argc != 3) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <archivoEntrada> <archivoSalida>\n";
        exit(1);
    }

    const int TAM_BUFFER = 512;
    int entrada, salida, leidos, escritos;
    char buffer[TAM_BUFFER];

    if ((entrada = open(argv[1], O_RDONLY)) == -1) {
        cerr << "Error: No se ha podido abrir el archivo \"" << argv[1] << "\" para solo lectura.\n";
        exit(-1);
    }

    if ((salida = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC)) == -1) {
        cerr << "Error: No se pudo abrir o crear el archivo \"" << argv[2] << "\" para solo escritura.\n";
        close(entrada);
        exit(-1);
    }

    while ((leidos = read(entrada, &buffer, sizeof (buffer))) > 0) {
        if (leidos == -1) {
            cerr << "Error: Fallo al leer desde archivo \"" << argv[1] << "\".\n";
            close(entrada);
            close(salida);
            exit(-1);
        } else if (leidos > 0) {
            if ((escritos = write(salida, &buffer, leidos)) == -1) {
                cerr << "Error: Fallo al escribir en archivo \"" << argv[2] << "\".\n";
                close(entrada);
                close(salida);
                exit(-1);
            }
        }
    }

    if (close(entrada) == -1)
        cerr << "Error: No se ha podido cerrar correctamente el archivo \"" << argv[1] << "\".";

    if (close(salida) == -1)
        cerr << "Error: No se ha podido cerrar correctamente el archivo \"" << argv[2] << "\".";

    return (0);
}
