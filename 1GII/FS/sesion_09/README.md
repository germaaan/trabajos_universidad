# Sesión 9: Depuración sencilla de programas


***
## Ejercicio 1
### Compila el programa main.cpp y genera un ejecutable con el nombre ejemplo1.
```
$ g++ -g main.cpp -o ejemplo1
$ gdb ejemplo1
GNU gdb (GDB) 7.2-ubuntu
Copyright (C) 2010 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law. Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
Para las instrucciones de informe de errores, vea:
<http://www.gnu.org/software/gdb/bugs/>...
Leyendo símbolos desde /home/germaaan/sesion9/ArchivosParaSesion9DePracticas/ejemplo1...hecho.
(gdb) run
Starting program: /home/germaaan/sesion9/ArchivosParaSesion9DePracticas/ejemplo1
6

Program exited normally.
```


***
## Ejercicio 2
### Lista todo el programa anterior con la orden list (para ello utiliza la orden help).
```
(gdb) list 1,54
1     #include <iostream>
2     /*
3          Este programa trata mantener dos variables, la primera
4          realiza la multiplicación de valores.
5          La segunda ...
6     */
7
8     /* Incrementa en 2 una variable */
9     int cuenta (int y)
10      {
11          int tmp;
12
13          tmp = y + 2;
14
15          /* break */
16
17          return tmp;
18     }
19
20     /* Calcula la multiplicación de dos números */
21     int multiplica (int x, int y)
22     {
23          int final;
24          int i;
25
26          final = 0;
27          for (i = 0; i < x; i ++)
28          {
29               /* break */
30               final = final + y;
31          }
32
33          return final;
34     }
35
36     int main (void)
37     {
38          int final1;
---Type <return> to continue, or q <return> to quit---
39          int final2;
40          int i;
41
42          /* break */
43          final1 = multiplica(3, 2);
44
45
46          for (i = 0; i < 100; i ++)
47               /* break */
48               final2 = cuenta(i);
49
50          std::cout << final1 << "\n";
51
52          return 0;
53     }
54
```


***
## Ejercicio 3
### Pon varios puntos de ruptura en las zonas marcadas como `/* break */`. Muestra un display con la información de todas las variables en cada paso. Muestra la información del contador de programa y de la pila (para ello utiliza el registro `$sp` en lugar del `$cp`).
```
(gdb) break 15
Punto de interrupción 1 at 0x8048633: file main.cpp, line 15.
(gdb) break 29
Punto de interrupción 2 at 0x804864e: file main.cpp, line 29.
(gdb) break 42
Punto de interrupción 3 at 0x8048673: file main.cpp, line 42.
(gdb) break 47
Punto de interrupción 4 at 0x8048695: file main.cpp, line 47.
(gdb) run
Starting program: /home/germaaan/sesion9/Archivos/ejemplo1

Breakpoint 3, main () at main.cpp:43
43     final1 = multiplica(3, 2);
(gdb) display final1
1: final1 = -1209430028
(gdb) p/x $sp
$1 = 0xbffff3a0
(gdb) p/x $pc
$2 = 0x8048673
(gdb) disable 3
(gdb) continue
Continuando.

Breakpoint 2, multiplica (x=3, y=2) at main.cpp:30
30     final = final + y;
(gdb) display final
2: final = 0
(gdb) p/x $sp
$3 = 0xbffff388
(gdb) p/x $pc
$4 = 0x804864e
(gdb) disable 2
(gdb) continue
Continuando.

Breakpoint 4, main () at main.cpp:48
48     final2 = cuenta(i);
1: final1 = 6
(gdb) display final2
3: final2 = 134514523
(gdb) p/x $sp
$5 = 0xbffff3a0
(gdb) p/x $pc
$6 = 0x8048695
(gdb) disable 4
(gdb) continue
Continuando.

Breakpoint 1, cuenta (y=0) at main.cpp:17
17     return tmp;
(gdb) p/x $sp
$7 = 0xbffff388
(gdb) p/x $pc
$8 = 0x8048633
(gdb) disable 1
(gdb) continue
Continuando.
6

Program exited normally.
```


