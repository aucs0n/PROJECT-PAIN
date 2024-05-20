/*
============================================================================
 FILE        : main.c
 AUTHOR      : Desiree Go
               Dhan Jacob Olmilla
               Jame Paul Silmaro
               Vincent Michael Villariza
 DESCRIPTION : This file contains the main function and the user interface
               for interacting with the min heap operations.
 COPYRIGHT   : 05 May 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : The main function presents a menu for interacting with the
               min heap operations.
 ARGUMENTS   : None
 RETURNS     : int - 0 on successful completion
===========================================================================
*/

int main()
{
    Node* root = NULL;
    int data;
    char choice;

    do
    {
        printf("\n-- Min Heap Operations --\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Display Min Heap\n");
        printf("5. Display Depth-First Traversal\n");
        printf("6. Display Breadth-First Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case '1':
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(&root, data);
                minHeapify(root);
                printTree(root,0);
                break;
            case '2':
                removeRoot(&root);
                minHeapify(root);
                printf("Root node deleted.");
                printTree(root,0);
                break;
            case '3':
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL)
                {
                    printf("Node found.\n");
                }
                else
                {
                    printf("Node not found.\n");
                }
                break;
            case '4':
                printf("Display Min Heap:\n");
                printTree(root,0);
                printf("\n");
                break;
            case '5':
                depthFirstTraversal(root);
                break;
            case '6':
                breadthFirstTraversal(root);
                break;
            case '7':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '7');

    return 0;
}
