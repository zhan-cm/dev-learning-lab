#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int* data;
    int length;//顺序表的长度
    int num;//顺序表当前元素个数
}List;

int* initList(int length){
    List* list = (List*)malloc(sizeof(List));
    list->length=length;
    list->data = (int*)malloc(sizeof(int)*length);
    list->num=1;
    return list;
}

void printList(List* list){
    for(int i=0;i<list->num;i++){
        printf("%d-->",list->data[i]);
    }
    printf("NULL\n");
}

void listAdd(List* list,int data){
    list->data[list->num]=data;
    list->num=(list->num)+1;
}

int search(List* list,int key){
    int i;
    list->data[0] = key;
    for(i=(list->num)-1;list->data[i]!=key;i--);
    return i;
}

int main(){
    List* list = initList(5);
    listAdd(list,1);
    listAdd(list,2);
    listAdd(list,3);
    listAdd(list,4);
    listAdd(list,5);
    printList(list);
    printf("%d\n",search(list,5));
}