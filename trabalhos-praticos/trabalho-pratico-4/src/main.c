#include <stdio.h>
#include <string.h>

void selectionSort(int* array, int size) {
    int i, j, smaller, swap;

    for (i = 0; i < size - 1; i++) {

        smaller = i;

        for (j = i + 1; j < size; j++) {

            if (array[j] < array[smaller]) {
                smaller = j;
            }
        }

        if (i != smaller) {
            swap = array[i];
            array[i] = array[smaller];
            array[smaller] = swap;
        }
    }
}

int checkArray(int* array, int size) {

    // 0, 1, 3

    for (int i = 0; i < size; i++) {
        if ((array[i] + 1) == array[i + 1]) {
            printf("Check!");
        } else {
            return array[i] + 1;
        }
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d, ", array[i]);
    printf("\n");
}

int main() {
    

    int nums[] = {9,6,4,2,3,5,7,0,1};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: \n");
    printArray(nums, size);

    selectionSort(nums, size);

    printf("Sorted array: \n");
    printArray(nums, size);

    printf("%d", checkArray(nums, size));

    return 0;
}