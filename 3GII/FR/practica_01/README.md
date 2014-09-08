Fundamentos de Redes
=========================================
3º Grado en Ingeniería Informática 2012/2013
--------------------------------------------


# Práctica 1: Configuración de servicios de red
### Germán Martínez Maldonado


### 1) Compruebe las direcciones IP que tienen asignadas las diferentes interfaces de red de su equipo mediante el comando ifconfig, ¿cómo se llama dichas interfaces? ¿qué direcciones de red hay definidas?

```
# ifconfig

datos: 33.1.2.2
gestion: 192.168.1.3
interna: 172.18.143.84
```


### 2) Compruebe que existe conectividad con otro equipo del laboratorio, mediante la utilidad ping.

```
# ping 172.18.141.84

PING 172.18.141.84 (172.18.141.84) 56(84) bytes of data.
64 bytes from 172.18.141.84: icmp_seq=1 ttl=64 time=0.351 ms 
64 bytes from 172.18.141.84: icmp_seq=2 ttl=64 time=0.226 ms 
64 bytes from 172.18.141.84: icmp_seq=3 ttl=64 time=0.221 ms 
64 bytes from 172.18.141.84: icmp_seq=4 ttl=64 time=0.228 ms
^C
--- 172.18.141.84 ping stadistics ---
4 packets transmitted, 4 received, 0% packet loss, time 2999ms
rtt min/avg/max/mdev = 0.221/0.256/0.351/0.056ms
```


### 3) Cree una cuenta de usuario en su equipo, habilite el servicio telnet y compruebe con algún compañero que dicho servicio es accesible.

```
# adduser telemaco
```

En el archivo **“/etc/xinetd.d/telnet”** ponemos la directiva **“disable = no”**. Reiniciamos para hacer efectiva la configuración de telnet:

```
# service xinetd restart
```

Probamos la conexión:

```
# telnet 172.18.141.84
Trying 172.18.141.84...
Connected to 172.18.141.84.
Escape character is '^]'.
Ubuntu 8.10-r-A37
ei141084 login: telemaco
Password:

Linux ei141084 3.2.9 #4 SMP Mon Mar 12 14:38:51 CET 2012 i686

telemaco@ei141084:~$
```

Vemos que estamos dentro del ordenador remoto con el usuario creado.


### 4) Configure el servicio telnet para que:

#### a) Sólo sea accesible desde la dirección IP de su compañero.

En el archivo **“/etc/xinetd.d/telnet”** ponemos **“only_from = 172.18.141.84”**. Reiniciamos para hacer efectiva la configuración de telnet:

```
# service xinetd restart
```

Probamos la conexión:

```
# telnet 172.18.141.84
Trying 172.18.141.84...
Connected to 172.18.141.84.
Escape character is '^]'.
Conection closed by foreign host.
```

Vemos que la conexión ha sido rechazada.

#### b) Se registre en el fichero /var/log/telnet.log los intentos de acceso con y sin éxito al servicio telnet, indicando la dirección IP del equipo que intenta el acceso.

En el archivo **“/etc/xinetd.d/telnet”** ponemos **“log_type = FILE /var/log/telnet.log”**. A partir de ahora en el archivo **“/var/log/telnet.log”**, se registrarán todos los intentos de acceso al ordenador mediante telnet. Reiniciamos para hacer efectiva la configuración de telnet:

```
# service xinetd restart
```


### 5) Habilite el servicio ftp en su equipo. Pida a un compañero que pruebe dicho servicio a través de la cuenta de usuario. Pida a un compañero que pruebe a descargar un fichero desde su equipo. (¡Atención! debe crear previamente el directorio /var/run/vsftpd).

Creamos el directorio **“/var/run/vsftpd”**:

```
# mkdir /var/run/vsftpd.conf
```

En el archivo **“/etc/xinetd.d/vsftp”** ponemos **“disable = no”**. Reiniciamos para hacer efectiva la configuración de vsftp:

```
#service xinetd restart
```

Probamos la conexión:

```
# ftp 172.18.143.84
Connected to 172.18.143.84
220 (vsFTPd 2.0.7)
Name (172.18.143.84:root): telemaco.
331 Please specify the password.
Password: telemaco
230 login successful.
Remote system type is UNIX.
Using binary mode to transfer files.
ftp> lcd
Local directory now /etc/xinetd.d
ftp> get prueba
local: prueba remote: prueba
200 PORT command successful. Consider using PASV.
150 Opening BINARY mode data connection for prueba (0 bytes).
226 File send OK.
```

Vemos que hemos podido acceder al servidor remoto con el nombre de usuario y contraseña creados anteriormente, y que además con el comando **“get”** hemos podido descargar el archivo **“prueba”**.


### 6) Configure el servicio ftp para que:

#### a) Únicamente pueda ser utilizando a través de la cuenta de usuario que hemos creado en nuestro equipo en el apartado 3).

En el archivo **“/etc/xinetd.d/vsftp”** descomentamos las líneas **“chroot_list_enable=YES”** y **“chroot_list_file=/etc/vsftpd.chroot_list”**. Creamos el archivo **“/etc/vsftpd.chroot_list”** y añadimos el nombre del usuario que hemos creado: **“telemaco”**. Reiniciamos para hacer efectiva la configuración de vsftp:

```
#service xinetd restart
```

#### b) Acepte la subida de ficheros al servidor ftp.

En el archivo **“/etc/xinetd.d/vsftp”** descomentamos las líneas **“write_enable=YES”**. Reiniciamos para hacer efectiva la configuración de vsftp:

```
#service xinetd restart
```


### 7) Habilite el servicio http en su equipo. Abra un navegador web y pruebe a visualizar la página de inicio desde su equipo (http://localhost o http://127.0.0.1). Además, realice los siguientes cambios:

#### a) Modifique el contenido de la página de inicio, y compruebe con su compañero que puede acceder mediante su navegador a la dirección de su servidor.

La página de inicio actual para nuestra configuración por defecto es el archivo **“/var/www/index.html”**, podemos modificar este archivo para modificar el contenido de la página de inicio, o indicar un archivo correspondiente a una página de inicio nueva incluyendo la directiva **“DirectoryIndex pagina.html”** en el archivo de configuración de nuestro sitio. La ruta de este archivo de página de inicio siempre deberá tener una ruta relativa a la directiva **“DocumentRoot”** que en este caso es **“/var/www”**. Reiniciamos para hacer efectiva la configuración de apache:

```
#service apache2 restart
 * Restarting web server apache2
 ... waiting                                                                            [ OK ]
```

Simplemente con introducir la dirección IP de nuestro ordenador en la barra de direcciones del navegador de otro, podremos comprobar que el servidor funciona correctamente.

#### b) Modifique el puerto de escucha del servidor para que haya que acceder a la página de inicio mediante la dirección: http://localhost:8080.

En el archivo **“/etc/apache2/ports.conf”** modificamos la línea **“Listen 80”** a **“Listen 8080”**. Reiniciamos para hacer efectiva la configuración de apache:

```
#service apache2 restart
 * Restarting web server apache2
 ... waiting                                                                            [ OK ]
```
