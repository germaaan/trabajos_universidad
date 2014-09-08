Fundamentos de Bases de Datos
=============================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Ejercicios de autocomprobación del tema 1: Introducción y definiciones iniciales
### Germán Martínez Maldonado 

**1. ¿Cuáles son las principales diferencias entre un sistema de procesamiento de archivos y un sistema de bases de datos?**

En un sistema de procesamiento de archivos es posible que los archivos con la información se almacenen con diferentes estructuras, lo que puede dar problemas al querer usar la información desde diferentes sistemas, como en un sistema de base de datos los usuarios no tienen la opción de trabajar a tan bajo nivel, esta posible inconveniencia se evita, además de que si el diseño es correcto, se evitan también que se produzcan redundancias e inconsistencias en los datos.

**2. Características más importantes en un sistema de base de datos. Propiedades más deseables. Explicar a tu juicio cual es la propiedad más importante.**

Las principales características en un sistema de base de datos son en primer lugar el mayor control para evitar que se produzcan redundancias e inconsistencias de datos, el mayor control sobre la seguridad al poder especificar para cada acción los usuarios que  tienen permiso para realizarla, además de poder realizar un acceso concurrente eficiente. Personalmente considero que el poder asegurarse de que la información tenga consistencia y evite redundancias es la propiedad más importante, porque por muy bueno que sea el control de acceso o la seguridad, si los datos son erróneos, nada de este importa para nuestra base de datos.

**3. Hemos conocido cuales son las ventajas de utilizar un sistema de bases de datos, podrías encontrar algún inconveniente.**

La única desventaja apreciable puede ser que según va creciendo el volumen de datos, aumente en gran medida la complejidad de la base de datos, y las personas que trabajen con ellas, deban conocer con gran nivel de detalle la funcionalidad de la misma.

**4. Explicar la diferencia entre independencia física e independencia lógica.**

La diferencia entre independencia física e independencia lógica la encontramos en que, la independencia física busca que si cambiamos la estructura física de la base de datos, este cambio no tenga que repercutir en un cambio en el esquema lógico; mientras que la independencia lógica busca que si la estructura lógica de la base datos cambia, este cambio no repercuta en como acceden externamente otros programas a la información.

**5. Definir brevemente:**

* Base de datos: es un banco de información almacenada a la que puede acceder todo usuario que disponga de los permisos requeridos.
* DBMS: (DataBase Management System, Sistema de Gestión de Base de Datos) es un conjunto de software destinado a facilitar las acciones que un usuario puede realizar sobre la información de una base de datos (crear, consultar, alterar y eliminar).
* DBA: (DataBase Administrator, Administrador de la Base de Datos) es el encargado de gestionar todos los elementos del SGBD para que se pueda representar una base de datos de forma íntegra, además de asegurarse de que esta esté siempre disponible de forma segura.
* Acceso concurrente: uno de los objetivos de un SGDB es que se pueda realizar un acceso concurrente a la información de la base de datos, es decir, que se si varios usuarios acceden al mismo tiempo a la misma información, esto no provoque inconsistencias en la misma.
* Visión de usuario: será la representación de la información contenida en la base de datos de la forma en que será accedida por el usuario.

**6. Explicar brevemente los conceptos de:"**

**Integridad, fiabilidad y seguridad en una base de datos.**

* La integridad en una base de datos significa que esa misma base de datos debe corresponderse en todo momento  con la realidad que representa.
* La fiabilidad se refiere a que es necesario contar con mecanismos que eviten que la información se pierda o se corrompa.
* La seguridad nos asegura que la información contenida no será accedida por alguien que no tenga permiso para verla.

**Ordenarlos por importancia explicando los criterios utilizados.**

Considero que el concepto más importante es el de la fiabilidad, porque una base de datos es información, si esta información se pierde, se pierde la base de datos. El siguiente sería la integridad, porque si la información no representada no es correcta, la base de datos no tiene razón de ser, por lo que siempre se debe cumplir. Por último, la seguridad, en función de lo sensible que sea la información a almacenar, la importancia de la seguridad puede aumentar o disminuir, pero por muy importante que sea este punto, si los otros dos no se cumplen, este pasa a ser inservible.

**¿En qué etapa de la vida de una base de datos se deben tener en cuenta unos y otros?**

La integridad se debe tener en cuenta en la etapa de diseño conceptual, porque es cuando se está definiendo la estructura de lo que será la base de datos. La fiabilidad y la seguridad se tendrán en cuenta en la etapa de diseño lógico, ya que en función a la información a representar se tomarán en cuenta los mecanismos a usar para cubrir estas necesidades.

**¿Cómo se mantienen en una base de datos?**

La integridad se mantendrá mediante mecanismos de mantenimiento para que los datos no tengan fallos lógicos, la fiabilidad mediante mecanismos de manteniendo de recuperación y protección de los datos, y la seguridad mediante mecanismos de gestión de usuarios y de protección de información.

**7. Definir y sit uar históricamente los siguientes términos:**

* COBOL: (COmmon Business-Oriented Language, Lenguaje Común Orientado a Negocios), lenguaje de programación desarrollado en 1960 por el grupo CODASYL.
* Acceso secuencial: consiste  en acceder a un conjunto de  elementos mediante un orden predeterminado.
* CODASYL: (Conference On DAta SYstems Languages, Conferencia Sobre Lenguajes de Sistemas de Datos), comunidad formada en 1959 con el objetivo de desarrollar un lenguaje de programación estándar para una amplia variedad de ordenadores.
* DBTG: (Data Base Task Group, Grupo de Trabajo de Base de Datos), grupo que definió el modelo en red de base de datos en 1969.
* SQL: (Structured Query Language, Lenguaje de Consulta Estructurado), lenguaje declarativo de acceso a bases de datos relacionales que nos permite realizar operaciones sobre la misma. Apareció en 1974.
* Ingres: SGBD relacional SQL de código abierto destinado a grandes aplicaciones comerciales que apareció en la década de 1970.
* Cálculo relacional: lenguaje de consulta de base de datos en el que describimos la respuesta deseada, pero sin especificar como obtenerla. Originó los lenguajes de acceso a base de datos declarativos (como es SQL).
* Consultas recursivas: tipo de consultas usadas para modelos con relaciones jerárquicas.
* Modelo semántico: forma de modelar una base de datos en su manera conceptual, lo que será la descripción general de la base de datos.
* Base de datos orientada a objetos: base de datos en la que la información se representa como objetos del tipo usados en la programación orientada a objetos.
* Base de Datos Multimedia: base de datos en la que la información se representa como una combinación de textos, gráficos, animaciones, música, voz y video.
* Base de datos XML: base de datos que definen un modelo lógico de gestión mediante archivos XML.
* Base de datos móvil: base de datos distribuida que gestiona una base de datos central y diversas bases de datos móviles que interaccionan de forma bidimensional.
* Minería de Datos: consiste en realizar una extracción selectiva de datos para obtener la información que, a simple a vista, está oculta en ella.
