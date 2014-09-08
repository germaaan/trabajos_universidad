//Orden de compilación usada:	gcc -m32 -O2 bomba.c -o bomba

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

//char spacing83[] = "ordenador\n";		//ASCII: 111 114 100 101 110 97 100 111 114 10	
																		// Clave es "ordenador", pero para que no sea tan obvia
char spacing83[] = {113, 116, 102, 103, 112, 99, 102, 113, 116, 12};	// en codigo ASCII incrementados en 2 todos sus caracteres

int  spacing53 = 85476;		// Clave de la que partimos, da igual que sea conocida, porque 
							// para comprobar que la clave es correcta sólo se puede llegar
							// mediante una serie de operaciones matemáticas, no sirve 
							// introducirla directamente:
							// 85476 / 2 = 42738 * 3 = 128214 + 55 = 128269 <-- Clave correcta

void unnamed1(){
	printf("\nERROR DESCONOCIDO: la BOMBA ha sido ACTIVADA\n");
//	printf("##########     *********     ********     *******     ······     ·····     ····     ...     ..     .     ");
	printf(".     ..     ...     ····     ·····     ······     *******     ********     *********     ##########     ");
	printf("BOOOM!!!\n\n");
	exit(-1);
}

void unnamed3(){
	unnamed1();
}

void unnamed2(){
	printf("\nACCESO PERMITIDO: la BOMBA ha sido DESACTIVADA\n\n");
	exit(0);
}

void unnamed88(char *pcpp){
	char spaux[strlen(spacing83)];
	int i=0;

	if (strlen(pcpp) != strlen(spacing83))
		unnamed3();

//	printf("\nLongitud correcta.\n\n");

	// Rellenamos un vector de caracteres auxiliar con los caracteres de la cadena introducida por teclado
	// a los que le aplicamos el mismo incremento de valor que a la cadena clave.
	while(i < strlen(spacing83)){
		spaux[i] = pcpp[i]+2;
		
		//printf("%c\t%c",spaux[i],spacing83[i]);
		//printf("\n");

		i++;
	}

	if (strncmp(spaux,spacing83,strlen(spacing83)))
		unnamed3();

//	printf("Comparación clave correcta.\n\n");
}

void unnamed503(int pcvv){
	int aux = spacing53;

	// Calculamos si la clave introducida es correcta.
	aux = spacing53 / 2;
	aux = aux * 3;
	aux = aux + 55;

//	printf("\nValor introducido: %d", pcvv);
//	printf("\nSecuencia de comprobación: %d//2 = %d*3 = %d+55 == %d", spacing53, spacing53/2, (spacing53/2)*3, ((spacing53/2)*3)+55);

	if (pcvv != aux)
		unnamed3();

//	printf("\n\nComparacion código válida.\n\n");

}

int main(){
#define SIZE 100
	char cpp[SIZE];
	int  cvv;
#define TLIM 60
	struct timeval tv1,tv2;

	gettimeofday(&tv1,NULL);

	printf("Introduce la contraseña: ");
	fgets(cpp,SIZE,stdin);
	unnamed88(cpp);

	gettimeofday(&tv2,NULL);
	if (tv2.tv_sec - tv1.tv_sec > TLIM)
	    unnamed3();

	printf("Introduce el código: ");
	scanf("%i",&cvv);
	//if (cvv!=spacing53) unnamed3();
	unnamed503(cvv);

	gettimeofday(&tv1,NULL);
	if (tv1.tv_sec - tv2.tv_sec > TLIM)
	    unnamed3();

	unnamed2();
}
