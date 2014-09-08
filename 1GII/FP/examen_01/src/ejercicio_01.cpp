// [buscar cadena] Queremos comprobar si las letras de una palabra se en
// encuentran dentro de un conjunto de palabras que van a continuacion. Desde
// la entrada estandar leeremos al principio un total de 3 letras que forman la
// palabra a buscar, por ejemplo f e o. Siempre habra, exactamente, tres
// letras. A continuacion, se introducira el conjunto de palabras en el que vamos
// a buscar. El final de cada palabra viene determinado por la aparicion del
// caracter ’@’, y el final del conjunto de palabras por el caracter ’#’. La
// busqueda tendra las siguientes restricciones:
// 
// 	• Deben encontrarse las tres letras
// 
// 	• Debe respetarse el orden de aparicion. Es decir, si por ejemplo
// 	  encontramos la ’f’ en la segunda palabra, la siguiente letra a buscar
// 	  ’e’ debe estar en una palabra posterior a la segunda.
// 	
// 	• Una vez encontremos una letra en una palabra, ya no buscaremos mas
// 	  letras en dicha palabra.
// 
// 	• No nos planteamos una busqueda barajando todas las posibilidades,
// 	  en el sentido de que una vez encontrada una letra, no volveremos a
// 	 buscarla de nuevo.
// 
// La salida sera RESULTADO = SI en el caso de que se encuentre y
// RESULTADO = NO en caso contrario.
// 
// 				f e o
// 				h o l a @
// 				m o f e t a @		<- f
// 				c o f i a @ 
// 	Entrada:	c e r r o @			<- e
// 				p e r a @
// 				c o s a @			<- o
// 				h o y @
// 				#
// 
// 	Salida:		RESULTADO = SI


#include <iostream>
using namespace std;

int main() {
    char letraUno, letraDos, letraTres, letraIntroducida;
    int numLetrasEncontradas = 0;

    cin >> letraUno;
    cin >> letraDos;
    cin >> letraTres;

    do {
        cin >> letraIntroducida;

        if (letraIntroducida != '#') {

            if ((numLetrasEncontradas == 0)&&(letraIntroducida == letraUno)) {
                numLetrasEncontradas++;

                while (letraIntroducida != '@')
                    cin >> letraIntroducida;
            } else {

                if ((numLetrasEncontradas == 1)&&(letraIntroducida == letraDos)) {
                    numLetrasEncontradas++;

                    while (letraIntroducida != '@')
                        cin >> letraIntroducida;
                } else {

                    if ((numLetrasEncontradas == 2)&&(letraIntroducida == letraTres))
                        numLetrasEncontradas++;

                }

            }

        }
    } while ((letraIntroducida != '#')&&(numLetrasEncontradas < 3));

    if (numLetrasEncontradas == 3)
        cout << "RESULTADO = SI";
    else
        cout << "RESULTADO = NO";

    cout << "\n\n";
}
