Fundamentos de Bases de Datos
=============================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Ejercicios de algebra lineal
### Germán Martínez Maldonado 


## Ejercicio 1

* PROVEEDOR (**CODPRO**, NOMPRO, STATUS, CIUDAD)
* PIEZA (**CODPIE**, NOMPIE, COLOR, PESO, CIUDAD)
* PROYECTO (**CODPJ**, NOMPJ, CIUDAD)
* VENTAS (**CODPRO, CODPIE, CODPJ**, CANTIDAD, FECHA)

### a) Encontrar los códigos de los proveedores que suministran alguna pieza a J1.

Π CODPRO (σ CODPJ=J1 (VENTAS))

### b) Encontrar los suministros cuya cantidad supere las 100 unidades.

Π CODPRO,CODPIE,CODPJ (σ CANTIDAD>100 (VENTAS))

### c) Encontrar los nombres de proveedores, piezas y proyectos que se encuentren en la misma ciudad.

Π PROVEEDOR.NOMBRE,PIEZA.NOMBRE,PROYECTO.NOMBRE (σ PROVEEDOR.CIUDAD=PIEZA.CIUDAD ^ PROVEEDOR.CIUDAD=PROYECTO.CIUDAD ^ PIEZA.CIUDAD=PROYECTO.CIUDAD (PROVEEDOR ⋈ PIEZA ⋈ PROYECTO ⋈ VENTAS))

### d) Encontrar los nombres de las piezas suministradas por los proveedores de Londres.

Π NOMPIE (PIEZA ⋈ (Π CODPIE (VENTAS) - Π CODPIE (VENTAS ⋈ σ CIUDAD<>LONDRES (PROVEEDOR))))

### e) Encontrar todas las parejas de ciudades tales que la primera sea la de un proveedor y la segunda la de un proyecto entre los cuales haya algún suministro.

Π PROVEEDOR.CIUDAD,PROYECTO.CIUDAD (PROVEEDOR ⋈ PROYECTO ⋈ VENTAS)

### f) Encontrar los códigos de las piezas suministradas a algún proyecto por un proveedor que se encuentre en la misma ciudad que el proyecto.

Π CODPIE (σ PROVEEDOR.CIUDAD=PROYECTO.CIUDAD (PROVEEDOR ⋈ PROYECTO ⋈ VENTAS))

### g) Encontrar los códigos de los proyectos que tienen al menos un proveedor que no se encuentra en su misma ciudad.

Π CODPJ (σ PROVEEDOR.CIUDAD<>PROYECTO.CIUDAD (PROVEEDOR ⋈ PROYECTO ⋈ VENTAS))

### h) Mostrar todas las ciudades de donde proveden piezas y donde hay proyectos.

Π PROVEEDOR.CIUDAD (PROVEEDOR ⋈ (Π CODPRO (VENTAS) - Π CODPRO (σ PIEZA.CIUDAD<>PROYECTO.CIUDAD (PIEZA ⋈ PROYECTO ⋈ VENTAS))))

### i) Mostrar todas las ciudades de los proveedores en las que no se fabriquen piezas.

Π PROVEEDOR.CIUDAD (PROVEEDOR - Π PROVEEDOR.* (σ PROVEEDOR.CIUDAD=PIEZA.CIUDAD (PROVEEDOR ⋈ PIEZA ⋈ VENTAS))))

### j) Mostrar todas las ciudades de los proveedores en las que además se fabriquen piezas.

Π PROVEEDOR.CIUDAD (PROVEEDOR - Π PROVEEDOR.* (σ PROVEEDOR.CIUDAD<>PIEZA.CIUDAD (PROVEEDOR ⋈ PIEZA ⋈ VENTAS))))

### k) Encontrar los códigos de los proyectos que usan una pieza que vende S1.

Π CODPJ (σ CODPRO=S1 (VENTAS))

### l) Encontrar la cantidad más pequeña enviada en algún suministro.

ρ(VENTAS)=VEN
Π VENTAS.CANTIDAD (VENTAS - Π VENTAS.* (σ VENTAS.CANTIDAD > VEN.CANTIDAD (VENTAS x VEN)))

### m) Encontrar los códigos de los proyectos que no utilizan una pieza roja suministrada por un proveedor de Londres.

Π CODPJ (VENTAS) - Π CODPJ (VENTAS ⋈ σ COLOR=ROJO (PIEZA) ⋈ σ CIUDAD<>LONDRES (PROVEEDOR))

