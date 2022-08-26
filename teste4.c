#include <stdio.h>
#include <string.h>

int main() {

    char string[] = "Ola mundo!";

    int length = strlen(string);

    char c;

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        c = string[i];
        string[i] = string[j];
        string[j] = c;
    }
    
    printf("%s", string);
}