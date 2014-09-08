Ingeniería de Servidores
=========================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Ejecuciones ApacheBench
### Jesús Gómez Obregón
### Germán Martínez Maldonado


## ÍNDICE DE CONTENIDOS

1. [Pruebas de rendimiento a Tomcat](anexo_02.md#1-pruebas-de-rendimiento-a-tomcat)
2. [Pruebas de rendimiento a JBoss](anexo_02.md#2-pruebas-de-rendimiento-a-jboss)
3. [Pruebas de rendimiento a GlassFish](anexo_02.md#3-pruebas-de-rendimiento-a-glassfish)


## 1. PRUEBAS DE RENDIMIENTO A TOMCAT

### Primera prueba

```
[root@localhost ~]# ab -kc 500 -n 1000000 -g tomcat1.txt http://localhost:8080/prueba/prueba/
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        989 bytes

Concurrency Level:      500
Time taken for tests:   225.011 seconds 
Complete requests:      1000000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000074
Keep-Alive requests:    342300
Total transferred:      1163797498 bytes 
HTML transferred:       989073186 bytes 
Requests per second:    4444.23 [#/sec] (mean) 
Time per request:       112.505 [ms] (mean)
Time per request:       0.225 [ms] (mean, across all concurrent requests) 
Transfer rate:          5050.96 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       66      337.6   26      15042
Processing:     0       46      42.8    42      2012
   Waiting:     0       35      39.5    34      2013
     Total:     0       112     342.2   71      15096

Percentage of the requests served within a certain time (ms) 
 50%    71
 66%    79
 75%    85
 80%    88
 90%    106
 95%    173
 98%    1069
 99%    1105
 100%   15096 (longest request)
```

### Segunda prueba

```
[root@localhost ~]# ab -kc 10 -n 1000000 -g tomcat2.txt http://localhost:8080/prueba/prueba/
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        989 bytes
Concurrency Level:      10
Time taken for tests:   151.135 seconds 
Complete requests:      1000000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000009
Keep-Alive requests:    990004
Total transferred:      1166960523 bytes 
HTML transferred:       989008901 bytes 
Requests per second:    6616.60 [#/sec] (mean) 
Time per request:       1.511 [ms] (mean)
Time per request:       0.151 [ms] (mean, across all concurrent requests) 
Transfer rate:          7540.34 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.3     0       47
Processing:     0       1       5.5     1       2126
   Waiting:     0       1       5.4     1       2126
     Total:     0       2       5.5     1       2126

Percentage of the requests served within a certain time (ms)
 50%    1
 66%    1
 75%    1
 80%    1
 90%    1
 95%    2
 98%    4
 99%    5
 100%   2126 (longest request)
```

### Tercera prueba

```
[root@localhost ~]# ab -kc 500 -n 500000 -g tomcat3.txt http://localhost:8080/prueba/prueba/
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        989 bytes
Concurrency Level:      500
Time taken for tests:   102.917 seconds 
Complete requests:      500000
Failed requests:        0
Write errors:           0
Non-2xx responses:      500194
Keep-Alive requests:    169287
Total transferred:      582071863 bytes 
HTML transferred:       494691866 bytes 
Requests per second:    4858.30 [#/sec] (mean) 
Time per request:       102.917 [ms] (mean)
Time per request:       0.206 [ms] (mean, across all concurrent requests) 
Transfer rate:          5523.20 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       60      340.0   26      15046
Processing:     0       42      22.1    42      814
   Waiting:     0       31      21.9    34      793
     Total:     0       102     341.3   70      15124

Percentage of the requests served within a certain time (ms) 
 50%    70
 66%    77
 75%    83
 80%    86
 90%    93
 95%    107
 98%    1061
 99%    1085
 100% 15124 (longest request)
```

### Cuarta prueba

```
[root@localhost ~]# ab -kc 10 -n 500000 -g tomcat4.txt http://localhost:8080/prueba/prueba/ 
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        989 bytes
Concurrency Level:      10
Time taken for tests:   65.447 seconds 
Complete requests:      500000
Failed requests:        0
Write errors:           0
Non-2xx responses:      500006
Keep-Alive requests:    495005
Total transferred:      583482027 bytes 
HTML transferred:       494505934 bytes 
Requests per second:    7639.75 [#/sec] (mean) 
Time per request:       1.309 [ms] (mean)
Time per request:       0.131 [ms] (mean, across all concurrent requests) 
Transfer rate:          8706.36 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       60      340.0   26      15046
Processing:     0       42      22.1    42      814
   Waiting:     0       31      21.9    34      793
     Total:     0       102     341.3   70      15124

Percentage of the requests served within a certain time (ms)
 50%    1
 66%    1
 75%    1
 80%    1
 90%    1
 95%    2
 98%    3
 99%    4
 100%   145 (longest request)
```

### Quinta prueba

```
[root@localhost ~]# ab -kc 500 -n 1000 -g tomcat5.txt http://localhost:8080/prueba/prueba/ 
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        989 bytes
Concurrency Level:      500
Time taken for tests:   0.244 seconds 
Complete requests:      1000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1065
Keep-Alive requests:    999
Total transferred:      1242850 bytes
HTML transferred:       1053285 bytes 
Requests per second:    4092.34 [#/sec] (mean) 
Time per request:       122.179 [ms] (mean)
Time per request:       0.244 [ms] (mean, across all concurrent requests) 
Transfer rate:          4966.96 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       5       12.6    0       42
Processing:     0       23      39.2    5       143
   Waiting:     0       23      39.2    5       143
     Total:     0       28      40.3    5       143

Percentage of the requests served within a certain time (ms)
 50%    5
 66%    18
 75%    46
 80%    53
 90%    74
 95%    135
 98%    141
 99%    142
 100%   143 (longest request)
```

### Sexta prueba

```
[root@localhost ~]# ab -kc 10 -n 1000 -g tomcat6.txt http://localhost:8080/prueba/prueba/ 
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        989 bytes
Concurrency Level:      10
Time taken for tests:   0.206 seconds 
Complete requests:      1000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000
Keep-Alive requests:    990
Total transferred:      1166950 bytes
HTML transferred:       989000 bytes 
Requests per second:    4849.52 [#/sec] (mean) 
Time per request:       2.062 [ms] (mean)
Time per request:       0.206 [ms] (mean, across all concurrent requests)
Transfer rate:          5526.51 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.4     0       6
Processing:     1       2       1.3     1       10
   Waiting:     0       2       1.2     1       10
     Total:     1       2       1.4     1       10

Percentage of the requests served within a certain time (ms)
 50%    1
 66%    2
 75%    2
 80%    3
 90%    4
 95%    5
 98%    8
 99%    9
 100%   10 (longest request)
```

## 2. PRUEBAS DE RENDIMIENTO A JBOSS

### Primera prueba

```
[root@localhost ~]# ab -kc 500 -n 1000000 -g jboss1.txt http://localhost:8080/prueba/prueba/

Server Software:        Apache-Coyote/1.1 Server Hostname:              localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1011 bytes
Concurrency Level:      500
Time taken for tests:   115.931 seconds 
Complete requests:      1000000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000100
Keep-Alive requests:    1000000
Total transferred:      1190119000 bytes 
HTML transferred:       1011101100 bytes 
Requests per second:    8625.80 [#/sec] (mean) 
Time per request:       57.966 [ms] (mean)
Time per request:       0.116 [ms] (mean, across all concurrent requests) 
Transfer rate:          10025.12 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       1.4     0       65
Processing:     1       58      17.0    52      199
   Waiting:     0       58      17.0    52      199
     Total:     1       58      17.1    52      199

Percentage of the requests served within a certain time (ms)
 50%    52
 66%    59
 75%    65
 80%    68
 90%    79
 95%    91
 98%    106
 99%    117
 100%   199 (longest request)
```

### Segunda prueba

```
[root@localhost ~]# ab -kc 10 -n 1000000 -g jboss2.txt http://localhost:8080/prueba/prueba/

Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1011 bytes
Concurrency Level:      10
Time taken for tests:   88.110 seconds 
Complete requests:      1000000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000002
Keep-Alive requests:    1000000
Total transferred:      1190002380 bytes 
HTML transferred:       1011002022 bytes 
Requests per second:    11349.46 [#/sec] (mean) 
Time per request:       0.881 [ms] (mean)
Time per request:       0.088 [ms] (mean, across all concurrent requests) 
Transfer rate:          13189.34 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.0     0       3
Processing:     0       1       0.9     1       46
   Waiting:     0       1       0.9     1       46
     Total:     0       1       0.9     1       46

Percentage of the requests served within a certain time (ms)
 50%    1
 66%    1
 75%    1
 80%    1
 90%    1
 95%    1
 98%    1
 99%    3
 100%   46 (longest request)
```

### Tercera prueba

```
[root@localhost ~]# ab -kc 500 -n 500000 -g jboss3.txt http://localhost:8080/prueba/prueba/

Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1011 bytes
Concurrency Level:      500
Time taken for tests:   51.611 seconds 
Complete requests:      500000
Failed requests:        0
Write errors:           0
Non-2xx responses:      500283
Keep-Alive requests:    500000
Total transferred:      595336770 bytes 
HTML transferred:       505786113 bytes 
Requests per second:    9687.81 [#/sec] (mean) 
Time per request:       51.611 [ms] (mean)
Time per request:       0.103 [ms] (mean, across all concurrent requests) 
Transfer rate:          11264.67 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       2.1     0       88
Processing:     1       51      13.7    49      165
   Waiting:     1       51      13.8    49      165
     Total:     1       51      14.0    49      165

Percentage of the requests served within a certain time (ms)
 50%    49
 66%    51
 75%    53
 80%    57
 90%    68
 95%    77
 98%    97
 99%    104
 100%   165 (longest request)
```

### Cuarta prueba

```
[root@localhost ~]# ab -kc 10 -n 500000 -g jboss4.txt http://localhost:8080/prueba/prueba/ 
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1011 bytes
Concurrency Level:      10
Time taken for tests:   40.466 seconds 
Complete requests:      500000
Failed requests:        0
Write errors:           0
Non-2xx responses:      500002
Keep-Alive requests:    500000
Total transferred:      595002380 bytes 
HTML transferred:       505502022 bytes 
Requests per second:    12355.96 [#/sec] (mean) 
Time per request:       0.809 [ms] (mean)
Time per request:       0.081 [ms] (mean, across all concurrent requests) 
Transfer rate:  14359.04 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.0     0       2
Processing:     0       1       0.5     1       29
   Waiting:     0       1       0.4     1       26
     Total:     0       1       0.5     1       29

Percentage of the requests served within a certain time (ms)
 50%    1
 66%    1
 75%    1
 80%    1
 90%    1
 95%    1
 98%    1
 99%    2
 100%   29 (longest request)
```

### Quinta prueba

```
[root@localhost ~]# ab -kc 500 -n 1000 -g jboss5.txt http://localhost:8080/prueba/prueba/ 
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1011 bytes
Concurrency Level:      500
Time taken for tests:   0.266 seconds 
Complete requests:      1000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1211
Keep-Alive requests:    1000
Total transferred:      1441090 bytes
HTML transferred:       1224321 bytes 
Requests per second:    3759.38 [#/sec] (mean) 
Time per request:       133.000 [ms] (mean)
Time per request:       0.266 [ms] (mean, across all concurrent requests) 
Transfer rate:          5290.64 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       24      24.5    39      54
Processing:     21      60      23.1    52      116
   Waiting:     21      59      23.2    52      112
     Total:     21      84      41.9    86      166

Percentage of the requests served within a certain time (ms)
 50%    86
 66%    115
 75%    119
 80%    128
 90%    146
 95%    155
 98%    161
 99%    164
 100%   166 (longest request)
```

### Sexta prueba

```
[root@localhost ~]# ab -kc 10 -n 1000 -g jboss6.txt http://localhost:8080/prueba/prueba/ 
Server Software:        Apache-Coyote/1.1
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1011 bytes
Concurrency Level:      10
Time taken for tests:   0.110 seconds 
Complete requests:      1000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1004
Keep-Alive requests:    1000
Total transferred:      1194760 bytes
HTML transferred:       1015044 bytes 
Requests per second:    9129.50 [#/sec] (mean) 
Time per request:       1.095 [ms] (mean)
Time per request:       0.110 [ms] (mean, across all concurrent requests) 
Transfer rate:          10651.92 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.2     0       2
Processing:     0       1       1.2     1       31
   Waiting:     0       1       1.1     1       26
     Total:     0       1       1.3     1       31

Percentage of the requests served within a certain time (ms)
 50%    1
 66%    1
 75%    1
 80%    1
 90%    1
 95%    2
 98%    4
 99%    7
 100%   31 (longest request)
```


## 3. PRUEBAS DE RENDIMIENTO A GLASSFISH

### Primera prueba

```
[root@localhost ~]# ab -kc 500 -n 1000000 -g glassfish1.txt http://localhost:8080/prueba/prueba/
Server Software:        GlassFish
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1071 bytes
Concurrency Level:      500
Time taken for tests:   335.939 seconds 
Complete requests:      1000000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000000
Keep-Alive requests:    996500
Total transferred:      1368982500 bytes 
HTML transferred:       1071000000 bytes 
Requests per second:    2976.73 [#/sec] (mean) 
Time per request:       167.969 [ms] (mean)
Time per request:       0.336 [ms] (mean, across all concurrent requests) 
Transfer rate:          3979.58 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       8.9     0       1002
Processing:     30      168     10.7    166     347
   Waiting:     30      168     10.7    166     347
     Total:     112     168     14.3    166     1281

Percentage of the requests served within a certain time (ms)
 50%    166
 66%    169
 75%    171
 80%    173
 90%    179
 95%    187
 98%    196
 99%    206
 100%   1281 (longest request)
```

### Segunda prueba

```
[root@localhost ~]# ab -kc 10 -n 1000000 -g glassfish2.txt http://localhost:8080/prueba/prueba/
Server Software:        GlassFish
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1071 bytes
Concurrency Level:      10
Time taken for tests:   330.465 seconds 
Complete requests:      1000000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000000
Keep-Alive requests:    996021
Total transferred:      1368980105 bytes 
HTML transferred:       1071000000 bytes 
Requests per second:    3026.04 [#/sec] (mean) 
Time per request:       3.305 [ms] (mean)
Time per request:       0.330 [ms] (mean, across all concurrent requests) 
Transfer rate:          4045.49 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.0     0       4
Processing:     0       3       2.8     2       72
   Waiting:     0       3       2.8     2       72
     Total:     0       3       2.8     2       72

Percentage of the requests served within a certain time (ms)
 50%    2
 66%    2
 75%    2
 80%    4
 90%    9
 95%    9
 98%    10
 99%    11
 100%   72 (longest request)
```

### Tercera prueba

```
[root@localhost ~]# ab -kc 500 -n 500000 -g glassfish3.txt http://localhost:8080/prueba/prueba/
Server Software:        GlassFish
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1071 bytes
Concurrency Level:      500
Time taken for tests:   161.642 seconds 
Complete requests:      500000
Failed requests:        0
Write errors:           0
Non-2xx responses:      500000
Keep-Alive requests:    498466
Total transferred:      684492330 bytes 
HTML transferred:       535500000 bytes 
Requests per second:    3093.26 [#/sec] (mean) 
Time per request:       161.642 [ms] (mean)
Time per request:       0.323 [ms] (mean, across all concurrent requests) 
Transfer rate:          4135.38 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       11.9    0       1014
Processing:     28      161     11.1    161     269
   Waiting:     7       161     11.1    161     269
     Total:     46      162     16.1    161     1194

Percentage of the requests served within a certain time (ms)
 50%    161
 66%    165
 75%    167
 80%    169
 90%    173
 95%    178
 98%    185
 99%    189
 100%   1194 (longest request)
```

### Cuarta prueba

```
[root@localhost ~]# ab -kc 10 -n 500000 -g glassfish4.txt http://localhost:8080/prueba/prueba/
Server Software:        GlassFish
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1071 bytes
Concurrency Level:      10
Time taken for tests:   158.422 seconds 
Complete requests:      500000
Failed requests:        0
Write errors:           0
Non-2xx responses:      500000
Keep-Alive requests:    498014
Total transferred:      684490070 bytes 
HTML transferred:       535500000 bytes 
Requests per second:    3156.14 [#/sec] (mean) 
Time per request:       3.168 [ms] (mean)
Time per request:       0.317 [ms] (mean, across all concurrent requests) 
Transfer rate:          4219.42 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.0     0       11
Processing:     0       3       2.8     2       64
   Waiting:     0       3       2.8     2       64
     Total:     0       3       2.8     2       64

Percentage of the requests served within a certain time (ms)
 50%    2
 66%    2
 75%    2
 80%    3
 90%    9
 95%    9
 98%    10
 99%    11
 100%   64 (longest request)
```

### Quinta prueba

```
[root@localhost ~]# ab -kc 500 -n 1000 -g glassfish5.txt http://localhost:8080/prueba/prueba/
Server Software:        GlassFish
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1071 bytes
Concurrency Level:      500
Time taken for tests:   0.548 seconds 
Complete requests:      1000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000
Keep-Alive requests:    1000
Total transferred:      1369000 bytes
HTML transferred:       1071000 bytes 
Requests per second:    1826.07 [#/sec] (mean) 
Time per request:       273.812 [ms] (mean)
Time per request:       0.548 [ms] (mean, across all concurrent requests) 
Transfer rate:          2441.30 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       21      32.5    0       94
Processing:     3       121     50.9    144     368
   Waiting:     3       121     50.9    144     368
     Total:     67      142     38.3    149     419

Percentage of the requests served within a certain time (ms)
 50%    149
 66%    156
 75%    160
 80%    162
 90%    172
 95%    205
 98%    228
 99%    243
 100%   419 (longest request)
```

### Sexta prueba

```
[root@localhost ~]# ab -kc 10 -n 1000 -g glassfish6.txt http://localhost:8080/prueba/prueba/ 
Server Software:        GlassFish
Server Hostname:        localhost
Server Port:            8080

Document Path:          /prueba/prueba/
Document Length:        1071 bytes
Concurrency Level:      10
Time taken for tests:   0.401 seconds 
Complete requests:      1000
Failed requests:        0
Write errors:           0
Non-2xx responses:      1000
Keep-Alive requests:    1000
Total transferred:      1369000 bytes
HTML transferred:       1071000 bytes 
Requests per second:    2491.40 [#/sec] (mean) 
Time per request:       4.014 [ms] (mean)
Time per request:       0.401 [ms] (mean, across all concurrent requests) 
Transfer rate:          3330.79 [Kbytes/sec] received

Connection Times (ms)
　　　　　　         min     mean    [+/-sd] median   max 
   Connect:     0       0       0.9     0       10
Processing:     1       4       3.3     2       25
   Waiting:     1       4       3.3     2       25
     Total:     1       4       3.5     2       30

Percentage of the requests served within a certain time (ms)
 50%    2
 66%    3
 75%    5
 80%    7
 90%    9
 95%    11
 98%    13
 99%    17
 100%   30 (longest request)
```
