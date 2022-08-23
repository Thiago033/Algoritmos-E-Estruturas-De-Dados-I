#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu();
void adicionarPesssoa(void *pBuffer, char *nome, int *idade, int *telefone);
void listarPessoas(void *pBuffer, int numeroDePesssoas);

void *pBuffer;
int numeroDePessoas = 0;

int main() {

    int opcao;

	char *nome;
	int *idade, *telefone;

	pBuffer = (void*) malloc(sizeof(char) * 10 + 1 + sizeof(int) + sizeof(int));

    if (!pBuffer) {
        printf("Erro! Memoria indisponivel!\n");
        exit (1);
    }

    do {
        opcao = menu();

        switch (opcao) {
        case 1:
			adicionarPesssoa(pBuffer, nome, idade, telefone);
            
            break;

        case 2:

            //listarPessoas(pBuffer, numeroDePessoas);

            break;

        case 3:
         
            //Funcao remover pessoa da lista

            break;

        case 4:
         
            //Funcao buscar pessoa na lista

            break;

        case 0:
            printf("Saindo do programa.");
            exit(0);

            break;
        
        default:
            printf("Opcao invalida!\nTente novamente.\n");

        	break;
        }

    }while (opcao != 0);
}

/*
==================================
Menu

Printa um menu para interacao com 
o usuario e retorna uma opcao
===================================
*/
int menu() {
    int opcao;

    printf("Escolha uma opcao abaixo:\n");
    printf("Adicionar nome: [1]\n");
    printf("Listar pessoas: [2]\n");
    printf("Remover nome:   [3]\n");    
    printf("Sair:           [0]\n");
    fflush(stdin);
    scanf("%d", &opcao);

    return opcao;
}

/*
=============================================
Adicionar Pesssoa

Adiciona nome, idade, e telefone as variaveis
==============================================
*/
void adicionarPesssoa(void *pBuffer, char *nome, int *idade, int *telefone) {
    if (numeroDePessoas == 0) {
        nome = pBuffer;
    } else {

        pBuffer = realloc(pBuffer, 2 * (sizeof(char) * 10 + 1 + sizeof(int) + sizeof(int)));

        nome = telefone;
    }
    
	idade = nome + sizeof(char) * 10 + 1;
	telefone = idade + sizeof(int);

	printf("Digite o nome:\n");
    fflush(stdin);
    char tempNome[10];
    gets(tempNome);

	strcat(tempNome, "\0");
    strcpy(nome,tempNome);


    printf("Digite a idade:\n");
    fflush(stdin);
    int tempIdade;
    scanf("%d", &tempIdade);
    *idade = tempIdade;


    printf("Digite o telefone:\n");
    int tempTelefone;
    fflush(stdin);
    scanf("%d", &tempTelefone);
    *telefone = tempTelefone;

	printf("VALOR NOS PONTEIROS:\n %s, %d, %d\n", nome, *idade, *telefone);

    numeroDePessoas++;
}

/*
=====================================================
Listar Pesssoas

Lista as informacoes das pessoas salvas em pBuffer
======================================================
*/
void listarPessoas(void *pBuffer, int numeroDePesssoas) {

}