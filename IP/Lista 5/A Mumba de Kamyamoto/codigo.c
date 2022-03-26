#include <stdio.h>
#include <string.h>
//#include <math.h>
#include <stdlib.h>

typedef struct{
        int x;
        int y;
        int z;
        int id;
    }ponto;


int main() {



    int i,j,k,num=1,idmenordistancia,verificador,verificador2;
    float menor_distancia,distancia_atual;

    while(num>0){

        scanf("%d",&num);
        if(num>0){
            ponto conjunto[num],atual;

            //obtencao dos pontos
            for(i=0;i<num;i++){
                scanf("%d %d %d",&conjunto[i].x,&conjunto[i].y,&conjunto[i].z);
                conjunto[i].id = i;
            };

            //inicializacao da variavel ponto atual como a origem
            atual.x = 0;
            atual.y = 0;
            atual.z = 0;
            for(i=0;i<num;i++){
                menor_distancia = 0;
                verificador2 = 0;
                /*vai calcular a distancia da caixa atual ate as caixas que restam e comparar qual a menor delas
                uma vez escolhida a menor distancia, esse ponto vai ser colocado na variavel ponto atual
                e sua posicao (j+1) vai ser colocada no vetor da ordem dos ids, que armazena a ordem que as
                caixas serao obtidas.*/
                for(j=0;j<num;j++){
                
                    if(conjunto[j].id!=-1){
                        distancia_atual = (conjunto[j].x-atual.x)*(conjunto[j].x-atual.x)+(conjunto[j].y-atual.y)*(conjunto[j].y-atual.y)+(conjunto[j].z-atual.z)*(conjunto[j].z-atual.z);
                        if(verificador2 == 0){
                            menor_distancia = distancia_atual;
                            idmenordistancia = j;
                            verificador2 = 1;
                        }else if(distancia_atual<menor_distancia){
                            menor_distancia = distancia_atual;
                            idmenordistancia = j;
                        };

                    };
                };
                atual.x = conjunto[idmenordistancia].x;
                atual.y = conjunto[idmenordistancia].y;
                atual.z = conjunto[idmenordistancia].z;
                conjunto[idmenordistancia].id = -1;
                if(i<num-1){printf("%d ",idmenordistancia +1);
                }else if(i==num-1)printf("%d\n",idmenordistancia+1);
            };
        };
    };

	return 0;
}
