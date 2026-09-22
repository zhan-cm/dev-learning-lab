
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* root);

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->right->val = 20;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 15;
    root->left->right->val = 7;
    root->right->left->val = 12;
    root->right->right->val = 18;
    printf("The maximum depth of the binary tree is %d", maxDepth(root));
    return 0;
}
int maxDepth(struct TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    int m = maxDepth(root->left);
    int n= maxDepth(root->right);
    if(m>n)return m+1;
    else return n+1;
}