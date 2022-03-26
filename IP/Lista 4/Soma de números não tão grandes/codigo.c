#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n,i,j,numerodezeros,algarismo,tamanhodasoma;
    scanf("%d",&n);

    char entrada[22],partesignificativa[n][7],resultado[24],somaemstring[8];
    long int numerosconvertidos[n],num,soma=0,vaux1,vaux2;

    //recebimento dos dados, pasa cada entrada, sera adicionado no vetor das partes significativas os 6
    //primeiros digitos da entrada, se a entrada for um numero negativo, e os 5 primeiros se a entrada for um numero positivo.
    for(i=0;i<n;i++){
        scanf(" %s", entrada);
        for(j=0;j<6;j++){
                if(j==0){
                    if(entrada[j]=='-'){partesignificativa[i][j]='-';
                    }else{partesignificativa[i][j]='+';};
                }else{
                    if(entrada[0]=='-'){partesignificativa[i][j]=entrada[j];
                    }else{partesignificativa[i][j]=entrada[j-1];};
                };
        };
    };

    //conversao da variavel em char para uma variavel long int para cada entrada
    for(i=0;i<n;i++){
        vaux1 = 10000;
        num = 0;
        for(j=1;j<6;j++){
            num += (((int)partesignificativa[i][j]) - 48)*vaux1;
            vaux1 /= 10;
        };
        numerosconvertidos[i] = num;
    };

    //acumulacao da soma, para isso eh verificado o sinal de cada entrada, e a soma eh realizada.
    for(i=0;i<n;i++){
        if(partesignificativa[i][0]=='+'){soma+=numerosconvertidos[i];
        }else if(partesignificativa[i][0]=='-')soma-=numerosconvertidos[i];
    };

    //a quantidade de zeros na entrada eh obtido pelo tamanho da entrada menos a quantidade de algarismos
    //significativos - 5 (mais o sinal no caso de numero negativo - 6)
    numerodezeros = (entrada[0]=='-')?(strlen(entrada)-6):(strlen(entrada)-5);

    //para transformar a soma de inteiro para char eh pegado caractere por caractere e colocado em uma string
    i=0;
    vaux2 = soma;
    while(soma!=0){
            algarismo = soma%10;
            if(algarismo<0)algarismo*=-1;
            somaemstring[i] = (char)(algarismo+48);
            soma /= 10;
            i++;
        };
    tamanhodasoma = strlen(somaemstring);
    //if(vaux2==0)tamanhodasoma=0;

    //o resultado vai depender se a soma foi negativa ou nao, para cada caso, a string resultado sera composta pelo
    //(sinal se for negativa, mais) os algarismos da soma, mais a quantidade de zeros da entrada.
    if(vaux2<0){
        resultado[0] = '-';

        for(i=1;i<=tamanhodasoma;i++){
            resultado[i] = somaemstring[tamanhodasoma-i];};
        for(i=tamanhodasoma+1;i<(numerodezeros+tamanhodasoma+1);i++){
            resultado[i] = '0';};
    }else{
        for(i=0;i<tamanhodasoma;i++){
            resultado[i] = somaemstring[tamanhodasoma-1-i];
        };
        for(i=tamanhodasoma;i<(numerodezeros+tamanhodasoma);i++){
            resultado[i] = '0';
        };
    };

    //impressao do resultado.
    if(vaux2!=0){
        printf("%s\n",resultado);
    }else{printf("%d\n",0);};
    
	return 0;
}