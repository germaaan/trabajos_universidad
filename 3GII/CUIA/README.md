Computación Ubicua e Inteligencia Ambiental
===========================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# TRIVIO

### Germán Martínez Maldonado
### Pablo Sánchez Robles

## Motivación

La motivación que nos ha llevado a desarrollar este trabajo es poder adentrarnos en el mundo de la realidad aumentada, porque consideramos interesante el hecho de investigar la interacción textual con un intérprete creado mediante realidad aumentada, ya que aunque no se diferencia en gran medida de la clásica interacción hombre-máquina mediante comandos de texto, el hecho de ver representada a la “máquina” en nuestro propio entorno como una forma “real” da una profundidad emocional con la que queremos experimentar.

Además, el hecho de poder poner en práctica lo que vayamos aprendiendo dándole forma a un juego en el que de inmediato podemos ver cómo funciona lo que estamos implementando, hace que la experiencia puede ser mucho más amena, y aunque siempre teniendo presente que sigue siendo un trabajo, le da un punto más de interés que ayuda a trabajar aun cuando no dejen de aparecer errores.

A todo lo descrito consideramos que partiendo de esta base se abre una gran cantidad de posibilidades de expansión para el proyecto que se podrían ir concretando en función del resultado. Las posibles ideas que tenemos las concretaremos en el último punto del trabajo.


## Problema a resolver

El problema que nos hemos propuesto resolver y ha motivado este proyecto, es crear un juego en el que un personaje virtual nos hará preguntas y nos dará posibles respuestas. El personaje será creado mediante realidad aumentada cuando la cámara del móvil reconozca un patrón que hemos diseñado previamente, y las respuestas serán seleccionadas de entre cuatro posibles por el jugador, informándonos si hemos acertado o no. Vamos a desarrollar un juego que tenemos en mente que puede ser usado por toda la familia, desde el más pequeño hasta el más grande.

El entorno de desarrollo que hemos usado es Unity3D en conjunto con el SDK de realidad aumentada Vuforia. Como ya hemos dicho, la forma de funcionar del programa sería a través de reconocimiento de marcadores, según el tipo de marcador reconocido generaría un personaje que nos haría una pregunta concreta de un  tema determinado en  función  del marcador reconocido, además nos daría cuatro posibles respuestas, siendo el jugador el que deberá seleccionar la respuesta correcta para poder proseguir con el juego, o si nos equivocamos “perder” una vida. La plataforma para la que vamos a desarrollar la aplicación es Android.


## Características de un buen programa

En general todos los programas deben tener una sería de características mínimas como pueden ser estabilidad o rapidez de respuestas para que el usuario no deje de usar el problema, simplemente por un mal funcionamiento. Además siendo este un juego basado sobre todo en un interacción con un interfaz táctil nos interesa que su funcionamiento sea fácil e intuitivo, que ningún detalle ajeno al desarrollo del juego le distraiga y le haga concentrarse o tener en mente algo que no sea responder a la pregunta formulada.

Al ser un programa desarrollado para Android en el que hemos dicho que la interfaz táctil es especialmente importante, debemos tener en cuenta que en Android hay una gran segmentación de versiones y dispositivos, por lo que queremos que el juego sea lo más simple posible, a la par que divertido, para lo que nos centraremos en implementar un juego simple que no requiera mucha capacidad técnica para ser ejecutada; y en cuanto al problema de los dispositivos, el mayor problema en nuestro caso lo encontramos en los diferentes tipos y tamaños de pantallas, así que para este solucionar este problema, hemos querido hacer una interfaz lo más intuitiva posible, simplista pero funcional, donde no hay complicaciones a la hora de seleccionar una respuesta haciendo uso de la interfaz de usuario en superficie de nuestro dispositivo.


## Soluciones actuales y sus carencias

