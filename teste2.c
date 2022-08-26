#include <stdio.h>

int main() {

    int n;

    printf("Digite quantos numeros do fibonacci:\n");
    scanf("%d", &n);
    
    int n1 = 0, n2 = 1, aux;

    for (int i = 0; i < n; i++) {
        printf("%d ", n1);
        aux = n1;
        n1 = n2;
        n2 += aux;
    }

    return 0;
}