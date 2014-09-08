#ifndef __VECTOR_H
#define __VECTOR_H

typedef double TipoBase;

class vector {
public:
    // Inicializa el vector con capacidad para alojar n elementos del TipoBase
    vector(int n);

    // Devuelve el numero de elementos en el vector
    int size();

    // Devuelve la capacidad del vector
    int capacity();


    // Inserta un elemento al final del vector, e incrementa en uno su tamaño
    void push_back(TipoBase x);

    // Libera los recursos alojados por el vector
    void liberar();

    // Devuelve el elemento en la posicion i-esima del vector
    TipoBase at(int i);


private:
    // Aumenta el tamaño del vector para alojar n elementos, el size no cambia
    void realojar(int n);

    TipoBase * _datos;
    int _size;
    int _capacity;
};


#endif