#include <stdio.h>

int main(){

    char *frases[3];

    frases[0] = "1 string de caracteres 1";
    frases[1] = "2 string de caracteres 2";
    frases[2] = "3 string de caracteres 3";

    printf("%d", (int) sizeof(frases));

    puts(frases[0]);
    puts(frases[1]);
    puts(frases[2]);
}
