Algorítmica
===========
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Práctica 3: Algoritmos voraces
### Germán Martínez Maldonado

### 1. Implementación

La implementación realizada consta de 4 métodos, el método principal (`main()`) y 3 métodos auxiliares: `int obtenerDimension(ifstream &flujo)`, que nos devolverá el tamaño del grafo  a  construir  con  los  datos  leídos  de  fichero;  `void  rellenarGrafo(grafo  &G,  ifstream &flujo)`, que introducirá los datos leídos de fichero en el grafo; y `void Dijkstra(grafo &G, vertice s)`, que es el método que usaremos para obtener el camino mínimo de nuestro grafo.

#### 1.1 “int obtenerDimension(ifstream &flujo)”

Este método recibe un flujo de entrada con el fichero de entrada de datos, el procedimiento consistirá en posicionarse al comienzo del fichero y leer las primeras líneas, hasta llegar a la línea que tiene el valor de dimensión, una vez en esta línea nos desplazaremos hasta la posición del valor, lo leeremos, lo asignaremos a una variable y lo devolveremos.

#### 1.2 “void rellenarGrafo(grafo &G, ifstream &flujo)”

Este método recibe un flujo de entrada con el fichero de entrada de datos y una referencia a un grafo que será en el que introduzcamos los valores de la distancias entre los vértices. Para comenzar, nos situamos al principio del fichero, y leemos línea por línea hasta llegar a la línea donde comienzan los datos.

En función del primer valor numérico que nos encontremos en el fichero, esto nos indicará que los datos están organizados de una forma en concreto, por lo que según el valor nos encontremos, iremos leyendo los valores e introduciéndolos en nuestro de grafo de una forma o de otra.

#### 1.3 “void Dijkstra(grafo &G, vertice s)”

Este método recibe una referencia al grafo del que queremos obtener el  camino mínimo y el vértice de partida, siendo nuestro objetivo obtener un vector con las distancias entre dos vértices y otro con los vértices predecesor de cada vértice del camino, para ello nos valdremos de un heap que implementa una cola con prioridad.

Una vez inicializados los elementos como corresponde, procederemos a introducir todos los vértices en el heap, para posteriormente ir sacándolos todos de forma ordenada de menor a mayor, actualizando los datos del heap cuando sea necesario, cuando como indica el algoritmo de Dijkstra, si la distancia desde el punto de partida al punto adyacente actual es mayor que la distancia desde el punto de partida a otro punto adyacente y desde ese punto al punto actual, la distancia del punto actual se cambia por la distancia que acabamos de calcular.

Finalmente, mostraremos el camino de vértices y la distancia que representa para el camino más corto encontrado.

### 2. Resultados
Estos son los resultados que obtenidos con la implementación realizada:

