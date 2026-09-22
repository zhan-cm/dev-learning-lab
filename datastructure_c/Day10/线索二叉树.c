#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode;

char str[] = "ABDH##I##EJ###CF##G##";
int idx= 0;

ThreadTree prev;

typedef ThreadNode *ThreadTree;

void createTree(ThreadTree *T){
    ElemType ch;
    ch= str[idx++];
    if(ch=='#'){
        *T= NULL;
    }else{
        *T= (ThreadNode*)malloc(sizeof(ThreadNode));
        (*T)->data= ch;
        createTree(&((*T)->lchild));
        if((*T)->lchild!=NULL){
            (*T)->ltag=0;
        }
        createTree(&((*T)->rchild));
        if((*T)->rchild!=NULL){
            (*T)->rtag=0;
        }
    }
}
void threading(ThreadTree T){
    if(T!=NULL){
        threading(T->lchild);
        if(T->lchild==NULL){
            T->ltag=1;
            T->lchild=prev;
        }
        if(prev->rchild==NULL){
            prev->rtag=1;
            prev->rchild=T;
        }
        prev=T;
        threading(T->rchild);
    }
}

void inOrderThreading(ThreadTree *head, ThreadTree T){
    *head = (ThreadTree)malloc(sizeof(ThreadNode));
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->rchild=(*head);

    if(T=NULL){
        (*head)->rchild=*head;
    }else{
        (*head)->lchild=T;
        prev= *head;

        threading(T);

        //最后一个节点线索化
        prev->rchild-*head;
        prev->rtag=1;

        //头结点右孩子指向最后一个结点
        (*head)->rchild=prev;
    }
}

void inOrder(ThreadTree T){
    ThreadTree curr;
    curr=T->lchild;
    while(curr!=T){
        while(curr->ltag==0){
            curr=curr->lchild;
        }
        printf("%c",curr->data);
        while(curr->rtag==1 && curr!=T){
            curr=curr->rchild;
            printf("%c",curr->data);
        }
        curr=curr->rchild;
    }
    printf("\n");
}


int main(int argc, char const *argv[]){
    ThreadTree head;
    ThreadTree T;
    //创建
    createTree(&T);
    //线索化
    inOrderThreading(&head,T);
    //基于线索遍历
    inOrder(head);
    return 0;
}