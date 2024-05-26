#include <stdio.h>

/*
 * Suppose we are given the task of generating code to multiply integer variable
 * x by various different constant factors K. To be efficient, we want to use
 * only the operations +, -, and <<. For the following values of K, write C
 * expressions to perform the multiplication using at most three operations per
 * expression.
 */

int main(void) {
    int x = 120;
    int y = -51;

    /* A. K = 17 */
    /* 17 = 2^4 + 1 */
    printf("A. %d * 17 = %d\n", x, (x << 4) + x);
    printf("A. %d * 17 = %d\n", y, (y << 4) + y);

    /* B. K = −7 */
    /* -7 = -2^3 + 1 */
    printf("B. %d * -7 = %d\n", x, x - (x << 3));
    printf("B. %d * -7 = %d\n", y, y - (y << 3));

    /* C. K = 60 */
    /* 60 = 0x111100 = 2^6 - 2^2 */
    printf("C. %d * 60 = %d\n", x, (x << 6) - (x << 2));
    printf("C. %d * 60 = %d\n", y, (y << 6) - (y << 2));

    /* D. K = −112 */
    /* -112 = -(0x1110000) = -2^7 + 2^4 */
    printf("D. %d * -112 = %d\n", x, (x << 4) - (x << 7));
    printf("D. %d * -112 = %d\n", y, (y << 4) - (y << 7));
    return 0;
}
