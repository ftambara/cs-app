#include <stdio.h>
#include <limits.h>

/* Write code for a function with the following prototype: */

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y);

/* Instead of overflowing the way normal two’s-complement addition does,
 * saturating addition returns TMax when there would be positive overflow, and
 * TMin when there would be negative overflow. Saturating arithmetic is commonly
 * used in programs that perform digital signal processing.
 * Your function should follow the bit-level integer coding rules (page 164).
 */

int saturating_add(int x, int y) {
    size_t w = 8 * sizeof(int);
    /* -1 if negative, 0 if positive */
    int sign = (x&y) >> (w-1);
    int same_sign = ~(x^y) >> (w-1);

    /* -1 if has carry, 0 if it doesn't */
    int carry = ((x & (~0 >> 1)) + (y & (~0 >> 1))) >> (w-1) & same_sign;

    int pos_overflow = ~sign & carry;
    int neg_overflow = sign & ~carry;
    int overflow = pos_overflow | neg_overflow;
    return (pos_overflow & INT_MAX) | (neg_overflow & INT_MIN) | (~overflow & (x + y));
}
 
int main(void) {
    printf("saturating_add(1, 1) == 2 = %d\n",
            saturating_add(1, 1) == 2);
    printf("saturating_add(-10, 3) == -7 = %d\n",
            saturating_add(-10, 3) == -7);
    printf("saturating_add(INT_MAX, 1) == INT_MAX = %d\n",
            saturating_add(INT_MAX, 1) == INT_MAX);
    printf("saturating_add(INT_MIN, -10) == INT_MIN = %d\n",
            saturating_add(INT_MIN, -10) == INT_MIN);
    return 0;
}
