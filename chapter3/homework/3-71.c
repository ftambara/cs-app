/*
 * Write a function good_echo that reads a line from standard input and writes
 * it to standard output. Your implementation should work for an input line of
 * arbitrary length. You may use the library function fgets, but you must make
 * sure your function works correctly even when the input line requires more
 * space than you have allocated for your buffer. Your code should also check
 * for error conditions and return when one is encountered. Refer to the
 * definitions of the standard I/O functions for documentation [45, 61].
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int good_echo(char* buffer, size_t len){
    if (len > INT_MAX) {
        perror("len too long");
        return 1;
    }
    while(fgets(buffer, (int)len, stdin) != NULL) {
        if (fputs(buffer, stdout) < 0) {
            perror("error writing to stdout");
            return 1;
        }
    }
    if (!feof(stdin)) {
        perror("error reading stdin");
        return 1;
    }
    return 0;
}

int main(void) {
    size_t bufsize = 128;
    char* buffer = malloc(bufsize);
    exit(good_echo(buffer, bufsize));
}
