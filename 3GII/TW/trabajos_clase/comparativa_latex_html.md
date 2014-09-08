Tecnologías Web
===============
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Comparativa de LaTeX y HTML
### Germán Martínez Maldonado

## Introducción

El objetivo de este trabajo es conocer a grandes rasgos las diferencias existentes entre LaTeX y HTML, siendo el primero un procesador  de textos y el segundo un lenguaje de marcado, pero ambos con la misma función de estructurar contenidos dentro de un documento. Para conocer en qué se diferencia, primero vamos a hacer una breve descripción de que es cada uno.

## LaTeX

Es un sistema de composición de textos, usado sobre todo para textos científicos o de contenido muy técnico que contenga grandes cantidades de fórmulas matemáticas, todo esto gracias a la potencia que dan el gran conjunto de macros de TeX, no teniendo así que preocuparnos por la distribución del texto, LaTeX se encarga de hacerlo obtenido un apariencia similar a la de la edición de un libro.

## HTML

Es un lenguaje de marcado que se usa sobre todo para la descripción de la estructura de un texto en páginas web. Al ser un lenguaje de marcado todo se escribe con etiquetas entre corchetes angulares, además también permite la inclusión de script en lenguajes como JavaScript, para añadirle una mayor funcionalidad al documento durante su navegación.

## Diferencias

La primera diferencia cuando nos referimos a LaTeX y HTML, es que mientras el primero es un software que debemos instalar para poder preparar los textos, el segundo es un lenguaje que podemos usar sin necesitar más que un simple editor de texto plano, por esto mismo, LaTeX es el encargado de procesar los escritos en él, mientras que los textos escritos con HTML, no son procesados por un programa HTML, serán interpretados por cualquier navegador web compatible.

Como indicábamos, LaTeX está más enfocado a textos de ámbito científico que contengan fórmulas matemáticas, ya que una facilidad que encontramos es que podremos introducir con mayor facilidad una gran cantidad de símbolos que no se encuentran en un teclado estándar gracias a los códigos que nos permiten introducir, pero en contraposición, encontraremos mayor dificultad para introducir imágenes, sobretodo en formatos tan extendidos hoy en día como son JPEG y GIF, hecho que es todo lo contrario a la facilidad que encontramos en HTML para introducir este tipo de elementos y cualquier elemento multimedia en general.
Otra características de LaTeX es que este recibe un texto cualquier y mediante los comandos que describen la estructura del documento, decide cómo debe formatear el documento que se va a generar, en HTML, sobretodo en la versión 5, se define la estructura del documento, pero no como se va a formatear la misma, esto se podría realizar externamente mediante el uso de CSS.

También es una ventaja de LaTeX que el documento generado es independiente del dispositivo o sistema, la salida generada es siempre la misma en cualquier sistema, además de que puede ser portado a otros formatos como Postscript, PDF, SGML, HTML o RTF, entre otros. HTML es un formato en sí mismo, además que en función del sistema operativo y el navegador usado para visualizar el documento, este puede variar en su representación.

A nivel práctico, un documento HTML como mínimo debe contener lo siguiente:

```
<!DOCTYPE HTML>
    <HTML>
        <HEAD>
            <TITLE> TITULO </TITLE>
    </HEAD>
    <BODY>
        <P> TEXTO </P>
    </BODY>
</HTML>
```

Y en LaTeX:

```
\documentclass{article}
\usepackage[spanish]{babel}
\usepackage{amsmath}
\title{TITULO}
\begin{document}
    \maketitle TEXTO
\end{document}
```

Con ambos código generaríamos una salida similar, pero a simple vista vemos como el código en HTML se nos puede hacer más amigable por su aparente mayor simpleza.

### Referencias:

Referencias consultadas a 1 de abril de 2013:

* Enlace 1: “LaTeX – Wikipedia, la enciclopedia libre”, última modificación 10:39 24/03/2013:
[http://es.wikipedia.org/wiki/LaTeX](http://es.wikipedia.org/wiki/LaTeX)

* Enlace 2: “LaTeX, Procesador de documentos científicos y técnicos”, Alfredo Catalina, 01/10/97:
[http://www.idg.es/pcworld/LaTeX_-Procesador-de-documentos-cientificos-y-tecn/art38016.htm](http://www.idg.es/pcworld/LaTeX_-Procesador-de-documentos-cientificos-y-tecn/art38016.htm)

* Enlace 3: “Manual de LaTeX/Insertar figuras en un documento – Wikilibros”, última modificación 01:24 28/11/2012: 
[http://es.wikibooks.org/wiki/Manual_de_LaTeX/Insertar_figuras_en_un_documento](http://es.wikibooks.org/wiki/Manual_de_LaTeX/Insertar_figuras_en_un_documento)

* Enlace 4: “HTML – Wikipedia, la enciclopedia libre”, última modificación 22:21 26/03/2013:
[http://es.wikipedia.org/wiki/HTML](http://es.wikipedia.org/wiki/HTML)

* Enlace 5: “Definición de html – Qué es, Significado y Concepto”, 2008-2013: 
[http://definicion.de/html/](http://definicion.de/html/)
