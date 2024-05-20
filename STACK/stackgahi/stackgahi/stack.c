/*
================================================================================
FILE        : stack.c
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
#include "stack.h"

/*
================================================================================
FUNCTION    : decToHex
DESCRIPTION : converts a decimal value to a hexadecimal value
ARGUMENTS   : int n - interger to be converted
RETURNS     : return hex[n % 16]
================================================================================
*/
char decToHex(int n) {
  char hex[] = "0123456789ABCDEF";
  return hex[n % 16];
}


/*
================================================================================
FUNCTION    : push
DESCRIPTION : creates the list and generates a random number for every array
ARGUMENTS   : struct Stack* stack: This is a pointer to the stack data structure itself.
            : char data: This is the data that needs to be added to the top of the stack.
RETURNS     : none
================================================================================
*/
void push(struct Stack* stack, char data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}


/*
================================================================================
FUNCTION    : pop
DESCRIPTION : creates the list and generates a random number for every array
ARGUMENTS   : struct Stack* stack: This is a pointer to the stack data structure itself.
RETURNS     : return data
================================================================================
*/
char pop(struct Stack* stack) {
  if (stack->top == NULL) {
    printf("Stack Underflow\n");
    exit(1);
  }
  struct Node* temp = stack->top;
  char data = temp->data;
  stack->top = stack->top->next;
  free(temp);
  return data;
}


/*
================================================================================
FUNCTION    : decimalToHexadecimal
DESCRIPTION : converts decimal inputs to hexadecimal inputs
ARGUMENTS   : int decimal
RETURNS     : none
================================================================================
*/
void decimalToHexadecimal(int decimal) {
  struct Stack stack;
  stack.top = NULL;

  while (decimal > 0) {
    int remainder = decimal % 16;
    char hex = decToHex(remainder);
    push(&stack, hex);
    decimal /= 16;
  }

  printf("Stack: \n");
  struct Node* temp = stack.top;
  while (temp) {
    printf("|%c|\n ", temp->data);
    temp = temp->next;
  }

  printf("STACK TOP: %c\n", stack.top->data);

  printf("HEXADECIMAL: ");
  while (stack.top) {
    printf(" %c", pop(&stack));
  }
}

