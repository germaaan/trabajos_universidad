#!/bin/csh -vx
@ i = 1
echo ""> divide_venceras.dat
#while ( $i <= 10)
echo " $i `./main $i`" >> divide_venceras.dat
@ i++
end
