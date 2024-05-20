#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

// Define the structure for the stack node
struct Node {
    char *data;
    struct Node *next;
};

// Function prototypes
void push(struct Node **top, char *str);
void pop(struct Node **top);
int isEmpty(struct Node *top);
void destroyDuplicates(struct Node **top);
void displayStrings(struct Node *top);

#endif
