Sistemas Multimedia
===================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Evaluación: Documentación
### Germán Martínez Maldonado

## Introducción

Esta documentación corresponde al proceso de desarrollo de la aplicación para la práctica de evaluación de la asignatura **“Sistemas Multimedia”**. Dicha aplicación tiene funciones multimedia que nos permiten reproducir y capturar audio y video en diferentes formatos, además de poder visualizar, crear y editar archivos de imagen; todo esto dentro de una misma aplicación con un entorno multiventana.


## Requisitos
### Requisitos funcionales

Se va a realizar una breve descripción estructurada de todas las características que nuestro sistema debe cubrir.

1. **Funcionalidades generales**: acciones que podremos llevar a cabo con nuestra aplicación sin que tengan como objetivo su uso con un medio multimedia en concreto.
 * Crear una nueva ventana de imagen.
 * Reproducir archivos de audio.
 * Visualizar archivos de video.
 * Reproducir archivos de video.
 * Guardar en un archivo el contenido de una ventana de imagen.
 * Capturar audio desde una entrada de audio.
 * Capturar video desde una webcam.
 * Capturar la imagen actual de una ventana interna.

2. **Funcionalidades de dibujo**: acciones que podremos llevar a cabo a la hora de crear nuevos archivos de imagen.
 * Dibujar figuras con forma de punto.
 * Dibujar figuras con forma de línea recta.
 * Dibujar figuras con forma de rectángulo cuyas esquinas forman un ángulo recto.
 * Dibujar figuras con forma de elipse.
 * Dibujar figuras mediante un trazo libre que podrá ser abierto o cerrado.
 * Dibujar figuras con forma de rectángulo cuyas esquinas son redondeadas.
 * Dibujar figuras con forma de arco que podrá ser abierto o cerrado.
 * Seleccionar  un  color  a  utilizar  como  color  de  trazo  o  de  frente  de degradado.
 * Seleccionar  un  color  a  utilizar  como  color  de  relleno  o  de  fondo  de degradado.
 * Informar sobre el color de trazo y de frente de degradado actual.
 * Informar sobre el color de relleno y de fondo de degradado actual.
 * Modificar el grosor del trazo con el que se dibujan las figuras.
 * Seleccionar un trazo continuo o discontinuo para dibujar las figuras.
 * Seleccionar si las figuras tendrán un color de relleno y si este será liso, degradado horizontalmente, degradado verticalmente, degradado  de forma radial o se usará una imagen predeterminada en lugar de un color.
 * Activar la opción de editar las propiedades de las figuras ya dibujadas.
 * Activar diferentes opciones  de rendering sobre las imágenes que  serán pintadas.

3. **Funcionalidades de operaciones sobre imágenes**: acciones que podremos aplicar sobre una imagen dentro de una ventana de imagen.
 * Modificar el brillo de la imagen.
 * Aplicar un contraste predefinido a la imagen.
 * Aplicar un filtro predefinido a la imagen.
 * Invertir los colores de la imagen.
 * Transformar los colores de la imagen a una escala de grises.
 * Girar libremente la imagen en la ventana sobre sí misma.
 * Escalar el tamaño de la imagen.
 * Deformar la forma de la imagen.
 * Aumentar la iluminación de la imagen.
 * Aplicar una corrección gamma a la imagen.
 * Realizar una combinación de lineal de las bandas de la imagen.

4. **Funcionalidades  del  menú**:  acciones  generales  de  la  aplicación  que  podremos realizar desde el menú.
 * Salir de la aplicación.
 * Ocultar o mostrar las diferentes barras de herramientas.
 * Mostrar información sobre la aplicación y el autor.

### Requisitos no funcionales

Enumeración de requisitos relacionados o que afectan a distintos aspectos del sistema; como la usabilidad o restricciones de implementación.

1. Para crear una nueva ventana de imagen se tiene que especificar un tamaño que debe estar dentro de unos límites establecidos.
2. Los archivos multimedia que pueden ser abiertos serán solo de los formatos establecidos previamente mediante filtros.
3. Solo se puede guardar multimedia cuando sean imágenes.
4. Para capturar el audio se deben seleccionar los parámetros de digitalización.
5. No puede haber más de una ventana de captura de audio simultáneamente.
6. El audio capturado es almacenado en un archivo temporal hasta que finaliza la captura y se guarda en su archivo definitivo.
7. Solo se podrá captura la imagen de una ventana de reproducción de video o captura de webcam.
8. Cada figura tendrá sus propios atributos.
9. Una  vez  que  una figura ha sido dibujada no se  puede  cambiar  su  tipo  de relleno.
10. Para el desarrollo de la aplicación se usará el lenguaje Java compatible con Java Platform (JDK) 7.


