#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int numeroderodadas,cartaequipe1,cartaequipe2,pontuacaoequipe1=0,pontuacaoequipe2=0,soma,numerodedivisores,diferenca;

    scanf("%d",&numeroderodadas);

    //obtem a pontuacao de cada equipe, a cada ciclo incrementa a pontuacao se a equipe pontuou.
    while(numeroderodadas>0){
        scanf("%d %d",&cartaequipe1,&cartaequipe2);

        soma = 0;
        //obtem a soma dos digitos do numero da carta
        for(int i = cartaequipe1;i!=0;i /= 10){
            soma += i%10;
        };

        numerodedivisores = 0;
        //verifica o numero de divisores da soma dos digitos da carta
        for(int i = 1; i <= soma;i++){
            if(soma%i==0){numerodedivisores += 1;};
        };

        //veerifica se a equipe pontuou ou nao
        if(numerodedivisores%2==0){pontuacaoequipe1 += 1;};

        soma = 0;
        //repete o precesso para a equipe 2
        for(int i = cartaequipe2;i!=0;i /= 10){
            soma += i%10;
        };

        numerodedivisores = 0;
        for(int i = 1; i <= soma;i++){
            if(soma%i==0){numerodedivisores += 1;};
        };

        if(numerodedivisores%2==0){pontuacaoequipe2 += 1;};

        //decementa o numero de rodadas
        numeroderodadas--;
    };

    soma = 0;
    //obtem a soma dos digitos da pontuacao da equipe 1
    for(int i = pontuacaoequipe1;i!=0;i /= 10){
        soma += i%10;
    };

    numerodedivisores = 0;
    //obtem o numero de divisores da soma dos digitos da pontuacao da equipe 1
    for(int i = 1; i <= soma;i++){
        if(soma%i==0){numerodedivisores += 1;};
    };

    //verifica a pontuacao final da equipe 1
    if(soma==2){pontuacaoequipe1 -= 4;
    }else if(numerodedivisores==2){pontuacaoequipe1+=3;};



    soma = 0;
    //repete o processo para a equipe 2
    for(int i = pontuacaoequipe2;i!=0;i /= 10){
        soma += i%10;
    };

    numerodedivisores = 0;
    for(int i = 1; i <= soma;i++){
        if(soma%i==0){numerodedivisores += 1;};
    };

    if(soma==2){pontuacaoequipe2 -= 4;
    }else if(numerodedivisores==2){pontuacaoequipe2+=3;};

    //obtidas as duas pontuacoes, agora se obtem a diferenca entre as duas
    if(pontuacaoequipe1==pontuacaoequipe2){diferenca=1;
    }else{
        if(pontuacaoequipe1>pontuacaoequipe2){diferenca=pontuacaoequipe1-pontuacaoequipe2;
        }else{diferenca=pontuacaoequipe2-pontuacaoequipe1;};
    };

    //impressao do resultado.
    printf("Quem ganhou foi aquele time.\n");
    printf("%d",diferenca);


	return 0;
}