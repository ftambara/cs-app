#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef unsigned float_bits;

/* Following the bit-level floating-point coding rules, implement the function
 * with the following prototype:
 */

/* Compute (float) i */
float_bits float_i2f(int i);

/* For argument i, this function computes the bit-level representation of
 * (float) i.
 * Test your function by evaluating it for all 2^32 values of argument f and
 * comparing the result to what would be obtained using your machine’s
 * floating-point operations.
 */

#define FLOAT_EXP_BIAS 127
#define INT_MIN_TO_FLOAT_BITS 0xCf000000;

float_bits float_i2f(int i) {
    unsigned sign = 0;
    if (i == 0) {
        return 0;
    }
    if (i >> 31) {
        if (i == INT_MIN) {
            return INT_MIN_TO_FLOAT_BITS;
        }
        sign = 1;
        i = ~i + 1;
    }

    unsigned exp = 31 + FLOAT_EXP_BIAS;  // Init with max exp
    /* Normalize */
    unsigned msb_mask = 1 << 31;
    while ((i & msb_mask) == 0) {
        i <<= 1;
        exp--;
    }

    unsigned frac = (i >> 8) & 0x7fffff;  /* 23 bits, discard leftmost 1 */
    printf("frac = 0x%x\n", frac);
    unsigned residue = i & 0xFF;
    if (residue > 0x80 || ((frac & 1) && residue == 0x80)) {
        frac++;
        printf("frac = 0x%x\n", frac);
        if (frac > 0x7fffff) {
            /* discard leftmost 1 again */
            frac = (frac & 0x7fffff) >> 1;
            exp++;
        }
    }
    return (sign << 31) | (exp << 23) | frac;
}

float u2f(unsigned x) {
    return *(float *) &x;
}

int main(void) {
    /* Test corner cases */
    int cases[] = {
        INT_MIN,
        -1,
        0,
        1,
        INT_MAX,
    };

    for (int i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        printf("%d: %a == %a: %d\n",
                i,
                (float) cases[i],
                u2f(float_i2f(cases[i])),
                (float) cases[i] == u2f(float_i2f(cases[i])));
    }

    int num = INT_MIN;
    float n_machine;
    float n_func;
    int ok;

    for (;;) {
        n_machine = (float) num;
        n_func = u2f(float_i2f(num));
        ok = (n_machine == n_func);
        printf("0x%x: %a == %a: %d\n", num, n_machine, n_func, ok);
        if (!ok) {
            printf("ERROR\n");
            return 1;
        }
        if (num == INT_MAX) {
            break;
        }
        num++;
    }
    return 0;
}
