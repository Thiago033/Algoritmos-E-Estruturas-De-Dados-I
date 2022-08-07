/*
Lista Structs:

1. 
Escreva um trecho de codigo para fazer a criacao dos novos tipos de dados conforme solicitado abaixo:
    • Horario: composto de hora, minutos e segundos.
    • Data: composto de dia, mes e ano.
    • Compromisso: composto de uma data, horario e texto que descreve o compromisso.
*/

#include<stdio.h>

struct Horario{
    int hora;
    int minutos;
    int segundos;
};

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Compromisso{
    char descricao[20];
    struct Horario hora;
    struct Data data;
    };

int main(){

    struct Compromisso compromisso1;

    printf("Digite a descricao do compromisso: \n");
    gets(compromisso1.descricao);

    printf("Digite um horario: \n");
    scanf("%d %d %d", &compromisso1.hora.hora, &compromisso1.hora.minutos, &compromisso1.hora.segundos);

    printf("Digite uma data: \n");
    scanf("%d %d %d", &compromisso1.data.dia, &compromisso1.data.mes, &compromisso1.data.ano);

    printf("%s\n", compromisso1.descricao);
    printf("%d Horas %d  Minutos %d Segundos \n", compromisso1.hora.hora, compromisso1.hora.minutos, compromisso1.hora.segundos);
    printf("Dia %d Mes %d Ano %d", compromisso1.data.dia, compromisso1.data.mes, compromisso1.data.ano);

   

    return 0;
}