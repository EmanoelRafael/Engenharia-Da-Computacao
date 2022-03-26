#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int numero,contador,frequencia = 0,divisormaisfrequente=1;

    scanf(" %d",&numero);

    for(int i = 2;i<=numero;i++){
        contador = 0;
        while(numero%i==0){
            contador += 1;
            numero = numero/i;
        };
        if(contador==frequencia){
           if(i<divisormaisfrequente){
                divisormaisfrequente = i;
           };
        }else if(contador>frequencia){
            frequencia = contador;
            divisormaisfrequente = i;
        };
    };

    printf("mostFrequent: %d, frequency: %d",divisormaisfrequente,frequencia);

	return 0;
}