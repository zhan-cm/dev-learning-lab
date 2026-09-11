/**
 * 1.建立平衡二叉树的过程就是建立一棵二叉排序树的过程
 * 2.在建立过程中我们需要去进行调整，调整需要用到树的高度，
 *      所以我们节点的结构体当中需要加一个字段来标识树的高度
 * 3.调整方法
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    int height;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

int getHeight(TreeNode *node)
{
    return node ? node->height : 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void rrRotation(TreeNode *node, TreeNode **root)
{
    /*
        取中间的节点，使它的父亲成为它的左孩子，
        如果它有左孩子的话，那么这个左孩子连接到父亲的右孩子上
    */
    TreeNode *temp = node->rchild; // 取中间节点
    node->rchild = temp->lchild;   // 如果它有左孩子，那么这个左孩子连接到父亲的右孩子上
    temp->lchild = node;           // 它的父亲成为它的左孩子
    node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    *root = temp;
}

void llRotation(TreeNode *node, TreeNode **root)
{
    /*
        取中间的节点，使它的父亲成为它的右孩子，
        如果它有右孩子的话，那么这个左孩子连接到父亲的左孩子上
    */
    TreeNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    *root = temp;
}

void avlInsert(TreeNode **T, int data)
{
    if (*T == NULL)
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->height = 0;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    else if (data < (*T)->data)
    {
        avlInsert(&(*T)->lchild, data);
        // 拿到当前节点的左右子树高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        // 判断高度差
        if (lHeight - rHeight == 2)
        {
            if (data < (*T)->lchild->data)
            {
                // LL调整
                llRotation(*T, T);
            }
            else
            {
                // LR调整
                rrRotation((*T)->lchild, &(*T)->lchild);
                llRotation(*T, T);
            }
        }
    }
    else if (data > (*T)->data)
    {
        avlInsert(&(*T)->rchild, data);
        // 拿到当前节点的左右子树高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        // 判断高度差
        if (rHeight - lHeight == 2)
        {
            if (data > (*T)->lchild->data)
            {
                // RR调整
                rrRotation(*T, T);
            }
            else
            {
                // RL调整
                llRotation((*T)->rchild, &(*T)->rchild);
                rrRotation(*T, T);
            }
        }
    }
    else
    {
        return;
    }
    (*T)->height = max(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;
}

void preOrder(TreeNode *T)
{
    printf("%d", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

int main()
{
    TreeNode *T = NULL;
    int nums[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        avlInsert(&T, nums[i]);
    }
    preOrder(T);
    printf("\n");
}