## Análisis

A parte de la ventana principal, necesitaremos representar las diferentes ventanas internas en función del medio que vayan a contener (imagen, reproducción de audio, reproducción de video, captura de audio o captura de webcam). También necesitaremos representar los diferentes tipos de figura y sus atributos, ya que uno de los requisitos fundamentales es que cada figura tiene sus propios atributos.

La mayoría de los requisitos son acciones simples, pero concretas, por lo que serán realizadas por una función desarrollada para tal fin. Estos métodos que necesitaremos para cumplir con los requisitos estarán dentro de clases concretas con ese objetivo (como los filtros de archivos), o serán parte de las clases representativas de elementos del sistema (como la modificación de atributos de los figuras).


## Diseño

Para implementar la interfaz del programa, nos vamos a basar en  la clase **“VentanaPrincipal”** que heredará de JFrame, esta clase será sobre la que situemos todos los elementos que nos permitirán interactuar con el programa, ya sea a través de las barras de herramientas que heredan de JToolBar o de las ventanas internas JInternalFrame que podremos ir creando y añadiendo sobre el JDesktopPane. Crearemos una clase por tipo de ventana interna: para reproducción de sonido **“VentInternaReprSoni”**, para reproducción de video **“VentInternaReprVide”**, para grabación de sonido **“VentInternaGrab”**, para captura de webcam **“VentInternaWebcam”** y para las imágenes **“VentanaInternaImag”**.
Tanto para la reproducción de audio y de video, en la clase de la ventana interna correspondiente usaremos un objeto de la clase **“Player”** que nos provee JMF, generando dicho reproductor de forma directa mediante el método **“createRealizedPlayer”** de la clase **“Manager”** que también obtenemos de JMF. También usaremos la misma clase **“Player”** para realizar la captura desde la webcam, pero con la diferencia de que el reproductor obtenido para reproducir los archivos de audio y video se obtiene pasándole como parámetro el localizador de un archivo multimedia y, para el reproductor de webcam le pasamos como parámetro la información sobre el dispositivo de captura, en este caso la propia webcam. Tanto en la ventana interna de reproducción de video como en la de captura de webcam, incluiremos el método **“getFrame”** para poder captura la imagen que haya en ese momento y visualizarla en una ventana de imagen.

Para la grabación de sonido usaremos la clase **“Grabador”**, que es una adaptación de la clase **“SMSoundRecorder”** que tuvimos a nuestra disposición para desarrollar la práctica 11. Los cambios más importantes hechos en esta clase con respecto a la original, es que los parámetros de digitalización no son unos parámetros predefinidos, sino que son parámetros que le asignamos a la clase como atributos mediante el método correspondiente. La otra gran diferencia, es que ahora el sonido capturado se va almacenado en un archivo que creamos directamente en el directorio temporal del sistema, solo cuando pulsemos el botón de **“stop”**, se nos mostrará un dialogo para indicar dónde queremos guardar el audio capturado, volcándose la información del archivo temporal en ese nuevo archivo indicando, y borrando además el archivo temporal. De la misma forma que la reproducción de audio y video se realizaba incluyendo un objeto **“Player”** en la ventana interna correspondiente, para capturar sonido solo tenderemos que incluir un objeto **“Grabador”** en **“VentInternaGrab”**. Además, como también queremos que no pueda haber más de una ventana de captura de sonido a la vez, implementaremos un patrón Singleton para la creación de este tipo de ventanas internas, controlando la grabación siempre con la misma ventana.

Usaremos la clase **“Filtro”** para crear los filtros que usaremos en la selección de ficheros a abrir o guardar, para que solo se puedan abrir determinados archivos según su extensión (lo que nos será especialmente útil a la hora de abrir todos los tipos de archivos con un mismo método), también para comprobar la extensión de los archivos y así siempre se guarden con la extensión que hemos seleccionado y no otra.

Las clases **“KernelProducer”** y **“LookTableProduce”** son las clases proporcionadas durante el desarrollo de las prácticas para aplicar filtros sobre la imagen la primera, y transformaciones del color la segunda. La clase **“ColoresComboBox”** nos permite darle propiedades especiales a los elementos de un JComboBox para conseguir el detalle de mostrar iconos (colores planos en nuestro caso) junto con el texto de las posibles opciones a elegir.

La parte que ha necesitado de un diseño propio más extenso ha sido la relacionada con la imagen, para visualizar las imágenes partimos de la ventana interna **“VentInternaImag”** y la clase panel **“LienzoImagen”** que ya usábamos en anteriores prácticas. Se le han añadido los métodos necesarios para conseguir las funcionalidades necesarias, pero lo importante se encuentra en las clases desarrolladas dentro del paquete **“formas”**. A diferencia de cómo se hacía en las prácticas anteriores donde usábamos objetos de las clases ya implementadas como **“Line2D.Double”** o **“Rectangle2D.Double”**, para el desarrollo de este práctica he desarrollado una serie de clases que representan a cada una de estas figuras.

