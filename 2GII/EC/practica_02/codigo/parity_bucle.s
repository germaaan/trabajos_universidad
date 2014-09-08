	.file	"parity_bucle.c"
	.comm	numero,4,4
.globl paridad
	.bss
	.align 4
	.type	paridad, @object
	.size	paridad, 4
paridad:
	.zero	4
	.text
.globl parity
	.type	parity, @function
parity:
	pushl	%ebp
	movl	%esp, %ebp
	jmp	.L2
.L3:
	movl	numero, %eax
	movl	%eax, %edx
	andl	$1, %edx
	movl	paridad, %eax
	xorl	%edx, %eax
	movl	%eax, paridad
	movl	numero, %eax
	sarl	%eax
	movl	%eax, numero
.L2:
	movl	numero, %eax
	testl	%eax, %eax
	jne	.L3
	popl	%ebp
	ret
	.size	parity, .-parity
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
