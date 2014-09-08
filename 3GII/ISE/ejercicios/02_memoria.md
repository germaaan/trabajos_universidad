Ingeniería de Servidores
=========================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Ejercicios Memoria
### Germán Martínez Maldonado


## Bibliografía (Todos los enlaces consultados a fecha 29 de octubre de 2012):

* *Ark | Intel® Xeon® Processor E7-8870 (30M Cache, 2.40 GHz, 6.40 GT/s Intel® QPI)*: [http://ark.intel.com/es-es/products/53580/Intel-Xeon-Processor-E7-8870-30M-Cache-2_40-GHz-6_40-GTs-Intel-QPI](http://ark.intel.com/es-es/products/53580/Intel-Xeon-Processor-E7-8870-30M-Cache-2_40-GHz-6_40-GTs-Intel-QPI)

* *Ark | Intel® Xeon® Processor E5-4650l (20M Cache, 2.60 GHz, 8.00 GT/s Intel® QPI)*: [http://ark.intel.com/es-es/products/64606/Intel-Xeon-Processor-E5-4650L-20M-Cache-2_60-GHz-8_00-GTs-Intel-QPI](http://ark.intel.com/es-es/products/64606/Intel-Xeon-Processor-E5-4650L-20M-Cache-2_60-GHz-8_00-GTs-Intel-QPI)

* *Procesadores AMD Opteron™ Serie 6200*: [http://www.amd.com/es/products/server/processors/6000-series-platform/6200/Pages/6200-series-processors.aspx#5](http://www.amd.com/es/products/server/processors/6000-series-platform/6200/Pages/6200-series-processors.aspx#5)

* *AMD Processors for Servers and Workstations: AMD Opteron™ Processor*: [http://products.amd.com/en-us/OpteronCPUDetail.aspx?id=790](http://products.amd.com/en-us/OpteronCPUDetail.aspx?id=790)

* *Procesadores AMD Opteron™ Serie 6100*: [http://www.amd.com/es/products/server/processors/6000-series-platform/6100/Pages/6100-series-processors.aspx#5](http://www.amd.com/es/products/server/processors/6000-series-platform/6100/Pages/6100-series-processors.aspx#5)

* *AMD Processors for Servers and Workstations: AMD Opteron™ Processor*: [http://products.amd.com/en-us/OpteronCPUDetail.aspx?id=739](http://products.amd.com/en-us/OpteronCPUDetail.aspx?id=739)

* *IBM Power 795 server specifications*: [http://www-03.ibm.com/systems/power/hardware/795/specs.html](http://www-03.ibm.com/systems/power/hardware/795/specs.html)

* *IBM Power 795 server specifications*: [http://www-03.ibm.com/systems/power/hardware/780/specs.html](http://www-03.ibm.com/systems/power/hardware/780/specs.html)

* *Newegg.com - Kingston ValueRAM 4GB 240-Pin DDR3 SDRAM ECC Unbuffered DDR3 1333 Server Memory Model KVR1333D3E9S/4G*: [http://www.newegg.com/Product/Product.aspx?Item=N82E16820139077](http://www.newegg.com/Product/Product.aspx?Item=N82E16820139077)

* *Newegg.com - Crucial 1GB 240-Pin DDR2 SDRAM ECC Unbuffered DDR2 667 (PC2 5300) Server Memory Model CT12872AA667*: [http://www.newegg.com/Product/Product.aspx?Item=N82E16820146523](http://www.newegg.com/Product/Product.aspx?Item=N82E16820146523)

* *Newegg.com - CORSAIR 2GB 240-Pin DDR3 SDRAM ECC DDR3 1333 (PC3 10600) Server Memory Model CM72DD2G1333 G*: [http://www.newegg.com/Product/Product.aspx?Item=N82E16820145245](http://www.newegg.com/Product/Product.aspx?Item=N82E16820145245)


## Memoria: Caché en servidores

### Ejercicio 1: Conociendo las referencias de la sección de microprocesadores, indique los datos de caché de los últimos modelos de Xeon, Opteron y POWER.

| FABRICANTE |      MODELO     | MEMORIA CACHÉ |
|:----------:|:---------------:|:-------------:|
|    Intel   |   Xeon E7-8870  |     30 MB     |
|    Intel   |  Xeon E5-4650L  |     20 MB     |
|     AMD    | Opteron 6284 SE |     16 MB     |
|     AMD    | Opteron 6180 SE |     12 MB     |
|     IBM    |    POWER 795    | 512 – 2048 MB |
|     IBM    |    POWER 780    | 160 – 1280 MB |


## Memoria: Principal para servidores

### Ejercicio: De las páginas propuestas o de otras que usted considere, seleccione 3 opciones de módulos de RAM de acuerdo a estos objetivos:

* Precio mínimo (en euros)
* Capacidad máxima
* Mínima latencia
* Mayor velocidad del reloj

### Una vez obtenidos los tres módulos, indique si serían válidos para servidores y, de no serlo, indique el porqué.

| FABRICANTE |      MODELO     |  PRECIO MÍNIMO  | CAPACIDAD MÁXIMA | MÍNIMO LATENCIA | MAYOR VELOCIDAD RELOJ |
|:----------:|:---------------:|:---------------:|:----------------:|:---------------:|:---------------------:|
|  Kingston  | KVR1333D3E9S/4G | $27.99 / 21.69€ |       4 GB       |  CL9 / 13.5 ns  |   DDR3 1333/667 MHz   |
|   Crucial  |   CT12872AA667  | $21.99 / 17.04€ |       1 GB       |   CL5 / 15 ns   |    DDR2 667/333 MHz   |
|   Corsair  |  CM72DD2G1333 G | $27.99 / 21.69€ |       2 GB       |  CL9 / 13.5 ns  |   DDR3 1333/667 MHz   |

Todas la memorias mostradas en la tabla, independientemente de las características listadas, que sólo influirían en tener un mayor o menor rendimiento en el servidor, sí serían válidas para servidores, porque todas usan la tecnología ECC para evitar la corrupción de los datos internos.


## Memoria Externa: Ejemplos

### Ejercicio: Lea “[http://www.tomshardware.co.uk/hdd-enterprise-storage-3.5,review-32244.html](http://www.tomshardware.co.uk/hdd-enterprise-storage-3.5,review-32244.html)” y escriba un párrafo con las conclusiones del artículo y otro con una reflexión personal sobre el artículo (p.ej. Es objetivo por..., los experimentos son o no son rigurosos...)

Generalmente es más importante tener menor cantidad y más segura, que mucha y menos segura, pero siempre respetando ciertos márgenes. Con este pensamiento, podemos entender que, independiente del ambiente, lo habitual será que la mejor opción sea optar por un disco duro normal  (no SSD) con un tamaño de 3.5” conectado mediante SATA. SATA sustituyó a IDE porque ambos se basa en bases similares a este, pero eliminando restricciones y aportando nuevas ventajas. Por otro lado tenemos los SAS, que con un caso similar al de SATA-IDE, vendrían a ser los sucesores de los discos SCSI. Aunque teniendo en cuenta los antecedentes de ambos interfaces, lo lógico sería pensar que en entorno empresarial, sería más recomendable usar discos SAS en lugar de SATA, igual que en su momento se usaron SCSI en lugar de IDE, pero después de realizar numerosas pruebas, podremos comprobar que en la práctica, aun existentes, no hay motivos suficiente para asegurar que los discos SAS son más recomendables que los SATA.

La conclusión se puede entender como objetiva, porque se base en los resultados de las pruebas, que son los bastantes rigurosas como para hacerse una idea inicial de la diferencia que puede haber entre las unidades SATA y SAS, además de realizar las mismas pruebas a las unidades tanto en solitario como en RAID, que será la configuración más común para su funcionamiento. De todas formas, ya que los resultados no dan un claro ganador, como bien indican al final del artículo, el resultado puede ser de libre interpretación según criterios o necesidades personales.
