#!/bin/bash

SNMPGET="snmpget -v1 -c COM1"
SNMPSET="snmpset -v1 -c COM1"
SNMPDELTA="snmpdelta -v1 -c COM1"

echo -e "\n\nScript para gestión de agente SNMP"
echo "=================================="

echo -e "\nIntroduzca la dirección IP del dispositivo:"
read IP

INDICE="`$SNMPGET $IP ipAdEntIfIndex.$IP | cut -d ":" -f 4 | cut -d " " -f 2`"

echo -e "\nNombre del host:\t\t`$SNMPGET $IP sysName.0 | \
	cut -d ":" -f 4`"

echo  "Descripción del sistema: "
echo -e "\t Hardware: `$SNMPGET $IP sysDescr.0 | cut -d ":" -f 5 | \
	cut -d "-" -f 1`"
echo -e "\t Software: `$SNMPGET $IP sysDescr.0 | cut -d ":" -f 6`"

echo -e "\nInformación de contacto:\t`$SNMPGET $IP sysContact.0 | \
	cut -d ":" -f 4`"

echo -e "Localización del sistema:\t`$SNMPGET $IP sysLocation.0 | \
	cut -d ":" -f 4`"

echo -e "Fecha en el sistema:\t\t`$SNMPGET $IP hrSystemDate.0 | \
	cut -d ":" -f 4 | cut -d "," -f 1`"

echo -e "Tiempo desde inicio de sistema:\t`$SNMPGET $IP hrSystemUptime.0 | \
	cut -d ")" -f 2`"

OPC="NULL"
while [ $OPC != "S" -a $OPC != "s" -a $OPC != "N" -a $OPC != "n" ]; do
	echo -e "\n¿Cambiar el valor de infomación de contacto? S|N:"
	read OPC
done

if [ $OPC = "S" -o $OPC = "s" ]; then
	echo -e "Introduzca nuevo valor de información de contacto: "
	read OPC
	echo "Información de contacto actualizada:`$SNMPSET $IP sysContact.0 \
		s "$OPC" | cut -d ":" -f 4`"
fi

OPC="NULL"
while [ $OPC != "S" -a $OPC != "s" -a $OPC != "N" -a $OPC != "n" ]; do
	echo -e "\n¿Cambiar el valor de localización del sistema? S|N:"
	read OPC
done

if [ $OPC = "S" -o $OPC = "s" ]; then
	echo -e "Introduzca nuevo valor de localización del sistema: "
	read OPC
	echo "Localización del sistema actualizado:`$SNMPSET $IP sysLocation.0 \
		s "$OPC" | cut -d ":" -f 4`"
fi

OPC="NULL"
while [ $OPC != "E" -a $OPC != "e" -a $OPC != "S" -a $OPC != "s" -a $OPC != "N" -a $OPC != "n" ]; do
	echo -e "\n¿Monitorizar tráfico del dispositivo? [E]ntrada | [S]alida | [N]inguno:"
	read OPC
done

if [ $OPC = "E" -o $OPC = "e" -o $OPC = "S" -o $OPC = "s" ]; then
	echo "Introduzca el intervalo de actualización (en segundos):"
	read SEG

	if [ $OPC = "E" -o $OPC = "e" ]; then
		echo -e "\nComenzando monitorización del tráfico de entrada, para finalizar use Control+C."
		$SNMPDELTA $IP -Cp $SEG ifInOctets.$INDICE
	elif [ $OPC = "S" -o $OPC = "s" ]; then
		echo -e "\nComenzando monitorización del tráfico de salida, para finalizar use Control+C."
		$SNMPDELTA $IP -Cp $SEG ifOutOctets.$INDICE
	fi
fi

echo -e "\nSaliendo...\n\n"
