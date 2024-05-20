#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void insertNode(Node** root, int data);
void deleteNode(Node** root, int data);
Node* searchNode(Node* root, int data);
void displayTree(Node* root);
void reverseTree(Node** root);
void levelOrderTraversal(Node* root);
Node* findMinimum(Node* root);
void exitProgram();

#endif /* BINARY_TREE_H */
