#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int i,j,tamanho1,tamanho2,qntdepontuacao1=0,qntdepontuacao2=0,tamanhoabsoluto1,tamanhoabsoluto2,ehanagrama=1;
    char frase1[500],frase2[500];

    scanf(" %[^\n]s",frase1);
    scanf(" %[^\n]s",frase2);

    tamanho1 = strlen(frase1);
    tamanho2 = strlen(frase2);

    for(i=0;i<tamanho1;i++){
        if((int)frase1[i]>64&&(int)frase1[i]<=90)frase1[i]=(char)(((int)frase1[i])+32);
        if(frase1[i]=='.'||frase1[i]=='?'||frase1[i]=='!'||frase1[i]==' '||frase1[i]==','){
                    frase1[i]=' ';
                    qntdepontuacao1++;
        };
    };

    for(i=0;i<tamanho2;i++){
        if((int)frase2[i]>64&&(int)frase2[i]<=90)frase2[i]=(char)(((int)frase2[i])+32);
        if(frase2[i]=='.'||frase2[i]=='?'||frase2[i]=='!'||frase2[i]==' '||frase2[i]==','){
                    frase2[i]=' ';
                    qntdepontuacao2++;
        };
    };

    tamanhoabsoluto1 = tamanho1 - qntdepontuacao1;
    tamanhoabsoluto2 = tamanho2 - qntdepontuacao2;

    if(tamanhoabsoluto1!=tamanhoabsoluto2){ehanagrama=0;
    }else{

        for(i=0;i<tamanho1;i++){
            if(frase1[i]!=' '){
                for(j=0;j<tamanho2;j++){
                    if(frase1[i]==frase2[j]){
                        frase2[j]=' ';
                        frase1[i]=' ';
                        j = tamanho2;};};
            };
        };

        for(i=0;i<tamanho1;i++){if(frase1[i]!=' ')ehanagrama=0;};
        for(i=0;i<tamanho2;i++){if(frase2[i]!=' ')ehanagrama=0;};
    };
    //printf("%s\n",frase1);
    //printf("%s\n",frase2);

    if(ehanagrama==1)printf("True");
    if(ehanagrama==0)printf("False");
    
	return 0;
}