#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

//初始化链表
Node* initList(){
    Node* list = (Node*)malloc(sizeof(Node));
    list->data=0;
    list->next=list;
    return list;
}
//头插法
void headInsert(Node* list,int data){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data=data;
    p->next=list->next;
    list->next=p;
    list->data++;
}
//尾插法
void tailInsert(Node* list,int data){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data=data;
    Node* node=list;
    while(node->next!=list){
        node=node->next;
    }
    p->next=list;
    node->next=p;
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
void printList(Node* list){
    Node* p = list->next;
    while(p!=list){
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