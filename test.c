#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main () {

    time_t t1 = time(NULL);

    int array;

    //define the random number generator 
    srand(t1);


    array = rand() % 100;

    printf("%d", array);


}