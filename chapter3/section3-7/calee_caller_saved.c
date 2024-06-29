long Q(long x) {return x;}

long P(long x, long y) {
    long u = Q(y);
    long v = Q(x);
    return u + v;
}
/*
Q:
        movq    %rdi, %rax
        ret
P:
        pushq   %r14            Save %r14 to use it as an auxiliary register
        pushq   %rbx            Save %rbx for the same purpose
        movq    %rdi, %r14      Save the second argument, y, because the register
                                is needed to pass the argument to Q
        movq    %rsi, %rdi      Prepare the argument to Q
        call    Q               Call Q(y)
        movq    %rax, %rbx      Save the result to auxiliary register rbx
        movq    %r14, %rdi      Prepare the argument to Q (x, which was in %r14)
        call    Q               Call Q(x)
        addq    %rax, %rbx      Do u + v
        movq    %rbx, %rax      Move u + v to conventional return register rax
        popq    %rbx            Restore calee-saved value of rbx
        popq    %r14            Restore calee-saved value of r14
        ret                     Return
*/
