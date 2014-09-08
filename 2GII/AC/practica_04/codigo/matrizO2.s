	.file	"matriz.cpp"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"\n[ERROR] - Debe introducir introducir dimension. \n"
	.align 8
.LC1:
	.string	"\n[ERROR] - El tama\303\261o de filas y columnas tiene que ser un valor entre 4 y 4094. \n"
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
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$72, %rsp
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	cmpl	$1, %edi
	jle	.L28
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movslq	%eax, %r12
	movl	%eax, %r13d
	movq	%r12, %rax
	imulq	%r12, %rax
	leaq	30(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	leaq	15(%rsp), %r15
	subq	%rax, %rsp
	leaq	15(%rsp), %r14
	subq	%rax, %rsp
	leal	-4(%r13), %eax
	leaq	15(%rsp), %rbx
	andq	$-16, %r15
	andq	$-16, %r14
	andq	$-16, %rbx
	cmpl	$4090, %eax
	ja	.L29
	xorl	%ecx, %ecx
.L3:
	movslq	%ecx, %rax
	xorl	%edx, %edx
	imulq	%r12, %rax
	leaq	(%r15,%rax,4), %rax
	.p2align 4,,10
	.p2align 3
.L4:
	addl	$4, %edx
	movl	$0, (%rax)
	movl	$0, 4(%rax)
	movl	$0, 8(%rax)
	movl	$0, 12(%rax)
	addq	$16, %rax
	cmpl	%r13d, %edx
	jl	.L4
	addl	$1, %ecx
	cmpl	%r13d, %ecx
	jl	.L3
	xorl	%edi, %edi
	movl	$1, %edx
.L5:
	movslq	%edi, %rax
	xorl	%ecx, %ecx
	imulq	%r12, %rax
	leaq	(%r14,%rax,4), %rax
	.p2align 4,,10
	.p2align 3
.L6:
	leal	1(%rdx), %esi
	addl	$4, %ecx
	movl	%edx, (%rax)
	movl	%esi, 4(%rax)
	leal	2(%rdx), %esi
	movl	%esi, 8(%rax)
	leal	3(%rdx), %esi
	addl	$4, %edx
	movl	%esi, 12(%rax)
	addq	$16, %rax
	cmpl	%r13d, %ecx
	jl	.L6
	addl	$1, %edi
	cmpl	%r13d, %edi
	jl	.L5
	xorl	%edi, %edi
	movl	$2, %edx
.L7:
	movslq	%edi, %rax
	xorl	%ecx, %ecx
	imulq	%r12, %rax
	leaq	(%rbx,%rax,4), %rax
	.p2align 4,,10
	.p2align 3
.L8:
	leal	1(%rdx), %esi
	addl	$4, %ecx
	movl	%edx, (%rax)
	movl	%esi, 4(%rax)
	leal	2(%rdx), %esi
	movl	%esi, 8(%rax)
	leal	3(%rdx), %esi
	addl	$4, %edx
	movl	%esi, 12(%rax)
	addq	$16, %rax
	cmpl	%r13d, %ecx
	jl	.L8
	addl	$1, %edi
	cmpl	%r13d, %edi
	jl	.L7
	leaq	-96(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movl	$.LC2, %edi
.LEHB0:
	call	puts
	leaq	0(,%r12,4), %rdx
	xorl	%r11d, %r11d
	movq	%rdx, -104(%rbp)
.L10:
	movslq	%r11d, %rax
	xorl	%r9d, %r9d
	imulq	%r12, %rax
	leaq	(%r14,%rax,4), %r10
	.p2align 4,,10
	.p2align 3
.L14:
	movl	(%r15,%r9,4), %esi
	movq	%r10, %rdx
	xorl	%eax, %eax
	movslq	%r9d, %rcx
	.p2align 4,,10
	.p2align 3
.L11:
	movslq	%eax, %rdi
	movl	(%rdx), %r8d
	imulq	%r12, %rdi
	addq	%rcx, %rdi
	imull	(%rbx,%rdi,4), %r8d
	leal	1(%rax), %edi
	movslq	%edi, %rdi
	imulq	%r12, %rdi
	addl	%r8d, %esi
	movl	4(%rdx), %r8d
	addq	%rcx, %rdi
	imull	(%rbx,%rdi,4), %r8d
	movl	8(%rdx), %edi
	addl	%esi, %r8d
	leal	2(%rax), %esi
	movslq	%esi, %rsi
	imulq	%r12, %rsi
	addq	%rcx, %rsi
	imull	(%rbx,%rsi,4), %edi
	movl	12(%rdx), %esi
	addq	$16, %rdx
	addl	%r8d, %edi
	leal	3(%rax), %r8d
	addl	$4, %eax
	movslq	%r8d, %r8
	imulq	%r12, %r8
	addq	%rcx, %r8
	imull	(%rbx,%r8,4), %esi
	addl	%edi, %esi
	cmpl	%r13d, %eax
	jl	.L11
	movl	%esi, (%r15,%r9,4)
	addq	$1, %r9
	cmpl	%r9d, %r13d
	jg	.L14
	addl	$1, %r11d
	addq	-104(%rbp), %r15
	cmpl	%r13d, %r11d
	jl	.L10
	movl	$.LC3, %edi
	call	puts
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-80(%rbp), %rax
	subq	-96(%rbp), %rax
	movl	$.LC5, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-72(%rbp), %rax
	subq	-88(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC4(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	xorl	%eax, %eax
	movq	-56(%rbp), %rdx
	xorq	%fs:40, %rdx
	jne	.L30
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L28:
	.cfi_restore_state
	movq	stderr(%rip), %rcx
	movl	$50, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
.L26:
	orl	$-1, %edi
	call	exit
.L29:
	movq	stderr(%rip), %rcx
	movl	$82, %edx
	movl	$1, %esi
	movl	$.LC1, %edi
	call	fwrite
.LEHE0:
	jmp	.L26
.L20:
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L30:
	.p2align 4,,5
	call	__stack_chk_fail
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
	.uleb128 .L20-.LFB43
	.uleb128 0
	.uleb128 .LEHB1-.LFB43
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
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
