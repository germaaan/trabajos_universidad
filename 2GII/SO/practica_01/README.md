Sistemas Operativos
===================
2º Grado en Ingeniería Informática 2011/2012
--------------------------------------------


# Práctica 1: Administración de un sistema operativo GNU/Linux
## Germán Martínez Maldonado

## Sesión 1: Introducción a UML (User Mode Linux). Órdenes para administrar usuario y grupos de usuarios.

### Actividad: Como este proceso deberemos repetirlo en todas las sesiones de la Práctica 1, como primer paso, debemos construir un script para automatizar los pasos anteriores y probar su correcto funcionamiento. Nota: en las pruebas, copiar los ficheros el menor número de veces posibles para evitar aumentar innecesariamente el tráfico en la red de la Escuela, dado que estos ficheros son bastante grandes.

```
#!/bin/bash
cd /home/germaaan/Universidad/2o/SO
chmod u+x kernel32-3.0.4
./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=256M
```

**El sistema de archivos suministrado tiene inicialmente poca potencialidad, por ejemplo, no tiene man e info esta recortado. Podemos usar estas órdenes del sistema anfitrión. Para ello, podemos usar las órdenes de anfitrión en otra ventana de entorno gráfico. Si no estamos en modo gráfico, podemos utilizar la potencialidad de consolas virtuales que suministra Linux. Podemos lazar UML en la consola actual, y cuando necesitemos consultar algo en el sistema anfitrión utilizar Ctrl-Alt-Fn para cambiar de consola.**

**Nota: Dado que al necesitar un archivo en nuestra cuenta personal para almacenar la memoria, argumento mem, el arranque de UML puede fallar por falta de espacio y nos dará un mensaje al respeto. Lo normal es que hayamos excedido la cuota de espacio asignado en nuestro home, por lo que deberemos borrar archivos hasta que liberemos el suficiente espacio. Podemos ver el consumo de espacio con quota -v.**

```
#!/bin/bash

#VARIABLES DEL SISTEMA USADAS
#    IFS:               (Internal Field Separator) Utilizado para cambiar el separador por defecto de los campos.
#    SHELL:             Contiene el valor del shell usado por defecto en el sistema.

#VARIABLES LOCALES USADAS
#    grupoExistente:    Usado para comprobar si el grupo al que van a ser añadidos los usuarios ya existe en el sistema.
#    line:              Usado para ir almacenando el contenido de cada una de las lineas del archivo procesado.
#    nUsuarios:         Número de usuarios a dar de alta en el sistema.
#    loginExistente:    Usado para comprobar si el login con el que se va a dar de alta a un usuario ya existe en el sistema.
#    nombre:            Nombre completo del próximo usuario a dar de alta en el sistema.
#    telefono:          Teléfono del próximo usuario a dar de alta en el sistema.
#    uLogin:            Login de acceso al sistema para el próximo usuario a dar de alta en el sistema.
#    uLine:             Usado para ir almacenando el contenido de cada una de las lineas del archivo procesado.
#    eLogin:            Usado para ir almacenando los logins existentes en el sistema.
#    numero:            Usado para almacenar el numero que acompañara al nombre de usuario en caso de este ser necesario para el registro.

if test $# -ne 1;
    then 
        printf "\nERROR: no ha indicado el archivo con los datos de los usuarios a dar de alta.\n\n"
    else
 
    IFS=":"
 
    grupoExistente='N'
 
    while read line
        do
            read group _ _ _ <<< "$line"
                
            if [ $group = "empleados" ];
                then
                    grupoExistente='S'
                    echo "grupo listo"
                    break
                fi
                
        done < /etc/group
 
    if [ $grupoExistente = "N" ];
        then
            sudo groupadd empleados
        fi
 
    nUsuarios=`cat $1 | wc -l`
    printf "\nNumero de usuarios a dar de alta: $nUsuarios."

    while read line
        do   
        
        loginExistente='N'

        read nombre telefono uLogin <<< "$line"
    
        printf "\n\nDATOS DEL USUARIO: "
        printf "\nNombre completo: $nombre"
        printf "\nTelefono: $telefono"
        printf "\nLogin: $uLogin\n"

        while read uLine
            do
                read eLogin _ _ _ _ _ _ <<< "$uLine"
                
                if [ $uLogin = $eLogin ];
                    then
                        loginExistente='S'
                        break
                    fi
                
            done < /etc/passwd
            
            if [ $loginExistente = 'S' ];
                then
                    printf "\nYa existe un usuario con el login \"$uLogin\"."
                
                    let numero=`tail -1 /etc/passwd | cut -d':' -f3`+1
                    uLogin=`echo $uLogin"_"$numero`
                    printf "\nSe debera usar el login \"$uLogin\" para el registro."
                fi
            
            sudo useradd -d /home/$uLogin -G empleados -m -p $uLogin -s $SHELL $uLogin
            
        done <$1    

fi
```


