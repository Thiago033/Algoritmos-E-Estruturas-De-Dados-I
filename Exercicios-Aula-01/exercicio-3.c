/*
Lista Ponteiros:

1.
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char.
Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando os ponteiros.
Imprima os valores das variaveis antes e apos a modificacao.
*/

#include<stdio.h>

int main() {
    int inteiro = 1;
    char character = 'a';

    int *pInteiro;
    char *pCharacter;

    pInteiro = &inteiro;
    pCharacter = &character;
    

    printf("Valores das variaveis:\n");
    printf("inteiro: %d\n", inteiro);
    printf("character: %c\n", character);

    printf("Valores dos ponteiros \n");
    printf("pInteiro: %d \n", *pInteiro);
    printf("pCharacter: %c \n", *pCharacter);

    *pInteiro = 2;
    *pCharacter = 'b';

    printf("=============================== \n");

    printf("Valores das variaveis modificadas pelos ponteiros:\n");
    printf("inteiro: %d\n", inteiro);
    printf("character: %c\n", character);


    return 0;
}


