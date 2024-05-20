/*============================================================================
 FILE        : main.c
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : contains the main function of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 5/03/2024      Ghemarson   added function details
 ============================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#define MAX_SIZE 10
#include "hash.h"

void mainmenu();
/*============================================================================
 FUNCTION    : main
 DESCRIPTION : main function of the program
 ARGUMENTS   : none
 RETURNS     : int - exit code
 ============================================================================*/
int main()
{
    list *ht = createHashTable();
    int data;
    char c;
    for (;;)
    {
        do
        {
            system("cls");
            mainmenu();
            c = getch();
        }
        while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5');

        switch (c)
        {
        case '1':
            if (ht->count == MAX_SIZE)
            {
                printf("TABLE FULL");
                getch();
                break;
            }
            printf("Enter data to add to table: ");
            scanf("%d", &data);
            insertData(ht, data);
            break;
        case '2':
            if (ht->count == 0)
            {
                printf("NO DATA TO DELETE YET");
                getch();
                break;
            }
            printf("Enter data to delete in table: ");
            scanf("%d", &data);
            deleteNode(ht, data);
            break;
        case '3':
            displayHashTable(ht);
            break;
        case '4':
            if (ht->count == 0)
            {
                printf("NO DATA TO DELETE YET");
                getch();
                break;
            }
            clearHashTable(ht);
            break;
        case '5':
            system("cls");
            printf("T H A N K  Y O U !!!");
            exit(0);
        default:
            printf("INVALID CHOICE! TRY AGAIN");
            getch();
        }
    }
}

/*============================================================================
 FUNCTION    : mainmenu
 DESCRIPTION : displays the mainmenu options and functions of the program
 ARGUMENTS   : none
 RETURNS     : void (No Return)
 ============================================================================*/
void mainmenu()
{
    printf("=================================\n");
    printf("[1] INSERT DATA TO HASH TABLE\n\n");
    printf("[2] DELETE DATA IN HASH TABLE\n\n");
    printf("[3] DISPLAY HASH TABLE\n\n");
    printf("[4] DELETE HASH TABLE\n\n");
    printf("[5] QUIT\n\n");
    printf("=================================\n");
    return;
}
