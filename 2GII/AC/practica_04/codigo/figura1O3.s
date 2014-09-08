	.file	"figura1.cpp"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"INICIO"
.LC1:
	.string	"FIN"
.LC3:
	.string	"\tTiempo:\t%8.6f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB43:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$80000, %edi
	call	malloc
	call	clock
	movl	$.LC0, %edi
	movq	%rax, %rbx
	call	puts
	movl	$.LC1, %edi
	call	puts
	call	clock
	subq	%rbx, %rax
	movl	$.LC3, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movl	$1, %eax
	divsd	.LC2(%rip), %xmm0
	call	__printf_chk
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE43:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	0
	.long	1093567616
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
