/* For the case where data type int has 32 bits, devise a version of tmult_ok
 * (Problem 2.35) that uses the 64-bit precision of data type int64_t, without
 * using division. */

#include <stdint.h>
#include <stdio.h>

int tmult_ok(int32_t x, int32_t y) {
    int64_t prod = (int64_t)x*y;
    return prod == (int32_t)prod;
}

int main(void){
    printf("tmult_ok(INT32_MAX/2, INT32_MAX/2)=%d\n",
            tmult_ok(INT32_MAX/2, INT32_MAX/2));
    printf("tmult_ok(2, INT32_MAX/2)=%d\n", tmult_ok(2, INT32_MAX/2));
}
