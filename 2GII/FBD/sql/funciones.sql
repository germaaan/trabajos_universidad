SQL*Plus: Release 8.0.6.0.0 - Production on Jue May 17 12:08:50 2012

(c) Copyright 1999 Oracle Corporation.  All rights reserved.


Conectado a:
Oracle Database 10g Enterprise Edition Release 10.2.0.3.0 - Production
With the Partitioning, OLAP and Data Mining options


SQL> select min(cantidad), max(cantidad) from ventas;

MIN(CANTIDAD) MAX(CANTIDAD)
------------- -------------
           10          4500

SQL> describe ventas;
 Name                            Null?    Type
 ------------------------------- -------- ----
 CODPRO                          NOT NULL CHAR(3)
 CODPIE                          NOT NULL CHAR(3)
 CODPJ                           NOT NULL CHAR(3)
 CANTIDAD                                 NUMBER(4)
 FECHA                                    DATE


SQL> select proveedor.* from proveedor
  2  where 4<= (select count(*) from ventas where ventas.codpro = proveedor.codpro);

COD NOMPRO                            STATUS CIUDAD
--- ------------------------------ --------- ---------------
S1  Jose Fernandez                         2 Madrid
S4  Pedro Sanchez                          4 Paris

SQL> select codpie, count(*), sum(cantidad) from ventas group by codpie;

COD  COUNT(*) SUM(CANTIDAD)
--- --------- -------------
P3          4          1330
P5          3           335
P2          6          6780
P4          3           550
P1          6          2740

SQL> select codpie, count(*), sum(cantidad) from ventas group by codpie order by codpie;

COD  COUNT(*) SUM(CANTIDAD)
--- --------- -------------
P1          6          2740
P2          6          6780
P3          4          1330
P4          3           550
P5          3           335

SQL> select codpie, count(*) cantidadEnvios, sum(cantidad) totalEnviados from ventas
  2  group by codpie order by codpie;

COD CANTIDADENVIOS TOTALENVIADOS
--- -------------- -------------
P1               6          2740
P2               6          6780
P3               4          1330
P4               3           550
P5               3           335

SQL> select nompie nombre, count(*) cantidad_envios, sum(cantidad) total_enviados
  2  from ventas,pieza where ventas.codpie = pieza.codpie
  3  group by nompie order by nompie;

NOMBRE     CANTIDAD_ENVIOS TOTAL_ENVIADOS
---------- --------------- --------------
Alcayata                 3            335
Arandela                 4           1330
Clavo                    3            550
Tornillo                 6           6780
Tuerca                   6           2740

SQL> select codpj,codpro, count(*) from ventas group by codpj,codpro order by codpj,codpro

COD COD  COUNT(*)
--- --- ---------
J1  S1          4
J1  S2          1
J1  S3          2
J1  S4          2
J2  S1          1
J2  S2          2
J2  S5          1
J3  S1          2
J3  S3          1
J3  S4          2
J3  S5          1
J4  S1          2
J4  S5          1

13 filas seleccionadas.


SQL> select codpj,codpro,count(*) from ventas
  2  where ventas.fecha between to_date('01/01/2012') and to_date('31/12/2012')
  3  group by codpj,codpro
  4  having codpj in (select codpj from ventas ven where ven.fecha between
  5  to_date('01/01/2011') and to_date('31/12/2011'))
  6  order by codpj,codpro;

ninguna fila seleccionada

SQL> save funcionesAgregacion.sql replace;
Escrito fichero funcionesAgregacion.sql
SQL> 