## Sesión 2: El sistema de archivos. Gestión de paquetes.

### Actividad  1:  Qué  sistemas  de  archivos  monta  Ubuntu  cuando  arranca  y nuestro UML.

Para saber que sistemas de archivos monta Ubuntu cuando arranca, ejecutamos la orden cat
/etc/fstab:

```
<file system>                              <mount point> <type> <options>            <dump> <pass>
proc                                       /proc         proc   nodev,noexec,nosuid  0      0
UUID=8faa5ffd-0c24-4785-9c83-1849a084a6b6  /             ext4   errors=remount-ro    0      1
UUID=3c94529a-41cd-4f30-8773-5b9dab7197c2  none          swap   sw                   0      0
```

Como podemos ver se encuentran montados 3 sistemas de archivos: proc, ext4 y swap. proc contiene información detallada sobre el hardware del sistema y cualquier proceso que se esté ejecutando actualmente, ext4 que es el sistema de archivos sobre el que está instalado nuestro sistema y que almacena nuestros archivos, y swap, que es la partición usada como memoria de intercambio.

Si ejecutamos la misma orden en el UML:

```
<file system>  <mount point> <type>  <options>                                          <dump> <pass> 
LABEL=ROOT     /             auto    noatime                                            1      1 
tmpfs          /dev/shm      tmpfs   defaults                                           0      0 
tmp            /tmp          tmpfs   rw,mode=1777,fscontext=system_u:object_r:tmp_t:s0  0      0 
devpts         /dev/pts      devpts  gid=5,mode=620                                     0      0 
sysfs          /sys          sysfs   defaults                                           0      0 
proc           /proc         proc    defaults                                           0      0 
```

En el UML tenemos varios sistemas de más que en Ubuntu. auto que indica donde se encuentra montado el usuario root, tmpfs que es un dispositivo virtual que se usa como sistema de archivos temporal, devpts para montar pseudoterminales, sysfs que es un sistema de archivos virtual que exporta información sobre los dispositivos y sus controladores y proc contiene información detallada sobre el hardware del sistema y cualquier proceso que se esté ejecutando actualmente.

### Actividad 2: Supongamos que vamos a construir un archivo teléfonos (situado en /opt/datos) que contiene los teléfonos de los empleados de un departamento de la empresa. Debemos construir un script (situado en /opt/bin) que lee el archivo y nos da un listado de los teléfonos. La cuestión es que deseamos que sólo los empleados de ese departamento, y no de otro, puedan leer el archivo, y por tanto, los teléfonos. Establecer las acciones oportunas en la protección del archivo y el script para que cumplan los requisitos. 

Para asegurarnos de que el script solo pueda ser ejecutado por los empleados de un mismo departamento, haremos que solo los usuarios del mismo grupo puedan ejecutar el script, esto lo haremos con el comando "chmod g+x /opt/bin/NOMBRE_SCRIPT"

```
if test $# -ne 1; 
    then 
        printf "\nERROR: no ha indicado el archivo con los datos de los empleados de los que obterner los elefonos.\n\n" 
    else 
 
        IFS=":" 

        while read line 
            do 
                read _ telefono _ <<< "$line" 
                echo $telefono 
            done <$1 
fi
```

### Actividad 3: En el home de root de UML crear una pequeña jerarquía de dos directorios con un par de archivos cada uno. Probar a crear enlaces duros y simbólicos entres los archivos y directorios. 

