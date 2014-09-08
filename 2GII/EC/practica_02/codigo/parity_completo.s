	.file	"parity_completo.c"
	.text
.globl parity2
	.type	parity2, @function
parity2:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -4(%ebp)
	jmp	.L2
.L5:
	movl	-4(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	jmp	.L3
.L4:
	movl	-8(%ebp), %eax
	andl	$1, %eax
	xorl	%eax, -12(%ebp)
	sarl	-8(%ebp)
.L3:
	cmpl	$0, -8(%ebp)
	jne	.L4
	movl	-12(%ebp), %eax
	addl	%eax, -16(%ebp)
	addl	$1, -4(%ebp)
.L2:
	cmpl	$1048575, -4(%ebp)
	jle	.L5
	movl	-16(%ebp), %eax
	leave
	ret
	.size	parity2, .-parity2
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
