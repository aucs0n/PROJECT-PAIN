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
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd);
Node* quickSortRecur(Node* head, Node* end);
void quickSort(Node** headRef);
Node *getTail(Node *cur);


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
    quickSort(&list->head);
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

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd)
{
    Node* pivot = end;
    Node* prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;  
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* end)
{
    if (!head || head == end)
        return head;

    Node* newHead = NULL, *newEnd = NULL;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    
    return newHead;
}

void quickSort(Node** headRef)
{
    Node* newHead = NULL;
    if (*headRef == NULL || (*headRef)->next == NULL)
        return;

    Node* newEnd = NULL;
    Node* pivot = partition(*headRef, getTail(*headRef), &newHead, &newEnd);

    quickSort(&newHead);
    quickSort(&pivot->next);

    printList(newHead);
    printf("\n");

    return;
}

Node *getTail(Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

