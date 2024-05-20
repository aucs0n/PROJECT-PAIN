/*
============================================================================
FILE : main.c
AUTHOR : Remy Gabriel Cordero
DESCRIPTION : A Hash Table that uses Linear Probing Closed Hashing with LIST ADTs and operations
COPYRIGHT : 04 May 2024
============================================================================
*/
#include "hash.h"

LIST *hashtable[HSIZE];

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
    int choice, data, intCheck;

    for (int i = 0; i < HSIZE; i++)
    {
        hashtable[i] = NULL;
    }

    printf("Hash Table Program");
    while (1)
    {
        hashMenu();
        intCheck = scanf("%d", &choice);

        if (intCheck != 1)
        {
            while (getchar() != '\n')

                printf("Invalid input! Please enter a number.\n");

            continue;
        }

        switch (choice)
        {
        case 1: // Insert
            printf("Enter data to insert: ");
            intCheck = scanf("%d", &data);
            if (intCheck != 1)
            {
                while (getchar() != '\n')
                printf("Invalid input! Please enter a none negative number!\n");
            }
            else if (data < 0)
            {
                printf("Invalid input! Please enter a none negative number!\n");
            }
            else
            {
                insert(data);
            }
            break;
        case 2: // Delete
            printf("Enter data to delete: ");
            intCheck = scanf("%d", &data);
            if (intCheck != 1)
            {
                while (getchar() != '\n')
                printf("Invalid input! Please enter a none negative number!\n");
            }
            else if (data < 0)
            {
                printf("Invalid input! Please enter a none negative number!\n");
            }
            else
            {
                delete(data);
            }
            break;
        case 3: // Display
            display();
            break;
        case 4: // Destroy
            destroy();
            break;
        case 5: // Exit
            printf("Exiting...");
            exit(0);
        default: // Invalid
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
