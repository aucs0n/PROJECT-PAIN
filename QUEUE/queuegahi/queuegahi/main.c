/*
================================================================================
FILE        : main.c
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
#include <stdio.h>
#include <string.h>
#include "queue.h"
/*
================================================================================
FUNCTION    : main
DESCRIPTION : executes main program
ARGUMENTS   : string - user input
RETURNS     : int - exit codes
================================================================================
*/
int main() {
  char string[100];

  printf("Enter a string: ");
  fgets(string, 100, stdin);
  string[strcspn(string, "\n")] = '\0';

  struct Queue* queue = createQueue();

  for (int i = 0; i < strlen(string); i++) {
    enqueue(queue, string[i]);
  }

  printf("\nSTRING: %s\n", string);
  printf("QUEUE: ");
  printQueue(queue);

  printf("\nQUEUE FRONT: %c\n", queue->front->data);
  printf("QUEUE REAR: %c\n", queue->rear->data);
  printf("LENGTH OF STRING: %d\n", length(queue));


  while (!isEmpty(queue)) {
    dequeue(queue);
  }
  free(queue);

  return 0;
}
