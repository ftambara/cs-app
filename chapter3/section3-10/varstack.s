vframe:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        leaq    15(,%rdi,8), %rax
        andq    $-16, %rax
        subq    %rax, %rsp
        leaq    7(%rsp), %rax
        shrq    $3, %rax
        leaq    0(,%rax,8), %rcx
        leaq    -8(%rbp), %r8
        movq    %r8, 0(,%rax,8)
        movq    $1, -8(%rbp)
        jmp     .L2
.L3:
        movq    %rdx, (%rcx,%rax,8)
        addq    $1, -8(%rbp)        # i++
.L2:
        movq    -8(%rbp), %rax
        cmpq    %rdi, %rax
        jl      .L3
        movq    (%rcx,%rsi,8), %rax
        movq    (%rax), %rax
        leave
        ret
