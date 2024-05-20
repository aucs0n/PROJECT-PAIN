/*============================================================================
 FILE        : hash.c
 AUTHOR      : Ghemarson John D. Nacua
 DESCRIPTION : contains the operations of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 5/03/2024      Ghemarson   added function details
 ============================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#define MAX_SIZE 10
#include "hash.h"

/*============================================================================
 FUNCTION    : createHashTable
 DESCRIPTION : Creates and initializes a hash table.
 ARGUMENTS   : none
 RETURNS     : list * - Pointer to the created hash table
 ============================================================================*/
list *createHashTable(void)
{
    list *hashTable = malloc(sizeof(list));
    hashTable->entries = malloc(sizeof(node *) * MAX_SIZE);
    hashTable->count = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        hashTable->entries[i] = NULL;
    }

    return hashTable;
}

/*============================================================================
 FUNCTION    : insertData
 DESCRIPTION : Inserts a new node with data into a hash table using linear probing to handle collisions.
 ARGUMENTS   :
 list *ht - Pointer to the hash table
 int data - Data to be inserted into the hash table
 RETURNS     : void (no return)
============================================================================*/
void insertData(list *ht, int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    unsigned int index = hashFunction(data);
    unsigned int startIndex = index;

    while (ht->entries[index] != NULL)
    {
        if (ht->entries[index]->data == data)
            {

            index = (index + 1) % MAX_SIZE;

            if (index == startIndex)
                {
                printf("Hash table is full, cannot insert %d\n", data);
                getch();
                return;
                }
            }
            else
            {
                index = (index + 1) % MAX_SIZE;
            }
    }
    ht->entries[index] = newNode;
    ht->count++;
    printf("%d inserted at index %d\n", data, index);
    getch();
    return;
}

/*============================================================================
 FUNCTION    : searchData
 DESCRIPTION : Searches for a data in a hash table using linear probing.
 ARGUMENTS   :
 list *ht - Pointer to the hash table
 int data - Data to search for in the hash table
 RETURNS     : void (no return)
============================================================================*/
void searchData(list *ht, int data)
{
    unsigned int index = hashFunction(data);
    unsigned int initialIndex = index;

    node *entry = ht->entries[index];

    while (entry != NULL)
    {
        if (entry->data == data)
        {
            printf("%d FOUND AT Index %d\n", data, index);
            return;
        }
        else
        {
            index = (index + 1) % MAX_SIZE;
            entry = ht->entries[index];


            if (index == initialIndex)
            {
                printf("%d NOT FOUND\n", data);
                return;
            }
        }
    }
}

/*============================================================================
 FUNCTION    : deleteNode
 DESCRIPTION : Deletes a node with specific data from a hash table and handles rehashing.
 ARGUMENTS   :
 list *ht - Pointer to the hash table
 int data - Data to be deleted from the hash table
 RETURNS     : void (no return)
============================================================================*/
void deleteNode(list *ht, int data)
{
    system("cls");
    unsigned int index = hashFunction(data);
    unsigned int initialIndex = index;


    bool found = false;

    while (ht->entries[index] != NULL)
    {
        if (ht->entries[index]->data == data)
        {

            free(ht->entries[index]);
            ht->entries[index] = NULL;
            printf("Deleted %d at index %d\n", data, index);
            found = true;

            unsigned int nextIndex = (index + 1) % MAX_SIZE;
            while (ht->entries[nextIndex] != NULL && hashFunction(ht->entries[nextIndex]->data) != nextIndex)
            {
                node *temp = ht->entries[nextIndex];
                ht->entries[nextIndex] = NULL;
                insertData(ht, temp->data);
                free(temp);
                nextIndex = (nextIndex + 1) % MAX_SIZE;
            }
        }


        index = (index + 1) % MAX_SIZE;


        if (index == initialIndex)
        {
            if (!found)
                system("cls");
            printf("%d NOT FOUND\n", data);
            getch();
            return;
        }
    }


    if (!found)
    {
        system("cls");
        printf("%d NOT FOUND\n", data);
    }

    getch();
    return;
}

/*============================================================================
 FUNCTION    : hashFunction
 DESCRIPTION : Calculates the hash value for a given data using modulo operation.
 ARGUMENTS   :
 int data - Data for which the hash value is calculated
 RETURNS     : unsigned int - Hash value of the data
============================================================================*/
unsigned int hashFunction(int data)
{
    return data % MAX_SIZE;
}

/*============================================================================
 FUNCTION    : displayHashTable
 DESCRIPTION : Displays the contents of a hash table.
 ARGUMENTS   :
 list *ht - Pointer to the hash table to be displayed
 RETURNS     : void (no return)
============================================================================*/
void displayHashTable(list *ht)
{
    system("cls");
    printf("Hash Table:\n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        node *entry = ht->entries[i];
        printf("Index %d: ", i);
        while (entry != NULL)
        {
            printf("(%d) ", entry->data);
            entry = entry->next;
        }
        printf("\n");
    }
    getch();
    return;
}

/*============================================================================
 FUNCTION    : clearHashTable
 DESCRIPTION : Deletes all data and frees memory associated with a hash table.
 ARGUMENTS   :
 list *ht - Pointer to the hash table to be deleted
 RETURNS     : void (no return)
============================================================================*/
void clearHashTable(list *ht)
{
    ht->count = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(ht->entries[i]);
        ht->entries[i] = NULL;
    }
    system("cls");
    printf("TABLE DELETED\n");
    getch();
    return;
}
