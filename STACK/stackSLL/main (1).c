#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stackSLL.h"

extern int nodeCount;

int main(){

    NODE *head = NULL, *new_node;
    char choice, name[30], number[15];
    int position, choiceOfChange;
    clearScr();
    printf("Welcome to Himmel Appenders and Deleters STACK!!\n\n");
    printf("Loading...\n\n");
    pause();
    clearScr();
    do{
        showMenu();
        printf("Choice : ");
        scanf(" %c", &choice);
        while(choice < 'a' || choice > 'e')
        {
            printf("You have entered an invalid choice. Please try again.\n");
            printf("Choice : ");
            scanf(" %c", &choice);
        }
        if(choice == 'a')
        {
            clearScr();
            new_node = createNode();
            if(new_node == NULL)
                continue;
            else
            {
                printf("Name : ");
                scanf(" %[^\n]s", name);
                printf("Number: ");
                scanf(" %[^\n]s", number);
                assign(&new_node, name, number);
                push(new_node, &head);
            }
        }

        else if(choice == 'b')
        {
            clearScr();
            showData(head);
            printf("Press ENTER key to continue...");
            fflush(stdin);
            getchar();
        }

        else if(choice == 'c')
        {
            clearScr();
            peek(head);
            printf("Press ENTER key to continue...");
            fflush(stdin);
            getchar();
        }

        else if(choice == 'd')
        {
            clearScr();
            showData(head);
            if(nodeCount > 0)
            {
                printf("Record to be removed : ");
                scanf("%d", &position);
                while(position > nodeCount || position < 1)
                {
                    printf("You have entered an invalid record. Please try again.\n");
                    printf("Record to be removed : ");
                    scanf("%d", &position);
                }
                pop(&head, position);
            }
        }

    if(choice != 'e')
    {
        pause();
        clearScr();
    }
    else
    {
        clearScr();
        printf("Thank you! See you next time!\n\n");
        pause();
        clearScr();
    }
    }while(choice != 'e');
    return 0;
}
