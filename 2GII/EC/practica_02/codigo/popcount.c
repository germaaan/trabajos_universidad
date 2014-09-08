#include <stdio.h>		// para printf()
#include <stdlib.h>		// para exit()
#include <sys/time.h>	// para gettimeofday(), struct timeval

#define SIZE (1<<20)
#define WSIZE 8*sizeof(int)
#define COPY_PASTE 1

int lista[SIZE];
int resultado = 0;

int popcount1(int* array) {
	int i, j, numero, contador = 0;

	for (i = 0; i < SIZE; i++) {			// Para todos los números del vector:

		numero = array[i];					// Extraemos un número.
		
		for (j = 0; j < WSIZE; j++){		// Recorremos todos los bits del número.
			contador += numero & 0x1;		// Extrayendo los bits con una máscara AND (0x1), acumulándolos en el contador.
			numero >>= 1;					// Realizamos el desplazamiento de los bits a la derecha.
		}
	}

	return contador;
}

int popcount2(int* array) {
	int i, numero, contador = 0;

	for (i = 0; i < SIZE; i++) {

		numero = array[i];		
		
		while (numero) {
			contador += numero & 0x1;
			numero >>= 1;
		}
	}

	return contador;
}

int popcount3(int* array) {
	int i, numero, contador;

	for (i = 0; i < SIZE; i++) {

		numero = array[i];		
		
		asm("movl	%[n],%%eax		\n"		// Movemos el número que hemos sacado de la lista a un registro.
"			testl	%%eax,%%eax		\n"		// Comparamos los valores del registro.
"			je		fin				\n"		// Saltamos a la etiqueta fin si el código de condición es 0.
"			movl	%[r],%%edx		\n"		// Movemos la variable contador a un registro.
"bucle:								\n"
"			movl	%%eax, %%ecx	\n"		// Movemos el valor del registro con el número a otro registro.
"			andl	$1, %%ecx		\n"		// Extraemos los bits con una máscara AND (0x1).
"			addl	%%ecx, %%edx	\n"		// Sumamos el número de bits al registro del contador.
"			sarl	%%eax			\n"		// Desplazamos los bits del número.
"			jnc		bucle			\n"		// Si el código de condición no es 0, saltamos al inicio del bucle.
"			movl	%%edx, %[r]		\n"		// Movemos el valor del registro con la suma de bits a la variable contador.
"fin:								\n"
		 :	[r] "+r"	(contador)	// output-input
		 :	[n] "r"		(numero)	// input
//		 :	"cc"					// clobber
//			"eax","ecx","edx"
		);
	}

	return contador;
}

int popcount4(int* array) {
	int i, j, numero, contador = 0;

	for (i = 0; i < SIZE; i++) {

		numero = array[i];

		for (j = 0; j < 8; j++){
			contador += numero & 0x01010101;
			numero >>= 1;
		}
	}

	contador += (contador >> 16);
	contador += (contador >> 8);

	return contador & 0xFF;
}

int popcount5(unsigned* array){
	int i, res, count = 0;

	static const int SSE_mask[] __attribute__ ((aligned (16))) = {0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f, 0x0f0f0f0f};
	static const int SSE_LUTb[] __attribute__ ((aligned (16))) = {0x02010100, 0x03020201, 0x03020201, 0x04030302};
			 													// 	 3 2 1 0      7 6 5 4   1110 9 8    15141312
	for (i=0; i<SIZE; i+=4){
		asm("movdqa		%[x], %%xmm0		\n"
"			 movdqa    	%%xmm0, %%xmm1		\n"
"			 psrlw		$4, %%xmm1			\n"
"			 pand      	%%xmm6, %%xmm0		\n"
"			 pand      	%%xmm6, %%xmm1		\n"
"			 movdqa    	%%xmm7, %%xmm2		\n"
"			 movdqa    	%%xmm7, %%xmm3		\n"
"			 pshufb    	%%xmm0, %%xmm2		\n"
"			 pshufb    	%%xmm1, %%xmm3		\n"
"			 paddb     	%%xmm2, %%xmm4		\n"
"			 paddb     	%%xmm3, %%xmm4		\n"
"			 pxor		%%xmm0, %%xmm0		\n"
"			 psadbw		%%xmm0, %%xmm4		\n"
"			 paddd		%%xmm4, %%xmm5		\n"
"			 movhlps   	%%xmm5, %%xmm0		\n"
"			 paddd     	%%xmm5, %%xmm0		\n"
"			 movd      	%%xmm0, %[res]		\n"
		:	 [res]	"=m"	(res)
		: 	 [x] 	"m" 	(array[i]),
			 [m] 	"m" 	(SSE_mask[0]),
			 [l] 	"m" 	(SSE_LUTb[0])
		);

		count += res;
		}

	return count;
}

void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2;			// gettimeofday() secs-usecs
    long tv_usecs;					// y sus cuentas

    gettimeofday(&tv1,NULL);
    resultado = func(lista);
    gettimeofday(&tv2,NULL);

    tv_usecs = (tv2.tv_sec -tv1.tv_sec )*1E6 + (tv2.tv_usec-tv1.tv_usec);
    
    /*printf("Tiempo: %d\t", resultado);
    printf("%s:%9ld us\n", msg, tv_usecs);*/

	#if COPY_PASTE
		printf("%ld \n", tv_usecs);
	#else
		printf("Tiempo: %d\t", resultado);
	#endif
}

int main(){

	int i, sumabits1, sumabits2, sumabits3, sumabits4, sumabits5;

	for (i=0; i<SIZE; i++)
		lista[i] = i;
/*
	sumabits1 = popcount1(lista);
	sumabits2 = popcount2(lista);
	sumabits3 = popcount3(lista);
	sumabits4 = popcount4(lista);
	sumabits5 = popcount5(lista);
	
	printf("Suma de bits del array calculada con método for/for: \t%d\n", sumabits1);
	printf("Suma de bits del array calculada con método for/while: \t%d\n", sumabits2);
	printf("Suma de bits del array calculada con método for/asm: \t%d\n", sumabits3);
	printf("Suma de bits del array calculada con método libro: \t%d\n", sumabits4);
	printf("Suma de bits del array calculada con método SSE3: \t%d\n", sumabits5);
*/
	crono(popcount1, "popcount1 (for/for)");
	crono(popcount2, "popcount1 (for/while)");
	crono(popcount3, "popcount1 (for/asm)");
	crono(popcount4, "popcount1 (libro)");
	crono(popcount5, "popcount1 (SSE3)");

    //printf("N*(N+1)/2 = %d\n", (SIZE-1)*(SIZE/2)); /*OF*/

    exit(0);
}
