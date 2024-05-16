/* Write a function with the following prototype: */

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);
/* This function should return 1 if arguments x and y can be added without
causing overflow. */


int tadd_ok(int x, int y) {
    if (x < 0 && y < 0) {
        return x+y < 0;
    }
    if (x > 0 && y > 0) {
        return x+y > 0;
    }
    return 1;
}
