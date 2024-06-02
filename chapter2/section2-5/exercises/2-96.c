#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef unsigned float_bits;

/* Following the bit-level floating-point coding rules, implement the function
 * with the following prototype:
 */

/*
* Compute (int) f.
* If conversion causes overflow or f is NaN, return 0x80000000
*/
int float_f2i(float_bits f);

/* For floating-point number f, this function computes (int) f. Your function
 * should round toward zero. If f cannot be represented as an integer (e.g., it
 * is out of range, or it is NaN), then the function should return 0x80000000.
 * Test your function by evaluating it for all 2^32 values of argument f and
 * comparing the result to what would be obtained using your machine’s
 * floating-point operations.
 */

#define FLOAT_TOTAL_BITS 32
#define FLOAT_FRAC_BITS 23
#define FLOAT_EXP_BIAS 127
#define INT_TOTAL_BITS 31
#define F_POS_INF 0x7f800000
#define F_NEG_INF 0xff800000
#define F2I_ERROR_RESULT 0x80000000

int float_f2i(float_bits f) {
    unsigned sign = f >> (FLOAT_TOTAL_BITS - 1);
    unsigned exp = (f >> FLOAT_FRAC_BITS) & 0xff;
    unsigned frac = f & 0x7fffff;

    if (exp < FLOAT_EXP_BIAS) {
        /* All values |f| < 1 will be converted to 0 */
        return 0;
    }

    unsigned res = (1 << FLOAT_FRAC_BITS) | frac;
    int shift = FLOAT_FRAC_BITS - ((int) exp - FLOAT_EXP_BIAS); 
    if (shift < -(INT_TOTAL_BITS - FLOAT_FRAC_BITS - 1)) {
        return F2I_ERROR_RESULT;
    }
    if (shift < 0) {
        res <<= -shift;
    } else {
        res >>= shift;
    }
    if (sign == 1) {
        res = ~res + 1;
    }
    return (int) res;
}


float u2f(unsigned x) {
    return *(float *) &x;
}

int main(void) {
    /* Test corner cases */
    unsigned cases[] = {
        0,           // 0
        F_POS_INF,   // +∞
        F_NEG_INF,   // -∞
        0xff7fffff,  // smallest normal number
        0x007fffff,  // largest subnormal number
        0x3f7fffff,   // largest number less than one
        0x3f800000,  // one
        0x3f800001,  // smallest number larger than one (1 + 2^-24)
        0x7f7fffff,  // largest normal number
    };

    for (int i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        printf("%d: %x == %x: %d\n",
                i,
                (int) u2f(cases[i]),
                float_f2i(cases[i]),
                (int) u2f(cases[i]) == float_f2i(cases[i]));
    }

    unsigned num = 0;
    int n_machine;
    int n_func;
    int ok;

    for (;;) {
        n_machine = (int) (u2f(num));
        n_func = float_f2i(num);
        ok = (n_machine == n_func);
        printf("0x%x: %d == %d: %d\n", num, n_machine, n_func, ok);
        if (n_func == F2I_ERROR_RESULT) {
            ok = ok || (n_machine == INT_MAX) || (n_machine == INT_MIN);
        }
        if (!ok) {
            printf("ERROR\n");
            return 1;
        }
        if (num == UINT_MAX) {
            break;
        }
        num++;
    }
    return 0;
}
