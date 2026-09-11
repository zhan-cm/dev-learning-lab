#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

void createTree(TreeNode** T,char* data,int* index){
    char ch;
    ch=data[*index];
    *index+=1;
    if(ch=='#'){
        *T=NULL;
    }else{
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        createTree(&((*T)->lchild),data,index);
        createTree(&((*T)->rchild),data,index);
    }
}

void preOrder(TreeNode* T){
    if(T==NULL){
        return ;
    }else{
        printf("%c ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
//中序后序举一反三即可

int main(){
    TreeNode* T;
    int index=0;
    char data[100]="AB##C##";
    createTree(&T,data,&index);
    preOrder(T);
    return 0;
}