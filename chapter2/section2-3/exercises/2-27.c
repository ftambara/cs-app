/* Write a function with the following prototype: */

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y);

/* This function should return 1 if arguments x and y can be added without
causing overflow. */

int uadd_ok(unsigned x, unsigned y) {
    return x + y < x
}
