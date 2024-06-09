	.file	"3-7.c"
	.text
	.p2align 4
	.globl	scale3
	.type	scale3, @function
scale3:
.LFB0:
	.cfi_startproc
	addl	$10, %edi
	imull	%esi, %edi
	leal	(%rdi,%rdx), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	scale3, .-scale3
	.ident	"GCC: (GNU) 14.1.1 20240522 (Red Hat 14.1.1-4)"
	.section	.note.GNU-stack,"",@progbits
