#include <stdio.h>
#include <assert.h>
#include <limits.h>

typedef unsigned float_bits;

/* Following the bit-level floating-point coding rules, implement the function
 * with the following prototype:
 */

/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f);

/* For floating-point number f, this function computes |f|. If f is NaN, your
 * function should simply return f.
 * Test your function by evaluating it for all 2^32 values of argument f and
 * comparing the result to what would be obtained using your machine’s
 * floating-point operations.
 */

float u2f(unsigned x) {
    return *(float *) &x;
}

float_bits float_absval(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if (exp == 0xFF && frac != 0) {
        return f;
    }
    return 0 | exp << 23 | frac;
}

float absf(float f) {
    if (f < 0) {
        return -f;
    }
    return f;
}

int main(void) {
    unsigned num = 0;
    float f_machine;
    float f_func;
    int ok;
    for (;;) {
        f_machine = absf(u2f(num));
        f_func = u2f(float_absval(num));
        ok = (f_machine == f_func);
        if (f_machine != f_machine) {  /* Only true for Nan */
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
