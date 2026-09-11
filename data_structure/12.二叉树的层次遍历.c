#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef struct QueueNode
{
    TreeNode *data;
    struct QueueNode *pre;
    struct QueueNode *next;
} QueueNode;

void createTree(TreeNode **T, char *data, int *index)
{
    char ch;
    ch = data[*index];
    *index += 1;
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&((*T)->lchild), data, index);
        createTree(&((*T)->rchild), data, index);
    }
}
void preOrder(TreeNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%c ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

QueueNode *initQueue()
{
    QueueNode *Q = (QueueNode *)malloc(sizeof(QueueNode));
    Q->data = NULL;
    Q->next = Q;
    Q->pre = Q;
    return Q;
}

void enQueue(TreeNode *data, QueueNode *Q)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->pre = Q;
    node->next = Q;
    Q->pre->next = node;
    Q->pre = node;
}

int isEmpty(QueueNode *Q)
{
    if (Q->next == Q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

QueueNode *deQueue(QueueNode *Q)
{
    if (isEmpty(Q))
    {
        return NULL;
    }
    else
    {
        QueueNode *node = Q->next;
        Q->next->next->pre = Q;
        Q->next = Q->next->next;
        return node;
    }
}

void levelTraverse(QueueNode *Q, TreeNode *T)
{
    enQueue(T, Q);
    while (!isEmpty(Q))
    {
        QueueNode *node = deQueue(Q);
        printf("%c ", node->data->data);
        if (node->data->lchild)
        {
            enQueue(node->data->lchild, Q);
        }
        if (node->data->rchild)
        {
            enQueue(node->data->rchild, Q);
        }
    }
}

int main()
{
    TreeNode *T;
    int index = 0;
    char data[100] = "ABD##E##CF##G##";
    createTree(&T, data, &index);
    preOrder(T);
    return 0;
}