Fundamentos de Bases de Datos
=============================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Ejercicios de calculo relacional
### Germán Martínez Maldonado 


## Ejercicio 1

* Tablas:
 * PROVEEDOR (**CODPRO**, NOMPRO, STATUS, CIUDAD)
 * PIEZA (**CODPIE**, NOMPIE, COLOR, PESO, CIUDAD)
 * PROYECTO (**CODPJ**, NOMPJ, CIUDAD)
 * VENTAS (**CODPRO, CODPIE, CODPJ**, CANTIDAD, FECHA)

* Dominios:
 * RANGE Sx IN PROVEEDOR
 * RANGE Px IN PIEZA
 * RANGE Jx IN PROYECTO
 * RANGE SPJx IN VENTAS

### a) Encontrar los códigos de los proveedores que suministran alguna pieza a J1.

SELECT SPJx.CODPRO WHERE SPJx.CODPJ=J1

### b) Encontrar los suministros cuya cantidad supere las 100 unidades.

SELECT SPJx.CODPRO,SPJx.CODPIE,SPJx.CODPJ WHERE SPJx.CANTIDAD>100

### c) Encontrar los nombres de proveedores, piezas y proyectos que se encuentren en la misma ciudad.

SELECT Sx.NOMBRE,Px.NOMBRE,Jx.NOMBRE WHERE ((Sx.CODPRO=SPJx.CODPRO) ^ (Px.CODPIE=SPJx.CODPIE) ^ (Jx.CODPJ=SPJx.CODPJ) ^ (Sx.CIUDAD=Px.CIUDAD) ^ (Sx.CIUDAD=Jx.CIUDAD) ^ (Px.CIUDAD=Jx.CIUDAD))

### d) Encontrar los nombres de las piezas suministradas por los proveedores de Londres.

SELECT Px.NOMPIE WHERE ¬∃ Sx ((Sx.CODPRO=SPJx.CODPRO) ^ (Sx.CIUDAD<>LONDRES)) ^ ∃ SPJx (Px.CODPIE=SPJx.CODPIE)

### e) Encontrar todas las parejas de ciudades tales que la primera sea la de un proveedor y la segunda la de un proyecto entre los cuales haya algún suministro.

SELECT Sx.CIUDAD,Jx.CIUDAD WHERE ((Sx.CODPRO=SPJx.CODPRO) ^ (Jx.CODPJ=SPJx.CODPJ))

### f) Encontrar los códigos de las piezas suministradas a algún proyecto por un proveedor que se encuentre en la misma ciudad que el proyecto.

SELECT SPJx.CODPIE WHERE ((Sx.CODPRO=SPJx.CODPRO) ^ (Jx.CODPJ=SPJx.CODPJ) ^ (Sx.CIUDAD=Jx.CIUDAD))

### g) Encontrar los códigos de los proyectos que tienen al menos un proveedor que no se encuentra en su misma ciudad.

SELECT SPJx.CODPIE WHERE ((Sx.CODPRO=SPJx.CODPRO) ^ (Jx.CODPJ=SPJx.CODPJ) ^ (Sx.CIUDAD<>Jx.CIUDAD))

### h) Mostrar todas las ciudades de donde proveden piezas y donde hay proyectos.

SELECT Sx.CIUDAD WHERE ¬∃ Jx,SPJx ((Px.CODPIE=SPJx.CODPIE) ^ (Jx.CODPJ=SPJx.CODPJ) ^ (Px.CIUDAD<>Jx.CIUDAD)) ^ ∃ SPJx (Sx.CODPRO=SPJx.CODPRO)

### i) Mostrar todas las ciudades de los proveedores en las que no se fabriquen piezas.

SELECT Sx.CIUDAD WHERE ¬∃ Px ((Sx.CODPRO=SPJx.CODPRO) ^ (Px.CODPIE=SPJx.CODPIE) ^ (Sx.CIUDAD=Px.CIUDAD))

### j) Mostrar todas las ciudades de los proveedores en las que además se fabriquen piezas.

SELECT Sx.CIUDAD WHERE ¬∃ Px ((Sx.CODPRO=SPJx.CODPRO) ^ (Px.CODPIE=SPJx.CODPIE) ^ (Sx.CIUDAD<>Px.CIUDAD))

### k) Encontrar los códigos de los proyectos que usan una pieza que vende S1.

SELECT SPJx.CODPJ WHERE SPJx.CODPRO=S1

### l) Encontrar la cantidad más pequeña enviada en algún suministro.

SELECT SPJx.CANTIDAD WHERE ¬∃ SPJy (SPJy.CANTIDAD > SPJx.CANTIDAD)

### m) Encontrar los códigos de los proyectos que no utilizan una pieza roja suministrada por un proveedor de Londres.

SELECT SPJx.CODPJ WHERE ¬∃ Px,SPJx ((Px.CODPIE=SPJx.CODPIE) ^ (Sx.CODPRO=SPJx.CODPRO) ^ (Px.COLOR=ROJO) ^ (Sx.CIUDAD<>LONDRES))

