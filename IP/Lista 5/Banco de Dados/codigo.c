#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    typedef struct{
        int idade;
        char nome[51];
        char sexo[2];
        char estadocivil[2];
        int numdeamigos;
        int numdefotos;

    }dadosdousuario;

    int idade_aux,numdeamigos_aux,numdefotos_aux,i,j,num;

    scanf("%d",&num);
    dadosdousuario dados[num];

    for(i=0;i<num;i++){
        scanf("%d\n",&idade_aux);
        dados[i].idade = idade_aux;
        gets(dados[i].nome);
        gets(dados[i].sexo);
        gets(dados[i].estadocivil);
        scanf("%d\n",&numdeamigos_aux);
        dados[i].numdeamigos = numdeamigos_aux;
        scanf("%d\n",&numdefotos_aux);
        dados[i].numdefotos = numdefotos_aux;};



    for(i=0;i<num;i++){
        printf("Idade: %d\nNome: %s\nSexo: %s\nEstado Civil: %s\nNumero de amigos: %d\nNumero de fotos: %d\n\n",dados[i].idade,dados[i].nome,dados[i].sexo,dados[i].estadocivil,dados[i].numdeamigos,dados[i].numdefotos);
    };


	return 0;
}