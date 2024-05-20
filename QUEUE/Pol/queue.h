#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

typedef struct queueHead
{
    struct node *front, *rear;
    int count;
}queueHead;

typedef struct node
{
    char c;
    struct node *next;
}Node;

void enqueue(queueHead *queue, char c);
void dequeue(queueHead *queue);
char front(queueHead *queue);
char rear(queueHead *queue);