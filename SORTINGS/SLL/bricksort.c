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
void printList(List *list);
void brickSort(List* list);


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
    brickSort(list);

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

void printList(List *list)
{
    Node *temp = list->head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

void brickSort(List* list) {
    if (list->head == NULL || list->head->next == NULL) {
        return; 
    }

    int swapped;
    do {
        swapped = 0;

        Node* current = list->head;
        while (current && current->next) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = 1;
            }
            current = current->next->next;               //if you read this your gay
        }
        current = list->head->next;
        while (current && current->next) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = 1;
            }
            current = current->next->next;
        }
        printList(list);
        printf("\n");
    } while (swapped);
}
