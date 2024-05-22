/*
 * Suppose we number the bytes in a w-bit word from 0 (least significant) to
 * w/8 − 1 (most significant). Write code for the following C function, which
 * will return an unsigned value in which byte i of argument x has been
 * replaced by byte b:
 *
 *  unsigned replace_byte (unsigned x, int i, unsigned char b);
 *
 * Here are some examples showing how the function should work:
 *
 *  replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 *  replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
 */

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b);

int main(void) {
    printf(
        "replace_byte(0x12345678, 2, 0xAB): %X\n",
        replace_byte(0x12345678, 2, 0xAB));
    printf(
        "replace_byte(0x12345678, 0, 0xAB): %X\n",
        replace_byte(0x12345678, 0, 0xAB));
    printf(
        "replace_byte(0x12345678, -1, 0xAB): %X\n",
        replace_byte(0x12345678, -1, 0xAB));
    printf(
        "replace_byte(0x12345678, -1, 0xAB): %X\n",
        replace_byte(0x12345678, 5, 0xAB));
    return 0;
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    if (i < 0 || i >= sizeof x) {
        return 0;
    }
    unsigned res = x;
    unsigned char *byte_p = (unsigned char *)&res;
    byte_p += i;
    *byte_p = b;
    return res;
}
