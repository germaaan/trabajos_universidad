.section .data
saludo:		.ascii	"Hola a todos!\nHello, World!\n"
longsaludo:	.int	.-saludo

.section .text
.global _start
_start:
	mov         $4, %eax
	mov         $1, %ebx
	mov    $saludo, %ecx
	mov longsaludo, %edx
	int $0x80

	mov $1, %eax
	mov $0, %ebx
	int $0x80

