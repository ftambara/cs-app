#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef unsigned float_bits;

/* Following the bit-level floating-point coding rules, implement the function
 * with the following prototype:
 */

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_twice(float_bits f);

/* For floating-point number f, this function computes 2.0*f. If f is NaN, your
 * function should simply return f.
 * Test your function by evaluating it for all 2^32 values of argument f and
 * comparing the result to what would be obtained using your machine’s
 * floating-point operations.
 */

#define F_POS_INF 0x7F800000
#define F_NEG_INF 0xFF800000
#define F_NORMAL_MAX_EXP 0xFE

float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && f != 0) {
        return f;
    }
    if (exp == F_NORMAL_MAX_EXP || (exp == 0xFF && frac == 0)) {
        /* overflow */
        if (sign == 0) {
            return F_POS_INF;
        } else {
            return F_NEG_INF;
        }
    }
    if (exp == 0) {
        /* denormalized value */
        if ((frac & 0x800000) == 0) {
            /* has room to grow */
            frac <<= 1;
        } else {
            /* transform to normalized value */
            frac <<= 1;
            exp = 1;
        }
    } else {
        exp++;
    }
    return (sign << 31) | (exp << 23) | frac;
}

float u2f(unsigned x) {
    return *(float *) &x;
}

int main(void) {
    /* Test corner cases */
    /*
    // x = 0
    printf("float_twice(0x00000000): %a\n", u2f(float_twice(0x00000000)));
    // x = +∞
    printf("float_twice(0x7f800000): %a\n", u2f(float_twice(0x7f800000)));
    // x = -∞
    printf("float_twice(0xff800000): %a\n", u2f(float_twice(0xff800000)));
    // largest subnormal number (x = 2^-126 * (1 - 2^-23))
    printf("float_twice(0x007fffff): %a\n", u2f(float_twice(0x007fffff)));
    // largest normal number (x = 2^127 * (1 - 2^-23))
    printf("float_twice(0x7f7fffff): %a\n", u2f(float_twice(0x7f7fffff)));
    // largest number less than one (x = 1 - 2^-24)
    printf("float_twice(0x3f7fffff): %a\n", u2f(float_twice(0x3f7fffff)));
    */

    unsigned num = 0;
    float f_machine;
    float f_func;
    int ok;
    for (;;) {
        f_machine = 2.0F*(u2f(num));
        f_func = u2f(float_twice(num));
        ok = (f_machine == f_func);
        if (f_machine != f_machine) {  /* Only true for NaN */
            ok = !ok;
        }
        printf("%a == %a: %d\n", f_machine, f_func, ok);
        assert(ok);
        if (num == UINT_MAX) {
            break;
        }
        num++;
    }
    return 0;
}
