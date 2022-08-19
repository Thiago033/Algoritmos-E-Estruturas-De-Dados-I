/*
Exercicio 13: 
    Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensoes ˜
    definidas pelo usuario e a leia. Em seguida, implemente uma func¸ ´ ao que receba um ˜
    valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso nao esteja na matriz.
*/

#include <stdio.h>
#include <stdlib.h>

int contido(int resp, int **matriz, int nLinhas, int nColunas);

int main(int argc, char const *argv[]) {
    
    int **matriz;
    int nLinha, nColunas;

    printf("Digite o numero de linhas: ");
    scanf("%d", &nLinha);
    printf("Digite o numero de colunas: ");
    scanf("%d", &nColunas);

    matriz = (int **) malloc(nLinha * sizeof(int *));

    //Preencher linhas da matriz

    for (int i = 0; i < nLinha; i++) {
        
        matriz[i] = (int *) malloc(nColunas * sizeof(int));

        for (int j = 0; j < nColunas; j++) {
            printf("");
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int resp, retorno, opcao;

    do {
        printf("Verificar qual valor? \n");
        scanf("%d", &resp);

        retorno = contido(resp, matriz, nLinha, nColunas);

        if (retorno == 1)
        {
            printf("O valor ESTA contido na matriz");
        } else {
            printf("O valor NAO ESTA contido na matriz");
        }
        
        printf("Verificar mais um valor? [1]");
        scanf("%d", opcao);

    } while (opcao == 1);
    

    return 0;
}

int contido(int resp, int **matriz, int nLinhas, int nColunas) {
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            if (resp == matriz[i][j]) {
                return 1;
            }
        } 
    }

    return 0;
}