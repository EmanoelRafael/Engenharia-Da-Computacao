#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int a,b,antecessor=0,sucessor=0,num,i,j,k,ehprimo,n=0,primodezeca=0,contagem=0;
    double somatorio;
    scanf("%d %d",&a,&b);

//para cada elemento do intervalo deve-se verificar se ele eh primo
    for(i=a;i<=b;i++){

        ehprimo = 1;
        for(j=2;j*2<=i;j++){if(i%j==0)ehprimo = 0;};


        if(ehprimo==1){
            contagem++;

            if(contagem==1){
//se i for o primeiro primo do intervalo [A,B] entao o seu antecessor sera anterior a A.
                
                for(j=a-1;j>1;j--){
                    ehprimo = 1;
                    for(k=2;k*2<=j;k++){if(j%k==0)ehprimo = 0;};
                    if(ehprimo==1){
                        antecessor = j;
                        primodezeca = i;
                        j = 1;
                    };
                };

            }else {
//se i nao for o primeiro primo do intervalo entao ele e o sucessor do i anterior(que esta armazenado na variavel primodezeca)
//apos a verificacao do i anterior(primodezeca), as variaveis sao atalizadas, naproxima iteracao  o primo atual(i) sera o
//primodezeca, seu antecessor sera o primo que se encontra armazenado na variavel primodezeca atual e seu sucessor sera o primo(i)
//da proxima iteracao.

                sucessor = i;
                if((antecessor+sucessor+0.0)/2==primodezeca)n++;
                antecessor = primodezeca;
                primodezeca = i;

            };
        };

    };

//uma vez fora do intervalo, para verificar se o ultimo primo eh um primo de zeca, deve-se achar o primeiro primo maior que b
//esse sera o sucessor do ultimo primo no intervalo
    i = b+1;
    contagem = 0;
    do{
        ehprimo = 1;
        for(k=2;k*2<=i;k++){if(i%k==0)ehprimo = 0;};

        if(ehprimo==1){
            contagem = 1;
            sucessor = i;
            if((antecessor+sucessor+0.0)/2==primodezeca)n++;
        };

        i++;


    }while(contagem==0);

    printf("%d",n);

    
	return 0;
}