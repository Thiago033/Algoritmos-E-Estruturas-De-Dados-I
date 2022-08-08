#include <stdio.h>
#include <math.h>

int raizes(float A,float B,float C,float * X1,float * X2);


int main() {

    float a, b, c, raiz1, raiz2;

    printf("A: ");
    scanf("%f", &a);
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
