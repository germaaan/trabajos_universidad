#include <stdio.h>		// printf()
#include <stdlib.h>		// exit()
#include <sys/time.h>	// gettimeofday(), struct timeval

#define SIZE (1<<20)			// Tamaño (en número de elementos) del vector.
#define WSIZE 8*sizeof(int)		// Tamaño (en número de bits) de los elementos del vector.
#define COPY_PASTE 1

int lista[SIZE];
int resultado = 0;

int parity1(int* array){
	int i, j, numero, paridad = 0, contador = 0;

	for (i = 0; i < SIZE; i++){			// Para todos los números del vector:

		numero = array[i];				// Extraemos un número.

		for (j = 0; j < WSIZE; j++){	// Recorremos todos los bits del número.
			paridad ^= numero & 0x1;	// Extrayendo los bits con una máscara AND (0x1), acumulándolos con XOR (^=).
			numero >>= 1;				// Realizamos el desplazamiento de los bits a la derecha.
		}

		contador += paridad;			// Acumulamos la paridad calculada.
	}

	return contador;
}

int parity2(int* array){
	int i, numero, paridad = 0, contador = 0;

	for (i = 0; i < SIZE; i++){

		numero = array[i];		

		while (numero) {
			paridad ^= numero & 0x1;
			numero >>= 1;
		}

		contador += paridad;
	}

	return contador;
}

int parity3(int* array){
	int i, numero, paridad = 0, contador = 0;

	for (i = 0; i < SIZE; i++){

		numero = array[i];		

		asm("movl	%[n],%%eax		\n"		// Movemos el número que hemos sacado de la lista a un registro.
"			testl	%%eax,%%eax		\n"		// Comparamos los valores del registro.
"			je		fin				\n"		// Saltamos a la etiqueta fin si el código de condición es 0.
"			movl	%[p],%%edx		\n"		// Movemos la variable paridad a un registro.
"bucle:								\n"
"			movl	%%eax, %%ecx	\n"		// Movemos el valor del registro con el número a otro registro.
"			andl	$1, %%ecx		\n"		// Extraemos los bits con una máscara AND (0x1).
"			xorl	%%ecx, %%edx	\n"		// Acumulándolos con XOR (^=) en otro registro.
"			sarl	%%eax			\n"		// Desplazamos los bits del número.
"			jne		bucle			\n"		// Si el código de condición no es 0, saltamos al inicio del bucle.
"			movl	%%edx, %[p]		\n"		// Movemos el valor del registro con la suma de paridad a la variable paridad.
"fin:								\n"
		 :	[p] "+r"	(paridad)	// output-input
		 :	[n] "r"		(numero)	// input
//		 :	"cc"					// clobber
//			"eax","ecx","edx"
		);

		contador += paridad;
	}

	return contador;
}

int parity4(int* array){
	asm("pushl	%ebx				\n" // clobber
"		movl	8(%ebp), %edi		\n"		// array
"		movl	$0, %ebx			\n"		// contador
"		movl	$0, %ecx			\n"		// paridad
"		movl	$1, %esi			\n"		// i
"condicion:							\n"
"		movl	(%edi,%esi,4), %edx	\n"		// Movemos el número correspondiente desde el array a un registro.
"		testl	%edx, %edx			\n"
"		je		for					\n"
"while:								\n"
"		movl	%edx, %eax			\n"
"		andl	$1, %eax			\n"
"		xorl	%eax, %ecx			\n"
"		sarl	%edx				\n"
"		jne		while				\n"
"for:								\n"
"		addl	%ecx, %ebx			\n"		// Sumamos la paridad calculada al contador.
"		addl	$1, %esi			\n"		// Sumamos 1 al indice del for.
"		cmpl	$1048576, %esi		\n"		// Comparamos si hemos llegado al final.
"		jne		condicion			\n"		// Si el código de condición no es igual, saltamos a la etiqueta condición.
"		movl	%ebx, %eax			\n"		
"		popl	%ebx				\n"		// Sacamos el valor del contador.
//   : 								// output
//   : 								// input
//   : "cc",						// clobber
//     "eax","ebx","ecx","edx","esi","edi"
    );
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
	int i, paridad1, paridad2, paridad3, paridad4;

	for (i=0; i<SIZE; i++)
		lista[i] = i;
/*
	paridad1 = parity1(lista);
	paridad2 = parity2(lista);
	paridad3 = parity3(lista);
	paridad4 = parity4(lista);

	printf("Paridad del array calculada con método for/for: \t%d\n", paridad1);
	printf("Paridad del array calculada con método for/while: \t%d\n", paridad2);
	printf("Paridad del array calculada con método for/asm: \t%d\n", paridad3);
	printf("Paridad del array calculada con método asm: \t\t%d\n", paridad4);
*/
	crono(parity1, "parity1 (for/for)");
	crono(parity2, "parity2 (for/while)");
	crono(parity3, "parity3 (for/asm)");
	crono(parity4, "parity4 (asm)");

    //printf("N*(N+1)/2 = %d\n", (SIZE-1)*(SIZE/2)); /*OF*/

    exit(0);
}
