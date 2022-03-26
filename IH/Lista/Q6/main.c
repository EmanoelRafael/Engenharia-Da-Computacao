/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int test(char* string);

int main(void)
{
	long long int n;
	char frase[] = "ola, primeiro teste";

	n = test(frase);
    printf("Quantidade de vogais:  %lld\n", n);
    return 0;
}
