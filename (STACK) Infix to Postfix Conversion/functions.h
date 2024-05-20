#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** top, char data);
char pop(Node** top);
char peek(Node* top);
int isEmpty(Node* top);
int isOperand(char ch);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);

#endif /* FUNCTIONS_H */
