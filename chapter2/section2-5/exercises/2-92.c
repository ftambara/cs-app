#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned float_bits;

/* Following the bit-level floating-point coding rules, implement the function
 * with the following prototype:
 */

/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f);

/* For floating-point number f, this function computes −f. If f is NaN, your
 * function should simply return f. Test your function by evaluating it for all
 * 2^32 values of argument f and comparing the result to what would be obtained
 * using your machine’s floating-point operations.
 */

float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = (f >> 23) & 0xFF;  /* last 8 bits */
    unsigned frac = f & 0x7FFFFF;  /* last 23 bits */

    if (exp == 0xFF && frac != 0) {
        return f;
    }
    return (~sign << 31) | (f & 0x7FFFFFFF); /* last 31 bits */
}

float u2f(unsigned x) {
    return *(float *) &x;
}

int main(void) {
    unsigned num = 0;
    float f_machine;
    float f_func;
    int ok;
    for (;;) {
        f_machine = -u2f(num);
        f_func = u2f(float_negate(num));
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
