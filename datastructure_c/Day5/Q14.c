/*
        顺序循环队列
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct{
    int* base;
    int front;
    int rear;
}SqQueue;

//初始化队列
void QueueInit(SqQueue* Q){
    Q->base=(int*)malloc(MAXSIZE*sizeof(int));
    if(Q->base==NULL){
        printf("QueueInit error:out of space\n");
        exit(0);
    }
    Q->front=Q->rear=0;
}

//判断队列是否为空
int QueueEmpty(SqQueue Q){
    return (Q.front==Q.rear);
}

//判断队列是否已满
int QueueFull(SqQueue Q){
    return ((Q.rear+1)%MAXSIZE==Q.front);
}

//入队操作
int EnQueue(SqQueue* Q,int e){
    if(QueueFull(*Q)){
        printf("EnQueue error:queue is full\n");
        return -1;
    }
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return 1;
}

//出队操作
int DeQueue(SqQueue* Q){
    if(QueueEmpty(*Q)){
        printf("DeQueue error:queue is empty\n");
        return -1;
    }
    int e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return e;
}

//遍历队列
void QueueTraverse(SqQueue Q){
    if(QueueEmpty(Q)){
        printf("Queue is empty\n");
        return;
    }
    int i=Q.front;
    do{
        printf("%d ",Q.base[i]);
        i=(i+1)%MAXSIZE;
    }while(i!=Q.rear);
    printf("\n");
}

//测试队列
int main(){
    SqQueue Q;
    QueueInit(&Q);
    EnQueue(&Q,1);
    EnQueue(&Q,2);
    EnQueue(&Q,3);
    EnQueue(&Q,4);
    EnQueue(&Q,5);
    DeQueue(&Q);
    DeQueue(&Q);
    DeQueue(&Q);
    DeQueue(&Q);
    DeQueue(&Q);
    QueueTraverse(Q);
    return 0;
}
