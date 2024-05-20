#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

struct HashTable *createHashTable(int size) {
    struct HashTable *hashTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    if (hashTable == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    hashTable->size = size;
    hashTable->table = (struct ListNode **)calloc(size, sizeof(struct ListNode *));
    if (hashTable->table == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    return hashTable;
}

void insert(struct HashTable *hashTable, int key) {
    int index = abs(key) % hashTable->size;

    // Check if the value already exists in the hash table
    struct ListNode *current = hashTable->table[index];
    while (current != NULL) {
        if (current->val == key) {
            printf("Duplicate found: %d\n", key);
            return;
        }
        current = current->next;
    }

    // Value is not a duplicate, insert it into the hash table
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    node->val = key;
    node->next = hashTable->table[index];
    hashTable->table[index] = node;
}

void delete(struct HashTable *hashTable, int key) {
    int index = abs(key) % hashTable->size;

    struct ListNode *prev = NULL;
    struct ListNode *current = hashTable->table[index];

    while (current != NULL && current->val != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    if (prev == NULL) {
        hashTable->table[index] = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void display(struct HashTable *hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Bucket %d: ", i);
        struct ListNode *current = hashTable->table[i];
        while (current != NULL) {
            printf("%d -> ", current->val);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void destroyHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        struct ListNode *current = hashTable->table[i];
        while (current != NULL) {
            struct ListNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(hashTable->table);
    free(hashTable);
}
