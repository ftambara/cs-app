	.file	"3-61.c"
	.text
	.p2align 4
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB0:
	.cfi_startproc
	xorl	%eax, %eax
	testb	%sil, %sil
	cmovne	%rdi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	cread_alt, .-cread_alt
	.ident	"GCC: (GNU) 14.2.1 20240912 (Red Hat 14.2.1-3)"
	.section	.note.GNU-stack,"",@progbits
