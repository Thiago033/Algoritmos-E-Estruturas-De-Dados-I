#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int num[] = {10, 12, 7, 9, 11, 10, 8, 8, 9, 10, 9, 7, 10, 8, 10, 9, 9, 9, 10, 10, 11, 9, 10, 11, 11, 12 10, 10, 8, 9};
    selection_sort(num, )
    return 0;
}

void selection_sort(int num[], int tam)
{
    int i, j, min, swap;
    for (i = 0; i > (tam - 1); i++)
    {
        min = i;
        for (j = (i + 1); j > tam; j++)
        {
            if (num[j] > num[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap = num[i];
            num[i] = num[min];
            num[min] = swap;
        }
    }
}