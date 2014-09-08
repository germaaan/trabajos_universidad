// Se pide crear una clase "Conjunto_3_Valores" que represente un conjunto de 3
// valores de tipo "double", sobre los que se quiere realizar las operaciones de calcular
// el maximo y la media aritmetica. Para ello, haced lo siguiente:
// 
// 	a) Definid en primer lugar la clase con tres datos miembro publicos llamados "uno",
// 	   "dos" y "tres". A esta primera version de la clase, dadle el nombre
// 	   "Conjunto_3_Valores_vs1".
// 	   Añadid un metodo publico "Max". Este metodo tendra la siguiente cabecera:
// 	   		"double Max()"
// 	   Observad que el metodo "Max" actua sobre los datos de la clase ("uno", "dos" y 
// 	   "tres") por lo que no tiene parametros. Observad la diferencia con la cabecera del
// 	   ejercicio 2 en el que "Max" era una funcion que no estaba dentro de ninguna clase.
// 
// 	b) Añadid ahora un metodo para calcular la media aritmetica de los tres valores.
// 
// 	c) Cread un "main" que llame a los metodos anteriores.
// 	   Comprobad que podemos modificar directamente los datos miembro publicos
// 	   desde el "main", lo cual no es muy recomendable como ya se ha visto en clase de
// 	   teoria. Para resolver este problema, hacemos lo siguiente:
// 
// 	d) Copiad el codigo de la clase anterior y copiadlo dentro de una nueva clase llamada
// 	   "Conjunto_3_Valores_vs2".
// 	   En esta nueva version, declarad los datos miembro como "private", en vez de
// 	   "public". Comprobad que ya no podemos acceder a ellos desde el "main", por lo
// 	   que necesitamos asignarles un valor de otra forma. Para ello, haced lo siguiente:
// 
// 			I) Añadid un constructor a la clase "Conjunto_3_Valores_vs2". En dicho
// 			constructor, pasaremos los tres valores que habra que asignarselos a los
// 			datos miembro (usad la lista de inicializacion, que va precedida de dos puntos).
// 			Cread el objeto correspondiente desde el "main" (el compilador nos obligara a
// 			pasar los tres valores en el constructor)
// 
// 			II) Añadid tres metodos (GetPrimero(), GetSegundo(), GetTercero())
// 			que devuelvan los correspondientes datos miembro, para que asi pueda
// 			consultarse su valor desde el "main".
// 
// 	e) Supongamos que creamos un objeto con los valores 2, 5, 7. Si ahora quisieramos
// 	   cambiar de conjunto de datos y trabajar con 3, 9, 1, por ejemplo, tendriamos
// 	   que crear otro objeto distinto. Esto es completamente licito. En cualquier
// 	   caso, dependiendo del problema que estemos abordando, podriamos estar interesados
// 	   en permitir cambiar los datos del objeto (su estado) y asi no tener que
// 	   crear otro objeto distinto. Para ello, debemos proporcionar dicha funcionalidad a
// 	   la clase. Lo hacemos de tres formas alternativas:
// 
// 		• Creamos la clase
// 		  "Conjunto_3_Valores_vs3"
// 		  que contendra el mismo codigo que "Conjunto_3_Valores_vs2" y le añadimos
// 		  un metodo "SetValores" que cambie los tres valores a la vez (como ha
// 		  cambiado el nombre de la clase, habra que cambiar el nombre del
// 		  constructor). Cread un objeto de esta clase desde el "main" y llamad a sus
// 		  metodos.
// 		  En esta solucion, asignamos (dentro del constructor) un primer valor a cada
// 		  uno de los tres datos miembro y posteriormente permitimos su modificacion
// 		  a traves del metodo "SetValores". Solo permitimos la modificacion conjunta
// 		  de los tres datos miembro a la misma vez.
// 
// 		• Alternativamente, creamos la clase
// 		  "Conjunto_3_Valores_vs4"
// 		  que contendra el mismo codigo que "Conjunto_3_Valores_vs3", salvo que
// 		  suprimimos el constructor de la clase. Modificad convenientemente el "main".
// 		  En esta solucion, los tres datos miembro solo los podemos asignar con el
// 		  metodo nuevo "SetValores". Solo permitimos la modificacion conjunta de
// 		  los tres datos miembro a la misma vez.
// 
// 		• Alternativamente, creamos la clase
// 		  "Conjunto_3_Valores_vs5"
// 		  que contendra el mismo codigo que "Conjunto_3_Valores_vs4", pero
// 		  suprimimos el metodo "SetValores", y le añadimos tres metodos nuevos
// 		  "SetPrimero", "SetSegundo", "SetTercero", para que cambien cada uno de
// 		  los valores de forma independiente. Cread un objeto de esta clase desde el
// 		  main y llamad a sus metodos.
// 		  En esta solucion, los tres datos miembro solo los podemos asignar a traves
// 		  de un metodo especifico para cada uno de ellos.
// 
// 	   Observad la flexibilidad que me ofrece el concepto de clase. El programador 
// 	   decide como quiere que se acceda a los datos miembro: prohibiendo cambiar los
// 	   datos miembro una vez que se ha construido el objeto (version 2) o permitiendolo,
// 	   bien todos a la vez (versiones 3 y 4) o uno a uno (version 5).
// 
// 	f) Modificad ahora cualquiera de las clases anteriores para implementar el metodo
// 	   "Max" de otra forma distinta. Lo haremos llamando a un metodo "Max2valores"
// 	   que sera privado a la clase. Como el metodo añadido es privado y la cabecera del
// 	   metodo "Max" no varia, no tenemos que cambiar ni una linea de codigo del "main".
// 	   Esto nos permite independizar el desarrollo del programa "main" del desarrollo de
// 	   la clase, lo cual es vital en un entorno profesional de programacion. Esto es otro
// 	   ejemplo de las ventajas de la ocultacion de informacion (conseguido por el ambito
// 	   "private")
// 
// Finalidad: Trabajar con los conceptos basicos de clases. Dificultad Baja.
// 
// A partir de ahora, todos los ejercicios deben resolverse utilizando
// unicamente datos miembro privados.


