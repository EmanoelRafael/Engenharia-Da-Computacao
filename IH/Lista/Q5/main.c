#include <stdio.h>

extern long long int test(long long int n, long long int a);

int main(void)
{
	long long int n = 5;
    long long int a = 6;

	n = test(n,a);
    printf("Quantidade de execucoes do loop teste = %lld\n", n);
    return 0;
}
