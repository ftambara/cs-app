/* Used to check the solution to problem 2.14 */

#include <stdio.h>


int main(void) {
    int a = 0x44, b = 0x57;
	printf("a & b = %x\n", a & b);
	printf("a | b = %x\n", a | b);
	printf("~a | ~b = %x\n", ~a | ~b);
	printf("a & !b = %x\n", a & !b);
	printf("a && b = %x\n", a && b);
	printf("a || b = %x\n", a || b);
	printf("!a || !b = %x\n", !a || !b);
	printf("a && ~b = %x\n", a && ~b);
}
