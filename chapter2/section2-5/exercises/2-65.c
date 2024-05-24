#include <stdio.h>

/* Write code to implement the following function: */

/* Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32 */
int odd_ones(unsigned x);

/* Your function should follow the bit-level integer coding rules (page 164),
 * except that you may assume that data type int has w = 32 bits.
 * Your code should contain a total of at most 12 arithmetic, bitwise, and
 * logical operations.
 */

int odd_ones(unsigned x) {
    /* I had to look this up. I got the idea of recursively checking both halves
     * of a bit vector, but I couldn't figure out how to extract and compare two
     * bits in so few operations.
     * The idea of successively getting the XOR of the number with itself as
     * a way to accomplish that is very clever.
     * The other simple idea that I've missed is that the order of comparisons
     * doesn't matter, as long as every bit is taken into account.
     */

    /* Assume x is 32 bits long */
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return (int)(x & 1);
}

int main(void) {
    unsigned num1 = 0xaaaaaaaa;
    unsigned num2 = 0xaaaaaaab;
    printf("odd_ones(0x%x) = %d\n", num1, odd_ones(num1));
    printf("odd_ones(0x%x) = %d\n", num2, odd_ones(num2));
    return 0;
}
