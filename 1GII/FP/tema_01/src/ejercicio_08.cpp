// Realizar un programa que declare las variables 1 , 2 y 3 , les asigne los valores 10, 20
// y 30 e intercambien entre si sus valores de forma que el valor de 1 pasa a 2 , el de 2
// pasa a 3 y el valor de 3 pasa a 1 (se pueden declarar variables auxiliares aunque se
// pide que se use el menor numero posible).
// 
// Finalidad: Mostrar la importancia en el orden de las asignaciones. Dificultad Media.
//

int main() {
    int x = 10;
    int z = 20;
    int y = 30;

    int copia1;
    int copia2;
    int copia3;

    copia1 = y;
    y = x;
    copia2 = z;
    z = copia1;
    x = copia2;
}
