Ingeniería de Servidores
=========================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Práctica 1: Virtualización e instalación de sistemas operativos
### Germán Martínez Maldonado


## 1) Conceptos de máquinas virtuales y virtualización

### Cuestión 1: ¿Qué es una máquina virtual?

Es un software qe nos permite emular el hardware de un ordenador, haciendo posible ejecutar sistemas operativos y programas sobre ese hadware ficticio como si fuera uno real.

### Cuestión 2: ¿Qué modos de “virtualizar” se pueden implementar?

Existen dos tipos de virtualización:

* Virtualización total, que consiste en emular de forma completa el hardware de un sistema, siendo implementados con hipervisores que son ejecutados directamente en el hardware.

* Paravirtualización, que consiste en emular un sistema equivalente al hardware de un sistema, siendo implementado por otro tipo de hipervisores que son ejecutados a un nivel superior de un sistema operativo tradicional.

### Cuestión 3: ¿Qué son IVT y AMD-V?

IVT (Inter Virtualization Technology) es la tecnología de Intel que proporciona las extensiones de virtualización de hardware de arquitecturas x86.

AMD-V (AMD Virtualization) es la tecnología de AMD que proporciona las extensiones de virtualización de hardware de arquitecturas x86.


## 2) Software para virtualización: VMWare y VirtualBox

### Cuestión 4: Comente qué otros productos ofrece VMWare y su diferencia con Player

Además de Player, VMWare ofrece otros productos de virtualización: Workstation (de pago, al contrario de Player), Server (también gratuita, pero sin soporte oficial en la actualidad) y Fusion (la versión de pago compatible con Mac). De todos estos productos el más extendido es Workstation, del que destacan las siguientes diferencias:

* Menor cantidad máxima de RAM o de memoria virtual en Player que en Workstation.
* Workstation permite conectarse de forma remota a las máquinas virtuales del programa.
* Con Player no podemos guardar el estado actual de nuestra máquina virtual, con Workstation podemos realizar estas instantáneas, para realizar cambios en nuestro sistema, siempre pudiendo volver al estado previamente salvado.

### Cuestión 5: VMWare y VirtualBox. ¿Cuál es la diferencia entre ambos?

La principal diferencia entre VMWare y VirtualBox la encontramos en su sistema de almacenamiento de discos duros virtuales, VMWare usa el formato VMDK (Virtual Machine Disk), VirtualBox hace lo mismo con el formato VDI (Virtual Disk Image). Estas formatos aunque similares, tienen una gran diferencia, y esta la encontramos en que VMWare puede repartir una unidad de disco duro virtual entre varios archivos VMDK, mientras que VirtualBox está obligado a usar un único archivo VDI, lo que dependiendo el entorno en el que trabajemos, puede darnos problemas al tener que manejar archivos de varios GBs de capacidad.


## 3) Instalación de Sistemas Operativos virtualizados

### Cuestión 6: Windows Server. Enumere las versiones de este producto y los años en los que fueron presentadas

* Windows 2000 Server en el año 2000
* Windows Server 2003 en el año 2003
* Windows Server 2008 en el año 2008
* Windows Server 2008 R2 en el año 2009
* Windows Server 2012 en el año 2012

### Cuestión 7: Ubuntu Server. ¿Qué empresa hay detrás de Ubuntu? ¿De qué distribución parte?

La empresa que hay detrás de Ubuntu es Canonical, empresa fundada en 2004 por Mark Shuttleworth para desarrollar proyectos relacionados con el software libre. Ubuntu parte de la distribución Debian, que está considerada como una de las distribuciones más consolidadas de Linux.

### Cuestión 8: CentOS. ¿Qué relación tiene esta distribución con Red Hat y con el proyecto Fedora?

La relación entre CentOS y RedHat se basa en que CentOS es una distribución de Linux orientada a empresas que se basa en las fuentes de distribución Red Hat Enterprise Linux, otra distribución comercial de Linux desarrollada por Red Hat.

A su vez, Red Hat está relacionada directamente con Fedora, porque mediante un acuerdo patrocinado por Red Hat entre Proyecto Fedora y la propia Red Hat, se permite que Fedora se base en el anterior Red Hat Linux, y de igual manera, que Red Hat pueda aprovechar las innovaciones desarrolladas por Fedora e incorporarlas en su versión comercial, Red Hat Enterprise Linux.

### Cuestión 9: Solaris. ¿Qué empresa está detrás de Solaris?

Solaris fue inicialmente desarrollada por Sun MicroSystems desde 1992, pasando a Oracle Corporation cuando esta fue adquirida por la misma.


## 3.1) Particionamiento del disco virtual

### Cuestión 10: ¿Qué es LVM? ¿Qué ventaja tiene para un servidor de gama baja?

LVM es un administrador de volúmenes lógicos, esto nos permitirá que si creamos un grupo lógico con diferentes volúmenes lógicos en su interior, podremos variar el tamaño de los diferentes volúmenes lógicos en cualquier momento.

Esto es muy beneficioso en servidores de gama baja, porque si no disponemos de un inmesa capacidad de espacio en disco, ya que el espacio es limitado y no queremos tener problemas que nos hagan tener que volver a cambiar el esquema de particionado, teniendo también que reinstalar todo el sistema. Usando LVM, no deberemos preocuparnos especialmente por esto, porque si un volumen lógico se queda sin espacio libre, pero disponemos del mismo en otro volumen lógico se queda sin espacio libre, pro disponemos del mismo en otro volumen lógico redimensionando ambos, y añadiendo el espacio libre resultante al volumen lógico falto de espacio, solucinaríamos nuestro problema.

### Cuestión 11: ¿Da igual situar la partición /home al principio o al final del disco?

