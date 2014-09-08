Sistemas Operativos
===================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Configuración y compilación de un kernel de Linux
## David Bustos García
## Germán Martínez Maldonado
## José Rubén Sánchez Iruela
## Pablo Sánchez Robles

## 1. Opciones de configuración del kernel del Linux

Aquí vamos a listar las opciones más importantes de configuración del kernel de Linux que se muestran cuando ejecutamos “make config” o “make menuconfig” o “make xconfig”. Las opciones y ayuda que se van a mostrar son las que vienen en el libro “Greg Kroah-Hartman, Linux Kern el in a Nutshell, O'Reilly, 2007”, que a su vez están basadas en la ayuda que los desarrolladores del kernel escribieron. A continuación mostraremos los grupos de opciones más importantes que podemos encontrarnos a la hora de compilar el kernel:

* **EXPERIMENTAL**: Muchas de las cosas que Linux soporta (tanto drivers de red, sistemas de ficheros, protocolos de red, etc.) pueden estar aún en desarrollo ya que la funcionalidad, estabilidad o el nivel de prueba no es lo suficientemente alto para el uso general. Esto es conocido normalmente como alpha-test, y en esta opción se incluyen todas las opciones en proceso de desarrollo.

* **LOCALVERSION**: Esto le permite añadir una cadena adicional al final de su versión del núcleo. Esto se mostrará cuando se introduce un comando uname, por ejemplo. La cadena que se establezca aquí se añadirá después de que el contenido de cualquier archivo con un nombre que comience por LOCALVERSION en su objeto y el árbol de código fuente, en ese orden. La cadena puede ser un máximo de 64 caracteres.

* **AUDIT**: Activa la infraestructura de audición que puede ser usada con otro subsistema, así como SELinux (el cual requiere esto para el registro de control automático de volumen de salida de mensajes).

* **IKCONFIG**: Esta opción permite al kernel de Linux completar el contenido de los archivos de configuración.

* **EMBEDDED**: Esta opción permite ciertamente que algunas de las opciones y configuraciones del kernel puedan ser desactivadas o ajustadas. Esto es para entornos especializados que puedan tolerar un kernel no estándar. Esta opción es solo recomendada para usuarios expertos.

* **MODULES**: Los módulos del kernel son pequeñas piezas de código compilado que pueden ser insertadas en la ejecución del kernel, en lugar de estar permanentemente incorporadas en el kernel.

* **SMP**: Esta opción activa el soporte para sistemas con más de una CPU.

* **X86_GENERIC**: En lugar de utilizar simplemente como optimizaciones para la variante x86 seleccionada, se incluyen también algunas optimizaciones más genéricas.

* **NR_CPUS**: Esto te permite especificar el número máximo de CPUs que este kernel puede soportar. Debe estar en un rango entre 2 y 255.

* **NOHIGHMEM**: Linux puede usar 64GB de memoria física en sistemas x86, aunque el límite máximo para esos sistemas sea solo 4 GB.

* **PM**: “Power Management”, o administrador de energía, permite que partes de tu ordenador se apaguen o se pongan en un estado de ahorro de energía si dichas partes no son utilizadas.

* **SOFTWARE_SUSPEND**: Permite activar la suspensión de la máquina, guardando toda la misma en una imagen del swap.

* **ACPI**: Advanced Configuration and Power Interface, o configuración avanzada e interfaz de energía, soporte para Linux que requiere que el hardware y el firmware sean compatibles con ACPI.

* **CPU_FREQ**: Permite cambiar la velocidad del reloj del sistema. Esto puede ahorrar energía, porque cuanto menor sea la velocidad menos energía consume la CPU.

* **PCMCIA**: Esta opción activa el soporte para tarjetas de 16 bits PCMCIA.

* **CARDBUS**: Esta opción activa el soporte para tarjetas de 32 bits CARDBUS.

* **NET**: Activa o desactiva el soporte de red.

* **Unix**: Activa o desactiva el soporte para conexiones con los dominios UNIX. Son mecanismos para establecer y acceder a las conexiones de red.

