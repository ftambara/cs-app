#include <inttypes.h>
#include <stdio.h>

int32_t fact32(int32_t n) {
    int32_t result = 1;
    do {
        result *= n;
        n--;
    } while (n > 1);
    return result;
}


int64_t fact64(int64_t n) {
    int64_t result = 1;
    do {
        result *= n;
        n--;
    } while (n > 1);
    return result;
}

int main(void) {
    /* A. Try to calculate 14! with a 32-bit int. Verify whether the computation
     * of 14! overflows.
     */
    {
        int32_t fact14 = fact32(14);
        printf("14!(32) = %" PRId32 "\n", fact14);

        int32_t fact13 = fact32(13);
        int overflows = (fact14 / fact13) != 14;
        printf("Overflows? %d\n", overflows);
    }

    /* B. What if the computation is done with a 64-bit long int? */
    {
        int64_t fact14 = fact64(14);
        printf("14!(64) = %" PRId64 "\n", fact14);

        int64_t fact13 = fact64(13);
        int overflows = (fact14 / fact13) != 14;
        printf("Overflows? %d\n", overflows);
    }
}
