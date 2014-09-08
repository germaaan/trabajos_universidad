select codpj,codpro,count(*) from ventas
where ventas.fecha between to_date('01/01/2012') and to_date('31/12/2012')
group by codpj,codpro
having codpj in (select codpj from ventas ven where ven.fecha between
to_date('01/01/2011') and to_date('31/12/2011'))
order by codpj,codpro
/
select nompie,avg(cantidad) from ventas,pieza where ventas.codpie=pieza.codpie
group by nompie
/
select nompro,avg(cantidad) from ventas,proveedor where ventas.codpro=proveedor.codpro
and codpie='P1' group by nompro
/
select nompj,nompie,sum(cantidad) from proyecto,pieza,ventas
where ventas.codpj = proyecto.codpj and ventas.codpie = pieza.codpie
group by nompj,nompie order by nompj
/
select codpro,nompj,avg(cantidad)
from ventas, proyecto
where ventas.codpj=proyecto.codpj
group by ventas.codpj,nompj
/
