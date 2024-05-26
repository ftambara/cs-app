#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 * The library function calloc has the following declaration:
 *
 *  void *calloc(size_t nmemb, size_t size);
 *
 * According to the library documentation, “The `calloc` function allocates
 * memory for an array of `nmemb` elements of size bytes each. The memory is set
 * to zero. If `nmemb` or size is zero, then `calloc` returns `NULL`.”
 * Write an implementation of `calloc` that performs the allocation by a call to
 * `malloc` and sets the memory to zero via `memset`. Your code should not have
 * any vulnerabilities due to arithmetic overflow, and it should work correctly
 * regardless of the number of bits used to represent data of type `size_t`.
 * As a reference, functions `malloc` and `memset` have the following
 * declarations:
 *
 * void *malloc(size_t size);
 * void *memset(void *s, int c, size_t n);
 */

void *my_calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) {
        return NULL;
    }
    size_t total_size = nmemb * size;
    int mult_ok = size && (total_size/size == nmemb);
    if (!mult_ok) {
        /* Multiplication_overflow */
        printf("Multiplication overflow\n");
        exit(1);
    }

    void *p = malloc(total_size);
    if (!p) {
        /* Failed to allocate total_size bytes */
        printf("Failed to allocate %zu bytes\n", total_size);
        exit(1);
    }

    memset(p, 0, total_size);
    return p;
}

int main(void) {
    size_t nmemb = 10;
    size_t size = 8;
    int *p = my_calloc(nmemb, size);
    printf("p = %p\n", (void *)p);
    for (size_t i = 0; i < 2*nmemb; i++) {
        printf("p[%zu] = %d\n", i, p[i]);
    }
    free(p);

    nmemb = 0;
    p = my_calloc(nmemb, size);
    printf("p = %p\n", (void *)p);
    free(p);

    nmemb = SIZE_MAX;
    size = 2;
    /* This should exit the program */
    p = my_calloc(nmemb, size);

    return 0;
}
