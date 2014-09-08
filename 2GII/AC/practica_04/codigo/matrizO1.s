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
	.text
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
	subq	$88, %rsp
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	cmpl	$1, %edi
	jg	.L2
	.cfi_offset 3, -56
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	stderr(%rip), %rcx
	movl	$50, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
.LEHB0:
	call	fwrite
	movl	$-1, %edi
	call	exit
.L2:
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movl	%eax, %r14d
	movslq	%eax, %r15
	movq	%r15, %r13
	movq	%r15, %rax
	imulq	%r15, %rax
	leaq	30(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	leaq	15(%rsp), %rdx
	andq	$-16, %rdx
	movq	%rdx, -104(%rbp)
	movq	%rdx, %rcx
	subq	%rax, %rsp
	leaq	15(%rsp), %r12
	andq	$-16, %r12
	subq	%rax, %rsp
	leaq	15(%rsp), %rbx
	andq	$-16, %rbx
	leal	-4(%r14), %eax
	cmpl	$4090, %eax
	ja	.L3
	movl	$0, %edi
	testl	%r14d, %r14d
	jg	.L26
	jmp	.L5
.L3:
	movq	stderr(%rip), %rcx
	movl	$82, %edx
	movl	$1, %esi
	movl	$.LC1, %edi
	call	fwrite
	movl	$-1, %edi
	call	exit
.L6:
	movslq	%eax, %rsi
	addq	%rdx, %rsi
	movl	$0, (%rcx,%rsi,4)
	leal	1(%rax), %esi
	movslq	%esi, %rsi
	addq	%rdx, %rsi
	movl	$0, (%rcx,%rsi,4)
	leal	2(%rax), %esi
	movslq	%esi, %rsi
	addq	%rdx, %rsi
	movl	$0, (%rcx,%rsi,4)
	leal	3(%rax), %esi
	movslq	%esi, %rsi
	addq	%rdx, %rsi
	movl	$0, (%rcx,%rsi,4)
	addl	$4, %eax
	cmpl	%r14d, %eax
	jl	.L6
	addl	$1, %edi
	cmpl	%r14d, %edi
	jge	.L19
.L26:
	movl	$0, %eax
	movslq	%edi, %rdx
	imulq	%r13, %rdx
	jmp	.L6
.L8:
	movslq	%eax, %rsi
	addq	%rcx, %rsi
	movl	%edx, (%r12,%rsi,4)
	leal	1(%rax), %esi
	movslq	%esi, %rsi
	addq	%rcx, %rsi
	leal	1(%rdx), %edi
	movl	%edi, (%r12,%rsi,4)
	leal	2(%rax), %esi
	movslq	%esi, %rsi
	addq	%rcx, %rsi
	leal	2(%rdx), %edi
	movl	%edi, (%r12,%rsi,4)
	leal	3(%rax), %esi
	movslq	%esi, %rsi
	addq	%rcx, %rsi
	leal	3(%rdx), %edi
	movl	%edi, (%r12,%rsi,4)
	addl	$4, %edx
	addl	$4, %eax
	cmpl	%r14d, %eax
	jl	.L8
	addl	$1, %r8d
	cmpl	%r14d, %r8d
	jl	.L7
	jmp	.L29
.L19:
	movl	$0, %r8d
	movl	$1, %edx
.L7:
	movl	$0, %eax
	movslq	%r8d, %rcx
	imulq	%r13, %rcx
	jmp	.L8
.L10:
	movslq	%eax, %rsi
	addq	%rcx, %rsi
	movl	%edx, (%rbx,%rsi,4)
	leal	1(%rax), %esi
	movslq	%esi, %rsi
	addq	%rcx, %rsi
	leal	1(%rdx), %edi
	movl	%edi, (%rbx,%rsi,4)
	leal	2(%rax), %esi
	movslq	%esi, %rsi
	addq	%rcx, %rsi
	leal	2(%rdx), %edi
	movl	%edi, (%rbx,%rsi,4)
	leal	3(%rax), %esi
	movslq	%esi, %rsi
	addq	%rcx, %rsi
	leal	3(%rdx), %edi
	movl	%edi, (%rbx,%rsi,4)
	addl	$4, %edx
	addl	$4, %eax
	cmpl	%r14d, %eax
	jl	.L10
	addl	$1, %r8d
	cmpl	%r14d, %r8d
	jl	.L9
	jmp	.L5
.L29:
	movl	$0, %r8d
	movl	$2, %edx
.L9:
	movl	$0, %eax
	movslq	%r8d, %rcx
	imulq	%r13, %rcx
	jmp	.L10
.L5:
	leaq	-96(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$.LC2, %edi
	call	puts
	testl	%r14d, %r14d
	jle	.L11
	salq	$2, %r15
	movq	%r15, -120(%rbp)
	movl	$0, -108(%rbp)
	jmp	.L12
.L13:
	leal	1(%rax), %r9d
	leal	2(%rax), %r8d
	movslq	%eax, %rsi
	leaq	(%rsi,%rcx), %r10
	imulq	%r13, %rsi
	addq	%rdx, %rsi
	movl	(%r12,%r10,4), %r10d
	imull	(%rbx,%rsi,4), %r10d
	addl	%r10d, %edi
	movslq	%r9d, %r9
	leaq	(%r9,%rcx), %rsi
	imulq	%r13, %r9
	addq	%rdx, %r9
	movl	(%r12,%rsi,4), %esi
	imull	(%rbx,%r9,4), %esi
	addl	%esi, %edi
	movslq	%r8d, %r8
	leaq	(%r8,%rcx), %rsi
	imulq	%r13, %r8
	addq	%rdx, %r8
	movl	(%r12,%rsi,4), %esi
	imull	(%rbx,%r8,4), %esi
	addl	%esi, %edi
	leal	3(%rax), %r8d
	movslq	%r8d, %r8
	leaq	(%r8,%rcx), %rsi
	imulq	%r13, %r8
	addq	%rdx, %r8
	movl	(%r12,%rsi,4), %esi
	imull	(%rbx,%r8,4), %esi
	addl	%esi, %edi
	addl	$4, %eax
	cmpl	%r14d, %eax
	jl	.L13
	movl	%edi, (%r15,%r11,4)
	addq	$1, %r11
	cmpl	%r11d, %r14d
	jle	.L14
.L15:
	movq	-104(%rbp), %r15
	movl	(%r15,%r11,4), %edi
	movl	$0, %eax
	movslq	%r11d, %rdx
	jmp	.L13
.L14:
	addl	$1, -108(%rbp)
	movq	-120(%rbp), %rax
	addq	%rax, -104(%rbp)
	cmpl	%r14d, -108(%rbp)
	jge	.L11
.L12:
	movl	$0, %r11d
	movslq	-108(%rbp), %rcx
	imulq	%r13, %rcx
	jmp	.L15
.L11:
	movl	$.LC3, %edi
	call	puts
	leaq	-80(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-80(%rbp), %rax
	subq	-96(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-72(%rbp), %rax
	subq	-88(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC4(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movl	$.LC5, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
.LEHE0:
	movl	$0, %eax
	movq	-56(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L17
	jmp	.L30
.L21:
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L30:
	.p2align 4,,5
	call	__stack_chk_fail
.L17:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
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
	.uleb128 .L21-.LFB43
	.uleb128 0
	.uleb128 .LEHB1-.LFB43
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE43:
	.text
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC4:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
