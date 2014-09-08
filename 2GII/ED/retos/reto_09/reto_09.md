Estructuras de Datos
====================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Reto 9: Tablas hash
### Germán Martínez Maldonado


### PROBLEMA 1

**Mediante un sencillo procedimiento de simulación, hacer que el ordenador encuentre las parejas (a, c) que den lugar a un esquema de hashing válido (sucesión que no cicle antes de tiempo).**

* Partiendo de que tenemos una función hash:
h(k) = k % M

* Y un método de resolución de colisiones siguiendo un esquema de hashing doble a través de la función:
hi(k) = [h(k) + di ] % M

* Calculando di como:
di = [a*di-1 + c] % M con d0 = 0

Nos dispondremos a crear un procedimiento que nos encuentre las parejas (a,c) para poder gestionar de forma idónea la inserción de datos en un tabla hash. Dicho procedimiento tendría la siguiente forma:

```
int buscarCasillaLibre(int clave){
    int aux = hash(clave) % tabla.size();

    while ((tabla[aux]!= LIBRE) || (tabla[aux] != BORRADA) || (tabla[aux].obtenerClave() != clave))
        aux = (aux + 1) % tabla.size();

    return aux;
}
```

De esta forma nos aseguramos que aunque haya un gran número de casillas contiguas ocupadas, esto necesariamente no repercutirá en exceso en la eficiencia de nuestro algoritmo, aunque seguirá sin poder evitarse que pasado un alto porcentaje de ocupación, el número de colisiones crecerá en gran número, lo que si afectara negativamente a la eficiencia.
