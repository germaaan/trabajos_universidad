#include <iostream>
#include <stdlib.h>
#include "celda.h"

using namespace std;

celdasEnlazadas inicializar() {
    celdasEnlazadas salida;

    salida.ini_lista = new _celda;
    if (salida.ini_lista == 0) {
        cout << "Error de Memoria" << endl;
        exit(1);
    }
    salida.ini_lista->ss = 0;
    salida._size = 0;
    return salida;
}

celdasEnlazadas inic_sin() {
    celdasEnlazadas salida;

    salida.ini_lista = 0;
    salida._size = 0;

    return salida;
}

int size(const celdasEnlazadas *c) {
    return c->_size;
}

void push_back(celdasEnlazadas *c, TipoBase x) {
    _celda * aux;
    aux = c->ini_lista;
    while (aux->ss != 0)
        aux = aux->ss;
    aux->ss = new _celda;
    if (aux->ss == 0) {
        cout << "Error de Memoria" << endl;
        exit(1);
    }
    aux->ss->_dato = x;
    aux->ss->ss = 0;
    c->_size++;
}

void push_back_sin(celdasEnlazadas *c, TipoBase x) {
    _celda *aux;

    if ((*c).ini_lista == 0) {
        (*c).ini_lista = new _celda;
        (*c).ini_lista -> _dato = x;
        (*c).ini_lista -> ss = 0;
    } else {
        aux = (*c).ini_lista;

        while (aux->ss != 0)
            aux = aux->ss;

        aux->ss = new _celda;
        aux->ss->_dato = x;
        aux->ss->ss = 0;
    }

    (*c)._size++;
}

void insertar_sin(celdasEnlazadas *c, int p, TipoBase x) {
    _celda *aux, *n_celda;

    if (p == 1) {
        aux = new _celda;
        aux->_dato = x;
        aux->ss = (*c).ini_lista;
        (*c).ini_lista = aux;
    } else {
        aux = (*c).ini_lista;

        for (int i = 2; i < p; i++)
            aux = aux->ss;

        n_celda = new _celda;
        n_celda->_dato = x;

        n_celda->ss = aux->ss;
        aux->ss = n_celda;
    }

    (*c)._size++;
}

TipoBase at(const celdasEnlazadas *c, int i) {
    if (i < c->_size) {
        _celda *aux = c->ini_lista;
        for (int j = 0; j < i; j++)
            aux = aux->ss;
        return aux->ss->_dato;
    }
}

void liberar(celdasEnlazadas *c) {
    _celda * aux, *ant;

    aux = c->ini_lista;
    ant = aux;
    while (aux->ss != 0) {
        aux = aux->ss;
        delete ant;
        ant = aux;
    }
    c->ini_lista = 0;
    c->_size = 0;
}
