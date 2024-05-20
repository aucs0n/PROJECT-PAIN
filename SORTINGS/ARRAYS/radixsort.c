#include <stdio.h>
/*================================
Author: Im You
Description: Where You Go I Go
================================*/
void printArray(int arr[], int size);
int getMax(int arr[], int size);
void countSort(int arr[], int size, int exp);
void radixsort(int arr[], int size);
int main() {
    int arr[] = {5, 8, 75, 48, 56, 13, 9, 91, 14, 87};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("RADIX SORT\n");
    printArray(arr, size);
    radixsort(arr, size);

    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int size, int exp) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int size) {
    int max = getMax(arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, size, exp);
        printArray(arr, size);
    }
}
