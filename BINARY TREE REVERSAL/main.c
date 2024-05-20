#include <stdio.h>
#include "binary_tree.h"

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Display Tree\n");
        printf("5. Reverse Tree\n");
        printf("6. Level Order Traversal\n");
        printf("7. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(&root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchNode(root, data) != NULL) {
                    printf("Node found\n");
                } else {
                    printf("Node not found\n");
                }
                break;
            case 4:
                printf("Binary Tree (Depth Order Traversal): ");
                displayTree(root);
                printf("\n");
                break;
            case 5:
                reverseTree(&root);
                printf("Tree reversed\n");
                break;
            case 6:
                printf("Level Order Traversal: ");
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 7:
                exitProgram();
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
