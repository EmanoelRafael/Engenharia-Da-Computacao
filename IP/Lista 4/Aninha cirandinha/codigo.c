#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int k,iteracoes;

    scanf("%d",&iteracoes);

    for(k=0;k<iteracoes;k++){

        int n,i,numeroanterior,verificadorhorario=1,verificadorantihorario=1;

        scanf("%d",&n);
        int elemento,posdoselementos[n],posicaodoelemento1,x;

        //preenche o vetor
        for(i = 0; i<n ; i++){
                scanf("%d",&elemento);
                posdoselementos[elemento-1] = i;
                if(elemento==1)posicaodoelemento1=i;
        };
        //verificar se funciona no sentido horario
        x = posicaodoelemento1;
        for(i = 0; verificadorhorario&&i<n ; i++){
                if(posdoselementos[i]!=x+i)verificadorhorario=0;
                if(x+i==n-1)x=-i-1;
        };

        //verificar se funciona no sentido antihorario
        x = posicaodoelemento1;
        for(i = 0; verificadorantihorario&&i<n ; i++){
                if(posdoselementos[i]!=x-i)verificadorantihorario=0;
                if(x-i==0)x=n+i;
        };

        if(verificadorhorario==1){
            printf("SIM, HORARIO\n");
        }else if(verificadorantihorario==1){
            printf("SIM, ANTI-HORARIO\n");
        }else{
            printf("NAO\n");
        };
    };

	return 0;
}