#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char corte;
    int lin,col,i,j;

    scanf(" %c %d %d",&corte,&lin,&col);

    int matriz[lin][col],novamatriz[lin][col];

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            scanf("%d",&matriz[i][j]);
        };
    };

    if(corte=='H'){
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                if(i<lin/2)novamatriz[i][j]=matriz[i][j];
                if(i>=lin/2)novamatriz[i][j]=matriz[i][col-1-j];
            };
        };
    }else{
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                if(j<col/2)novamatriz[i][j]=matriz[i][j];
                if(j>=col/2)novamatriz[i][j]=matriz[lin-1-i][j];
            };
        };
    };

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%02d ",novamatriz[i][j]);
        };
        printf("\n");
    };

    
	return 0;
}