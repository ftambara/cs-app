#include <stdio.h>
#include <assert.h>
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

#define F_POS_INF 0x7F800000
#define F_NEG_INF 0xFF800000

float_bits float_half(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && f != 0) {
        return f;
    }
    if (exp == 0xFF && frac == 0) {
        /* Infinity/2 is still infinity */
        return f;
    }
    if (exp == 0) {
        /* Denormalized mode */
        /* Rounding bias is 0 (2^0 - 1), no need to add */
        frac >>= 1;
    } else if (exp == 1) {
        /* Normalized mode, need to transform to denormalized */
        exp = 0;
        frac |= 0x800000;  // add leading 1
        /* Add rounding bias (2^1 - 1) and shift
         * one for the new leading one
         * and one for the division
         */
        frac = (frac + 1) >> 2;
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
    // x = 0
    printf("float_half(0x00000000): %a\n", u2f(float_half(0x00000000)));
    // x = +∞
    printf("float_half(0x7f800000): %a\n", u2f(float_half(0x7f800000)));
    // x = -∞
    printf("float_half(0xff800000): %a\n", u2f(float_half(0xff800000)));
    // smallest subnormal positive subnormal number (x = 2^-149)
    printf("float_half(0x00000001): %a\n", u2f(float_half(0x00000001)));
    // smallest subnormal negative subnormal number (x = -2^-149)
    printf("float_half(0x80000001): %a\n", u2f(float_half(0x80000001)));
    // smallest positive normal number (x = 2^-126)
    printf("float_half(0x00800000): %a\n", u2f(float_half(0x00800000)));
    // one
    printf("float_half(0x3f800000): %a\n", u2f(float_half(0x3f800000)));
    // smallest number larger than one (x = 1 + 2^-24)
    printf("float_half(0x3f800001): %f\n", u2f(float_half(0x3f800001)));

    /*
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
        printf("%a == %a: %d\n", f_machine, f_func, ok);
        assert(ok);
        if (num == UINT_MAX) {
            break;
        }
        num++;
    }
    */
    return 0;
}
