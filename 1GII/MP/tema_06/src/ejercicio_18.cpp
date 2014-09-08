// Una empresa de distribucion mantiene la informacion acerca de sus vendedores, productos y ventas en ficheros
// informaticos. Los ficheros almacenan la informacion en formato binario y la estructura de los registros es:
// 
// 	Fichero Vendedores:
// 		RegVendedor: CodVendedor (unsigned char), Nombre (50*char) y CodZona (unsigned char).
// 
// 	Fichero Articulos:
// 		RegArticulo: CodArticulo (10*char), Descripcion (30*char) y PVP (float).
// 
// 	Fichero Ventas:
// 		RegVenta: NumFactura (int), CodVendedor (unsigned char), CodArticulo (10*char) y Unidades (int).
// 		Se supone que el fichero Ventas contiene las ventas realizadas en un mes.
// 
// Se trata de realizar programas para:
// 
// 	a) Mostrar el total (numero de ventas y cantidad total de ventas) de las ventas realizadas por un vendedor,
// 	   dado su codigo (CodVendedor).
// 
// 	b) Pedir una cantidad y crear un fichero (binario) llamado VendedoresVIP cuyos registros tengan la siguiente
// 	   estructura:
// 	   RegVendedorVIP: CodVendedor (unsigned char), CodZona (unsigned char), TotalVentas (float).
// 	   donde TotalVentas es la cantidad total de ventas realizadas por el vendedor.
// 	   El fichero VendedoresVIP tendra u ́nicamente los registros de los vendedores cuyo total de ventas sea superior
// 	   a la cantidad leida.


#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct RegVendedor {
    unsigned char CodVendedor;
    char Nombre[50];
    unsigned char CodZona;
};

struct RegArticulo {
    char CodArticulo[10];
    char Descripcion[30];
    float PVP;
};

struct RegVenta {
    int NumFactura;
    unsigned char CodVendedor;
    char CodArticulo[10];
    int Unidades;
};

struct RegVendedorVIP {
    unsigned char CodVendedor;
    unsigned char CodZona;
    float TotalVentas;
};

int main(int argc, char **argv) {
    ifstream fi;
    ofstream fo;
    const int TAM_BUFFER_VENTAS = 1024 / sizeof (RegVenta);
    RegVenta bufferVentas[TAM_BUFFER_VENTAS];

    unsigned char vendedorBuscado = 'a';

    int numVentas = 0;
    int cantVentas = 0;

    fi.open("Ventas", ios::in);

    if (!fi) {
        cerr << "Error: no se pudo acceder al fichero Ventas ." << endl;
        exit(1);
    }

    while (!fi.eof()) {
        fi.read((char *) &bufferVentas, TAM_BUFFER_VENTAS);

        for (int i = 0; i < fi.gcount() / sizeof (RegVenta); i++) {
            if (bufferVentas[i].CodVendedor == vendedorBuscado) {
                numVentas++;
                cantVentas += bufferVentas[i].Unidades;
            }
        }
    }

    fo.open("VendedoresVIP", ios::in);

    if (!fo) {
        cerr << "Error: no se pudo acceder al fichero VendedoresVIP ." << endl;
        exit(1);
    }

    return (0);
}
