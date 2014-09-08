# Sesión 5: Expresiones con variables y expresiones regulares


## Operadores aritméticos
### Realice las siguientes operaciones para conocer el funcionamiento del operador de incremento como sufijo y como prefijo. Razone el resultado obtenido en cada una de ellas:

* `v=1`: Declara una variable v a la que se le asigna el valor 1. v=1
* `echo $v`: Muestra el valor actual de la variable v. v=1
* `echo $((v++))`: Muestra el valor actual de la variable v y seguidamente incrementa en uno su valor. v=1
* `echo $v`: Muestra el valor actual de la variable v. v=2
* `echo $((++v))`: Incrementa en uno el valor actual de la variable v y seguidamente muestra su valor actual. v=3
* `echo $v`: Muestra el valor actual de la variable v. v=3


***
## Operadores de consulta de archivos
### Haciendo uso del help, compruebe y anote cuáles son los operadores que se pueden utilizar con la orden test para manejar cadenas, para aplicar condiciones lógicas a expresiones y para hacer evaluaciones aritméticas.

* **Cadenas**:
 + `-z STRING`: Verdadero si la cadena está vacía.
 + `-n STRING`: Verdadero si la cadena no está vacía.
 + `STRING1 = STRING2`: Verdadero si las cadenas son iguales.
 + `STRING1 != STRING2`: Verdadero si las cadenas no son iguales.
 + `STRING1 < STRING2`: Verdadero su **STRING1** es más corta lexicográficamente que **STRING2**.
 + `STRING1 > STRING2`: Verdadero su **STRING1** es más larga lexicográficamente que **STRING2**.

* **Condiciones lógicas a expresiones**:
 + `-o OPTION`: Verdadero si la opción del shell **OPTION** está activada.
 + `! EXPR`: Verdadero si **EXPR** es falsa.
 + `EXPR1 -a EXPR2`: Verdadero si ambas **EXPR1** y **EXPR2** son verdaderas.
 + `EXPR1 -o EXPR2`: Verdadero si alguna **EXPR1** o **EXPR2** son verdaderas.

* **Evaluaciones aritméticas**:
 + `arg1 OP arg2`: Tests aritméticos. **OP** es uno de `-eq`, `-ne`, `-lt`, `-le`, `-gt` o `-ge`.


***
### Razone qué hace la siguiente orden:
```
if test -f ./sesion5.pdf;
     then 
          printf "El archivo ./sesion5.pdf existe\n";
fi
```
Comprueba si el archivo ./sesion5.pdf existe, en cuyo caso muestra un mensaje por pantalla.


***
### Añada los cambios necesarios en la orden anterior para que también muestre un mensaje de aviso en caso de no existir el archivo.
```
if test -f ./sesion5.pdf;
     then 
          printf "El archivo ./sesion5.pdf existe\n";
     else 
          printf "El archivo ./sesion5.pdf no existe\n";
fi
```


***
### Consulte la sintaxis completa de la orden let utilizando la orden de ayuda para las ordenes empotradas (`help let`) y tome nota de sus sintaxis general. Observe que admite asignaciones múltiples y operadores que nosotros no hemos mencionada anteriormente. Ponga un ejemplo de asignación múltiple y, por otra parte, copie en un archivo el orden en el que se evalúan los operadores que admite.
* **Orden let**:
 + `id++, id--`: post-incremento, post-decremento de variable
 + `++id, --id`: pre-incremento, pre-decremento de variable
 + `-, +`: menos, más unario
 + `!, ~`: negación lógica y basada en bits
 + `**`: exponenciación
 + `*, /, %`: multiplicación, división, residuo
 + `+, -`: adición, sustracción
 + `<<, >>`: desplazamientos de bits izquierdo y derecho
 + `<=, >=, <, >`: comparación
 + `==, !=`: equivalencia, inequivalencia
 + `&`: AND de bits
 + `^`: XOR de bits
 + `|`: OR de bits
 + `&&`: AND lógico
 + `||`: OR lógico
 + `expr ? expr : expr`: operador condicional
 + `=, *=, /=, %=, +=, -=, <<=, >>=, &=, ^=, |=`: asignación


***
## Ejercicio 1
### Escriba una orden que calcule si el número de días que faltan hasta fin de año es múltiplo de cinco o no, y que comunique el resultado de la evaluación.
```
if test $(( (365 - $(date +%j)) % 5 ));
     then
          printf "El número de días hasta fin de año es multiplo de5\n";
     else
          printf "El número de días hasta fin de año no es múltiplo de 5\n";
fi
```


***
## Ejercicio 2
### Construya una orden que permita saber si su usario es el propietario del archivo `/bin/ls` y si tiene permiso de lectura sobre él.
```
if test -O /bin/ls -a -r /bin/ls;
     then
          printf "El usuario es propietario del archivo /bin/ls o tiene permisos de lectura sobre él\n";
     else
          printf "El usuario no es propietario del archivo /bin/ls o tiene permisos de lectura sobre él\n";
fi
```


***
## Ejercicio 3
### Haciendo uso de expresiones regulares, escriba una oreden que permita buscar en el árbol de directorios los nombres de los archivos que contenga al menos un digito y la letra e. ¿Cómo sería la orden si quisiéramos obtener los nombres de los archivos uqe tenga la letra e y no contengan ni el 0 ni el 1?
```
find / -name "*e*" | find / -name "*2-9*"
```
