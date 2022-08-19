/*
Exercicio 9: 
    Faca um programa que leia uma quantidade qualquer de numeros armazenando-os na ´
    memoria e pare a leitura quando o usuario entrar um numero negativo. Em seguida, ´
    imprima o vetor lido. Use a func¸ao REALLOC
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    
    int *vetor, opcao=1, index = 0;

    vetor = (int *) malloc(sizeof(int));
    
    do {
        printf("Digite um numero para o vetor:\n");
        scanf("%d", &vetor[index]);

        printf("Digitar mais um numero? [1]\n");
        scanf("%d", &opcao);

        if (opcao == 1) {

            index++;

            vetor = (int *) realloc(vetor, (index+1) * sizeof(int));
        }
    } while (opcao == 1);

    printf("Numero digitados: \n");

    for (int i = 0; i <= index; i++) {
        printf("%d ", vetor[i]);
    }
    
    free(vetor);

    return 0;
}