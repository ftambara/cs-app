	.text
	.file	"3-10.c"
	.globl	arith3                          # -- Begin function arith3
	.p2align	4, 0x90
	.type	arith3,@function
arith3:                                 # @arith3
	.cfi_startproc
# %bb.0:
                                        # kill: def $edx killed $edx def $rdx
                                        # kill: def $edi killed $edi def $rdi
	orl	%esi, %edi
	sarl	$3, %edi
	leal	(%rdx,%rdi), %eax
	incl	%eax
                                        # kill: def $ax killed $ax killed $eax
	retq
.Lfunc_end0:
	.size	arith3, .Lfunc_end0-arith3
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 18.1.6 (Fedora 18.1.6-3.fc40)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
