#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    // A.
    int x = INT_MAX;
    printf("A: x: %d\n", x);
    printf("   (int)(double)x: %d\n", (int)(double)x);

    // B.
    x = (2<<25) + 1;
    printf("B: x: %d\n", x);
    printf("   (int)(float)x: %d\n", (int)(float)x);

    // C.
    double d = (double)(2<<25);
    printf("C: d: %lf\n", d);
    printf("   (double)(float)d: %lf\n", (double)(float)d);

    // D.
    float f = (float)12345.125;
    printf("D: f: %f\n", f);
    printf("   (float)(double)f: %f\n", (float)(double)f);

    // E.
    printf("E: f: %f\n", f);
    printf("   -(-f): %f\n", -(-f));

    // F.
    printf("F: 1.0/2=%f; 1/2.0=%f\n", 1.0/2, 1/2.0);

    // G.
    d = -DBL_MAX;
    printf("G: d*d: %f\n", d*d);

    // H.
    f = FLT_MAX;
    d = 10;
    printf("H: d: %lf\n", d);
    printf("   (f+d)-f: %lf\n", (f+d)-f);

    return 0;
}
