/* Consider the following code, in which we have omitted the expression being
 * computed:
 *
 * short scale3(short x, short y, short z) {
 *     short t = ???;
 *     return t;
 * }
 *
 * Compiling the actual function with gcc yields the following assembly code:
 *
 *      short scale3(short x, short y, short z)
 *      x in %rdi, y in %rsi, z in %rdx
 * scale3:
 *  leaq (%rsi,%rsi,9), %rbx  < I think there is an error here. Scaling factor
 *  leaq (%rbx,%rdx), %rbx          can only be 1, 2, 4 or 8
 *  leaq (%rbx,%rdi,%rsi), %rbx
 *  ret
 *
 * Fill in the missing expression in the C code.
 */

short scale3(short x, short y, short z) {
    short t = 10*y + z + y*x;
    return t;
}

/* This compiles to:
 *
 * scale3:
 *   leal   10(%rdi), %eax
 *   imull  %esi, %eax
 *   addl   %edx, %eax
 *   retq
 */
