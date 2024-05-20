#ifndef HASH_H
#define HASH_H

struct ListNode {
    int val;
    struct ListNode *next;
};

struct HashTable {
    int size;
    struct ListNode **table;
};

struct HashTable *createHashTable(int size);
void insert(struct HashTable *hashTable, int key);
void delete(struct HashTable *hashTable, int key);
void display(struct HashTable *hashTable);
void destroyHashTable(struct HashTable *hashTable);

#endif
