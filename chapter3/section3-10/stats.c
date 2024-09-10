#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { LINE_SIZE = 15 };

void print_stats(size_t n, const long nums[n], short slots_n) {
    if (n == 0 || slots_n == 0) {
        return;
    }
    printf("Stats:\n");
    long min = nums[0];
    long max = nums[0];

    long slots[slots_n];
    for (size_t i = 0; i < slots_n; i++) {
        slots[i] = 0;
    }

    for (size_t i = 0; i < n; i++) {
        if (nums[i] < min) {
            min = nums[i];
        } else if (nums[i] > max) {
            max = nums[i];
        }
    }
    printf("Min: %lx\n", min);
    printf("Max: %lx\n", max);
    printf("Δ: %lu\n", max-min);

    printf("Slots:\n");
    long step = (max - min) / slots_n;
    for (size_t i = 0; i < n; i++) {
        long slot = (long) (slots_n * (double) (nums[i] - min) / (double) (max - min));
        slots[slot]++;
    }
    for (size_t i = 0; i < slots_n; i++) {
        printf("%16lx\n", min + (i * step));
        printf("                ");
        printf("%ld\n", slots[i]);
    }
    printf("%16lx\n", min + (slots_n * step));
}

int main(void) {
    FILE* fp = fopen("stacks", "rt");
    if (fp == NULL) {
        perror("Error opening 'stacks'");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char buf[size];
    size_t read = fread(buf, sizeof(buf[0]), size, fp);
    fclose(fp);
    if (read != size) {
        perror("Error reading 'stacks'");
        exit(1);
    }

    size_t address_n = size / LINE_SIZE;
    unsigned long addresses[address_n];
    char* next = buf;
    char* endp;
    for (size_t i = 0; i < address_n; i++) {
        unsigned long n = strtol(next, &endp, 16);
        if (endp == next) {
            break;
        }
        next = endp;
        addresses[i] = n;
    }

    print_stats(address_n, (const long *) addresses, 10);
}
