#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define NUM_CHAR 256

typedef struct trienode{

    struct trienode *children[NUM_CHAR];
    bool isEndOfWord;
} trienode;

void printMenu(){

    printf("[1] Add string\n");
    printf("[2] Delete string\n");
    printf("[3] Show strings\n");
    printf("[4] Search strings\n");
    printf("[5] Exit\n");
}

trienode *createNode(){

    trienode *newNode = (trienode *) malloc(sizeof *newNode);
    for(int i = 0; i < NUM_CHAR; i++)
        newNode->children[i] = NULL;
    newNode->isEndOfWord = false;
    return newNode;
}

bool trieInsert(trienode **root, char *str){

    if(*root == NULL)
        *root = createNode();
    unsigned char *text = (unsigned char*)str;
    trienode *temp = *root;
    int length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        if(temp->children[text[i]] == NULL)
            temp->children[text[i]] = createNode();
        temp = temp->children[text[i]];
    }
    if(temp->isEndOfWord)
        return false;
    else
    {
        temp->isEndOfWord = true;
        return true;
    }
}

void printTrieRec(trienode *node, unsigned char *prefix, int length){

    unsigned char newPrefix[length + 2];
    memcpy(newPrefix, prefix, length);
    newPrefix[length + 1] = 0;
    
    if(node->isEndOfWord)
        printf("WORD : %s\n", prefix);
    for(int i = 0; i < NUM_CHAR; i++)
    {
        if(node->children[i] != NULL)
        {
            newPrefix[length] = i;
            printTrieRec(node->children[i], newPrefix, length + 1);
        }
    }
}

void printTrie(trienode *root){

    if(root == NULL)
        return;
    printTrieRec(root, NULL, 0);
}

bool trieSearch(trienode *root, char *str){

    unsigned char *text = (unsigned char *)str;
    trienode *temp = root;
    int length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        if(temp->children[text[i]] == NULL)
            return false;
        temp = temp->children[text[i]];
    }
    return temp->isEndOfWord;
}

bool nodeHasChild(trienode *node){

    if(node == NULL) return false;
    for(int i = 0; i < NUM_CHAR; i++)
    {
        if(node->children[i] != NULL)
            return true;
    }
    return false;
}

trienode *trieDeleteRec(trienode *root, unsigned char *text, bool *result){

    if(root == NULL) return root;
    
    if(*text == '\0')
    {
        if(root->isEndOfWord)
        {
            root->isEndOfWord = false;
            *result = true;
            if(nodeHasChild == false)
            {
                free(root);
                root = NULL;
            }
        }
        return root;
    }

    root->children[text[0]] = trieDeleteRec(root->children[text[0]], text + 1, result);
    if(result && nodeHasChild == false && root->isEndOfWord == false)
    {
        free(root);
        root = NULL;
    }
    return root;
}

bool trieDelete(trienode **root, char *str){

    unsigned char *text = (unsigned char *)str;
    bool result = false;
    if(*root == NULL) return false;

    *root = trieDeleteRec(*root, text, &result);
    return result;
}

int main(){

    int choice;
    trienode *root = NULL;
    do{
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        int numOfStrings, i;
        char str[100];
        if(choice == 1)
        {
            printf("How many strings do you want in the trie? ");
            scanf("%d", &numOfStrings);
            for(i = 0; i < numOfStrings; i++)
            {
                printf("Enter string #%d: ", i+1);
                scanf(" %[^\n]s", str);
                trieInsert(&root, str);
            }
        }

        if(choice == 2)
        {
            printf("How many strings would you like to delete? ");
            scanf("%d", &numOfStrings);
            printTrie(root);
            for(i = 0; i < numOfStrings; i++)
            {
                printf("Enter string #%d: ", i+1);
                scanf(" %[^\n]s", str);
                trieDelete(&root, str);
            }
        }

        if(choice == 3)
            printTrie(root);

        if(choice == 4)
        {
            printf("How many strings would you like to search? ");
            scanf("%d", &numOfStrings);
            for(i = 0; i < numOfStrings; i++)
            {
                printf("Enter string #%d: ", i+1);
                scanf(" %[^\n]s", str);
                printf("%s (%d)\n", str, trieSearch(root, str));
            }
        }

    }while(choice < 5 && choice >= 1);
    return 0;
}