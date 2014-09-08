Estructura de Computadores
==========================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 1: Programación en ensamblador x86 Linux
### Germán Martínez Maldonado

### Resumen de objetivos

Al finalizar esta práctica, se debería ser capaz de: 

* Usar las herramientas gcc , as , ld , objdump y nm para compilar código C, ensamblar y enlazar código ensamblador, y localizar y examinar el código generado por el compilador. 
* Reconocer la estructura del código generado por gcc para rutinas aritméticas muy sencillas, relacionando las instrucciones del procesador con la construcción C de la que provienen. 
* Describir la estructura general de un programa ensamblador en gas (GNU assembler). 
* Escribir un programa ensamblador sencillo. 
* Usar interrupciones software para hacer llamadas al sistema operativo (kernel Linux). 
* Enumerar los registros e instrucciones más usuales de los procesadores de la línea x86. 
* Usar con efectividad un depurador como gdb/ddd , para ver el contenido de los registros, ejecutar paso a paso y con puntos de ruptura, desensamblar el código, y volcar el contenido de la pila y los datos. Los depuradores permiten familiarizarse con la arquitectura del computador. 
* Argumentar la utilidad de los depuradores para ahorrar tiempo de depuración. 
* Explicar la gestión de pila en procesadores x86. 
* Recordar y practicar en una plataforma de 32bits la representación de caracteres, de enteros naturales y enteros con signo en complemento a dos, y las operaciones de suma en doble precisión y división entera.

### Tabla 3: preguntas de autocomprobación (saludo.s) Sesión de depuración saludo.s


**1. ¿Qué contiene EDX tras ejecutar mov longsaludo, %edx? ¿Para qué necesitamos esa instrucción, o ese valor? Responder no sólo el valor concreto (en decimal y hex) sino también el significado del mismo (¿de dónde sale?). Comprobar que se corresponden los valores hexadecimal y decimal mostrados en la ventana Status‐>Registers.**

Tras ejecutar “mov longsaludo, %edx”, como hemos movido el valor de la variable “longsaludo” al registro “edx”, este ahora contiene el valor hexadecimal 0x1C (valor decimal 28). “longsaludo” es una variable entera que almacena “.‐saludo”, o lo que es lo mismo, el contador de posiciones de saludo, el número de bytes que ocupa. Esta instrucción será necesaria para indicar que se van a escribir 28 bytes.

**2. ¿Qué contiene ECX tras ejecutar mov $saludo, %ecx? Indicar el valor en hexadecimal, y el significado del mismo. Realizar un dibujo a escala de la memoria del programa, indicando dónde empieza el programa (_start, .text), dónde empieza saludo (.data), y dónde está el tope de pila (%esp).**

Tras ejecutar “mov $saludo, %ecx”, como hemos movido la dirección de la variable “saludo” al registro “ecx”, este ahora contiene el valor hexadecimal 0x8049098, valor correspondiente a la dirección en memoria del contenido de la cadena de texto “saludo”, indicará la dirección del texto a escribir.

**3. ¿Qué sucede si se elimina el símbolo de dato inmediato ($) de la instrucción anterior? (mov saludo, %ecx). Realizar la modificación, indicar el contenido de ECX en hexadecimal, explicar por qué no es lo mismo en ambos casos. Concretar de dónde viene el nuevo valor (obtenido sin usar $).**

Si se elimina el símbolo de dato inmediato ($), en vez de mover la dirección de memoria de “saludo” al registro “ecx”, lo que haremos será mover el contenido de saludo al registro. Como podemos comprobar el valor hexadecimal del registro “ecx” pasará de ser 0x8049098 (con el símbolo $) a 0x616c6f48, que es la representación hexadecimal de la cadena de texto almacenada en la variable “saludo”.

**4. ¿Cuántas posiciones de memoria ocupa ocupa la variable longsaludo? ¿Y la variable saludo? ¿Cuántos bytes ocupa por tanto la sección de datos? Comprobar con un volcado Data‐>Memory mayor que la zona de datos antes de hacer Run.**

La variable “longsaludo” ocupa 1B en memoria, mientras que la variable “saludo” ocupa 28B, por lo tanto la seccion de datos ocupa 29B en memoria.

