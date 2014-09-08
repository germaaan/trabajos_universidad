Diseño de Aplicaciones para Internet
====================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Utilización de Servicios On-line: RSS
# Utilización de Servicios On-line: Google Charts y Google Maps
# Utilización de Servicios On-line: Twitter
### Germán Martínez Maldonado

### Resumen

Una vez que dominamos los rudimentos de la programación web con web.py vamos a aprender a utilizar servicios que están disponibles e intentar integrarlos en nuestro sitio web. En esta primera práctica vamos a manejar la sindicación de noticias: RSS (Really Simple Syndication), un formato basado en XML utilizado para compartir información actualizada frecuentemente.

Google ofrece una amplia variedad de servicios que están disponibles para ser utilizados en otras webs. En esta práctica vamos a aprender a usar los servicios Google Charts (que nos permite crear gráficas estadísticas interactivas) y Google Maps (que nos permite integrar mapas interativos en nuestra web). Tenga en cuenta que esta práctica es muy abierta (podemos llegar al nivel que queramos profundizar).

Twitter es el famoso sistema que permite comunicar ideas, frases, situaciones, etc. utilizando (fundamentalmente) mensajes de un máximo de 140 caracteres. En esta práctica vamos a utilizar las herramientas que nos proporciona este servicio para integrarlo en nuestra página web.

### 1. Usando Bibliotecas RSS Especializadas

Existen varias bibliotecas especializadas que permiten acceder a contenidos específicamente RSS de manera muy sencilla. Por ejemplo, la biblioteca Universal Feed Parser permite acceder a feeds RSS remotos de manera muy sencilla.

Implemente un script en Python que use dicha biblioteca que realice las mismas acciones que en los puntos anteriores. Puede basarse en el código que existe en.

Basándonos en lo aprendido en los puntos anteriores, añadamos a nuestra web (de la práctica 3) algún marco en donde se muestren los últimos feeds de alguna fuente web que nos interese (periódico o web).

Sería conveniente, por no abusar del proveedor del RSS no consultarlo con demasiada frecuencia (por ejemplo como máximo cada 10 minutos). Para ello podemos hacer algún tipo de caché en nuestra base de datos de los RSS que vayamos a mostrar.

### 2. Google Charts

Google Charts es un servicio que nos permite integrar gráficas estadísticas (y de otros tipos) en nuestra página web, entre las que encontramos gráficas de tarta, ditribución de puntos, gráficas de barras, tablas dinámicas, gráficas de líneas, líneas temporales, etc.

La manera más habitual de usar este servicio es introduciendo un trozo de código JavaScript en nuestra página (usualmente en el <head>). Dicho JavaScript carga algunas bibliotecas de Google, define las series de datos a mostrar, selecciona las opciones para configurar la gráfica y crea un objeto gráfica con un identificador determinado. En el cuerpo de la página web se definirá un objeto <div> con el identificador de la gráfica donde se mostrará la misma.

La biblioteca de Google Charts es bastante sencilla de utilizar y tiene una documentación bastante clara. Se pide seguir el tutorial de dicha documentación para familiarizarse con la biblioteca.

Además, vamos a intentar integrar dicha biblioteca en nuestro sitio web. Para ello crearemos alguna página (o páginas) que nos permita, mediante el uso de formularios, guardar series de datos numéricos en la base de datos. Por ejemplo: “Serie Ingresos” → [1000, 1200, 1100, 1000, 1000, 1234]. Posteriormente debemos ser capaces de visualizar dichas series usando distintos tipos de gráficas (de tarta, barras, lineas, puntos, etc).

Se valorará especialmente si se utilizan las opciones de interactividad de las gráficas, utilización de las gráficas “menos habituales”, la personalización de las gráficas mostradas y, en general, la originalidad de las mismas.

Un recurso que puede facilitar mucho el uso de esta práctica es el Google Charts Playground.

### 3. Google Maps

Google Maps es el archiconocido servicio de mapas interactivos online. Google ofrece la posibilidad de integrar mapas personalizados en nuestras páginas web mediante el uso de una API que se puede integrar en nuestro código HTML.

Al igual que con el servicio de gráficas, para páginas web se hace uso de JavaScript incrustado en nuestro HTML para definir los parámetros de un mapa, que luego se mostrará en un <div> de nuestra web.

Para comenzar a utilizar este servicio es muy recomendable seguir el tutorial que nos ofrecen. De especial importancia es el apartado en el que se nos comenta la necesidad de obtener una “llave” (key) para el uso de la API.

En esta práctica se pide que nos familiaricemos con esta biblioteca y que seamos capaces de utilizar las características que nos parezcan más interesantes de la misma en nuestro sitio web, como por ejemplo: Añadir marcadores, textos o imágenes a un mapa (¿desde la base de datos?), uso de distintas capas en un mapa, modificar el interfaz de los mapas, uso de geolocalización, el servicio de “como llegar”, el servicio de elevación, de Street View, el servicio de mostrar panorámicas (al estilo Street View ), etc.

Al igual que en el punto anterior, se valorará especialmente el uso de funcionalidades menos conocidas, la personalización llevada a cabo, originalidad, etc.

### 4. Introducción e Integración Sencilla de Twitter

Antes de lanzarnos a programar e implementar algún sevicio de Twitter en nuestra página web debemos familiarizarnos un poco con los servicios que ofrecen, así como darnos de alta como usarios de la plataforma.

También es interesante leer un poco acerca de la plataforma Twitter. Debemos familiarizarnos con los conceptos: Tweet, User, Entity y Place.

Twitter ofrece una manera muy simple con la que podemos empezar a incrustar el servicio en nuestra página web. En la página Twitter for Websites se nos ofrecen algunas herramientas muy sencillas con las que podemos incrustar el “típico” boton de Twitter o incluso una caja de Tweets dinámicos.

Compruebe que efectivamente puede incrustar ambos tipos de objetos en su página web simpemente copiando el codigo HTML en el sitio oportuno.

### 5.  Python Twitter

Tweepy es una biblioteca que permite acceder a la API de Twitter desde el lenguaje de programación Python.
En esta práctica (muy abierta) debemos utilizar esta biblioteca para acceder a contenidos publicados en Twitter y mostrarlos de la manera que consideremos oportuna. Por ejemplo, podemos mostrar los tweets que respondan a una búsqueda, los que se hayan producido cerca de unas coordenadas concretas, etc.

Para utilizar la biblioteca debemos instalarla:

```
sudo apt-get install python-pip
sudo pip install tweepy
```

### 9. Mashupeando

Una vez que sabemos utilizar distintos servicios, podemos hacer un Mashup de los mismos. Por ejemplo, podemos mostrar en un mapa la localización de unos tweets (¿útil para seguir eventos masivos?), mostrar una gráfica estadística sobre los últimos tweets relacionados con un tema, etc.

En esta sección de la práctica se pide pensar y realizar un mashup utilizando los servicios vistos (o algún otro que conozcamos).
