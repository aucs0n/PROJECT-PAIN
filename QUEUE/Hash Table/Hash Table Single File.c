#include <stdio.h>
#include <stdlib.h>

#define HSIZE 10 // Size of the hash table
#define DELETED -1 // Tombstone marker

typedef struct node {
    int data;
    struct node *p, *n;
} NODE;

typedef struct list {
    int count;
    NODE *head, *tail;
} LIST;

LIST *hashtable[HSIZE]; // Hash table array

// Function prototypes
int hash(int key);
void insert(int data);
void delete(int data);
void display();
void destroy();

int main() {
    int choice, data;

    // Initialize hash table
    for (int i = 0; i < HSIZE; i++) {
        hashtable[i] = NULL;
    }

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Destroy\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                display();
                break;
            case 4:
                destroy();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Hash function
int hash(int key) {
    return key % HSIZE;
}

// Insert data into the hash table
void insert(int data) {
    int index = hash(data);

    // Linear probing
    while (hashtable[index] != NULL && hashtable[index]->head->data != DELETED) {
        index = (index + 1) % HSIZE;
    }

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->p = NULL;
    newNode->n = NULL;

    if (hashtable[index] == NULL) {
        hashtable[index] = (LIST *)malloc(sizeof(LIST));
        hashtable[index]->count = 0;
        hashtable[index]->head = hashtable[index]->tail = newNode;
    } else {
        hashtable[index]->tail->n = newNode;
        newNode->p = hashtable[index]->tail;
        hashtable[index]->tail = newNode;
    }
    hashtable[index]->count++;
}

// Delete data from the hash table
void delete(int data) {
    int index = hash(data);

    // Linear probing
    while (hashtable[index] != NULL) {
        NODE *current = hashtable[index]->head;
        while (current != NULL) {
            if (current->data == data) {
                if (current->p != NULL) {
                    current->p->n = current->n;
                } else {
                    hashtable[index]->head = current->n;
                }
                if (current->n != NULL) {
                    current->n->p = current->p;
                } else {
                    hashtable[index]->tail = current->p;
                }
                free(current);
                hashtable[index]->count--;
                printf("Data %d deleted successfully.\n", data);
                return;
            }
            current = current->n;
        }
        index = (index + 1) % HSIZE;
    }

    printf("Data %d not found.\n", data);
}

// Display the hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < HSIZE; i++) {
        printf("%d:", i);
        if (hashtable[i] != NULL) {
            NODE *current = hashtable[i]->head;
            while (current != NULL) {
                if (current->data != DELETED) {
                    printf(" %d", current->data);
                }
                current = current->n;
            }
        }
        printf("\n");
    }
}

// Destroy the hash table
void destroy() {
    for (int i = 0; i < HSIZE; i++) {
        if (hashtable[i] != NULL) {
            NODE *current = hashtable[i]->head;
            while (current != NULL) {
                NODE *temp = current;
                current = current->n;
                free(temp);
            }
            free(hashtable[i]);
            hashtable[i] = NULL;
        }
    }
    printf("Hash table destroyed.\n");
}
