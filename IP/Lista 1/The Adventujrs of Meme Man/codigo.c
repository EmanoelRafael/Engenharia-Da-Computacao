#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int qntlar,qntban,qntovo,qntleit,lar=0,ban=0,ovo=0,leit=0;

    scanf("%d %d %d %d",&qntlar,&qntban,&qntovo,&qntleit);

    if(qntlar<0||qntban<0||qntovo<0||qntleit<0){
        printf("lurn maf :(\n");
    }else{

        if(qntlar==0){lar = qntban*qntban;};

        if(lar){ban = 2;};

        if((ban+qntban)>qntovo){
            ovo = lar - qntovo;
            if(ovo<0){ovo=0;};
        };

        if(ovo){
            if(qntleit<2000){leit = 2000 - qntleit;};
        }else{leit = 500;};

        printf("%d laranjas\n%d bananas\n%d ovos\n%d mL de leite\n",lar,ban,ovo,leit);
    };

    
	return 0;
}