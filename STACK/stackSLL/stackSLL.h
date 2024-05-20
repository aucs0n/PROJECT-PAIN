#ifndef STACKSLL_H
#define STACKSLL_H

typedef struct node {
    char name[30];
    char phone[15];
    struct node *next;
} NODE;

void showMenu();
NODE *createNode();
void assign(NODE **new, char person[], char number[]);
void push(NODE *new, NODE **L);
void pop(NODE **L, int position);
void showData(NODE *L);
void clearScr();
void delay(int seconds);
void pause();
void peek(NODE *L);

#endif