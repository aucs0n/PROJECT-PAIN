#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

void insertNode(Node** root, int data) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (data <= (*root)->data) {
            insertNode(&((*root)->left), data);
        } else {
            insertNode(&((*root)->right), data);
        }
    }
}

void deleteNode(Node** root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        deleteNode(&((*root)->left), data);
    } else if (data > (*root)->data) {
        deleteNode(&((*root)->right), data);
    } else {
        // Node found, handle deletion
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            Node* temp = findMinimum((*root)->right);
            (*root)->data = temp->data;
            deleteNode(&((*root)->right), temp->data);
        }
    }
}

Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

Node* findMinimum(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void displayTree(Node* root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

void reverseTree(Node** root) {
    if (*root == NULL) {
        return;
    }

    Node* temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = temp;

    reverseTree(&((*root)->left));
    reverseTree(&((*root)->right));
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    // Create a queue for level order traversal
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        Node* current = queue[++front];
        printf("%d ", current->data);
        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
}

void exitProgram() {
    exit(0);
}
