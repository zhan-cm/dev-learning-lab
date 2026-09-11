#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 初始化栈
int initStack(Node* S)
{
    S=NULL;
    return 1;
}
 
//入栈
int push(Node* S,int data){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data=data;
    p->next=S;
    S=p;
    return 1;
}

//出栈
int pop(Node* S){
    if(S==NULL)return -1;
    int e = S->data;
    Node* p = S;
    S=S->next;
    free(p);
    return 1;
}

//取栈顶元素 
int GetTop(Node* S){
    if(S!=NULL)
        return S->data;
}