/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int test(char *conj, char *palavra);

int main(void)
{
	char conjuto[] = "grnrclszemskvbgcluwtgyvieip";
	char palavra[] = "leg";
	long long int m = 0;

	m = test(conjuto,palavra);
    printf("A palavra pode ser formada %lld vezes\n", m);
    return 0;
}
