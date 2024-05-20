// ========= LIBRAY DECLARATIONS ========= //

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

// ========= INDIVIDUAL FILE DECLARATIONS ========= //
#include "insertion.c" 
#include "deletion.c"
#include "sizeCheck.c"
#include "displaying.c"
#include "hashFunction.c"
#include "arrayInitializer.c"

// ========= MAIN DRIVER CODE ========= //
int main(void){
    int choice, key, input, n;
    char getOut;
    initializeArray();

    do{
        printf ("\n\n========= HASH TABLE TEST PROGRAM =========\n\n");
        printf("[1]: Add Hash Data\n[2]: Delete Hash Data\n[3]: Display Hash Data\n[0]: Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        while (choice != 1 && choice != 2 && choice != 3 && choice != 0){
            printf("Invalid choice. Please enter again: ");
            scanf("%d", &choice);
        }

        switch(choice){
            case 1: 
                printf("Enter Hash Key (Max of 15): ");
                scanf("%d", &key);

                while (key > 15 || key < 0){
                    printf("\nInvalid key. Please enter key between 1-15: ");
                    scanf("%d", &key);
                }

                printf("Enter Data Value: ");
                scanf("%d", &input);
                insert(key, input);

                n = sizeCheck();
                printf("Current Size of Hash Table is: %d\n\n", n);

                printf("Enter any key to continue: ");
                scanf(" %c", &getOut);
                break;

            case 2: 
                printf("Enter a number to delete: ");
                scanf("%d", &input);
                deletion(input);

                n = sizeCheck();
                printf("\n\nCurrent Size of Hash Table is: %d\n\n", n);

                printf("Enter any key to continue: ");
                scanf(" %c", &getOut);
                break;

            case 3: 
                printf("Current Hash Table: ");
                display();

                 n = sizeCheck();
                printf("\n\nCurrent Size of Hash Table is: %d\n\n", n);

                printf("Enter any key to continue: ");
                scanf(" %c", &getOut);
                break;
        }
    }while (choice != 0);

    printf ("\n\n========= HASH TABLE TEST PROGRAM =========\n\n");
    printf ("          [ T E R M I N A T E D ]          \n\n");
}

// PROJECT NOTE: EVERYTHING WORKS AS INTENDED. HOWEVER, COLLISION HANDLING IS NOT DONE PROPERLY.
// INSTEAD OF LINKING DATA WITH SIMILAR KEYS, DATA WITH SIMILAR KEYS GET OVERRIDDEN BY THE MOST RECENT ONE.
// THIS IS BAD, BUT WE CAN FIX THIS. 
