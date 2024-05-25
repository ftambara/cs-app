#include <stdio.h>

/* Write code for a function with the following prototype: */
/*
* Do rotating left shift. Assume 0 <= n < w
* Examples when x = 0x12345678 and w = 32:
*
n=4 -> 0x23456781, n=20 -> 0x67812345
*/
unsigned rotate_left(unsigned x, int n);

/* Your function should follow the bit-level integer coding rules (page 164). Be
careful of the case n = 0. */

unsigned rotate_left(unsigned x, int n) {
    /* Mask with all 1s to the right of the n-th bit, inclusive */
    unsigned w = 8*sizeof(unsigned);
    /* Shift left part in two stages to avoid shifting by w when n == 0 */
    return ((x >> (w - n - 1)) >> 1) | (x << n);
}

int main(void) {
    printf("rotate_left(0x12345678, 4) == 0x23456781 = %d\n",
            rotate_left(0x12345678, 4) == 0x23456781);
    printf("rotate_left(0x12345678, 20) == 0x67812345 = %d\n",
            rotate_left(0x12345678, 20) == 0x67812345);
    printf("rotate_left(0x12345678, 0) == 0x12345678 = %d\n",
            rotate_left(0x12345678, 0) == 0x12345678);
    return 0;
}
