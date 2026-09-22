/*
    二叉树的中序遍历
*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


void preorder(struct TreeNode* root,int* res,int* returnSize){
    if(root==NULL){
        return;
    }
    preorder(root->left,res,returnSize);
    res[(*returnSize)++]=root->val;
    preorder(root->right,res,returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int)*2000);
    *returnSize=0;
    preorder(root,res,returnSize);
    return res;
}
int main(){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->left->left = malloc(sizeof(struct TreeNode));
    root->left->left->val = 4;
    root->left->right = malloc(sizeof(struct TreeNode));
    root->left->right->val = 5;
    root->right->left = malloc(sizeof(struct TreeNode));
    root->right->left->val = 6;
    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->val = 7;
    int* res = inorderTraversal(root,NULL);
    for(int i=0;i<*res;i++){
        printf("%d ",res[i]);
    }
    return 0;
}