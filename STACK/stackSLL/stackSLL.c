#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stackSLL.h"

int nodeCount = 0;

void showMenu(){

    printf("Menu:\n");
    printf("[a]ppend\n");
    printf("[b]rowse\n");
    printf("[c]peek top\n");
    printf("[d]elete\n");
    printf("[e]xit\n");
}

NODE *createNode(){

    NODE *new = malloc(sizeof(NODE));
    if(new == NULL)
        printf("ERROR: Not enough memory on this device to create a new contact!\n");
    return new;
}

void assign(NODE **new, char person[], char number[]){

    strcpy((*new)->name, person);
    strcpy((*new)->phone, number);
}

void push(NODE *new, NODE **L){

    new->next = *L;
    *L = new;
    printf("\n\nSUCCESS: New record pushed to the top!\n\n");
    nodeCount++; 
}

void pop(NODE **L, int position){

    position--;
    int currentPos = 0;
    NODE *current_node = malloc(sizeof(NODE));
    if(current_node == NULL)
        printf("ERROR: Not enough memory on this device to carry out this operation!\n");
    else
    {
        current_node = *L;
        while(currentPos <= position)
        {
            *L = current_node->next;
            free(current_node);
            current_node = *L;
            currentPos++;
            nodeCount--;
        }
        printf("\n\nSUCCESS: Delete successful!\n\n");
    }
}

void showData(NODE *L){

    int i = 1;
    if(L == NULL)
        printf("\n\nERROR: No records available.\n\n");
    else
    {
        printf("\n\nPhonebook\n\n");
        if(nodeCount == 1)
            printf("%d contact available\n\n", nodeCount);
        else
            printf("%d contacts available\n\n", nodeCount);
        for(; L != NULL; L = L->next, i++)
            printf("%d. %-35s\t\t\t%s\n", i, L->name, L->phone);
        printf("\n");
    }
}

void clearScr(){
    printf("\e[1;1H\e[2J");
}

void delay(int seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void pause(){
    #ifdef _WIN32
        delay(2);
    #elif __APPLE__
        delay(2000);
    #elif __unix__
        delay(2000);
    #endif
}

void peek(NODE *L){

    if(L == NULL)
        printf("\n\nERROR: No records available.\n\n");
    else
    {
        printf("\n\nPhonebook\n\n");
        printf("Top contact: \n");
        printf("1. %-35s\t\t\t%s\n", L->name, L->phone);
        printf("\n");
    }  
}