#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a[3] = {5,9,7};

    void *p = &a;
    
    p = p + sizeof(int);

    printf("%d", *(int *)p);

    return 0;
}