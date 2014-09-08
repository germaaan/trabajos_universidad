	.file	"linpack.cpp"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"\n[ERROR] - Debe introducir introducir dimension. \n"
	.align 8
.LC1:
	.string	"\n[ERROR] - El tama\303\261o tiene que ser un valor mayor que 0. \n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"INICIO"
.LC3:
	.string	"FIN"
.LC5:
	.string	"\tTiempo:\t%8.6f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB43:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA43
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	cmpl	$1, %edi
	jle	.L14
	.cfi_offset 3, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movl	%eax, %r13d
	cltq
	leaq	30(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	leaq	15(%rsp), %r12
	subq	%rax, %rsp
	leaq	15(%rsp), %rbx
	andq	$-16, %r12
	andq	$-16, %rbx
	testl	%r13d, %r13d
	jle	.L15
	xorl	%edx, %edx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%edx, (%rbx,%rax,4)
	movl	%eax, (%r12,%rax,4)
	addq	$1, %rax
	addl	$3, %edx
	cmpl	%eax, %r13d
	jg	.L3
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movl	$.LC2, %edi
.LEHB0:
	call	puts
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L4:
	movl	(%r12,%rax,4), %edx
	leal	(%rdx,%rdx,4), %edx
	addl	%edx, (%rbx,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %r13d
	jg	.L4
	movl	$.LC3, %edi
	call	puts
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	$.LC5, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC4(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
.LEHE0:
	xorl	%eax, %eax
	movq	-40(%rbp), %rdx
	xorq	%fs:40, %rdx
	jne	.L16
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L16:
	.cfi_restore_state
	call	__stack_chk_fail
.L8:
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L15:
	movq	stderr(%rip), %rcx
	movl	$59, %edx
	movl	$1, %esi
	movl	$.LC1, %edi
.LEHB2:
	call	fwrite
.L12:
	orl	$-1, %edi
	call	exit
.L14:
	movq	stderr(%rip), %rcx
	movl	$50, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
.LEHE2:
	jmp	.L12
	.cfi_endproc
.LFE43:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA43:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE43-.LLSDACSB43
.LLSDACSB43:
	.uleb128 .LEHB0-.LFB43
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L8-.LFB43
	.uleb128 0
	.uleb128 .LEHB1-.LFB43
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB2-.LFB43
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L8-.LFB43
	.uleb128 0
.LLSDACSE43:
	.section	.text.startup
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC4:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
