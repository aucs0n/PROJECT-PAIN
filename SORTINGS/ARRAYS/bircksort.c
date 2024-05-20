#include <stdio.h>
#include <stdbool.h>
/*================================
Author: Im You
Description: Where You Go I Go
================================*/

void printArray(int arr[], int size);
void brickSort(int arr[], int size);

int main() {
    int arr[] = {5, 8, 75, 48, 56, 13, 9, 91, 14, 87};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("BRICK SORT\n");
    printArray(arr, size);
    brickSort(arr, size);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void brickSort(int arr[], int size) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i <= size - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        for (int i = 0; i <= size - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        printArray(arr, size);
    }
}