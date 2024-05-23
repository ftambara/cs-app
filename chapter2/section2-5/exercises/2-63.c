/*
 * Fill in code for the following C functions. Function srl performs a logical
 * right shift using an arithmetic right shift (given by value xsra), followed
 * by other oper- ations not including right shifts or division. Function sra
 * performs an arithmetic right shift using a logical right shift (given by
 * value xsrl), followed by other operations not including right shifts or
 * division. You may use the computation 8*sizeof(int) to determine w, the
 * number of bits in data type int. The shift amount k can range from 0 to w−1.
 */

#include <stdio.h>

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    /* Trick to get the mask I want without using right shifts or division.
     I essentially do the same by getting complementary zeros on the right
     and then negating that */
    unsigned mask = ~(~0 << (8*sizeof(int) - k));
    return xsra & mask;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (int)((unsigned) x >> k);

    /* Get a 1 on the msb and zeros elsewere */
    unsigned sign_mask = 0x1 << (8*sizeof(int) - 1);
    unsigned char sign = (x & sign_mask) && 1;

    /* Get a pattern of all 1s (negative) or all 0s (positive) */
    unsigned sign_fill = ~(sign - 1);

    /* Use the same technique as in srl */
    unsigned mask = sign_fill << (8*sizeof(int) - k);
    return (int)(xsrl | mask);
}

int main(void) {
    printf("srl(0x80000000, 1) = 0x%X\n", srl(0x80000000, 1));
    printf("srl(0x80000000, 2) = 0x%X\n", srl(0x80000000, 2));
    printf("srl(0x0F000000, 7) = 0x%X\n", srl(0x0F000000, 7));

    printf("sra(0x80000000, 1) = 0x%X\n", sra((int)0x80000000, 1));
    printf("sra(0x80000000, 2) = 0x%X\n", sra((int)0x80000000, 2));
    printf("sra(0x0F000000, 7) = 0x%X\n", sra((int)0x0F000000, 7));
    return 0;
}
