#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

typedef struct Node
{
    int x;
    int i;
    int value;
    struct Node *n;
    struct Node *p;
} NODE;

typedef struct list
{
    struct Node *head;
    struct Node *tail;
    int count;
} LIST;

void displayList(LIST *data);
void createList(LIST *data, int Data);
void insertEnd(LIST *data, int Data);
void destroyList(LIST *data);

#endif  // LIST_H
