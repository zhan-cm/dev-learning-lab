/*
        链队列的实现
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode{
    int data;
    struct QNode *next;
}QNode;

typedef struct{
    QNode *front;
    QNode *rear;
}ListQueue;


// 初始化队列
void InitQueue(ListQueue *q){
    q->front = q->rear = (QNode*)malloc(sizeof(QNode));
    q->front->next = NULL;
}

//入队操作
void EnQueue(ListQueue* q,int data){
    QNode *p = (QNode*)malloc(sizeof(QNode));
    p->data=data;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}

// 出队操作
int DeQueue(ListQueue* q){
    if(q->front==q->rear)
        return -1;
    QNode *p=q->front->next;
    int data=p->data;
    q->front->next=p->next;
    if(q->rear==p)
        q->rear=q->front;
    free(p);
    return data;
}

// 队列判空操作
int QueueEmpty(ListQueue* q){
    return (q->front==q->rear);
}

// 队列判满操作
int QueueFull(ListQueue* q){
    return (q->rear->next!=NULL);
}

// 打印队列
void PrintQueue(ListQueue* q){
    QNode *p=q->front->next;
    printf("Queue: ");
    while(p!=NULL){
        printf("%d\n ",p->data);
        p=p->next;
    }
    printf("\n");   
}
// 销毁队列
void DestroyQueue(ListQueue* q){
    QNode *p=q->front->next;
    while(p!=NULL){
        QNode *q=p;
        p=p->next;
        free(q);
    }
    free(q->front);
}   
// 测试队列
int main(){
    ListQueue q;
    InitQueue(&q);
    EnQueue(&q,1);
    EnQueue(&q,2);
    EnQueue(&q,3);
    EnQueue(&q,4);
    EnQueue(&q,5);
    PrintQueue(&q);
    DeQueue(&q);
    DeQueue(&q);    
    PrintQueue(&q);
    DestroyQueue(&q);
    return 0;
}

