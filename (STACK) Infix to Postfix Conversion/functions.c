#include "functions.h"

void push(Node** top, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (isEmpty(*top)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

char peek(Node* top) {
    if (isEmpty(top)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return top->data;
}

int isEmpty(Node* top) {
    return top == NULL;
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Node* stack = NULL;
    int i = 0, j = 0;

    while (infix[i]) {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        }
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                fprintf(stderr, "Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            else {
                pop(&stack);
            }
            i++;
        }
        else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}
