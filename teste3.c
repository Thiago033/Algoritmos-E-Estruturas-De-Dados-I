#include <stdio.h>

int fatorial(int num);

int main() {

    int n;
    float e;
    float fat;
    printf("Digite quantas linhas do numero de euler:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        fat = fatorial(i);
        e += 1.0 / fat;
    }
    
    printf("%f", e);

    return 0;

}

int fatorial(int num){
    if (num == 0) return 1;

    return num *= fatorial(num - 1);
}
