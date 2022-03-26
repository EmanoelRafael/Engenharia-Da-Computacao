#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int dia,mes,ano,invalida=0;

    scanf("%d %d %d",&dia,&mes,&ano);

    if(mes<1||mes>12){
        printf("invalida");
        invalida = 1;
    };
    if(ano<1900||ano>2100){
        printf("invalida");
        invalida = 1;
    };
    if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
        if(dia<1||dia>31){
            printf("invalida");
            invalida = 1;
        };
    }else if(mes==4||mes==6||mes==9||mes==11){
        if(dia<1||dia>30){
            printf("invalida");
            invalida = 1;
        };
    }else if(mes==2){
        if(ano%4==0&ano!=1900&ano!=2100){
            if(dia<1||dia>29){
            printf("invalida");
            invalida = 1;
            };
        }else{
            if(dia<1||dia>28){
            printf("invalida");
            invalida = 1;
            };
        };
    };

    if(invalida==0){
        printf("valida");
    };

	return 0;
}