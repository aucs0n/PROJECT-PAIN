/*============================================================================
 FILE        : ExpressionTree.h
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : The header files for ExpressionTree.h and contains function declarations for the program
 REVISION HISTORY
 Date: 3/30/2024 			By: Ghemarson John D. Nacua		Description: Organizing the main file
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H


typedef struct node
{
    char key;
    struct node *left, *right;
}NODE;


typedef struct tree
{
    NODE *root;
}TREE;


NODE* createNode(char key);

void prefix(NODE* root);

void postfix(NODE* root);

#endif
