/*============================================================================
 FILE        : hash.h
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : contains the function prototypes and data structs of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 5/03/2024      Ghemarson   added function prototypes
 ============================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#define MAX_SIZE 10

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct list
{
    struct node **entries;
    int count;
} list;

void menu();

list *createHashTable(void);

void insertData(list *ht, int data);

void searchData(list *ht, int data);

unsigned int hashFunction(int data);

void displayHashTable(list *ht);

void deleteNode(list *ht, int data);

void clearHashTable(list *ht);
