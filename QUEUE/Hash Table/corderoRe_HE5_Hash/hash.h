/*
============================================================================
FILE : main.c
AUTHOR : Remy Gabriel Cordero
DESCRIPTION : Function prototypes and structures for Hash Table Program
COPYRIGHT : 04 May 2024
============================================================================
*/
#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

#define HSIZE 10
#define DELETED -1

/*
============================================================================
 STRUCTURE   : NODE
 DESCRIPTION : This structure represents a node in a doubly linked list.
 ARGUMENTS   : 
    int data - The data stored in the node.
    struct node *p - A pointer to the previous node in the list.
    struct node *n - A pointer to the next node in the list.
============================================================================
*/
typedef struct node
{
    int data;
    struct node *p, *n;
} NODE;


/*
============================================================================
 STRUCTURE   : LIST
 DESCRIPTION : This structure represents a doubly linked list.
 ARGUMENTS   : 
    int count - The number of nodes in the list.
    NODE *head - A pointer to the first node in the list.
    NODE *tail - A pointer to the last node in the list.
============================================================================
*/
typedef struct list
{
    int count;
    NODE *head, *tail;
} LIST;

extern LIST *hashtable[HSIZE];

/*
============================================================================
 FUNCTION    : hash
 DESCRIPTION : This function calculates the hash value for a given key.
 ARGUMENTS   : int key - The key to be hashed.
 RETURNS     : int - The hash value for the given key.
============================================================================
*/
int hash(int key);

/*
============================================================================
 FUNCTION    : hashMenu
 DESCRIPTION : This function displays the menu for the hash table operations.
 ARGUMENTS   : None
 RETURNS     : none - void
============================================================================
*/
void hashMenu();

/*
============================================================================
 FUNCTION    : insert
 DESCRIPTION : This function inserts a new data into the hash table.
 ARGUMENTS   : int data - The data to be inserted.
 RETURNS     : none - void
============================================================================
*/
void insert(int data);

/*
============================================================================
 FUNCTION    : delete
 DESCRIPTION : This function deletes a data from the hash table.
 ARGUMENTS   : int data - The data to be deleted.
 RETURNS     : none - void
============================================================================
*/
void delete(int data);

/*
============================================================================
 FUNCTION    : display
 DESCRIPTION : This function displays the contents of the hash table.
 ARGUMENTS   : None
 RETURNS     : none - void
============================================================================
*/
void display();

/*
============================================================================
 FUNCTION    : destroy
 DESCRIPTION : This function destroys the hash table and frees up the memory.
 ARGUMENTS   : None
 RETURNS     : none - void
============================================================================
*/
void destroy();

#endif // HASH_H
