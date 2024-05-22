/*
 * Write a procedure is_little_endian that will return 1 when compiled and run
 * on a little-endian machine, and will return 0 when compiled and run on a
 * big-endian machine. This program should run on any machine, regardless of its
 * word size.
 */

#include <stdio.h>
#include <stdbool.h>

bool is_little_endian() {
    int example = 0x01;
    unsigned char *byte = (unsigned char *)&example;
    return *byte == 1;
}

int main(void) {
    printf("Is this machine little endian?: %d\n", is_little_endian());
    return 0;
}
