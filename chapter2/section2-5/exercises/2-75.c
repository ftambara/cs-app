#include <stdint.h>
#include <stdio.h>

/* Suppose we want to compute the complete 2w-bit representation of x.y, where
 * both x and y are unsigned, on a machine for which data type unsigned is w
 * bits. The low-order w bits of the product can be computed with the expression
 * x*y, so we only require a procedure with prototype
 *
 * unsigned unsigned_high_prod(unsigned x, unsigned y);
 *
 * that computes the high-order w bits of x.y for unsigned variables.
 * We have access to a library function with prototype
 *
 * int signed_high_prod(int x, int y);
 *
 * that computes the high-order w bits of x.y for the case where x and y are
 * in two’s-complement form. Write code calling this procedure to implement the
 * function for unsigned arguments. Justify the correctness of your solution.
 * Hint: Look at the relationship between the signed product x.y and the
 * unsigned product x'.y' in the derivation of Equation 2.18.
 */

int16_t signed_high_prod(int16_t x, int16_t y) {
    int32_t prod = (int32_t)x * (int32_t)y;
    return (int16_t)(prod >> 16);
}

uint16_t unsigned_high_prod(uint16_t x, uint16_t y) {
    uint16_t p = (uint16_t)signed_high_prod((int16_t)x, (int16_t)y);
    uint16_t mask = 1 << 15;
    /* x'*y' = ((x*[2w]y) + (x_(w-1)*y + x*y_(w-1)) * 2^w) mod 2^2w */
    /* Add the necessary corrections */
    if ((x & mask) && (y & mask)) {
        p += (y + x);
    } else if (x & mask) {
        p += y;
    } else if (y & mask) {
        p += x;
    }
    return p;
}

int main(void) {
    int16_t a = INT16_MAX;
    int16_t b = INT16_MIN;
    int16_t c = -1;
    printf("signed_high_prod(0x%hx (%d), 0x%hx (%d)) = 0x%hx and 0x%hx\n",
            a, a, 1, 1, signed_high_prod(a, 1), a * 1);
    printf("signed_high_prod(0x%hx (%d), 0x%hx (%d)) = 0x%hx and 0x%hx\n",
            a, a, b, b, signed_high_prod(a, b), a * b);
    printf("signed_high_prod(0x%hx (%d), 0x%hx (%d)) = 0x%hx and 0x%hx\n",
            b, b, c, c, signed_high_prod(b, c), b * c);

    uint16_t x = UINT16_MAX;
    uint16_t y = 1;
    printf("unsigned_high_prod(0x%hx (%u), 0x%hx (%u)) = 0x%hx and 0x%hx\n",
            x, x, y, y, unsigned_high_prod(x, y), x * y);
    printf("unsigned_high_prod(0x%hx (%u), 0x%hx (%u)) = 0x%hx and 0x%hx\n",
            x, x, x, x, unsigned_high_prod(x, x), x * x);

    return 0;
}