#include <iostream>
using namespace std;

class Conjunto_3_Valores_vs1 {
public:
    double uno;
    double dos;
    double tres;

    double Max() {
        double max = uno;

        if (dos > max)
            max = dos;

        if (tres > max)
            max = tres;

        return max;
    }

    double Media() {
        double media;

        media = (uno + dos + tres) / 3;

        return media;
    }
};

class Conjunto_3_Valores_vs2 {
private:
    double uno;
    double dos;
    double tres;

public:

    Conjunto_3_Valores_vs2(double primero, double segundo, double tercero)
    : uno(primero),
    dos(segundo),
    tres(tercero) {
    }

    double GetPrimero() {
        return uno;
    }

    double GetSegundo() {
        return dos;
    }

    double GetTercero() {
        return tres;
    }

    double Max() {
        double max = uno;

        if (dos > max)
            max = dos;

        if (tres > max)
            max = tres;

        return max;
    }

    double Media() {
        double media;

        media = (uno + dos + tres) / 3;

        return media;
    }
};

class Conjunto_3_Valores_vs3 {
private:
    double uno;
    double dos;
    double tres;

public:

    Conjunto_3_Valores_vs3()
    : uno(2),
    dos(5),
    tres(7) {
    }

    void SetValores(double primero, double segundo, double tercero) {
        uno = primero;
        dos = segundo;
        tres = tercero;
    }

    double GetPrimero() {
        return uno;
    }

    double GetSegundo() {
        return dos;
    }

    double GetTercero() {
        return tres;
    }

    double Max() {
        double max = uno;

        if (dos > max)
            max = dos;

        if (tres > max)
            max = tres;

        return max;
    }

    double Media() {
        double media;

        media = (uno + dos + tres) / 3;

        return media;
    }
};

class Conjunto_3_Valores_vs4 {
private:
    double uno;
    double dos;
    double tres;

public:

    void SetValores(double primero, double segundo, double tercero) {
        uno = primero;
        dos = segundo;
        tres = tercero;
    }

    double GetPrimero() {
        return uno;
    }

    double GetSegundo() {
        return dos;
    }

    double GetTercero() {
        return tres;
    }

    double Max() {
        double max = uno;

        if (dos > max)
            max = dos;

        if (tres > max)
            max = tres;

        return max;
    }

    double Media() {
        double media;

        media = (uno + dos + tres) / 3;

        return media;
    }
};

