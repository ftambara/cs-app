/*
 * This problem will give you a chance to reverse engineer a switch statement
 * from disassembled machine code. In the following procedure, the body of the
 * switch statement has been omitted:
 *
 *    1  long switch_prob(long x, long n) {
 *    2      long result = x;
 *    3      switch(n) {
 *    4          // Fill in code here
 *    5
 *    6      }
 *    7      return result;
 *    8  }
 *
 * Figure 3.53 shows the disassembled machine code for the procedure. The jump
 * table resides in a different area of memory. We can see from the indirect
 * jump on line 5 that the jump table begins at address 0x4006f8. Using the gdb
 * debugger, we can examine the six 8-byte words of memory comprising the jump
 * table with the command x/6gx 0x4006f8. Gdb prints the following:
 *
 *
 *    (gdb) x/6gx 0x4006f8
 *    0x4006f8:   0x00000000004005a1  0x00000000004005c3
 *    0x400708:   0x00000000004005a1  0x00000000004005aa
 *    0x400718:   0x00000000004005b2  0x00000000004005bf
 *
 * Fill in the body of the switch statement with C code that will have the same
 * behavior as the machine code.
 *
 *
 *      long switch_prob(long x, long n)
 *         x in %rdi, n in %rsi
 *    1  0000000000400590 <switch_prob>:
 *    2  400590: 48 83 ee 3c              sub     $0x3c, %rsi
 *    3  400594: 48 83 fe 05              cmp     $0x5, %rsi
 *    4  400598: 77 29                    ja      4005c3 <switch_prob+0x33>
 *    5  40059a: ff 24 f5 f8 06 40 00     jmpq    *0x4006f8(,%rsi,8)
 *    6  4005a1: 48 8d 04 fd 00 00 00     lea     0x0(,%rdi,8), %rax
 *    7  4005a8: 00
 *    8  4005a9: c3                       retq
 *    9  4005aa: 4889f8                   mov     %rdi, %rax
 *    10 4005ad: 48 c1 f8 03              sar     $0x3, %rax
 *    11 4005b1: c3                       retq
 *    12 4005b2: 48 89 f8                 mov     %rdi, %rax
 *    13 4005b5: 48 c1 e0 04              shl     $0x4, %rax
 *    14 4005b9: 48 29 f8                 sub     %rdi, %rax
 *    15 4005bc: 48 89 c7                 mov     %rax, %rdi
 *    16 4005bf: 48 0f af ff              imul    %rdi, %rdi
 *    17 4005c3: 48 8d 47 4b              lea     0x4b(%rdi), %rax
 *    18 4005c7: c3                       retq
 */

long switch_prob(long x, long n) {
    long result = x;
    switch(n) {
        case 0:
        case 2:
            result = 8 * x;
            break;
        case 3:
            result = x >> 3;
            break;
        case 4:
            result = (x << 4) - x;
            break;
        case 5:
            x *= x;
            // fall through
        case 1:
        default:
            result = 0x4b + x;
    }
    return result;
}
