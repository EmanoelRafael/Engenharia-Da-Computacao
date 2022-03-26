/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int test(long long int m, long long int a, long long int b);

int main(void)
{
	long long int a = 5;
	long long int b = 9;
	long long int m = 0;

	m = test(m,a,b);
    printf("Resultado com a = %lld e b = %lld: m = %lld\n", a, b, m);
    return 0;
}
