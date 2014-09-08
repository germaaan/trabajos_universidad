/**
 * @file conjunto.cpp
 * @brief implementación del TDA conjunto
 */
#include <cassert>
#include "vector_dinamico.h"
#include "conjunto.h"

conjunto::conjunto() {
    vector_dinamico v;
}

conjunto::conjunto(const conjunto &x) {
    vector_dinamico v(x.v);
}

void conjunto::insert(float x) {
    int posicion;

    if (v.size() == 0)
        v.push_back(x);
    else {

        if (!find(x)) {
            posicion = buscar_posicion(x);
            v.insert(posicion, x);
        }
    }
}

void conjunto::erase(float x) {
    int posicion;

    if (find(x)) {
        posicion = buscar_posicion(x);
        v.erase(posicion - 1);
    }
}

bool conjunto::find(float x) const {
    bool encontrado = false;
    int i = 0;

    while (!encontrado && i < v.size()) {
        if (v[i] == x)
            encontrado = true;
        else
            i++;
    }

    return encontrado;
}

const float & conjunto::operator[](int i) const {
    assert(i >= 0 && i < v.size());

    return v[i];
}

int conjunto::size() const {
    return v.size();
}

int conjunto::buscar_posicion(float x) {
    bool encontrado = false;
    int i = 0;

    while (!encontrado && i < v.size()) {
        if (v[i] > x)
            encontrado = true;
        else
            i++;
    }

    return i;
}
