Ingeniería de Servidores
=========================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Ejercicios Microprocesadores
### Germán Martínez Maldonado


## Bibliografía (Todos los enlaces consultados a fecha 23 de octubre de 2012):

* *3rd Generation Intel® Core™ i3 Processors*: [http://ark.intel.com/es-es/products/family/65503](http://ark.intel.com/es-es/products/family/65503)

* *3rd Generation Intel® Core™ i5 Processors*: [http://ark.intel.com/es-es/products/family/65504](http://ark.intel.com/es-es/products/family/65504)

* *3rd Generation Intel® Core™ i7 Processors*: [http://ark.intel.com/es-es/products/family/65506](http://ark.intel.com/es-es/products/family/65506)

* *Intel® Xeon® Processors E3 Family*: [http://ark.intel.com/es-es/products/family/59137](http://ark.intel.com/es-es/products/family/59137)

* *Intel® Xeon® Processors E5 Family*: [http://ark.intel.com/es-es/products/family/59138](http://ark.intel.com/es-es/products/family/59138)

* *Intel® Xeon® Processors E7 Family*: [http://ark.intel.com/es-es/products/family/59139](http://ark.intel.com/es-es/products/family/59139)

* *ARK | Comparar productos Intel®*: [http://ark.intel.com/es-es/compare/66168,65704,70846,65722,64606,53580](http://ark.intel.com/es-es/compare/66168,65704,70846,65722,64606,53580)

* *¿Qué son FSB, Hypertransport, DMI, QPI, y FDI? (Autor: Ángel Luis Sánchez Iglesias)*: [http://computadoras.about.com/od/conoce-procesadores/a/Que-Son-Fsb-Hypertransport-Dmi-Qpi-Y-Fdi.htm](http://computadoras.about.com/od/conoce-procesadores/a/Que-Son-Fsb-Hypertransport-Dmi-Qpi-Y-Fdi.htm)

* *Intel Processor Comparison*: [http://www.intel.com/content/www/us/en/processor-comparison/compare-intel-processors.html?select=server](http://www.intel.com/content/www/us/en/processor-comparison/compare-intel-processors.html?select=server)

* *Tecnología AMD HyperTransport™*: [http://www.amd.com/la/products/technologies/hypertransport-technology/Pages/hypertransport-technology.aspx](http://www.amd.com/la/products/technologies/hypertransport-technology/Pages/hypertransport-technology.aspx)

* *Características del procesador AMD Opteron™ Six-Core*: [http://www.amd.com/es/products/server/processors/six-core-opteron/Pages/six-core-opteron-key-architectural-features.aspx](http://www.amd.com/es/products/server/processors/six-core-opteron/Pages/six-core-opteron-key-architectural-features.aspx)


## Intel

### Ejercicio 1: Compare varios modelos de la familia Xeon con los Core y comente cuáles son las principales diferencias.

Vamos resaltar las principales diferencias entre ambas familias de procesadores, nos basaremos en las especificaciones de una tabla realizada mediante el comparador de productor de la propia página de Intel. Los procesadores a comparar son:

* Intel Core i3-3240T Processor
* Intel Core i5-3610ME Processor
* Intel Core i7-3840QM Processor
* Intel Xeon Processor E3-1290V2
* Intel Xeon Processor E5-4650L
* Intel Xeon Processor E7-8870

Para que la comparación resulte equilibrada y actual, todos los procesadores a comparar han sido lanzados entre el segundo y tercer trimestre de 2012, a excepción del Intel Xeon Processor E7-8870 que fue lanzado en el segundo trimestre de 2011.

|                                              |      Core i3-3240T      |      Core i5-3610ME     |      Core i7-3840QM     | Xeon E3-1290V2 |      Xeon E5-4650L      |                Xeon E7-8870               |
|:--------------------------------------------:|:-----------------------:|:-----------------------:|:-----------------------:|:--------------:|:-----------------------:|:-----------------------------------------:|
|                    Núcleos                   |            2            |            2            |            4            |        4       |            8            |                     10                    |
|                  Nº de hilos                 |            4            |            4            |            8            |        8       |            16           |                     20                    |
|              Velocidad de reloj              |         2.9 GHz         |         2.7 GHz         |         2.8 GHz         |     3.7 GHz    |         2.6 GHz         |                  2.4 GHz                  |
|            Frecuencia turbo máxima           |                         |         3.3 GHz         |         3.8 GHz         |     4.1 GHz    |         3.1 GHz         |                  2.8 GHz                  |
|                     Caché                    |           3 MB          |           3 MB          |           8 MB          |      8 MB      |          20 MB          |                   30 MB                   |
|                  Tipo de bus                 |           DMI           |           DMI           |           DMI           |       DMI      |           QPI           |                    QPI                    |
| TDP (máxima potencia extraíble en ejecución) |           35 W          |           35 W          |           45 W          |      87 W      |          115 W          |                   130 W                   |
|           Tamaño de memoria máximo           |          32 GB          |          16 GB          |          32 GB          |      32 GB     |         1500 GB         |                  4096 GB                  |
|               Tipos de memoria               |      DDR3-1333/1600     |    DDR3/3L 1333/1600    |   DDR3/L/RS 1333/1600   | DDR3-1333/1600 | DDR3-800/1066/1333/1600 | DDR-3 800/978/1066/1333 (Máximo 1066 MHz) |
|           Nº de canales de memoria           |            2            |            2            |            2            |        2       |            4            |                     4                     |
|       Ancho de banda máximo de memoria       |        25,6 GB/s        |        25,6 GB/s        |        25,6 GB/s        |    25,6 GB/s   |        51,2 GB/s        |                                           |
|              Modelo de gráficos              | Intel® HD Graphics 2500 | Intel® HD Graphics 4000 | Intel® HD Graphics 4000 |                |                         |                                           |
|           Nº de puertos PCI Express          |                         |            1            |            1            |                |            40           |                                           |
|             Número máximo de CPUs            |            1            |            1            |            1            |        1       |            4            |                     8                     |

Aunque los procesadores Core están destinados al uso general y los Xeon a servidores, vemos como las características de un Core de alta gama son bastante similares a la de un Xeon de gama baja.

Vemos como los 2 procesadores Xeon de gama más alta tienen una cantidad de memoria caché mayor, más tamaño de memoria máximo (diferencia elevada), máxima potencia extraíble en ejecución más alta, mayor número de canales de memoria, mayor número de puertos PCI-E y mayor cantidad de procesadores instalables en una misma máquina. Todo esto nos indica precisamente que estos servidores están destinados a una carga de trabajo mucho mayor, lo que requerirá unos anchos de banda más altos, uno de los motivos por el que el tipo de bus usado es QPI, en lugar de DMI.

En comparación vemos, como todos los procesadores Core comparados si integran un procesador gráfico, mientras que ninguno de los Xeon no los integra, esto se debe a que en el entorno de servidores es posible que no sean necesarios procesar interfaces gráficos, pero en un entorno más general con cualquier sistema operativo doméstico actual será lo contrario, siendo necesario o disponer de un procesador gráfico integrado o de una tarjeta gráfica.


### Ejercicio 2: Dentro de la familia Xeon, compare varios modelos y comente las diferencias.

Vamos a comparar 4 procesadores Xeon de las categorías E3 Family, 5000 Sequence, E5 Family y E6 Family, siendo los procesadores específicos a comparar de lo más actuales de cada categoría (lanzados entre 2011 y 2012):

* Intel Xeon Processor E3-1290V2
* Intel Xeon Processor X5690
* Intel Xeon Processor E5-4650L
* Intel Xeon Processor E7-8870

|                                              | Xeon E3-1290V2 |     Xeon X5690     |      Xeon E5-4650L      |                Xeon E7-8870               |
|:--------------------------------------------:|:--------------:|:------------------:|:-----------------------:|:-----------------------------------------:|
|                    Núcleos                   |        4       |          6         |            8            |                     10                    |
|                  Nº de hilos                 |        8       |         12         |            16           |                     20                    |
|              Velocidad de reloj              |     3.7 GHz    |      3.46 GHz      |         2.6 GHz         |                  2.4 GHz                  |
|            Frecuencia turbo máxima           |     4.1 GHz    |      3.73 GHz      |         3.1 GHz         |                  2.8 GHz                  |
|                     Caché                    |      8 MB      |        12 MB       |          20 MB          |                   30 MB                   |
|                  Tipo de bus                 |       DMI      |         QPI        |           QPI           |                    QPI                    |
|                Bus de sistema                |     5 GT/s     |      6.4 GT/s      |          8 GT/s         |                  6.4 GT/s                 |
| TDP (máxima potencia extraíble en ejecución) |      87 W      |        130 W       |          115 W          |                   130 W                   |
|           Tamaño de memoria máximo           |      32 GB     |       288 GB       |         1500 GB         |                  4096 GB                  |
|               Tipos de memoria               | DDR3-1333/1600 | DDR3-800/1333/1600 | DDR3-800/1066/1333/1600 | DDR-3 800/978/1066/1333 (Máximo 1066 MHz) |
|           Nº de canales de memoria           |        2       |          3         |            4            |                     4                     |
|       Ancho de banda máximo de memoria       |    25,6 GB/s   |       32 GB/s      |        51,2 GB/s        |                                           |
|             Número máximo de CPUs            |        1       |          2         |            4            |                     8                     |

Analizando los datos, vemos que las características generales van aumentando en un procesador con respecto de su anterior (número de núcleos, caché, tamaño máximo de memoria, número máximo de CPUs…), por lo que podemos concluir que el servidor de gama más baja es el perteneciente a la familia E3, mientras que el E7 será de la gama más alta. Además esto también lo podremos confirmar viendo la gran diferencia entre cantidad de memoria máxima admitida (E3 = 32 GB, E7 = 4096) o cantidad máxima de CPUs admitida (E3 = 1, E7 = 8), que hacen la idea de que un procesador está orientado, aún en el mismo ámbito, a tener una carga de trabajo mucho mayor que el otro.


## AMD

### Ejercicio 3: En los Opteron 6200 nos encontramos con las  tecnologías HT3 y HT Assist. Describa brevemente qué aportan.

HT3 son las siglas de la tecnología HyperTransport 3.0, usada por AMD en muchos de sus procesadores. Esta tecnología permite una conexión bidireccional punto a punto entre los circuitos integrados de diferentes tipos de sistemas a una alta velocidad y con una baja latencia, obteniendo como una de las posibles ventajas, que el procesador pueda acceder de forma más rápida a la memoria, lo que nos permite mejorar la escalabilidad respecto a los sistemas actuales.

HT Assist es una función de la tecnología HyperTransport que permitirá al sistema conocer y poder acceder al contenido de la memoria caché de los distintos núcleos del procesador, acelerando las solicitudes, lo que puede aumentar el rendimiento del sistema.
