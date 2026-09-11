#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
    int ltag;
    int rtag;
} TreeNode;

void createTree(TreeNode **T, char *data, int *index)
{
    char ch = data[*index];
    *index += 1;
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        createTree(&(*T)->lchild, data, index);
        createTree(&(*T)->rchild, data, index);
    }
}

void PreThreadTree(TreeNode *T, TreeNode **pre)
{
    if (T)
    {
        if (T->lchild == NULL)
        {
            T->ltag = 1;
            T->lchild = *pre;
        }
        if (*pre != NULL && (*pre)->rchild == NULL)
        {
            (*pre)->rtag = 1;
            (*pre)->rchild = T;
        }
        *pre = T;
        if (T->ltag == 0)
        {
            PreThreadTree(T->lchild, pre);
        }
        PreThreadTree(T->rchild, pre);
    }
}

TreeNode* getNext(TreeNode* node){
    if(node->rtag==1){
        return node->rchild;
    }else{
        if(node->ltag==0){
            return node->lchild;
        }else{
            return node->rchild;
        }
    }
}

int main(int argc,char* argv[]){
    TreeNode* T;
    TreeNode* pre = NULL;
    int index =0;
    createTree(&T,argv[1],&index);
    pre->rtag=1;
    pre->rchild=NULL;
    for(TreeNode* node=T;node!=NULL;node=getNext(node)){
        printf("%c ",node->data);
    }
    printf("\n");
    return 0;
}