#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    typedef struct{
        char cor[10];
        char tamanho[2];
        char nomealuno[100]
    }camiseta;

    int i,num=1,j,k,troca=0;
    char tamanho_aux[2],cor_aux[10],tamanho_temp[2],cor_temp[10],nomealuno_temp[100];

    while(num>0){

        scanf("%d\n",&num);
        if(num>0){
            camiseta camisetas[num];

            for(i=0;i<num;i++){
                gets(camisetas[i].nomealuno);
                scanf("%s %s\n",cor_aux,tamanho_aux);
                strcpy(camisetas[i].cor,cor_aux);
                strcpy(camisetas[i].tamanho,tamanho_aux);
                };

            for(i=0;i<num;i++){
                    troca = 0;
                for(j=i+1;(troca==0)&&j<num;j++){
                    if(strcmp(camisetas[i].cor,camisetas[j].cor)!=0&&strcmp(camisetas[i].cor,"vermelho")==0){
                        troca = 1;
                        strcpy(cor_temp,camisetas[i].cor);
                        strcpy(tamanho_temp,camisetas[i].tamanho);
                        strcpy(nomealuno_temp,camisetas[i].nomealuno);
                        strcpy(camisetas[i].cor,camisetas[j].cor);
                        strcpy(camisetas[i].tamanho,camisetas[j].tamanho);
                        strcpy(camisetas[i].nomealuno,camisetas[j].nomealuno);
                        strcpy(camisetas[j].cor,cor_temp);
                        strcpy(camisetas[j].tamanho,tamanho_temp);
                        strcpy(camisetas[j].nomealuno,nomealuno_temp);
                    };
                };
            };

            for(i=0;i<num;i++){
                for(j=i+1;j<num;j++){
                    troca = 0;
                    if(strcmp(camisetas[i].cor,camisetas[j].cor)==0){
                        if(strcmp(camisetas[i].tamanho,camisetas[j].tamanho)!=0){
                            if(strcmp(camisetas[i].tamanho,"G")==0){troca=1;
                            }else if(strcmp(camisetas[i].tamanho,"M")==0&&strcmp(camisetas[j].tamanho,"P")==0)troca=1;
                        };
                        if(troca==1){
                            strcpy(cor_temp,camisetas[i].cor);
                            strcpy(tamanho_temp,camisetas[i].tamanho);
                            strcpy(nomealuno_temp,camisetas[i].nomealuno);
                            strcpy(camisetas[i].cor,camisetas[j].cor);
                            strcpy(camisetas[i].tamanho,camisetas[j].tamanho);
                            strcpy(camisetas[i].nomealuno,camisetas[j].nomealuno);
                            strcpy(camisetas[j].cor,cor_temp);
                            strcpy(camisetas[j].tamanho,tamanho_temp);
                            strcpy(camisetas[j].nomealuno,nomealuno_temp);
                        };
                    };
                };
            };

            for(i=0;i<num;i++){
                for(j=i+1;j<num;j++){
                    if(strcmp(camisetas[i].cor,camisetas[j].cor)==0&&strcmp(camisetas[i].tamanho,camisetas[j].tamanho)==0){
                        troca = 0;
                        for(k=0;(troca==0)&&k<strlen(camisetas[i].nomealuno);k++){
                            if((int)camisetas[i].nomealuno[k]<(int)camisetas[j].nomealuno[k]){troca = 2;
                            }else if((int)camisetas[i].nomealuno[k]>(int)camisetas[j].nomealuno[k])troca = 1;
                        };
                        if(troca==1){
                            strcpy(cor_temp,camisetas[i].cor);
                            strcpy(tamanho_temp,camisetas[i].tamanho);
                            strcpy(nomealuno_temp,camisetas[i].nomealuno);
                            strcpy(camisetas[i].cor,camisetas[j].cor);
                            strcpy(camisetas[i].tamanho,camisetas[j].tamanho);
                            strcpy(camisetas[i].nomealuno,camisetas[j].nomealuno);
                            strcpy(camisetas[j].cor,cor_temp);
                            strcpy(camisetas[j].tamanho,tamanho_temp);
                            strcpy(camisetas[j].nomealuno,nomealuno_temp);
                        };
                    };
                };
            };

            for(i=0;i<num;i++){printf("%s %s %s\n",camisetas[i].cor,camisetas[i].tamanho,camisetas[i].nomealuno);};};
            printf("\n");
    };

    
	return 0;
}