***
## Ejercicio 4
### Imprime el valor de las variables final1 y final2 del programa anterior en los puntos de ruptura correspondientes. Copia el contenido de ensamblador de la zona depurada.
```
Breakpoint 3, main () at main.cpp:43
43     final1 = multiplica(3, 2);
(gdb) print final1
$1 = -1209430028
(gdb) print final2
$2 = 134514523
(gdb) disassemble
Dump of assembler code for function main():
 0x0804866a <+0>: push %ebp
 0x0804866b <+1>: mov %esp,%ebp
 0x0804866d <+3>: and $0xfffffff0,%esp
 0x08048670 <+6>: sub $0x20,%esp
=> 0x08048673 <+9>: movl $0x2,0x4(%esp)
 0x0804867b <+17>: movl $0x3,(%esp)
 0x08048682 <+24>: call 0x8048638 <multiplica(int, int)>
 0x08048687 <+29>: mov %eax,0x1c(%esp)
 0x0804868b <+33>: movl $0x0,0x14(%esp)
 0x08048693 <+41>: jmp 0x80486aa <main()+64>
 0x08048695 <+43>: mov 0x14(%esp),%eax
 0x08048699 <+47>: mov %eax,(%esp)
 0x0804869c <+50>: call 0x8048624 <cuenta(int)>
 0x080486a1 <+55>: mov %eax,0x18(%esp)
 0x080486a5 <+59>: addl $0x1,0x14(%esp)
 0x080486aa <+64>: cmpl $0x63,0x14(%esp)
 0x080486af <+69>: setle %al
 0x080486b2 <+72>: test %al,%al
 0x080486b4 <+74>: jne 0x8048695 <main()+43>
 0x080486b6 <+76>: mov 0x1c(%esp),%eax
 0x080486ba <+80>: mov %eax,0x4(%esp)
 0x080486be <+84>: movl $0x804a040,(%esp)
 0x080486c5 <+91>: call 0x80484e8 <_ZNSolsEi@plt>
 0x080486ca <+96>: movl $0x8048800,0x4(%esp)
 0x080486d2 <+104>: mov %eax,(%esp)
 0x080486d5 <+107>: call 0x8048548
<_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 0x080486da <+112>: mov $0x0,%eax
 0x080486df <+117>: leave
 0x080486e0 <+118>: ret
End of assembler dump.
(gdb) disable 3
(gdb) continue
Continuando.

Breakpoint 2, multiplica (x=3, y=2) at main.cpp:30
30     final = final + y;
(gdb) print final1
No symbol "final1" in current context.
(gdb) print final2
No symbol "final2" in current context.
(gdb) disassemble
Dump of assembler code for function multiplica(int, int):
 0x08048638 <+0>: push %ebp
 0x08048639 <+1>: mov %esp,%ebp
 0x0804863b <+3>: sub $0x10,%esp
 0x0804863e <+6>: movl $0x0,-0x4(%ebp)
 0x08048645 <+13>: movl $0x0,-0x8(%ebp)
 0x0804864c <+20>: jmp 0x8048658 <multiplica(int, int)+32>
=> 0x0804864e <+22>: mov 0xc(%ebp),%eax
 0x08048651 <+25>: add %eax,-0x4(%ebp)
 0x08048654 <+28>: addl $0x1,-0x8(%ebp)
 0x08048658 <+32>: mov -0x8(%ebp),%eax
 0x0804865b <+35>: cmp 0x8(%ebp),%eax
 0x0804865e <+38>: setl %al
 0x08048661 <+41>: test %al,%al
 0x08048663 <+43>: jne 0x804864e <multiplica(int, int)+22>
 0x08048665 <+45>: mov -0x4(%ebp),%eax
 0x08048668 <+48>: leave
 0x08048669 <+49>: ret
End of assembler dump.
(gdb) disable 2
(gdb) continue
Continuando.

Breakpoint 4, main () at main.cpp:48
48     final2 = cuenta(i);
(gdb) print final1
$3 = 6
(gdb) print final2
$4 = 134514523
(gdb) disassemble
Dump of assembler code for function main():
 0x0804866a <+0>: push %ebp
 0x0804866b <+1>: mov %esp,%ebp
 0x0804866d <+3>: and $0xfffffff0,%esp
 0x08048670 <+6>: sub $0x20,%esp
 0x08048673 <+9>: movl $0x2,0x4(%esp)
 0x0804867b <+17>: movl $0x3,(%esp)
 0x08048682 <+24>: call 0x8048638 <multiplica(int, int)>
 0x08048687 <+29>: mov %eax,0x1c(%esp)
 0x0804868b <+33>: movl $0x0,0x14(%esp)
 0x08048693 <+41>: jmp 0x80486aa <main()+64>
=> 0x08048695 <+43>: mov 0x14(%esp),%eax
 0x08048699 <+47>: mov %eax,(%esp)
 0x0804869c <+50>: call 0x8048624 <cuenta(int)>
 0x080486a1 <+55>: mov %eax,0x18(%esp)
 0x080486a5 <+59>: addl $0x1,0x14(%esp)
 0x080486aa <+64>: cmpl $0x63,0x14(%esp)
 0x080486af <+69>: setle %al
 0x080486b2 <+72>: test %al,%al
 0x080486b4 <+74>: jne 0x8048695 <main()+43>
 0x080486b6 <+76>: mov 0x1c(%esp),%eax
 0x080486ba <+80>: mov %eax,0x4(%esp)
 0x080486be <+84>: movl $0x804a040,(%esp)
 0x080486c5 <+91>: call 0x80484e8 <_ZNSolsEi@plt>
 0x080486ca <+96>: movl $0x8048800,0x4(%esp)
 0x080486d2 <+104>: mov %eax,(%esp)
 0x080486d5 <+107>: call 0x8048548
<_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 0x080486da <+112>: mov $0x0,%eax
 0x080486df <+117>: leave
 0x080486e0 <+118>: ret
End of assembler dump.
(gdb) disable 4
(gdb) continue
Continuando.

Breakpoint 1, cuenta (y=0) at main.cpp:17
17     return tmp;
(gdb) print final1
No symbol "final1" in current context.
(gdb) print final2
No symbol "final2" in current context.
(gdb) disassemble
Dump of assembler code for function cuenta(int):
 0x08048624 <+0>: push %ebp
 0x08048625 <+1>: mov %esp,%ebp
 0x08048627 <+3>: sub $0x10,%esp
 0x0804862a <+6>: mov 0x8(%ebp),%eax
 0x0804862d <+9>: add $0x2,%eax
 0x08048630 <+12>: mov %eax,-0x4(%ebp)
=> 0x08048633 <+15>: mov -0x4(%ebp),%eax
 0x08048636 <+18>: leave
 0x08048637 <+19>: ret
End of assembler dump.
(gdb) disable 1
(gdb) continue
Continuando.
6

Program exited normally.
```


***
## Ejercicio 5
### Elimina todos los puntos de ruptura salvo el primero.
```
(gdb) info breakpoints
Num   Type      Disp Enb Address   What
1   breakpoint  keep y  0x08048633 in cuenta(int) at main.cpp:15
      breakpoint already hit 13 times
2   breakpoint  keep y  0x0804864e in multiplica(int, int) at main.cpp:29
      breakpoint already hit 3 times
3   breakpoint  keep y  0x08048673 in main() at main.cpp:42
      breakpoint already hit 1 time
4   breakpoint  keep y  0x08048695 in main() at main.cpp:47
      breakpoint already hit 13 times
(gdb) delete 4
(gdb) delete 3
(gdb) delete 2
```
