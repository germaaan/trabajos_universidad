#ifndef _MATRIZ2D
#define _MATRIZ2D
#include <iostream>

using namespace std;

typedef unsigned int** TipoBase;

class Matriz2D{
private:
	TipoBase datos;
	int unsigned filas;
	int unsigned columnas;

public:
	Matriz2D();
	Matriz2D(const unsigned int &fils, const unsigned int &cols);
	Matriz2D(const unsigned int &fils, const unsigned int &cols, const unsigned int &val);
	Matriz2D(const Matriz2D &otro);
	~Matriz2D();
	bool estaVacia();
	void PonValor(const unsigned int &fil, const unsigned int &col, const unsigned int &val);
	int LeeValor(const unsigned int &fil, const unsigned int &col);
	
	Matriz2D& operator =(const Matriz2D &otro);

	int& operator()(int, int);
	int operator()(int, int) const;

	friend Matriz2D operator +(const Matriz2D &otro);
	friend Matriz2D operator -(const Matriz2D &otro);

	bool operator ==(const Matriz2D &otro);
	bool operator !=(const Matriz2D &otro);

	friend ostream & operator << (ostream &out, const Matriz2D &m);

	void aumentarFilas();

private:
	void Copia(const Matriz2D &otro);
	void PideMemoria(const unsigned int &fils, const unsigned int &cols);
	void LiberaMemoria();
};

#endif
