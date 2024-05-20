#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queueDLL.h"

extern int nodeCount;

int main(){

    NODE *head = NULL, *new_node;
    char choice, name[30], number[15];
    int position, choiceOfChange;
    clearScr();
    printf("WELCOME TO HIMMEL appenders and deleters queue\n\n");
    printf("Loading...\n\n");
    pause();
    clearScr();
    do{
        showMenu();
        printf("Choice : ");
        scanf(" %c", &choice);
        while(choice < 'a' || choice == 'c' || choice > 'e')
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
                enQueue(new_node, &head);
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

        else if(choice == 'd')
        {
            clearScr();
            deQueue(&head);
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

