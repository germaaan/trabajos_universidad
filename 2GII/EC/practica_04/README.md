Estructura de Computadores
==========================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 4: Procesadores segmentados con WinDLX
### Germán Martínez Maldonado

### Objetivos

El objetivo de estas prácticas es el estudio experimental de un procesador segmentado para ilustrar la mejora de prestaciones que se puede conseguir con un cauce segmentado, analizando las dificultades y las limitaciones existentes para alcanzar dicha mejora. Para realizar el trabajo experimental correspondiente a esta práctica se utilizará el simulador WinDLX.

### 1.5 Ejercicios Prácticos con WinDLX

#### 1. Simular los programas ejemplo inic1.s, inic2.s, inic4.s e inic5.s.

**a. ¿Cuáles son las ganancias que se obtienen en inic2 inic3, inic4, e inic5 con la segmentación con respecto al cauce sin segmentar de ssrDLX?**

Teniendo en cuenta los ciclos que se ocupan en la ejecución de cada instrucción:

| Instrucción | Nº de ciclos |
|:-----------:|:------------:|
|      ld     |      4.6     |
|      sd     |      3.8     |
|     mult    |      7.6     |
|     add     |      3.6     |
|     sub     |      3.6     |
|     bnez    |      1.8     |
|     trap    |      1.8     |


**inic1.s:**
- Instrucciones = ld + add + 6*(4*(ld + multd + sd)
- Ciclos = 4.6 + 3.6 + 6*(4*(4.6 + 7.6 + 3.8) + 3.6 + 1.8) + 1.8 = 426.4
- Ganancia = 426.4 / 223 = 1.912

**inic2.s**
- Instrucciones = ld + add + 3*(8*(ld + multd + sd) + sub + bnez) + trap 
- Ciclos = 4.6 + 3.6 + 3*(8*(4.6 + 7.6 + 3.8) + 3.6 + 1.8) + 1.8 = 410.2
- Ganancia = 410.2 / 211 = 1.94

**inic3.s**
 - Instrucciones = ld + add + 6*((2*ld + 2* multd + 2*sd + 2*ld + 2*multd + 2*sd) + sub + bnez) + trap.
 - Ciclos = 4.6 + 3.6 + 6*((2*4.6 + 2*7.6 + 2*3.8 + 2*4.6 + 2*7.6 + 2*3.8) + 3.6 + 1.8) + 1.8 = 426.4
 - Ganancia = 426.4 / 187 = 2.28

**inic4.s**
 - Instrucciones = ld + add + 6*((4*ld + 4*multd + 4*sd) + sub +bnez) + trap 
 - Ciclos = 4.6 + 3.6 + 6*((4*4.6 + 4*7.6 + 4*3.8) + 3.6 + 1.8) + 1.8 = 426.4
 - Ganancia = 426.4 / 181 = 2.35

**Init5.s**
 - Instrucciones = 5* ld + add + 6*((4*sd) + (4*ld) + sub) + 4*multd + sub + bnez + 4*sd * trap
 - Ciclos = 5 *4.6 + 3.6 + 6*((4 * 3.8) + (4* 4.6) + 3.6) + 4*7.6 + 3.6 + 1.8 + 4*3.8 + 1.8 = 302.6
 - Ganancia = 302.6 / 183 = 1.65

**b. ¿Cuál de los cuatro códigos es más eficiente?**

El código más eficiente es el de init4.

#### 2. El siguiente código en ensamblador calcula la expresión aX + Y, donde a es un escalar y X e Y son dos vectores cuyos componentes se encuentran almacenados en memoria en posiciones consecutivas a partid de dos direcciones. Tanto a como X e Y son de doble precisión.

```
start:  ld     f0,a              (1)
        add    r8,r0,rx          (2)
        addi   r4,r8,#128        (3)
        add    r12,r0,ry         (4)
loop:   ld     f2,0(r8)          (5)
        multd  f2,f0,f2          (6)
        ld     f4,0(r12)         (7)
        addd   f4,f2,f4          (8)
        sd     0(r12),f4         (9)
        addi   r8,r8,#8          (10)
        addi   r12,r12,#8        (11)
        sub    r20,r4,r8         (12)
        bnez   r20, loop         (13)
        nop                      (14)
```

#### Los  componentes  de  los  vectores  se  encuentran  almacenados  a  partir  de  las direcciones de memoria rx y ry. El número de componentes de los vectores es N=16.

**a) Explicar con detalle el programa.**

