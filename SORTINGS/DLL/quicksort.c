#include<stdio.h>
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
    struct node *prev, *next;   
}node;

typedef struct List
{
    int count;
    struct node *head, *tail;
}List;

void add(List *data, int x);
void displayList(List *data);
node* getTail(node* cur);
node* partition(node* head, node* end, node** newHead, node** newEnd);  
node* quickSortRecur(node* head, node* end);
void quickSort(node** headRef);

int main()
{
    List *a = malloc(sizeof(List));
    a->count = 0;
    a->head = a->tail = NULL;

    int n, i;

	time_t t;
	srand((unsigned) time(&t));

	for(i=0; i<10; i++)
	{
		n = rand() % 101;
		add(a,n);
	}
    displayList(a);
    quickSort(&a->head);
    printf("\n");
    displayList(a);

}

void add(List *data, int x)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->prev = newNode->next = NULL;

    if(data->head == NULL)
    {
        data->head = data->tail = newNode;
    }
    else
    {
        newNode->prev = data->tail;
        data->tail->next = newNode;
        data->tail = newNode;
    }
    data->count++;
}
void displayList(List *data)
{
    node *temp = data->head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
node* getTail(node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

/*============================================================================
 FUNCTION    : partition
 DESCRIPTION : partitions the linked list for quicksort
 ARGUMENTS   : node* head - the head node of the list
               node* end - the end node of the list
               node** newHead - pointer to the new head node after partition
               node** newEnd - pointer to the new end node after partition
 RETURNS     : node* - the pivot node
============================================================================*/
node* partition(node* head, node* end, node** newHead, node** newEnd) {
    node* pivot = end;
    node* prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            node* tmp = cur->next;
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

/*============================================================================
 FUNCTION    : quickSortRecur
 DESCRIPTION : recursively sorts a linked list using quicksort
 ARGUMENTS   : node* head - the head node of the list
               node* end - the end node of the list
 RETURNS     : node* - the new head node after sorting
============================================================================*/
node* quickSortRecur(node* head, node* end) {
    if (!head || head == end)
        return head;

    node* newHead = NULL, *newEnd = NULL;

    node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}
/*============================================================================
 FUNCTION    : quickSort
 DESCRIPTION : initiates quicksort on a linked list
 ARGUMENTS   : node** headRef - pointer to the head node of the list
 RETURNS     : void
============================================================================*/
void quickSort(node** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
