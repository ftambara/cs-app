#include <stdio.h>


float to_c(float f) {
    return 5.0 * (f - 32)/9.0;
}

int main(void) {
    int from_temp;
    int to_temp;
    int step;

    printf("F to C table\n");
    printf("From: ");
    scanf("%d", &from_temp);
    printf("To: ");
    scanf("%d", &to_temp);
    printf("Step: ");
    scanf("%d", &step);

    for (; from_temp < to_temp; from_temp += step) {
        printf("%4d F\t%6.2f C\n", from_temp, to_c(from_temp));
    }
}
