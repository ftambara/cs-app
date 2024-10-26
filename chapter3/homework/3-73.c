/* Write a function in assembly code that matches the behavior of the function
 * find_range in Figure 3.51. Your code should contain only one floating-point
 * comparison instruction, and then it should use conditional branches to
 * generate the correct result. Test your code on all 2^32 possible argument
 * values. Web Aside ASM:EASM on page 178 describes how to incorporate functions
 * written in assembly code into C programs.
 *
 *    typedef enum {NEG, ZERO, POS, OTHER} range_t;
 *    
 *    range_t find_range(float x) {
 *        int result;
 *        if (x < 0)
 *            result = NEG;
 *        else if (x == 0)
 *            result = ZERO;
 *        else if (x > 0)
 *            result = POS;
 *        else
 *            result = OTHER;
 *        return result;
 *    }
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float x);

const char* range_string(range_t r) {
    switch (r) {
        case NEG:
            return "NEG";
        case ZERO:
            return "ZERO";
        case POS:
            return "POS";
        case OTHER:
            return "OTHER";
    }
}

void assert_eq(float f, range_t got, range_t expected) {
    if (got != expected) {
        printf("wrong range %a: expected %d (%s), got %d (%s)\n",
                f,
                expected,
                range_string(expected),
                got,
                range_string(got));
        exit(1);
    }
}

int main(void) {
    union conv {
        uint32_t u;
        float f;
    } c;

    c.u = 0;
    assert_eq(c.f, find_range(c.f), ZERO);
    printf("0x%x: OK\n", c.u);

    for (c.u++; c.u < 0x7f800001; c.u++) {
        assert_eq(c.f, find_range(c.f), POS);
    }
    printf("0 to 0x7f800001: OK\n");

    for (; c.u < 0x80000000; c.u++) {
        assert_eq(c.f, find_range(c.f), OTHER);
    }
    printf("0x7f800000 to 0x80000000: OK\n");

    assert_eq(c.f, find_range(c.f), ZERO);
    printf("0x%x: OK\n", c.u);

    for (c.u++; c.u < 0xff800001; c.u++) {
        assert_eq(c.f, find_range(c.f), NEG);
    }
    printf("0x80000000 to 0xff800001: OK\n");

    for (; c.u < UINT32_MAX; c.u++) {
        assert_eq(c.f, find_range(c.f), OTHER);
    }
    printf("0xff800000 to 0xffffffff: OK\n");
}
