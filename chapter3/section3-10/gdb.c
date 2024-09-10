#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Implementation of library function gets()
char* gets(char* s) {
    int c;
    char *dest = s;
    while ((c = getchar()) != '\n' && c != EOF) {
        *dest++ = (char)c;
    }
    if (c == EOF && dest == s) {
        // No characters read
        return NULL;
    }
    *dest++ = '0';  // Terminate string
    return s;
}

// Read input line and write it back
void echo(void) {
    char buf[8];  // Way too small!
    gets(buf);
    puts(buf);
}
