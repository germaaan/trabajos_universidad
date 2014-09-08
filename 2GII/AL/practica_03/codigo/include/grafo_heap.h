#ifndef __GRAFOHEAP__
#define __GRAFOHEAP__

/**************************************************************************
 *
 *   Ejemplos de algoritmos greedy: PRIM                                   *
 *
 ***************************************************************************/

#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

#define INFINITO 1000
typedef int vertice;
typedef int distancia;

/*--- Grafo matricial basico -----------------------------------------------------------*/
class grafo {
public:
    grafo(int tama);
    int asignar_peso(int org, int dest, distancia w);
    double devolver_peso(int org, int dest) const;
    int size();
    vertice begin_ady(vertice i);
    vertice end_ady(vertice i);

private:
    vector< vector< distancia > > pesos;
};

class heap {
public:
    heap(int tama);
    bool in_heap(vertice v);
    void insert(distancia d, vertice v);
    void update_heap(distancia nueva, vertice v);
    bool empty() const;
    pair<distancia, vertice> erase_min();

private:
    vector<bool> dentro; // Nodos que estan en el heap
    set< pair<distancia, vertice> > heapD; //heap de distancias  -- vertice a incluir;
};

#endif
