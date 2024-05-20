/*============================================================================
 FILE        : stack.h
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : struct declarations and function prototypes for the program
 REVISION HISTORY
 Date: 			By: 		Description:
 3/20/2024		Paul		added file and function details
============================================================================*/

#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>      // included header files
#include<conio.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next,*prev;    // Node declaration
 
}Node;

typedef struct stack
{
    int count;                  // stack declaration
    struct node *top, *bottom;
}Stack;


void push(Stack *stack, int dec);
void pop(Stack *stack);              // function prototypes
void top(Stack *stack); 

#endif