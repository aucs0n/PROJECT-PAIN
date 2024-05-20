#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bstHeader.h"

void printMenu(){

    printf("[1] Add nodes\n");
    printf("[2] Delete nodes\n");
    printf("[3] Show tree\n");
    printf("[4] Search tree\n");
    printf("[5] Exit\n");
}

treenode *createNode(int value){

    treenode *newNode = (treenode*) malloc(sizeof(treenode));
    if(newNode != NULL)
    {
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
}

treenode *maxValueNode(treenode *node){

    treenode *current = node;
    while (current->right != NULL) // loop down to find the rightmost leaf in the left subtree 
        current = current->right;
    return current;
}

treenode *insertNode(treenode *root, int value){

    if(root == NULL)
        root = createNode(value);
    if(value < root->value)
        root->left = insertNode(root->left, value);
    if(value > root->value)
        root->right = insertNode(root->right, value);
    if(value == root->value)
        return root;
 
    return root;
}

treenode *deleteNode(treenode *root, int value){
 
    if(root == NULL)
        return root;
    if(value < root->value)
        root->left = deleteNode(root->left, value);
    else if(value > root->value)
        root->right = deleteNode(root->right, value);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) ) // Delete case with one child
        {
            treenode *temp = root->left ? root->left : root->right; // Assign non-null child to temp
 
            if (temp == NULL) // No child case
            {
                temp = root; // Temp assigned to node to be deleted
                root = NULL; // Current node is set to null
            }
            else // One child case
             *root = *temp; // Move content of non-null child to current node
            free(temp); // Free non-null child
        }
        else // Delete case with two children
        {
            treenode *temp = maxValueNode(root->left); // Find biggest value in left subtree (rightmost in left)
            root->value = temp->value; // Move smallest value to current node
            root->left = deleteNode(root->left, temp->value); // Delete node containing max value
        }
    }
 
    return root;
}

bool findNumber(treenode *root, int value){

    if(root == NULL)
        return false;
    if(value == root->value)
        return true;
    if(value < root->value)
        return findNumber(root->left, value);
    if(value > root->value)
        return findNumber(root->right, value);
}

void preOrder(treenode *root){

    if(root == NULL)
        return;
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(treenode *root){

    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}

void postOrder(treenode *root){

    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}

int printTreeBackend(treenode *tree, int is_left, int offset, int depth, char space[20][255])
{
    char buff[20];
    int width = 5;

    if (!tree) // Base case.
    {
        return 0;  
    }
    
    sprintf(buff, "(%3d)", tree->value); // change data type depending on type of value to be printed.

    int left  = printTreeBackend(tree->left,  1, offset,                depth + 1, space); 
    int right = printTreeBackend(tree->right, 0, offset + left + width, depth + 1, space); 

    #ifdef COMPACT
        for (int i = 0; i < width; i++)
        {
            space[depth][offset + left + i] = b[i];
        }

        if (depth && is_left) 
        {

            for (int i = 0; i < width + right; i++)
            {
                space[depth - 1][offset + left + width/2 + i] = '-';
            }

            space[depth - 1][offset + left + width/2] = '.';
        } 
        else if (depth && !is_left) 
        {

            for (int i = 0; i < left + width; i++)
            {
                space[depth - 1][offset - width/2 + i] = '-';
            }

            space[depth - 1][offset + left + width/2] = '.';
        }
    #else
        for (int i = 0; i < width; i++)
        {
            space[2 * depth][offset + left + i] = buff[i];
        }

        if (depth && is_left)
        {

            for (int i = 0; i < width + right; i++)
            {
                space[2 * depth - 1][offset + left + width/2 + i] = '-';
            }

            space[2 * depth - 1][offset + left + width/2] = '+';
            space[2 * depth - 1][offset + left + width + right + width/2] = '+';
        } 
        else if (depth && !is_left) 
        {

            for (int i = 0; i < left + width; i++)
            {
                space[2 * depth - 1][offset - width/2 + i] = '-';
            }

            space[2 * depth - 1][offset + left + width/2] = '+';
            space[2 * depth - 1][offset - width/2 - 1] = '+';
        }
    #endif

    return left + width + right;
}

void printTree(treenode *tree)
{
    char space[20][255];

    for (int i = 0; i < 20; i++)
    {
        sprintf(space[i], "%80s", " "); 
    }

    printTreeBackend(tree, 0, 0, 0, space);

    for (int i = 0; i < 20; i++)
    {
        printf("%s\n", space[i]);
    }
}