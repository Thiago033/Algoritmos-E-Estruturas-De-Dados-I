// C program for insertion sort
#include <math.h>
#include <stdio.h>

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}  

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], that are
          greater than temp, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
        printArray(arr, n);
    }
}
  
/* Driver program to test insertion sort */
int main()
{
    int arr[] = { 6, 5, 4, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    insertionSort(arr, n);
    printArray(arr, n);
  
    return 0;
}