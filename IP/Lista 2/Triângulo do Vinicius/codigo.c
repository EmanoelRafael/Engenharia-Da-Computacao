#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char letra;
    int numerodaletra,tamanhodabase;

    scanf("%c",&letra);

    numerodaletra = ((int) letra) - 64;
    tamanhodabase = (numerodaletra - 1)*2 +1;

    for(int i=1;i<=numerodaletra;i++){

        for(int j = 1; j<=((tamanhodabase-((i - 1)*2 +1))/2) ;j++){printf(".");};

        for(int j = 1; j<=i ;j++){printf("%c",j+64);};

        for(int j = i-1; j>=1 ;j--){printf("%c",j+64);};

        for(int j = 1; j<=((tamanhodabase-((i - 1)*2 +1))/2) ;j++){printf(".");};

        printf("\n");

    };

	return 0;
}