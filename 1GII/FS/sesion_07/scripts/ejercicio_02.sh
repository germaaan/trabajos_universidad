#!/bin/bash

printf "\nProceso del sistema que consume mas memoria:\n\n"
printf "`ps -eo cmd,size --sort=-size | head -2`\n\n"
