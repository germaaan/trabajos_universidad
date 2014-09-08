#ifndef __VECTORV2
#define __VECTORV2

typedef double TipoBase;

struct vector {
    TipoBase * datos;
    int _size;
    int _capacity;
};

// Inicializa el vector con capacidad para alojar n elementos del TipoBase
vector inicializar(int n);

// Devuelve el numero de elementos en el vector
int size(const vector *v);

// Devuelve la capacidad del vector
int capacity(const vector *v);

// Aumenta el tamaño del vector para alojar n elementos, el size no cambia
void realojar(vector *v, int n);

// Inserta un elemento al final del vector, e incrementa en uno su tamaño
void push_back(vector *v, TipoBase x);

// Libera los recursos alojados por el vector
void liberar(vector * v);

// Devuelve el elemento en la posicion i-esima del vector
TipoBase at(const vector *v, int i);

//Reserva memoria para n elementos
void reservar(vector *v, int n);

#endif
