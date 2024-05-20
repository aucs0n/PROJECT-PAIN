

/*============================================================================
 FILE        : avl.c
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : contains the operations of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 4/23/2024      Ghemarson   added function details
 4/29/2024      Paul        added function details
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "avl.h"

/*============================================================================
 FUNCTION    : printMenu
 DESCRIPTION : prints the menu
 ARGUMENTS   : none
 RETURNS     : void
 ============================================================================*/
void printMenu(){

    printf("[1] Add nodes\n");
    printf("[2] Delete nodes\n");
    printf("[3] Show tree\n");
    printf("[4] Search tree\n");
    printf("[5] Exit\n");
}

/*============================================================================
 FUNCTION    : createNode
 DESCRIPTION : creates a node
 ARGUMENTS   : int value - the value to put in node
 RETURNS     : newNode - the new Node
 ============================================================================*/
treenode *createNode(int value){

    treenode *newNode = (treenode*) malloc(sizeof(treenode));
    if(newNode != NULL)
    {
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;
    }
}

/*============================================================================
FUNCTION : max
DESCRIPTION : Returns the maximum of two integers.
ARGUMENTS : int a - first integer
int b - second integer
RETURNS : int - the maximum of the two integers
============================================================================*/
int max(int a, int b){

    return (a > b)? a : b;
}

/*============================================================================
 FUNCTION    : height
 DESCRIPTION : Calculates the height of a given node in the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
 RETURNS     : int - height of the subtree rooted at the given node
 ============================================================================*/

int height(treenode *root){

    if (root == NULL)
        return 0;
    return 1+max(height(root->left), height(root->right));
}

/*============================================================================
 FUNCTION    : getBalance
 DESCRIPTION : Calculates the balance factor of a given node in the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
 RETURNS     : int - balance factor of the subtree rooted at the given node
 ============================================================================*/

int getBalance(treenode *root){

    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

/*============================================================================
 FUNCTION    : leftRotate
 DESCRIPTION : Performs a left rotation on the given node in the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
 RETURNS     : treenode* - pointer to the new root after rotation
 ============================================================================*/

treenode *leftRotate(treenode *root){

    treenode *rightChild = root->right;
    treenode *minInRS = rightChild->left;

    // Perform rotation
    rightChild->left = root;
    root->right = minInRS;

    //  Update heights
    root->height = height(root);
    rightChild->height = height(rightChild);

    // Return new root
    return rightChild;
}
/*============================================================================
 FUNCTION    : rightRotate
 DESCRIPTION : Performs a right rotation on the given node in the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
 RETURNS     : treenode* - pointer to the new root after rotation
 ============================================================================*/

treenode *rightRotate(treenode *root){

    treenode *leftChild = root->left;
    treenode *maxInLS = leftChild->right;

    // Perform rotation
    leftChild->right = root;
    root->left = maxInLS;

    // Update heights
    root->height = height(root);
    leftChild->height = height(leftChild);

    // Return new root
    return leftChild;
}
/*============================================================================
 FUNCTION    : rotateCheck
 DESCRIPTION : Checks and performs rotations if necessary to balance the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
               int value - value being inserted into the tree
               int balance - balance factor of the current node
 RETURNS     : treenode* - pointer to the root of the balanced subtree
 ============================================================================*/

treenode *rotateCheck(treenode *root, int value, int balance){

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case (More nodes on the left subtree)
    if (balance > 1 && value < root->left->value)
        return rightRotate(root);

    // Left Right Case (More nodes on the left subtree and at the same time, left subtree has more nodes on its right subtree)
    if (balance > 1 && value > root->left->value)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case (More nodes on the right subtree)
    if (balance < -1 && value > root->right->value)
        return leftRotate(root);

    // Right Left Case (More nodes on the right subtree and at the same time, right subtree has more nodes on its left subtree)
    if (balance < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
/*============================================================================
 FUNCTION    : maxValueNode
 DESCRIPTION : Finds the node with the maximum value in a subtree.
 ARGUMENTS   : treenode *node - pointer to the root of the subtree
 RETURNS     : treenode* - pointer to the node with the maximum value
 ============================================================================*/

treenode *maxValueNode(treenode *node){

    treenode *current = node;
    while (current->right != NULL) // loop down to find the rightmost leaf in the left subtree
        current = current->right;
    return current;
}
/*============================================================================
 FUNCTION    : insertNode
 DESCRIPTION : Inserts a new node with the given value into the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
               int value - value to be inserted
 RETURNS     : treenode* - pointer to the root of the updated subtree
 ============================================================================*/

treenode *insertNode(treenode *root, int value){

    if(root == NULL)
        root = createNode(value);
    if(value < root->value)
        root->left = insertNode(root->left, value);
    if(value > root->value)
        root->right = insertNode(root->right, value);
    if(value == root->value)
        return root;

    root->height = height(root); // Update height for root
    int balance = getBalance(root); // Find balance factor to check if balancing is needed
    root = rotateCheck(root, value, balance);

    return root;
}
/*============================================================================
 FUNCTION    : deleteNode
 DESCRIPTION : Deletes the node with the given value from the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
               int value - value to be deleted
 RETURNS     : treenode* - pointer to the root of the updated subtree
 ============================================================================*/

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

    if (root == NULL) // Return if tree only has one node after deletion
      return root;

    root->height = height(root); // Update height for root
    int balance = getBalance(root); // Find balance factor to check if balancing is needed
    root = rotateCheck(root, value, balance);

    return root;
}
/*============================================================================
 FUNCTION    : findNumber
 DESCRIPTION : Searches for a value in the AVL tree.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
               int value - value to be searched
 RETURNS     : bool - true if value is found, false otherwise
 ============================================================================*/

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
/*============================================================================
 FUNCTION    : preOrder
 DESCRIPTION : Performs pre-order traversal of the AVL tree and prints the nodes.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
 RETURNS     : void
 ============================================================================*/

void preOrder(treenode *root){

    if(root == NULL)
        return;
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}
/*============================================================================
 FUNCTION    : inOrder
 DESCRIPTION : Performs in-order traversal of the AVL tree and prints the nodes.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
 RETURNS     : void
 ============================================================================*/

void inOrder(treenode *root){

    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}

/*============================================================================
 FUNCTION    : postOrder
 DESCRIPTION : Performs post-order traversal of the AVL tree and prints the nodes.
 ARGUMENTS   : treenode *root - pointer to the root of the subtree
 RETURNS     : void
 ============================================================================*/

void postOrder(treenode *root){

    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}

/*============================================================================
 FUNCTION    : printTreeBackend
 DESCRIPTION : Prints the AVL tree in a visually appealing format (backend function).
 ARGUMENTS   : treenode *tree - pointer to the root of the AVL tree
               int is_left - flag indicating whether the current node is a left child
               int offset - horizontal offset for printing
               int depth - depth of the current node in the tree
               char space[20][255] - 2D array to store the tree structure
 RETURNS     : int - total width occupied by the current subtree
 ============================================================================*/

int printTreeBackend(treenode *tree, int is_left, int offset, int depth, char space[20][255]){
    char buff[20];
    int width = 5;

    if (!tree)
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
/*============================================================================
 FUNCTION    : printTree
 DESCRIPTION : Prints the AVL tree in a visually appealing format.
 ARGUMENTS   : treenode *tree - pointer to the root of the AVL tree
 RETURNS     : void
 ============================================================================*/

void printTree(treenode *tree){
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
