#include <stdio.h>
/*================================
Author: Im You
Description: Where You Go I Go
================================*/
void printArray(int arr[], int size);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
    int arr[] = {5, 8, 75, 48, 56, 13, 9, 91, 14, 87};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("QUICK SORT\n");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printArray(arr, high + 1);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
