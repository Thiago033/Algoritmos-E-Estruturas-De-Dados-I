#include <stdio.h>
#include <stdlib.h>

int main() {

    int *vetor; 
    vetor = (int*) malloc(5 * sizeof(int));
    int num;

    for (int i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &num);
        vetor[i] = num;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    
    free(vetor);

    return 0;
}