```
germaaan@germaaan-PC:~/Documentos/AL/PRACTICA_3/codigo-prim$ ./dijkstra ftv70.atsp 
Tamaño del Grafo 71
Llamo a Dijkstra (origen) 0
Nodo seleccionado 27 Distancia 13
Nodo seleccionado 0 Distancia 26
Nodo seleccionado 43 Distancia 26
Nodo seleccionado 67 Distancia 38
Nodo seleccionado 68 Distancia 40
Nodo seleccionado 60 Distancia 42
Nodo seleccionado 28 Distancia 46
Nodo seleccionado 30 Distancia 48
Nodo seleccionado 70 Distancia 31
Nodo seleccionado 69 Distancia 38
Nodo seleccionado 40 Distancia 44
Nodo seleccionado 41 Distancia 54
Nodo seleccionado 29 Distancia 57
Nodo seleccionado 1 Distancia 47
Nodo seleccionado 64 Distancia 58
Nodo seleccionado 7 Distancia 28
Nodo seleccionado 50 Distancia 30
Nodo seleccionado 49 Distancia 38
Nodo seleccionado 6 Distancia 42
Nodo seleccionado 35 Distancia 61
Nodo seleccionado 13 Distancia 65
Nodo seleccionado 12 Distancia 66
Nodo seleccionado 23 Distancia 66
Nodo seleccionado 33 Distancia 66
Nodo seleccionado 39 Distancia 66
Nodo seleccionado 42 Distancia 66
Nodo seleccionado 45 Distancia 66
Nodo seleccionado 46 Distancia 66
Nodo seleccionado 48 Distancia 66
Nodo seleccionado 54 Distancia 66
Nodo seleccionado 61 Distancia 66
Nodo seleccionado 25 Distancia 72
Nodo seleccionado 36 Distancia 72
Nodo seleccionado 26 Distancia 74
Nodo seleccionado 65 Distancia 76
Nodo seleccionado 15 Distancia 81
Nodo seleccionado 32 Distancia 85
Nodo seleccionado 3 Distancia 86
Nodo seleccionado 37 Distancia 87
Nodo seleccionado 19 Distancia 95
Nodo seleccionado 38 Distancia 96
Nodo seleccionado 51 Distancia 98
Nodo seleccionado 16 Distancia 99
Nodo seleccionado 2 Distancia 83
Nodo seleccionado 47 Distancia 85
Nodo seleccionado 66 Distancia 90
Nodo seleccionado 4 Distancia 95
Nodo seleccionado 21 Distancia 102
Nodo seleccionado 31 Distancia 102
Nodo seleccionado 58 Distancia 105
Nodo seleccionado 62 Distancia 105
Nodo seleccionado 44 Distancia 106
Nodo seleccionado 20 Distancia 57
Nodo seleccionado 8 Distancia 73
Nodo seleccionado 17 Distancia 94
Nodo seleccionado 57 Distancia 106
Nodo seleccionado 18 Distancia 107
Nodo seleccionado 63 Distancia 109
Nodo seleccionado 24 Distancia 42
Nodo seleccionado 34 Distancia 79
Nodo seleccionado 11 Distancia 112
Nodo seleccionado 56 Distancia 115
Nodo seleccionado 5 Distancia 116
Nodo seleccionado 53 Distancia 120
Nodo seleccionado 55 Distancia 121
Nodo seleccionado 14 Distancia 128
Nodo seleccionado 10 Distancia 132
Nodo seleccionado 52 Distancia 136
Nodo seleccionado 9 Distancia 79
Nodo seleccionado 59 Distancia 112
Nodo seleccionado 22 Distancia 137 
Presentamos los resultados
arco (27,0) costo 13
arco (29,1) costo 47
arco (16,2) costo 83
arco (32,3) costo 143
arco (66,4) costo 165
arco (56,5) costo 93
arco (49,6) costo 149
arco (64,7) costo 28
arco (20,8) costo 89
arco (52,9) costo 79
arco (14,10) costo 106
arco (34,11) costo 94
arco (13,12) costo 69
arco (35,13) costo 137
arco (55,14) costo 94
arco (65,15) costo 62
arco (51,16) costo 100
arco (8,17) costo 100
arco (57,18) costo 122
arco (37,19) costo 123
arco (44,20) costo 57
arco (4,21) costo 65
arco (59,22) costo 162
arco (12,23) costo 75
arco (63,24) costo 42
arco (61,25) costo 76
arco (36,26) costo 104
arco (-1,27) costo 1000
arco (60,28) costo 154
arco (41,29) costo 58
arco (28,30) costo 38
arco (21,31) costo 76
arco (15,32) costo 117
arco (23,33) costo 38
arco (24,34) costo 40
arco (6,35) costo 104
arco (25,36) costo 58
arco (3,37) costo 82
arco (19,38) costo 158
arco (33,39) costo 106
arco (69,40) costo 66
arco (40,41) costo 70
arco (39,42) costo 98
arco (0,43) costo 26
arco (62,44) costo 118
arco (42,45) costo 38
arco (45,46) costo 67
arco (2,47) costo 74
arco (46,48) costo 118
arco (50,49) costo 140
arco (7,50) costo 102
arco (38,51) costo 140
arco (10,52) costo 134
arco (5,53) costo 90
arco (48,54) costo 105
arco (53,55) costo 115
arco (11,56) costo 90
arco (17,57) costo 71
arco (31,58) costo 103
arco (9,59) costo 147
arco (68,60) costo 94
arco (54,61) costo 141
arco (58,62) costo 113
arco (18,63) costo 96
arco (1,64) costo 46
arco (26,65) costo 59
arco (47,66) costo 120
arco (43,67) costo 30
arco (67,68) costo 92
arco (70,69) costo 66
arco (30,70) costo 31
```

