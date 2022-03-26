#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
        char nome[101];
        char sexo;
        char nascimento[12]
    }morador;

typedef struct{
        morador moradoresapt[4];
        int qntdemoradores;
    }apartamento;

typedef struct{
        apartamento apartamentos[2];
    }andar;

typedef struct{
        andar andares[20];
    }edificio;

typedef struct{
        morador moradorescasa[4];
        int qntdemoradores;
    }casa;

typedef struct{
        char nome[50];
        casa casas[50];
        edificio edificios[10];
    }logradouro;


int main()
{
    logradouro ruas[5];
    int operacao,i,j,k,l,i_rua,n_casa,n_edificio,n_andar,n_apt,qntdemoradores,instancias;
    char nomedarua[50],caracterdeidentificacao,nomedomorador[101],sexo,nascimento[12];
    for(i=0;i<5;i++){
        strcpy(ruas[i].nome," ");
    };
    //inicializa como 0 a variavel quantidade de moradores em todas as casas e apartamento de todas as ruas.
    for(i=0;i<5;i++){
        for(j=0;j<50;j++){
            ruas[i].casas[j].qntdemoradores =0;
        };
    };
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            for(k=0;k<20;k++){
                for(l=0;l<2;l++){
                    ruas[i].edificios[j].andares[k].apartamentos[l].qntdemoradores=0;
                };
            };
        };
    };

    do{
        scanf("%d\n", &operacao);
        while(operacao!=1&&operacao!=2&&operacao!=3){
            printf("Opcao invalida. Por favor, digite uma opcao valida.\n");
            scanf("%d\n", &operacao);
        };
        if(operacao==1){
            i_rua = 5;
            //obtencao do nome da rua
            gets(nomedarua);
            //verificacao se o nome da rua ja esta registrado
            for(i=0;i<5;i++){
                if(strcmp(nomedarua,ruas[i].nome)==0)i_rua=i;
            };
            //se o nome nao estiver registrado, ele vai ser registrado na primeira rua com nome vazio
            if(i_rua==5){
                for(i=0;i<5;i++){
                    if(strcmp(ruas[i].nome," ")==0){
                            i_rua=i;
                            strcpy(ruas[i].nome,nomedarua);
                            i = 5;
                    };
                };
            };
            //obtido o nome da rua, agora se obtem o caracter de identificacao
            scanf("%c ",&caracterdeidentificacao);
            //dado o caracter obtido, eh hora de se obter as informacoes do endereco e do morador
            //apos a obtencao, os dados do morador sao colocados no endereco correspondente
            if(caracterdeidentificacao == 'c'){
                scanf("%d\n",&n_casa);
                gets(nomedomorador);
                scanf("%c %s\n",&sexo,nascimento);
                qntdemoradores = ruas[i_rua].casas[n_casa-1].qntdemoradores;
                if(qntdemoradores<4){
                    strcpy(ruas[i_rua].casas[n_casa-1].moradorescasa[qntdemoradores].nome,nomedomorador);
                    ruas[i_rua].casas[n_casa-1].moradorescasa[qntdemoradores].sexo = sexo;
                    strcpy(ruas[i_rua].casas[n_casa-1].moradorescasa[qntdemoradores].nascimento,nascimento);
                    ruas[i_rua].casas[n_casa-1].qntdemoradores += 1;
                };


            }else if(caracterdeidentificacao == 'e'){
                scanf("%d %d %d\n",&n_edificio,&n_andar,&n_apt);
                gets(nomedomorador);
                scanf("%c %s\n",&sexo,nascimento);
                qntdemoradores = ruas[i_rua].edificios[n_edificio-1].andares[n_andar-1].apartamentos[n_apt-1].qntdemoradores;
                if(qntdemoradores<4){
                    strcpy(ruas[i_rua].edificios[n_edificio-1].andares[n_andar-1].apartamentos[n_apt-1].moradoresapt[qntdemoradores].nome,nomedomorador);
                    ruas[i_rua].edificios[n_edificio-1].andares[n_andar-1].apartamentos[n_apt-1].moradoresapt[qntdemoradores].sexo = sexo;
                    strcpy(ruas[i_rua].edificios[n_edificio-1].andares[n_andar-1].apartamentos[n_apt-1].moradoresapt[qntdemoradores].nascimento,nascimento);
                    ruas[i_rua].edificios[n_edificio-1].andares[n_andar-1].apartamentos[n_apt-1].qntdemoradores += 1;
                };
            }

            scanf("[^\n]");
        }else if(operacao==2){
            gets(nomedomorador);
            gets(nomedarua);
            instancias = 0;
            i_rua = 5;
            for(i=0;i<5;i++){
                //possivel problema se existirem duas ruas com nomes iguais, mas suponha-se que nao existem
                if(strcmp(nomedarua,ruas[i].nome)==0)i_rua=i;
            };
            if(i_rua<5){
                for(i=0;i<50;i++){
                    for(j=0;j<4;j++){
                        if(strcmp(ruas[i_rua].casas[i].moradorescasa[j].nome,nomedomorador)==0){
                            printf("Casa: %d | Sexo: %c | Nascimento: %s\n",i+1,ruas[i_rua].casas[i].moradorescasa[j].sexo,ruas[i_rua].casas[i].moradorescasa[j].nascimento);
                            instancias += 1;
                        };
                    };
                };
                for(i=0;i<10;i++){
                    for(j=0;j<20;j++){
                        for(k=0;k<2;k++){
                            for(l=0;l<4;l++){
                                if(strcmp(ruas[i_rua].edificios[i].andares[j].apartamentos[k].moradoresapt[l].nome,nomedomorador)==0){
                                    printf("Edificio: %d | Andar: %d | Numero do apt.: %d | Sexo: %c | Nascimento: %s\n",i+1,j+1,k+1,ruas[i_rua].edificios[i].andares[j].apartamentos[k].moradoresapt[l].sexo,ruas[i_rua].edificios[i].andares[j].apartamentos[k].moradoresapt[l].nascimento);
                                    instancias += 1;
                                };
                            };
                        };
                    };
                };

                if(instancias>0)printf("Foram encontradas %d instancias de pessoas chamadas \"%s\" em \"%s\", relatadas acima.\n",instancias,nomedomorador,nomedarua);
            };
            if(instancias==0)printf("Sem dados de \"%s\" em \"%s\"!\n",nomedomorador,nomedarua);

            scanf("[^\n]");
        }else if(operacao==3)printf("O programa sera fechado, obrigado por fazer uso dele. Lembre-se de evitar a fadiga!\n");

    }while(operacao!=3);

    return 0;
}