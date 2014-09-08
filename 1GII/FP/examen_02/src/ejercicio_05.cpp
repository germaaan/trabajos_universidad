// [ciclica] Escribir un programa para determinar si una secuencia de letras C1 contiene a otra
// secuencia C2 en el mismo orden (no tienen que estar consecutivos) y de forma ciclica. Para que
// se cumpla este criterio se deben satisfacer las siguientes condiciones
// 
// 	• Todos los caracteres de C2 deben estar en C1
// 
// 	• Deben estar en el mismo orden aunque no de forma consecutiva
// 
// 	• Si durante la busqueda se ha llegado al final de la secuencia C1, se debe proseguir la
// 	  busqueda por el inicio de C1, pero sin sobrepasar la posicion en la que hubo la primera
// 	  concordancia.
// 
// Se muestran algunos ejemplos en los que la secuencia C1 contiene a C2:
// 
// 	• C1 = xzayobnmcpwqdfg				C2 = abcd
// 	• C1 = ftkcpxqdhjzaxqoblki			C2 = abcd
// 	• C1 = tzsbluyclpygdmngrafvc		C2 = abcd
// 
// Hay que destacar que la primera letra de C2 a buscar en C1 podria estar en cualquier sitio. Por
// ejemplo, para el siguiente caso:
// 
// 	• C1 = bghcjadxak					C2 = abcd
// 
// podemos ver que a partir de la primera a de C1 no podemos encontrar C2 de forma ciclica,
// aunque si lo podemos hacer a partir de la segunda a de C1.
// 
// Tambien puede darse el caso de que C1 no contenga a C2 de forma ciclica aunque incluya todas
// sus letras, como muestra el siguiente ejemplo:
// 
// 	• C1 = tzsbluyclpcaygdmxngrfvc		C2 = abcd
// 
// Los datos de entrada al programa se deben dar en el siguiente orden:
// 
// 	a) Caracter terminador que representa el final de la secuencia de letras.
// 
// 	b) Conjunto de letras C1 con un terminador al final (el terminador no forma parte de la
// 	secuencia).
// 
// 	c) Conjunto de letras C2 con un terminador al final (el terminador no forma parte de la
// 	secuencia).
// 
// Restricciones del problema:
// 
// 	a) Debe implementar una clase SecuenciaLetras que almacene la secuencia de letras
// 	y que incorpore la funcionalidad necesaria para que podamos consultar si una secuencia
// 	contiene de forma ciclica a otra secuencia.
// 
// 	b) No se admitira que la entrada o la salida de datos se realice dentro de la clase que incorpora
// 	la funcionalidad para resolver este problema. Esas operaciones se resolveran fuera de la
// 	clase.
// 
// Ejemplo de fichero de validacion:
// 	#ftkcpxqdhjzaxqoblki#abcd#
// 
// Salida del programa: El caracter S, si se cumple la condicion del problema, o el caracter N,
// en caso contrario.
// 	S


#include <iostream>
#include <stdexcept>
using namespace std;

class SecuenciaLetras {
private:
    static const int TAMANIO = 50;
    char vectorC1[TAMANIO];
    char vectorC2[TAMANIO];
    int totalUtilizadosC1;
    int totalUtilizadosC2;

public:

    SecuenciaLetras()
    : totalUtilizadosC1(0),
    totalUtilizadosC2(0) {
    }

    void Aniade(int secuencia, char letra) {

        if (secuencia == 1) {

            if (totalUtilizadosC1 < TAMANIO) {
                vectorC1[totalUtilizadosC1] = letra;
                totalUtilizadosC1++;
            } else
                throw logic_error("No hay componentes suficientes.");
        } else {

            if (totalUtilizadosC2 < TAMANIO) {
                vectorC2[totalUtilizadosC2] = letra;
                totalUtilizadosC1++;
            } else
                throw logic_error("No hay componentes suficientes.");
        }

    }

    char BuscaSecuencia() {
        int posBusqueda;
        int posPrimeraConcordancia;
        int posValorBuscado = 0;
        bool encontrado = false;
        char resultado;

        for (posBusqueda = 0; (posBusqueda < totalUtilizadosC1) && !encontrado; posBusqueda++) {

            if (vectorC1[posBusqueda] == vectorC2[posValorBuscado]) {
                posPrimeraConcordancia = posBusqueda;
                posValorBuscado++;
            }

            if (posValorBuscado == totalUtilizadosC2)
                encontrado = true;

            if ((posBusqueda == (totalUtilizadosC1 - 1)) || (posValorBuscado > 0))
                posBusqueda = posPrimeraConcordancia;
            else
                encontrado = true;

        }

        if (encontrado)
            resultado = 'S';
        else
            resultado = 'N';

        return resultado;
    }

};

int main() {
    SecuenciaLetras secuencia;
    char valorLeido;
    char resultado;


    resultado = secuencia.BuscaSecuencia();

    cout << resultado;
}
