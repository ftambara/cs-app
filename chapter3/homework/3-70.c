#include <stdio.h>

union ele {
    struct {
        long *p;
        long y;
    } e1;
    struct {
        long x;
        union ele *next;
    } e2;
};

int main(void) {
    union ele u;
    void* start = &u;
    printf("offset(e1.p) = %ld\n", (void *) &(u.e1.p) - start);
    printf("offset(e1.y) = %ld\n", (void *) &(u.e1.y) - start);
    printf("offset(e2.x) = %ld\n", (void *) &(u.e2.x) - start);
    printf("offset(e2.next) = %ld\n", (void *) &(u.e2.next) - start);
    printf("sizeof(union ele) = %lu\n", sizeof(union ele));
}
