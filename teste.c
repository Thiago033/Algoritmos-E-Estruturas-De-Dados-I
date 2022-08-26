#include <stdio.h>

int main() {

    int n;

    printf("Digite quantas linhas do triangulo:\n");
    scanf("%d", &n);

    int numero = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {

            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }
    

    return 0;
}