Primero creamos la siguiente jerarquía de directorios:

```
[root@localhost ~]# ls -R 
.: 
prueba1  prueba2 

./prueba1: 
pruebaSub 

./prueba1/pruebaSub: 
pruebaSub1  pruebaSub2 

./prueba2: 
pruebaSub21  pruebaSub22 
```

Ahora, vamos a crear un enlace duro de uno de los archivos creados, en nuestro caso crearemos un enlace duro de "pruebaSub21" con el nombre "otraPrueba", esto lo haremos con el comando "ln  pruebaSub21 otraPrueba". Para comprobar que el enlace duro se ha creado correctamente, listamos con "ls -li" y vemos que ahora aparece un archivo nuevo, pero si nos fijamos en el "inodo" los dos tienen el mismo, porque lo que aunque los veamos como dos, internamente son el mismo archivo. 

```
[root@localhost prueba2]# ls -li
total 0 
13871 -rw-r--r-- 1 root root 0 Oct 13 03:21 pruebaSub21 
13875 -rw-r--r-- 1 root root 0 Oct 13 03:21 pruebaSub22 
[root@localhost prueba2]# ln  pruebaSub21 otraPrueba 
[root@localhost prueba2]# ls -li 
total 0 
13871 -rw-r--r-- 2 root root 0 Oct 13 03:21 otraPrueba 
13871 -rw-r--r-- 2 root root 0 Oct 13 03:21 pruebaSub21 
13875 -rw-r--r-- 1 root root 0 Oct 13 03:21 pruebaSub22 
```

En este caso, vamos a crear un enlace simbólico al enlace duro que acabamos de crear, esto se hace con el comando "ln -s ~/prueba2/otraPrueba". Ahora con "ls -li" comprobamos que se ha creado el enlace simbólico, podremos ver que el número archivo, ya no tiene el mismo "inodo" y ademas la "->" indica que es un enlace simbólico. 

```
[root@localhost prueba2]# cd ~/prueba1 
[root@localhost prueba1]# ln -s ~/prueba2/otraPrueba 
[root@localhost prueba1]# ls -li 
total 4 
13876 lrwxrwxrwx 1 root root   24 Oct 13 03:28 otraPrueba -> /root/prueba2/otraPrueba 
12727 drwxr-xr-x 2 root root 4096 Oct 13 03:21 pruebaSub
```

### Actividad 4: ¿Cuántos y qué paquetes tiene instalados nuestro sistema UML?

Para saber que paquetes se encuentran instalados en nuestro sistema UML, usamos el comando "rpm -qa", si añadimos "| wc -l" obtendremos el número de paquetes intalados. 

```
[root@localhost prueba1]# rpm -qa 
filesystem-2.4.35-1.fc14.i686 
openssh-server-5.5p1-24.fc14.2.i686 
sendmail-8.14.4-10.fc14.i686 
...
libselinux-2.0.96-6.fc14.1.i686 
openssh-5.5p1-24.fc14.2.i686 
libselinux-utils-2.0.96-6.fc14.1.i686 

[root@localhost prueba1]# rpm -qa | wc -l 
181
```

### Actividad 5: Instalar un paquete en formato rpm en nuestro sistema, en concreto sysstat, que necesitaremos en sesiones posteriores. Los pasos son los siguiente: 

1. Vamos a descargarnos de Internet el archivo correspondiente. Para ello, podemos acceder, entre otras, a alguna de las siguientes direcciones: 

* http://pkgs.org/ 
* http://www.rpmseek.com/index.html 
* http://www.rpmfind.net/ 
* http://rpm.pbone.net/ 

Y buscamos el paquete para la distribución Fedora 14 que es la que se corresponde a nuestro sistema de archivos. En este caso, veremos que debemos descargar el archivo: sysstat-9.0.6.1-4.fc14.i686.rpm 

2. Pasaremos el archivo del directorio donde lo hayamos descargado en el anfitrión al directorio home de root en el huésped (Ver Apéndice 4.1, Como intercambiar archivos entre el anfitrión y el huésped). 

3. Procederemos a instalarlo con rpm. Comprobar que se ha instalado correctamente. 

