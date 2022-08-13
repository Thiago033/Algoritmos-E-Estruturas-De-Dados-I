#include <stdio.h>

int main() {
    int i = 10;
    int *pNum;
    int **ppNum;

    pNum = &i;

    ppNum = &pNum;

   
    printf("%d\n", i);
    printf("%d\n", *pNum);
    printf("%d\n", **ppNum);

    printf("%d\n", ppNum);
    printf("%d\n", *ppNum);

    return 0;
}