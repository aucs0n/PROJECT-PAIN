#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void display(void) {
    for (int i = 0; i < capacity; i++) {
        struct set *current = database[i];
        if (current!= NULL) {
            printf("\n Key[%d];  Array[%d]: ", database[i]->keyValue, i);
            while (current!= NULL) {
                printf("%d -> ", current->dataValue);
                current = current->next;
            }
            printf("NULL");
        }
        else{
            printf("\n Array[%d]: NULL", i);
        }
    }
}
