.section .data
lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
longlista:	.int (.-lista)/4
resultado:	.int -1

.section .text
_start:	.global _start

	mov    $lista, %ebx
	mov longlista, %ecx
	call suma
	mov %eax, resultado

	mov $1, %eax
	mov $0, %ebx
	int $0x80

suma:
	push %edx
	mov $0, %eax
	mov $0, %edx
bucle:
	add (%ebx,%edx,4), %eax
	inc       %edx
	cmp  %edx,%ecx
	jne bucle

	pop %edx
	ret