4. Procederemos a ejecutarlo. Probablemente nos aparecerá un mensaje de error similar a “Cannot open file /var/log/sa/sa06”. Para solventarlo, crearemos el archivo con la orden “touch /var/log/sa/sa06”. 

5. Solucionado el problema anterior, al volverlo a ejecutar posiblemente nos aparezca en mensaje de error “Invalid system activity file /var/log/sa/sa06”. Para solventarlo ejecutaremos el demonio de sar para que sobrescriba el archivo con la orden “/usr/lib/sa/sadc -” 

Vamos a instalar el paquete "sysstat", más concretamente "sysstat-9.0.6.1-4.fc14.i686.rpm", que lo podremos descargar desde la dirección "[http://download.fedora.redhat.com/pub/fedora/linux/releases/14/Everything/i386/os/Packages/sysstat-9.0.6.1-4.fc14.i686.rpm](http://download.fedora.redhat.com/pub/fedora/linux/releases/14/Everything/i386/os/Packages/sysstat-9.0.6.1-4.fc14.i686.rpm)". 

```
[root@localhost ~]# mount none /mnt -t hostfs 

[root@localhost ~]# cp /mnt/home/germaaan/Descargas/sysstat-9.0.6.1-4.fc14.i686.rpm /home 

[root@localhost ~]# cd /home 

[root@localhost home]# rpm -i sysstat-9.0.6.1-4.fc14.i686.rpm 

[root@localhost home]# rpm -q sysstat-9.0.6.1-4.fc14.i686
sysstat-9.0.6.1-4.fc14.i686 

[root@localhost home]# sar 
Cannot open /var/log/sa/sa08: No such file or directory 
[root@localhost home]# touch /var/log/sa/sa08 

[root@localhost home]# sar 
Linux 3.0.4 (localhost) 11/08/11 _i686_ (1 CPU)
```

### Actividad 6: Una vez instalado el paquete, obtenga cuantos paquetes hay instalados y cuales son. Como en la actividad ??. Como el listado de paquetes el muy largo, podemos ver cuáles son las diferencias con la orden diff que muestra las diferencias entre varios archivos (ver manual). 

```
[root@localhost sesion_2]# diff paquetesAntes paquetesDespues 
84a85 
> sysstat-9.0.6.1-4.fc14.i686
```


## Sesión 3: Vigilancia y optimización del sistema. Registro de actividades.

### Actividad 2: En tutor puedes descargar un programa que multiplica matrices. Utilízalo para ver cómo afecta a la carga del sistema. Para ello, ejecuta varias instancias del mismo concurrentemente con el operador &. Visualiza como varia la carga del sistema con las herramientas vistas en el guión.

```
top - 08:33:13 up 26 min,  2 users,  load average: 2.98, 0.99, 0.44 
Tasks: 162 total,   5 running, 156 sleeping,   0 stopped,   1 zombie 
Cpu(s): 99.5%us,  0.5%sy,  0.0%ni,  0.0%id,  0.0%wa,  0.0%hi,  0.0%si,  0.0%st 
Mem:   4081864k total,  1247344k used,  2834520k free,   232892k buffers 
Swap:   514044k total,        0k used,   514044k free,   511100k cached 

  PID  USER      PR  NI  VIRT   RES   SHR   S  %CPU  %MEM   TIME+   COMMAND
 2617  germaaan  20  0   18188  14m   284   R  49    0.4   0:38.54  mulmatrices
 2619  germaaan  20  0   18188  14m   284   R  49    0.4   0:37.39  mulmatrices
 2616  germaaan  20  0   18188  14m   284   R  48    0.4   0:39.25  mulmatrices
 2618  germaaan  20  0   18188  14m   284   R  48    0.4   0:36.82  mulmatrices
 1187  root      20  0   59612  24m   10m   S  1     0.6   1:08.54  Xorg
 1303  germaaan  20  0   5040   2196  700   S  1     0.1   0:01.13  dbus-daemon
 1429  germaaan  20  0   169m   11m   9064  S  1     0.3   0:00.75  gnome-power-man
 1572  germaaan  20  0   113m   15m   11m   S  1     0.4   0:02.25  indicator-apple
 1994  germaaan  20  0   138m   68m   28m   S  1     1.7   1:03.64  acroread
 2224  germaaan  20  0   99772  14m   11m   S  1     0.4   0:01.60  gnome-terminal
 1451  root      20  0   16788  3832  3024  S  0     0.1   0:00.32  upowerd
 1604  germaaan  20  0   53344  5504  4416  S  0     0.1   0:00.06  indicator-sessi
 1776  germaaan  20  0   74188  30m   10m   S  0     0.8   0:03.68  ubuntuone-syncd
    1  root      20  0   2920   1788  1256  S  0     0.0   0:00.57  init
    2  root      20  0   0      0     0     S  0     0.0   0:00.00  kthreadd
    3  root      20  0   0      0     0     S  0     0.0   0:00.12  ksoftirqd/0
    6  root      RT  0   0      0     0     S  0     0.0   0:00.00  migration/0
```