* (1)   Etiqueta “start”. Carga en (f0,f1) el contenido al que apunta “a”.
* (2)   Suma el contenido de “rx” a “r0” y lo guarda en “r8”.
* (3)   Suma el contenido de “r8” con 128 y lo guarda en “r4”.
* (4)   Suma el contenido de “ry” a “r0” y lo guarda en “r12”.
* (5)   Etiqueta “loop”. Carga en (f2,f3) el contenido al que apunta “r8”.
* (6)   Multiplica en doble precisión (f0,f1) con (f2,f3), guardándose en este último.
* (7)   Carga en (f4,f5) el contenido al que apunta “r12”.
* (8)   Suma en doble precisión de (f2,f3) a (f4,f5) , guardándose en este último.
* (9)   Almacena con doble precisión el contenido de (f4,f5) en “r12”.
* (10)  Suma el contenido de “r8” con 8 y lo guarda en “r8”.
* (11)  Suma el contenido de “r12” con 12 y lo guarda en “r12”.
* (12)  Resta el contenido de “r4” menos el de “r8” y lo guarda en “r20”.
* (13)  Si el “r20” es distinto de 0, salta a la etiqueta “loop”.
* (14)  Instrucción  usada  para  retrasar  la  captación  de  la  instrucción  que  tiene  que ejecutarse después de la instrucción de salto.

**b) Simular el programa con winDLX.**

Cuando simulamos el programa obtenemos que su ejecución es de 264 ciclos, produciéndose 114 stalls.

**c) A partir de los diagramas de ciclo de reloj (Clock Cycle Diagram) obtenidos con el simulador, explicar qué atascos (stall) van surgiendo a lo largo de la ejecución del programa y a qué se deben.**

* Entre (multd f2,f0,f2) y (addd f4,f2,f4) por dependencia de f2.
* Entre (addd f4,f2,f4) y (sd a(r12),f4) por dependencia de f4.
* Entre (sub r20,r4,r8) y (bnez r20,loop) por dependencia de r20.
* Entre (ld f2,a(r8)) y (multd f2,f0,f2) por dependencia de f2.

**f) Una posible aplicación de la técnica de segmentación software para mejorar las prestaciones podría ser la siguiente:**

```
start:	ld     f0,a
        add    r8,r0,rx 
        addi   r4,r8,#128 
        add    r12,r0,ry
loop0:  ld     f2,0(r8)
        multd  f2,f0,f2
        ld     f4,0(r12)
        ld     f6,8(r8)
        ld     f8,8(r12)
        addd   f4,f2,f4

loop:	sd     0(r12),f4
        multd  f6,f0,f6
        addi   r8,r8,#8
        addi   r12,r12,#8
        addd   f4,f6,f8
        ld     f6,8(r8)
        ld     f8,8(r12) 
        sub    r20,r4,r8 
        bnez   r20,loop 
        nop
```

**Explicar los cambios que se han introducido respecto al programa original y cómo afecta a los riesgos que había.**

Se hace un primer ciclo de ejecuciones a partir de “loop0”, y el resto de iteraciones del bucle se hacen durante “loop”. Esto hará que se produzcan menos atascos, porque habrá menos veces que se tenga que esperar a un dato.

**g) Otra posible mejora de prestaciones se conseguiría con la siguiente reordenación del código, respecto al programa original:**

```
start:	ld     f0,a
        add    r8,r0,rx 
        ld     f2,0(r8)
        addi   r4,r8,#128 
        multd  f2,f0,f2 
        add    r12,r0,ry 
        ld     f4,0(r12)
        ld     f6,8(r8)   
        ld     f8,8(r12) 
        addd   f4,f2,f4

loop:	multd  f6,f0,f6
        sd     0(r12),f4 
        addi   r8,r8,#8 
        addi   r12,r12,#8 
        addd   f4,f6,f8 
        sub    r20,r4,r8  
        ld     f6,8(r8)
        ld     f8,8(r12) 
        bnez   r20,loop 
        nop
```

**Explicar los cambios que se han introducido respecto al programa original.**

Se reordena la ejecución de las instrucciones que pueden producir más atascos.

**h) Comparar y comentar los resultados estadísticos obtenidos con WinDLX al simular las diferentes versiones del programa ¿Cuál es la mejor opción?**

Cuando simulamos el programa f obtenemos que su ejecución es de 242 ciclos, produciéndose 69 stalls.

Cuando simulamos el programa g obtenemos que su ejecución es de 207 ciclos, produciéndose 34 stalls.

Por lo tanto la mejor opción es la g.
