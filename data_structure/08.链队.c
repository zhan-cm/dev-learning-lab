#include<stdio.h>
#include<stdlib.h>

typedef struct QNode{
    int data;
    struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//初始化
int initQueue(LinkQueue* Q){
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    Q->front->next=NULL;
    return 1;
}

//入队
int EnQueue(LinkQueue* Q,int data){
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->data=data;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return 1;
}
//出队
int DeQueue(LinkQueue* Q,int *data){
    if(Q->front==Q->rear)return -2;
    QNode* p = Q->front->next;
    data=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)Q->rear=Q->front;
    free(p);
    return 1;
}

//取队头元素
int GetHead(LinkQueue* Q){
    if(Q->front!=Q->rear)
        return Q->front->next->data;
}