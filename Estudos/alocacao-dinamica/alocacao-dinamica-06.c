#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *nomes[10];


int main() {

    char dados[20];
    printf("Digite um nome:\n");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    
    nomes[0] = alocarMemoria(strlen(dados));
    strcpy(nomes[0], dados);
    
    printf("%s", nomes[0]);

    return 0;
}

/*
==================================================
alocarMemoria

aloca memoria para a palavra no vetor de strings
==================================================
*/
char* alocarMemoria(int tamanho){
    char* info = NULL;

    info = (char*) malloc(sizeof(tamanho) * sizeof(char));

    if(info == NULL){
        printf("ERRO: impossível alocar a quantidade de memória requisitada!");
        exit(1);
    }

    return info;
}