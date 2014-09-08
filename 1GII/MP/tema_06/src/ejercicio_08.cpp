// Se dispone de ficheros de texto que contienen un numero indeterminado de lineas, cada una de ellas con los datos
// correspondientes a una serie de grupos de valores reales.
// 
// Por ejemplo, una linea de entrada podria ser la siguiente:
// 
// 	3 3.1 0.0 2.1 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
// 
// donde puede observar que se distinguen tres grupos de datos, y cada grupo empieza por un valor entero seguido
// por tantos valores reales como indique el valor entero que encabeza cada grupo:
// 
// 	[3] 3.1 0.0 2.1 [5] 1.0 1.0 1.0 1.0 1.0 [2] 5.2 4.7
// 
// Escribir un programa que escriba en la salida estandar una linea de resultado por cada linea de entrada, y en
// cada liinea mostrara las sumas de los valores de cada grupo.
// 
// Por ejemplo, en el caso anterior, deberia escribir:
// 
// 	5.2		5.0		9.9
// 
// El programa se ejecutara desde la linea de ordenes y permitira:
// 
// 	a) Llamarlo sin ningun argumento. En este caso, los datos de entrada se leeran desde la entrada estandar.
// 
// 	b) Llamarlo con un argumento. El argumento corresponde al nombre del archivo con las lineas de entrada.
// 
// Las restricciones que se imponen, y que se deben cumplir en la resolucion son:
// 
// 	a) El fichero solo puede ser leido una unica vez, y no pueden copiarse completo en memoria.
// 
// 	b) Se desconoce a priori el numero de lineas del fichero.
// 
// 	c) Las lineas del fichero tiene una longitud indeterminada, aunque nunca mayor de 500.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char **argv) {
    ifstream fi;
    int valorGrupo;
    int valorSecuencia;
    int contGrupo;
    int contSecuencia;
    float valorReal;
    float suma;

    if (argc > 2) {
        cerr << "Error: numero de argumentos incorrecto, introducir uno o ninguno solamente" << endl;
        cerr << "Uso: " << argv[0] << "OPCIONAL:[ficheroEntrada]" << endl;
        exit(1);
    } else if (argc == 1) {
        cout << "Introduzca nueva linea de datos: " << endl;
        cout << "Numero de grupos: " << endl;
        cin >> valorGrupo;

        while (!cin.eof()) {

            contGrupo = 0;
            contSecuencia = 0;
            suma = 0.0;

            while (contGrupo < valorGrupo) {
                cout << "Numero de valores de la secuencia: " << endl;
                cin >> valorSecuencia;

                while (contSecuencia < valorSecuencia) {
                    cout << "Valores de la secuencia: " << endl;
                    cin >> valorReal;

                    suma += valorReal;

                    contSecuencia++;
                }

                contSecuencia = 0;

                cout << "\tSuma de los valores de la secuencia: " << setiosflags(ios::showpoint) << setprecision(2) << suma << endl << endl;

                suma = 0.0;

                contGrupo++;
            }

            cout << endl;

            cout << "Introduzca nueva linea de datos: " << endl;
            cout << "Numero de grupos: " << endl;
            cin >> valorGrupo;
        }
    } else {
        fi.open(argv[1], ios::in);

        if (!fi) {
            cerr << "Error: no se ha podido acceder al fichero de entrada " << argv[1] << endl;
            exit(1);
        }

        fi >> valorGrupo;

        while (!fi.eof()) {

            contGrupo = 0;
            contSecuencia = 0;
            suma = 0.0;

            while (contGrupo < valorGrupo) {
                fi >> valorSecuencia;

                while (contSecuencia < valorSecuencia) {
                    fi >> valorReal;

                    suma += valorReal;

                    contSecuencia++;
                }

                contSecuencia = 0;

                cout << '\t' << setiosflags(ios::showpoint) << setprecision(2) << suma;

                suma = 0.0;

                contGrupo++;
            }

            cout << endl;

            fi >> valorGrupo;

        }
    }

    fi.close();

    return (0);
}
