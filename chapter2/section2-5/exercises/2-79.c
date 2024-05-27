#include <stdio.h>
#include <limits.h>

/*
 * Write code for a function mul3div4 that, for integer argument x, computes
 * 3*x/4 but follows the bit-level integer coding rules (page 164). Your code
 * should replicate the fact that the computation 3*x can cause overflow.
 */

int mul3div4(int x) {
    /* bias = 2^2 - 1 */
    int bias = 3;
    int sign = x >> (8 * sizeof(int) - 1);
    return (x + x + x + (bias&sign)) >> 2;
}

int main(void) {
    printf("mul3div4(15) = %d. Expected: %d\n", mul3div4(15), 15*3/4);
    printf("mul3div4(-7) = %d. Expected: %d\n", mul3div4(-7), -7*3/4);
    printf("mul3div4(-6) = %d. Expected: %d\n", mul3div4(-6), -6*3/4);
    printf("mul3div4(0) = %d. Expected: %d\n", mul3div4(0), 0*3/4);
    printf("mul3div4(INT_MAX) = %d. Expected: %d\n", mul3div4(INT_MAX), INT_MAX*3/4);
    printf("mul3div4(INT_MIN) = %d. Expected: %d\n", mul3div4(INT_MIN), INT_MIN*3/4);
    return 0;
}
