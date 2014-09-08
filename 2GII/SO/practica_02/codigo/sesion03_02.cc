#include <sys/stat.h>
#include <fcntl.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    if (argc != 2) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <archivoConsulta>\n";
        exit(1);
    }

    struct stat statbuf;

    if (stat(argv[1], &statbuf) == -1) {
        cerr << "Error: No se han podido obtener los atributos del archivo \"" << argv[1] << "\".\n";
        exit(-1);
    } else {
        cout << "\nNombre:\t" << argv[1] << endl;

        cout << "Tipo:\t";

        switch (statbuf.st_mode & S_IFMT) {
            case (S_IFREG):
                cout << "Archivo regular" << endl;
                break;
            case (S_IFDIR):
                cout << "Directorio" << endl;
                break;
            case (S_IFCHR):
                cout << "Dispositivo de caracteres" << endl;
                break;
            case (S_IFBLK):
                cout << "Dispositivo de bloques" << endl;
                break;
            case (S_IFIFO):
                cout << "FIFO o cauce" << endl;
                break;
            case (S_IFSOCK):
                cout << "Socket" << endl;
                break;
            case (S_IFLNK):
                cout << "Enlace simbólico" << endl;
                break;
        }

        cout << "Tamaño:\t" << statbuf.st_size << " Bytes" << endl;
    }

    return (0);
}
