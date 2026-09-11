#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
    struct TreeNode *parent;
    int ltag;
    int rtag;
} TreeNode;

void createTree(TreeNode **T, char *data, int *index,TreeNode* parent)
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
        (*T)->parent = parent;
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        createTree(&(*T)->lchild, data, index,*T);
        createTree(&(*T)->rchild, data, index,*T);
    }
}

void postThreadTree(TreeNode* T,TreeNode** pre){
    if(T){
        postThreadTree(T->lchild,pre);
        postThreadTree(T->rchild,pre);
        if(T->lchild==NULL){
            T->ltag=1;
            T->lchild=*pre;
        }
        if(*pre!=NULL&&(*pre)->rchild==NULL){
            (*pre)->rtag=1;
            (*pre)->rchild=T;
        }
        *pre=T;
    }
}

TreeNode *getFirst(TreeNode *T)
{
    while(T->ltag==0){
        T=T->lchild;
    }
    if(T->rtag==0){
        return getFirst(T->rchild);
    }
    return T;
}

TreeNode* getNext(TreeNode* node){
    if(node->rtag==1){
        return node->rchild;
    }else{
        //如果是根节点
        if(node->parent==NULL){
            return NULL;
        }
        //如果是右孩子
        else if(node->parent->rchild==node){
            return node->parent;
        }
        //如果是左孩子
        else{
            if(node->parent->rtag==0){
                return getFirst(node->parent->rchild);
            }else{
                return node->parent;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    TreeNode *T;
    TreeNode *pre = NULL;
    int index = 0;
    createTree(&T, argv[1], &index,NULL);
    inThreadTree(T, &pre);
    for(TreeNode* node=getFirst(T);node!=NULL;node=getNext(node)){
        printf("%c ",node->data);
    }
    printf("\n");
    return 0;
}