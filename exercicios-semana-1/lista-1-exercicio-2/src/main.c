#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu();

int main() {
    char *nomes, *removerNome, nome[50];

    int i, j, index, opcao, indexNome = 0, totalNomes = 0;

    nomes = (char*)malloc(sizeof(char));

    if (!nomes) {
        printf("Erro! Memoria indisponivel!\n");
        exit (1);
    }

    do {
        opcao = menu();

        switch (opcao) {
        case 1:
            printf("Digite um nome para adicionar a lista:\n");
            fflush(stdin);
            gets(nome);

            nomes = (char*)realloc(nomes, (strlen(nomes) + strlen(nome)) + 2 * sizeof(char));

            if (!nomes) {
                printf("Erro! Memoria indisponivel!\n");
                exit (1);
            }

            strcat(nome,".");

            for (i=0; i <= (strlen(nome)); i++) {
                nomes[indexNome] = nome[i];
                indexNome++;
            }
            
            totalNomes++;
            indexNome--;
            
            break;

        case 2:
            printf("Digite o nome a ser removido:\n");
            fflush(stdin);
            gets(nome);

            removerNome = strstr(nomes, nome);

            if (removerNome) {
                index = strlen(nomes) - strlen(removerNome);

                if (nomes[index - 1] == '.') {
                    index--;
                    removerNome--;
                }

                for (i=0; i<=strlen(nome); i++) {

                    for (j=0; j<strlen(removerNome); j++) {
                        nomes[index + j] = nomes[index + j + 1];
                    }

                    indexNome--;
                }

                nomes = (char *)realloc(nomes, strlen(nomes) + 1 * sizeof(char));

                printf("Nome removido!\n");
                totalNomes--;
            } else {
                printf("Nome nao encontrado!\ntente novamente.\n");
            }

            break;

        case 3:
            if (totalNomes <= 0) {
                printf("Lista vazia!\n"); 
                break;
            }

            printf("Listando nomes:\n");
			printf("=========================\n");

            for (i=0; i <= (strlen(nomes)); i++) {
                if (nomes[i] != '.') printf("%c", nomes[i]);
				if (nomes[i] == '.') printf("\n");
            }

			printf("=========================\n");

            break;

        case 0:
            printf("Saindo do programa.");

            break;
        
        default:
            printf("Opcao invalida!\nTente novamente.\n");

        	break;
        }

    }while (opcao != 0);

    free(nomes);
}

int menu() {
    int opcao;

    printf("Escolha uma opcao abaixo:\n");
    printf("Adicionar nome: [1]\n");
    printf("Remover nome:   [2]\n");
    printf("Listar:         [3]\n");
    printf("Sair:           [0]\n");
    scanf("%d", &opcao);

    return opcao;
}