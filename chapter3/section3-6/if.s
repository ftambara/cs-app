	.file	"if.c"
	.text
	.p2align 4
	.globl	absdiff_se
	.type	absdiff_se, @function
absdiff_se:
.LFB0:
	.cfi_startproc
	cmpq	%rsi, %rdi
	jge	.L2
	movq	%rsi, %rax
	addq	$1, lt_cnt(%rip)
	subq	%rdi, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L2:
	movq	%rdi, %rax
	addq	$1, ge_cnt(%rip)
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	absdiff_se, .-absdiff_se
	.p2align 4
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB1:
	.cfi_startproc
	movq	%rsi, %rdx
	movq	%rdi, %rax
	subq	%rdi, %rdx
	subq	%rsi, %rax
	cmpq	%rsi, %rdi
	cmovl	%rdx, %rax
	ret
	.cfi_endproc
.LFE1:
	.size	absdiff, .-absdiff
	.globl	ge_cnt
	.bss
	.align 8
	.type	ge_cnt, @object
	.size	ge_cnt, 8
ge_cnt:
	.zero	8
	.globl	lt_cnt
	.align 8
	.type	lt_cnt, @object
	.size	lt_cnt, 8
lt_cnt:
	.zero	8
	.ident	"GCC: (GNU) 14.1.1 20240522 (Red Hat 14.1.1-4)"
	.section	.note.GNU-stack,"",@progbits