### Actividad 3: Vamos a ver como varía la carga del sistema tanto en consumo de CPU como en entradas/salidas con las herramientas vistas. Para ello, vamos a tomar el script que hicimos para descargar, descomprimir y ejecutar UML. Analiza el comportamiento del script respecto al uso de recursos.

```
top - 08:47:46 up 41 min,  3 users,  load average: 0.16, 0.22, 0.31 
Tasks: 175 total,   1 running, 165 sleeping,   0 stopped,   1 zombie 
Cpu(s):  5.6%us, 17.8%sy,  0.0%ni, 70.8%id,  5.8%wa,  0.0%hi,  0.0%si,  0.0%st 
Mem:   4081864k total,  2593532k used,  1488332k free,   239368k buffers 
Swap:   514044k total,        0k used,   514044k free,  1868372k cached 

  PID  USER      PR  NI   VIRT   RES   SHR   S  %CPU  %MEM   TIME+   COMMAND
 3763  germaaan  20  0    258m   40m   40m   S  33    1.0   0:04.16  kernel32-3.0.4
 1187  root      20  0    61276  25m   10m   S  4     0.6   1:45.17  Xorg
 2224  germaaan  20  0    98.3m  15m   11m   S  3     0.4   0:05.54  gnome-terminal
 1994  germaaan  20  0    138m   68m   28m   S  1     1.7   1:16.62  acroread
 2985  root      20  0    0      0     0     S  1     0.0   0:01.26  kworker/1:2
 3773  germaaan  20  0    1332   1308  1308  t  1     0.0   0:00.07  kernel32-3.0.4
 4089  germaaan  20  0    1880   988   988   t  1     0.0   0:00.02  kernel32-3.0.4
 1400  germaaan  20  0    106m   12m   9896  S  0     0.3   0:03.90  metacity
 3720  root      20  0    0      0     0     S  0     0.0   0:01.50  kworker/0:0
 3754  germaaan  20  0    2632   1156  864   R  0     0.0   0:00.11  top
 3771  germaaan  20  0    258m   40m   40m   S  0     1.0   0:00.07  kernel32-3.0.4
 4020  germaaan  20  0    1212   372   372   t  0     0.0   0:00.04  kernel32-3.0.4
 4122  germaaan  20  0    1180   1032  1032  t  0     0.0   0:00.01  kernel32-3.0.4
    1  root      20  0    2920   1788  1256  S  0     0.0   0:00.57  init
    2  root      20  0    0      0     0     S  0     0.0   0:00.00  kthreadd
    3  root      20  0    0      0     0     S  0     0.0   0:00.22  ksoftirqd/0
    6  root      RT  0    0      0     0     S  0     0.0   0:00.00  migration/0
    7  root      RT  0    0      0     0     S  0     0.0   0:00.00  migration/1
    9  root      20  0    0      0     0     S  0     0.0   0:00.16  ksoftirqd/1
   11  root      0   -20  0      0     0     S  0     0.0   0:00.00  cpuset
   12  root      0   -20  0      0     0     S  0     0.0   0:00.00  khelper
   
[root@localhost ~]# dd if=/dev/zero of=./archivogrande bs=1M count=1024& 
[2] 1191 
[root@localhost ~]# vmstat 5 5 
procs -----------memory--------- ---swap--- -----io------ --system--- -----cpu----- 
 r  b     swpd  free    buff  cache   si  so  bi  bo   in  cs  us  sy  id  wa   st 
 0  2     0     151668  3168  77904   0   0   84  186  10  31  0   0   74  26   0
 0  2     0     151644  3168  77904   0   0   0   794  74  2   0   0   0   100  0 
 0  2     0     151660  3168  77904   0   0   0   0    92  2   0   0   0   100  0 
 0  2     0     151676  3172  77912   0   0   1   200  84  3   0   0   0   100  0 
 0  2     0     151700  3172  77912   0   0   0   0    89  1   0   0   0   100  0
```

