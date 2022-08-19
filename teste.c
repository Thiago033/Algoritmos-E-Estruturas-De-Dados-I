#include <stdio.h>

int main() {
    int *vetor1;
    int *vetor2;

    int num;

    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero para o vetor 1: \n", i+1);
        scanf("%d", &num);
        vetor1[i] = num;
    }

    for (int j = 0; j < 10; j++) {
        printf("Digite o %d numero para o vetor 2: \n", j+1);
        scanf("%d", &num);
        vetor2[j] = num;
    }
    
    return 0;
}