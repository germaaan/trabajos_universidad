Tecnologías Web
===============
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Análisis del fichero de configuración del servidor Apache
### Germán Martínez Maldonado

El archivo **“httpd.conf”** es el archivo principal de configuración del servidor Apache, al inicio de dicho archivo nos da información sobre el propio y otros archivos de configuración, como son los archivos de los puertos de escucha de conexiones entrantes (**“ports.conf”**, incluido en el propio archivo de configuración principal) o las configuraciones de módulos o host virtuales (los archivos en los directorios **“mods-enabled/”** u **“sites-enabled/”** respectivamente).

Una vez ya en las directivas de configuración, la primera que nos encontramos es **“ServerRoot”**, podemos considerarla la más importante, ya que indica la raíz de la jerarquía de directorios bajo la que se van a encontrar todos los archivos de configuración y  demás aspectos del servidor. Se considerará por defecto la ruta **“/etc/apache2”**, por eso la línea que define esta directiva viene comentada.

Hay otras directivas que aunque pueden ser cambiadas, se recomienda que se deje su valor por defecto, por eso vamos a centrarnos en las que sus valores si se pueden modificar de forma más libre:

* **Timeout**: número de segundos a esperar antes de responder **“Tiempo de espera agotado”**. Por defecto son 300 segundos.
* **KeepAlive**: permitir o no permitir conexiones persistentes, que consisten en permitir más de una petición por conexión. Por defecto activada con valor **“On”**, se puede desactivar indicando un valor **“Off”**.
* **MaxKeepAliveRequests**: el máximo número de peticiones permitidas durante una conexión persistente. Si se indica el valor 0, el número de peticiones será ilimitado. Aun así, nos recomiendan dejar el valor por defecto 100, para así tener un mayor rendimiento.
* **KeepAliveTimeou**t: número de segundos a esperar para la próxima solicitud del mismo cliente en la misma conexión. Por defecto es 5.

Después de las directivas listadas arriba, nos encontramos la configuración de los módulos de multiprocesamiento (MPM), por defecto la configuración de los módulos incluidos es:

* **prefork**: módulo que implementa un servidor web no hebrado encargado de gestionar peticiones, el mejor para la separación de peticiones y que los problemas con una petición no afecten a otra.
* **worker**: módulo que implementa un servidor hibrido multiproceso y multihebra, al usar múltiples hebras puede  atender un  gran número de peticiones con menores recursos que si solo usara procesos para tal fin, en su lugar usa los procesos para mantener las múltiples hebras.
* **event**: módulo basado en el módulo **“worker”** con la misma funcionalidad, pero cuyo funcionamiento consiste en pasar un poco de trabajo de las hebras principales a las hebras de soporte, para que así las hebras principales puede trabajar en nuevas solicitudes.
Los parámetros configurables en los módulos son muy parecidos, la diferencia radica en que para **“prefork”** configuramos en base a servidores, mientras que en **“worker”** y **“event”** configuramos en base a hebras. Esto lo podemos ver en parámetros como **“MinSpareServers”** que indica el número mínimo de procesos servidor que se tienen que mantener de repuesto y **“MinSpareThreads”** que indica el número mínimo de procesos worker que se tienen que mantener de repuesto, pero también coinciden en otros como **“StartServers”** que indica el número inicial de procesos servidor a iniciar o **“MaxClients”** que indica el número máximo de conexiones simultaneas de clientes.

Otra directiva importante es **“AccessFileName”** que indica el nombre del fichero a buscar en cada uno de los directorios de la jerarquía que puede contener directivas de configuración adicional, por defecto será **“.htaccess”**.

También destacar las directivas relacionadas con los archivos de registro como son:

* **ErrorLog**: indica la ruta del archivo de registro de errores.
* **LogLevel**: indica el nivel de detalle al que se va a llegar en el archivo de registro de errores, siendo posible: debug, info, notice, warn, error, crit, alert, emerg.
* **LogFormat**: indica el formato de los nombres de otros archivos de registros.

Finalmente, solo añadir la directive **“Include”** que es la que va a indicar otros archivos de configuración que se van a incluir en la configuración de Apache, como son los archivos antes mencionados **“ports.conf”**, **“mods-enabled/*.load”** y **“mods-enabled/*.conf”** o directamente todos los contenidos en los directorios **“conf.d/”** o **“sites-enabled/”**.
