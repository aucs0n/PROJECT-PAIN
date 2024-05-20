#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
    int size;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    struct HashTable *hashTable = createHashTable(size);

    int choice, key;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Destroy\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(hashTable, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(hashTable, key);
                break;
            case 3:
                display(hashTable);
                break;
            case 4:
                destroyHashTable(hashTable);
                printf("Hash table destroyed\n");
                return 0;
            case 5:
                printf("Exiting...\n");
                destroyHashTable(hashTable);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
