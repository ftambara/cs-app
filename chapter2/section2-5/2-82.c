#include <stdio.h>
#include <limits.h>

int main(void) {
    /* A: (x<y) == (-x>-y) */
    int x = INT_MIN;
    int y = 5;
    printf("(%d < %d) == (%d > %d) is %d\n",
            x, y, -x, -y, (x < y) == (-x > -y));

    /* B: ((x+y)<<4) + y-x == 17*y+15*x */
    printf("(%d + %d) << 4 + %d - %d == 17*%d + 15*%d is %d\n",
            x, y, y, x, y, x, ((x+y)<<4) + y-x == 17*y+15*x);

    /* C: ~x+~y+1 == ~(x+y) */
    printf("~%d + ~%d + 1 == ~(%d + %d) is %d\n",
            x, y, x, y, ~x+~y+1 == ~(x+y));

    /* D: (ux-uy) == -(unsigned)(y-x) */
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    printf("(%u - %u) == -(unsigned)(%d - %d) is %d\n",
            ux, uy, y, x, (ux-uy) == -(unsigned)(y-x));
    printf("%u - %u = %u\n", ux, uy, ux-uy);
    printf("%d - %d = %d\n", y, x, y-x);
    printf("(unsigned)(%d - %d) = %u\n", y, x, (unsigned)(y-x));
    printf("-(%d - %d) = %d\n", y, x, -(y-x));
    printf("-(unsigned)(%d - %d) = %u\n", y, x, -(unsigned)(y-x));

    /* E: ((x >> 2) << 2) <= x */
    printf("((%d >> 2) << 2) <= %d is %d\n",
            x, x, ((x >> 2) << 2) <= x);
    return 0;
}
