#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
/*================================
Author: Im You
Description: Where You Go I Go
================================*/

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct list
{
    int count;
    struct node *head, *tail;
}List;

void add(List *ist, int x);
void printList(Node *headRef);
void selectionSort(Node **head_ref);
void swap(Node *a, Node *b);

int main()
{
    List *list = malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->count = 0;
    int n, i;
    printf("Unsorted: \t");
    time_t t;
    srand((unsigned) time(&t));
    for(i=0; i<10; i++)
    {
        n = rand() % 101;
        printf("%d ", n);
        add(list,n);
    }

    printf("\n");
    printf("\nTraversal:\n");
    selectionSort(&list->head);
    printList(list->head);
    

    return 0;
}


void add(List *list, int x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if(list->head == NULL)
    {
        list->head = list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->count++;
}

void printList(Node *headRef)
{
    Node *temp = headRef;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

void selectionSort(Node **head_ref) {
    Node *start = *head_ref;
    Node *trav;
    Node *min;

    while (start->next) {
        min = start;
        trav = start->next;

        while (trav) {
            if (min->data > trav->data)
                min = trav;

            trav = trav->next;
        }

        swap(start, min);
        start = start->next;
        printList(*head_ref);
        printf("\n");
    }
}

void swap(Node *a, Node *b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
