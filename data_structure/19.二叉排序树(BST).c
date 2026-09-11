// BST  Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

TreeNode *BST_Search(TreeNode *T, int data)
{
    if (T)
    {
        if (T->data == data)
        {
            return T;
        }
        else if (data < T->data)
        {
            return BST_Search(T->lchild, data);
        }
        else
        {
            return BST_Search(T->rchild, data);
        }
    }
    else
    {
        return NULL;
    }
}

void BST_Insert(TreeNode **T, int data)
{
    if (*T == NULL)
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    else if (data < (*T)->data)
    {
        BST_Insert(&(*T)->lchild, data);
    }
    else if (data == (*T)->data)
    {
        return;
    }
    else
    {
        BST_Insert(&(*T)->rchild, data);
    }
}

void preOrder(TreeNode *T)
{
    if (T)
    {
        printf("%d", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

int main()
{
    TreeNode *T = NULL;
    int nums[6] = {4, 5, 19, 23, 2, 8};
    for (int i = 0; i < 6; i++)
    {
        BST_Insert(&T, nums[i]);
    }
    preOrder(T);
    printf("\n");
}
