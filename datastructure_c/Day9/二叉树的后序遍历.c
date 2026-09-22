/*
    二叉树的后序遍历
*/
#include <stdlib.h>
#include <stdio.h>
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
    preorder(root->right,res,returnSize);
    res[(*returnSize)++]=root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int)*2000);
    *returnSize=0;
    preorder(root,res,returnSize);
    return res;
}
int main(){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = malloc(sizeof(struct TreeNode));    // 左子树
    root->left->val = 2;
    root->right = malloc(sizeof(struct TreeNode));   // 右子树
    root->right->val = 3;
    root->left->left = malloc(sizeof(struct TreeNode));    // 左子树的左子树
    root->left->left->val = 4;
    root->left->right = malloc(sizeof(struct TreeNode));   // 左子树的右子树
    root->left->right->val = 5;
    root->right->left = malloc(sizeof(struct TreeNode));   // 右子树的左子树
    root->right->left->val = 6;
    root->right->right = malloc(sizeof(struct TreeNode));  // 右子树的右子树
    root->right->right->val = 7;
    int* res = postorderTraversal(root,NULL);
    for(int i=0;i<*res;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    return 0;
}