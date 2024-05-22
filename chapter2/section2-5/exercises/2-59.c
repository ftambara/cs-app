/*
 * Write a C expression that will yield a word consisting of the least
 * significant byte of x and the remaining bytes of y. For operands
 * x = 0x89ABCDEF and y = 0x76543210, this would give 0x765432EF.
 */

#include <stdio.h>

int main(void) {
    int x = 0x89ABCDEF;
    int y = 0x76543210;

    printf("%X\n", (x & 0xFF) | (y & 0xFFFFFF00));
    return 0;
}
