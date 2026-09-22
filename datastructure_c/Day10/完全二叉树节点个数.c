
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int countNodes(struct TreeNode* root);

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    root->right = NULL;
    printf("%d\n", countNodes(root));
    return 0;
}
int countNodes(struct TreeNode* root) {
    if(root==NULL)  return 0;
    else return countNodes(root->left)+countNodes(root->right)+1;
}