#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int* sortedArray = (int*) malloc(sizeof(int) * numsSize);

    int* left = sortedArray;
    int* right = sortedArray + numsSize;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 1) {
            *--right = nums[i];
        } else {
            *left++ = nums[i];
        }
    }
    
    *returnSize = numsSize;
    return sortedArray;
}

int main(int argc, char const *argv[])
{
    int array[] = {64, 25, 12, 22, 11};

    int size = sizeof(array) / sizeof(array[0]);

    sortArrayByParity(array, size, &size);

    printf("Array after sort ");
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
        
    return 0;
}