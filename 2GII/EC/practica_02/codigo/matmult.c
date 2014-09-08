#include <stdio.h>		// para printf()
#include <stdlib.h>		// para exit()
#include <sys/time.h>	// para gettimeofday(), struct timeval

#define N (1<<8)
#define COPY_PASTE 1

typedef int matriz[N][N];

matriz A, B, C = {0};
int resultado = 0;

void inicializa_matrices(){
	int i, j, cont = 0;

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			A[i][j] = cont;

			cont++;
			
			if (cont == 100)
				cont = 0;
		}
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			B[i][j] = cont;

			cont++;
			
			if (cont == 100)
				cont = 0;
		}
	}

}

void mostrar_resultados(int n){
	printf("matmult%d:\n",n);
	printf("Esq. Sup. Izq.:[%d]\n", C[0][0]);
	printf("Esq. Sup. Der.:[%d]\n", C[0][255]);
	printf("Esq. Inf. Izq.:[%d]\n", C[255][0]);
	printf("Esq. Inf. Der.:[%d]\n", C[255][255]);
}

void vacia_matriz(){
	int i, j;

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++)
			C[i][j] = 0;
	}
}

int matmult1(){
	int i,j,k;

	for (i = 0; i < N; i++){						// Recorremos todas las filas de la matriz
		for (j = 0; j < N; j++){					// Recorremos todas las columnas de la matriz
			for (k = 0; k < N; k++){				
				C[i][j] += A[i][k] * B[k][j];		// Para cada casilla almacenamos el valor de la multiplicación.
			}
		}
	}

	return 1;	

}

int matmult2(){
	int i,j,k;

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			for (k = 0; k < N; k++){
				// Se calculan las direcciones de los elementos sumandole al indice las filas y el número de casillas de las columnas.
				*(*(C+i)+j) += *(*(A+i)+k) * *(*(B+k)+j);
			}
		}
	}

	return 2;

}

int matmult3(){
	int i,j,k,colB[N],*Ap,*Bp;

	for(j = 0; j < N; j++){							// Recorremos todas las columnas de la matriz.

		for(i = 0; i < N; i++)
			colB[i] = B[i][j];						// Copiamos a un vector todos los elementos de la columna.

			for(i = 0; i < N; i++){					// Recorremos todas las filas de la columna.
				Ap = A[i];							// Elementos de la primera fila.
				Bp = colB;							// Elementos de la primera columna.

				for (k = 0; k < N; k++)
					C[i][j] += Ap[k] * Bp[k];		// Se realiza la multiplicación.

				}

	}
	
	return 3;
}

void crono(int (*func)(), char* msg){
    struct timeval tv1,tv2;			// gettimeofday() secs-usecs
    long tv_usecs;					// y sus cuentas

    gettimeofday(&tv1,NULL);
    resultado = func();
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
/*
	inicializa_matrices();

	matmult1(A, B, C);

	mostrar_resultados(1);

	vacia_matriz(C);

	matmult2(A, B, C);

	mostrar_resultados(2);

	vacia_matriz(C);

	matmult3(A, B, C);

	mostrar_resultados(3);
*/
	crono(matmult1, "matmult1");
	crono(matmult2, "matmult2");
	crono(matmult2, "matmult3");

    //printf("N*(N+1)/2 = %d\n", (SIZE-1)*(SIZE/2)); /*OF*/

    exit(0);
}
