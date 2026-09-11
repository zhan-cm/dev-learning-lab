#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;
//初始化链表
Node* initList(){
    Node* list = (Node*)malloc(sizeof(Node));
    list->data=0;
    list->next=NULL;
}
//头插法
void headInsert(Node* list,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=list->next;
    list->next=node;
    list->data++;
}
//尾插法
void tailInsert(Node* list,int data){
    Node* p = list;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    p=p->next;
    while(p->next){
        p=p->next;
    }
    p->next=node;
    list->data++;
}
//删除节点
void delete(Node* list,int data){
    Node* p = list;
    while(p->next){
        if(p->next->data==data){
            Node* q = p->next;
            p->next=q->next;
            free(q);
            break;
        }
        p=p->next;
    }
    list->data--;
}
//遍历节点
void printList(Node* list ){
    Node* p = list;
    p=p->next;
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}


int main(){
    Node* list = initList();
    headInsert(list,1);
    headInsert(list,2);
    headInsert(list,3);
    headInsert(list,4);
    headInsert(list,5);
    tailInsert(list,6);
    tailInsert(list,7);
    tailInsert(list,8);
    tailInsert(list,9);
    tailInsert(list,10);
    printList(list);
    delete(list,5);
    delete(list,10);
    delete(list,6);
    printList(list);
    free(list);
    return 0;
}