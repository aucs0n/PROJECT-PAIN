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
void MergeSort(Node** headRef);
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);


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
    MergeSort(&list->head);
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


void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
