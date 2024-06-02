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

#define FLOAT_TOTAL_BITS 32
#define FLOAT_FRAC_BITS 23
#define FLOAT_EXP_BIAS 127
#define INT_TOTAL_BITS 32
#define INT_MIN_TO_FLOAT_BITS 0xCf000000;

int leftmost_one_pos(unsigned x) {
    int i;
    for (i = 0; i < INT_TOTAL_BITS; i++) {
        x >>= 1;
        if (x == 0) {
            return i;
        }
    }
    return -1;
}

float_bits float_i2f(int i) {
    unsigned sign = 0;
    unsigned frac;
    unsigned exp;
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

    int left_one_pos = leftmost_one_pos(i);

    const unsigned frac_mask = (1 << FLOAT_FRAC_BITS) - 1;
    int shift = left_one_pos - FLOAT_FRAC_BITS;
    if (shift <= 0) {
        /* There is enough space, no rounding needed */
        frac = (i << -shift) & frac_mask;
    } else {
        /* Calculate rounding bias */
        const unsigned rounding_mask = 0x3 << (shift - 1);
        unsigned masked_bits = (i & rounding_mask);
        int bias;
        if (masked_bits == rounding_mask) {
            /* Round towards even or closest int */
            bias = (1 << shift) - 1;
        } else {
            /* Round towards closest int */
            bias = (1 << (shift - 1)) - 1;
        }
        /* Check if masked_bits have changed, which whould mean we
         * are rounding up */
        int do_round_up = ((i + bias) && rounding_mask) != masked_bits;

        if (do_round_up) {
            i = (i + bias);
            if (!(i & (1 << left_one_pos))) {
                /* leftmost position has shifted, update values */
                left_one_pos++;
                shift++;
            }
        }
        frac = (i >> shift) & frac_mask;
    }
    exp = left_one_pos + FLOAT_EXP_BIAS;

    return (sign << 31) | (exp << FLOAT_FRAC_BITS) | frac;
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
