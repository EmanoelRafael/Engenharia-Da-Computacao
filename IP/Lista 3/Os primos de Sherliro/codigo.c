#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int funcionou = 0,iteracao = 0,teto,contador;
    long long sinal,entrada1,entrada2,entrada3,num,i;
    double somatorio;
    scanf("%lld %lld %lld",&entrada1,&entrada2,&entrada3);

    do{
        iteracao++;
        //verifica qual sinal vai ser analisado
        if(iteracao==1)sinal=entrada1;
        else if(iteracao==2)sinal=entrada2;
        else if(iteracao==3)sinal=entrada3;

        //faz a fatoracao do sinal e o somatorio de acordo com as normas
        contador = 1;
        num = sinal;
        somatorio = 0;

        for(i=2;i*2<=sinal;i++){
            while(num%i==0){
                somatorio += (i+0.0)/contador;
                contador++;
                num /= i;
            };
            if(num==1)i=sinal/2;
        };
        //if(somatorio == 0)somatorio = sinal/1;

        //verifica se o somatorio tem parte decimal e arredonda pra cima caso tenha(obtendo o teto do somatorio)
        teto = (int) somatorio;
        if(somatorio>teto){
            teto++;
        };

        //verifica se o teto eh numero primo
        contador = 0;

        for(i=2;i*2<=teto;i++){
            if(teto%i==0)contador=1;
            if(contador==1)i=teto/2;
        };


        //verifica se o teto do somatorio eh primo e imprime a mensagem correspondente
        if(contador == 0){
            printf("SHERLIRO SALVOU MULITTLE\n");
            funcionou = 1;
        }else{printf("ERRO\n");};

    }while(funcionou == 0 && iteracao < 3);

    if(iteracao<3){
            for(i=3;i>iteracao;i--){
                printf("SINAL OFF\n");
            };
    };


    
	return 0;
}