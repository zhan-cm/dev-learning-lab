/*
    栈的实现
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef struct{
    int stackSize;
    int* top;
    int* base;
}Stack;
void initStack(Stack* s){
    s->base=(int*)malloc(MAXSIZE*sizeof(int));
    if(!s->base){
        exit(0);
    }
    s->top=s->base;
    s->stackSize=MAXSIZE;
}
void push(Stack* s,int data){
    if(s->top-s->base==s->stackSize){
        printf("栈满\n");
        return;
    }
    s->top++;
    *s->top=data;
}
void pop(Stack* s){
    if(s->top==s->base){
        printf("栈空\n");
        return ;
    }
    printf("弹出元素:%d\n",*s->top);
    s->top--;
}

int main(){
    Stack s;
    initStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    return 0;
   
}