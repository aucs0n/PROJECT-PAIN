/*============================================================================
 FILE        : main.c
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : contains the main function of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 4/23/2024      Ghemarson   added function details
 4/29/2024      Paul        modified case 4 and 2 if statements
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "avl.h"

/*============================================================================
 FUNCTION    : main
 DESCRIPTION : main function of the program
 ARGUMENTS   : none
 RETURNS     : 0 - exit code
 ============================================================================*/
int main()
{

    treenode *newTree = NULL;
    int choice, i;
    do
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            int numOfNodes, newData;
            printf("How many nodes would you like to add? ");
            scanf("%d", &numOfNodes);
            for(i = 1; i <= numOfNodes; i++)
            {
                printf("Enter data for node #%d: ", i);
                scanf("%d", &newData);
                newTree = insertNode(newTree, newData);
            }
        }

        if(choice == 2)
        {
            int numOfNodes, toDelete;
            printTree(newTree);

                printf("Enter value for node to delete: ");
                scanf("%d", &toDelete);
                if(findNumber(newTree,toDelete))
                {
                    newTree = deleteNode(newTree, toDelete);
                    printf("Deleted Successfully!\n");
                }
                else
                {
                    printf("DATA NOT FOUND IN TREE\n");
                }


        }

        if(choice == 3)
        {
            printf("Preorder: ");
            preOrder(newTree);
            printf("\n");
            printf("Inorder: ");
            inOrder(newTree);
            printf("\n");
            printf("Postorder: ");
            postOrder(newTree);
            printf("\n");
            printTree(newTree);
        }

        if(choice == 4)
        {
            int numOfSearchables, toSearch;

                printf("Enter node to search : ");
                scanf("%d", &toSearch);
                if(findNumber(newTree, toSearch))
                {
                    printf("%d FOUND\n", toSearch);
                }
                else
                {
                    printf("%d NOT FOUND\n", toSearch);
                }

        }
    }while(choice <= 4 && choice >= 1);
    return 0;
}
