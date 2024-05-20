#ifndef AVLHEADER_H
#define AVLHEADER_H

typedef struct tree{
    int value;
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
treenode *rightRotate(treenode *root);
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