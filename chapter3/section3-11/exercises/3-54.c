/* Function funct2 has the following prototype: */
double funct2(double w, int x, float y, long z);

/* GCC generates the following code for the function:
 *
 *   double funct2(double w, int x, float y, long z)
 *    w in %xmm0, x in %edi, y in %xmm1, z in %rsi
 *   1 funct2:
 *   2    vcvtsi2ss   %edi, %xmm2, %xmm2
 *   3    vmulss      %xmm1, %xmm2, %xmm1
 *   4    vunpcklps   %xmm1, %xmm1, %xmm1
 *   5    vcvtps2pd   %xmm1, %xmm2
 *   6    vcvtsi2sdq  %rsi, %xmm1, %xmm1
 *   7    vdivsd      %xmm1, %xmm0, %xmm0
 *   8    vsubsd      %xmm0, %xmm2, %xmm0
 *   9    ret
 *
 * Write a C version of funct2.
 */

double funct2(double w, int x, float y, long z) {
    double prod = (double) (y * (float) x);
    return prod - (w / (double) z);
}
