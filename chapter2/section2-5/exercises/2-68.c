#include <stdio.h>

/* Write code for a function with the following prototype: */

/* 
 * Mask with least signficant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */
int lower_one_mask(int n);
/* 
 * Your function should follow the bit-level integer coding rules (page 164). Be
 * careful of the case n = w.
 */

int lower_one_mask(int n) {
    return (int)((unsigned)~0 >> (8*sizeof(int) - n));
}

int main(void) {
    printf("lower_one_mask(6) == 0x3F = %d\n", lower_one_mask(6) == 0x3F);
    printf("lower_one_mask(17) == 0x1FFFF = %d\n",
            lower_one_mask(17) == 0x1FFFF);
    printf("lower_one_mask(32) == 0xFFFFFFFF = %d\n",
            lower_one_mask(32) == 0xFFFFFFFF);
    printf("lower_one_mask(1) == 0x1 = %d\n", lower_one_mask(1) == 0x1);
    return 0;
}