```
germaaan@germaaan-PC:~/Documentos/AL/PRACTICA_3/codigo-prim$ ./dijkstra kro124p.atsp
Tamaño del Grafo 100 Llamo a Dijkstra (origen) 0
Nodo seleccionado 0 Distancia 0
Nodo seleccionado 91 Distancia 353
Nodo seleccionado 5 Distancia 436
Nodo seleccionado 62 Distancia 480
Nodo seleccionado 92 Distancia 489
Nodo seleccionado 46 Distancia 621
Nodo seleccionado 7 Distancia 649
Nodo seleccionado 66 Distancia 655
Nodo seleccionado 48 Distancia 690
Nodo seleccionado 27 Distancia 740
Nodo seleccionado 9 Distancia 773
Nodo seleccionado 89 Distancia 773
Nodo seleccionado 74 Distancia 776
Nodo seleccionado 57 Distancia 790
Nodo seleccionado 41 Distancia 799
Nodo seleccionado 97 Distancia 881
Nodo seleccionado 88 Distancia 899
Nodo seleccionado 55 Distancia 963
Nodo seleccionado 83 Distancia 969
Nodo seleccionado 18 Distancia 1009
Nodo seleccionado 73 Distancia 1019
Nodo seleccionado 10 Distancia 1069
Nodo seleccionado 30 Distancia 1075
Nodo seleccionado 90 Distancia 1089
Nodo seleccionado 96 Distancia 1140
Nodo seleccionado 50 Distancia 1168
Nodo seleccionado 60 Distancia 1168
Nodo seleccionado 20 Distancia 1185
Nodo seleccionado 31 Distancia 1186
Nodo seleccionado 3 Distancia 1193
Nodo seleccionado 71 Distancia 1201
Nodo seleccionado 52 Distancia 1205
Nodo seleccionado 78 Distancia 1211
Nodo seleccionado 79 Distancia 1215
Nodo seleccionado 59 Distancia 1218
Nodo seleccionado 37 Distancia 1233
Nodo seleccionado 14 Distancia 1257
Nodo seleccionado 22 Distancia 1266
Nodo seleccionado 76 Distancia 1282
Nodo seleccionado 58 Distancia 1283
Nodo seleccionado 44 Distancia 1308
Nodo seleccionado 64 Distancia 1321
Nodo seleccionado 68 Distancia 1341
Nodo seleccionado 93 Distancia 1359
Nodo seleccionado 16 Distancia 1363
Nodo seleccionado 24 Distancia 1393
Nodo seleccionado 69 Distancia 1395
Nodo seleccionado 86 Distancia 1395
Nodo seleccionado 65 Distancia 1404
Nodo seleccionado 15 Distancia 1413
Nodo seleccionado 61 Distancia 1414
Nodo seleccionado 35 Distancia 1426
Nodo seleccionado 17 Distancia 1451
Nodo seleccionado 23 Distancia 1482
Nodo seleccionado 80 Distancia 1505
Nodo seleccionado 98 Distancia 1530
Nodo seleccionado 63 Distancia 1534
Nodo seleccionado 53 Distancia 1539
Nodo seleccionado 56 Distancia 1557
Nodo seleccionado 87 Distancia 1578
Nodo seleccionado 8 Distancia 1599
Nodo seleccionado 72 Distancia 1610
Nodo seleccionado 19 Distancia 1614
Nodo seleccionado 26 Distancia 1621
Nodo seleccionado 21 Distancia 1644
Nodo seleccionado 85 Distancia 1650
Nodo seleccionado 67 Distancia 1728
Nodo seleccionado 39 Distancia 1735
Nodo seleccionado 34 Distancia 1813
Nodo seleccionado 6 Distancia 1814
Nodo seleccionado 25 Distancia 1819
Nodo seleccionado 49 Distancia 1819
Nodo seleccionado 1 Distancia 1890
Nodo seleccionado 11 Distancia 1932
Nodo seleccionado 33 Distancia 1934
Nodo seleccionado 43 Distancia 1946
Nodo seleccionado 84 Distancia 1946
Nodo seleccionado 82 Distancia 2013
Nodo seleccionado 54 Distancia 2020
Nodo seleccionado 38 Distancia 2110
Nodo seleccionado 29 Distancia 2226
Nodo seleccionado 45 Distancia 2325
Nodo seleccionado 81 Distancia 2330
Nodo seleccionado 28 Distancia 2381
Nodo seleccionado 77 Distancia 2493
Nodo seleccionado 51 Distancia 2499
Nodo seleccionado 94 Distancia 2546
Nodo seleccionado 12 Distancia 2564
Nodo seleccionado 13 Distancia 2566
Nodo seleccionado 42 Distancia 2571
Nodo seleccionado 47 Distancia 2587
Nodo seleccionado 2 Distancia 2629
Nodo seleccionado 95 Distancia 2671
Nodo seleccionado 36 Distancia 2700
Nodo seleccionado 75 Distancia 2843
Nodo seleccionado 4 Distancia 2864
Nodo seleccionado 40 Distancia 2887
Nodo seleccionado 32 Distancia 2923
Nodo seleccionado 99 Distancia 2936
Nodo seleccionado 70 Distancia 2981 
Presentamos los resultados
arco (0,0) costo 0
arco (49,1) costo 1819
arco (47,2) costo 2587
arco (31,3) costo 1186
arco (75,4) costo 2843
arco (91,5) costo 353
arco (34,6) costo 1813
arco (46,7) costo 621
arco (87,8) costo 1578
arco (27,9) costo 740
arco (73,10) costo 1019
arco (1,11) costo 1890
arco (94,12) costo 2546
arco (12,13) costo 2564
arco (37,14) costo 1233
arco (65,15) costo 1404
arco (93,16) costo 1359
arco (35,17) costo 1426
arco (83,18) costo 969
arco (72,19) costo 1610
arco (60,20) costo 1168
arco (26,21) costo 1621
arco (14,22) costo 1257
arco (17,23) costo 1451
arco (16,24) costo 1363
arco (6,25) costo 1814
arco (19,26) costo 1614
arco (48,27) costo 690
arco (81,28) costo 2330
arco (38,29) costo 2110
arco (10,30) costo 1069
arco (20,31) costo 1185
arco (40,32) costo 2887
arco (11,33) costo 1932
arco (39,34) costo 1735
arco (61,35) costo 1414
arco (95,36) costo 2671
arco (59,37) costo 1218
arco (54,38) costo 2020
arco (67,39) costo 1728
arco (4,40) costo 2864
arco (57,41) costo 790
arco (13,42) costo 2566
arco (33,43) costo 1934
arco (58,44) costo 1283
arco (29,45) costo 2226
arco (92,46) costo 489
arco (42,47) costo 2571
arco (66,48) costo 655
arco (25,49) costo 1819
arco (96,50) costo 1140
arco (77,51) costo 2493
arco (71,52) costo 1201
arco (63,53) costo 1534
arco (82,54) costo 2013
arco (88,55) costo 899
arco (53,56) costo 1539
arco (74,57) costo 776
arco (76,58) costo 1282
arco (79,59) costo 1215
arco (50,60) costo 1168
arco (15,61) costo 1413
arco (5,62) costo 436
arco (98,63) costo 1530
arco (44,64) costo 1308
arco (86,65) costo 1395
arco (7,66) costo 672
arco (85,67) costo 1650
arco (64,68) costo 1321
arco (24,69) costo 1393
arco (99,70) costo 2936
arco (3,71) costo 1193
arco (8,72) costo 1599
arco (18,73) costo 1009
arco (89,74) costo 773
arco (36,75) costo 2700
arco (22,76) costo 1266
arco (28,77) costo 2381
arco (52,78) costo 1205
arco (78,79) costo 1211
arco (23,80) costo 1482
arco (45,81) costo 2325
arco (84,82) costo 1946
arco (55,83) costo 963
arco (43,84) costo 1946
arco (21,85) costo 1644
arco (69,86) costo 1395
arco (56,87) costo 1557
arco (97,88) costo 881
arco (9,89) costo 773
arco (30,90) costo 1075
arco (0,91) costo 353
arco (62,92) costo 480
arco (68,93) costo 1341
arco (51,94) costo 2499
arco (2,95) costo 2629
arco (90,96) costo 1089
arco (41,97) costo 799
arco (80,98) costo 1505
arco (32,99) costo 2923
```
