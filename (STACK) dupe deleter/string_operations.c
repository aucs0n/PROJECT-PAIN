#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_operations.h"

// Function to push a string onto the stack
void push(struct Node **top, char *str) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = (char*)malloc(strlen(str) + 1);
    if (newNode->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->data, str);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop the top element from the stack
void pop(struct Node **top) {
    if (*top == NULL) {
        return;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    free(temp->data);
    free(temp);
}

// Function to check if the stack is empty
int isEmpty(struct Node *top) {
    return top == NULL;
}

// Function to destroy duplicates in the stack
void destroyDuplicates(struct Node **top) {
    if (*top == NULL || (*top)->next == NULL) {
        return; // No duplicates possible
    }

    struct Node *current = *top;
    struct Node *next_next;

    while (current->next != NULL) {
        if (strcmp(current->data, current->next->data) == 0) {
            next_next = current->next->next;
            free(current->next->data);
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

// Function to display the strings in the stack
void displayStrings(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Strings in the stack:\n");
    while (top != NULL) {
        printf("%s\n", top->data);
        top = top->next;
    }
}
