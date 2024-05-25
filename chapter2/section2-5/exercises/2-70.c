#include <stdio.h>
#include <limits.h>

/* Write code for the function with the following prototype: */

/*
* Return 1 when x can be represented as an n-bit, 2’s-complement
* number; 0 otherwise
* Assume 1 <= n <= w
*/
int fits_bits(int x, int n);

/* Your function should follow the bit-level integer coding rules (page 164). */

int fit_bits(int x, int n) {
   unsigned w = 8 * sizeof(int);
   /* True either if n == w or nothing is left after shifting n places */
   return !(n ^ w) || !((unsigned)x >> n);
}

int main(void) {
    printf("fit_bits(0x813, 11) = %d\n", fit_bits(0x813, 11));
    printf("fit_bits(0x813, 12) = %d\n", fit_bits(0x813, 12));
    printf("fit_bits(INT_MAX, 8*sizeof(int)) = %d\n",
            fit_bits(INT_MAX, 8*sizeof(int)));
    printf("fit_bits(1, 0) = %d\n", fit_bits(1, 0));
    return 0;
}
