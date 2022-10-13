#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *p);
void imprimirVetor(int *p);
void ordenarVetor(int *p);

int main() {

    int *vetor; 
    vetor = (int*) malloc(10 * sizeof(int));

    lerVetor(vetor);

    ordenarVetor(vetor);

    imprimirVetor(vetor);

    free(vetor);

    return 0;
}

void lerVetor(int *p) {
    for (int i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", (p+i));
    }
}

void ordenarVetor(int *p) {
    int aux;

    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            if (p[i] < p[j]) {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
}

void imprimirVetor(int *p){
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(p+i));
    }
}