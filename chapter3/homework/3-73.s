    .global find_range
find_range:
    pxor %xmm1, %xmm1
    comiss %xmm1, %xmm0
    ja .POS
    jp .OTHER
    jb .NEG
    # ZERO
    movq $1, %rax
    ret
.OTHER:
    movq $3, %rax
    ret
.NEG:
    movq $0, %rax
    ret
.POS:
    movq $2, %rax
    ret
