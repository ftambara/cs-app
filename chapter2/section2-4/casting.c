#include <limits.h>
#include <stdio.h>

int main(void) {
    double tooLarge = UINT_MAX + 1.0;

    printf("unsigned: %u\n", (unsigned int)tooLarge);
    printf("int: %d\n", (int)tooLarge);

    return 0;
}
