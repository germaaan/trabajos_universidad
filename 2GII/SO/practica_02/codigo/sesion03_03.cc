#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    if (argc != 2) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <directorioConsulta>\n";
        exit(1);
    }

    DIR *flujo_directorio;
    struct dirent *entrada;
    struct stat statbuf;
    int archivo;

    if ((flujo_directorio = opendir(argv[1])) == NULL) {
        cerr << "Error: No se ha podido abrir el directorio \"" << argv[1] << "\".\n";
        exit(1);
    }

    while (entrada = readdir(flujo_directorio)) {

        if (stat(entrada->d_name, &statbuf) == -1) {
            cerr << "Error: No se han podido obtener los atributos del archivo \"" << argv[1] << "\".\n";
            exit(-1);
        } else {
            cout << "\nNombre:\t" << entrada->d_name << endl;

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
        }
    }

    if ((closedir(flujo_directorio)) == -1)
        cerr << "Error: No se podido cerrar correctamente el directorio \"" << argv[1] << "\".\n";

    return (0);
}
