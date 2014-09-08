Programación y Diseño Orientado a Objetos
=========================================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Relación de problemas. Tema 4: Herencia
### Germán Martínez Maldonado

**1. ¿Cómo afecta el especificador de acceso de una variable/método para ser heredado según sea: private, public, protected o visibilidad de paquete?**

Con private ninguna variable/método de la superclase es visible en la subclase; con public las variables/métodos de la superclase siguen siendo públicas en la subclase;  con protected las variables/métodos de la superclase son visibles en la subclase, pero no en el exterior; y con visibilidad de paquete, las variables/métodos son visibles desde todos los del mismo paquete.

**3. ¿Cómo se puede acceder a las variables privadas de una superclase desde una subclase?**

Solo se podrá acceder a estas si las variables tienen visibilidad protected.

**5. ¿Es  posible  redefinir  en  las  subclases  un  método  de  la superclase definido como final?**

No es posible redefinir un método declarado como final, porque este modificador se usa precisamente para indicar que una variable, método o clase no se va a modificar.

**6. Indica la diferencia entre sobrecargar y redefinir un método.**

La sobrecarga significa que pueden existir diferentes métodos con el mismo nombre, sólo si el número o el orden de los argumentos recibidos son distintos, pudiendo estos métodos tener diferentes comportamientos, pero la sobrecarga es siempre sobre métodos de la misma clase. Redefinir un método consiste en declarar en la subclase una función que ya existe en el superclase con el mismo nombre.

**7. ¿Para qué sirve la anotación @Override en Java?**

Sirve para indicar que el método redefine un método de la superclase.

**8. Explica cómo funciona la sobreescritura de métodos, es decir, cómo decide el sistema qué método invocar en cada caso.**

Cuando se invoca a un método desde una subclase, y el método no está definido en el ámbito de clase desde el que se ha realizado la llamada, se busca automáticamente en la superclase. Si el método está definido en la propia subclase, el método de la superclase se oculta, pudiendo sólo ser llamado a través de la palabra reservada “super”.

**14. ¿Para qué sirve una clase abstracta?**

Una clase abstracta sirve para definir la base de una clase, por que como tendrá mínimo un método sin implementar, nos podrá servir para crear clases hijo con comportamientos comunes, pero funcionamientos diferentes.

**15. ¿Para qué sirve una interface o interfaz de Java?**

Para poder simular una herencia múltiple, pudiendo así heredar de una clase, mientras que implementa una interfaz, simulando que se hereda de dos clases.
