/*
================================================================================
FILE        : stack.h
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
#ifndef STACK_H
#define STACK_H

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

struct Stack {
  struct Node* top;
};

// function prototypes
void push(struct Stack* stack, char data);
char pop(struct Stack* stack);
char decToHex(int n);

#endif
