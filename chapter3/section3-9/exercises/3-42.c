#include <stdlib.h>
/* The following code shows the declaration of a structure of type
 * ELE and the prototype for a function fun:
 */

struct ELE {
    long v;
    struct ELE *p;
};
long fun(struct ELE *ptr);

/* When the code for fun is compiled, GCC generates the following assembly code:
 *
 * # long fun(struct ELE *ptr)
 * # ptr in %rdi
 * 1   fun:
 * 2       movl    $0, %eax
 * 3       jmp     .L2
 * 4   L3:
 * 5       addq    (%rdi), %rax
 * 6       movq    8(%rdi), %rdi
 * 7   .L2:
 * 8       testq   %rdi, %rdi
 * 9       jne     .L3
 * 10      rep; ret
 */

/* A. Use your reverse engineering skills to write C code for fun. */
long fun(struct ELE *ptr) {
    long sum = 0;
    while (ptr != NULL) {
        sum += ptr->v;
        ptr = ptr->p;
    }
    return sum;
}

/* B. Describe the data structure that this structure implements and the
 * operation performed by fun.
 */

/* `ELE` implements a linked list node with `long` values.
 * `fun` sums all values in the list starting from node `ptr`
 */
