// En el ejercicio 7 de la relacion de problemas II (sobre los descuentos a aplicar a una
// tarifa aerea), se repetia en varias ocasiones un codigo muy parecido, a saber:
//
//	tarifa_final = tarifa_final * (1- DESCUENTO_CLIENTE_PREVIO/100.0);
//	tarifa_final = tarifa_final * (1- DESCUENTO_TRAYECTO_MEDIO/100.0);
//	...........
//
// Construid la funcion apropiada para que no se repita codigo y re-escribid la solucion
// llamando a dicha funcion en todos los sitios donde sea necesario.
//
// Finalidad: Diseño de una funcion sencilla. Dificultad Baja.


#include <iostream>
using namespace std;

double calculaTarifaFinal(double tarifaInicial, double descuento) {
    return tarifaInicial * (1 - descuento / 100.0);
}

int main() {
    const int LIMITE_KMS_TARIFICACION_ADICIONAL = 200;
    const double TARIFA_POR_KM_ADICIONAL = 0.1;
    const int MINIMO_KMS_TRAYECTO_MEDIO = 600;
    const int MINIMO_KMS_TRAYECTO_LARGO = 1100;
    const double DESCUENTO_TRAYECTO_MEDIO = 3.0;
    const double DESCUENTO_TRAYECTO_LARGO = 4.0;
    const double DESCUENTO_CLIENTE_PREVIO = 5.0;
    const double TARIFA_BASE = 150.0;

    double tarifa_con_km_adicionales, tarifa_final;
    int distancia_recorrido;
    bool es_cliente_previo;
    char opcion_es_cliente_previo;
    bool es_trayecto_medio, es_trayecto_largo;

    cout << "\nIntroduzca la distancia del recorrido del viaje: ";
    cin >> distancia_recorrido;
    cout << "\nEs un cliente previo (s/n)? ";
    cin >> opcion_es_cliente_previo;
    opcion_es_cliente_previo = toupper(opcion_es_cliente_previo);
    es_cliente_previo = (opcion_es_cliente_previo == 'S');

    tarifa_con_km_adicionales = TARIFA_BASE;

    if (distancia_recorrido > LIMITE_KMS_TARIFICACION_ADICIONAL)
        tarifa_con_km_adicionales = tarifa_con_km_adicionales + (distancia_recorrido - LIMITE_KMS_TARIFICACION_ADICIONAL) * TARIFA_POR_KM_ADICIONAL;

    es_trayecto_medio = (distancia_recorrido >= MINIMO_KMS_TRAYECTO_MEDIO) && (distancia_recorrido < MINIMO_KMS_TRAYECTO_LARGO);
    es_trayecto_largo = (distancia_recorrido >= MINIMO_KMS_TRAYECTO_LARGO);

    tarifa_final = tarifa_con_km_adicionales;

    if (es_cliente_previo)
        tarifa_final = calculaTarifaFinal(tarifa_final, DESCUENTO_CLIENTE_PREVIO);

    if (es_trayecto_medio)
        tarifa_final = calculaTarifaFinal(tarifa_final, DESCUENTO_TRAYECTO_MEDIO);
    else
        if (es_trayecto_largo)
        tarifa_final = calculaTarifaFinal(tarifa_final, DESCUENTO_TRAYECTO_LARGO);

    cout << "\n\nTarifa final aplicando todos los descuentos: ";
    cout << tarifa_final;

    tarifa_final = tarifa_con_km_adicionales;

    if (es_cliente_previo)
        tarifa_final = calculaTarifaFinal(tarifa_final, DESCUENTO_CLIENTE_PREVIO);
    else if (es_trayecto_medio)
        tarifa_final = calculaTarifaFinal(tarifa_final, DESCUENTO_TRAYECTO_MEDIO);
    else if (es_trayecto_largo)
        tarifa_final = calculaTarifaFinal(tarifa_final, DESCUENTO_TRAYECTO_LARGO);

    cout << "\n\nTarifa final aplicando el descuento por ser cliente previo, de forma excluyente ";
    cout << tarifa_final;

    cout << "\n\n";
}
