#include <stdio.h>

/* Write code for a function with the following prototype: */

/* Divide by power of 2. Assume 0 <= k < w-1 */
int divide_power2(int x, int k);

/* The function should compute x/2k with correct rounding, and it should follow
the bit-level integer coding rules (page 164). */

int divide_power2(int x, int k) {
    int bias = (1<<k)-1;
    /* sign = -1 if x < 0 */
    int sign = x >> (8*sizeof(int)-1);
    bias &= sign;
    return (x + bias) >> k;
}

int main(void) {
    printf("divide_power2(15, 1) = %d (0x%x)\n",
            divide_power2(15, 1), divide_power2(15, 1));
    printf("divide_power2(15, 2) = %d (0x%x)\n",
            divide_power2(15, 2), divide_power2(15, 2));
    printf("divide_power2(15, 3) = %d (0x%x)\n",
            divide_power2(15, 3), divide_power2(15, 3));

    printf("divide_power2(-7, 1) = %d (0x%x)\n",
            divide_power2(-7, 1), divide_power2(-7, 1));
    printf("divide_power2(-7, 2) = %d (0x%x)\n",
            divide_power2(-7, 2), divide_power2(-7, 2));
    return 0;
}
