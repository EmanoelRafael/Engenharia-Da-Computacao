/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int test(long long int a, long long int b);

int main(void)
{
    long long int a = 0x0000ffff0000ffff;
    long long int b = 0xffff0000ffff0000;

	b = test(a, b);

    printf("X13 = %x\n",b);
    
    return 0;
}
