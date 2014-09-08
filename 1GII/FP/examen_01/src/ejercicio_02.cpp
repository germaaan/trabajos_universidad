// [amenaza] El ejercito quiere implantar un sistema automatico de deteccion
// de amenazas sobre una determinada zona del territorio. Se considera una
// amenaza a cualquier objeto en movimiento detectado dentro de la zona de
// exclusion. Dicha zona de exclusion, viene definida como una esfera de radio
// r y centrada en el punto p = (x 0 , y 0 , 0). Se tiene un sistema de radares
// que detectan la presencia de objetos en movimiento. Los radares transmiten
// sobre cada objeto detectado, un caracter ’T’ y un par de numeros reales x
// y y cuando la amenaza es terrestre (la componente z del punto es cero) y un
// caracter ’A’ y una terna de numeros reales x, y y z cuando la amenaza es
// aerea. El sistema se desconecta al recibir el caracter ’D’ como caracter del
// objeto detectado.
// 
// Se pide desarrollar un programa que procese la informacion emitida por el
// sistema de radares y detecte si se han producido amenazas y en el caso de
// producirse, indicar si la primera amenaza fue terrestre o aerea. Al principio
// de la ejecucion se reciben 3 numero reales, el primero es el radio y los dos
// siguientes el punto central de la esfera. A partir de ese momento empieza la
// transmision para la deteccion de objetos.
// 	
// NOTA: Un punto (x1, y1, z1) esta dentro de una esfera de radio r y de origen
// (x0, y0, z0) si (x1−x0)² + (y1−y0)² + (z1−z0)² < r².
// 	
//	Entrada:	1.5 0 0 T 50.3 0.7 A 0.7 1.2 0.4 T 48.9 2.3 D
//	Salida: 	AMENAZA AEREA
// 	
//	Entrada: 	1.5 0 0 T 1 0.7 A 0.7 1.2 0.4 T 48.9 2.3 D
//	Salida: 	AMENAZA TERRESTRE
// 	
//	Entrada: 	1.5 0 0 A 50.3 0.7 104.3 A 97.7 48.2 0.4 T 48.9 2.3 A 38.6 40.4 23.3 D
//	Salida: 	NINGUNA AMENAZA


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float radio, x0, y0, z0 = 0, x1, y1, z1, radioAmenaza;
    char objetoDetectado;
    bool amenazaProducida = false;

    cin >> radio;
    cin >> x0;
    cin >> y0;

    do {
        cin >> objetoDetectado;

        if (objetoDetectado != 'D') {

            if (objetoDetectado == 'T') {
                cin >> x1;
                cin >> y1;
                z1 = 0;
            } else {
                cin >> x1;
                cin >> y1;
                cin >> z1;
            }

            radioAmenaza = pow(x1 - x0, 2) + pow(y1 - y0, 2) + pow(z1 - z0, 2);

            if (radioAmenaza < (radio * radio)) {
                amenazaProducida = true;
            }

        }

    } while ((!amenazaProducida)&&(objetoDetectado != 'D'));

    if (objetoDetectado == 'D')
        cout << "NINGUNA AMENAZA";
    else if (objetoDetectado == 'T')
        cout << "AMENAZA TERRESTRE";
    else if (objetoDetectado == 'A')
        cout << "AMENAZA AREA";

    cout << "\n\n";
}
