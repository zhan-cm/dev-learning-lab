#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int *base;
    int front;
    int rear;
} SqQueue;

// 初始化
int initQueue(SqQueue *Q)
{
    Q->base = (int *)malloc(sizeof(int) * MAXSIZE);
    if (!Q->base)
        exit(-2);
    Q->front = Q->rear = 0;
    return 1;
}

// 求队列长度
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

// 入队
int EnQueue(SqQueue *Q, int data)
{
    if (Q->rear + 1 % MAXSIZE == Q->front)
    {
        return -2;
    }
    Q->base[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}
// 出队
int DeQueue(SqQueue *Q, int *e)
{
    if (Q->base == Q->rear)
        return -2;
    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

// 取队头元素
int GetHead(SqQueue Q)
{
    if (Q.front != Q.rear)
        return Q.base[Q.front];
}