Primero vamos a destacar 2 clases propias, la interfaz **“GFigura”** y la clase **“AtribCompuesto”**. **“GFigura”** proveerá de los métodos comunes que todos las figuras deben compartir, como el método **“contiene”** para saber si un punto pertenece a una figura, o **“setPosicion”** para establecer la nueva posición de una figura en el panel, haciendo que todas las clases para la representación de figuradas creadas implementen los métodos de la interfaz. Usando la clase **“AtribCompuesto”** para definir sus propiedades y métodos que actúan sobre dichas propiedades (como cambiar el color del trazo o el groso del mismo), podremos realizar las mismas operaciones de forma genérica sobre cualquier tipo de figura llamando al método correspondiente de la clase **“AtribCompuesto”**, no teniendo que implementar dichas operaciones en cada una de las clases.

Utilizando esta interfaz y esta clase, podemos almacenar todas las figuras en un contenedor de elementos **“GFigura”** y actuar sobre ellas de forma genérica llamando a los mismos métodos definidos en la interfaz o la clase de las propiedades, teniendo como primera ventaja un uso más simple de las figuras (se pinta mediante el mismo procedimiento una simple línea que un complejo trazo libre), y también si quisiéramos cambiar los comportamientos y atributos de las propiedades de las figuras, sólo deberíamos cambiarlos en dicha clase de propiedades, no en una por una cada una de las clases de las figuras implementadas, dándonos así un simplicidad y orden a la hora de extender las funcionalidades de la aplicación.
Esto también ocurre a la hora de realizar el pintado de las figuras, como todas las figuras tienen atributos propios, si quisiéramos pintar las figuras desde el método **“paint”** del JPanel, antes de pintar cada figura deberíamos modificar las propiedades del objeto **“Graphics2D”** en el que se van a pintar las figuras, el problema está en que si tuviéramos varias clases que pinten nuestras formas deberíamos modificar cada uno de los métodos **“paint”** de cada una de esas clases, lo que a la larga podría llevar a errores en la implementación; por eso es preferible que sea la propia figura la que disponga de las funcionalidades necesarias para pintarse a sí misma.

Para conseguir esto, hemos creado una clase **“Dibujante”** que será la que se encargará de realizar esta acción. Dicha clase estará referenciada como atributo de nuestra figura, a la vez que nuestra figura estará referenciada como atributo dentro su atributo de la clase **“Dibujante”**; este doble enlace nos dará un mayor control lo que se podrá dibujar. La clase dibujante recibirá el objeto **“Graphics2D”** sobre el que se tiene que pintar, al que le cambiará sus propiedades según las propiedades de la figura a la que esté  enlazada, que será  la única figura  que  puede  pintar,  y que gracias a la implementación de la interfaz **“GFigura”** y al uso de la clase **“AtribCompuesto”**, se hará siempre de la misma forma, todo desde un único método que podremos personalizar según queramos o vayamos necesitando, como en nuestro caso para aplicar las opciones de rendering o relleno de las figuras. Consiguiendo una implementación que se pueda llamar desde cualquier método **“paint”** de cualquier componente, sin tener que preocuparnos de adaptarlo antes según nuestras necesidades.


## Codificación

La documentación de la codificación se adjunta como API Javadoc generada con el código del propio programa mediante NetBeans. En dicha API se encuentran comentados todos los métodos existentes en la aplicación, tanto públicos como privados, además de las variables estáticas públicas que se han usado para referenciar valores concretos de propiedades de una clase desde cualquier otra clase cuando era necesario hacerlo; como en el caso de los diferentes tipos de degradados del color de relleno de las figuras o los valores de codificación para la digitalización en el audio a capturar.


## Bibliografía

Enlaces de las páginas consultadas que han sido de mayor utilidad durante el desarrollo del trabajo.

