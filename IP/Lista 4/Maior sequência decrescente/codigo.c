#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int teste,k;
    scanf("%d",&teste);
    for(k=0;k<teste;k++){

        int n,i,iniciodaseqatual,iniciodamaiorseq,tamanhodaseqatual,tamanhodamaiorseq=0,numeroanterior,dentrodeumasequencia=0;

        scanf("%d",&n);
        int vetor[n];

        //preenche o vetor
        scanf("%d",&vetor[0]);
        numeroanterior = vetor[0];

        for(i = 1; i<n ; i++){
                scanf("%d",&vetor[i]);
                if(vetor[i]<numeroanterior&&dentrodeumasequencia==0){
                    dentrodeumasequencia = 1;
                    tamanhodaseqatual = 2;
                    iniciodaseqatual = i-1;
                    if(i==n-1&&tamanhodaseqatual>tamanhodamaiorseq){
                        tamanhodamaiorseq = tamanhodaseqatual;
                        iniciodamaiorseq = iniciodaseqatual;
                        };
                }else if(vetor[i]<numeroanterior&&dentrodeumasequencia==1){
                    tamanhodaseqatual ++;
                    if(i==n-1&&tamanhodaseqatual>tamanhodamaiorseq){
                        tamanhodamaiorseq = tamanhodaseqatual;
                        iniciodamaiorseq = iniciodaseqatual;
                        };
                }else if(vetor[i]>=numeroanterior&&dentrodeumasequencia==1){
                    dentrodeumasequencia = 0;
                    if(tamanhodaseqatual>tamanhodamaiorseq){
                        tamanhodamaiorseq = tamanhodaseqatual;
                        //fimdamaiorseq = i-1;
                        iniciodamaiorseq = iniciodaseqatual;
                    };
                    tamanhodaseqatual = 0;
                };
                numeroanterior = vetor[i];
        };
        //printf("%d\n%d\n",iniciodamaiorseq,tamanhodamaiorseq);
        printf("%d\n",tamanhodamaiorseq);
        for(i=iniciodamaiorseq;i<=iniciodamaiorseq+tamanhodamaiorseq-1;i++){
            printf("%d ",vetor[i]);
        };
        if(tamanhodamaiorseq>0)printf("\n");
    };

    
	return 0;
}