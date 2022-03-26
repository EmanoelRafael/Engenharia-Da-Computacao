#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    typedef struct{
        int passagem;
        char data[15];
        char origem[100];
        char destino [100];
        char horario[6];
        int poltrona;
        int idade;
        char nome[100];

    }dadosdopassageiro;

    dadosdopassageiro dados[44];
    int passagem_aux,poltrona_aux,idade_aux,i=0,j,soma=0;
    float media;

    do{
        scanf("%d\n",&passagem_aux);
        if(passagem_aux!=-1){
            dados[i].passagem = passagem_aux;
            gets(dados[i].data);
            gets(dados[i].origem);
            gets(dados[i].destino);
            gets(dados[i].horario);
            scanf("%d\n",&poltrona_aux);
            dados[i].poltrona = poltrona_aux;
            scanf("%d\n",&idade_aux);
            dados[i].idade = idade_aux;
            gets(dados[i].nome);

            soma += idade_aux;
            i++;};

        //printf("%d\n",passagem_aux);
    }while(passagem_aux!=-1);

    //for(j=0;j<i;j++){
    //    printf("passagem %d\ndata %s\norigem %s\ndestino %s\nhorario %s\npoltrona %d\nidade %d\nnome %s\n",dados[j].passagem,dados[j].data,dados[j].origem,dados[j].destino,dados[j].horario,dados[j].poltrona,dados[j].idade,dados[j].nome);
    //};

    media = (soma+0.0)/i;
    //printf("%d e %f\n",i,media);
    for(j=0;j<i;j++){
        if(dados[j].idade>media&&dados[j].poltrona%2==0)printf("%s\n",dados[j].nome);
    };
    
	return 0;
}