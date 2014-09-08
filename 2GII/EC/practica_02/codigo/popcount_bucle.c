int numero, resultado=0;

void popcount() {
	while (numero) {
		resultado += numero & 0x1;
		numero >>= 1;
	}
}
