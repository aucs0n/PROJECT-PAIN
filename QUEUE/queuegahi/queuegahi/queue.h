/*
================================================================================
FILE        : queue.h
AUTHOR      : Justine Catalan, Wmffre Requieron, Lorenz Soriano
DESCRIPTION : Header files of the search project
COPYRIGHT   : 20 march 2024
REVISION HISTORY
Date: 				By: 		Description:
3/19/2024      Lorenz Soriano   Making of the Code
3/19/2024      Justine Catalan  Fixing bugs
3/20/2024      Wmffre Requieron Documentation
================================================================================
*/
/*
================================================================================
Header Files
================================================================================
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
/*
================================================================================
Function Prototypes
================================================================================
*/
struct Node {
  char data;
  struct Node* next;
};

struct Queue {
  struct Node* front;
  struct Node* rear;
};


struct Node* newNode(char data);
struct Queue* createQueue();
void enqueue(struct Queue* queue, char data);
char dequeue(struct Queue* queue);
int isEmpty(struct Queue* queue);
int length(struct Queue* queue);
void printQueue(struct Queue* queue);

#endif