Para comprobar que esto último es cierto, lo comprobamos haciendo volcados de datos, primero para ver la ocupación de la variable saludo, examinamos “32 char bytes from &saludo”, obteniendo la siguiente salida:

```
(gdb) x/32cb &saludo
0x8049098 <saludo>:    72  'H' 111 'o' 108 'l' 97  'a'  32 ' '    97 'a'    32  ' '    116 't'
0x80490a0 <saludo+8>:  111 'o' 100 'd' 111 'o' 115 's'  33 '!'    10 '\n'   72  'H'    101 'e'
0x80490a8 <saludo+16>: 108 'l' 108 'l' 111 'o' 44  ','  32 ' '    87 'W'    111 'o'    114 'r'
0x80490b0 <saludo+24>: 108 'l' 100 'd' 33  '!' 10  '\n' 28 '\034' 0  '\000' 0   '\000' 0   '\000'#
```

Como podemos comprobar, solo los primeros 28B corresponden al contenido de la variable “saludo”, por lo que queda comprobado que la variable saludo tiene un tamaño de 28B.

Ahora comprobaremos que la variable “longsaludo” tiene un tamaño de 1B, para ello examinamos “4 decimal bytes from &longsaludo”, obteniendo la siguiente salida:

```
(gdb) x /4db &longsaludo
0x80490b4 <longsaludo>: 28   0    0    0#
```

Como vemos, la variable “longsaludo” solo tiene una ocupación de 1B.

**5. Añadir dos volcados Data‐>Memory de la variable longsaludo, uno como entero hexadecimal, y otro como 4 bytes hex. Teniendo en cuenta lo mostrado en esos volcados... ¿Qué direcciones de memoria ocupa longsaludo? ¿Cuál byte está en la primera posición, el más o el menos significativo? ¿Los procesadores de la línea x86 usan el criterio del extremo mayor (big‐endian) o menor (little‐endian)? Razonar la respuesta.**

Hacemos los volcados de la variable “longsaludo”:

```
(gdb) x /1xb &longsaludo
0x80490b4 <longsaludo>: 0x1c
(gdb) x /4xb &longsaludo
0x80490b4 <longsaludo>: 0x1c  0x00  0x00  0x00#
```

Hecho esto, vemos que “longsaludo” ocupa la dirección 0x80490b4, siendo el primer byte el menos significativo. Los procesadores x86 (incluidos los x86‐64, que es sobre el que estamos trabajando), usan el criterio menor (little‐endian), porque si nos fijamos, primero escribe el bit menos significativo, si los valores obtenido los pasamos a binario, tenemos “00011100 00000000 00000000 00000000”, visto esto descubrimos que un cambio en un bit de la derecha, tiene mayor repercusión que un cambio en un bit de la izquierda, el modo de funcionamiento little‐endian.

**6. ¿Cuántas posiciones de memoria ocupa la instrucción mov $1, %ebx? ¿Cómo se ha obtenido esa información? Indicar las posiciones concretas en hexadecimal.**

La instrucción “mov $1, %ebx” ocupa 5 posiciones de memoria, concretamente desde la 0x08048079 hasta la 0x0804807d. Esta información la obtenemos haciendo un desensamblado del programa, introduciendo el comando “disassemble” en el modo consola y desde el menú “View → Machine Code Window”. Una vez hecho esto, buscamos la línea correspondiente a la instrucción y obtendremos su dirección de inicio y el número de posiciones ocupadas.

```
Dump of assembler code for function _star:
    0x08048074 <+0>:     mov   $0x4,%eax
    0x08048079 <+5>:     mov   $0x1,%ebx
    0x0804807e <+10>:    mov   $0x8049098,%ecx
    0x08048083 <+15>:    mov   0x80490b4,%edx
    0x08048089 <+21>:    int   $0x80
    0x0804808b <+23>:    mov   $0x1,%eax
    0x08048090 <+28>:    mov   $0x0,%ebx
    0x08048095 <+33>:    int   $0x80
```

**7. ¿Qué sucede si se elimina del programa la primera instrucción int 0x80? ¿Y si se elimina la segunda? Razonar las respuestas**

