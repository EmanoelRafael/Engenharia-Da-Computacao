#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int dinheiro,pverde,pvermelho,proxo,pamarelo,escolhido=0;
    float cstbenef;

    scanf("%d %d %d %d %d",&dinheiro,&pverde,&pvermelho,&proxo,&pamarelo);

    cstbenef = 80.0/pverde;
    if(dinheiro>pverde){
        escolhido = 1;
    };

    if(cstbenef<(100.0/pvermelho)&dinheiro>pvermelho){
        cstbenef = 100.0/pvermelho;
        escolhido = 2;
    };
    if(cstbenef<(120.0/proxo)&dinheiro>proxo){
        cstbenef = 120.0/proxo;
        escolhido = 3;
    };
    if(cstbenef<(80.0/pamarelo)&dinheiro>pamarelo){
        cstbenef = 80.0/pamarelo;
        escolhido = 4;
    };

    switch(escolhido){
        case 0:
            printf("Acho que vou a pe :(");
            break;
        case 1:
            printf("Verde");
            break;
        case 2:
            printf("Vermelho");
            break;
        case 3:
            printf("Roxo");
            break;
        case 4:
            printf("Amarelo");
            break;
    };

	return 0;
}