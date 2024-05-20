/*
============================================================================
 FILE        : main.c
 AUTHOR      : himmel
 DESCRIPTION : initializes all functions for strand sort program
 COPYRIGHT   : March 4 2024
============================================================================
*/

#include "list.h"
#include "sort.h"
#define TRUE 1
#define FALSE 0

void displayMenu();

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Executes the main program
 ARGUMENTS   : none
 RETURNS     : int - exit codes
============================================================================
*/

int main()
{
    char ch;
    int Data;
    bool start = FALSE;

    LIST *data = (LIST *)malloc(sizeof(LIST));
    data->head = NULL;
    data->tail = NULL;
    data->count = 0;

    for (;;)
    {
        displayMenu();
        ch = getch();

        switch (ch)
        {
        case '1':
        {
            printf("\nHow many values: ");
            if (scanf("%d", &Data) == 1 && Data > 1 && Data < 11)
            {
                createList(data, Data);
                start = TRUE;
                printf("\nLIST CREATED\n\n");
            }
            else
            {
                printf("\nNot a valid number\n\n");
                fflush(stdin);
            }
            break;
        }
        case '2':
        {
            if (start == TRUE)
            {
                displayList(data);
            }
            else
            {
                printf("\nPlease create list first");
            }
            break;
        }
        case '3':
        {
            if (start == TRUE)
            {
                printf("\nSorting Data:\n");
                strandSort(data);
                printf("\nList Sorted\n\n");
            }
            else
            {
                printf("\nPlease create list first");
            }
            break;
        }
        case '0':
        {
            if (start == TRUE)
            {
                destroyList(data);
            }
            free(data);
            exit(0);
            break;
        }
        default:
        {
            fflush(stdin);
        }
        }
    }

    return 0;
}

/*
 ==================================================================================
 FUNCTION        : displayMenu
 DESCRIPTION     : Displays the main menu of the program
 ARGUMENTS       : none
 RETURNS         : void
 ==================================================================================
*/

void displayMenu()
{
    printf("[STRAND SORTER] \n");
    printf("[1]- Create List \n");
    printf("[2]- Display List \n");
    printf("[3]- Sort \n");
    printf("[0]- Exit \n");
}