### n) Encontrar los códigos de los proyectos que tienen como único proveedor a S1.

SELECT SPJx.CODPJ WHERE ¬∃ Sx ((Sx.CODPRO=SPJx.CODPRO) ^ (Sx.CODPRO<>S1))

### ñ) Encontrar los códigos de las piezas suministradas a todos los proyectos de Paris.

SELECT SPJx.CODPIE WHERE ∀ Jx (∃ SPJx ((SPJx.CODPJ=Jx.CODPJ) ^ (Jx.CIUDAD=PARIS))

### o) Encontrar los códigos de los proveedores que venden la misma pieza a todos los proyectos.

SELECT SPJx.CODPRO WHERE ∀ Jx (∃ Px ((SPJx.CODPIE=Px.CODPIE) ^ (SPJx.CODPJ=Jx.CODPJ))

### p) Encontrar lod códigos de los proyectos a los que S1 suministra todas las piezas existentes.

SELECT SPJx.CODPJ WHERE ∀ Px (∃ Sx ((SPJx.CODPRO=Sx.CODPRO) ^ (SPJx.CODPIE) ^ (Sx.CODPRO=S1))


## Ejercicio 2

* Tablas:
 * LISTA_BODA (**REF#**, DESCRIPCION, PRECIO)
 * INVITACIONES (**NOMBRE**, DIRECCION, CIUDAD)
 * CONFIRMAN (**NOMBRE**, NUMERO)
 * RESERVA_REGALO (**NOMBRE**, REF#, FECHA)

* Dominios:
 * RANGE Lx IN LISTA_BODA
 * RANGE Ix IN INVITACIONES
 * RANGE Cx IN CONFIRMAN
 * RANGE Rx IN RESERVA_REGALO

### a) Encontrar los regalos (descripcion) que no han sido reservadas.

SELECT Lx.DESCRIPCION WHERE ¬∃ Rx (Lx.REF#=Rx.REF#)

### b) Encontrar la dirección de los invitados que confirman la asistencia de más de dos personas.

SELECT Ix.DIRECCION WHERE ((Ix.NOMBRE=Cx.NOMBRE) ^ (Cx.NUMERO>2))

### c) Encontrar el nombre y la referencia del regalo más caro ya reservado.

SELECT Rx.NOMBRE,Rx.REF# WHERE ((¬∃ Ly (Ly.PRECIO>Lx.PRECIO)) ^ (∃ Lx (Lx.REF#=R.REF#)))


## Ejercicio 3

* Tablas:
 * HOMBRES (**NomH**, EDAD)
 * MUJERES (**NomM**, EDAD)
 * HSimM (**NomH, NomM**)
 * MSimH (**NomM, NomH**)
 * MATRIM (**NomH, NomM**)

* Dominios:
 * RANGE Hx IN HOMBRES
 * RANGE Mx IN MUJERES
 * RANGE HSMx IN HSimM
 * RANGE MSHx IN MSimH
 * RANGE MAx IN MATRIM

### a) Hallar las parejas de hombres y mujeres que se caen mutuamente simpáticos, con edades entre 20 y 30 años y que no estén casados entre sí.

SELECT Hx.NomH,Mx.NomM WHERE ((¬∃ MAx ((MAx.NomH=Hx.NomH) ^ (MAx.NomM=Mx.NomM) ^ (∃ HSMx,MSHx ((Hx.NomH=HSM.NomH) ^ (Hx.NomH=MSH.NomH) ^ (Mx.NomM=HSMx.NomM) ^ (Mx.NomM=MSHx.NomM) ^ (Hx.EDAD>20) ^ (Hx.EDAD<30) ^ (Hx.EDAD>20) ^ (Hx.EDAD<30)))

### b) Hallar las mujeres casadas a las que no cae simpático su marido.

SELECT MAx.NomM WHERE ¬∃ HSMx (MAx.NomM=HSMx.NomM)

### c) Hallar los hombres a los que no les cae simpática ninguna mujers.

SELECT Hx.NomH WHERE ¬∃ MSHx (MSHx.NomH=Hx.NomH)

### d) Hallar las mujeres casadas a las que no les cae simpático ningún hombre casado.

SELECT MAx.NomM WHERE ¬∃ HSMx ((HSMx.NomH=MAx.NomH) ^ (HSMx.NomM = MAx.NomM))


## Ejercicio 4

* Tablas:
 * CONDUCTOR (**DNI**, NOMBRE, DIREC, PROV)
 * VEHICULO (**MATRICULA**, CARGA_MAX, FECHA_COMPRA)
 * RUTA (**RUTA#**, CIUDAD_SAL, CIUDAD_LLEG, KM)
 * VIAJE (**VIAJE#**, DNI, MATRICULA)
 * PROG_VIAJE (**VIAJE#, RUTA#, DIA_SEM, HORA_SAL, HORA_LLEG)

* Dominios:
 * RANGE Cx IN CONDUCTOR
 * RANGE Vx IN VEHICULO
 * RANGE Rx IN RUTA
 * RANGE VIx IN VIAJE
 * RANGE Px IN PROG_VIAJE

### a) Encontrar entre qué dos ciudades se realiza el viaje más largo.

SELECT Rx.CIUDAD_SAL,Rx.CIUDAD_LLEG WHERE ¬∃ Ry (Ry.KM > Rx.RM)

### b) Listar los nombres de los conductores que hayan llevado todos los camiones de la empresa.

SELECT Cx.NOMBRE WHERE ∀ Vx (∃ VIx ((VIx.DNI=Cx.DNI) ^ (VIx.MATRICULA=Vx.MATRICULA))

### c) Encontrar que días de la semana se hacen viajes entre Granada y Sevilla por la mañana (antes de las 13h).

SELECT Px.DIA_SEM WHERE ((Px.RUTA# = Rx.RUTA#) ^ (Px.HORA_SAL<13) ^ (Rx.CIUDAD_SAL=GRANADA) ^ (Rx.CIUDAD_LLEG=SEVILLA))

### d) Encontrar las rutas que se hacen todos los días de la semana, suponiendo que hay viajes todos los días.

SELECT Rx.RUTA# WHERE ∀ Ry (Rx.DIA_SEM = Ry.DIA_SEM)


## Ejercicio 5

* Tablas:
 * REPRESENTANTE (**DNI**, NOMBRE, DIREC, PROVINCIA)
 * ZONA_REP (**DNI, COD_ZONA**, POBLACION, PROVINCIA)
 * PEDIDOS (**DNI, COD_ART**, CANTIDAD, POBLACION)
 * ARTICULO (**COD_ART**, NOMBRE, COLOR, PROV_FAB)

* Dominios:
 * RANGE Rx IN REPRESENTANTE
 * RANGE Zx IN ZONA_REP
 * RANGE Px IN PEDIDOS
 * RANGE Ax IN ARTICULO

### a) Listar las provincias que son visitadas por todos los representantes.

SELECT Zx.PROVINCIA WHERE ∀ Rx (∃ Zy (Rx.DNI=Zy.DNI) ^ (Zx.PROVINCIA=Zy.PROVINCIA))

### b) Encontrar los representantes que venden fuera de su provincia artículos fabricados en su provincia.

SELECT Rx.DNI WHERE ∃ Zx ((Rx.DNI=Zx.DNI) ^ (Rx.PROVINCIA<>Zx.PROVINCIA)) ^ ¬∃ Ax ((Px.DNI=Rx.DNI) ^ (Px.COD_ART=Ax.COD_ART) ^ (Rx.PROVINCIA<>Ax.PROV_FAB))

### c) Obtener las poblaciones de Granada que hayan superado los 50.000 euros de facturación y quién realizó el pedido.

SELECT Zx.POBLACION,Zx.DNI WHERE ((Zx.DNI=Px.DNI) ^ (Zx.PROVINCIA=GRANADA) ^ (Px.CANTIDAD>50000))

### d) Mostrar las zonas que incluyen a una sola población.

SELECT Zx.COD_ZONA WHERE ¬∃ Zy (Zy.POBLACION<>Zx.POBLACION)

### e) Encontrar el código del artículo vendido en mayor cantidad

SELECT Px.COD_ART WHERE ¬∃ Py (Py.CANTIDAD > Px.CANTIDAD)


## Ejercicio 6

* Tablas:
 * INSCRIPCIONES (**INS#**, NOMBRE, PROCEDENCIA)
 * SESIONES (**SES#**, TITULO, COORD#)
 * ARTICULOS (**ART#**, TITULO)
 * PROGRAMAS (**SES#, ART#**, FECHA, HORA_INICIO, HORA_FIN, SALA, PONENTE#)

* Dominios:
 * RANGE Ix IN INSCRIPCIONES
 * RANGE Sx IN SESIONES
 * RANGE Ax IN ARTICULOS
 * RANGE Px IN PROGRAMAS

### a) Mostrar los nombres de los ponentes que coordinan su propia sesión.

SELECT Ix.NOMBRE WHERE ((Ix.INS#=Px.PONENTE#) ^ (Px.PONENTE#=Sx.COORD#) ^ (Sx.SES#=Px.SES#))

### b) Seleccionar los coordinadores que coordinan una única sesión.

SELECT Sx.COORD# WHERE ¬∃ Sy (Sy.COORD#<>Sx.COORD#)

### c) Mostrar el título de los artículos que se exponen en primer y último lugar.

SELECT Ax.TITULO WHERE ¬∃ Ay ((Ay.HORA_INICIO<Ax.HORA_INICIO) ^ (Ay.HORA_FIN>Ax.HORA_FIN))