Con las tecnologías disponibles en la actualidad, almacenar cualquier directorio al principio o final de un disco duro no es especialmente trascendente porque el disco duro está en continuo movimiento, lo que sifnifica que cuando le llega una petición de lectura/escritura, siempre va a tardarse un mínimo intervalo de tiempo, desde que llega la petición hasta que los cabezales se posicionan en los sectores adecuados.


## 4) Conexión con la máquina anfitriona

### Cuestión 12: ¿Con qué opción establecemos una red local con la máquina anfitriona? ¿Con qué opción podemos compartir la conexión a Internet?

Para establecerse una red local con la máquina anfitriona usaremos la opción Host-only, que hará que la máquina virtual pueda conectarse en red con la máquina anfitriona y el resto de máquinas virtuales que se encuentren en funcionamiento en la máquina anfitriona.

Para compartir la conexión a Internet, activaremos la opción NAT, que nos permite que dos redes con direcciones incompatible intercambien paquetes, esto hará que nuestra red local virtual con la máquina anfitriona intercambie paquetes con la red local mediante la cual la máquina antriona tiene acceso a Internet, consiguiendo en consecuencia que nuestra máquina virtual también tenga acceso a Internet.

### Cuestión 13: ¿Cómo podemos ver que ambas máquinas están conectadas en la misma red local?

Si usando el comando ifconfig obtenemos la dirección IP tanto de nuestra máquina anfitriona como de nuestra máquina virtual, hacemos ping desde una máquina a la dirección IP de la otra y obtenemos como resultado que los paquetes han llegado correctamente, este significara que las máquinas estan conectada a una misma red local.


## 5) Editando archivos en la consola: vi, pico, nano y emacs

### Cuestión 14: Prepare un resumen (“chuletario”) con los comandos y combinaciones de teclas necesarias para moverse por el contenido del archivo, editarlo, buscar y reemplazar y guardar en los cuatro editores mencionados.

* vi:
 * Moverse. Izquierda: ← o h; Derecha: → o l; Arriba: ↑ o k; Abajo: ↓ o j
 * Editar. Añadir al final de la línea: a; Insertar al inicio de la línea: i
 * Buscar. /"cadena"
 * Reemplazar. Caracteres: c; Palabras: cw
 * Guardar: :w; Guardar y salir: :wq

* pico:
 * Buscar: ctrl+w
 * Reemplazar: ctrl+w -> ctrl+r
 * Guardar: ctrl+o

* nano:
 * Buscar: ctrl+w
 * Reemplazar: ctrl+w -> ctrl+r
 * Guardar: ctrl+o

* emacs:
 * Moverse. Izquierda: ctrl+b; Derecha: ctrl+f; Arriba: ctrl+p; Abajo: ctrl+n
 * Buscar: ctrl+s
 * Guardar: ctrl+x -> ctrl+s
 * Reemplazar. mayus+x replace-string -> enter -> cadenaReemplazar -> enter -> cadenReemplazo -> enter


## Bibliografia: (consultado a día 15/10/2012)

[http://www.aprendiendopc.com/%C2%BFque-es-una-maquina-virtual/](http://www.aprendiendopc.com/%C2%BFque-es-una-maquina-virtual/)

[http://es.wikipedia.org/wiki/Virtualizaci%C3%B3n](http://es.wikipedia.org/wiki/Virtualizaci%C3%B3n)

[http://www.itnews.ec/marco/000039.aspx](http://www.itnews.ec/marco/000039.aspx)

[http://es.wikipedia.org/wiki/Virtualizaci%C3%B3n_x86](http://es.wikipedia.org/wiki/Virtualizaci%C3%B3n_x86)

[http://www.vmware.com/es/products/desktop_virtualization/player/overview.html](http://www.vmware.com/es/products/desktop_virtualization/player/overview.html)

[http://www.vmware.com/es/products/desktop_virtualization/workstation/overview.html](http://www.vmware.com/es/products/desktop_virtualization/workstation/overview.html)

[http://www.vmware.com/es/products/datacenter-virtualization/server/overview.html](http://www.vmware.com/es/products/datacenter-virtualization/server/overview.html)

[http://www.vmware.com/es/products/desktop_virtualization/fusion/overview.html](http://www.vmware.com/es/products/desktop_virtualization/fusion/overview.html)

[http://vmfaq.com/entry/5/](http://vmfaq.com/entry/5/)

[http://www.virtualbox.org/manual/ch05.html#vdidetails](http://www.virtualbox.org/manual/ch05.html#vdidetails)

[http://en.wikipedia.org/wiki/Windows_server](http://en.wikipedia.org/wiki/Windows_server)

[http://www.ubuntu.com/project/about-ubuntu](http://www.ubuntu.com/project/about-ubuntu)

[http://www.canonical.com/about-canonical](http://www.canonical.com/about-canonical)

[http://wiki.centos.org/About](http://wiki.centos.org/About)

[http://es.wikipedia.org/wiki/Fedora_(distribuci%C3%B3n_Linux)](http://es.wikipedia.org/wiki/Fedora_(distribuci%C3%B3n_Linux))

[http://www.redhat.com/resourcelibrary/articles/relationship-between-fedora-and-rhel](http://www.redhat.com/resourcelibrary/articles/relationship-between-fedora-and-rhel)

[http://es.wikipedia.org/wiki/Solaris_(sistema_operativo)](http://es.wikipedia.org/wiki/Solaris_(sistema_operativo))

[http://www.tldp.org/HOWTO/LVM-HOWTO/benefitsoflvmsmall.html](http://www.tldp.org/HOWTO/LVM-HOWTO/benefitsoflvmsmall.html)

[http://es.wikipedia.org/wiki/Network_Address_Translation](http://es.wikipedia.org/wiki/Network_Address_Translation)
