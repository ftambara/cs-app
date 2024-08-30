typedef union {
    struct {
        long u;
        short v;
        char w;
    } t1;
    struct {
        int a[2];
        char *p;
    } t2;
} u_type;

void get_a(u_type *up, int *dest[2]) {
    *dest = up->t2.a;
}

void get_a_pos(u_type *up, int *dest) {
    *dest = up->t2.a[up->t1.u];
}

void get_p(u_type *up, char *dest) {
    *dest = *up->t2.p;
}
