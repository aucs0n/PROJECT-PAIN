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
void insertionSort(Node **head_ref);
void sortedInsert(Node** head_ref, Node* new_node);


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
    insertionSort(&list->head);
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

void sortedInsert(Node** head_ref, Node* new_node)
{
    Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL && current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertionSort(Node **head_ref)
{
    Node *sorted = NULL;
    Node *current = *head_ref;
    while (current != NULL)
    {
        Node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
        printList(sorted);
        printf("\n");
   
    }
    *head_ref = sorted;
}