	.file	"popcount_while.c"
	.text
.globl popcount
	.type	popcount, @function
popcount:
	pushl	%ebp
	movl	%esp, %ebp
	movl	numero, %eax
	testl	%eax, %eax
	je	.L4
	movl	resultado, %edx
.L3:
	movl	%eax, %ecx
	andl	$1, %ecx
	addl	%ecx, %edx
	sarl	%eax
	jne	.L3
	movl	%edx, resultado
	movl	%eax, numero
.L4:
	popl	%ebp
	ret
	.size	popcount, .-popcount
.globl resultado
	.bss
	.align 4
	.type	resultado, @object
	.size	resultado, 4
resultado:
	.zero	4
	.comm	numero,4,4
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