* **BT**: Permite el soporte de subsistemas por bluetooth.

Estas son algunas de las muchas opciones que el kernel de Linux permite seleccionar a la hora de la compilación del mismo, hay muchas opciones más que no hemos incluido por no extendernos demasiado. Las  5  opciones  que  seleccionaremos  serian  aconsejables  para  servidores  porque  ayudarían  al  mejor funcionamiento de estos, así como para el ahorro de energía y el mayor aprovechamiento de los recursos de los que se puedan disponer:

* **NR_CPUS**: Ya que con esto podemos aumentar el número de procesadores que puede usar el servidor, para mejorar el rendimiento.

* **NOHIGHMEM**:  desactivamos  con  esto  el  límite  impuesto  de  4  GB  de  memoria  física  máxima pudiendo incluir hasta 64 GB a nuestro servidor.

* **CPU_FREQ**: Con esta opción podemos ahorrar energía en nuestro servidor o aumentar la potencia haciendo overcloking.

* **PM**: Como la opción anterior también nos sirve para ahorrar energía si en algún momento hay alguna parte de nuestro servidor que no está en uso y queremos desactivar momentáneamente.

* **NET**: Esta opción la debemos tener activada ya que un servidor ha de estar siempre conectado a una red, porque si deja de estar en conexión el servicio que ofrece se desactivará.

## 2. Herramientas para facilitar la compilación de un kernel de Linux

Al igual que existen diversos pasos a seguir para compilar un kernel de Linux, existen diversas herramientas que nos ayudaran en gran medida para realizar esta tarea, no todas las herramientas son compatibles con todas las distribuciones, así que nos basaremos en las herramientas disponibles para compilar el kernel desde un distribución Ubuntu en su última versión disponible 11.10 (Oneiric Ocelot), herramientas que se pueden usar también en todas las distribuciones basadas en Debian.

**fakeroot:**
Herramienta que nos permitirá usar un entorno que hará creer a nuestro sistema que disponemos de privilegios superusuario aunque esto no sea así, esto nos será útil para cuando tengamos que modificar archivos del sistema, y así compilar nuestro nuevo kernel.
Dependencias: libc6

**build-essential:**
Herramienta que contiene una lista con los paquetes esenciales para la creación de paquetes Debian, necesarios para cuando queramos reconstruir los paquetes de nuestro kernel.
Dependencias: dpkg-dev, g++, gcc, libc-dev, libc6-dev, make

**crash:**
Herramienta que permite realizar depuración del kernel, cuenta con una sintaxis parecida a la de
otras herramientas de depuración más comunes, como es el caso  del gdb.
Dependencias: libc6, libncurses5, zlib1g

**kexec-tools:**
Herramienta que proporciona las utilidades necesarias para cargar un kernel en memoria y reiniciar directamente en el kernel que realizó la llamada a kexec, sin tener que realizar un proceso de arranque normal.
Dependencias: debconf, debconf-2.0, initramfs-tools, libc6

**makedumpfile:**
Herramienta con la que podremos extraer un subconjunto de la memoria disponible a través de
/dev/mem y /proc/vmcore (para crush dump, volcados de memoria que se producen cuando la ejecución de un programa es abortada). Es utilizado para obtener imágenes de memoria sin también tener que copiar información adicional que nos resulte innecesaria (direcciones de memoria indicadas como zero pages, programas del espacio de usuario, etc.).
Dependencias: libc6, libdw1, libelff1, perl, zlib1g

**kernel-wedge:**
Herramienta para extraer de un paquete de imagen del kernel un paquete udeb, micro paquetes principales deb, usados normalmente sólo para el arranque de una instalación Debian.
Dependencias: debhelper, make

**git:**
Herramienta  de  control  de  versiones  diseñado  para  manejar  proyectos  muy  grandes  con
velocidad y eficiencia, como sobre todo para nuestro caso, el kernel de Linux.
Dependencias: git-man, libc6, libcurl3-gnutls, liberror-perl, libexpat1, perl-modules, zlib1g

