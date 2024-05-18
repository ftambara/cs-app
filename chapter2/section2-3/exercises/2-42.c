/* Write a function div16 that returns the value x/16 for integer argument x.
 * Your function should not use division, modulus, multiplication, any
 * conditionals (if or ?:), any comparison operators (e.g., <, >, or ==), or
 * any loops. You may assume that data type int is 32 bits long and uses a
 * two’s-complement representation, and that right shifts are performed
 * arithmetically. */

#include <stdint.h>

int32_t div16(int32_t x) {
    unsigned char sign = ((uint32_t) x)>>31;
    return (x + (sign<<4) - sign) >> 4;
}
