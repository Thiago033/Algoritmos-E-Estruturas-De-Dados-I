Faça uma agenda capaz de incluir, apagar, buscar e listar quantas
pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar
num único lugar chamado: “void *pBuffer”. •Não pergunte para o usuário quantas pessoas e
le vai incluir. Não pode alocar espaço para mais pessoas
do que o necessário.•Cada pessoa tem nome[10], idade e telefone.
#include<stdio.h>
#include<stdlib.h>

int main(){
void "*pBuffer";
int "*list"
int "nome[10]", "idade", "telefone[10]";
int "incluir", "apagar", "buscar", "*listar";

void incluirNaLista( node *lista);
void ApagarDaLista( node *lista);
void BuscaNaLista( node *lista);
void ListarPessoas( node *lista);
void InserirNome  () node *lista);  
void InserirTelefone () node *lista);
void InserirIdade (node *lista);





int menu();





int opt;
    printf("o que deseja modificar na lista\n");
    printf(0."Sair");
    printf(1."insira o nome: \n");
    printf(2."insira a idade: \n");
    printf(3."insira o telefone: \n");
    printf(4."incluir na lista\n");
    printf(5."apagar na lista\n");
    printf(6."buscar na lista\n");
    printf(7."listar pessoas da lista\n");


return opt;

switch case(opt){

case 1:
InserirNome;

case 2:
InserirIdade;

case 3:
InserirTelefone;
break:

case 4;
IncluirNaLista;
break;

case 5:
ApagarDaLista;
printf("a linha da lista foi apagada");
scanf("%d\n", &opt);
break;

case 6:
BuscaNaLista;
break;

case 7:
ListarPessoas;
break;
}

node *aloca;

int lista





void InserirNome( node *lista);
printf("escreva o nome que deseja: \n")
Scanf("%d\n", &nome[10]);

void InserirIdade( node *lista);
printf("escreva o numero que deseja:\n")
scanf("%d\n", &telefone);

void InserirTelefone( node *lista);
printf("escreva a idade:\n")
scanf("%d\n", &idade);

void InserirNaLista( node *lista);
printf("escreva qual linha dseja inserir")
scanf("%d\n", &opt);

void ApagarDaLista( node *lista);
printf("escreva qual linha deseja apagar da lista");
scanf("%d\n", &opt);

void BuscarNaLista( node *lista);
printf("escreva qual linha deseja buscar");
scanf("%d\n", &opt);

void ListarPessoas( node *lista);
printf("")


}
