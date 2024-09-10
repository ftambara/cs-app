#include <stdio.h>

typedef int (*op_fn)(int a, int b);

int operate(op_fn fn, int a, int b) {
    return fn(a, b);
}

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int main(void) {
    printf("operate(&add, 4, 5) = %d\n", operate(&add, 4, 5));
    printf("operate(&mul, 4, 5) = %d\n", operate(&mul, 4, 5));

    return 0;
}
