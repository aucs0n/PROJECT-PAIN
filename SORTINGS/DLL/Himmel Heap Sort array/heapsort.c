#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapSort(LIST *L){
	NODE *walker = L->head;
	
	int arr[10];
	int i, c, j, n =10;
	for(i=0;i<10;i++){
		arr[i]=walker->x;
		walker=walker->n;
	}
	
	for(i=0;i<n;i++){
		reheapUp(arr, i); // Heapify
			
		printf("\n");
		for(c=0;c<=i;c++){
			printf("%4d", arr[c]);
		}
	}
	
	//Delete root
	j=n-1;
	while(j>=0){
		printf("\n");
		for(c=0;c<=j;c++){
			printf("%4d", arr[c]);
		}
		
		swap(&arr[0], &arr[j]);
		j--;
		reheapDown(arr, 0, j);
	}
	
	walker = L->head;
	
	for(i=0; i<10;i++){
		walker->x=arr[i];
		walker=walker->n;
	}
}

void reheapUp(int *arr, int index){
	while(index>0 && arr[index]>arr[(index-1)/2]){
		swap(&arr[index], &arr[(index-1)/2]);
		index= (index-1)/2;
	}
}

void reheapDown(int *arr, int f, int l){
	int c=f*2+1;
	while(c<=l && arr[c] > arr[(c-1)/2]){
		if( (c<l) && (arr[c] < arr[c+1]))	c++;	// Check sibling's value
		//if(arr[c] < arr[(c-1)/2])			break; // Check parent's value
		swap(&arr[c], &arr[(c-1)/2]);
		c=c*2+1;
	}
}
