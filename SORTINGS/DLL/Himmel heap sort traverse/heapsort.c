/* ===============================================================================
 FILE     	 : list.c
 AUTHORS     : himmel
 DESCRIPTION : Handles the list structure: creation, deletion, and sorting
 COPYRIGHT   : 16 March 2021
 =============================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "heapsort.h"
#define MAX 8

/* ================================================================================
 FUNCTION        : heapSort
 DESCRIPTION     : Sorts the list by using heap sort
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ */
void heapSort(LIST *L){
	NODE *walker = L->head;
	NODE *last, *root;
	int temp, i, j, c, n = MAX;
	
	for(i=0;i<n;i++){
		reheapUp(L, walker, i); // Heapify
		walker=walker->n;
	}
	
	displayList(L);
	//Delete root
	j=0;
	last = L->tail;
	root= L->head;
	
	while(last!=root){	
		//swap root with current last
		temp = last->x;
		last->x = root->x;
		root->x = temp;
		
		//remove last
		last=last->p;
		
		reheapDown(L, last);
		printf("\nPASS %d:", j++);
		displayList(L);
	}
	
	printf("\n====SORTED DATA====");
	displayList(L);	
}

/* ================================================================================
 FUNCTION        : heapSort
 DESCRIPTION     : Adds the nth element to a heap
 ARGUMENTS       : LIST *L - pointer to the LIST
 				   NODE *walker - pointer to the current walker to be added
 				   int index - index of the current data
 RETURNS         : void
 ================================================================================ */
void reheapUp(LIST *L, NODE* walker, int index){
	NODE* parent= walker;
	int temp;
	while( parent && parent->i != (index-1)/2 ){
		parent=parent->p;
	}
	
	while(parent && index>0 && walker->x > parent->x ){
		
		temp =parent->x;
		parent->x = walker->x;
		walker->x = temp;
		
		walker = parent;
		index= (index-1)/2;
		while( parent && parent->i != (index-1)/2 ){
			parent=parent->p;
		}
	}
}

/* ================================================================================
 FUNCTION        : heapSort
 DESCRIPTION     : Rearranges the contents of the tree to create a max heap after
 				   the last node has been removed.
 ARGUMENTS       : LIST *L - pointer to the LIST
 				   NODE *last - pointer to the current last
 RETURNS         : void
 ================================================================================ */
void reheapDown(LIST *L, NODE *last){
	NODE *parent = L->head;
	NODE *child = L->head->n;
	int childIndex = 1;
	int temp;
	
	while(child && child->i <= last->i && (child->x > parent->x || child->n->x > parent->x) ){
		if( child->i < last->i && (child->x < child->n->x) ){	
			child = child->n;								// Check sibling's value
			childIndex++;
		}
		
		if(child->x > parent->x){
			temp = parent->x;
			parent->x = child->x;
			child->x = temp;
		}
		
		parent = child;
		childIndex=childIndex*2+1;
		
		while(child && child->i != childIndex){
			child=child->n;
		}
	}
}
