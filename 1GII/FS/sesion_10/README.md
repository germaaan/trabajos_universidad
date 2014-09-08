# Sesión 10: Depuración compleja de programas


***
## Ejercicio 1
### Compila el programa main.cpp y genera un ejecutable con el nombre ejemplo1. Ejecuta gdb con dicho ejemplo y ejecútalo. Añade un punto de ruptura (breakpoint) en la función cuenta (tal y como muestra el ejemplo). Realiza 10 pasos de ejecución con step y otros 10 con next. Comenta las diferencias.
```
(gdb) break cuenta
Punto de interrupción 1 at 0x804862a: file main.cpp, line 13.
(gdb) run
Starting program: /home/germaaan/sesion9/Archivos10/ejemplo1

Breakpoint 1, cuenta (y=0) at main.cpp:13
13     tmp = y + 2;
(gdb) step
17     return tmp;
(gdb) step
18     }
(gdb) step
main () at main.cpp:46
46     for (i = 0; i < 100; i ++)
(gdb) step
48     final2 = cuenta(i);
(gdb) step

Breakpoint 1, cuenta (y=1) at main.cpp:13
13     tmp = y + 2;
(gdb) step
17     return tmp;
(gdb) step
18     }
(gdb) step
main () at main.cpp:46
46     for (i = 0; i < 100; i ++)
(gdb) step
48     final2 = cuenta(i);
(gdb) step

Breakpoint 1, cuenta (y=2) at main.cpp:13
13     tmp = y + 2;
(gdb) next
17     return tmp;
(gdb) next
18     }
(gdb) next
main () at main.cpp:46
46     for (i = 0; i < 100; i ++)
(gdb) next
48     final2 = cuenta(i);
(gdb) next

Breakpoint 1, cuenta (y=3) at main.cpp:13
13     tmp = y + 2;
(gdb) next
17     return tmp;
(gdb) next
18     }
(gdb) next
main () at main.cpp:46
46     for (i = 0; i < 100; i ++)
(gdb) next
48     final2 = cuenta(i);
(gdb) next

Breakpoint 1, cuenta (y=4) at main.cpp:13
13     tmp = y + 2;
```

Next ejecuta paso a paso el programa a través de llamadas a subrutinas, algo que no hace step.


***
## Ejercicio 2
### Depura el programa del ejercicio 1. Introduce un punto de ruptura (breakpoint) dentro de la función cuenta. Muestra la información del marco actual y del marco superior, vuelve al marco inicial y comprueba si ha cambiado algo.
```
(gdb) info frame
Stack level 0, frame at 0xbffff390:
eip = 0x804862a in cuenta (main.cpp:13); saved eip 0x80486a1
called by frame at 0xbffff3c0
source language c++.
Arglist at 0xbffff388, args: y=4
Locals at 0xbffff388, Previous frame's sp is 0xbffff390
Saved registers:
ebp at 0xbffff388, eip at 0xbffff38c

(gdb) up
#1 0x080486a1 in main () at main.cpp:48
48     final2 = cuenta(i);

(gdb) info frame
Stack level 1, frame at 0xbffff3c0:
eip = 0x80486a1 in main (main.cpp:48); saved eip 0xb7d55ce7
caller of frame at 0xbffff390
source language c++.
Arglist at 0xbffff3b8, args:
Locals at 0xbffff3b8, Previous frame's sp is 0xbffff3c0
Saved registers:
ebp at 0xbffff3b8, eip at 0xbffff3bc

(gdb) down
#0 cuenta (y=4) at main.cpp:13
13     tmp = y + 2;

(gdb) info frame
Stack level 0, frame at 0xbffff390:
eip = 0x804862a in cuenta (main.cpp:13); saved eip 0x80486a1
called by frame at 0xbffff3c0
source language c++.
Arglist at 0xbffff388, args: y=4
Locals at 0xbffff388, Previous frame's sp is 0xbffff390
Saved registers:
ebp at 0xbffff388, eip at 0xbffff38c
```

Aparentemente no ha cambiado nada.


***
## Ejercicio 3
### Pon un punto de ruptura en la línea 30 del programa (función multiplica) de tal forma que el programa se detenga cuando la variable final llegue a 8. Comprueba si se detiene o no y explica por qué.
```
(gdb) break 30 if final >= 8
Punto de interrupción 1 at 0x804864e: file main.cpp, line 30.
(gdb) run
Starting program: /home/germaaan/sesion9/Archivos10/ejemplo1
6

Program exited normally.
```

No se detiene, pero debería.
