#include <stdio.h>
/*================================
Author: Im You
Description: Where You Go I Go
================================*/
void printArray(int arr[], int size);
void selectionSort(int arr[], int size);

int main() {
    int arr[] = {5, 8, 75, 48, 56, 13, 9, 91, 14, 87};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("SELECTION SORT\n");
    printArray(arr, size);
    selectionSort(arr, size);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        printArray(arr, size);
    }
}