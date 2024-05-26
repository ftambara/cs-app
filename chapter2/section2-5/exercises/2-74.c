#include <stdio.h>
#include <limits.h>

/* Write a function with the following prototype: */

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y);

/* This function should return 1 if the computation x-y does not overflow. */

int tsub_ok(int x, int y) {
    int sub = x - y;
    size_t w = 8 * sizeof(int);
    unsigned mask = 1 << (w - 1);
    /* x - y may overflow if x is negative and y is positive */
    unsigned neg_overflow = (x & mask) && !(y & mask) && !(sub & mask);
    /* or if x is positive and y is negative */
    unsigned pos_overflow = !(x & mask) && (y & mask) && (sub & mask);
    return !neg_overflow && !pos_overflow;
}


int main(void) {
    printf("tsub_ok(1, 1) = %d\n", tsub_ok(1, 1));
    printf("tsub_ok(INT_MIN, -10) = %d\n", tsub_ok(INT_MIN, -10));
    printf("tsub_ok(INT_MIN, 10) = %d\n", tsub_ok(INT_MIN, 10));
    printf("tsub_ok(INT_MAX, -10) = %d\n", tsub_ok(INT_MAX, -10));
    return 0;
}
