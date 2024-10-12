/* For a function with prototype */
long decode2(long x, long y, long z);

/*
 * GCC generates the following assembly code:
 *
 *  1   decode2:
 *  2       subq    %rdx, %rsi
 *  3       imulq   %rsi, %rdi
 *  4       movq    %rsi, %rax
 *  5       salq    $63, %rax
 *  6       sarq    $63, %rax
 *  7       xorq    %rdi, %rax
 *  8       ret
 *
 * Parameters x, y, and z are passed in registers %rdi, %rsi, and %rdx. The
 * code stores the return value in register %rax.
 * Write C code for decode2 that will have an effect equivalent to the assembly
 * code shown.
 */

/*
 *  1   decode2:
 *  2       subq    %rdx, %rsi  rsi = y - z
 *  3       imulq   %rsi, %rdi  rdi = x * (y-z)
 *  4       movq    %rsi, %rax  rax = y - z
 *  5       salq    $63, %rax   rax = (y-z) << 63
 *  6       sarq    $63, %rax   rax = (y-z) >> 63  
 *  7       xorq    %rdi, %rax  rax = rax ^ rdi
 *  8       ret
 */

long decode2(long x, long y, long z) {
    // a is 0 if (y-z) is even, and ~0 if it's odd
    long a = ((y-z) << 63) >> 63;
    // A ^ 0 = A; A ^ 1 = ~A
    return a ^ (x * (y-z));
}
