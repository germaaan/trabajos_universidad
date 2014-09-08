int numero, paridad=0;

void parity() {
	while (numero) {
		paridad ^= numero & 0x1;
		numero >>= 1;
	}
}
