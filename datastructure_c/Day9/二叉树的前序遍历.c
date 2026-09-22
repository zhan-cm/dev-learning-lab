/*
    二叉树的前序遍历
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preorder(struct TreeNode* root,int* res,int* returnSize){
    if(root==NULL){
        return;
    }
    res[(*returnSize)++]=root->val;
    preorder(root->left,res,returnSize);
    preorder(root->right,res,returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int)*2000);
    *returnSize=0;
    preorder(root,res,returnSize);
    return res;
}
int main() {
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = malloc(sizeof(struct TreeNode));
    root->right = malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right->val = 3;
    root->left->left = malloc(sizeof(struct TreeNode));
    root->left->right = malloc(sizeof(struct TreeNode));
    root->right->left = malloc(sizeof(struct TreeNode));
    root->right->right = malloc(sizeof(struct TreeNode));
    root->left->left->val = 4;
    root->left->right->val = 5;
    root->right->left->val = 6;
    root->right->right->val = 7;
    int* res = preorderTraversal(root, NULL);
    for(int i=0;i<*res;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    free(res);
    return 0;
}