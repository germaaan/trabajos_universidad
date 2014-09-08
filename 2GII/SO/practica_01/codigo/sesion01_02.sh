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
