#include <stdio.h>

#define POS_INFINITY    1e310
#define NEG_INFINITY    -1e310
#define NEG_ZERO        -0.0

int main(void) {
    printf("POS_INFINITY: %f\n", POS_INFINITY);
    printf("NEG_INFINITY: %f\n", NEG_INFINITY);
    printf("NEG_ZERO: %f\n", NEG_ZERO);
    return 0;
}
