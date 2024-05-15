#include <limits.h>
#include <stdio.h>


typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

int main() {
    short x = 12345;
    short mx = -x;

    show_bytes((byte_pointer) &x, sizeof(short));
    // 39 30
    show_bytes((byte_pointer) &mx, sizeof(short));
    // c7 cf

    short v = -12345;
    unsigned short uv = (unsigned short) v;
    printf("v = %d, uv = %u\n", v, uv);

    show_bytes((byte_pointer) &uv, sizeof(unsigned short));
    // c7 cf
    // It has the same byte representation as -12345, meaning C's
    // casting only re-interprets the bytes, it doesn't change them
    // (at least in this case)
    
    float f = 23.0F;
    int i = (int) f;
    show_bytes((byte_pointer) &f, sizeof(float));
    // 00 00 b8 41
    show_bytes((byte_pointer) &i, sizeof(int));
    // 17 00 00 00
    // For float-to-int casting, instead, the bytes are changed

    unsigned u = UINT_MAX;
    int tu = (int) u;
    printf("u = %u, tu = %d\n", u, tu);

    short sx = -12345;
    unsigned short usx = sx;
    int n = sx;
    unsigned ux = usx;
    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));
    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    printf("n = %d:\t", n);
    show_bytes((byte_pointer) &n, sizeof(int));
    printf("ux = %u:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned));
}
