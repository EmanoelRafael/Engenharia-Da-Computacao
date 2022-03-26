#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int pessoas,amigos, msc1, msc2, msc3, v1, v2, v3, verg1, verg2, verg3;
    float ideal;

    scanf("%d %d %d %d %d %d %d %d",&pessoas,&amigos,&msc1,&v1,&msc2,&v2,&msc3,&v3);

    ideal = sqrt(pessoas);

    if(ideal>amigos){
        printf("Não cantarei, desculpa.");
    }else{
        verg1 = pow(msc1,2)*v1;
        verg2 = pow(msc2,2)*v2;
        verg3 = pow(msc3,2)*v3;

        if(verg1>verg3&verg2>verg3){
            printf("Você deve cantar a música 3, boa sorte!");
        }else if(verg1>verg2&verg3>verg2){
            printf("Você deve cantar a música 2, boa sorte!");
        }else if(verg2>verg1&verg3>verg1){
            printf("Você deve cantar a música 1, boa sorte!");
        }else if(verg1==verg2&verg1<verg3){
            printf("Você deve cantar a música 1, boa sorte!");
        }else if(verg1==verg3&verg1<verg2){
            printf("Você deve cantar a música 1, boa sorte!");
        }else if(verg2==verg3&verg2<verg1){
            printf("Você deve cantar a música 2, boa sorte!");
        }else if(verg1==verg2&verg1==verg3){
            printf("Você deve cantar a música 1, boa sorte!");
        };
    };
	return 0;
}