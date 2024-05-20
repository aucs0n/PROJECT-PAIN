/* ===============================================================================
 FILE     	 : list.h
 AUTHORS     : himmel
 DESCRIPTION : Data structures and header files for list.c
 COPYRIGHT   : 16 March 2021
 =============================================================================== */

#ifndef LIST_H
#define LIST_H

//DATA STRUCTURES

typedef struct node{
	int x;
	int i;
	struct node *n;
	struct node *p;
}NODE;

typedef struct list{
	struct node *head;
	struct node *tail;
	int count;
}LIST;

//Function prototypes
void displayList(LIST *L);
void createList(LIST *L);
void insertEnd(LIST *L, int data);
void destroyList(LIST *L);

#endif
