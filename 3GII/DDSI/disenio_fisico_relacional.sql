-- Borrado de tablas

drop table tarifa;
drop table empleado;
drop table cliente;
drop table movimiento;
drop table clase;
drop table nomina;
drop table ensal;
drop table cliente_elige_clase;


-- Creación de tablas

create table empleado(
DNI	CHAR(9) primary key,
NOMBRE	VARCHAR(30),
APELLIDOS	VARCHAR(50),
TLF	NUMBER(9),
EMAIL	VARCHAR(30),
FECHA	DATE,
ADMINISTRADOR	CHAR(1) check (administrador in('S','s','N','n')),
id_creador char(9) references empleado(dni)
);

create table clase(
  id_c number(5) primary key,
  n_alumnos number(2),
  id_profesor references empleado(dni),
  fecha date,
  hora number,
  descripcion varchar(300),
  id_creador char(9) references empleado(dni)
);

create table tarifa(
  id_t number(5) primary key,
  turno varchar(8) check(turno in ('mañana', 'tarde', 'total')),
  precio number,
  descripcion varchar(300),
  id_creador char(9) references empleado(dni)
);

create table cliente(
  dni char(9) primary key,
  nombre varchar(30),
  apellidos varchar(50),
  --foto,
  tar references tarifa(id_t),
  tlf number(9),
  email varchar(30),
  id_creador char(9) references empleado(dni)
);

create table cliente_elige_clase(
  id_c  references clase(id_c),
  dni_c  references cliente(dni),
  primary key(id_c,dni_c)
);

create table EnSal(
dni_c references cliente(dni),
fecha date,
hora number,
tipo char(7) check(tipo in ('entrada','salida')),
primary key(dni_c,fecha,hora)
);

create table nomina(
  dni references empleado(dni),
  sueldo number,
  fecha date,
  ncc number,
  administrador references empleado(dni)
);

create table movimiento(
  id_m number primary key,
  fecha date,
  concepto varchar(300),
  cantidad number,
  precio_unidad number,
  tipo char(10) check(tipo in ('ingreso','reintegro','pago','cobro')),
  id_admin char(9) references empleado(dni)
);


-- Introducción de valores en las tablas

insert into cliente_elige_clase (id_c,dni_c)
values(1,'45345645L');
insert into cliente_elige_clase (id_c,dni_c)
values(2,'11111111E');
insert into cliente_elige_clase (id_c,dni_c)
values(3,'23412412R');

insert into empleado(dni,nombre,apellidos,tlf,email,fecha, administrador,id_creador)
values('73737373F','PEPE','PERES_PEREZ','958585858','pepe@ugr.es','10/10/10', 'S','73737373F');
insert into empleado(dni,nombre,apellidos,tlf,email,fecha, administrador,id_creador)
values('19283918F','JUAN','RAMIREZ','958234241','juan@ugr.es', '12/9/08', 'N','73737373F');
insert into empleado(dni,nombre,apellidos,tlf,email,fecha, administrador,id_creador)
values('92839182F','LURDES','MAXIMA DIVERSION','958938392','lurdes@ugr.es', '7/10/09', 'N','73737373F');
insert into empleado(dni,nombre,apellidos,tlf,email,fecha, administrador,id_creador)
values('23412412R','MARIA','JIMENEZ','681928392','maria@ugr.es','1/1/1', 'S','73737373F');

insert into clase(id_c, n_alumnos, id_profesor, fecha, hora, descripcion, id_creador)
values(1,20,'73737373F','1/2/2013', 1800, 'Estiramientos', '73737373F');
insert into clase(id_c, n_alumnos, id_profesor, fecha, hora, descripcion, id_creador)
values(2,20,'73737373F','1/12/2012', 1200, 'Movimientos funcionales', '73737373F');
insert into clase(id_c, n_alumnos, id_profesor, fecha, hora, descripcion, id_creador)
values(3,20,'73737373F','1/2/2013', 1400, 'Alterofilia', '73737373F');
insert into clase(id_c, n_alumnos, id_profesor, fecha, hora, descripcion, id_creador)
values(4,25,'73737373F','1/3/2013', 1900, 'Aer—bica', '73737373F');

insert into tarifa(id_t, turno, precio, descripcion, id_creador)
values(1,'mañana', 30, 'Turno para ir solo por la mañana','73737373F');
insert into tarifa(id_t, turno, precio, descripcion, id_creador)
values(2,'tarde', 35, 'Turno para ir solo por la tarde','73737373F');
insert into tarifa(id_t, turno, precio, descripcion, id_creador)
values(3,'total', 45, 'Todo el dia','73737373F');

insert into cliente (dni, nombre, apellidos, tar, tlf, email, id_creador)
values('45345645L','Elutardo','DelCallao', 1, 619223344,'EluDC@callao.org','73737373F');
insert into cliente (dni, nombre, apellidos, tar, tlf, email, id_creador)
values('11111111E','Ruben','Sanchez', 2, 689381232,'Ruben@gmail.com','73737373F');
insert into cliente (dni, nombre, apellidos, tar, tlf, email, id_creador)
values('23412412R','German','lerelele', 3, 958302102,'german@ugr.es','73737373F');

insert into EnSal (dni_c, fecha, hora, tipo)
values('11111111E','23/1/2013', 1100, 'entrada');
insert into EnSal (dni_c, fecha, hora, tipo)
values('45345645L','23/1/2013', 1210, 'entrada');
insert into EnSal (dni_c, fecha, hora, tipo)
values('23412412R','23/1/2013', 1210, 'entrada');
insert into EnSal (dni_c, fecha, hora, tipo)
values('11111111E','23/1/2013', 1200, 'salida');

insert into nomina (dni, sueldo, fecha,  ncc, administrador)
values('73737373F',2000, '01/01/2012', 20020303940104, '73737373F');
insert into nomina (dni, sueldo, fecha,  ncc, administrador)
values('19283918F',1200, '01/02/2012', 30192039102932, '73737373F');
insert into nomina (dni, sueldo, fecha,  ncc, administrador)
values('92839182F',1800, '10/04/2012', 30020703940104, '73737373F');
insert into nomina (dni, sueldo, fecha,  ncc, administrador)
values('23412412R',2000, '11/03/2012', 42020893720423, '73737373F');

insert into movimiento (id_m, fecha, concepto, cantidad, precio_unidad, tipo, id_admin)
values(1, '1/1/2013','material-Pesas', 3, 20, 'pago','73737373F');
insert into movimiento (id_m, fecha, concepto, cantidad, precio_unidad, tipo, id_admin)
values(2, '1/2/2012','Complemento vitam’nico', 5, 12, 'pago','73737373F');
insert into movimiento (id_m, fecha, concepto, cantidad, precio_unidad, tipo, id_admin)
values(3, '6/12/2012','Gomas elasticas', 15, 3, 'pago','73737373F');
insert into movimiento (id_m, fecha, concepto, cantidad, precio_unidad, tipo, id_admin)
values(4, '6/11/2012','Barras de proteinas', 20, 8, 'pago','73737373F');


-- Selección de tablas

select * from tarifa;
select * from empleado;
select * from cliente;
select * from movimiento;
select * from clase;
select * from nomina;
select * from ensal;
select * from cliente_elige_clase;
