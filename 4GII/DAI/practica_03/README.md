Diseño de Aplicaciones para Internet
====================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Formularios “Avanzados”, Templates, Manejo de Sesiones y Persistencia
### Germán Martínez Maldonado

### Resumen
En esta práctica avanzaremos en el uso de web.py: aprenderemos a usar las opciones de validación de formularios, usaremos plantillas (tem- plates) para generar cómodamente nuestro código, utilizaremos sesiones para gestionar la identificación de usuarios en la web y otros posibles datos de sesión de nuestra aplicación web y, por último, veremos como gestionar la persistencia usando diversas bases de datos.

### 1. Formularios  “Avanzados”
En la práctica anterior empezamos a manejar la sub-biblioteca Form de web.py para manejar formularios. Dicha biblioteca contiene opciones interesantes que pueden facilitarnos el introducir información en una página web, así como su posterior manejo. En este punto de la práctica vamos realizar un formulario algo más complejo que los vistos hasta ahora:

* El formulario debe preguntar los siguientes datos personales a los usuarios de la web: nombre, apellidos, DNI, correo electrónico, fecha de nacimiento, dirección, contraseña, verificación de la contraseña, forma de pago preferida (contra reembolso o tarjeta VISA), número de la tarjeta VISA, aceptación de las clausulas de protección de datos, botón de mandar.

* Los campos del formulario deben ser del tipo:
 * Nombre, apellidos, correo electrónico, número de VISA: textbox.
 * Fecha de nacimiento: dropdown (x3, día, mes, año).
 * Dirección: textarea.
 * Contraseña y verificación: password.
 * Forma de pago: radio.
 * Aceptación clausulas: checkbox.
 * Botón: button.

* El formulario debe verificarse utilizando los mecanismos de la biblioteca para ello (validators). Probablemente haga falta utilizar alguna función lambda de Python. Particularmente hay que asegurarse de que:
 * Ningún campo de texto esté vacío
 * El correo electrónico sea “válido”
 * Que el número de la tarjeta VISA sea correcto (4 grupos de 4 dígitos separados por un espacio o -).
 * Que la fecha de nacimiento sea una fecha válida.
 * Que la contraseña y su validación coincidan y tengan más de 7 caracteres.
 * Que la clausulas se hayan aceptado.


### 2. Plantillas  (templates)

Cuando desarrollamos una aplicación web (por ejemplo con web.py) no es buena idea incluir el código HTML de las páginas dentro de nuestra aplicación Python. Utilizando plantillas (templates) conseguiremos simplificar mucho todas las tareas repetitivas, así como separar correctamente el aspecto de la aplicación (vista) de su lógica interna (controlador).

Una biblioteca potente de templates para Python es Mako utilizada en sitios masivos en producción como [http://reddit.com](http://reddit.com). En esta práctica vamos a familiarizarnos con esta biblioteca. Para ello tendremos que construir varias páginas usando esta biblioteca.

Dichas páginas deberán mostrar un sitio web en el que haya (al menos) una cabecera, dos columnas y un pie de página. En la cabecera habrá una imagen de logo del sitio, el nombre del mismo, un subtítulo y un mini-formulario de login. En la columna izquierda habrá opciones (como por ejemplo menús), la columna de la derecha contendrá el cuerpo principal de la página y el pie contendrá información sobre el autor de la página y los derechos de la misma (licencia). En caso de no querer hacer el diseño de la página desde cero, podemos optar por descargar alguna plantilla web ya creada y adaptarla para poder presentar los contenidos dinámicos de la aplicación.

Debemos intentar seguir el paradigma modelo, vista, controlador lo más fielmente posible, de tal manera que sea posible, por ejemplo, cambiar radicalmente el aspecto de la aplicación web modificando únicamente los templates.


### 3. Manejo de Sesiones

En toda aplicación web es necesario gestionar información que se mantenga entre las distintas páginas que visita el usuario. Para ello se hace uso de las sesiones. En web.py las sesiones se manejan mediante la clase Session.

En esta práctica adaptaremos nuestra página web para que el formulario de login anteriormente citado funcione correctamente y se muestre distinto con- tenido si el usuario está ya identificado o no (a esta alturas la comprobación del usuario estará codificada “a pelo” en la aplicación, en el siguiente apartado guardaremos distintos usuarios usando persistencia). Por ejemplo, el formulario de login de la cabecera solo debe aparecerle a los usuario no identificados, mien- tras que a los identificados debe mostrárseles el típico mensaje de “Bienvenido xxxx” y un enlace para hacer logout.

Además, implementaremos en nuestra aplicación (y utilizando exclusiva- mente sesiones) un “menu” que muestre -y permita acceder- a las últimas 3 páginas del sitio visitadas (lo podemos incluir en el menú de la izquierda).


### 4. Persistencia

#### 4.1. Persistencia Sencilla: dbm

Para almacenar la información de nuestra aplicación podemos utilizar distintos mecanismos de persistencia. Cuando la aplicación sea suficientemente sencilla podemos utilizar algún esquema de almacenamiento local, como por ejemplo la biblioteca dbm o anydbm.

En esta práctica usaremos dicha base de datos para almacenar la información del formulario de datos de usuario de la sección 1 una vez haya sido validada. Crearemos una página nueva de nuestra aplicación que nos permita visualizar los datos del usuario (tendremos acceso a través del menú a esta página cuando estemos identificados en la web). Asimismo crearemos una nueva página que le permita al usuario cambiar los datos personales (volviendo a mandar el formulario, que aparecerá relleno con los datos anteriores).

#### 4.2. Persistencia NO-SQL: MongoDB

MongoDB es una base de datos NO-SQL potente que nos permitirá almacenar cualquier información que nuestra aplicación web necesite.

Copia y modifica la aplicación de la sección 4.1 para usar la base de datos MongoDB usando la biblioteca Pymongo.

Nota: A partir de este práctica continuaremos trabajando con esta versión de la aplicación web.
