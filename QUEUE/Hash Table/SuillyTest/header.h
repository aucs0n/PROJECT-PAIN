#ifndef HEADER_H
#define HEADER_H

#define capacity 15

struct set{
    int keyValue; 
    int dataValue;
    struct set *next;
};

struct set *database[capacity];
int size = 0;

void insert(int keyValue, int dataValue);
void deletion(int deletor);

int hashFunction(int keyValue);
int sizeCheck(void);

int checkPrime (int n);
int getPrime (int n);

void initializeArray(void);
void display(void);

#endif
