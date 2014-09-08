// [permutacion] Una permutacion de un conjunto de enteros, C = {1, · · · , n}, tiene l lecturas,
// si para leer sus elementos en orden creciente (de izquierda a derecha) tenemos que recorrer la
// permutacion l veces. Por ejemplo, la siguiente permutacion del conjunto {1, . . . , 9}:
// 
// 	4 9 1 8 2 5 3 6 7
// 
// necesita 4 lecturas. En la primera obtendriamos 1, 2 y 3. En la segunda 4, 5, 6 y 7. En la tercera
// 8. Y finalmente, en la cuarta 9.
// 
// Implementa un programa que lea un conjunto de enteros y que muestre el numero de lecturas
// de dicha permutacion.
// 
// Los datos de entrada al programa se deben dar en el siguiente formato:
// 
// 	a) El cardinal n del conjunto C.
// 
// 	b) La permutacion: una secuencia de numeros enteros distintos entre 1 y n.
// 
// Restricciones del problema:
// 
// 	a) Debe implementar una clase “Permutacion”. Dicha clase debe incorporar la funcionalidad
// 	necesaria para resolver el problema.
// 
// 	b) No se permite declarar vectores fuera de la clase “Permutacion”.
// 
// 	c) No se admitira que la entrada o la salida de datos se realice dentro de la clase que incorpora
// 	la funcionalidad para resolver este problema. Esas operaciones se resolveran fuera de la
// 	clase.
// 
// 	d) Observe que, por definicion, en un “conjunto” de numeros no existen elementos repetidos.
// 
// Ejemplo de fichero de validacion:
// 	9
// 	4 9 1 8 2 5 3 6 7
// 
// Salida del programa: El numero de lecturas de la permutacion.
// 	4


#include <iostream>
#include <stdexcept>
using namespace std;

class Permutacion {
private:
    static const int TAMANIO = 50;
    int vectorPermutacion[TAMANIO];
    int totalUtilizados;

public:

    Permutacion()
    : totalUtilizados(0) {
    }

    bool BusquedaValores(int valorBuscado) {
        bool encontrado = false;

        for (int i = 0; i < totalUtilizados && !encontrado; i++) {
            if (valorBuscado == vectorPermutacion[i])
                encontrado = true;
        }

        return encontrado;
    }

    void Aniade(int valorAniadir) {
        if (totalUtilizados < TAMANIO) {
            vectorPermutacion[totalUtilizados] = valorAniadir;
            totalUtilizados++;
        } else
            throw logic_error("No hay componentes suficientes");
    }

    int CalcularLecturas() {
        bool lecturaCompletada = false;
        int valorBuscado = 1;
        int numeroLecturas = 0;

        while (!lecturaCompletada) {
            for (int i = 0; i < totalUtilizados; i++) {
                if (valorBuscado == vectorPermutacion[i])
                    valorBuscado++;
            }

            numeroLecturas++;

            if (valorBuscado == totalUtilizados + 1)
                lecturaCompletada = true;
        }

        return numeroLecturas;
    }
};

int main() {
    int cardinal;
    Permutacion permutacion;
    bool valorExistenteConjunto;
    int valorAniadir;
    int numeroLecturas;

    cin >> cardinal;

    for (int i = 1; i <= cardinal; i++) {
        cin >> valorAniadir;

        if (valorAniadir >= 1) {
            valorExistenteConjunto = permutacion.BusquedaValores(valorAniadir);

            if (!valorExistenteConjunto) {
                try {
                    permutacion.Aniade(valorAniadir);
                } catch (logic_error excepcion) {
                    cout << "Error logico: " << excepcion.what();
                }
            }
        }
    }

    numeroLecturas = permutacion.CalcularLecturas();

    cout << numeroLecturas;

    cout << "\n\n";
}
