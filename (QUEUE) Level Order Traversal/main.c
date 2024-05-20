#include <stdio.h>
#include "functions.h"

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Add Node\n");
        printf("2. Delete Tree\n");
        printf("3. Display Tree\n");
        printf("4. Display Level Order Traversal (Line By Line)\n");
        printf("5. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                addNode(&root, data);
                break;
            case 2:
                deleteTree(root);
                root = NULL;
                printf("Tree deleted successfully.\n");
                break;
            case 3:
                printf("Binary Tree: ");
                displayTree(root);
                printf("\n");
                break;
            case 4:
                printf("Level Order Traversal (Line By Line):\n");
                displayLineByLine(root);
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