**binutils:**
Herramienta de GNU para ensamblar, enlazar y manipular archivos y objetos binarios. Puede ser usado en conjunto con un compilador y varias bibliotecas para construir programas.
Dependencias: libc6, libgcc1, libstdc++6, zlib1g

## 3. Pasos para la compilación de un kernel de Linux

### 1.1. Obtener el código fuente

Antes de nada comprobaremos si tenemos la última versión del núcleo utilizando  la orden la “uname –sr”. Si no es el más actual, debemos descargar la versión más actual en /usr/src. A continuación debemos crear un directorio para el código fuente del kernel y crear un enlace a este directorio.

### 1.2. Preparar el árbol de archivos del código fuente

Construiremos el árbol de archivos del código fuente para poder utilizarlo. La orden para hacerlo va a depender del formato del archivo que hayamos descargado. El archivo con el código fuente puede tener el formato .tar.gz ó tar.bz2.

Si el archivo tiene el formato .tar.gz, la orden que debemos de utilizar es:
`% tar xzfv linux-2.4.22.tar.gz`
Para el formato tar.bz2 utilizaremos
`% bzcat linux-2.4.22.tar.bz2 | tar xv`
o bien
`% tar xvfj linux-2.4.22.tar.bz2`

Ahora, cambiaremos al directorio (cd linux). Para comenzar el proceso de compilación de un nuevo kernel es necesario ejecutar la siguiente orden: % make mrproper que configura el entorno para el kernel.

### 1.3. Configurar el código fuente

Configuramos las opciones deseadas para nuestro nuevo kernel, los tres métodos alternativos para la configuración son:

```
% make config
% make menuconfig
% make xconfig
```

Los tres métodos realizan la misma tarea, crear el archivo .config, pero lo hacen de tres formas diferentes:

* La primera, make config, es un script secuencial de texto que nos solicitando las diferentes opciones, en el que el principal inconveniente es que no podemos retroceder.
* La segunda, make menuconfig, ya no es un script secuencial y no depende tampoco de ningún entorno de ventanas. Presenta un tipo especial de ventanas, denominadas ncurses o curses, si tenemos instalada la biblioteca ncurses.
* El último método, make xconfig, es el más fácil pues solo debemos seleccionar con el ratón los parámetros deseados pero para su uso debemos tener instalado el entorno de ventanas.

Sea cual sea el método, indicar que existen muchas opciones posibles. (General Configuration “PCI, Sysctl, Kernel core”, Block devices, SCSI, Mouse, Character, Filesystems, Console drivers…)

### 1.4. Construir el kernel a partir del código fuente e instalar los módulos

Una vez definida la configuración, debemos realizar los siguientes pasos:

```
% make dep
% make clean
% make [ bzImage | bzdisk | bzlilo ]
% make modules
% make modules_install
```

El primer paso crea los archivos de dependencias entre componentes. El segundo eliminará los pasos no finalizados de construcciones previas para que no interfieran con la actual. La orden 3 construye la parte estática del kernel y existen tres posibilidades. La orden 4 construye los módulos de carga dinámica para aquellas partes que se indicaron como tales en la configuración con “m”. La última orden mueve los módulos a su ubicación final.

### 1.5. Reubicar el kernel

Una vez creado el kernel, debemos dejarlo en el directorio adecuado. Actualmente, se está abandonando la política de situarlo en el directorio raíz, y se tiene a ubicarlo en el directorio /boot, junto con el archivo del mapa del kernel. Para ello, solo debemos ejecutar una simple copia:

```
% cp System.map /boot/System.map-2.4.YY
% cp arch/i386/boot/bzImage /boot/bzImage-2.4.YY
```

### 1.6. Configurar y ejecutar LILO

Damos aquí este paso por completitud, ya que en los equipos de la Escuela no es necesario ya que utilizamos un cargador especial, denominado Rembo.

El cargador de arranque nos permitirá especificar varias imágenes de arranque. Si el cargador es LILO, podemos insertar otra imagen de arranque insertando otra sección en el archivo /etc/lilo.conf. Por ejemplo, un ejemplo del contenido de este archivo es:

