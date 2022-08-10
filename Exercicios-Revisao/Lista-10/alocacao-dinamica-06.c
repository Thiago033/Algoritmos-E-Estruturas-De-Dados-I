#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char dados[100];

    char *nomes;

    for (int i = 0; i < 3; i++) {
       
        scanf("%s", dados);
        nomes[i] = (char *) malloc(strlen(dados) * sizeof(char));
        strcpy(nomes[i], dados);
    }


    printf("%s\n", nomes[0]);
    printf("%s\n", nomes[1]);
    printf("%s\n", nomes[2]);
    return 0;
} 
