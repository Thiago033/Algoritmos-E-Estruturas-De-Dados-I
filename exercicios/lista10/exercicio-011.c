/*
Exercicio 11: 
    Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int matricula;
    char sobrenome[25];
    int anoNascimento;
};

typedef struct aluno aluno;

int main(int argc, char const *argv[]) {

    int qtd;

    aluno *ptrAluno;

    printf("Quantos alunos deseja alocar? ");
    scanf("%d", &qtd);

    ptrAluno = malloc(qtd * sizeof(aluno));

    for (int i = 0; i < qtd; i++) {
        printf("Digite a matricula do aluno %d:\n", i+1);
        scanf("%d", &ptrAluno[i].matricula);

        printf("Digite o sobrenome do aluno %d:\n", i+1);
        scanf("%s", &ptrAluno[i].sobrenome);

        printf("Digite o ano de nascimento do aluno %d:\n", i+1);
        scanf("%d", &ptrAluno[i].anoNascimento);
    }

    for (int i = 0; i < qtd; i++) {
        printf("Aluno %d\n", i+1);
        printf("Matricula %d\n", ptrAluno[i].matricula);
        printf("Sobrenome %s\n", ptrAluno[i].sobrenome);
        printf("Ano de nascimento %d\n", ptrAluno[i].anoNascimento);
        printf("\n");
    }   

    free(ptrAluno);

    return 0;
}