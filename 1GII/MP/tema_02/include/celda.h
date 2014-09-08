#ifndef __CELDAS_H
#define __CELDAS_H

typedef double TipoBase;

struct _celda {
    TipoBase _dato;
    _celda * ss;
};

struct celdasEnlazadas {
    _celda * ini_lista;
    int _size;
};

// Inicializa la estructura de celdasEnlazadas enlazadas con cabecera
celdasEnlazadas inicializar();

// Devuelve el numero de elementos en las celdasEnlazadas
int size(const celdasEnlazadas *v);

// Inserta un elemento al final de las celdasEnlazadas e incrementa en uno el numero de elementos
void push_back(celdasEnlazadas *v, TipoBase x);

// Libera los recursos alojados por el celdasEnlazadas
void liberar(celdasEnlazadas * v);

// Devuelve el elemento en la posicion i-esima del celdasEnlazadas
TipoBase at(const celdasEnlazadas *v, int i);

celdasEnlazadas inic_sin();

void push_back_sin(celdasEnlazadas *c, TipoBase x);

void insertar_sin(celdasEnlazadas *c, int p, TipoBase x);


#endif
