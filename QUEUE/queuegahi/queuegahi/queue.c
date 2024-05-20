/*
================================================================================
FILE        : queue.c
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
#include "queue.h"


struct Node* newNode(char data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}


struct Queue* createQueue() {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = queue->rear = NULL;
  return queue;
}

/*
================================================================================
FUNCTION    : enqueue
DESCRIPTION : Adds an element to the back of the queue.
ARGUMENTS   : struct Queue queue:* This is a pointer to the queue structure itself.
            : char data: This is the data element that needs to be added to the back of the queue.
RETURNS     : none(void)
================================================================================
*/
void enqueue(struct Queue* queue, char data) {
  struct Node* new_node = newNode(data);
  if (isEmpty(queue)) {
    queue->front = queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
}

/*
================================================================================
FUNCTION    : dequeue
DESCRIPTION : Removes and returns the element from the front of the queue.
ARGUMENTS   : struct Queue queue:* This is a pointer to the queue structure itself.
RETURNS     : return data
================================================================================
*/
char dequeue(struct Queue* queue) {
  if (isEmpty(queue)) {
    printf("Error: Queue is empty\n");
    exit(1);
  }
  struct Node* temp = queue->front;
  char data = temp->data;
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  free(temp);
  return data;
}

/*
================================================================================
FUNCTION    : isEmpty
DESCRIPTION : Checks if the queue is empty
ARGUMENTS   : struct Queue queue:* This is a pointer to the queue structure itself.
RETURNS     : return queue
================================================================================
*/
int isEmpty(struct Queue* queue) {
  return queue->front == NULL;
}

/*
================================================================================
FUNCTION    : length
DESCRIPTION : determines the length of a given string
ARGUMENTS   : struct Queue queue:* This is a pointer to the queue structure itself.
RETURNS     : return count
================================================================================
*/
int length(struct Queue* queue) {
  struct Node* current = queue->front;
  int count = 0;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

/*
================================================================================
FUNCTION    : printQueue
DESCRIPTION : prints the string in a queue format
ARGUMENTS   : struct Queue queue:* This is a pointer to the queue structure itself.
RETURNS     : none(void)
================================================================================
*/
void printQueue(struct Queue* queue) {
  struct Node* temp = queue->front;
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
