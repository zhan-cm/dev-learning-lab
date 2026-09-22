/*
        舞伴问题：
        给定一组舞伴，男女各一半，要求按顺序交替输出，男队先出，女队后出。
        输入：
        第一行：一个整数n，表示舞伴的数量。
        接下来n行：每行一个字符串，表示一个舞伴的名字和性别，用空格隔开。
        输出：
        按顺序输出舞伴的名字和性别，男队先出，女队后出。    
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAXQSIZE 100
typedef struct
{
    char name[20];
    char sex;//F or M   
}Person;
typedef struct
{
    Person *base;
    int front,rear;
}SqQueue;
SqQueue Mdancers,Fdancers;//Male and Female dancers
void InitQueue(SqQueue *q){
    q->base=(Person*)malloc(MAXQSIZE*sizeof(Person));
    if(q->base==NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    q->front=q->rear=0;
}
void DancePartner(Person dancer[],int num){
    InitQueue(&Mdancers);
    InitQueue(&Fdancers);
    for(int i=0;i<num;i++){
        if(dancer[i].sex=='M'){
            Enqueue(&Mdancers,dancer[i]);
        }else{
            Enqueue(&Fdancers,dancer[i]);
        }
    }
    printf("The dance partners are:\n");
    //两队列都不为空，反复循环，依次交替输出男女队伍的队员
    while(!isEmpty(&Mdancers)&&!isEmpty(&Fdancers)){
        Person p1,p2;
        Dequeue(&Mdancers,&p1);
        printf("%s(%c)\n",p1.name,p1.sex);
        Dequeue(&Fdancers,&p2);
        printf("%s(%c)\n",p2.name,p2.sex);
    }
    //若男队队伍为空，则输出女队队伍
    while(!isEmpty(&Fdancers)){
        Person p;
        Dequeue(&Fdancers,&p);
        printf("%s(%c)\n",p.name,p.sex);
    }
    //若女队队伍为空，则输出男队队伍
    while(!isEmpty(&Mdancers)){
        Person p;
        Dequeue(&Mdancers,&p);
        printf("%s(%c)\n",p.name,p.sex);
    }
}
//判断队列是否为空
bool isEmpty(SqQueue *q){
    return (q->front==q->rear);
}
void Enqueue(SqQueue *q,Person p){
    if(q->rear==MAXQSIZE-1)
    {
        printf("Queue is full");
        return;
    }
    q->base[q->rear++]=p;
}
//出队
void Dequeue(SqQueue *q,Person *p){
    if(isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }
    *p=q->base[q->front++];
}

int main(){
    Person dancer[100];
    int num;
    printf("Enter the number of dancers:");
    scanf("%d",&num);
    DancePartner(dancer,num);
    return 0;
}
