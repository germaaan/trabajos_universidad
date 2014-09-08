#ifndef BIGINT_H
#define BIGINT_H
#include <vector>
#include <iostream>
#include <string>

// TDA para representar enteros positivos con un número indeterminado de cifras
// FA: los numeros se guardan de izquierda a derecha de dígito menos significativo a más significativo
// IR: digitos[digitos.size()-1]!=0
// @author Miguel García Silvente
// @date 27-03-2012

using namespace std;

class bigint {
public:
    /**
    @brief constructor por defecto
     */
    bigint();

    /**
    @brief constructor a partir de un int
    @param x número entero
     */
    bigint(int x);
    bigint(const char *s);
    bigint(const string &s);
    bigint operator+(const bigint &x) const;
    bigint operator-(const bigint &x) const;
    bigint operator*(const int x) const;
    bigint operator*(const bigint &x) const;
    bool operator<(const bigint &x) const;
    bool operator==(const bigint &x) const;
    bigint operator-() const;

    /**
    @brief Devuelve un bigint con los digitos comprendidos entre a y b (incluidos)
     */
    bigint digits(unsigned int a, unsigned int b) const;

    unsigned int size() const {
        return digitos.size();
    }

    ~bigint();
private:
    vector<unsigned char> digitos;
    char signo; // 1 es positivo y -1 es negativo

    bigint resta(const bigint &x) const;


    friend ostream& operator<<(ostream &os, const bigint &x);
};

ostream& operator<<(ostream &os, const bigint &x);

#endif // BIGINT_H
