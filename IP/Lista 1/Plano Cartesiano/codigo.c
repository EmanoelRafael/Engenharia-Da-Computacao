#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int x,y;

    scanf("%d %d",&x,&y);

    if(x==0&y==0){
        printf("Sobre a origem");
    }else if(x==0&y!=0){
        printf("Sobre o eixo y");
    }else if(x!=0&y==0){
        printf("Sobre o eixo x");
    }else if(x>0&y>0){
        printf("Primeiro Quadrante");
    }else if(x<0&y>0){
        printf("Segundo Quadrante");
    }else if(x<0&y<0){
        printf("Terceiro Quadrante");
    }else if(x>0&y<0){
        printf("Quarto Quadrante");
    };
    
	return 0;
}