* [http://chuwiki.chuidiang.org/index.php?title=Poner_iconos_en_un_JCombobox](http://chuwiki.chuidiang.org/index.php?title=Poner_iconos_en_un_JCombobox)
* [http://docs.oracle.com/cd/E17802_01/j2se/javase/technologies/desktop/media/jmf/2.1.1/apidocs/javax/media/Player.html](http://docs.oracle.com/cd/E17802_01/j2se/javase/technologies/desktop/media/jmf/2.1.1/apidocs/javax/media/Player.html)
* [http://docs.oracle.com/javase/7/docs/api/java/awt/geom/GeneralPath.html](http://docs.oracle.com/javase/7/docs/api/java/awt/geom/GeneralPath.html)
* [http://docs.oracle.com/javase/7/docs/api/java/awt/RadialGradientPaint.html](http://docs.oracle.com/javase/7/docs/api/java/awt/RadialGradientPaint.html)
* [http://docs.oracle.com/javase/7/docs/api/java/awt/RenderingHints.html](http://docs.oracle.com/javase/7/docs/api/java/awt/RenderingHints.html)
* [http://docs.oracle.com/javase/7/docs/api/javax/swing/JFileChooser.html](http://docs.oracle.com/javase/7/docs/api/javax/swing/JFileChooser.html)
* [http://docs.oracle.com/javase/tutorial/uiswing/components/combobox.html#renderer](http://docs.oracle.com/javase/tutorial/uiswing/components/combobox.html#renderer)
* [http://docs.oracle.com/javase/tutorial/uiswing/components/filechooser.html](http://docs.oracle.com/javase/tutorial/uiswing/components/filechooser.html)
* [http://docs.oracle.com/javase/tutorial/uiswing/examples/components/FileChooserDemo2Project/src/components/ImageFilter.java](http://docs.oracle.com/javase/tutorial/uiswing/examples/components/FileChooserDemo2Project/src/components/ImageFilter.java)
* [http://docs.oracle.com/javase/tutorial/uiswing/examples/components/FileChooserDemo2Project/src/components/Utils.java](http://docs.oracle.com/javase/tutorial/uiswing/examples/components/FileChooserDemo2Project/src/components/Utils.java)
* [http://foro.chuidiang.com/java-j2se/jcombobox-problema-al-anadir-icono-con-texto/](http://foro.chuidiang.com/java-j2se/jcombobox-problema-al-anadir-icono-con-texto/)
* [http://lineadecodigo.com/java/borrar-un-fichero-con-java/](http://lineadecodigo.com/java/borrar-un-fichero-con-java/)
* [http://lineadecodigo.com/tag/createtempfile/](http://lineadecodigo.com/tag/createtempfile/)
* [http://snipplr.com/view/1592/](http://snipplr.com/view/1592/)
* [http://stackoverflow.com/questions/10951449/multiple-colors-for-each-item-in-jcombobox](http://stackoverflow.com/questions/10951449/multiple-colors-for-each-item-in-jcombobox)
* [http://stackoverflow.com/questions/2229124/how-to-assign-different-colors-to-items-in-jcombobox](http://stackoverflow.com/questions/2229124/how-to-assign-different-colors-to-items-in-jcombobox)
* [http://stackoverflow.com/questions/9265703/component-with-transparent-background-to-bufferedimage](http://stackoverflow.com/questions/9265703/component-with-transparent-background-to-bufferedimage)
* [http://stackoverflow.com/questions/9522465/java-editable-jcombobox-in-joptionpane-inputdialog](http://stackoverflow.com/questions/9522465/java-editable-jcombobox-in-joptionpane-inputdialog)
* [http://swing-facil.blogspot.com.es/2011/12/renderinghints-renderizados-y.html](http://swing-facil.blogspot.com.es/2011/12/renderinghints-renderizados-y.html)
* [http://swing-facil.blogspot.com.es/2012/03/gradientpaint-demo-ejemplos-del-uso-de.html](http://swing-facil.blogspot.com.es/2012/03/gradientpaint-demo-ejemplos-del-uso-de.html)
* [http://www.developer.com/java/other/article.php/1572251/Java-Sound-Getting-Started-Part-1-Playback.htm](http://www.developer.com/java/other/article.php/1572251/Java-Sound-Getting-Started-Part-1-Playback.htm)
* [http://www.dzone.com/snippets/java-example-very-simple](http://www.dzone.com/snippets/java-example-very-simple)
* [http://www.java2s.com/Code/Java/2D-Graphics-GUI/Dashedrectangle.htm](http://www.java2s.com/Code/Java/2D-Graphics-GUI/Dashedrectangle.htm)
* [http://www.java2s.com/Code/Java/2D-Graphics-GUI/GradientPaintdemo.htm](http://www.java2s.com/Code/Java/2D-Graphics-GUI/GradientPaintdemo.htm)
* [http://www.kodejava.org/how-do-i-draw-a-generalpath-in-java-2d/](http://www.kodejava.org/how-do-i-draw-a-generalpath-in-java-2d/)
* [http://www.oracle.com/technetwork/java/javase/formats-138492.html](http://www.oracle.com/technetwork/java/javase/formats-138492.html)
* [http://www2.sys-con.com/itsg/virtualcd/java/archives/0502/decarmo/index.html](http://www2.sys-con.com/itsg/virtualcd/java/archives/0502/decarmo/index.html)
