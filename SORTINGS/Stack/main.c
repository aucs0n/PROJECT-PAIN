/*
============================================================================
FILE : main.c
AUTHOR : Remy Gabriel Cordero || Ghemarson John Nacua || Vincent Michael Villariza
DESCRIPTION : Create a program that convert decimal number to hexadecimal number using the principle of STACK implementing Linked List.
COPYRIGHT : March 20, 2024
============================================================================
*/

#include "stack.h"

/*
============================================================================
FUNCTION : main
DESCRIPTION : initialize program
ARGUMENTS : none
RETURNS : (no return) void
===========================================================================
*/
int main()
{
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("Decimal: %d\n", decimal);
    printf("STACK\n");
    decimalToHexadecimal(decimal);
    printf("\n");
    return 0;
}
