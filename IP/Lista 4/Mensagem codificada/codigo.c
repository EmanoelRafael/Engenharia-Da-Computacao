#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int i,tamanho,verificadordeponto=1;
    char frase[500];

    scanf("%[^\n]s",frase);

    tamanho = strlen(frase);

    for(i=0;i<tamanho;i++){
        //printf("%c %c\n",frase[i],letraasertrocada);
        if(frase[i]=='.')verificadordeponto=1;

        if(verificadordeponto==1){
            if(frase[i]=='4'){frase[i]='A';
            }else if(frase[i]=='5'){frase[i]='E';
            }else if(frase[i]=='1'){frase[i]='I';
            }else if(frase[i]=='0'){frase[i]='O';
            }else if(frase[i]=='2'){frase[i]='U';
            }else if(((int)frase[i])>96&&((int)frase[i])<123)frase[i]=(char)((int)frase[i]-32);
        }else if(verificadordeponto==0){
            if(frase[i]=='4'){frase[i]='a';
            }else if(frase[i]=='5'){frase[i]='e';
            }else if(frase[i]=='1'){frase[i]='i';
            }else if(frase[i]=='0'){frase[i]='o';
            }else if(frase[i]=='2')frase[i]='u';
        };

        if(verificadordeponto==1&&frase[i]!='.'&&frase[i]!=' ')verificadordeponto = 0;
    };

    printf("%s\n",frase);

    
	return 0;
}