Select ciudad from proyecto;
Select distinct ciudad from proyecto;
Select * from proveedor;
Select codpro, nompro, status, ciudad from proveedor;
Select codpro from proveedor;
Select codpro from ventas where codpj='J1';
Select codpie from pieza where (ciudad='Madrid' and color in ('Rojo','Gris'));
Select codpie from ventas where cantidad between 200 and 300;
Select codpro, nompro from proveedor where ciudad LIKE 'L%';
select codpie from pieza where nompie like '%_ornillo%';
select cantidad/12 from ventas where (cantidad/12)>10;
select codpro, nompro from proveedor where status is not null;
select table_name from user_tables;
select table_name from all_tables where table_name like '%ventas';
(select distinct ciudad from proveedor where status>2) MINUS (select distinct ciudad from pieza where codpie='P1');
(select distinct ciudad from proveedor where status>2) INTERSECT (select distinct ciudad from pieza where codpie in ('P2','P3','P4'));


