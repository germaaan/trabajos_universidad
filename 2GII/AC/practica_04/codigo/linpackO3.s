	.file	"linpack.cpp"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"\n[ERROR] - Debe introducir introducir dimension. \n"
	.align 8
.LC1:
	.string	"\n[ERROR] - El tama\303\261o tiene que ser un valor mayor que 0. \n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC4:
	.string	"INICIO"
.LC6:
	.string	"FIN"
.LC8:
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
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	cmpl	$1, %edi
	jle	.L33
	.cfi_offset 3, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movslq	%eax, %rdx
	movl	%eax, %r13d
	leaq	30(,%rdx,4), %rdx
	andq	$-16, %rdx
	subq	%rdx, %rsp
	leaq	15(%rsp), %rbx
	subq	%rdx, %rsp
	leaq	15(%rsp), %r12
	andq	$-16, %rbx
	andq	$-16, %r12
	testl	%eax, %eax
	jle	.L34
	xorl	%esi, %esi
	movl	%eax, %r14d
	testl	%esi, %esi
	movl	%esi, %edi
	je	.L20
	xorl	%ecx, %ecx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	movl	%ecx, (%r12,%rax,4)
	movl	%eax, (%rbx,%rax,4)
	leal	1(%rax), %edx
	addq	$1, %rax
	addl	$3, %ecx
	cmpl	%eax, %esi
	ja	.L5
	cmpl	%esi, %r14d
	je	.L6
.L4:
	movl	%r14d, %r10d
	subl	%esi, %r10d
	movl	%r10d, %esi
	shrl	$2, %esi
	leal	0(,%rsi,4), %r9d
	testl	%r9d, %r9d
	je	.L7
	leal	1(%rdx), %eax
	movl	%edx, -96(%rbp)
	salq	$2, %rdi
	leaq	(%rbx,%rdi), %r8
	movdqa	.LC2(%rip), %xmm5
	movl	%eax, -84(%rbp)
	leal	2(%rdx), %eax
	addq	%r12, %rdi
	movd	-84(%rbp), %xmm2
	xorl	%ecx, %ecx
	movl	%eax, -88(%rbp)
	leal	3(%rdx), %eax
	movd	-88(%rbp), %xmm1
	movl	%eax, -92(%rbp)
	xorl	%eax, %eax
	movd	-92(%rbp), %xmm0
	punpckldq	%xmm0, %xmm1
	movd	-96(%rbp), %xmm0
	punpckldq	%xmm2, %xmm0
	punpcklqdq	%xmm1, %xmm0
	movdqa	.LC3(%rip), %xmm1
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L21:
	movdqa	%xmm4, %xmm0
.L8:
	movdqa	%xmm0, %xmm3
	addl	$1, %ecx
	movdqa	%xmm1, %xmm2
	movdqa	%xmm0, %xmm4
	pmuludq	%xmm1, %xmm3
	movdqa	%xmm0, (%r8,%rax)
	psrldq	$4, %xmm2
	psrldq	$4, %xmm0
	pmuludq	%xmm0, %xmm2
	pshufd	$8, %xmm3, %xmm0
	paddd	%xmm5, %xmm4
	pshufd	$8, %xmm2, %xmm2
	punpckldq	%xmm2, %xmm0
	movdqu	%xmm0, (%rdi,%rax)
	addq	$16, %rax
	cmpl	%esi, %ecx
	jb	.L21
	addl	%r9d, %edx
	cmpl	%r9d, %r10d
	je	.L6
.L7:
	leal	(%rdx,%rdx,2), %eax
	.p2align 4,,10
	.p2align 3
.L10:
	movslq	%edx, %rcx
	movl	%edx, (%rbx,%rcx,4)
	addl	$1, %edx
	movl	%eax, (%r12,%rcx,4)
	addl	$3, %eax
	cmpl	%edx, %r13d
	jg	.L10
.L6:
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movl	$.LC4, %edi
.LEHB0:
	call	puts
	xorl	%ecx, %ecx
	testl	%ecx, %ecx
	movl	%ecx, %esi
	je	.L22
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L12:
	movl	(%rbx,%rax,4), %edx
	leal	(%rdx,%rdx,4), %edx
	addl	%edx, (%r12,%rax,4)
	leal	1(%rax), %edx
	addq	$1, %rax
	cmpl	%eax, %ecx
	ja	.L12
	cmpl	%r14d, %ecx
	je	.L13
.L11:
	subl	%ecx, %r14d
	movl	%r14d, %edi
	shrl	$2, %edi
	leal	0(,%rdi,4), %r9d
	testl	%r9d, %r9d
	je	.L24
	salq	$2, %rsi
	movdqa	.LC5(%rip), %xmm2
	leaq	(%rbx,%rsi), %r8
	xorl	%eax, %eax
	addq	%r12, %rsi
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L15:
	movdqu	(%r8,%rax), %xmm1
	addl	$1, %ecx
	movdqa	%xmm2, %xmm3
	movdqa	%xmm1, %xmm0
	psrldq	$4, %xmm1
	psrldq	$4, %xmm3
	pmuludq	%xmm3, %xmm1
	pshufd	$8, %xmm1, %xmm1
	pmuludq	%xmm2, %xmm0
	pshufd	$8, %xmm0, %xmm0
	punpckldq	%xmm1, %xmm0
	paddd	(%rsi,%rax), %xmm0
	movdqa	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpl	%edi, %ecx
	jb	.L15
	addl	%r9d, %edx
	cmpl	%r9d, %r14d
	je	.L13
	.p2align 4,,10
	.p2align 3
.L24:
	movslq	%edx, %rax
	addl	$1, %edx
	movl	(%rbx,%rax,4), %ecx
	leal	(%rcx,%rcx,4), %ecx
	addl	%ecx, (%r12,%rax,4)
	cmpl	%edx, %r13d
	jg	.L24
.L13:
	movl	$.LC6, %edi
	call	puts
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	$.LC8, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC7(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
.LEHE0:
	xorl	%eax, %eax
	movq	-40(%rbp), %rdx
	xorq	%fs:40, %rdx
	jne	.L35
	leaq	-32(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L35:
	.cfi_restore_state
	call	__stack_chk_fail
.L22:
	xorl	%edx, %edx
	jmp	.L11
.L23:
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L20:
	xorl	%edx, %edx
	jmp	.L4
.L34:
	movq	stderr(%rip), %rcx
	movl	$59, %edx
	movl	$1, %esi
	movl	$.LC1, %edi
.LEHB2:
	call	fwrite
.L31:
	orl	$-1, %edi
	call	exit
.L33:
	movq	stderr(%rip), %rcx
	movl	$50, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
.LEHE2:
	jmp	.L31
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
	.uleb128 .L23-.LFB43
	.uleb128 0
	.uleb128 .LEHB1-.LFB43
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB2-.LFB43
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L23-.LFB43
	.uleb128 0
.LLSDACSE43:
	.section	.text.startup
	.size	main, .-main
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC2:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 16
.LC3:
	.long	3
	.long	3
	.long	3
	.long	3
	.align 16
.LC5:
	.long	5
	.long	5
	.long	5
	.long	5
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC7:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