Las instrucciones “int 0x80” son usadas para provocar interrupciones de software e invocar servicios de GNU/Linux, por lo cual en este caso su eliminación produce las siguientes situaciones:

La siguiente salida muestra la salida del programa si eliminamos la primera instrucción “int 0x80”:

```
(gdb) run

Program exited normally.#
```

Vemos que el programa finaliza correctamente, pero no muestra los mensajes por pantalla, esto se debe a que al inicio del programa con la instrucción “mov $4, %eax”, estamos indicando que vamos a llamar al servicio 4 del kernel de Linux, en este caso es “write”, el encargado de escribir mensajes en pantalla, como no se produce la interrupción que invoca este servicio, esta se pierde con la instrucción “mov $1, %eax”, que cambiará el servicio a invocar antes de que sea invocado.

Si eliminamos la segunda instrucción “int 0x80”, obtenemos la próxima salida:

```
(gdb) run
Hola a todos!
Hello, World!

Program received signal SIGSEGV, Segmentation fault.
0x08048095 in ?? ()#
```

Como hemos indicado en la situación anterior, justo después de la primera instrucción “int 0x80”, tenemos la instrucción “mov $1, %eax”, indicando que vamos a llamar al servicio 1 del kernel de Linux, “exit” en este caso, que es el encargado de finalizar la ejecución de un programa, como no se llegará a producir esta invocación del servicio de finalización, el programa no sabe como acabar y produce un fallo de segmentación.

**8. ¿Cuál es el número de la llamada al sistema READ (en kernel Linux 32bits)? ¿De dónde se ha obtenido esa información?**

El número de llamada al sistema READ es el 3, esta información la obtenemos del archivo “/usr/include/asm/unistd_32.h”, que es el que contiene los números de llamadas al sistema, en concreto para READ, esto lo comprobamos en la siguiente linea:

```
#define __NR_read      3
```


### Tabla 4: preguntas de autocomprobación (suma.s) Sesión de depuración suma.s

**1. ¿Cuál es el contenido de EAX justo antes de ejecutar la instrucción RET, para esos componentes de lista concretos? Razonar la respuesta, incluyendo cuánto valen 0b10, 0x10, y (.‐lista)/4.**

Como EAX es el registro que hemos usado como acumulador, antes de ejecutar la instrucción RET (que realizará el retorno de la llamada de la función) el valor del registro será el resultado de todas las sumas realizadas, 37 en este caso, porque los valores que se están sumando son 1, 2, 10, 1, 2, 0b10 (valor decimal 2 representado en binario), 1, 2, 0x10 (valor decimal 16 representado de hexadecimal). La expresión (.‐lista)/4 significa que todo el espacio en memoria de lista lo dividamos en grupos de 4, como estamos trabajando con enteros de 32 bits, estos ocupan 4 B cada uno, como lista ocupa 36 B, la expresión valdrá 9, lo que nos indica que lista tiene 9 números.

**2. ¿Qué valor en hexadecimal se obtiene en resultado si se usa la lista de 3 elementos: .int 0xffffffff, 0xffffffff, 0xffffffff? ¿Por qué es diferente del que se obtiene haciendo la suma a mano? NOTA: Indicar qué valores va tomando EAX en cada iteración del bucle, como los muestra la ventana Status‐>Registers, en hexadecimal y decimal (con signo). Fijarse también en si se van activando los flags CF y OF o no tras cada suma. Indicar también qué valor muestra resultado si se vuelca con Data‐>Memory como decimal (con signo) o unsigned (sin signo).**

Con un lista de 3 elementos como la indicada, el valor de la variable resultado en hexadecimal es 0xFFFFFFFD, si lo consideramos un valor decimal con signo su valor será ‐3, mientras que si lo consideramos sin signo, su valor será 253, la diferencia entre el resultado con signo y sin signo está en que con signo el 0xFFFFFFFF al realizarle el complemento a 2, su valor representado es ‐1, mientras que sin signo su valor representado es 2^8 – 1, que es 255.

