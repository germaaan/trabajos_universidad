#ifndef __VECTORV3
#define __VECTORV3

class vector {
private:
    double *_m;
    int _size;
    int _capacity;

public:
    vector();
    int size();
    int capacity();
    void push_back(const double &x);
    void push_back_7(const double &x);
    void ampliar(int n);
    void print();
};

#endif
