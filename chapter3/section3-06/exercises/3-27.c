#include <stdio.h>

/* Write goto code for fact_for based on first transforming it to a while loop
 * and then applying the guarded-do transformation.
 */

long fact_for_while(short n) {
    long result = 1;
    long i = 2;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

long fact_for(short n) {
    long result = 1;
    long i = 2;
    if (n < 2) {
        goto done;
    }
loop:
    result *= i;
    i++;
    if (i <= n) {
        goto loop;
    }
done:
    return result;
}

int main(void) {
    return 0;
}
