	.file	"exec.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"backtrace() returned %d addresses\n"
.LC1:
	.string	"backtrace_symbols"
	.text
	.globl	myfunc3
	.type	myfunc3, @function
myfunc3:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$816, %rsp
	leaq	-800(%rbp), %rax
	movl	$100, %esi
	movq	%rax, %rdi
	call	backtrace
	movl	%eax, -812(%rbp)
	movl	-812(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	-812(%rbp), %edx
	leaq	-800(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	backtrace_symbols
	movq	%rax, -808(%rbp)
	cmpq	$0, -808(%rbp)
	jne	.L2
	movl	$.LC1, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L2:
	movl	$0, -816(%rbp)
	jmp	.L3
.L4:
	movl	-816(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-808(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	puts
	addl	$1, -816(%rbp)
.L3:
	movl	-816(%rbp), %eax
	cmpl	-812(%rbp), %eax
	jl	.L4
	movq	-808(%rbp), %rax
	movq	%rax, %rdi
	call	free
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	myfunc3, .-myfunc3
	.type	myfunc2, @function
myfunc2:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	myfunc3
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	myfunc2, .-myfunc2
	.globl	myfunc
	.type	myfunc, @function
myfunc:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$1, -4(%rbp)
	jle	.L7
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	myfunc
	jmp	.L6
.L7:
	call	myfunc2
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	myfunc, .-myfunc
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
