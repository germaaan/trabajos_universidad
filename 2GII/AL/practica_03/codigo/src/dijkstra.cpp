#include <iostream>
#include <fstream>
#include <cstdlib>
#include "grafo_heap.h"

using namespace std;

#define TAM_BUFFER 50

int obtenerDimension(ifstream &flujo) {
    char buffer[TAM_BUFFER], aux;
    int cont = 0, dimension;

    flujo.seekg(0, ios::beg);

    //Nos movemos hasta la linea que tiene el valor del tamaño
    while (!flujo.eof() && cont < 3) {
        cont++;
        flujo.getline(buffer, TAM_BUFFER);

        //Nos movemos hasta la posicion del valor del tamaño
        if (cont == 3) {
            cont++;
            flujo.getline(buffer, TAM_BUFFER, ' ');

            while (!flujo.eof() && flujo.peek() == ' ')
                flujo.get(aux);
        }
    }

    //Leemos el valor de tamaño
    flujo.getline(buffer, TAM_BUFFER);
    dimension = atoi(buffer);

    return dimension;
}

void rellenarGrafo(grafo &G, ifstream &flujo) {
    char buffer[TAM_BUFFER], aux;
    int cont = 0, valor, posicion;
    bool orden, salto = false;

    flujo.seekg(0, ios::beg);

    //Nos movemos hasta la linea en la que empieza la matriz de adyacencias
    while (!flujo.eof() && cont < 7) {
        cont++;
        flujo.getline(buffer, TAM_BUFFER);

        //Nos movemos hasta la posición del primer valor
        if (cont == 7)
            while (!flujo.eof() && flujo.peek() == ' ')
                flujo.get(aux);
    }

    posicion = flujo.tellg();

    //Comprobamos el fichero que estamos leyendo para procesar los datos de una u otra forma	
    flujo.getline(buffer, TAM_BUFFER, ' ');
    valor = atoi(buffer);

    if (valor == 100000000)
        orden = true;
    else
        orden = false;

    flujo.seekg(posicion, ios::beg);

    //Vamos introduciendo las distancias entre los vertices	
    if (orden) {
        for (int i = 0; i < G.size(); i++) {
            int j = 0;

            while (j < G.size() && !flujo.eof()) {
                flujo.getline(buffer, TAM_BUFFER, ' ');
                valor = atoi(buffer);

                if (valor == 100000000) {
                    flujo.getline(buffer, TAM_BUFFER, ' ');
                    valor = atoi(buffer);
                }

                if (valor != 0) {
                    if (i == j) {
                        G.asignar_peso(i, j, 0);
                        G.asignar_peso(i, j, valor);
                    } else {
                        G.asignar_peso(i, j, valor);
                    }

                    j++;
                }
            }
        }
    } else {
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G.size(); j++) {
                flujo.getline(buffer, TAM_BUFFER, ' ');
                valor = atoi(buffer);

                if (i == j)
                    G.asignar_peso(i, j, 0);
                else
                    G.asignar_peso(i, j, valor);

                while (!flujo.eof() && flujo.peek() == ' ')
                    flujo.get(aux);
            }
        }
    }
}

void Dijkstra(grafo &G, vertice s) {
    vector<bool> seleccionado(G.size(), false); // Nodos incluidos en la solución
    vector<distancia> D(G.size(), INFINITO); // Distancias de los vertices
    heap Q(G.size()); // Pares (distancia,vertice) ordenados por distancia
    vector<vertice> P(G.size(), -1); // Vertices predecesores de cada vertice del camino mínimo
    pair<distancia, vertice> u; // Pareja distancia-vertice que representa el vertice candidato
    distancia distancia_candidata; // Distancia candidata a ser camino más corto
    vertice aux; // Valor de vertice del vertice candidato

    // Inicializamos al vertice de origen, siendo su padre el mismo y su distancia 0
    u.first = 0;
    u.second = s;
    D[s] = 0;
    P[s] = s;


    for (u.second = G.begin_ady(s); u.second != G.end_ady(s); u.second++) {
        u.first = G.devolver_peso(s, u.second);
        Q.insert(u.first, u.second); // Insertamos todos los vertices del grafo en el heap
    }

    while (!Q.empty()) {
        u = Q.erase_min(); // Sacamos vertice candidato, que será el que tenga la distancia más corta
        cout << "Nodo seleccionado " << u.second << " Distancia " << u.first << endl;
        aux = u.second;
        seleccionado[aux] = true;

        // Para cada nodo adyacente al vertice actual
        for (vertice v = G.begin_ady(aux); v != G.end_ady(aux); v++) {

            // Si no estaba ya incluido en la solución
            if (!seleccionado[v]) {
                // Calculamos la distancia candidata
                distancia_candidata = G.devolver_peso(s, aux) + G.devolver_peso(aux, v);

                // Si el valor actual es mayor, lo sustituimos
                if (D[v] > distancia_candidata) {
                    P[v] = aux;
                    D[v] = distancia_candidata;

                    // Actualizamos su información en el heap
                    if (Q.in_heap(v))
                        Q.update_heap(distancia_candidata, v);
                } else {
                    P[v] = aux;
                    D[v] = G.devolver_peso(s, aux);
                }
            }
        }
    }

    // Presentamos los resultados;
    cout << "Presentamos los resultados " << endl;
    for (int i = 0; i < G.size(); i++) {
        cout << " arco  (" << P[i] << "," << i << ") costo " << D[i] << endl;
    }
}

int main(int argc, char **argv) {
    ifstream flujo;
    int dimension;

    if (argc != 2) {
        cerr << "Error: Numero de parametros erroneo.\n";
        cerr << "Uso: " << argv[0] << " <ficheroGrafo>\n";
        exit(1);
    }

    flujo.open(argv[1], ios::in);

    if (!flujo) {
        cerr << "Error: No se pudo abrir " << argv[1] << endl;
        exit(1);
    }

    dimension = obtenerDimension(flujo);
    grafo G(dimension);
    rellenarGrafo(G, flujo);

    vertice s = 0;

    cout << "Tamaño del Grafo " << G.size() << endl;
    cout << "Llamo a Dijkstra (origen) " << s << endl;
    Dijkstra(G, s);

    flujo.close();

    return (0);
}
