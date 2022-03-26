#include <stdio.h>

extern long long int test(long long int a);

int main(void)
{
    long long int a = 0x0000fff00f00f0ff;
    long long int r;

    r = test(a);

    printf("Numero invertido: %x\n",r);
    return 0;
}
