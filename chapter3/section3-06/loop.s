	.file	"loop.c"
	.text
	.globl	fact_do
	.type	fact_do, @function
fact_do:
.LFB0:
	.cfi_startproc
	movl	$1, %eax
.L2:
	imulq	%rdi, %rax
	subq	$1, %rdi
	cmpq	$1, %rdi
	jg	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	fact_do, .-fact_do
	.globl	fact_while
	.type	fact_while, @function
fact_while:
.LFB1:
	.cfi_startproc
	movl	$1, %eax
	jmp	.L4
.L5:
	imulq	%rdi, %rax
	subq	$1, %rdi
.L4:
	cmpq	$1, %rdi
	jg	.L5
	ret
	.cfi_endproc
.LFE1:
	.size	fact_while, .-fact_while
	.globl	fact_for
	.type	fact_for, @function
fact_for:
.LFB2:
	.cfi_startproc
	movl	$2, %eax
	movl	$1, %edx
	jmp	.L7
.L8:
	imulq	%rax, %rdx
	addq	$1, %rax
.L7:
	cmpq	%rdi, %rax
	jle	.L8
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE2:
	.size	fact_for, .-fact_for
	.ident	"GCC: (GNU) 14.1.1 20240522 (Red Hat 14.1.1-4)"
	.section	.note.GNU-stack,"",@progbits
