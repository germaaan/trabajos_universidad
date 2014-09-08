// En C++, los tipos de datos simples como "int", "char", "double", etc, no son clases.
// Por tanto, si declaramos una variable real en la forma "double real", para calcular el
// seno de "real", llamamos a una funcion en la forma
// 
// 	double real, resultado;
// 	real = 6.5;
// 	resultado = sin(real);
// 
// Estamos interesados en construir una clase llamada "MiReal" para trabajar con reales
// al estilo de las clases. Por tanto, para calcular el seno de "6.5", deberiamos hacer algo
// como lo siguiente:
// 
//	MiReal real(6.5)
//	double resultado;
//	resultado = real.Seno();
//
// En esta caso, "Seno" es un metodo de la clase "MiReal" que devuelve un tipo "double".
// Construid dicha clase, proporcionando los siguientes metodos:
// 
//	a) Valor. Este metodo debe devolver el valor del real (6.5 en el ejemplo anterior)
// 
//	b) Seno. Para definirlo, llamad a la propia funcion "sin" de la biblioteca "cmath". Debe
//	   devolver un "double"
//
// 	c) "ValorAbsoluto". Devolvera un tipo "double" que contendra el valor absoluto del
//	   real. No pueden utilizarse las funciones de "cmath".
//
// Cread un programa principal que llame a dichos metodos.
// Observad que seria interesante que nuestro codigo fuese el siguiente:
//
// 	MiReal real(6.5);
// 	MiReal resultado;
// 	resultado = real.Seno();
// 	resultado = resultado + real;
// 
// Es decir, que el metodo "Seno" devolviese un tipo "MiReal" en vez de un tipo "double".
// Aunque esto es posible en C++, por ahora no disponemos de las herramientas necesarias 
// para hacerlo. Por ejemplo, para hacer la asignacion entre variables de tipo
// "MiReal" se necesita el concepto de sobrecarga del operador de asignacion y para
// realizar la suma de dos variables de tipo "MiReal" se necesita sobrecargar el operador
// + (se vera en el segundo cuatrimestre).
// 
// Nota. Este tipo de clases (MiEntero, MiReal, etc) son proporcionadas por Java de
// forma standard. En otros lenguajes como SmallTalk o plataformas como .NET (con
// lenguajes como Visual Basic, C#) no existe la diferencia entre tipos basicos (como
// "int", "double", etc) y todo son clases, siguiendo una filosofia orientada a objetos pura.
// 
// Finalidad: Entender las clases que actuan como envolventes (wrappers) de los tipos
// basicos. Dificultad Baja.


#include <iostream>
#include <cmath>
using namespace std;

class MiReal {
private:
    double real;

public:

    MiReal(double valorMiReal = 0)
    : real(valorMiReal) {
    }

    double Valor() {
        return real;
    }

    double Seno() {
        return sin(real);
    }

    int ValorAbsoluto() {
        int valorAbsoluto = real;

        if (valorAbsoluto < 0)
            valorAbsoluto = valorAbsoluto * (-1);

        return valorAbsoluto;

    }

};

int main() {
    double valorReal;

    cout << "Introduzca un valor real: ";
    cin >> valorReal;

    MiReal real(valorReal);

    double valor = real.Valor();
    double seno = real.Seno();
    int valorAbsoluto = real.ValorAbsoluto();

    cout << "Valor de MiReal: " << valor << endl;
    cout << "Seno de MiReal: " << seno << endl;
    cout << "Valor absoluto de MiReal: " << valorAbsoluto << endl;

    cout << "\n";
}
