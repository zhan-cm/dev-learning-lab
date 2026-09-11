#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

//初始化链表
Node* initList(){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data=0;
    node->prev=node;
    node->next=node;
    return node;
}

//头插法
void headInsert(Node* list,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    Node* p = list;
    node->data=data;
    if(p->next){
        p->next->prev=node;
    }else{
        p->prev=node;
    }
    node->next=p->next;
    node->prev=p;
    p->next=node;
    list->data++;
}

//尾插法
void tailInsert(Node* list,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    Node* p = list;
    node->data=data;
    node->next=list;
    node->prev=list->prev;
    list->prev->next=node;
    list->prev=node;
    list->data++;
}

//删除节点
int delete(Node* list,int data){
    Node* p = list;
    while(p->next){
        if(p->next->data==data){
            Node* temp = p->next;
            p->next=temp->next;
            temp->next->prev=p;
            free(temp);
            list->data--;
            return TRUE;
        }
        p=p->next;
    }
    return FALSE;
}

//遍历节点
void printList(Node* list){
    Node* p =list->next;
    while(p!=list){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}


int main(void){
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