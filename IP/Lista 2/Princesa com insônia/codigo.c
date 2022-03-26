#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int k,i,m,n,d,dragoesofendidos=0;
    scanf(" %d %d %d %d %d",&k,&i,&m,&n,&d);


    for(int j = 1;j<=d;j++){
        if(j%k == 0||j%i == 0||j%m == 0||j%n == 0){
            dragoesofendidos += 1;
        };
    };

    printf("%d",dragoesofendidos);

	return 0;
}