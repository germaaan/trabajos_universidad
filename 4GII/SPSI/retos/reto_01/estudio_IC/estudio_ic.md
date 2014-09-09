Seguridad y Protección de Sistemas Informáticos
===============================================
4º Grado en Ingeniería Informática 2013/2014
--------------------------------------------


# Cálculo del índice de coincidencias del español
### Germán Martínez Maldonado
### José Manuel Castillo Pérez
### Pablo Sánchez Robles

Para calcular los distintos indices de coincidencias del español según un período dado hemos utilizado distintos métodos primero para la encriptación del texto hemos usado la técnica de cifrado de Vigenere que para cada iteración hasta el período 20 se va variando la longitud de la clave que se maneja, empezando en tamaño uno hasta tamaño 20.


Lo que hace el cifrado de Vigenere es una encriptación de César utilizando la fórmula:

fi(a) = a + ki % n

El código que realiza esto es:

```
public void codVigenere() {
    int posicion_nuevo_caracter;
    char nuevo_caracter;
    int posicion_alfabeto_mensaje;
    int posicion_alfabeto_clave;
    Iterator<Character> it = mensaje.iterator();
    char c;
    int j = 0;

    while (it.hasNext()) {
        c = it.next();

        posicion_alfabeto_mensaje = obtenerPosicion(c);
        posicion_alfabeto_clave = obtenerPosicion(this.clave.charAt(j));
        posicion_nuevo_caracter = mod((posicion_alfabeto_mensaje + posicion_alfabeto_clave), this.alfabeto.length);
        nuevo_caracter = alfabeto[posicion_nuevo_caracter];
        this.codificada.add(nuevo_caracter);

        if (j == this.clave.length() - 1) {
            j = 0;
        } else {
            j++;
        }
    }
}
```

Una vez cifrado el texto pasamos a calcular las frecuencias de las letras en dicho texto, para ello utilizamos un array en el que se almacenan las frecuencias de cada letra según la iteración en la que nos encontremos, con estas calcularemos el indice de coincidencia en cada uno de estos pasos.

La fórmula que realiza el calculo del IC es la siguiente:

* IC = MR + 0.037 = ∑i=0^27 pi^2

El código que realiza esto es:

```
double suma = 0.0;

for (int i = 0; i < frec.length; i++) {
    suma += (frec[i] * frec[i]);
}
```

El texto que hemos utilizado para calcular los IC es la Constitución española y la palabra clave para el cifrado de Vigenere es **“quijotesñadfwryzmxcv”**, en cada período utilizamos una palabra de longitud igual a la iteración correspondiente siendo en la vuelta primera sólo la **“q”** y en la última la clave completa.

La tabla de indices de frecuencias generadas con nuestro software es la siguiente:

|  d |    IC    |
|:--:|:--------:|
|  1 | 0.074502 |
|  2 | 0.059155 |
|  3 | 0.049981 |
|  4 | 0.047080 |
|  5 | 0.042986 |
|  6 | 0.042089 |
|  7 | 0.041831 |
|  8 | 0.041704 |
|  9 | 0.039746 |
| 10 | 0.039236 |
| 11 | 0.039010 |
| 12 | 0.038988 |
| 13 | 0.038930 |
| 14 | 0.038536 |
| 15 | 0.038203 |
| 16 | 0.037851 |
| 17 | 0.037760 |
| 18 | 0.037609 |
| 19 | 0.037426 |
| 20 | 0.037259 |

Como podemos apreciar en la primera vuelta el IC es 0.074502 y el IC del español es 0.076613 lo que nos lleva a la conclusión de que la distribución de letras en el texto utilizado no es exactamente igual a la correspondiente en el español pero se aproxima.
