/*
Lista Funcoes:

13. 
Faca uma funcao que receba dois valores numericos e um sımbolo. Este sımbolo representara a operacao que se deseja efetuar com os numeros. 
Se o sımbolo for + deveraser realizada uma adicao, se for − uma subtracao, se for / uma divisao e se for ∗ sera efetuada uma multiplicacao.
*/

#include<stdio.h>

void OperacaoMatematica (int num1, int num2, char operacao);

int main() {
    int num1, num2;
    char operacao;

    printf("Digite dois numeros e uma operacao: (+ , - , / , *)\n");
    scanf("%d %d %c", &num1, &num2, &operacao);

    OperacaoMatematica(num1, num2, operacao);

    return 0;
}

void OperacaoMatematica (int num1, int num2, char operacao) {
    if (operacao == '+') {   
        printf("%d + %d = %d", num1, num2, num1+num2);
    } else if (operacao == '-') {
        printf("%d - %d = %d", num1, num2, num1-num2);
    } else if (operacao == '*') {
        printf("%d * %d = %d", num1, num2, num1*num2);
    } else if (operacao == '/') {
        printf("%d / %d = %d", num1, num2, num1/num2);
    } else {
        printf("Operacao invalida!");
    }
}



