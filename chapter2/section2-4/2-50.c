#include <stdint.h>
#include <stdio.h>

typedef uint32_t fourbytes;

/* My calculated value is 00111101110011001100110011001101
 * In hex, this is 3DCCCCCD
 * This is the same as the output of the program */
int main() {
    float pointone = 0.1F;
    fourbytes *p = (fourbytes *)&pointone;
    printf("%08X\n", *p);
    return 0;
}
