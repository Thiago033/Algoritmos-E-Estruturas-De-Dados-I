/*
Exercicio 26:

Implemente uma func¸ao que calcule as raızes de uma equacao do segundo grau do tipo
Ax2 + Bx + C = 0. Lembrando que:

A variavel A tem que ser diferente de zero.

• Se ∆ < 0 nao existe real.
• Se ∆ = 0 existe uma raiz real.
• Se ∆ ≥ 0 existem duas ra´ızes reais.

Essa funcao deve obedecer ao seguinte prototipo:
int raizes(float A,float B,float C,float * X1,float * X2);

Essa func¸ao deve ter como valor de retorno o numero de raızes reais e distintas da
equacao. Se existirem raızes reais, seus valores devem ser armazenados nas variaveis
apontadas por X1 e X2.

*/

#include <stdio.h>
#include <math.h>

int raizes(float A,float B,float C,float * X1,float * X2);


int main() {

    float a, b, c, raiz1, raiz2;

    do {
        printf("A: (Nao pode ser zero)");
        scanf("%f", &a);
    } while (a == 0);
    
    printf("B: ");
    scanf("%f", &b);
    printf("C: ");
    scanf("%f", &c);

    raiz1, raiz2 = raizes(a,b,c, &raiz1, &raiz2);

    printf("raiz1: %.2f , raiz2: %.2f", raiz1, raiz2);
}

/*
============================================================
raizes

calcula as raizes de uma equacao do segundo grau do tipo:
Ax^2 + Bx + C = 0
============================================================
*/
int raizes(float A,float B,float C,float * X1,float * X2) {
    float delta;

    delta = sqrt((pow(B,2))-(4*A*C));

    *X1 = (-B + delta) / (2*A);
    *X2 = (-B - delta) / (2*A);

    if (delta < 0) {
        printf("Nao existe raiz real");
        return 0;
    } else if (delta == 0) {
        return *X1;
    } else {
        return *X1, *X2;
    }
}
