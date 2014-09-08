#include "grafo_heap.h"

grafo::grafo(int tama) {
    pesos.resize(tama);
    for (int i = 0; i < tama; i++)
        pesos[i].resize(tama, 0);
}

int grafo::asignar_peso(int org, int dest, distancia w) {
    pesos[org][dest] = w;
}

double grafo::devolver_peso(int org, int dest) const {
    return pesos[org][dest];
}

int grafo::size() {
    return pesos.size();
}

vertice grafo::begin_ady(vertice i) //primer adyacente
{
    return 0;
}

vertice grafo::end_ady(vertice i) {
    return pesos.size();
}

heap::heap(int tama) {
    dentro.resize(tama, false);
}

bool heap::in_heap(vertice v) {
    return dentro[v];
}

void heap::insert(distancia d, vertice v) {
    pair<distancia, vertice> aux;
    aux.first = d;
    aux.second = v;
    heapD.insert(aux);
    dentro[v] = true;
}

void heap::update_heap(distancia nueva, vertice v) {
    set< pair<distancia, vertice> >::iterator it;
    pair<distancia, vertice> aux;

    for (it = heapD.begin(); it != heapD.end() && it->second != v; ++it);
    //Buscamos el vertice
    if (it == heapD.end()) {
        cout << "Error, intento de actualizar un elemento que no esta en heap " << endl;
        exit(0);
    }
    heapD.erase(it);
    aux.first = nueva;
    aux.second = v;
    heapD.insert(aux);

}

bool heap::empty() const {
    return heapD.empty();
}

pair<distancia, vertice> heap::erase_min() {

    pair<distancia, vertice> aux;
    aux = *(heapD.begin()); // EL menor en el heap (borrar el minimo)
    heapD.erase(heapD.begin());
    return aux;
}