```
boot=/dev/sda
map=/boot/map
install=/boot/boot.b
prompt
timeout=50
message=/boot/message 
linear
default=linux
image=/boot/vmlinuz-2.4.2-2
label=linux
initrd=/boot/initrd-2.4.2-2.img
read-only
root=/dev/sda5
```

Para añadir una nueva imagen, debemos copiar la entrada image (5 últimas líneas) y la etiqueta label para que contenga el nombre de la nueva imagen. Ahora, tendremos:

```
boot=/dev/sda
map=/boot/map
install=/boot/boot.b
prompt
timeout=50
message=/boot/message
linear
default=linux
image=/boot/vmlinuz-2.4.22
label=linux
initrd=/boot/initrd-2.4.22.img
read-only
root=/dev/sda5
image=/boot/vmlinuz-2.4.2-2.viejo
label=linux.viejo
initrd=/boot/initrd-2.4.2-2.img
read-only
```

Después de esta configuración, debemos volver a instalar el cargador de arranque con:

```
% lilo
Added linux *
Added Linux.viejo
```

Ya podemos reiniciar el sistema bien con el nuevo kernel bien con el anterior, dependiendo de la opción (nombre de la etiqueta) que le demos a LILO. Si nos fijamos en la configuración, aparece la entrada initrd=/boot/initrd-2.4.22.img. La opción initrd se utiliza en aquellos casos que es necesario instalar ciertos manejadores de dispositivos antes de iniciar el arranque propio del kernel. Esto ocurre cuando por ejemplo arrancamos en modo gráfico.

### 1.7. Verificar el soporte de módulos

Deberemos comprobar que el archivo /etc/modules.conf contiene los módulos que  deseamos cargar en el arranque del sistema.

### 1.8. Reiniciar el sistema y probar el nuevo kernel

El último paso será reiniciar el sistema para comprobar que el nuevo kernel  funciona correctamente.


## 4. Parámetros del kernel ajustables en tiempo de carga

* Opciones de consola**: Estas opciones hacen referencia al registro de la consola o el nucleó, donde se muestra la depuración del kernel.
* Opciones de interrupción**: El tiempo de las opciones de arranque que hacen referencia a la interfaz entre el kernel y el hardware que se encarga de las interrupciones.
* Opciones de memoria**: Estas opciones le permiten ajustar el tamaño y la configuración de las distintas zonas de memoria.
* Opciones para suspender el equipo**: Opciones para cambiar la forma en que el kernel maneja la suspensión para fines de ahorro de energía.
* Opciones de CPU**: Estas opciones hacen referencia al comportamiento en relación con el tiempo y uso del procesador en sistemas multiprocesadores. También hacen referencia a otros problemas del procesador.
* Opciones de planificado**r: Estas opciones hacen referencia a las decisiones de planificación. Son bastante complejas y se necesitan un amplio conocimiento de la planificación en Linux para su modificación.
* Opciones de memoria virtual**: Estas opciones controlan como se lleva a cabo el almacenamiento de información en memoria virtual. Incluyendo también algunas zonas que contienen información necesaria en algunas etapas del arranque.
* Opciones de la raíz del disco**: Estas opciones controlan como el núcleo gestiona el sistema de archivos que contiene el sistema de ficheros raíz.
* Opciones de inicio**: El proceso init es el primero en ser iniciado por el nucleó y el padre de todos los demás procesos que vengan a continuación de este. Estas opciones controlan los programas que se ejecutan y como se ejecutan.
* Opciones Kexec**: El subsistema de kexec es una función especializada, que permite  hacer  un reinicio rápido y normalmente se combina con Kdump que permite guardar la memoria del kernel a un lugar seguro para un posterior análisis. Estas opciones nos permiten modificar los parámetros de Kexec.
* Opciones RCU**: Es una parte del núcleo que se encarga de la exclusión mutual para que en el sistema no haya bloqueo.
* Opciones ACPI**: Estas opciones controlan los parámetros de la  ACPI que el subsistema puede usar.
* Opciones SCSI**: Estas opciones especifican los diferentes parámetros de SCSI que el subsistema puede usar.
* Opciones PCI**: Estas opciones controlan los parámetros de la PCI que el subsistema puede usar.
* Opciones Plug and Play BIOS**.
* Opciones SELinux**: Estas opciones cargan algunos aspectos fundamentales del inicio de SELinux.
* Opciones de red**: Son opciones de control de bajo nivel referentes a la red del subsistema.
* Opciones de red del sistema de archivo**s: Estas opciones controlan el arranque NFS.
* Opciones   especificas   del   hardware**:   Estas   opciones   especifican   los   distintos   parámetros, dependiendo del hardware disponible en el sistema.
* Opciones específicas de temporización**: Estas opciones tienen prioridad sobre el comportamiento por defecto del kernel para arreglar problemas con ciertos chips.
* Opciones varias**: Estas opciones están siempre disponibles y no dependen de ningún subsistema específico o hardware.

