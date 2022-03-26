#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    

    int andares,andarespercorridos=0,capacidade,solicitacoes,qntdepessoas,entramnessavolta,i,vaidescer,verificador;

    scanf("%d %d %d",&andares,&capacidade,&solicitacoes);
    //scanf("%d",&solicitacoes);
    int vetor[solicitacoes][2];

    for(i=0;i<solicitacoes;i++){
        scanf("%d %d",&vetor[i][0],&vetor[i][1]);
    };

    do{
        verificador = 0;
        vaidescer = 1;
        qntdepessoas = 0;
        for(i=0;vaidescer&&i<solicitacoes;i++){

            if(qntdepessoas + vetor[i][1]>capacidade){
                entramnessavolta=(capacidade-qntdepessoas);
                qntdepessoas += entramnessavolta;
                vetor[i][1] -= entramnessavolta;
                vaidescer = 0;
                andarespercorridos += 2*vetor[i][0];

            }else if(qntdepessoas + vetor[i][1]<capacidade){
                qntdepessoas += vetor[i][1];
                vetor[i][1] = 0;
                if(i==solicitacoes-1)andarespercorridos+=2*vetor[i][0];
            }else{
                qntdepessoas += vetor[i][1];
                vetor[i][1] = 0;
                vaidescer = 0;
                andarespercorridos += 2*vetor[i][0];
            };
        };
        for(i=0;i<solicitacoes;i++){
            if(vetor[i][1]!=0){verificador=1;i=solicitacoes;};
        };

        /*printf("situacao apos a iteracao: %d\n",andarespercorridos);
        for(i=0;i<solicitacoes;i++){
            printf("%d %d\n",vetor[i][0],vetor[i][1]);
        };*/

    }while(verificador==1);

    printf("%d",andarespercorridos);

	return 0;
}