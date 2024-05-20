/* ===============================================================================
 FILE     	 : list.c
 AUTHORS     : himmel
 DESCRIPTION : Handles the list structure: creation, deletion, and sorting
 COPYRIGHT   : 16 March 2021
 =============================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "list.h"

/* ================================================================================
 FUNCTION        : displayList
 DESCRIPTION     : Displays the list containing the data.
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ */
void displayList(LIST *L){
	NODE *walker =L->head;
	
	if(walker==NULL){
		printf("\n LIST IS EMPTY \n");
	}else{
		printf("\n LIST		: [ ");
		while(walker){
			printf("%4d", walker->x);
			walker = walker->n;
		}
		printf("]\n");
	}
	
}

/* ================================================================================
 FUNCTION        : createList
 DESCRIPTION     : Creates the list of data.
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ */
void createList(LIST *L){
	int i, n;
	
	if((L->count)>0){
		destroyList(L);
	}
	/*
	time_t t;
	srand((unsigned) time(&t));
	
	for(i=0;i<10;i++){
		n = rand() % 101;
		insertEnd(L, n);
	}*/
	
	insertEnd(L, 60);
	insertEnd(L, 22);
	insertEnd(L, 58);
	insertEnd(L, 46);
	insertEnd(L, 34);
	insertEnd(L, 68);
	insertEnd(L, 4);
	insertEnd(L, 9);
}

/* ================================================================================
 FUNCTION        : insertEnd
 DESCRIPTION     : Inserts a specific data at the end of the list. 
 ARGUMENTS       : 	LIST *L - pointer to the LIST
 					int data - the data to be added to the list
 RETURNS         : void
 ================================================================================ */
void insertEnd(LIST *L, int data){
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->i =L->count;
	newNode->x = data;
	newNode->n=NULL;
	newNode->p=NULL;
	
	if(L->count==0){
		L->head=newNode;
		L->tail=L->head;
	}else{
		L->tail->n =newNode;
		newNode->p=L->tail;
		L->tail=newNode;
	}
	(L->count)++;
}

/* ================================================================================
 FUNCTION        : destroyList
 DESCRIPTION     : Deletes the list.
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ */
void destroyList(LIST *L){
	int i;
	NODE *walker = L->tail;
	
	
	while(L->head!=L->tail){
		L->tail=L->tail->p;
		free(walker);
		walker = L->tail;	
	}
	
	free(L->head);
	
	L->head=NULL;
	L->tail=NULL;
	L->count=0;
}

