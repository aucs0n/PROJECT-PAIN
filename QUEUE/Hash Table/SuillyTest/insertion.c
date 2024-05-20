#include <stdlib.h>
#include <stdio.h>
#include "header.h"

//NOTE TO SELF: FIGURE OUT A WAY TO HANDLE HASH COLLISION, BECAUSE THE DATA IS BEING OVERRIDDEN. 

void insert(int keyValue, int dataValue) {
    int index = hashFunction(keyValue);
    int startIndex = index;

    if (database[index] == NULL){
        // Allocate memory for the new Node
        database[index] = (struct set*)malloc(sizeof(struct set));
        // Initialize the new Node
        database[index]->keyValue = keyValue;
        database[index]->dataValue = dataValue;
        database[index]->next = NULL;
        size++;
        printf("\n Key (%d) has been inserted \n", keyValue);
    }

    else{
            struct set* current = database[index];
            while (current->next!= NULL) {
            current = current->next;
            // Linear probing (you could use quadratic or double hashing instead)
            index = (index + 1) % capacity;
            if (index == startIndex) {
                // Table is full, handle this case accordingly
                printf("Database is full. Cannot insert new data.\n");
                return;
            }
        }
        // Allocate memory for the new Node
        struct set* newNode = (struct set*)malloc(sizeof(struct set));
        // Insert new data at the found empty slot
        newNode->keyValue = keyValue;
        newNode->dataValue = dataValue;
        newNode->next = NULL;
        current->next = newNode;
        size++;
        printf("\nData Value: %d has been inserted into key[%d].\n\n", dataValue, keyValue);
    }
}