class Conjunto_3_Valores_vs5 {
private:
    double uno;
    double dos;
    double tres;

    double Max2valores(double a, double b) {
        double max = a;

        if (b > max)
            max = b;

        return max;
    }

public:

    void SetPrimero(double primero) {
        uno = primero;
    }

    void SetSegundo(double segundo) {
        dos = segundo;
    }

    void SetTercero(double tercero) {
        tres = tercero;
    }

    double GetPrimero() {
        return uno;
    }

    double GetSegundo() {
        return dos;
    }

    double GetTercero() {
        return tres;
    }

    double Max() {
        double max;

        max = Max2valores(uno, dos);
        max = Max2valores(max, tres);

        return max;
    }

    double Media() {
        double media;

        media = (uno + dos + tres) / 3;

        return media;
    }
};

int main() {
    Conjunto_3_Valores_vs1 primer_conjunto;
    Conjunto_3_Valores_vs2 segundo_conjunto(3, 5, 8);
    Conjunto_3_Valores_vs3 tercer_conjunto;
    Conjunto_3_Valores_vs4 cuarto_conjunto;
    Conjunto_3_Valores_vs5 quinto_conjunto;
    double max;
    double media;

    primer_conjunto.uno = 10;
    primer_conjunto.dos = 7;
    primer_conjunto.tres = 9;

    max = primer_conjunto.Max();
    media = primer_conjunto.Media();

    cout << "\nLos 3 valores del primer conjunto: " << primer_conjunto.uno << " " << primer_conjunto.dos << " " << primer_conjunto.tres << endl;
    cout << "Valor maximo del primer conjunto: " << max << endl;
    cout << "Media aritmetica del primer conjunto: " << media << endl;

    max = segundo_conjunto.Max();
    media = segundo_conjunto.Media();

    cout << "\nLos 3 valores del segundo conjunto: " << segundo_conjunto.GetPrimero() << " " << segundo_conjunto.GetSegundo() << " " << segundo_conjunto.GetTercero() << endl;
    cout << "Valor maximo del segundo conjunto: " << max << endl;
    cout << "Media aritmetica del segundo conjunto: " << media << endl;

    max = tercer_conjunto.Max();
    media = tercer_conjunto.Media();

    cout << "\nLos 3 valores actuales del tercer conjunto: " << tercer_conjunto.GetPrimero() << " " << tercer_conjunto.GetSegundo() << " " << tercer_conjunto.GetTercero() << endl;
    cout << "Valor maximo del tercer conjunto: " << max << endl;
    cout << "Media aritmetica del tercer conjunto: " << media << endl;

    tercer_conjunto.SetValores(3, 9, 1);
    max = tercer_conjunto.Max();
    media = tercer_conjunto.Media();

    cout << "\nLos 3 valores cambiados del tercer conjunto: " << tercer_conjunto.GetPrimero() << " " << tercer_conjunto.GetSegundo() << " " << tercer_conjunto.GetTercero() << endl;
    cout << "Valor maximo del tercer conjunto: " << max << endl;
    cout << "Media aritmetica del tercer conjunto: " << media << endl;

    cuarto_conjunto.SetValores(11, 17, 2);
    max = cuarto_conjunto.Max();
    media = cuarto_conjunto.Media();

    cout << "\nLos 3 valores del cuarto conjunto: " << cuarto_conjunto.GetPrimero() << " " << cuarto_conjunto.GetSegundo() << " " << cuarto_conjunto.GetTercero() << endl;
    cout << "Valor maximo del cuarto conjunto: " << max << endl;
    cout << "Media aritmetica del cuarto conjunto: " << media << endl;

    quinto_conjunto.SetPrimero(17);
    quinto_conjunto.SetSegundo(32);
    quinto_conjunto.SetTercero(14);
    max = quinto_conjunto.Max();
    media = quinto_conjunto.Media();

    cout << "\nLos 3 valores del quinto conjunto: " << quinto_conjunto.GetPrimero() << " " << quinto_conjunto.GetSegundo() << " " << quinto_conjunto.GetTercero() << endl;
    cout << "Valor maximo del quinto conjunto: " << max << endl;
    cout << "Media aritmetica del quinto conjunto: " << media << endl;

    cout << "\n";
}
