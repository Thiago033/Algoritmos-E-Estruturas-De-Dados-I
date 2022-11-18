#include <stdio.h>
#include <string.h>

void insertionSort(int array[], int size){
    int i, key, j;

    for (i = 1; i < size; i++) {

        key = array[i];
        j = i - 1;
 
        while (j >= 0 && array[j] > key) {

            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

int checkArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (!((array[i] + 1) == array[i + 1])) {
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

    insertionSort(nums, size);

    printf("Sorted array: \n");
    printArray(nums, size);

    printf("Missing number in sequence: %d", checkArray(nums, size));

    return 0;
}