#define SIZE (1<<20)

int parity2(int* array){
	int i, numero, paridad = 0, resultado = 0;

	for (i = 0; i < SIZE; i++){

		numero = array[i];		

		while (numero) {
			paridad ^= numero & 0x1;
			numero >>= 1;
		}

		resultado += paridad;
	}

	return resultado;
}
