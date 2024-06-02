#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;

/* Following the bit-level floating-point coding rules, implement the function
 * with the following prototype:
 */

/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f);

/* For floating-point number f, this function computes 0.5*f. If f is NaN, your
 * function should simply return f.
 * Test your function by evaluating it for all 2^32 values of argument f and
 * comparing the result to what would be obtained using your machine’s
 * floating-point operations.
 */

#define F_POS_INF 0x7f800000
#define F_NEG_INF 0xff800000

float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xff;
    unsigned frac = f & 0x7fffff;

    if (exp == 0xff) {
        /* If NaN, return NaN. And if Inf, Inf/2 is still infinity */
        return f;
    }

    /* Round to even bias */
    unsigned bias;
    if ((f & 0x3) == 0x3) {
        bias = 1;
    } else {
        bias = 0;
    }

    if (exp == 0) {
        /* Denormalized mode */
        frac = (frac + bias) >> 1;
    } else if (exp == 1) {
        /* Normalized mode, need to transform to denormalized */
        exp = 0;
        frac |= 0x800000;  // add leading 1
        /* Add rounding bias (2^2 - 1) and shift
         * one for the new leading one
         * and one for the division
         */
        frac = (frac + bias) >> 1;
    } else {
        exp--;
    }
    return (sign << 31) | (exp << 23) | frac;
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
        0x00000001,  // smallest subnormal positive subnormal number (2^-149)
        0x80000001,  // smallest subnormal negative subnormal number (-2^-149)
        0x00800000,  // smallest positive normal number (2^-126)
        0x3f800000,  // one
        0x3f800001,  // smallest number larger than one (1 + 2^-24)
    };

    for (int i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        printf("%d: %a == %a: %d\n",
                i,
                u2f(cases[i]) * 0.5F,
                u2f(float_half(cases[i])),
                u2f(cases[i]) * 0.5F == u2f(float_half(cases[i])));
    }

    unsigned num = 0;
    float f_machine;
    float f_func;
    int ok;

    for (;;) {
        f_machine = .5F*(u2f(num));
        f_func = u2f(float_half(num));
        ok = (f_machine == f_func);
        if (f_machine != f_machine) {  // Only true for NaN
            ok = !ok;
        }
        printf("0x%x: %a == %a: %d\n", num, f_machine, f_func, ok);
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
