#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    

    int casoteste=1,a,b;

    while(casoteste!=0){
        
        scanf("%d",&casoteste);
        if(casoteste!=0){
            a = casoteste/2;
            b = a+1;
    
            printf("%d - %d\n",b*b,a*a);};
    };

	return 0;
}