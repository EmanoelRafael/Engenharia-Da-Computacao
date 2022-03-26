#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int saques,manjus,yakitoris,pessoas,copos;

    scanf("%d %d %d %d",&saques,&manjus,&yakitoris,&pessoas);

    if(pessoas < 4){
        printf("Ta faltando gente ai ein!\n");
    }else{
        //como cada saques tem 675ml o que corresponde a 15 copinhos de 45ml:
        copos = saques*15;

        if(copos >= pessoas*4 & manjus >= pessoas*5 & yakitoris >= pessoas*3){

            printf("Partiu Festa do Japa!");

        }else if(copos < pessoas*4 & manjus < pessoas*5 & yakitoris < pessoas*3){

            printf("Partiu Festa do Japa...Japacama");

        }else if(copos < pessoas*4 & manjus < pessoas*5 & yakitoris >= pessoas*3){

            printf("Faltaram %d saques e %d manjus",pessoas*4-copos,pessoas*5 - manjus);

        }else if(copos < pessoas*4 & manjus >= pessoas*5 & yakitoris < pessoas*3){

            printf("Faltaram %d saques e %d yakitoris",pessoas*4-copos,pessoas*3 - yakitoris);

        }else if(copos >= pessoas*4 & manjus < pessoas*5 & yakitoris < pessoas*3){

            printf("Faltaram %d manjus e %d yakitoris",pessoas*5 - manjus,pessoas*3 - yakitoris);

        }else if(copos < pessoas*4 & manjus >= pessoas*5 & yakitoris >= pessoas*3){

            printf("Faltaram %d saques",pessoas*4-copos);

        }else if(copos >= pessoas*4 & manjus < pessoas*5 & yakitoris >= pessoas*3){

            printf("Faltaram %d manjus",pessoas*5 - manjus);

        }else if(copos >= pessoas*4 & manjus >= pessoas*5 & yakitoris < pessoas*3){

            printf("Faltaram %d yakitoris",pessoas*3 - yakitoris);

        };
    };
    
	return 0;
}