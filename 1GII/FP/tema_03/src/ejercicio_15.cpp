// Una empresa quiere gestionar las nominas de sus empleados. El computo de la
// nomina se realiza en base a los siguientes criterios:
// 
// 	a) Hay cuatro tipos de categorias laborales: Operario, Base, Administrativo y Directivo.
// 
// 	b) Se parte de un salario base que depende de la antigüedad del trabajador y de
// 	   su categoria laboral. Para la categoria Operario, el salario base es de 900 euros,
// 	   1100 el puesto Base, 1200 los Administrativos y 2000 los Directivos. Dicho salario
// 	   base se incrementa con un tanto por ciento igual al numero de años trabajados.
// 
// 	c) Los trabajadores tienen complementos en su nomina por el numero de horas
// 	   extraordinarias trabajadas. La hora se paga distinta segun la categoria: 16 euros
// 	   por hora para los operarios, 23 para el puesto Base, 25 los Administrativos y 30
// 	   los Directivos. Ademas, al complemento que sale al computar el numero de horas
// 	   extraordinarias, se le aplica una subida con un tanto por ciento igual al numero
// 	   de años trabajados.
// 
// Se pide diseñar la interfaz de una clase (tambien hay que incluir los datos miembro
// privados) para poder trabajar con esta informacion. No se pide implementar la clase,
// unicamente determinar la interfaz.
// 
// Finalidad: Diseñar la interfaz de una clase. Dificultad Media.


#include <iostream>
using namespace std;

class GestionNominas {
private:
    static const int OPERARIO = 1;
    static const int BASE = 2;
    static const int ADMINISTRATIVO = 3;
    static const int DIRECTIVO = 4;
    int categoriaLaboral;
    int aniosTrabajados;
    int horasExtraTrabajadas;
    double salarioBase;
    double complementoHorasExtras;

public:

    GestionNominas(int tipoCategoria, int cantidadHoras = 0, int cantidadAnios = 0)
    : categoriaLaboral(tipoCategoria),
    horasExtraTrabajadas(cantidadHoras),
    aniosTrabajados(cantidadAnios) {
        if (tipoCategoria == OPERARIO) {
            salarioBase = 900;
            complementoHorasExtras = horasExtraTrabajadas * 16;
        }

        if (tipoCategoria == BASE) {
            salarioBase = 1100;
            complementoHorasExtras = horasExtraTrabajadas * 23;
        }

        if (tipoCategoria == ADMINISTRATIVO) {
            salarioBase = 1200;
            complementoHorasExtras = horasExtraTrabajadas * 25;
        }

        if (tipoCategoria == DIRECTIVO) {
            salarioBase = 2000;
            complementoHorasExtras = horasExtraTrabajadas * 30;
        }

        salarioBase = salarioBase + salarioBase * (1 + (aniosTrabajados) / 100.0);
        complementoHorasExtras = complementoHorasExtras + complementoHorasExtras * (1 + (aniosTrabajados) / 100.0);
    }
};

int main() {

    cout << "\n\n";
}
