Diseño de Aplicaciones para Internet
====================================
4º Grado en Ingeniería Informática 2013/2014
--------------------------------------------


# Práctica 5: Frameworks web Django y Bootstrap
### Germán Martínez Maldonado

### Resumen

En muchos desarrollos web no partiremos de cero (por no reinventar la rueda y no tener que solucionar problemas que ya han sido resueltos por otros programadores en el pasado). Es por ello que puede ser útil utiliar alguno de los frameworks libres que existen. Entre ellos están Django y Bootstrap.

### 1. Django

Django se define como un framework web que anima al desarrollo rápido de aplicaciones así como a un diseño pragmático y limpio. Está programado en Python.

En las clases de teoría se ha visto un ejemplo de instalación básica y mínima de Django. En esta práctica se pide realizar un sitio web nuevo usando Django. Se recomienda consultar las transparencias de teoría así como el tutorial del framework. Dicho sitio deberá incluir al menos un par de paquetes adicionales de Django que incorporen alguna funcionalidad extra que no tenga por defecto el framework.

### 2. Bootstrap

Uno de los desafios del desarrollo de aplicaciones web en la actualidad es conseguir que nuestro sitio se visualice y sea navegable de manera intuitiva en un rango amplio de navegadores y dispositivos (especialmente tras la aparición de los (mal llamados) móviles inteligentes y tabletas. Las implementaciones particulares de los estándares web (y las recomendaciones que aún no son estandar) provocan que el desarrollador tenga que tener en cuenta demasiados entornos donde se utilizará su aplicación web y, lo que es peor, entornos que probablemente aún ni siquiera están inventados.

Una de las tendencias actuales para evitar este tipo de problemas es la llamada “diseño web adaptable” (responsive web design) que permite adaptar la representación de nuestra aplicación web al entorno del usuario. La idea fundamental es NO tener que construir diversos sitios que se adapten a cada dispositivo o familia de dispositivos existentes, sino utilizar un único lenguaje de marcas (HTML) y hojas de estilo (CSS) que permitan al dispositivo cliente mostar correctamente el sitio sean cuales sean las características del mismo.

Para facilitar la tarea del desarrollo de aplicaciones web adaptables aparecen diversos frameworks que permiten al programador abstraerse de muchos de los aspectos a tener en cuenta. Uno de ellos es Bootstrap, desarrollado por Twitter. Consiste en una colección de estilos CSS, módulos de Javascript y tipografías que permiten un desarrollo rápido y adaptable de nuestra aplicación. Entre otros mecanismos, utiliza un sistema de rejilla que se adapta de manera dinámica dependiendo del dispositivo o ventana del cliente.

En esta práctica se pide adaptar el sitio web creado con Django en el punto anterior utilizando Bootstrap, de tal manera que nuestro sitio pueda verse (y usarse) de manera correcta tanto en dispositivos reducidos como en otros más grandes. Además de que nuestro sitio se adapte al tamaño del dispositivo, debemos mostrar al menos una tabla, un formulario y alguna imagen formateados con las clases de Bootstrap para tal efecto. Para ello se recomienda consultar la documentación del CSS de Bootstrap. Se valorará de forma positiva la utilización de alguno de los componentes o Javascript que proporciona el framework.
