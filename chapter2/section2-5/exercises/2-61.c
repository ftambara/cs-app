/*
 * Write C expressions that evaluate to 1 when the following conditions are true
 * and to 0 when they are false. Assume x is of type int.
 *  A. Any bit of x equals 1.
 *  B. Any bit of x equals 0
 *  C. Any bit in the least significant byte of x equals 1.
 *  D. Any bit in the most significant byte of x equals 0.
 *
 * Your code should follow the bit-level integer coding rules (page 164), with
 * the additional restriction that you may not use equality (==) or inequality
 * (!=) tests.
 */

#include <stdio.h>
#include <stdbool.h>

bool fn_a(int x) {
    /* True if x != 0 */
    return !!x;
}

bool fn_b(int x) {
    /* x ^ -1 will only yield 0 if x is -1 (all 1s)
     * In that case !!0 = 0
     * Otherwise it yields 1
     */
    return !!(x ^ -1);
}

bool fn_c(int x) {
    unsigned char lsb = x & 0xFF;
    return !!lsb;
}


bool fn_d(int x) {
    unsigned char lsb = x & 0xFF;
    return !!(lsb ^ 0xFF);
}


int main(void) {
    printf("A:\n");
    printf("  fn_a(0) = %d\n", fn_a(0));
    printf("  fn_a(1) = %d\n", fn_a(1));
    printf("  fn_a((int)0xFFFFFFFF) = %d\n", fn_a((int)0xFFFFFFFF));
    /*
      A:
        fn_a(0) = 0
        fn_a(1) = 1
        fn_a((int)0xFFFFFFFF) = 1
     */

    printf("B:\n");
    printf("  fn_b(0) = %d\n", fn_b(0));
    printf("  fn_b(1) = %d\n", fn_b(1));
    printf("  fn_b((int)0xFFFFFFFF) = %d\n", fn_b((int)0xFFFFFFFF));
    /*
      B:
        fn_b(0) = 1
        fn_b(1) = 1
        fn_b((int)0xFFFFFFFF) = 0
     */

    printf("C:\n");
    printf("  fn_c(0) = %d\n", fn_c(0));
    printf("  fn_c(1) = %d\n", fn_c(1));
    printf("  fn_c((int)0xFFFFFFFF) = %d\n", fn_c((int)0xFFFFFFFF));
    /*
      C:
        fn_c(0) = 0
        fn_c(1) = 1
        fn_c((int)0xFFFFFFFF) = 1
     */

    printf("D:\n");
    printf("  fn_d(0) = %d\n", fn_d(0));
    printf("  fn_d(1) = %d\n", fn_d(1));
    printf("  fn_d((int)0xFFFFFFFF) = %d\n", fn_d((int)0xFFFFFFFF));
    /*
      D:
        fn_d(0) = 1
        fn_d(1) = 1
        fn_d((int)0xFFFFFFFF) = 0
     */
}
