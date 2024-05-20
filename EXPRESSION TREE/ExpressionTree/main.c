/*============================================================================
 FILE        : main.c
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : A program that Implement an Expression Tree from Infix expression
               and Display Prefix and Postfix evaluation expression.
 REVISION HISTORY
 Date: 3/20/2024 			By: Ghemarson John D. Nacua		Description: Organizing the main file
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "expressiontree.h"

/*============================================================================
 FUNCTION    : main
 DESCRIPTION : Executes the main program
 ARGUMENTS   : none
 RETURNS     : int - exit codes
============================================================================*/
int main()
{
    printf("\t======== E X P R E S S I O N   T R E E ========\n\n");
    // [Infix] A + B * C + D
    TREE treeone;
    treeone.root = createNode('+');

    treeone.root->left = createNode('+');

    treeone.root->right = createNode('D');

    treeone.root->left->left = createNode('A');

    treeone.root->left->right = createNode('*');

    treeone.root->left->right->left = createNode('B');

    treeone.root->left->right->right = createNode('C');

    printf("\t\t [Infix] A + B * C + D\n\n");

    printf("\t\t Prefix: ");
    prefix(treeone.root);
    printf("\n\n");

    printf("\t\t Postfix: ");
    postfix(treeone.root);
    printf("\n\n\n");

    // [Infix] (A + B) * (C + D)
    TREE treetwo;
    treetwo.root = createNode('*');

    treetwo.root->left = createNode('+');

    treetwo.root->left->left = createNode('A');

    treetwo.root->left->right = createNode('B');

    treetwo.root->right = createNode('+');

    treetwo.root->right->left = createNode('C');

    treetwo.root->right->right = createNode('D');

    printf("\t\t [Infix] (A + B) * (C + D)\n\n");

    printf("\t\t Prefix: ");
    prefix(treetwo.root);
    printf("\n\n");

    printf("\t\t Postfix: ");
    postfix(treetwo.root);
    printf("\n\n\n");

    // [Infix] A * B + C * D
    TREE treethree;
    treethree.root = createNode('+');

    treethree.root->left = createNode('*');

    treethree.root->left->left = createNode('A');

    treethree.root->left->right = createNode('B');

    treethree.root->right = createNode('*');

    treethree.root->right->left = createNode('C');

    treethree.root->right->right = createNode('D');

    printf("\t\t [Infix] A * B + C * D\n\n");

    printf("\t\t Prefix: ");
    prefix(treethree.root);
    printf("\n\n");

    printf("\t\t Postfix: ");
    postfix(treethree.root);
    printf("\n\n\n");

    // [Infix] A + B + C + D
    TREE treefour;
    treefour.root = createNode('+');

    treefour.root->left = createNode('+');

    treefour.root->left->left = createNode('+');

    treefour.root->left->left->left = createNode('A');

    treefour.root->left->left->right = createNode('B');

    treefour.root->left->right = createNode('C');

    treefour.root->right = createNode('D');

    printf("\t\t [Infix] A + B + C + D\n\n");

    printf("\t\t Prefix: ");
    prefix(treefour.root);
    printf("\n\n");

    printf("\t\t Postfix: ");
    postfix(treefour.root);
    printf("\n\n");
    printf("\t================================================\n\n");

    return 0;
}

