#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *first, int *second){

    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void minHeapify(int numArr[], int size, int currentNode){

    int largest = currentNode, left = 2*currentNode+1, right = 2*currentNode+2;
    if(left < size && numArr[left] < numArr[largest]) // Checks if left child is greater than current largest.
        largest = left;
    if(right < size && numArr[right] < numArr[largest]) // Checks if right child is greater than current largest.
        largest = right;
    if(largest != currentNode) // If largest index is not equal to current node's index, swap current node index and largest.
    {
        swap(&numArr[currentNode], &numArr[largest]);
        minHeapify(numArr, size, largest);
    }
}

void maxHeapify(int numArr[], int size, int currentNode){

    int largest = currentNode, left = 2*currentNode+1, right = 2*currentNode+2;
    if(left < size && numArr[left] > numArr[largest]) // Checks if left child is greater than current largest.
        largest = left;
    if(right < size && numArr[right] > numArr[largest]) // Checks if right child is greater than current largest.
        largest = right;
    if(largest != currentNode) // If largest index is not equal to current node's index, swap current node index and largest.
    {
        swap(&numArr[currentNode], &numArr[largest]);
        maxHeapify(numArr, size, largest);
    }
}

void insertNode(int numArr[], int currentIter, int value){

    numArr[currentIter] = value;
    if(currentIter != 0)
    {
        currentIter++;
        for(int i = currentIter/2 - 1; i >= 0; i--)
            maxHeapify(numArr, currentIter, i);
    }
}

int main(){

    int numOfNodes, *numArr, i, num;
    printf("How many nodes would you like to add? ");
    scanf("%d", &numOfNodes);
    numArr = (int *) malloc(numOfNodes * sizeof(int));
    for(i = 0; i < numOfNodes; i++)
    {
        printf("Enter number #%d: ", i+1);
        scanf("%d", &num);
        insertNode(numArr, i, num);
    }
    for(i = 0; i < numOfNodes; i++)
        printf("%d ", numArr[i]);
    return 0;
}