#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/*
==================
Merge Sort
==================
*/
int merge(int array[], int low, int mid, int high) {

    int *temp, p1, p2, size, i, j, k;
    int end1 = 0, end2 = 0;

    size = high - low + 1;

    p1 = low;
    p2 = mid + 1;

    temp = (int *) malloc(size * sizeof(int));

    if (temp != NULL) {
        for (i = 0; i < size; i++) {
            if (!end1 && !end2) {
                
                if (array[p1] < array[p2]) {
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }
                
                if (p1 > mid) end1 = 1;
                if (p2 > high) end2 = 1;
            } else {
                if(!end1){
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }
            }
        }

        for (j = 0, k = low; j < size; j++, k++) {
            array[k] = temp[j];
        }
    }
    
    free(temp);
}

void mergeSort(int *array, int low, int high) {

    if (low < high) {

        int mid = floor((low + high) / 2);

        mergeSort(array, low , mid);
        mergeSort(array, mid+1, high);
        
        merge(array, low, mid, high);
    }
}

/*
==================
Quick Sort
==================
*/
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

/*
==================
Selection Sort
==================
*/
void selectionSort(int *array, int size) {
    int i,j, smaller, swap;

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

/*
==================
Insertion Sort
==================
*/
void insertionSort(int *array, int size) {
    int i, j, aux;

    for (i = i; i < size; i++) {
        aux = array[i];

        for (j = i; (j > 0) && (aux < array[j - 1]); j--) {
            array[j] = array[j - 1];
        }

        array[j] = aux;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main () {

    int size;
    time_t t1 = time(NULL);

    printf("Type the size of the array: \n");
    scanf("%d", &size);

    int* array = (int  *) malloc(sizeof(int) * size);

    //define the random number generator 
    srand(t1);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    printArray(array, size);
    
    free(array);

   return(0);
}