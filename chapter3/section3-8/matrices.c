#define N 16
typedef int fix_matrix[N][N];

int fix_prod_ele (fix_matrix A, fix_matrix B, long i, long k) {
    long j;
    int result = 0;
    for (j = 0; j < N; j++) {
        result += A[i][j] * B[j][k];
    }
    return result;
}

/*
fix_prod_ele:
        salq    $6, %rdx                # rdx = 64i
        addq    %rdx, %rdi              # rdi = A + 64i
        leaq    (%rsi,%rcx,4), %rax     # rax = B + 4k
        leaq    1024(%rax), %rsi        # rsi = 1024 + B + 4k
        movl    $0, %ecx                # rcx = 0
.L2:
        # First pass
        movl    (%rdi), %edx            # edx = M[A + 64i]
        imull   (%rax), %edx            # edx = M[A + 64i] * M[B + 4k]
        addl    %edx, %ecx              # ecx = M[A + 64i] * M[B + 4k]
        addq    $4, %rdi                # rdi = A + 64i + 4  skip a column
        addq    $64, %rax               # rax = B + 4k + 64  skip a row
        cmpq    %rsi, %rax              # if (rax != rsi)
        jne     .L2                     #     goto .L2
        movl    %ecx, %eax              # eax = ecx
        ret                             # return
*/

/* Compute i,k of fixed matrix product */
int fix_prod_ele_opt(fix_matrix A, fix_matrix B, long i, long k) {
    int *Aptr = &A[i][0];           /* Points to elements in row i of A */
    int *Bptr = &B[0][k];           /* Points to elements in column k of B */
    int *Bend = &B[N][k];           /* Marks stopping point for Bptr */
    int result = 0;
    do {                            /* No need for initial test */
        result += *Aptr * *Bptr;    /* Add next product to sum */
        Aptr ++;                    /* Move Aptr to next column */
        Bptr += N;                  /* Move Bptr to next row */
    } while (Bptr != Bend);         /* Test for stopping point */
    return result;
}

int fix_ele(int A[3][3], long i, long j) {
    return A[i][j];
}

/*
fix_ele:    # -O1
    leaq    (%rsi,%rsi,2), %rax
    leaq    (%rdi,%rax,4), %rax
    movl    (%rax,%rdx,4), %eax
    ret
*/

int var_ele(long n, int A[n][n], long i, long j) {
    return A[i][j];
}

/*
var_ele:    # -O1
    imulq   %rdx, %rdi              # n*i
    leaq    (%rsi,%rdi,4), %rax     # rax = &A[0][0] + 4n*i
    movl    (%rax,%rcx,4), %eax     # return *(&A[0][0] + 4n*i + 4j)
    ret
*/

// Difference: first instruction is a costlier imulq instead of leaq.
// In general, we exchange shifts and additions for multiplications

/* Compute i,k of variable matrix product */
int var_prod_ele(long n, int A[n][n], int B[n][n], long i, long k) {
    long j;
    int result = 0;
    for (j = 0; j < n; j++) {
        result += A[i][j] * B[j][k];
    }
    return result;
}

/*
var_prod_ele:
    testq   %rdi, %rdi              # if (n == 0)
    jle     .L4                     #     goto .L4  Basically, return 0
    imulq   %rdi, %rcx              # set rcx = n*i
    leaq    (%rsi,%rcx,4), %r10     # r10 = A + 4n*i
    leaq    0(,%rdi,4), %r9         # r9 = 4n
    leaq    (%rdx,%r8,4), %rcx      # rcx = B + 4k
    movl    $0, %esi                # esi = 0  (esi: accumulated sum of products)
    movl    $0, %eax                # eax = 0  (eax: common index j)
.L3:
    movl    (%r10,%rax,4), %edx     # edx = M[A + 4n*i + 4(rax)]
    imull   (%rcx), %edx            # edx =  M[A + 4n*i + 4(rax)] * M[B + 4k]
    addl    %edx, %esi              # esi +=  M[A + 4n*i + 4(rax)] * M[B + 4k]
    addq    $1, %rax                # rax++
    addq    %r9, %rcx               # rcx = (rcx) + 4n
    cmpq    %rax, %rdi              # if (rax) != n
    jne     .L3                     #     goto .L3
.L1:
    movl    %esi, %eax              # prepare return
    ret                             # return esi
.L4:
    movl    $0, %esi                # esi = 0
    jmp     .L1                     # goto .L1
*/

int var_prod_ele_opt(long n, int A[n][n], int B[n][n], long i, long k) {
    if (n == 0) {
        return 0;
    }
    int *Astart = &A[i][0];
    int *Bstart = &B[0][k];
    i = n*i;
    int sum = 0;
    int j = 0;
    do {
        sum += *(Astart + j) * *Bstart;
        j++;
        Bstart += n;
    } while (j != n);
    return sum;
}
