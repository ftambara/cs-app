#include <stdio.h>

typedef struct {
    int a;
    int b;
    char c;
} s1_t;

typedef struct {
    int a;
    char c;
    int b;
} s2_t;

typedef struct {
    char c;
    int a;
    int b;
} s3_t;

typedef struct {
    char a;
    int b;
    char c;
    char d;
} s4_t;

typedef struct {
    int b;
    char a;
    char c;
    char d;
} s5_t;

typedef struct {
    char a;
    char c;
    char d;
    int b;
} s6_t;

struct P1 { int i; char c; int j; char d; };
struct P2 { int i; char c; char d; long j; };
struct P3 { short w[3]; char c[3]; };
struct P4 { short w[5]; char *c[3]; };
struct P5 { struct P3 a[2]; struct P2 t; };

int main(void) {
    printf("sizeof(s1_t) = %lu\n", sizeof(s1_t));
    printf("sizeof(s2_t) = %lu\n", sizeof(s2_t));
    printf("sizeof(s3_t) = %lu\n", sizeof(s3_t));
    printf("sizeof(s4_t) = %lu\n", sizeof(s4_t));
    printf("sizeof(s5_t) = %lu\n", sizeof(s5_t));
    printf("sizeof(s6_t) = %lu\n", sizeof(s6_t));

    printf("sizeof(P1) = %lu\n", sizeof(struct P1));
    printf("sizeof(P2) = %lu\n", sizeof(struct P2));
    printf("sizeof(P3) = %lu\n", sizeof(struct P3));
    printf("sizeof(P4) = %lu\n", sizeof(struct P4));
    printf("sizeof(P5) = %lu\n", sizeof(struct P5));
    return 0;
}
