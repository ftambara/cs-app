/* The following C code sets the diagonal elements of one of our fixed-size
 * arrays to val:
 */

#define N 16
typedef int fix_matrix[N][N];

/* Set all diagonal elements to val */
void fix_set_diag(fix_matrix A, int val) {
    long i;
    for (i = 0; i < N; i++) {
        A[i][i] = val;
    }
}

/* When compiled with optimization level -01, GCC generates the
 * following assembly code:
 * 
 * 1   fix_set_diag:
 *     # void fix_set_diag(fix_matrix A, int val)
 *     # A in %rdi, val in %rsi
 * 2       movl    $0, %eax
 * 3   .L13:
 * 4       movl    %esi, (%rdi,%rax)
 * 5       addq    $68, %rax
 * 6       cmpq    $1088, %rax
 * 7       jne     .L13
 * 8       rep; ret
 */

/* Create a C code program fix_set_diag_opt that uses optimizations similar to
 * those in the assembly code, in the same style as the code in Figure 3.37(b) .
 * Use expressions involving the parameter N rather than integer constants, so
 * that your code will work correctly if N is redefined.
 */

void fix_set_diag_opt(fix_matrix A, int val) {
    int *Astart = &A[0][0];
    int *Aend = &A[N][N];
    do {
        *Astart = val;
        Astart += N + 1;
    } while (Astart != Aend);
}
