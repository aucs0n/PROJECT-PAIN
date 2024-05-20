#include "list.h"
#include "sort.h"

/*
============================================================================
 FUNCTION    : printList
 DESCRIPTION : Prints the iterations during the sorting process
 ARGUMENTS   : Node *node
 RETURNS     : void
============================================================================
*/

void printList(struct Node *node)
{
    printf("[ ");
    while (node != NULL)
    {
        printf("%d ", node->x);
        node = node->n;
    }
    printf("]\n");
}

/*
============================================================================
 FUNCTION    : strandsort
 DESCRIPTION : strand sort function that sorts the randomly generated list using strand sort sorting algorithm
 ARGUMENTS   : LIST *data - the list containing the data
 RETURNS     : void
============================================================================
*/

void strandSort(LIST *data)
{
    displayList(data);
    data->head = strandSorter(data->head);
    displayList(data);
}

struct Node *strandSorter(struct Node *head)
{
    int count = 1;
    if (!head)
        return NULL;
    struct Node *result = NULL;

    while (head)
    {
        struct Node *sublist = head;
        struct Node *tail = sublist;
        head = head->n;
        tail->n = NULL;

        struct Node **ptr = &head;
        while (*ptr)
        {
            if ((*ptr)->x > tail->x)
            {
                struct Node *temp = *ptr;
                *ptr = temp->n;

                tail->n = temp;
                tail = temp;
                tail->n = NULL;
            }
            else
            {
                ptr = &((*ptr)->n);
            }
        }

        result = merge(&result, &sublist);

        printf("Iteration %d: \n", count);

        printList(result);
        printList(head);

        count++;
    }
    
    return result;
}

struct Node *merge(struct Node **a, struct Node **b)
{
    struct Node *result = NULL;
    if (!(*a))
    {
        return *b;
    }
    else if (!(*b))
    {
        return *a;
    }

    if ((*a)->x <= (*b)->x)
    {
        result = *a;
        *a = (*a)->n;
        result->n = merge(a, b);
    }
    else
    {
        result = *b;
        *b = (*b)->n;
        result->n = merge(a, b);
    }

    return result;
}
