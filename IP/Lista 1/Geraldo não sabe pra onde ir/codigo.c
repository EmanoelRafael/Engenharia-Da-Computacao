#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    double dinheiro,x,y,a,b,c,d,gas1,ped1,gas2,ped2,custo1,custo2;

    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&dinheiro,&x,&y,&a,&b,&c,&d,&gas1,&ped1,&gas2,&ped2);

    custo1 = (sqrt(pow(a-x,2)+pow(b-y,2))/12)*gas1*2 + ped1;
    custo2 = (sqrt(pow(c-x,2)+pow(d-y,2))/12)*gas2*2 + ped2;
    //printf("%.2f %.2f", custo1,custo2);
    if(dinheiro>=custo1+custo2){
        printf("Ele vai visitar os dois lugares\n%.2f",custo1+custo2);
    }else if(custo1 == custo2&dinheiro>=custo1){
        printf("Tanto faz...\n%.2f",custo1);
    }else if(dinheiro>=custo1&custo1<custo2){
        printf("Ele vai para o destino 1\n%.2f",custo1);
    }else if(dinheiro>=custo2&custo2<custo1){
        printf("Ele vai para o destino 2\n%.2f",custo2);
    }else{
        printf("Ele vai ficar em casa\n-1");
    };
    
	return 0;
}