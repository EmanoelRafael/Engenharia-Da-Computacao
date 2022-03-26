/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int test(long long int n);

int main(void)
{
	long long int n = 5;
	long long int res;

	res = test(n);
    printf("Pontuacao: %lld\n", res);
    return 0;
}
