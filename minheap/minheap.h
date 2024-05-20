/*
============================================================================
 FILE        : minheap.h
 AUTHOR      : Desiree Go
               Dhan Jacob Olmilla
               Jame Paul Silmaro
               Vincent Michael Villariza
 DESCRIPTION : Header file containing function declarations and
               structure definition for min heap operations.
 COPYRIGHT   : 05 May 2024
============================================================================
*/

#ifndef HEADER_H
#define HEADER_H
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data);
void insertNode(Node** root, int data);
void deleteNode(Node** root, int data);
Node* searchNode(Node* root, int data);
void minHeapify(Node* root);
void printTree(struct Node *root, int space);
Node* getParentNode(Node* root, Node* child);
Node* findLastNode(Node* root);
void removeRoot(Node** root);
Node* deleteRoot(Node* root);
void displayMinHeap(Node* root);
void depthFirstTraversal(Node* root);
void breadthFirstTraversal(Node* root);

#endif // HEADER_H


