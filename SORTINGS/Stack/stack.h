/*
============================================================================
FILE : stack.h
AUTHOR : Remy Gabriel Cordero || Ghemarson John Nacua || Vincent Michael Villariza
DESCRIPTION : File that contains all the function prototypes to be used on the stack program.
COPYRIGHT : March 20, 2024
============================================================================
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top, int data);
int pop(struct Node **top);
void displayStack(struct Node *top);
void decimalToHexadecimal(int decimal);

#endif // STACK_H
