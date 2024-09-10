#include <stdio.h>

long vframe(long n, long idx, long* q) {
    long i;
    long* p[n];
    p[0] = &i;
    for (i = 1; i < n; i++) {
        p[i] = q;
    }
    return *p[idx];
}

long vframe_opt(long n, long idx, const long* q) {
    if (idx == 0) {
        return n;
    }
    return *q;
}

int main(void) {
    // Test both functions
    long idxes[] = {0, 1, 2, 3, 4, 5, 6, 7};
    long q = 0;
    long res1;
    long res2;
    for (int i = 0; i < 8; i++) {
        res1 = vframe(8, idxes[i], &q);
        res2 = vframe_opt(8, idxes[i], &q);
        if (res1 != res2) {
            printf("Error: res1 = %ld, res2 = %ld\n", res1, res2);
            return 1;
        }
    }

    q = 1;
    for (int i = 0; i < 8; i++) {
        res1 = vframe(8, idxes[i], &q);
        res2 = vframe_opt(8, idxes[i], &q);
        if (res1 != res2) {
            printf("Error: res1 = %ld, res2 = %ld\n", res1, res2);
            return 1;
        }
    }
}
