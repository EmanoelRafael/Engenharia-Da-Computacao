#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    typedef struct{
        int codigo;
        char descricao[51];
        float preco;
    }produto;

    int codigo_aux=1,quantidade,i,num;
    float preco_aux,valordacompra=0;

    scanf("%d",&num);
    produto produtos[num];

    for(i=0;i<num;i++){
        scanf("%d\n",&codigo_aux);
        produtos[i].codigo = codigo_aux;
        gets(produtos[i].descricao);
        scanf("%f\n",&preco_aux);
        produtos[i].preco = preco_aux;};

    while(codigo_aux!=0){
        scanf("%d",&codigo_aux);
        if(codigo_aux!=0){
            scanf("%d\n",&quantidade);
            if(quantidade>0){
                for(i=0;i<num;i++){
                    if(produtos[i].codigo==codigo_aux)valordacompra+=(quantidade*produtos[i].preco);
                    };};
        };
    };
    printf("%.2f",valordacompra);

    
	return 0;
}