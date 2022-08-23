#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu();
void adicionarPesssoa(char *nome, int *idade, int *telefone);
void listarPessoas();

void *pBuffer;
int numeroDePessoas = 0;

int main() {

    int opcao;

	char *nome; 
	int *idade, *telefone;

	pBuffer = (void*) malloc(sizeof(char) * 11 + sizeof(int) + sizeof(int));

    if (!pBuffer) {
        printf("Erro! Memoria indisponivel!\n");
        exit (1);
    }

    do {
        opcao = menu();

        switch (opcao) {
        case 1:
			adicionarPesssoa(nome, idade, telefone);
            printf("PESSOA ADICIONADA!");
            break;

        case 2:

            //listarPessoas();

            break;

        case 3:
         
            //Funcao remover pessoa da lista

            break;

        case 4:
         
            //Funcao buscar pessoa na lista

            break;

        case 0:
            printf("Saindo do programa.");
            exit(1);

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
    printf("Adicionar pessoa: [1]\n");
    printf("Listar pessoas:   [2]\n");
    printf("Remover pessoa:   [3]\n");
    printf("Buscar pessoa:    [4]\n");
    printf("Sair:             [0]\n");

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
void adicionarPesssoa(char *nome, int *idade, int *telefone) {

    //pBuffer = |    nome 1  | idade 1 | telefone 1 |   nome 2  | idade 2 | telefone 2 |   nome N  | idade N | telefone N  |
    //          | (char*11)  | (int)   |   (int)    | (char*11) |  (int)  |   (int)    | (char*11) |  (int)  |   (int)     |
    //          |                 19                |                 19               |                 19                |

    if (numeroDePessoas == 0) {
        //Caso seja a primeira entrada, o ponteiro para "nome" recebe o endereco da primeira posicao do "pBuffer" 
        nome = pBuffer + sizeof(int);
    } else {

        //Tentando dobrar o tamanho do pBuffer
        pBuffer = (void *) realloc(pBuffer, 2 * (sizeof(char) * 11 + sizeof(int) + sizeof(int)));

        //a partir da segunda entrada na agenda, "nome" ira receber o endereco da posicao seguinte ao endereco da variavel "telefone".
        nome = telefone + sizeof(int);
    }

	idade = nome + sizeof(char) * 11;
	telefone = idade + sizeof(int);

	printf("Digite o nome:\n");
    fflush(stdin);
    char tempNome[10];
    gets(tempNome);
    strcpy(nome,tempNome);
    strcat(tempNome, "\0");

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
void listarPessoas() {

}