#include <stdio.h>
#include <stdlib.h>
#include "string_operations.h"

int main() {
    struct Node *top = NULL;
    char str[100];
    int choice;

    do {
        printf("\n1. Insert string\n");
        printf("2. Destroy duplicates\n");
        printf("3. Display strings\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string to insert: ");
                scanf("%s", str);
                push(&top, str);
                break;
            case 2:
                destroyDuplicates(&top);
                break;
            case 3:
                displayStrings(top);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);

    // Free memory before exit
    while (!isEmpty(top)) {
        pop(&top);
    }

    return 0;
}
