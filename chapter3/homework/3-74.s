    .global find_range
find_range:
    pxor %xmm1, %xmm1
    comiss %xmm1, %xmm0
    movq $2, %rax
    ja  .POS
    movq $1, %rcx       # result = ZERO
    cmoveq  %rcx, %rax  # if (rax == 0 || rax is NaN) result = POS
    movq $0, %rcx
    cmovc  %rcx, %rax  # if (rax < 0 || rax is NaN) result = NEG
    movq $3, %rcx
    cmovp   %rcx, %rax # if (rax is NaN) result = OTHER
    ret
.POS:
    ret
