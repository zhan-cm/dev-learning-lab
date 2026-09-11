#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int *top;
    int *base;
    int stacksize;
} SqStack;

// 初始化
int initStack(SqStack *S)
{
    S->base = (int *)malloc(sizeof(int) * MAXSIZE);
    if (!S->base)
    {
        exit(-2);
    }
    S->top = S->base;
    S->stacksize = MAXSIZE;
    return 1;
}

//入栈
int push(SqStack* S,int data){
    if(S->top-S->base==S->stacksize){
        return -1;
    }
    *S->top++=data;
    return 1;
}
//出栈
int pop(SqStack* S){
    if(S->top==S->base){
        return -1;
    }
    int data = *--S->top;
    printf("栈顶元素为：%d\n",data);
    return 1;
}
//取栈顶元素
int GetTop(SqStack S){
    if(S.top!=S.base){
        return *(S.top-1);
    }
}
