#ifndef QUEUEDLL_H
#define QUEUEDLL_H

typedef struct node {
    char name[30];
    char phone[15];
    struct node *next, *prev;
} NODE;

void showMenu();
NODE *createNode();
void assign(NODE **new, char person[], char number[]);
void enQueue(NODE *new, NODE **L);
void deQueue(NODE **L);
void showData(NODE *L);
void clearScr();
void delay(int seconds);
void pause();

#endif