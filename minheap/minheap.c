/*
============================================================================
 FILE        : minheap.c
 AUTHOR      : Desiree Go
               Dhan Jacob Olmilla
               Jame Paul Silmaro
               Vincent Michael Villariza
 DESCRIPTION : Implementation of functions related to min heap operations.
 COPYRIGHT   : 05 May 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"

/*
============================================================================
 FUNCTION    : createNode
 DESCRIPTION : Creates a new node with the given data.
 ARGUMENTS   : int data - The data value for the new node
 RETURNS     : Node* - Pointer to the newly created node
===========================================================================
*/

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*
============================================================================
 FUNCTION    : swap
 DESCRIPTION : Swaps the values of two integers.
 ARGUMENTS   : int* a - Pointer to the first integer
               int* b - Pointer to the second integer
 RETURNS     : void
===========================================================================
*/

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
============================================================================
 FUNCTION    : minHeapify
 DESCRIPTION : Adjusts the min heap property at a given node.
 ARGUMENTS   : Node* root - Pointer to the root node of the subtree to heapify
 RETURNS     : void
===========================================================================
*/

void minHeapify(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    int smallest = root->data;
    Node* smallestNode = root;

    if(root->left != NULL && root->left->data < smallest)
    {
        smallest = root->left->data;
        smallestNode = root->left;
    }

    if(root->right != NULL && root->right->data < smallest)
    {
        smallest = root->right->data;
        smallestNode = root->right;
    }

    if(smallestNode != root)
    {
        swap(&root->data, &smallestNode->data);
        minHeapify(smallestNode);
    }
}

/*
============================================================================
 FUNCTION    : insertNode
 DESCRIPTION : Inserts a new node into the min heap.
 ARGUMENTS   : Node** root - Pointer to the pointer to the root node of
               the heap
               int data    - The data value to be inserted
 RETURNS     : void
===========================================================================
*/

void insertNode(Node** root, int data)
{
    if(*root == NULL)
    {
        *root = createNode(data);
        return;
    }

    if(data <= (*root)->data)
    {
        insertNode(&(*root)->left, data);
    }
    else
    {
        insertNode(&(*root)->right, data);
    }
    minHeapify(*root);
}

/*
============================================================================
 FUNCTION    : findMinNode
 DESCRIPTION : Finds the node with the minimum value in the min heap.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
 RETURNS     : Node* - Pointer to the node with the minimum value
===========================================================================
*/

Node* findMinNode(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

/*
============================================================================
 FUNCTION    : searchNode
 DESCRIPTION : Searches for a node with the given data in the min heap.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
               int data   - The data value to search for
 RETURNS     : Node* - Pointer to the node with the specified data if
               found, otherwise NULL
===========================================================================
*/

Node* searchNode(Node* root, int data)
{
    if(root == NULL || root->data == data)
    {
        return root;
    }

    Node* leftResult = searchNode(root->left, data);
    if(leftResult != NULL)
    {
        return leftResult;
    }
    return searchNode(root->right, data);
}

/*
============================================================================
 FUNCTION    : deleteTree
 DESCRIPTION : Deletes the entire min heap.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
 RETURNS     : void
===========================================================================
*/

void deleteTree(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

/*
============================================================================
 FUNCTION    : deleteMinHeap
 DESCRIPTION : Deletes the entire min heap.
 ARGUMENTS   : Node** root - Pointer to the pointer to the root node
               of the heap
 RETURNS     : void
===========================================================================
*/

void deleteMinHeap(Node** root)
{
    deleteTree(*root);
    *root = NULL;
}

/*
============================================================================
 FUNCTION    : removeRoot
 DESCRIPTION : Removes the root node from the min heap.
 ARGUMENTS   : Node** root - Pointer to the pointer to the root node
               of the heap
 RETURNS     : void
===========================================================================
*/

void removeRoot(Node** root)
{
    if(*root == NULL)
    {
        return;
    }

    Node* lastNode = findLastNode(*root);

    if(*root == lastNode)
    {
        free(*root);
        *root = NULL;
        return;
    }

    (*root)->data = lastNode->data;

    Node* parentNode = getParentNode(*root, lastNode);
    if(parentNode != NULL)
    {
        if(parentNode->right == lastNode)
        {
            free(parentNode->right);
        }
        else
        {
            free(parentNode->left);
        }

        if (parentNode->left == lastNode)
        {
            parentNode->left = NULL;
        }
        else
        {
            parentNode->right = NULL;
        }
    }
    minHeapify(*root);
}

/*
============================================================================
 FUNCTION    : findLastNode
 DESCRIPTION : Finds the last node in the min heap.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
 RETURNS     : Node* - Pointer to the last node
===========================================================================
*/

Node* findLastNode(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    while(root->right != NULL || root->left != NULL)
    {
        if(root->right != NULL)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return root;
}

/*
============================================================================
 FUNCTION    : getParentNode
 DESCRIPTION : Finds the parent node of a given child node in the min heap.
 ARGUMENTS   : Node* root  - Pointer to the root node of the heap
               Node* child - Pointer to the child node
 RETURNS     : Node* - Pointer to the parent node
===========================================================================
*/

Node* getParentNode(Node* root, Node* child)
{
    if(root == NULL || root == child)
    {
        return NULL;
    }

    if (root->left == child || root->right == child)
    {
        return root;
    }

    Node* leftParent = getParentNode(root->left, child);
    if(leftParent != NULL)
    {
        return leftParent;
    }
    return getParentNode(root->right, child);
}

/*
============================================================================
 FUNCTION    : printTree
 DESCRIPTION : Prints the min heap in a tree format.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
               int space  - The space for formatting
 RETURNS     : void
===========================================================================
*/

void printTree(Node* root, int space)
{
    if(root == NULL)
    {
        return;
    }

    space += 5;
    printTree(root->right, space);
    printf("\n");
    for(int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

/*
============================================================================
 FUNCTION    : depthFirstHelper
 DESCRIPTION : Helper function for depth-first traversal of the min heap.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
 RETURNS     : void
===========================================================================
*/

void depthFirstHelper(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    depthFirstHelper(root->left);
    printf("%d ", root->data);
    depthFirstHelper(root->right);
}

/*
============================================================================
 FUNCTION    : depthFirstTraversal
 DESCRIPTION : Performs depth-first traversal of the min heap.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
 RETURNS     : void
===========================================================================
*/

void depthFirstTraversal(Node* root)
{
    printf("Depth-First Traversal: ");
    depthFirstHelper(root);
    printf("\n");
}

/*
============================================================================
 FUNCTION    : breadthFirstTraversal
 DESCRIPTION : Performs breadth-first traversal of the min heap.
 ARGUMENTS   : Node* root - Pointer to the root node of the heap
 RETURNS     : void
===========================================================================
*/

void breadthFirstTraversal(Node* root)
{
    printf("Breadth-First Traversal: ");
    if(root == NULL)
    {
        return;
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while(front < rear)
    {
        Node* current = queue[front++];
        printf("%d ", current->data);

        if(current->left != NULL)
        {
            queue[rear++] = current->left;
        }

        if(current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}
