#include <iostream>
/*
 Este programa trata mantener dos variables, la primera 
 realiza la multiplicación de valores.
 La segunda ...
 */

/* Incrementa en 2 una variable */
int cuenta(int y) {
    int tmp;

    tmp = y + 2;

    /* break */

    return tmp;
}

/* Calcula la multiplicación de dos números */
int multiplica(int x, int y) {
    int final;
    int i;

    final = 0;
    for (i = 0; i < x; i++) {
        /* break */
        final = final + y;
    }

    return final;
}

int main(void) {
    int final1;
    int final2;
    int i;

    /* break */
    final1 = multiplica(3, 2);

    for (i = 0; i < 100; i++)
        /* break */
        final2 = cuenta(i);

    std::cout << final1 << "\n";

    return 0;
}