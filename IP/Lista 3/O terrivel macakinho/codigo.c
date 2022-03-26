#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n,num,i,primoanterior = 3,encontrou,ehprimo,primoatual;
    double soma;
    scanf("%d",&n);

    //enquanto a soma nao tiver n termos, o ciclo continuara
    while(n>0){

        //primeiro passo e encontrar o primo sucessor do primo anterior, ele sera armazenado na variavel primo atual
        ehprimo = 0;
        num = primoanterior;
        //enquanto nao for encontrado o primo, a variavel ehprimo sera zero
        while(ehprimo==0){

        ehprimo = 1;
        num = num+2;

        for(i=2;i*2<=num;i++){if(num%i==0)ehprimo=0;};

        if(ehprimo==1)primoatual=num;

        };

        //depois de encontrar o primo sucessor, deve ser verificado se o primo atual e o primo anterior sao primos gemeos
        //se forem gemeos, a soma sera adicionada do termo correto, e a quantidade de termos n sera diminuida
        if(primoatual-primoanterior==2){

            soma += ((1.0/primoanterior) + (1.0/primoatual));
            n--;

        };

        //apois a atulizacao do primo atual, ele sera o primo anterior da proxima iteracao
        primoanterior = primoatual;


    };

    printf("%.10lf",soma);

    
	return 0;
}