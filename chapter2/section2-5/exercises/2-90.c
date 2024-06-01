#include <stdio.h>

/* You have been assigned the task of writing a C function to compute a
 * floating-point representation of 2^x. You decide that the best way to do this
 * is to directly construct the IEEE single-precision representation of the
 * result. When x is too small, your routine will return 0.0. When x is too
 * large, it will return +∞. Fill in the blank portions of the code that follows
 * to compute the correct result. Assume the function u2f returns a
 * floating-point value having an identical bit representation as its unsigned
 * argument.
 */

float u2f(unsigned x) {
    return *(float *) &x;
}

float fpwr2(int x) {
    /* Result exponent and fraction */
    unsigned exp;
    unsigned frac;
    unsigned u;

    const int k = 8;
    const int n = 23;
    const int bias = (1 << (k-1)) - 1;
    const int min_exp = 1 - bias;

    if (x < min_exp - n) {
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < min_exp) {
        /* Denormalized result */
        exp = 0;
        frac = 1 << (n + (x - min_exp));
    } else if (x < ((1 << k) - 1 - bias)) {
        /* Normalized result. */
        exp = x + bias;
        frac = 0;
    } else {
        /* Too big. Return +∞ */
        exp = (1 << k) - 1;
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}

int main(void) {
    /* Test u2f */
    printf("u2f(0) == 0.0: %d\n", u2f(0) == 0.0);
    printf("u2f(0x3f800000) == 1.0: %d\n", u2f(0x3f800000) == 1.0);

    /* Test fpwr2 */
    printf("2^128: %f\n", fpwr2(128));
    printf("2^127: %a\n", fpwr2(127));
    printf("2^0: %f\n", fpwr2(0));
    printf("2^-126: %a\n", fpwr2(-126));
    printf("2^-127: %a\n", fpwr2(-127));
    printf("2^-149: %a\n", fpwr2(-149));
    printf("2^-150: %f\n", fpwr2(-150));

    return 0;
}