### n) Encontrar los códigos de los proyectos que tienen como único proveedor a S1.

Π CODPJ (VENTAS) - Π CODPJ (VENTAS ⋈ σ CODPRO<>S1 (PROVEEDOR))

### ñ) Encontrar los códigos de las piezas suministradas a todos los proyectos de Paris.

Π CODPIE,CODPJ (VENTAS) ÷ Π CODPJ (σ CIUDAD=PARIS (PROYECTO))

### o) Encontrar los códigos de los proveedores que venden la misma pieza a todos los proyectos.

Π CODPRO (VENTAS ⋈ Π CODPIE,CODPJ (VENTAS) ÷ Π CODPJ(PROYECTO)))

### p) Encontrar lod códigos de los proyectos a los que S1 suministra todas las piezas existentes.

Π CODPJ,CODPIE (VENTAS) ÷ Π CODPIE (VENTAS ⋈ σ CODPRO=S1 (PROVEEDOR))


## Ejercicio 2

* LISTA_BODA (**REF#**, DESCRIPCION, PRECIO)
* INVITACIONES (**NOMBRE**, DIRECCION, CIUDAD)
* CONFIRMAN (**NOMBRE**, NUMERO)
* RESERVA_REGALO (**NOMBRE**, REF#, FECHA)

### a) Encontrar los regalos (descripcion) que no han sido reservadas.

Π DESCRIPCION (LISTA_BODA - Π LISTA_BODA.* (LISTA_BODA ⋈ RESERVA))

### b) Encontrar la dirección de los invitados que confirman la asistencia de más de dos personas.

Π DIRECCION (σ NUMERO>2 (INVITACIONES ⋈ CONFIRMAN))

### c) Encontrar el nombre y la referencia del regalo más caro ya reservado.

ρ(LISTA_BODA)=LISTA
Π RESERVA_REGALO.NOMBRE,RESERVA_REGALO.REF# (RESERVA_REGALO ⋈ (Π REF# (LISTA_BODA) - Π LISTA_BODA.REF# (σ LISTA_BODA.PRECIO < LISTA.PRECIO ( (LISTA_BODA ⋈ RESERVA_REGALO) x (LISTA ⋈ RESERVA_REGALO)))))


## Ejercicio 3

* HOMBRES (**NomH**, EDAD)
* MUJERES (**NomM**, EDAD)
* HSimM (**NomH, NomM**)
* MSimH (**NomM, NomH**)
* MATRIM (**NomH, NomM**)

### a) Hallar las parejas de hombres y mujeres que se caen mutuamente simpáticos, con edades entre 20 y 30 años y que no estén casados entre sí.

Π HOMBRES.NomH,MUJERES.NomM (σ HOMBRES.EDAD>20 ^ HOMBRES.EDAD<30 ^ MUJERES.EDAD>20 ^ MUJERES.EDAD<30 (HOMBRES ⋈ MUJERES ⋈ HSimM ⋈  MSimH)) - Π NomH,NomM (MATRIM)

### b) Hallar las mujeres casadas a las que no cae simpático su marido.

Π NomM (MATRIM) - Π NomM (HSimM)

### c) Hallar los hombres a los que no les cae simpática ninguna mujers.

Π NomH (HOMBRES) - Π NomH (MSimH)

### d) Hallar las mujeres casadas a las que no les cae simpático ningún hombre casado.

Π NomM (MATRIM) - Π NomM (HSimM ⋈ MATRIM)


## Ejercicio 4

* CONDUCTOR (**DNI**, NOMBRE, DIREC, PROV)
* VEHICULO (**MATRICULA**, CARGA_MAX, FECHA_COMPRA)
* RUTA (**RUTA#**, CIUDAD_SAL, CIUDAD_LLEG, KM)
* VIAJE (**VIAJE#**, DNI, MATRICULA)
* PROG_VIAJE (**VIAJE#, RUTA#, DIA_SEM, HORA_SAL, HORA_LLEG)

### a) Encontrar entre qué dos ciudades se realiza el viaje más largo.

ρ(RUTA)=R
Π RUTA.CIUDAD_SAL,RUTA.CIUDAD_LLEG (RUTA - Π RUTA.* (σ RUTA.KM < R.KM (RUTA x R)))

### b) Listar los nombres de los conductores que hayan llevado todos los camiones de la empresa.

Π CONDUCTOR.NOMBRE (CONDUCTOR ⋈ (Π DNI,MATRICULA (CONDUCTOR ⋈ VIAJE) ÷ Π MATRICULA (VEHICULO)))

### c) Encontrar que días de la semana se hacen viajes entre Granada y Sevilla por la mañana (antes de las 13h).

Π DIA_SEM (σ CIUDAD_SAL=GRANADA ^ CIUDAD_LLEG=SEVILLA (RUTA) ⋈ σ HORA_SAL<13 (PROG_VIAJE))

### d) Encontrar las rutas que se hacen todos los días de la semana, suponiendo que hay viajes todos los días.

Π RUTA#,DIA_SEM (PROG_VIAJE) ÷ Π DIA_SEM (PROG_VIAJE)


## Ejercicio 5

* REPRESENTANTE (**DNI**, NOMBRE, DIREC, PROVINCIA)
* ZONA_REP (**DNI, COD_ZONA**, POBLACION, PROVINCIA)
* PEDIDOS (**DNI, COD_ART**, CANTIDAD, POBLACION)
* ARTICULO (**COD_ART**, NOMBRE, COLOR, PROV_FAB)

### a) Listar las provincias que son visitadas por todos los representantes.

Π ZONA_REP.PROVINCIA (ZONA_REP ⋈ (Π COD_ZONA,DNI (ZONA_REP) ÷ Π DNI (REPRESENTANTE)))

### b) Encontrar los representantes que venden fuera de su provincia artículos fabricados en su provincia.

Π DNI (σ REPRESENTANTE.PROVINCIA<>ZONA_REP.PROVINCIA (REPRESENTANTE ⋈ ZONA_REP)) - Π DNI (σ REPRESENTANTE.PROVINCIA<>ARTICULO.PROV_FAB (REPRESENTANTE ⋈ PEDIDOS ⋈ ARTICULO))

### c) Obtener las poblaciones de Granada que hayan superado los 50.000 euros de facturación y quién realizó el pedido.

Π ZONA_REP.POBLACION,ZONA_REP.DNI (σ PROVINCIA=GRANADA (ZONA_REP) ⋈ Π POBLACION (σ CANTIDAD>50000 (PEDIDOS)))

### d) Mostrar las zonas que incluyen a una sola población.

ρ(ZONA_REP)=ZONA
Π ZONA_REP.COD_ZONA (ZONA_REP - Π ZONA_REP.* (σ ZONA_REP.POBLACION<>ZONA.POBLACION (ZONA_REP x ZONA)))

### e) Encontrar el código del artículo vendido en mayor cantidad

ρ(PEDIDOS)=P
Π PEDIDOS.COD_ART (PEDIDO - Π PEDIDO.* (σ PEDIDO.CANTIDAD<P.CANTIDAD (PEDIDO x P)))


## Ejercicio 6

* INSCRIPCIONES (**INS#**, NOMBRE, PROCEDENCIA)
* SESIONES (**SES#**, TITULO, COORD#)
* ARTICULOS (**ART#**, TITULO)
* PROGRAMAS (**SES#, ART#**, FECHA, HORA_INICIO, HORA_FIN, SALA, PONENTE#)

### a) Mostrar los nombres de los ponentes que coordinan su propia sesión.

Π INSCRIPCIONES.NOMBRE (σ INS#=PONENTE# (INSCRIPCIONES ⋈ (σ COORD#=PONENTE# (SESIONES ⋈ PROGRAMAS))))

### b) Seleccionar los coordinadores que coordinan una única sesión.

ρ(SESIONES)=S
Π SESIONES.COORD# (SESIONES - Π SESIONES.* (σ SESIONES.COORD#<>S.COORD# (SESIONES x S)))

### c) Mostrar el título de los artículos que se exponen en primer y último lugar.

ρ(PROGRAMAS)=P
Π TITULO (ARTICULO ⋈ (Π PROGRAMA.ART# (PROGRAMA - Π PROGRAMA.* (σ PROGRAMA.HORA_INICIO>P.HORA_INICIO (PROGRAMA x P)))) ⋈ (Π PROGRAMA.ART# (PROGRAMA - Π PROGRAMA.* (σ PROGRAMA.HORA_FIN<P.HORA_FIN (PROGRAMA x P)))))
