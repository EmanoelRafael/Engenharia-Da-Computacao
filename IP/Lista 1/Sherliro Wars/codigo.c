#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int propum = 0,propdois = 0;
    float dinheiro,precopropum,precopropdois,divida,conserto;


    scanf("%f %d %d %f %f %f",&dinheiro,&propum,&propdois,&precopropum,&precopropdois,&divida);

    conserto = propum*precopropum + propdois*precopropdois;

    if(propum&propdois){
        if (precopropum>precopropdois){
            conserto = precopropum*0.88 + precopropdois;
        };
        if (precopropdois>precopropum){
            conserto = precopropum + precopropdois*0.88;
        };
    };

    if(conserto+divida<=dinheiro){
        printf("Sherliro livre do Jabbavitz e podendo voar");
    }else if(conserto<=dinheiro||divida<=dinheiro){
        printf("Sherliro consertou mas ta lascado com o Jabbavitz\nfaltam %.2f Napoleocoins",divida-(dinheiro-conserto));
    }else if(divida>dinheiro&conserto>dinheiro){
        printf("Sherliro vai ser perseguido hoje e ainda ta sem nave\nfaltam %.2f Napoleocoins",(dinheiro-(conserto+divida))*-1);
    };
	return 0;
}