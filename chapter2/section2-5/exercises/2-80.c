#include <stdio.h>
#include <limits.h>

/*
 * Write code for a function threefourths that, for integer argument x, computes
 * the value of (3/4)*x, rounded toward zero. It should not overflow. Your
 * function should follow the bit-level integer coding rules (page 164).
 */

int threefourths(int x) {
    /* Sign = [1...1] if x is negative, 0 otherwise */
    int sign = x >> (8 * sizeof(int) - 1);
    /* Bias = 0 if x is positive, 3 = 2^2 - 1 if x is negative */
    int bias = sign & 0x3;
    int x_by_four = x >> 2;
    int rounding = x & 0x3;
    rounding = (rounding + rounding + rounding + bias) >> 2;
    return x_by_four + x_by_four + x_by_four + rounding;
}

int main(void) {
    printf("threefourths(7) == 5: %d\n", threefourths(7) == 5);
    printf("threefourths(-7) == -5: %d\n", threefourths(-7) == -5);
    printf("threefourths(8) == 6: %d\n", threefourths(8) == 6);
    printf("threefourths(-8) == -6: %d\n", threefourths(-8) == -6);
    printf("threefourths(9) == 6: %d\n", threefourths(9) == 6);
    printf("threefourths(-9) == -6: %d\n", threefourths(-9) == -6);

    printf("threefourths(0) == 0: %d\n", threefourths(0) == 0);

    printf("threefourths(INT_MAX) == (int)(INT_MAX * 0.75): %d\n",
            threefourths(INT_MAX) == (int)(INT_MAX * 0.75));
    printf("INT_MAX: %d\n", INT_MAX);
    printf("INT_MAX * 0.75: %d\n", (int)(INT_MAX * 0.75));
    printf("threefourths(INT_MAX): %d\n", threefourths(INT_MAX));

    printf("threefourths(INT_MIN) == (int)(INT_MIN * 0.75): %d\n",
            threefourths(INT_MIN) == (int)(INT_MIN * 0.75));

    return 0;
}
