/* main.c simple program to test assembler program */

#include <stdio.h>

extern long long int test(char *string1, char *string2);

int main(void)
{
	char jogador1[] = "FLORESCER";
	char jogador2[] = "TELEVISAO";
	long long int a;

	a = test(jogador1,jogador2);
    printf(" %c\n", a);
    return 0;
}
