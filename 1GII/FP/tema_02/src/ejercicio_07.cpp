// Una compañia aerea establece el precio del billete como sigue: en primer lugar se fija
// una tarifa base de 150 euros, la misma para todos los destinos. Si el destino esta a
// menos de 200 kilómetros, el precio final es la tarifa inicial. Para destinos a mas de 200
// Km, se suman 10 céntimos por cada kilómetro de distancia al destino (a partir del Km
// 200).
// 
// En una campaña de promocion, se barajan las siguientes alternativas de politicas de
// descuento:
// 
// 	a) Una rebaja del 3 % en el precio final, para destinos a mas de 600Km
// 	b) Una rebaja del 4 % en el precio final, para destinos a mas de 1100Km
// 	c) Una rebaja del 5 % si el comprador es cliente previo de la empresa.
// 
// Cread un programa para que lea el numero de kilometros al destino y si el billete
// corresponde a un cliente previo de la empresa. Calcular el precio final del billete con
// las siguientes políticas de descuento:
// 
// 	• Aplicando c) de forma adicional a los descuentos a) y b)
// 	• Aplicando c) de forma exclusiva con los anteriores, es decir, que si se aplica c),
// 	  no se aplicaría ni a) ni b)
// 
// Finalidad: Plantear una estructura condicional anidada. Dificultad Media.


#include <iostream>
using namespace std;

int main() {
    int kilometros_destino;
    int kilometros_extras;
    double descuento;
    double precio_final;
    bool es_cliente_previo;
    const double TARIFA_BASE = 150.0;

    cout << "Introduzca el numero de kilometros al destino: ";
    cin >> kilometros_destino;
    cout << "Cliente previo de la empresa (1:SI / 0:NO): ";
    cin >> es_cliente_previo;

    if (es_cliente_previo && kilometros_destino > 600) {
        descuento = 5.0 + 3.0;

        if (kilometros_destino > 1100) {
            descuento = 5.0 + 4.0;
        }

    } else {

        if (es_cliente_previo) {
            descuento = 5.0;
        } else {
            descuento = 0;
        }

    }

    if (kilometros_destino <= 200) {
        precio_final = TARIFA_BASE - (TARIFA_BASE * (descuento / 100));
    } else {
        kilometros_extras = kilometros_destino - 200;
        precio_final = TARIFA_BASE + (kilometros_extras * 0.10);
        precio_final = precio_final - (precio_final * (descuento / 100));
    }

    cout << "\n\nEl precio final del billete es de: " << precio_final;
	cout << "\n\n";
}