Por iteraciones el valor de EAX es 0xffffffff en hexadecimal y ‐1 en decimal con signo, seguido de 0xfffffffe en hexadecimal y ‐2 en decimal con signo, y en la última, 0xfffffffd en hexadecimal y ‐3 en decimal con signo. Como en la suma no hemos controlado el acarreo, el resultado con signo será ‐3, pero sin signo será 2^8 – 3, que es 253.

**3. ¿Qué dirección se le ha asignado a la etiqueta suma? ¿Y a bucle? ¿Cómo se ha obtenido esa información?**

La etiqueta suma tiene asignada la dirección 0x8048095 y la etiqueta bucle la dirección 0x80480a0. Esta información se puede obtener del volcado del código ensamblador para el bucle de funciones, al que podemos acceder desde el menú, View → Machine Code Window.
```
0x0804807f <+11>: call 0x8048095 <suma>#
0x080480a6 <+6>: jne 0x80480a0 <bucle>#
```

**4. ¿Para qué usa el procesador los registros EIP y ESP?**

El procesador usa el registro EIP como puntero a la siguiente dirección de memoria que va a ser ejecutada por el procesador, el registro ESP es usado como puntero al inicio de la pila del programa.

**5. ¿Cuál es el valor de ESP antes de ejecutar CALL, y cuál antes de ejecutar RET? ¿En cuánto se diferencian ambos valores? ¿Por qué? ¿Cuál de los dos valores de ESP apunta a algún dato de interés para nosotros? ¿Cuál es ese dato?**

El valor de ESP antes de ejecutar CALL es 0xFFFFD4A0 y antes de ejecutar RET es 0xFFFFD49C. La diferencia entre ambos valores es de 4, esta diferencia es producida porque al ejecutar CALL, el tamaño de la pila se modifica porque se guarda en ella la dirección de retorno a la función que será necesaria cuando se ejecute RET.

**6. ¿Qué registros modifica la instrucción CALL? Explicar por qué necesita CALL modificar esos registros.**

La instrucción CALL modifica los registros EAX, EDX, ESP y EIP: EAX es modificado porque en nuestro programa funcionará como acumulador para ir guardando el resultado de las sumas, EDX es modificado porque funcionará como índice para conocer la siguiente dirección de memoria a leer, ESP es modificado porque almacenará la dirección a la que retornar cuando se ejecute la instrucción RET, y EIP es modificado porque almacenará la dirección de la próxima instrucción a ser ejecutada.

**7. ¿Qué registros modifica la instrucción RET? Explicar por qué necesita RET modificar esos registros.**

La instrucción RET modifica los registros ESP y EIP porque los punteros deberán cambiar para que el programa pueda continuar con su ejecución al punto donde estaba antes de llamar a la subrutina.

**8. Indicar qué valores se introducen en la pila durante la ejecución del programa, y en qué direcciones de memoria queda cada uno. Realizar un dibujo de la pila con dicha información. NOTA: en los volcados Data‐>Memory se puede usar $esp para referirse a donde apunta el registro ESP.**

Cuando se inicia al programa, vemos que el registro ESP apunta a la dirección 0xfffd4a0 con el valor 0x00000001, y una vez dentro de la subrutina suma, en la dirección 0xffffd49c tenemos el valor 0x08048084, a la siguiente instrucción tenemos en la dirección 0xffffd498 el valor 0x00000000, justo después de hacer POP, en la dirección 0xffffd49c tenemos el valor 0x08048084 y, finalmente, al volver al programa principal en la dirección 0xffffd4a0 tenemos el valor 0x00000001.

**10.  ¿Qué ocurriría si se eliminara la instrucción RET? Razonar la respuesta. Comprobarlo usando ddd.**

Que no se podría volver la ejecución al programa principal desde el que se llamó a la subrutina, y como no sabría cómo volver, produciría un error en la ejecución del programa:

```
(gdb) run

Program received signal SIGSEGV, Segmentation fault.
0x080480a9 in ?? ()#
```


### Tabla 5: preguntas de autocomprobación (suma64uns.s) Cuestiones sobre suma64unsigned.s

**1. Para N≈32, ¿cuántos bits adicionales pueden llegar a necesitarse para almacenar el resultado? Dicho resultado se alcanzaría cuando todos los elementos tomaran el valor máximo sin signo. ¿Cómo se escribe ese valor en hexadecimal? ¿Cuántos acarreos se producen?
¿Cuánto vale la suma (indicarla en hexadecimal)? Comprobarlo usando ddd.**

