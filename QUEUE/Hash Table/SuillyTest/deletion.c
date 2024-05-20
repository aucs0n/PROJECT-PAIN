#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void deletion(int deletor){
    int foundIt = 0;
    int i;
    for (i = 0; i < capacity; i++){
        if (database[i] != NULL) {
            struct set *current = database[i];
            struct set *previous = NULL;
            while (current != NULL) {
            if (current->dataValue == deletor){
                printf("\nData Value: %d has been deleted from key[%d].\n\n", current->dataValue, current->keyValue);
                if (previous == NULL) {
                    database[i] = current->next; 
                } else {
                    previous->next = current->next;
                }
                free(current);
                size--;
                foundIt = 1;
                break; // Exit the while loop
            } else {
                previous = current;
                current = current->next;
                }
            }
        }
    }

    if (!foundIt) {
        printf("This key does not exist within the Hash Table\n\n");
    }
}
