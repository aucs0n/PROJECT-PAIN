/*
============================================================================
FILE : hash.c
AUTHOR : Remy Gabriel Cordero
DESCRIPTION : Functions for Hash Table Program
COPYRIGHT : 04 May 2024
============================================================================
*/
#include "hash.h"

/*
============================================================================
 FUNCTION    : hash
 DESCRIPTION : This function calculates the hash value for a given key.
 ARGUMENTS   : int key - The key to be hashed.
 RETURNS     : int - The hash value for the given key.
============================================================================
*/
int hash(int key)
{
    return key % HSIZE;
}

/*
============================================================================
 FUNCTION    : hashMenu
 DESCRIPTION : This function displays the menu for the hash table operations.
 ARGUMENTS   : None
 RETURNS     : none - void
============================================================================
*/
void hashMenu()
{
    printf("\n[1] Insert");
    printf("\n[2] Delete");
    printf("\n[3] Display");
    printf("\n[4] Destroy");
    printf("\n[5] Exit");
    printf("\nEnter your choice: ");
}

/*
============================================================================
 FUNCTION    : insert
 DESCRIPTION : This function inserts a new data into the hash table.
 ARGUMENTS   : int data - The data to be inserted.
 RETURNS     : none - void
============================================================================
*/
void insert(int data)
{
    int index = hash(data);
    int originalIndex = index;
    int firstDeletedIndex = -1;

    while (hashtable[index] != NULL && hashtable[index]->head != NULL)
    {
        if (hashtable[index]->head->data == DELETED && firstDeletedIndex == -1)
        {
            firstDeletedIndex = index;
        }

        else if (hashtable[index]->head->data == data)
        {
            return;
        }
        index = (index + 1) % HSIZE;

        if (index == originalIndex)
        {
            break;
        }
    }

    if (firstDeletedIndex != -1)
    {
        index = firstDeletedIndex;
    }

    else if (hashtable[index] != NULL)
    {
        printf("Hash table is full, cannot insert new data.\n");
        return;
    }

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->p = NULL;
    newNode->n = NULL;

    if (hashtable[index] == NULL)
    {
        hashtable[index] = (LIST *)malloc(sizeof(LIST));
        hashtable[index]->count = 0;
        hashtable[index]->head = hashtable[index]->tail = newNode;
    }
    else
    {
        hashtable[index]->tail->n = newNode;
        newNode->p = hashtable[index]->tail;
        hashtable[index]->tail = newNode;
    }
    hashtable[index]->count++;
}

/*
============================================================================
 FUNCTION    : delete
 DESCRIPTION : This function deletes a data from the hash table.
 ARGUMENTS   : int data - The data to be deleted.
 RETURNS     : none - void
============================================================================
*/
void delete(int data)
{
    int index = hash(data);

    while (hashtable[index] != NULL)
    {
        NODE *current = hashtable[index]->head;
        while (current != NULL)
        {
            if (current->data == data)
            {
                if (hashtable[index]->count == 1)
                {
                    free(current);
                    free(hashtable[index]);
                    hashtable[index] = NULL;
                }

                else
                {
                    if (current->p != NULL)
                    {
                        current->p->n = current->n;
                    }

                    else
                    {
                        hashtable[index]->head = current->n;
                    }

                    if (current->n != NULL)
                    {
                        current->n->p = current->p;
                    }

                    else
                    {
                        hashtable[index]->tail = current->p;
                    }
                    current->data = DELETED;
                }
                printf("Data %d deleted successfully.\n", data);
            }
            current = current->n;
        }
        index = (index + 1) % HSIZE;
    }
}

/*
============================================================================
 FUNCTION    : display
 DESCRIPTION : This function displays the contents of the hash table.
 ARGUMENTS   : None
 RETURNS     : none - void
============================================================================
*/
void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < HSIZE; i++)
    {
        printf("%d:", i);
        if (hashtable[i] != NULL)
        {
            NODE *current = hashtable[i]->head;
            while (current != NULL)
            {
                if (current->data != DELETED)
                {
                    printf(" %d", current->data);
                }
                current = current->n;
            }
        }
        printf("\n");
    }
}

/*
============================================================================
 FUNCTION    : destroy
 DESCRIPTION : This function destroys the hash table and frees up the memory.
 ARGUMENTS   : None
 RETURNS     : none - void
============================================================================
*/
void destroy()
{
    for (int i = 0; i < HSIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            NODE *current = hashtable[i]->head;
            while (current != NULL)
            {
                NODE *temp = current;
                current = current->n;
                free(temp);
            }
            free(hashtable[i]);
            hashtable[i] = NULL;
        }
    }
    printf("Hash table destroyed.\n");
}
