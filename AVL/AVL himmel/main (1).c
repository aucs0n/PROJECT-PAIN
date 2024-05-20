#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "avlHeader.h"

int main(){

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
            printf("How many nodes would you like to delete? ");
            scanf("%d", &numOfNodes);
            printTree(newTree);
            for(i = 1; i <= numOfNodes; i++)
            {
                printf("Enter value for node #%d to delete: ", i);
                scanf("%d", &toDelete);
                newTree = deleteNode(newTree, toDelete);
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
            printf("How many nodes would you like to search? ");
            scanf("%d", &numOfSearchables);
            for(i = 1; i <= numOfSearchables; i++)
            {
                printf("Enter node to search #%d: ", i);
                scanf("%d", &toSearch);
                printf("%d (%d)\n", toSearch, findNumber(newTree, toSearch));
            }
        }
    }while(choice <= 4 && choice >= 1);
    return 0;
}