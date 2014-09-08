// Construid una clase "Fecha" para gestionar una fecha, la cual se especificara con tres
// enteros: dia, mes y año. En el constructor de la clase comprobaremos que los tres
// datos anteriores son correctos. Hay que tener en cuenta, por ejemplo, que Febrero
// solo tiene 28 dias, salvo los años bisiestos, en los que tiene 29.
// 
// Finalidad: Trabajar con constructores que determinan la correcta creacion del objeto.
// Dificultad Media.


#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:

    Fecha(int d = 0, int m = 0, int a = 0)
    : dia(d),
    mes(m),
    anio(a) {
        if (anio <= 0)
            anio = 0;

        if ((mes <= 0) || (mes > 12))
            mes = 0;

        switch (mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if ((dia <= 0) || (dia > 31))
                    dia = 0;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if ((dia <= 0) || (dia > 30))
                    dia = 0;
                break;
            case 2:
                if (anio % 4 != 0) {
                    if ((dia <= 0) || (dia > 28))
                        dia = 0;
                } else {
                    if ((dia <= 0) || (dia > 29))
                        dia = 0;
                }
                break;
        }
    }

    int GetDia() {
        return dia;
    }

    int GetMes() {
        return mes;
    }

    int GetAnio() {
        return anio;
    }
};

int main() {
    int d;
    int m;
    int a;
    bool es_fecha_validad = true;

    do {
        cout << "\n\nIntroduzca año (tiene que ser mayor que 0): ";
        cin >> a;

        cout << "Introduzca mes (1-12): ";
        cin >> m;

        cout << "Introduzca dia (entre 1 y 28-31 dependiendo del mes): ";
        cin >> d;

        Fecha fecha(d, m, a);

        if ((fecha.GetDia() == 0) || (fecha.GetMes() == 0) || (fecha.GetAnio() == 0))
            es_fecha_validad = false;
    } while (!es_fecha_validad);

    cout << "\n\n";
}
