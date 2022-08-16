#include <stdio.h>
#include <string.h>
int i=0;
int aluno[];
typedef struct
{
    char nome[100]; char curso [100];
    int matricula[41];
}informacoes;

void receber(informacoes nome[], int t){
 for(i=0; i<t; i++){
    printf("Nome: ");
    fflush(stdin);

    fgets(aluno[i].curso, 100, stdin);
    printf("Curso: ");
    fflush(stdin);

    fgets(aluno[i].matricula, 41, stdin);
    printf("Matricula: ");
    fflush(stdin);

    scanf("%d", &aluno[i].matricula);
 }
}
 void mostrar(aluno[], int t){
    int i;
    for(i=0; i<t;i++){
        printf("Nome %s", aluno[i].nome);
        printf("Curso %s", aluno[i].curso);
        printf("Matricula %d", aluno[i].matricula);

    }
 }
int main(){
    #define MAX 5
    aluno[MAX];
    scanf(aluno);
    printf(aluno);
    return 0;
}