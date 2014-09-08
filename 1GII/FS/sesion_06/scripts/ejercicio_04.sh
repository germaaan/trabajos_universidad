#!/bin/bash

if test $# -ne 1;
 then 
	printf "\nTiene que introducir solo 1 argumento obligatoriamente: el shell a comprobar por que usuarios es usado.\n\n";
 else
	printf "\nLista de usuarios que usan el shell \"$1\":\n"
	grep -w $1 /etc/passwd | cut -d':' -f1;
fi
