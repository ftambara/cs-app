/* Endianness determines how bytes are ordered in a contiguous block of
 * virtual memory. Little endian machines store the least significant byte
 * on the lowest byte address, whilist big endian's store the most significant
 * byte first.
 * Confusion may arise when representing little-endian sequences, given that
 * the bits that constitute each byte seem to follow a big-endian convention,
 * defeating consistency. My understanding is that, since we don't usually
 * control data on a bit level, the way we choose to represent bytes is
 * irrelevant. My only doubt is with bit masks, but since we'll use the same
 * conventions for writing hexadecimal literals, that problem might not exist.
 */

#include <stdio.h>


typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (size_t i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_string(char *x, size_t len) {
    show_bytes((byte_pointer) x, len * sizeof(char));
}


typedef union {
    short value;
    char bytes[sizeof(short)];
} short_bytes;

// Define a bitmap struct
typedef struct {
    unsigned int a:1;
    unsigned int b:1;
    unsigned int c:1;
    unsigned int d:1;
} bitmap;

typedef union {
    bitmap bits;
    char byte;
} bitmap_bytes;

int main(void) {
    int n = 5;
    show_int(n);
    show_float(n);
    show_float((float)n);
    show_pointer(&n);
    show_string("12345", 6);

    show_int(0x0123);
    // 23 01 00 00

    show_int(0x0123 & 0xFF);
    // 23 00 00 00
    // This proves that as long as you deal with the full structure of bytes,
    // since both the mask and the target value are both converted to the
    // appropriate internal representation, the result comes out right.

    short_bytes sb;
    sb.bytes[0] = 0xff;
    sb.bytes[1] = 0xa1;
    show_bytes((byte_pointer) &sb.value, sizeof(short));
    printf("%d\n", sb.value);

    bitmap_bytes bb;
    bb.bits.a = 1;
    bb.bits.b = 0;
    bb.bits.c = 1;
    bb.bits.d = 0;
    printf("%d\n", bb.byte);
    show_bytes((byte_pointer) &bb.byte, sizeof(char));

    return 0;
}
