#include <stdio.h>
#include <string.h>

int main() {

    char *frase = "AEIOU";
    printf("frase: %s\n", frase);

    char *fodase;
    fodase = frase;

    printf("%c", *fodase);
    fodase++;
    fodase = 'X';
    printf("%c", *fodase);

    //printf("fodase: %s", fodase);
    


    return 0;
}
