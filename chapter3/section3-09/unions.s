	.file	"unions.c"
	.text
	.p2align 4
	.globl	get_a
	.type	get_a, @function
get_a:
.LFB0:
	.cfi_startproc
	movq	%rdi, (%rsi)
	ret
	.cfi_endproc
.LFE0:
	.size	get_a, .-get_a
	.p2align 4
	.globl	get_a_pos
	.type	get_a_pos, @function
get_a_pos:
.LFB1:
	.cfi_startproc
	movq	(%rdi), %rax
	movl	(%rdi,%rax,4), %eax
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE1:
	.size	get_a_pos, .-get_a_pos
	.p2align 4
	.globl	get_p
	.type	get_p, @function
get_p:
.LFB2:
	.cfi_startproc
	movq	8(%rdi), %rax
	movzbl	(%rax), %eax
	movb	%al, (%rsi)
	ret
	.cfi_endproc
.LFE2:
	.size	get_p, .-get_p
	.ident	"GCC: (GNU) 14.2.1 20240801 (Red Hat 14.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
