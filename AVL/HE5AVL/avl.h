
/*============================================================================
 FILE        : avlHeader
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : contains the function prototypes and data structs of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 3/23/2024      Ghemarson   added function prototypes
 3/23/2024      Ghemarson   added tree struct
 ============================================================================*/
#ifndef AVLHEADER_H
#define AVLHEADER_H

#include <stdbool.h>

typedef struct tree{
    int value;                        // tree structure
    int height;
    struct tree *left;
    struct tree *right;
}treenode;

void printMenu();
treenode *createNode(int value);
int max(int a, int b);
int height(treenode *root);
int getBalance(treenode *root);
treenode *rotateCheck(treenode *root, int value, int balance);
treenode *leftRotate(treenode *root);
treenode *rightRotate(treenode *root);                              // function prototypes
treenode *maxValueNode(treenode *node);
treenode *insertNode(treenode *root, int value);
treenode *deleteNode(treenode *root, int value);
bool findNumber(treenode *root, int value);
void preOrder(treenode *root);
void inOrder(treenode *root);
void postOrder(treenode *root);
int printTreeBackend(treenode *tree, int is_left, int offset, int depth, char space[20][255]);
void printTree(treenode *tree);
#endif
