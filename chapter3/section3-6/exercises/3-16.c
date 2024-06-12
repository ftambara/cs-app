/* When given the C code
 *
 * void cond(long a, long *p) {
 *     if (p && a > *p)
 *         *p = a;
 * }
 *
 * gcc generates the following assembly code:
 *
 *   void cond(short a, short *p)
 *   a in %rdi, p in %rsi
 * cond:
 *     testq    %rsi, %rsi
 *     je       .L1
 *     cmpq     %rdi, (%rsi)
 *     jge      .L1
 *     movq     %rdi, (%rsi)
 * .L1:
 *     rep; ret
 */

/* A. Write a goto version in C that performs the same computation and mimics
 * the control flow of the assembly code, in the style shown in Figure 3.16(b).
 * You might find it helpful to first annotate the assembly code as we have done
 * in our examples.
 */

void goto_cond(long a, long *p) {
    if (a == 0) {
        goto end;
    }
    if (*p >= a) {
        goto end;
    }
    *p = a;
    end:
        return;
}

/* B. Explain why the assembly code contains two conditional branches, even
 * though the C code has only one if statement.
 */

/* The additional branches are due to the logical and operation in if's test
 * condition. There is one conditional jump for each.
 */
