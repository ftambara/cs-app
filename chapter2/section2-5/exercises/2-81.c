#include <stdio.h>
#include <limits.h>

/*
 * Write C expressions to generate the bit patterns that follow, where a k
 * represents k repetitions of symbol a. Assume a w-bit data type. Your code may
 * contain references to parameters j and k, representing the values of j and k,
 * but not a parameter representing w.
 */

unsigned a_fn(int k) {
    return UINT_MAX << k;
}

unsigned b_fn(int j, int k) {
    return ((1 << k) - 1) << j ;
}

int main(void) {
    /* A. 1^(w−k) 0^k */
    printf("A:\n");
    printf("a_fn(0) == 0xFFFFFFFF: %d\n", a_fn(0) == 0xFFFFFFFF);
    printf("a_fn(1) == 0xFFFFFFFE: %d\n", a_fn(1) == 0xFFFFFFFE);
    printf("a_fn(8) == 0xFFFFFF00: %d\n", a_fn(8) == 0xFFFFFF00);

    /* B. 0^(w−k−j) 1^k 0^j */
    printf("B:\n");
    printf("b_fn(0, 0) == 0x00000000: %d\n", b_fn(0, 0) == 0x00000000);
    printf("b_fn(0, 1) == 0x00000001: %d\n", b_fn(0, 1) == 0x00000001);
    printf("b_fn(0, 8) == 0x000000FF: %d\n", b_fn(0, 8) == 0x000000FF);
    printf("b_fn(1, 0) == 0x00000000: %d\n", b_fn(1, 0) == 0x00000000);
    printf("b_fn(1, 1) == 0x00000002: %d\n", b_fn(1, 1) == 0x00000002);
    printf("b_fn(1, 8) == 0x000001FE: %d\n", b_fn(1, 8) == 0x000001FE);
    printf("b_fn(8, 1) == 0x00000100: %d\n", b_fn(8, 1) == 0x00000100);
    printf("b_fn(8, 8) == 0x0000FF00: %d\n", b_fn(8, 8) == 0x0000FF00);
    return 0;
}