Para almacenar la suma de 32 enteros de 32 bits, si todos tomaran el valor máximo sin signo (0xFFFFFFFF en hexadecimal, 4294967295 en decimal), necesitaríamos un entero de mínimo 37 bits, porque la suma de esos 32 enteros, generaría 32 acarreos, dando como resultado de la suma el valor 0x1FFFFFFFE0 o 137438953440 en decimal, cuya representación binaria es 1111111111111111111111111111111100000, pero ese número no se podría almacenar en un entero de 32 bits sin signo, harían falta 5 bits extras.

**2. Si nos proponemos obtener sólo 1 acarreo con una lista de 32 elementos iguales, el objetivo es que la suma alcance 232 (que ya no cabe en 32bits). Cada elemento debe valer por tanto 2^32/32 = 2^32/2? = ?. ¿Cómo se escribe ese valor en hexadecimal? Inicializar los 32 elementos de la lista con ese valor y comprobar cuándo se produce el acarreo.**

Para que se produzca sólo 1 acarreo con una lista de 32 elementos iguales todos tienen que tener el valor hexadecimal 0x8000000, este valor es el resultado de 2^32 = 4294967296 (máximo valor para un entero sin signo) / 32, esto es así porque queremos que el resultado de la suma se pueda almacenar sin producir acarreo, por lo cual se tienen que dar las condiciones que todos los elementos tengan el mismo valor y que además la suma de todos no exceda el valor máximo posible. Si realizamos la suma paso a paso comprobamos que el acarreo se produce en la última suma, dando como resultado 0x100000000.

**3. Por probar valores intermedios: si la lista se inicializara con los valores 0x10000000, 0x20000000, 0x40000000, 0x80000000, repetidos cíclicamente, ¿qué valor tomaría la suma de los 32 elementos? ¿Cuándo se producirían los acarreos? Comprobarlo con ddd.**

Para la lista de valores indicada, la suma de los 32 elementos tomaría el valor hexadecimal 0x780000000, produciéndose los acarreos cuando se suman todos los elementos de un ciclo, esto se produce en ese momento porque la suma de los valores de cada ciclo genera un valor que no se puede almacenar sin producir acarreo, produciéndose 7 acarreos en este caso.

### Código suma64uns.s

```
.section .data 
lista:          .int    4294967295,4294967295,1,2,3,4,5,6 
                .int    0b111,0b1000,0b1001,0b1010,0b1011,0b1100,0b1101,0b1110 
                .int    017,020,021,022,023,024,025,026 
                .int    0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E 
                # Introducido valores más grandes para comprobar que funciona correctamente 
                # el acarreo en la suma.		

longlista:      .int    (.-lista)/4 
resultado:      .quad   -1        # Como se puede dar el caso de que necesitemos hasta 37 bits para
                                  # representar el resultado, usaremos un número de 64 bits.

.section .text 
_start:	.global _start 

        mov     $lista, %ebx 
        mov     $0, %edx          # Ponemos a 0 el registro que usaremos de contador del acarreo.
        mov     longlista, %ecx 
        call    suma 

        # Moveremos el resultado desde el registro acumulador a la variable declarada para tal fin y,
        # luego para sumar el acarreo, como la familia x86 es little-endian, moveremos el acarreo
        # generado a la dirección que empieza 4 posiciones por detrás del resultado.
        mov     %eax, resultado 	
        mov     %edx, resultado+4
	 
        mov     $1, %eax 
        mov     $0, %ebx 
        int     $0x80 
	 
suma: 
        push    %esi           # Usaremos %esi como índice.
        mov     $0, %eax 
        mov     $0, %esi 

bucle: 
        add     (%ebx, %esi, 4), %eax 
        jnc     acarreo        # Saltaremos si no se ha producido acarreo en la operación anterior. 
        inc     %edx           # Si no se produce el salto, hay que incrementar el acarreo producido.

acarreo: 
        inc     %esi 
        cmp     %esi,%ecx 
        jne     bucle 
	 
        pop     %esi 
        ret
```
