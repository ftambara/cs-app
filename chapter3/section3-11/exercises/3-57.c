/* Function funct3 has the following prototype: */
double funct3(int *ap, double b, long c, float *dp);

/*
 * For this function, gcc generates the following code:
 *
 *  double funct3(int *ap, double b, long c, float *dp)
 *  ap in %rdi, b in %xmm0, c in %rsi, dp in %rdx
 *  1   funct3:
 *  2       vmovss (%rdx), %xmm1
 *  3       vcvtsi2sd (%rdi), %xmm2, %xmm2
 *  4       vucomisd %xmm2, %xmm0
 *  5       jbe .L8
 *  6       vcvtsi2ssq %rsi, %xmm0, %xmm0
 *  7       vmulss %xmm1, %xmm0, %xmm1
 *  8       vunpcklps %xmm1, %xmm1, %xmm1
 *  9       vcvtps2pd %xmm1, %xmm0
 *  10      ret
 *  11  .L8:
 *  12      vaddss %xmm1, %xmm1, %xmm1
 *  13      vcvtsi2ssq %rsi, %xmm0, %xmm0
 *  14      vaddss %xmm1, %xmm0, %xmm0
 *  15      vunpcklps %xmm0, %xmm0, %xmm0
 *  16      vcvtps2pd %xmm0, %xmm0
 *  17  ret
 *
 * Write a C version of funct3
 */

double funct3(int *ap, double b, long c, float *dp) {
    /*
     *  1   funct3:
     *  2       vmovss (%rdx), %xmm1                xmm1 = *dp
     *  3       vcvtsi2sd (%rdi), %xmm2, %xmm2      xmm2 = (double) *ap
     *  4       vucomisd %xmm2, %xmm0               compare xmm2 to b
     *  5       jbe .L8                             
     *  6       vcvtsi2ssq %rsi, %xmm0, %xmm0       xmm0 = (float) c
     *  7       vmulss %xmm1, %xmm0, %xmm1          xmm1 *= (float) c
     *  8       vunpcklps %xmm1, %xmm1, %xmm1
     *  9       vcvtps2pd %xmm1, %xmm0              return (double) xmm1
     *  10      ret
     *  11  .L8:                                    if b <= (double) *ap
     *  12      vaddss %xmm1, %xmm1, %xmm1          xmm1 += *dp
     *  13      vcvtsi2ssq %rsi, %xmm0, %xmm0       xmm0 = (float) c
     *  14      vaddss %xmm1, %xmm0, %xmm0          xmm0 = (float) c + 2 * *dp
     *  15      vunpcklps %xmm0, %xmm0, %xmm0
     *  16      vcvtps2pd %xmm0, %xmm0              return (double) xmm0
     *  17  ret
     */
    if (b <= (double) *ap) {
        return (float) c + 2 * *dp;
    }
    return *dp * (float) c;
}
