#include <stdio.h>
#include <math.h>

/* 
 * Fill in the return value for the following procedure, which tests whether its
 * first argument is less than or equal to its second. Assume the function f2u
 * returns an unsigned 32-bit number having the same bit representation as its
 * floating-point argument. You can assume that neither argument is NaN. The two
 * flavors of zero, +0 and −0, are considered equal.
 */

unsigned f2u(float x) {
    return *(unsigned *)&x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    /* Give an expression using only ux, uy, sx, and sy */
    return (
        // Return 1 if both numbers are any kind of zero
        (ux << 1 == 0 && uy << 1 == 0)
        // Return 1 if the exponent bits of ux < exponent bits of uy
        || ((ux & 0x7f800000) < (uy & 0x7f800000))
        // Return 1 if the fraction bits of ux <= fraction bits of uy
        || ((ux & 0x007FFFFF) <= (uy & 0x007FFFFF))
    );
}

int main(void) {
    printf("f2u(0.5F) = 0x%x\n", f2u(0.5F));

    printf("float_le(0.5F, 0.5F) = %d\n", float_le(0.5F, 0.5F));
    printf("float_le(0.5F, 0.6F) = %d\n", float_le(0.5F, 0.6F));
    printf("float_le(0.6F, 0.5F) = %d\n", float_le(0.6F, 0.5F));
    printf("float_le(0.0F, 0.0F) = %d\n", float_le(0.0F, 0.0F));
    printf("float_le(-0.0F, 0.0F) = %d\n", float_le(-0.0F, 0.0F));
    printf("float_le(1E-10F, 1E-11F) = %d\n", float_le(1E10F, 1E10F));
    printf("float_le(1E-12F, 1E-11F) = %d\n", float_le(1E12F, 1E11F));
    printf("float_le(1E-10F, 5E-20F) = %d\n", float_le(1E10F, 5E20F));
    printf("float_le(5E-20F, INFINITY) = %d\n", float_le(5E-20F, INFINITY));

    return 0;
}