Hay algunas opciones más, si se quiere ver por completo todas ellas, se puede consultar el fichero Documentation/kernel-parameters.tx en el directorio del kernel y los parámetros específicos de cada opción.

Vistas todas las opciones anteriores de configuración, podemos considerar especialmente importantes las 5 siguientes:

* **init**: Esta opción establece el programa inicial que ejecutara el núcleo, por defecto se usa /sbin/init, que es el padre de todos los procesos. Para arrancar el sistema sin password: `init=/bin/bash`

* **root=/dev/device**: Este argumento le dice al núcleo que dispositivo será utilizado como sistema de ficheros raíz al arrancar: `root=/dev/sda1`

* **panic=SECOND**: Especifica el comportamiento del núcleo en estado de pánico. Por defecto no se reinicia después de uno de estos ataques, pero con la opción que le hemos puesto, después de un ataque se reiniciara en 10 segundos: `panic=10`

* **maxcpus=NUMBER**: Especificamos el número máximo de CPUs que deseamos que el kernel haga uso.  Por  ejemplo  si  tenemos  4  procesadores  y  queremos  utilizar  2,  pondríamos  lo  siguiente: `maxcpus=2`

* **mem=MEMEORY_SIZE**:  Podemos  especificar  la  cantidad  máxima  de  memoria  que  se  utilizara: `mem=1024M`


## 5. Bibliografía:

### 5.1 Opciones de configuración del kernel del Linux
**Greg Kroah-Hartman, Linux Kern el in a Nutshell, O'Reilly, 2007.**

### 5.2 Herramientas para facilitar la compilación de un kernel de Linux
* [https://help.ubuntu.com/community/Kernel/Compile](https://help.ubuntu.com/community/Kernel/Compile)
* [http://packages.debian.org/es/squeeze/fakeroot](http://packages.debian.org/es/squeeze/fakeroot)
* [http://packages.debian.org/es/squeeze/build-essential](http://packages.debian.org/es/squeeze/build-essential)
* [http://packages.debian.org/es/squeeze/crash](http://packages.debian.org/es/squeeze/crash)
* [http://packages.debian.org/es/squeeze/kexec-tools](http://packages.debian.org/es/squeeze/kexec-tools)
* [http://packages.debian.org/es/squeeze/makedumpfile](http://packages.debian.org/es/squeeze/makedumpfile)
* [http://packages.debian.org/es/squeeze/git](http://packages.debian.org/es/squeeze/git)
* [http://packages.debian.org/es/squeeze/binutils](http://packages.debian.org/es/squeeze/binutils)
* [http://en.wikipedia.org/wiki/Zero_page](http://en.wikipedia.org/wiki/Zero_page)
* [http://en.wikipedia.org/wiki/Deb_(file_format)](http://en.wikipedia.org/wiki/Deb_(file_format)

### 5.4 Parámetros del kernel ajustables en tiempo de carga
**Greg Kroah-Hartman,Linux Kern el in a Nutshell, O'Reilly, 2007. Capitulo 9.**
