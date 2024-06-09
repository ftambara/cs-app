/* Consider the following code, in which we have omitted the expression being
 * computed:
 *
 * short arith3(short x, short y, short z) {
 *     short p1 = ???;
 *     short p2 = ???;
 *     short p3 = ???;
 *     short p4 = ???;
 *     return p4;
 * }
 *
 * The portion of the generated assembly code implementing these expressions is
 * as follows:
 *  short arith3(short x, short y, short z)
 *  x in %rdi, y in %rsi, z in %rdx
 * arith3:
 *     orq  %rsi, %rdi
 *     sarq $3, %rdi
 *     notq %rdi
 *     movq %rdx, %rax
 *     subq %rdi, %rax
 *     ret
 *
 * Based on this assembly code, fill in the missing portions of the C code.
 */

short arith3(short x, short y, short z) {
    short p1 = (short) (y | x);
    short p2 = (short) (p1 >> 3);
    short p3 = (short) ~p2;
    short p4 = (short) (z - p3);
    return p4;
}

/* The generated assembly for this code (clang 18.1.6, x86_64, -O2) was:
 * arith3:
 *   orl	%esi, %edi
 *   sarl	$3, %edi
 *   leal	(%rdx,%rdi), %eax
 *   incl	%eax
 *
 * Using the property that ~a = -a + 1, both assembly codes are functionally
 * equivalent
 */
