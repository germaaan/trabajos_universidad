Fundamentos de Bases de Datos
=============================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Ejercicios de autocomprobación del tema 2: Arquitectura de un Sistema de Bases de Datos
### Germán Martínez Maldonado 

**1. Características más importantes en un sistema de base de datos. Propiedades más deseables. Explicar a tu juicio cual es la propiedad más importante.**

Las principales características en un sistema de base de datos son en primer lugar el mayor control para evitar que se produzcan redundancias e inconsistencias de datos, el mayor control sobre la seguridad al poder especificar para cada acción los usuarios que  tienen permiso para realizarla, además de poder realizar un acceso concurrente eficiente. Personalmente considero que el poder asegurarse de que la información tenga consistencia y evite redundancias es la propiedad más importante, porque por muy bueno que sea el control de acceso o la seguridad, si los datos son erróneos, nada de este importa para nuestra base de datos.

**2. Explicar la relación existente entre los niveles de una base de datos y el concepto de independencia.**

La relación está en que cada nivel especifica un grado de representación de la base de datos, lo que está directamente relacionado con la independencia, por ejemplo, el  nivel interno representa la capa más cercana a la estructura de almacenamiento físico, llevando contenida la independencia física.


**3. Explicar  la  diferencia  entre  esquema  externo  y  aplicaciones  de usuario.**
La diferencia es que en el esquema externo se definen las vistas que los usuarios tendrán de la base de datos, pero el usuario no hará un uso directo de ese esquema, será necesario que se implemente en una aplicación, que si será la que utilice el usuario.

**4. Explica por qué, a tu juicio, no se han desarrollado DDLs a nivel interno.**

Porque debido al acoplamiento entre un lenguaje anfitrión y los lenguajes de datos, no se hace necesario un DDL especifico a nivel interno.

**5. Explica por qué, a tu juicio no se han desarrollado DMLs a nivel externo.**

Por el mismo motivo que no se han desarrollado DDLs a nivel interno, por el acoplamiento existente actualmente entre el lenguaje anfitrión y los lenguajes de datos.

**6. Buscar tres ejemplos de lenguajes de cuarta generación. Indicando sus objetivos o funciones.**

* SQL: su objetivo es el acceso a bases de datos relacionales permitiendo una gran variedad de operaciones.
* PostScript: su objetivo es usar un lenguaje de programación completo para describir una imagen de impresión.
* M (MATLAB): su objetivo es proporcionar un lenguaje de cálculo matemático técnico que nos permita manipular matrices, representar datos y funciones, implementar algoritmos…

**7. Cuál es el enfoque actual del concepto de lenguaje anfitrión. Dar ejemplos de los mismos.**

En la actualidad se tiende a realizar acoplamientos entre un lenguaje anfitrión y el DSL, ya sea usando una API provista por el DGBD, para que el programador pueda acceder a la base de datos desde el código fuente, o también usando una inmersión en el código fuente del lenguaje anfitrión, desarrollando un código fuente hibrido entre lenguaje anfitrión y DSL. Un ejemplo puede ser JDBC de Java, que permite la ejecución de operaciones sobre bases de datos desde un programa realizado en Java, pero sin importar el sistema operativo en el que se ejecutará o la base de datos a la que se accede.

**8. ¿Qué elementos conciernen al nivel interno de una base de datos?**

Un DDL que describa el esquema interno y un DML que permita el acceso el acceso a los datos almacenados en el esquema interno.

**9. ¿Qué cuestiones deben cubrir a tu juicio una buena herramienta de gestión privilegios de usuarios?**

Una buena herramienta de gestión de privilegios de usuarios debe poder ser capaz de permitir realizar distinciones en varios grupos de usuarios con diferentes grados de privilegios, delimitando con la mayor exactitud posible el nivel de acceso permitido para cada uno de los grupos.

**10. Indicar qué elementos deben formar parte del catálogo de una base de datos.**

Todos los elementos que sean necesarios para poder tener una descripción completa de la base de datos.

**11. Explicar  las  ventajas  de  la  arquitectura  cliente/servidor  a  tres niveles.**

La arquitectura en 3 niveles nos va a permitir realizar una implementación mucho más eficiente de nuestra base de datos, porque para que podamos mantener una independencia física y también lógica, la mejor forma de controlarlo es disponiendo de varios niveles encargados de cumplir dichas restricciones, pudiendo a la vez relacionarse entre sí. Además, podremos también diferenciar un nivel más externo para las perspectivas de usuarios, porque son elementos independientes, que para nada deben relacionarse con el nivel interno.