### Actividad 4: Para comprobar la limitación de recursos, crea un usuario denominado limitado que:  Solo pueda tener abiertos tres archivos. Ejecuta ls para ver qué sucede. Limita el número de procesos a 1. Ejecuta ps y mira que sucede. 

```
limitado@PC-G:~$ ulimit -n 3 
limitado@PC-G:~$ ls 
-bash: start_pipeline: tubería de pgrp: Too many open files 
ls: error while loading shared libraries: libselinux.so.1: cannot open shared object file: Error 24 
limitado@PC-G:~$ ulimit -u 1 
limitado@PC-G:~$ ps 
-bash: start_pipeline: tubería de pgrp: Too many open files
```

### Actividad 5: A través de la documentación de /proc, por ejemplo, utilizando man, revisa a que información de kernel nos permite acceder (en teoría, haremos varias veces referencia a la información que nos muestra). 

El archivo de sistema "proc" es un pseudo-archivo de sistema que es usado como una interfaz a la estructura de datos del kernel. 

Es comúnmente montado en /proc. La mayoría son de solo lectura, pero algunos archivos permiten que sean cambiadas variables del kernel.

### Actividad 6: Crea un archivo de configuración para el demonio syslog de UML que no lo tiene (/etc/sysconfig/syslog). Selecciona los mecanismos y prioridades que desees y pruébalo con logger. 

```
/etc/default/syslogd 
service rsyslog restart 
sysklogd init
```


## Sesión 4: Planificación (Automatización) de tareas. Arranque y parada de servicios. 

### Actividad 1: Un usuario local está abusando de sus privilegios de crontab al ejecutar tareas costosas a intervalos frecuentes. Después de indicarle varias veces que no los haga, nos vemos obligados a revocar estos privilegios. Lista los pasos necesarios para borrar sus crontab actuales y asegurarnos de que no puede añadir nuevas entradas. 

Eliminamos su archivo crontab: 

```
crontab -u nombre_usuario -r 
```

Impedimos que use el crontab :

```
echo nombre_usuario >>/etc/cron.deny 
```

Si al usuario al que se le ha prohibido el uso de crontab intenta usarlo, verá el siguiente mensaje: 

```
$ crontab -e 
You (nombre_usuario) are not allowed to use this program (crontab) 
See crontab(1) for more information
```

### Actividad 2: Piensa un par de tareas que deban ejecutarse periódicamente. Escribe las entradas crontab para ellas y especifica donde deberían ir en el sistema. 

Creamos una copia de seguridad cada mes y borramos todos los ficheros temporales que no hayan sido accedidos en los últimos 7 días. 

```
30 2 28 * 0 tar -cvf usuario.tar /home/usuario 
20 1 * * * find /tmp -atime +7 -type f -exec rm -f {}';' 
```
Estas ordénenos irán en un archivo en la siguiente dirección: /var/spool/cron

### Actividad 3: Listar los servicios que se arrancan en el nivel de ejecución 3 de UML. Modificar la configuración para que no arranque un determinado servicio, por ejemplo, sendmail. 

```
[root@localhost etc]# cat /etc/inittab 
id:3:initdefault: 
id:4:senmail:
```

### Actividad 4: Suponed que hemos detectado que un determinado servicio no opera correctamente, por ejemplo, sendmail ¿cómo reiniciarías el servicio?. 

Para comprobar si esta iniciado: 

```
service sendmail status 
```

Para reiniciar: 
```
service sendmail restart
```
