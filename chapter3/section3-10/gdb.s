	.file	"gdb.c"
	.text
	.p2align 4
	.globl	gets
	.type	gets, @function
gets:
.LFB22:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L14:
	cmpl	$-1, %eax
	je	.L13
	movb	%al, (%rbx)
	addq	$1, %rbx
.L2:
	movq	stdin(%rip), %rdi
	call	getc
	cmpl	$10, %eax
	jne	.L14
.L3:
	movb	$48, (%rbx)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rbp, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L13:
	.cfi_restore_state
	xorl	%eax, %eax
	cmpq	%rbp, %rbx
	jne	.L3
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	gets, .-gets
	.p2align 4
	.globl	echo
	.type	echo, @function
echo:
.LFB23:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rbp
	movq	%rbp, 8(%rsp)
	movq	%rsp, %rbp
	movq	%rsp, %rbx
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L26:
	cmpl	$-1, %eax
	je	.L25
	movb	%al, (%rbx)
	addq	$1, %rbx
.L16:
	movq	stdin(%rip), %rdi
	call	getc
	cmpl	$10, %eax
	jne	.L26
.L17:
	movb	$48, (%rbx)
.L19:
	movq	%rbp, %rdi
	call	puts
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L27
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L25:
	.cfi_restore_state
	cmpq	%rbp, %rbx
	jne	.L17
	jmp	.L19
.L27:
	call	__stack_chk_fail
	.cfi_endproc
.LFE23:
	.size	echo, .-echo
	.ident	"GCC: (GNU) 14.2.1 20240801 (Red Hat 14.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
