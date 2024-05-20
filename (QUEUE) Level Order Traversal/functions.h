#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

void addNode(struct TreeNode** root, int data);
void deleteTree(struct TreeNode* root);
void displayTree(struct TreeNode* root);
void displayLineByLine(struct TreeNode* root);
void exitProgram();

#endif
