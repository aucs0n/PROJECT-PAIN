/*============================================================================
 FILE        : stack.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains functions for stack operations
 REVISION HISTORY
 Date: 			By: 		Description:
 3/20/2024		Paul		added file and function details
============================================================================*/

#include"stack.h"

/*============================================================================
 FUNCTION    : push
 DESCRIPTION : adds data to the top of the stack
 ARGUMENTS   : Stack *stack - the stack
                int dec - the data to be added
 RETURNS     : void
============================================================================*/
void push(Stack *stack, int dec)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = dec;
    newNode->next = newNode->prev = NULL;
    if(stack->bottom == NULL)
    {
        stack->bottom = stack->top =  newNode;
    }
    else
    {
        newNode->prev = stack->top;
        stack->top->next = newNode;
        stack->top = newNode;
    }
    stack->count++;
}
/*============================================================================
 FUNCTION    : pop
 DESCRIPTION : removes the data at the top of the stack
 ARGUMENTS   : Stack *stack - the stack
 RETURNS     : void
============================================================================*/
void pop(Stack *stack)
{
    if(stack->top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        Node *temp = stack->top;
        stack->top = stack->top->prev;
        if(stack->top != NULL)
        {
            stack->top->next = NULL;
        }
        free(temp);
        stack->count--;
        return;
    }
}
/*============================================================================
 FUNCTION    : top
 DESCRIPTION : prints the data at the top of the stack
 ARGUMENTS   : Stack *stack - the stack
 RETURNS     : void
============================================================================*/
void top(Stack *stack)
{
    if(stack->top == NULL)
    {
        printf("There is no stack yet");
        return;
    }
    else
    {
        printf("\nSTACK TOP: %d\n", stack->top->data);
    }
}