#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int i,j,tamanho,ehpalindromo=1;
    char frase[100];

    scanf(" %s",frase);

    //printf("%s\n",frase);

    tamanho = strlen(frase);
    char frasecontraria[tamanho];
    //printf("%d\n",tamanho);

    for(i=0,j=tamanho-1;i<tamanho;i++,j--){
        frasecontraria[j]=frase[i];
    };
    //printf("%s %s",frase,frasecontraria);
    for(i=0;i<tamanho;i++){
        if(frase[i]!=frasecontraria[i])ehpalindromo=0;
    };
    if(ehpalindromo==1)printf("S");
    if(ehpalindromo==0)printf("N");

	return 0;
}