/*============================================================================
 FILE        : ExpressionTree.c
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : The functions for the expression tree program
 REVISION HISTORY
 Date: 3/30/2024 			By: Ghemarson John D. Nacua		Description: Organizing the main file
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "expressiontree.h"
/*============================================================================
 FUNCTION    : createNode
 DESCRIPTION : Creates a new node for the expression tree with the given key
 ARGUMENTS   : char key - the key value to be stored in the node
 RETURNS     : newNode - pointer to the newly created node
============================================================================*/
NODE* createNode(char key)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*============================================================================
 FUNCTION    : preorder
 DESCRIPTION : Displays the prefix expression of the infix expression tree
 ARGUMENTS   : NODE* root - pointer to the root of the expression tree
 RETURNS     : void
============================================================================*/
void prefix(NODE* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->key);
    prefix(root->left);
    prefix(root->right);

}

/*============================================================================
 FUNCTION    : postorder
 DESCRIPTION : Displays the postfix expression of the infix expression tree
 ARGUMENTS   : NODE* root - pointer to the root of the expression tree
 RETURNS     : void
============================================================================*/
void postfix(NODE* root)
{
    if (root == NULL)
    {
        return;
    }
    postfix(root->left);
    postfix(root->right);
    printf("%c ", root->key);
}

