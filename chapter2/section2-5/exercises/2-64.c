#include <stdio.h>

/* Write code to implement the following function: */

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
   Assume w=32 */
int any_odd_one(unsigned x);

int any_odd_one(unsigned x) {
    /* Mask has all odd bits set to 1 */
    unsigned mask = 0xAAAAAAAA;
    return !!(x & mask);
}

int main(void) {
    printf("any_odd_one(0x4) = %d\n", any_odd_one(0x4));
    printf("any_odd_one(0x81) = %d\n", any_odd_one(0x81));
    printf("any_odd_one(0xAA) = %d\n", any_odd_one(0xAA));
    printf("any_odd_one(0) = %d\n", any_odd_one(0));
    return 0;
}
