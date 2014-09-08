Transmisión de Datos y Redes de Computadores
============================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# PRÁCTICA 1: Despliegue de servicios de red en entornos corporativos
### José Manuel Castillo Pérez
### Germán Martínez Maldonado

Las distintas interfaces y direcciones IP de los equipos donde hemos realizado las prácticas han sido:

* **Equipo A**:
 * Interfaz: datos, dirección IP: 33.2.2.2 
 * Interfaz: gestión, dirección IP: 192.168.2.3 
 * Interfaz: interna, dirección IP: 172.18.141.85

* **Equipo B**:
 * Interfaz: datos, dirección IP: 33.2.2.3 
 * Interfaz: gestión, dirección IP: 192.168.2.4 
 * Interfaz: interna, dirección IP: 172.18.143.86


**1. Configure el servicio de NFS en el equipo B, de forma que exista un directorio compartido /var/carpeta_compartida. Configure  el  equipo  A  para  que  desde  su  directorio  local /var/carpeta_remota se pueda acceder al directorio /var/carpeta_compartida del servidor con permisos de solo lectura. Permita que solo A pueda acceder a dicho recurso.**

Primero hemos empezado en el equipo B haciendo las siguientes operaciones:

* Creamos la carpeta que queremos compartir
```
# mkdir /var/carpeta_compartida
```

* Abrimos el archivo /etc/exports
```
# gedit /etc/exports
```

* Añadimos en dicho fichero la siguiente línea
```
/var/carpeta_compartida ei141085(ro)
```

* Exportamos todos los directorios que hemos añadido en el archivo de configuración
```
# exportfs –a
```

* Reiniciamos el servicio NFS
```
# service nfs-kernel-server restart
```

Ahora en el equipo A realizamos las siguientes operaciones:

* Creamos la carpeta que queremos que contenga el contenido de la carpeta compartida
```
# mkdir /var/carpeta_remota
```

* Montamos donde queremos que este la carpeta compartida entre los dos equipos
```
# mount –t nfs ei143086: /var/carpeta_compartida /var/carpeta_remota
```

Ya tenemos la carpeta compartida entre los dos equipos.

**2. Configure el servidor Samba en el equipo B, de forma que exista un directorio compartido /var/carpeta_compartida_samba. Permita que solo el usuario “Alice” pueda acceder a la carpeta compartida con permisos de lectura y escritura.**

Empezamos en el equipo B realizando las siguientes operaciones:

* Creamos la carpeta que queremos compartir
```
# mkdir /var/carpeta_compartida_samba
```

* Abrimos el archivo de configuración de Samba
```
# gedit /etc/samba/smb.conf
```

* Añadimos y modificamos las siguiente directivas:
```
Workgroup = Matabichos
Hosts allow 127.0.0.1.,192.168
Security = user
[carpeta_compartida_samba]
    comment = Carpeta compartida
    path = /var/carpeta_compartida_samba 
    writeable = yes
    browseable = yes 
    guest ok = no 
    valid users = Alice 
    write list = Alice
```

* Luego creamos el usuario Alice de la siguiente forma:
```
# useradd –s /bin/nologin Alice
```

* Y le asignamos una contraseña para usar en Samba.
```
# smbpasswd –a Alice
```

* Comprobamos con la siguiente orden si el fichero de configuración es correcta.
```
# testparm
```

* Y reiniciamos el servicio samba
```
# service samba restart
```

Para acceder al recurso compartido desde el equipo A podemos:

* Acceder por terminal mediante el siguiente comando:
```
# smbclient –L ei143086 –U Matabichos/Alice
```

* Acceder a través del explorador de ficheros del sistema, desde los recursos de red, podemos comprobar que el usuario Alice puede acceder al contenido compartido.

**3. Configure el router Rx_y para que funcione como servidor de DHCP. En la configuración debe indicarse que:**

* **En la red de datos, la pasarela por defecto es Rx_y.**
* **El servidor de nombres es eihal.**
* **El equipo B tendrá siempre la dirección 33.x.y.3, mientras que el equipo A puede tener cualquier dirección en el rango: 33.x.y.2-33.x.y.200.**
* **El tiempo de validez de una configuración será de 3 minutos.**

Para  realizar  esta  configuración  usaremos  el  programa  Winbox,  conectándonos  a  la dirección de la interfaz de gestión del router, cuya dirección es 192.168.2.12.

Seleccionamos como interfaz a configurar para ejecutar el servidor DHCP (DHCP Server Interface) la **“ether1”**.

El  espacio  de  direcciones  de  direcciones  IP  dinámicas  que  se  pueden  asignar  (DHCP Address Space) será **“33.2.2.0/24”**, para que así se englobe nuestra subred de datos.

La puerta pasarela por defecto (Gateway for DHCP Network) será la dirección de la interfaz de datos del router, **“33.2.2.1”**.

El rango de direcciones asignables (Addresses to Give Out) será **“33.2.2.2-33.2.2.200”**.

El servidor de nombres (DNS Server) será el equipo que conocemos como **“eihal”**, cuya dirección introduciremos: **“192.168.33.21”**

Y el tiempo de validez (Lease Time) será de **“00:03:00”**.

Probamos a solicitar una dirección desde el equipo B, cuando el servidor nos asigne una dirección, si no es **“33.2.2.3”**, en la configuración del servidor, entramos en la pestaña **“Leases”** y sobre la petición del equipo B hacemos doble clic para cambiar la dirección a la indicada y pulsamos el botón **“Make static”**, para que siempre se le asigne esa dirección al equipo B; si por el contrario, esa dirección hubiera sido iniciada al equipo desde un principio, solo deberemos seleccionar la solicitud y hacer clic en el botón **“Make static”**.
