#include <stdio.h>
#include <stdlib.h>

int partition(int array[], int low, int high) {
    int left, right, pivot, aux;

    left = low;
    right = high;

    pivot = array[low];

    while (left < right) {

        while (array[left] <= pivot) {
            left++;
        }

        while (array[right] > pivot) {
            right--;
        }

        if (left < right) {
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
        }
    }

    array[low] = array[right];
    array[right] = pivot;

    return right;
}

void quickSort(int *array, int low, int high) {

    if (low < high) {
        int pivot = partition(array, low, high);

        quickSort(array, low , pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

// 0 "1" 2 3
int checkArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (!((array[i] + 1) == array[i + 1])) {
            return array[i] + 1;
        }
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int *nums, size, i, digit;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &size);

    nums = (int*)malloc(sizeof(int)*size);

    for(i = 0; i < size; i++) {
        printf("Digite um numero inteiro:\n");
        scanf("%d", &digit);
        *(nums+i) = digit;
    }

    printf("\nOriginal array:\n");
    printArray(nums, size);

    quickSort(nums, 0, size-1);

    printf("\nSorted array:\n");
    printArray(nums, size);

    printf("\nMissing number in sequence: %d\n", checkArray(nums, size));

    free(nums);

    return 0;
}