#include <stdio.h>


typedef unsigned char byte;


int main(void) {
    byte bytes[] = {0xD4, 0x64, 0x72, 0x44};
    short nBytes = 4;

    for (short i = 0; i < nBytes; i++) {
        printf("a = %x\n", bytes[i]);
        printf("  a<<2 = %x\n", (byte)(bytes[i]<<2));
        printf("  a>>3 (logical) = %x\n", (byte)(bytes[i]>>3));
        printf("  a>>3 (arithm.) = %x\n", (byte)(((signed char)(bytes[i]))>>3));
    }
}
