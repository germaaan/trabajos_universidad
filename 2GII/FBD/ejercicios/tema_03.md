Fundamentos de Bases de Datos
=============================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------

# Ejercicios de autocomprobación del tema 3: Modelos de datos
### Germán Martínez Maldonado

**1. ¿Cuándo aparece el concepto de modelo de datos? ¿Por qué?**
El concepto de modelo de datos aparece a finales de los años 70, el motivo de su aparición se debe a que los sistemas de bases de datos tenían una compresión muy limitada de la información contenido por la propia base de datos, por eso se empezó a desarrollar este concepto, para que el sistema pudiera responder de forma inteligente a las peticiones de los usuarios.

**2. Diferencias entre los modelos de datos semánticos y los modelos de datos implementables.**

Aunque tanto los modelos de datos semánticos y los modelos de datos implementables se usan para describir datos a nivel conceptual, la diferencia entre ellos se encuentra en que, mientras que en el modelo de datos semántico se hace a nivel externo, permitiendo especificar restricciones de integridad, el modelo de datos semántico, se define a nivel físico, permitiendo especificar la estructura lógica global de la base de datos y, una descripción a un nivel más bajo, el de implementación.

**3. Defina  entidad  y  de  un  ejemplo.  Distinguir  entre  conjunto  entidad  y entidad concreta.**

Una entidad es un objeto que existe y se puede distinguir de los demás objetos. Un conjunto entidad es un conjunto de entidades que comparten unas mismas propiedades y una entidad concreta es una entidad que existe en el mundo como objeto físico.

**4. Defina atributos y de un ejemplo para la entidad antes definida. Identificar la llave primaria de esta.**

Los atributos son las propiedades que identifican a un conjunto de entidades. Por ejemplo: si tomamos como entidad un coche, sus atributos serán matrícula, nº de puertas, motor, color; siendo su llave primaria el atributo matrícula, ya que este es el que nos permite en cualquier caso identificar inequívocamente un coche en particular de entre todos  los demás.

**5. Poner  un  ejemplo  de  atributo  compuesto  relacionado  con  la  entidad definida.**

En el caso de la entidad coche, un atributo compuesto puede ser el motor, ya que este es un atributo del coche, pero a su vez tiene varios atributos como pueden ser tipo de motor, cilindrada, potencia máxima, combustible utilizado, etc.

**6. Definir relación y dar un ejemplo que involucre a la entidad antes definida.**

Una relación es una conexión semántica entre dos o más conjuntos de entidades, por ejemplo, un coche pertenece a una persona, sería una relación uno a uno en que una entidad
coche sólo puede relacionarse con una única entidad persona.

**7. Dar un ejemplo de relación de grado mayor que dos referente a la entidad antes definida.**

Un ejemplo de relación de grado mayor que dos podría ser Chofer, Cliente, Coche, que sería una relación ternaria en la que un cliente contrata un chofer para que lo lleve en un determinado coche.

**8. Definir cardinalidad máxima y mínima y dar dos ejemplos: uno referente a una relación uno a muchos y otro referente a una relación muchos a muchos.**

La cardinalidad máxima y mínima se refieren respectivamente al mayor y menor número de entidades con las que se produce relación.
Ejemplo de relación uno a muchos: relación persona – coche, si consideramos que una persona siempre va a tener uno o varios coches y, un coche siempre va a pertenecer a una persona, por parte de persona la cardinalidad mínima y máxima será 1, mientras que por parte de coche la cardinalidad mínima será 1 y la máxima m.
Ejemplo de relación muchos a muchos: si consideramos que una persona va a conducir uno o varios coches y, un coche puede ser conducido por una o varias personas, en ambos lados la cardinalidad mínima será 1 y la cardinalidad máxima será m.

**9. Definir entidad débil, dar dos ejemplos diferentes de los estudiados en clase.**

Una entidad débil es aquella que no puede identificarse simplemente por sus atributos, por lo que depende de otra para su existencia. Por ejemplo, la entidad motor que depende de la entidad coche, y la entidad despacho que depende de la entidad edificio.

**10. Distinguir  mediante  ejemplos  el  concepto  de  entidad  débil  de  el  de relación uno a muchos.**

Por ejemplo, en un catálogo de coches en venta de un concesionario, un coche puede tener diferentes motores, pero como el objetivo es el coche, un motor si no pertenece a un coche, en este caso no tiene sentido de existencia, por eso motor es una entidad débil.

**11. Establecer la conexión entre el concepto de entidad débil y el de atributo compuesto multivaluado. Ilustrar esta idea mediante dos ejemplos.**

Generalmente una entidad débil es un atributo compuesto multivaluado, porque las entidades débiles suelen ser atributos compuestos y además puede tener más de un valor. Por ejemplo el motor del coche puede tener distintas propiedades.

**12. Defina  el  concepto  de  subtipo  poner  dos  ejemplos  que  no  se  hayan explicado en clase.**

Un subtipo es un subgrupo de entidades de una entidad que tienen atributos adicionales específicos. Por ejemplo: avión, barco y tren son subtipos de transporte o, televisión, radio y teléfono son subtipos de electrodoméstico.

**13. Defina el concepto de herencia. ¿Cómo se relaciona con el caso anterior?**

La herencia es una propiedad por la cual todos los subtipos de un supertipo obtienen un número determinado de características comunes para todos. Por ejemplo, todos los electrodomésticos necesitan energía eléctrica para funciona.

**14. Explicar la  diferencia  entre la relación TIENE-UN y la  relación ES-UN poner un ejemplo de cada una de ellas.**

La diferencia se encuentra en que ES-UN indica que la entidad tiene que tomar uno de los posibles valores de forma obligatoria porque son el total del dominio, mientras que TIENE- UN indica posibles valores que puede tomar la entidad, pero no son todos los valores posibles. Por ejemplo: una persona por sexo ES-UN hombre o mujer se cumple siempre, pero  un vehículo TIENE-UN número de ruedas de 4 o 2, no se cumple siempre, porque puede ser un valor distinto.
