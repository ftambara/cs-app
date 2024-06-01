#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void) {
    /* A */
    float x = 0x1p20F;
    double dx = x;
    printf("A:\n");
    printf("(float) x == (float) dx: %d\n", (float) x == (float) dx);

    /* B */
    x = 0x2p25F;
    dx = (double) x;
    float y = 2.0F;
    double dy = y;
    printf("B:\n");
    printf("dx - dy == (double) (x-y): %d\n", dx - dy == (double) (x-y));

    /* C */
    dx = (double) 1.0F;
    dy = (double) FLT_MAX;
    double dz = (double) -FLT_MAX;
    printf("C:\n");
    printf("(dx + dy) + dz == dx + (dy + dz): %d\n",
            (dx + dy) + dz == dx + (dy + dz));
    printf("(dx + dy) + dz: %f\n", (dx + dy) + dz);
    printf("dx + (dy + dz): %f\n", dx + (dy + dz));

    /* D */
    dx = (double) .1;
    dy = (double) .2;
    dz = (double) .7;
    printf("D:\n");
    printf("(dx * dy) * dz == dx * (dy * dz): %d\n",
            (dx * dy) * dz == dx * (dy * dz));
    printf("(dx * dy) * dz: %f\n", (dx * dy) * dz);
    printf("dx * (dy * dz): %f\n", dx * (dy * dz));

    /* E */
    dx = INFINITY;
    dz = 123.45;
    printf("E:\n");
    printf("dx / dx == dz / dz: %d\n", dx / dx == dz / dz);
    printf("dx / dx: %f\n", dx / dx);
    printf("dz / dz: %f\n", dz / dz);
    return 0;
}
