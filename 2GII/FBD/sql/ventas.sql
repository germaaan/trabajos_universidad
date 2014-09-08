create table ventas(
codpro constraint codpro_clave_externa_proveedor references proveedor(codpro),
codpie constraint codpie_clave_externa_pieza references pieza(codpie),
codpj constraint codpj_clave_externa_proyecto references proyecto(codpj),
cantidad number(4),
constraint clave_primaria primary key (codpro,codpie,codpj));
alter table ventas add(fecha DATE);
/