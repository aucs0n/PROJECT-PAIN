/*============================================================================
 FILE        : main.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains main function of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 3/20/2024		Paul		added file and function details
 3/20/2024      Vaun        added conversion to hexadecimal operations
============================================================================*/

#include "stack.h"

/*============================================================================
 FUNCTION    : main
 DESCRIPTION : main function of the program
 ARGUMENTS   : none
 RETURNS     : 0 - exit code
============================================================================*/
int main()
{

    for (;;)
    {
        Stack *stack = malloc(sizeof(Stack));
        stack->top = stack->bottom = NULL;
        stack->count = 0;
        int i = 0;
        int dec;
        char str[100];
        printf("Enter a Decimal: ");
        scanf("%d", &dec);

        while (dec > 0)
        {
            int remainder = dec % 16;
            char hexDigit;

            if (remainder < 10)
                hexDigit = remainder + '0';
            else
                hexDigit = remainder - 10 + 'A';

            dec /= 16;
            str[i] = hexDigit;
            i++;
            push(stack, remainder);
        }

        Node *temp = stack->top;
        while (temp != NULL)
        {
            printf("| %d |\n", temp->data);
            temp = temp->prev;
        }
        top(stack);
        printf("\nHEXADECIMAL: ");
        for (int x = (strlen(str) - 1); x >= 0; x--)
        {
            printf("%c", str[x]);
        }
        
        printf("\n");
        str[0] = '\0';
    

        free(stack);
    }
}