Un importante detalle a destacar, es que hemos encontrado muchas aplicaciones basadas en típico juego de preguntas y respuestas como pueden ser “[Trivial Mobile](https://play.google.com/store/apps/details?id=erseco.soft&amp;%3Ft=W251bGwsMSwxLDIxMiwiZXJzZWNvLnNvZnQiXQ)”, “[Quizture  Películas Trivial](https://play.google.com/store/apps/details?id=com.novagecko.quizture.movies&amp;%3Ft=W251bGwsMSwxLDIxMiwiY29tLm5vdmFnZWNrby5xdWl6dHVyZS5tb3ZpZXMiXQ”, “[Bluzz Trivial Minds](https://play.google.com/store/apps/details?id=com.diablins.android.bluzztrivialminds2&amp;%3Ft=W251bGwsMSwxLDIxMiwiY29tLmRpYWJsaW5zLmFuZHJvaWQuYmx1enp0cml2aWFsbWluZHMyIl0)”, “[Súper Trivial Quiz](https://play.google.com/store/apps/details?id=com.jjvaca.trivial&amp;%3Ft=W251bGwsMSwxLDIxMiwiY29tLmpqdmFjYS50cml2aWFsIl0)” o el más famoso de todos, “[TriviaDos](https://play.google.com/store/apps/details?id=aul.irm.triviados&amp;%3Ft=W251bGwsMSwxLDIxMiwiYXVsLmlybS50cml2aWFkb3MiXQ)”. Todos los nombrados son los juegos de preguntas y respuestas que hemos encontrado entre lo más relevantes en la tienda de apps oficial de Google, Google Play, y a excepción de TriviaDos, que cuenta con casi 17.000 descargar, ninguna de las otras aplicaciones es que sea especialmente conocida; pero lo que sí nos llama la atención es que ninguna cuenta con una característica que si tiene la nuestra, el uso de realidad aumentada.

Como hemos visto, estamos en un campo el que se podríamos decir que tendríamos un gran competencia similar, pero una prácticamente inexistente competencia concreta, siendo el motivo que no hayan implementado nuestra característica principal, bien por desconocimiento, bien por cuestiones técnicas o simplemente porque han considerado que al público objetivo no le gustaría o lo consideraría demasiado complejo.

Sea cual sea el motivo de que nuestra competencia objetivo se haya basado para no usar la realidad aumentada cuando nosotros la consideramos especialmente importante, como nuestra aplicación está basado en ello, debemos centrar nuestros esfuerzos en que el usuario prefiera nuestra aplicación destacada sobre las otras.


## Descripción del trabajo realizado

Aunque nuestra aplicación finalmente la vamos a desarrollar mediante Unity3D y el paquete SDK de realidad aumentada que Vuforia ha hecho especialmente para integrar en este programa, esta no fue nuestra primera opción.

En un principio nuestra idea era desarrollar la aplicación haciendo uso del SDK Metaio, porque es una SDK muy reconocido en el campo de la realidad aumentada, lo que hace que tenga una gran cantidad de documentación. Además que poder usar geolocalización era un extra que aunque no entraba en nuestros planes iniciales, siempre está bien tener nuevas funcionalidades que explorar por si el día de mañana considerábamos una función o comportamiento de nuestro programa que pudiera aprovecharse de ello.

El problema de Metaio vino cuando intentamos realizar la instalación, primero nos descargamos el [Android SDK](http://developer.android.com/sdk/index.html), que ya trae incorporado el software de desarrollo Eclipse con las herramientas necesarias para realizar aplicaciones en Android. Como el proceso de integración de Metaio en Eclipse no era intuitivo, buscamos en diferentes webs de ayuda sobre este SDK como son “[https://dev.metaio.com/](https://dev.metaio.com/)” o “[http://helpdesk.metaio.com/](http://helpdesk.metaio.com/)”, también buscamos videos explicativos, pero después de invertir una gran cantidad de tiempo sin conseguir ningún resultado, decidimos desechar la idea de usar Metaio en nuestro proyecto.

La siguiente opción que consideramos fue que ya que teníamos instalado el IDE Eclipse instalado, buscar otro SDK compatible con este, buscamos otro SDK que también tuviera una gran cantidad de documentación existente, ya que era el primer proyecto que desarrollábamos con realidad aumentada, así que después de considerar varios SDK buscando uno con el que no tuviéramos los mismos problemas que tuvimos con Metaio, decidimos usar Vuforia, otro SDK de realidad aumentada muy extendido.

En este caso la instalación se intuía más sencilla, e incluso en la propia página del SDK se proporcionan ejemplos tanto en código como directamente compilados en un ejecutable APK ([ejemplos](https://developer.vuforia.com/resources/sample-apps)). Los problemas vinieron cuando los propios ejemplos ni compilaban en nuestras máquinas, ni los ejecutables funcionan en nuestros dispositivos Android, nos volvíamos a ver ante la misma situación que con Metaio. Después de investigar en una gran cantidad de páginas web, descubrimos que el fallo de la compilación se podía resolver cambiando la ruta de la librería en los proyectos de los ejemplos, y aunque ahora el proyecto compilaba y generaba un ejecutable, al instalar dicho ejecutable en nuestros smartphones, no obteníamos otra cosa que no fuera un fallo a la hora de iniciar la ejecución del programa.

Estando ya un mes de finalizar el plazo inicial de entrega del proyecto, no conseguíamos ni tener un entorno de desarrollo plenamente configurado y funcionando para realizar nuestra aplicación, por suerte buscando videos en YouTube encontramos un par de videos que explicaban paso a paso como configurar y empezar a desarrollar un sencillo juego usando el SDK de realidad aumentada Vuforia, pero en una plataforma de desarrollo que todavía no habíamos probado, Unity3D (enlace a los videos: [1](http://www.youtube.com/watch?v=0cah165qnis) y [2](http://www.youtube.com/watch?v=tuByRWTVmQI)).
Después de ver estos videos, decidimos probar con Unity3D para comenzar a desarrollar nuestra aplicación, y aunque también encontramos unos cuantos problemas, conseguimos por primera vez algo que no habíamos conseguido antes, obtener un aplicación sencilla que nos permitiera obtener realidad aumentada mediante un modelo 3D que nos habíamos bajado de una web que proporcionaba modelos 3D con licencia de distribución libre y los marcadores de ejemplo que trae el propio Unity3D.

Aun con la ayuda de los videos, el principal problema que hemos tenido ha sido a la hora de crear la interfaz gráfica de nuestra aplicación, ya que como es un juego simple, pensamos inicialmente que todo el juego funcionara alrededor de una misma pantalla, algo que en un principio ni siquiera conseguimos que funcionase al encontrarnos con varios problemas con las llamadas a las propiedades y funciones de la clase GUI, la clase que implementa la API de Unity para definir interfaces gráficas y su comportamiento. Cuando conseguimos tener esa pantalla del juego sin fallos, vimos que ese funcionamiento era poco funcional a la hora de gestionar el propio funcionamiento del juego, como por ejemplo las acciones que se llevan a cabo cuando se acierta o se falla al responder una pregunta.

Finalmente decidimos usar varias pantallas; una para la interfaz de inicio, otra para el desarrollo del juego en sí mismo, las pantallas de acierto y error y finalmente, la pantalla de fin del juego. Se pueden ver cada una de estas pantallas en las siguientes imágenes, hemos incluido varias imágenes de la pantalla del juego para que se vea cómo se comporta la aplicación en función de cómo reconozca el patrón que hace que muestre el modelo 3D.

#### Pantalla de inicio

![img01](imagenes/img01_png)

#### Pantalla del juego reconociendo el patrón a una distancia cercana

![img02](imagenes/img02_png)
 
#### Pantalla del juego reconociendo el patrón a una distancia más lejana.

![img03](imagenes/img03_png)

#### Pantalla del juego reconociendo el patrón con otra orientación.
 
![img04](imagenes/img04_png)

#### Pantalla de respuesta acertada 

![img05](imagenes/img05_png)

#### Pantalla de respuesta errónea

![img06](imagenes/img06_png)

#### Pantalla de fin del juego

![img07](imagenes/img07_png)

A primera vista podemos ver la sencillez de la interfaz del juego, lo cual era uno de nuestros objetivos, haciendo que la mecánica del juego sea muy fácil; cuando la cámara de nuestro móvil enfoca al patrón, la aplicación lo reconoce y automáticamente genera el modelo 3D en la pantalla de nuestro móvil, en función de la orientación y la distancia entre la cámara y el patrón, vemos que el modelo se mostrará en una posición u otra, con un tamaño menor o mayor, y seguidamente mostrando en pantalla la pregunta a formular y las posibles respuestas.

Empezamos el juego con 5 oportunidades (nuestras 5 vidas que se indican en la parte superior), por cada acierto se nos avisará por pantalla que hemos acertado, aumentará el marcador de aciertos de la parte superior izquierda y se pasará a la próxima pregunta; si se falla al elegir la respuesta a la pregunta, la aplicación también nos muestra una pantalla indicativa, se nos resta una de nuestras “vidas” y se pasa a la siguiente pregunta. El juego finalizará cuando nos quedemos sin ninguna vida.


## Conclusiones

Una vez que hemos finalizado la aplicación, lo primero que vemos es que algo que en principio parecía muy fácil, se terminó convirtiendo un problema bastante complejo donde llegaban momentos en los que no sabíamos por dónde continuar en la búsqueda de soluciones, seguramente si no fuera por la gran cantidad de documentación que hemos encontrado por Internet y por la gran cantidad de tiempo dedicada al desarrollo de la aplicación, no hubiéramos obtenido una aplicación funcional. El problema es que como los buenos resultados han terminado llegando ya acercándose la fecha de entrega, no hemos podido hacer una aplicación tan completa como describíamos al principio, que es lo que hubiéramos deseado, pero si nos ha permitido sentar las  bases de lo que podría  ser un proyecto interesante a desarrollar.

Aun así, toda la cantidad de tiempo invertida en el desarrollo de la aplicación, nos ha permitido conocer y adquirir experiencia a la hora de desarrollar este tipo de aplicaciones, lo que era una de nuestras principales motivaciones a la hora de comenzar con el desarrollo. Por todo esto podemos decir que hemos quedado satisfechos con el resultado obtenido de nuestro trabajo con esta aplicación.


## Trabajo futuro

Aunque nosotros hemos desarrollado nuestra aplicación con la intención de que sea un juego, también tiene se puede considerar que tiene un marcado carácter educativos, sobre todo si la persona que juego es de corta edad, ya que se puede crear un entorno divertido y didáctico en el que algún personaje atractivo para el usuario le puede hacer preguntas y comentar datos interesantes sobre el tema tratado llamando su atención más que en otros entornos educativos más convencionales.

Hoy en día las aulas están más informatizadas, así que no sería de extrañar en un futuro próximo, que se extendiera el uso de aplicaciones con características similares a la nuestra en las escuelas, desde nivel preescolar o primario, con dos objetivos, facilitar el aprendizaje de los niños con nuevos métodos pedagógicos basados en la informática por un lado, y que desde su infancia se vayan familiarizando con las nuevas tecnologías que cada vez les serán más necesarias.

Pero igual que podríamos presentar nuestro proyecto con una orientación docente, también se podría presentar en el mismo campo del ocio, pero en otro ambiente, como pueden ser espacios como museos, en los que juegos como este se podrían usar para hacer más amenas las visitas a los turistas, pudiendo conseguir ser especialmente llamativo para un público que no frecuenta estos espacios por considerarlos poco llamativos o aburridos, conseguir darle otro enfoque a lo que se tiene considerado una visita a un museo.


## Bibliografía

[http://developer.android.com/sdk/index.html#win-bundle](http://developer.android.com/sdk/index.html#win-bundle)
[http://ingcarlosreina.inkframe.com/realidad-aumentada/sdk-para-realidad-aumentada-en-ios-y-android](http://ingcarlosreina.inkframe.com/realidad-aumentada/sdk-para-realidad-aumentada-en-ios-y-android)
[http://jstyl8.blogspot.com.es/2012/02/android-vuforia-realidad-aumentada.html](http://jstyl8.blogspot.com.es/2012/02/android-vuforia-realidad-aumentada.html)
[http://spanish.unity3d.com/unity/download](http://spanish.unity3d.com/unity/download)
[http://trinit.es/2010/10/22/tutorial-de-unity3d-en-espanol](http://trinit.es/2010/10/22/tutorial-de-unity3d-en-espanol)
[https://developer.vuforia.com/resource/dev-guide/getting-started](https://developer.vuforia.com/resource/dev-guide/getting-started)
[https://developer.vuforia.com/resource/sdk/android](https://developer.vuforia.com/resource/sdk/android)
[https://developer.vuforia.com/resources/sample-apps](https://developer.vuforia.com/resources/sample-apps)
[https://play.google.com/store/apps/category/BRAIN](https://play.google.com/store/apps/category/BRAIN)
[https://play.google.com/store/apps/details?id=aul.irm.triviados#?t=W251bGwsMSwxLDIxMiwiYXVsLmlybS50cml2aWFkb3MiXQ..](https://play.google.com/store/apps/details?id=aul.irm.triviados#?t=W251bGwsMSwxLDIxMiwiYXVsLmlybS50cml2aWFkb3MiXQ..)
[https://play.google.com/store/apps/details?id=aul.irm.triviados&feature=search_result](https://play.google.com/store/apps/details?id=aul.irm.triviados&feature=search_result)
[https://play.google.com/store/apps/details?id=com.diablins.android.bluzztrivialminds2#?t](https://play.google.com/store/apps/details?id=com.diablins.android.bluzztrivialminds2#?t
=W251bGwsMSwxLDIxMiwiY29tLmRpYWJsaW5zLmFuZHJvaWQuYmx1enp0cml2aWFsbWluZHMyIl0.](=W251bGwsMSwxLDIxMiwiY29tLmRpYWJsaW5zLmFuZHJvaWQuYmx1enp0cml2aWFsbWluZHMyIl0.)
[https://play.google.com/store/apps/details?id=com.jjvaca.trivial#?t=W251bGwsMSwxLDIxMiwiY29tLmpqdmFjYS50cml2aWFsIl0.](https://play.google.com/store/apps/details?id=com.jjvaca.trivial#?t=W251bGwsMSwxLDIxMiwiY29tLmpqdmFjYS50cml2aWFsIl0.)
[https://play.google.com/store/apps/details?id=com.novagecko.quizture.movies#?t=W251](https://play.google.com/store/apps/details?id=com.novagecko.quizture.movies#?t=W251](bGwsMSwxLDIxMiwiY29tLm5vdmFnZWNrby5xdWl6dHVyZS5tb3ZpZXMiXQ..)
[https://play.google.com/store/apps/details?id=erseco.soft#?t=W251bGwsMSwxLDIxMiwiZXJzZWNvLnNvZnQiXQ..](https://play.google.com/store/apps/details?id=erseco.soft#?t=W251bGwsMSwxLDIxMiwiZXJzZWNvLnNvZnQiXQ..)
[https://play.google.com/store/search?q=realidad+aumentada&c=apps](https://play.google.com/store/search?q=realidad+aumentada&c=apps)
