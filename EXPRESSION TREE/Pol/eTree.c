/*============================================================================
 FILE        : eTree.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains main function of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 2/14/2024		Paul		added file and function details
 2/15/2024      Paul        transferred displayList() function to main
 2/15/2024      Desiree     modified main function and corrected spellings
============================================================================*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char key;
    struct node *left, *right;
} NODE;

typedef struct tree {
    int count;
    struct node *root;
} TREE;

// Function prototypes
NODE* createNode(char key);
void inorderTraversal(NODE* root);
void postorderTraversal(NODE* root);

int main() {
    // Define the expression
    char expression[] = "*+ab-cd";

    // Construct the expression tree
    TREE expressionTree;
    expressionTree.count = sizeof(expression) - 1; // excluding null terminator
    expressionTree.root = createNode(expression[0]);
    NODE* current = expressionTree.root;
    for (int i = 1; i < expressionTree.count; i += 2) {
        current->left = createNode(expression[i]);
        if (i + 1 < expressionTree.count) {
            current->right = createNode(expression[i + 1]);
        }
        if (i + 2 < expressionTree.count) {
            current = current->right;
        }
    }

    // Print infix expression
    printf("Infix Expression: ");
    inorderTraversal(expressionTree.root);
    printf("\n");

    // Print postfix expression
    printf("Postfix Expression: ");
    postorderTraversal(expressionTree.root);
    printf("\n");

    return 0;
}

// Function to create a new node
NODE* createNode(char key) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal to print infix expression
void inorderTraversal(NODE* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c", root->key);
        inorderTraversal(root->right);
    }
}

// Postorder traversal to print postfix expression
void postorderTraversal(NODE* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c", root->key);
    }
}
