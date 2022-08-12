#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 10
#define MAX 100

char buffer[MAX];

int main () {
    char *nomes[TAM];


    

    int i,j;
}

void adicionarNome(char *mat) {
    int i = 0;

    gets(buffer);
    mat[i] = (char *) calloc((strlen(buffer)+1), sizeof(char));

    if (!mat) {
        printf ("** Erro: Memoria Insuficiente **");
        exit(1);
    }

}

    // printf("\nEntre com %d Frases:\n\n", TAM);
    // for (i=0; i<TAM; i++) {

    //     gets(buffer);
    //     mat[i] = (char *) calloc((strlen(buffer)+1), sizeof(char));

    //     if (!mat) {
    //         printf ("** Erro: Memoria Insuficiente **");
    //         for(j=0; j < i; j++)
    //             free(mat[j]);
    //         exit(1);
    //     }

    //     strcpy(mat[i],buffer);
    // }   

    // printf("\nFrases digitadas");
    // for(i=0; i<TAM; i++)
    // printf("%s\n", mat[i]);
    // for(j=0; j<TAM; j++)
    // free(mat[j]);
