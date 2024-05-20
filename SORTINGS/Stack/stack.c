/*
============================================================================
FILE : stack.c
AUTHOR : Remy Gabriel Cordero || Ghemarson John Nacua || Vincent Michael Villariza
DESCRIPTION : File that contains all the functions to be used on the stack program.
COPYRIGHT : March 20, 2024
============================================================================
*/

#include "stack.h"

/*
============================================================================
FUNCTION : push
DESCRIPTION : Puts the current number input on the top of the linked list.
ARGUMENTS :
struct Node **top: Pointer that points to the front of the linked list.
int data: Number input
RETURNS : void
===========================================================================
*/
void push(struct Node **top, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

/*
============================================================================
FUNCTION : pop
DESCRIPTION : Removes the topmost number from the stack.
ARGUMENTS :
struct Node **top: Pointer that points to the value on front of the linked list.
RETURNS : void
===========================================================================
*/
int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow.\n");
        exit(1);
    }
    struct Node *temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

/*
============================================================================
FUNCTION : Displaystack
DESCRIPTION : Displays data.
ARGUMENTS :
struct Node **top: Pointer that points to the front of the linked list.
int data: Number input
RETURNS : void
===========================================================================
*/
void displayStack(struct Node *top)
{
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
}

/*
============================================================================
FUNCTION : decimalToHexadecimal
DESCRIPTION : Converts the decimal number input to a hexadecimal
ARGUMENTS :
struct Node **top: Pointer that points to the front of the linked list.
int decimal: Decimal number that gets converted to hexadecimal.
RETURNS : void
===========================================================================
*/
void decimalToHexadecimal(int decimal)
{
    struct Node *stack = NULL;

    if (decimal == 0)
    {
        printf("0");
        return;
    }

    while (decimal != 0)
    {
        int remainder = decimal % 16;
        push(&stack, remainder);
        decimal /= 16;
    }

    displayStack(stack);
    printf("STACK TOP: %d\n", stack->data);

    printf("HEXADECIMAL: ");
    while (stack != NULL)
    {
        int digit = pop(&stack);
        if (digit < 10)
            printf("%d", digit);
        else
            printf("%c", digit - 10 + 'A');
    }
}
