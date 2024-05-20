#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enQueue(struct Queue* queue, struct TreeNode* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

struct TreeNode* deQueue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    struct TreeNode* temp = queue->front->data;
    struct QueueNode* tempNode = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(tempNode);
    return temp;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void addNode(struct TreeNode** root, int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Queue* queue = createQueue();
    enQueue(queue, *root);

    while (!isEmpty(queue)) {
        struct TreeNode* temp = deQueue(queue);

        if (temp->left != NULL)
            enQueue(queue, temp->left);
        else {
            temp->left = newNode;
            free(queue);
            return;
        }

        if (temp->right != NULL)
            enQueue(queue, temp->right);
        else {
            temp->right = newNode;
            free(queue);
            return;
        }
    }
}

void deleteTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void displayTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    displayTree(root->left);
    displayTree(root->right);
}

void displayLineByLine(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enQueue(queue, root);

    while (!isEmpty(queue)) {
        int nodeCount = queue->rear - queue->front + 1;

        for (int i = 0; i < nodeCount; i++) {
            struct TreeNode* temp = deQueue(queue);
            printf("%d ", temp->data);

            if (temp->left != NULL)
                enQueue(queue, temp->left);
            if (temp->right != NULL)
                enQueue(queue, temp->right);
        }
        printf("\n");
    }
}

void exitProgram() {
    exit(0);
}
